#' Pretty break-points for continuous (numeric) data
#'
#' @description
#' The distances between break-points are always equal in this implementation.
#'
#' @param x A numeric vector.
#' @param n Number of breakpoints. You may get less or more than requested.
#' @param pretty Should pretty break-points be prioritised? Default is `TRUE`.
#' @param expand_min Should smallest break be extended beyond the
#' minimum of the data? Default is `FALSE`.
#' @param expand_max Should largest break be extended beyond the maximum
#' of the data? Default is `FALSE`.
#' @param ... Extra arguments passed onto methods.
#'
#' @returns
#' A numeric vector of break-points.
#'
#' @examples
#' library(cheapr)
#'
#' set.seed(123)
#' ages <- sample(0:80, 100, TRUE)
#'
#' get_breaks(ages, n = 10)
#'
#' ## To get the same break-points that `cut()` produces, we can do this..
#'
#' signif(
#'   get_breaks(ages, n = 5, pretty = FALSE,
#'              expand_min = TRUE, expand_max = TRUE), 3
#' )
#' levels(cut(ages, 5))
#'
#' @rdname get_breaks
#' @export
get_breaks <- function(x, n = 7, ...){
  UseMethod("get_breaks")
}
#' @rdname get_breaks
#' @export
get_breaks.numeric <- function(x, n = 7,
                               pretty = TRUE,
                               expand_min = FALSE,
                               expand_max = FALSE,
                               ...){
  check_length(n, 1L)
  stopifnot(n >= 1)

  rng <- as.double(collapse::frange(x, na.rm = TRUE, finite = TRUE))
  if (any_na(rng)){
    return(NA_real_)
  }
  rng_width <- diff(rng)
  start <- rng[1]
  end <- rng[2]
  spans_zero <- abs(diff(sign(rng))) == 2

  if (rng_width == 0){
    return(seq(start - 0.05, end + 0.05, by = 0.1 / max((n - 1), 1)))
  }

  if (!pretty){

    # The way cut() does it
    width <- rng_width / n
    out <- seq(start, end, by = width)
    if (expand_min){
      out[1] <- start - (rng_width * 0.001)
    }
    if (expand_max){
      out[length(out)] <- end + (rng_width * 0.001)
    }
    out

  } else {

    # Make end-points prettier

    adj_start <- round(pretty_floor(start), 6)
    scale_diff <- log_scale(rng_width) - log_scale(adj_start)

    # If large range & relatively small starting value
    # floor start to the nearest difference in orders of magnitude

    if (scale_diff >= 1){
      # If range spans across zero and start val is small
      if (spans_zero && abs(adj_start) < 1){
        adj_start <- nearest_floor(adj_start, 10^(log_scale(end)))
      } else {
        adj_start <- nearest_floor(adj_start, 10^(scale_diff))
      }
    }
    adj_rng_width <- end - adj_start

    # Calculate bin-width (guaranteed to span end-points inclusively)
    bin_width <- adj_rng_width / n
    adj_width <- round(pretty_ceiling(bin_width), 6)

    # Reduce floating-point error
    # If width is almost a whole number, just round it

    last_break_is_short <- isTRUE(is_integerable(seq_to(n + 3, adj_start, by = adj_width)))

    # Also this produces an integer sequence
    if (isTRUE(abs(adj_width - round(adj_width)) < sqrt(.Machine$double.eps))){
      adj_width <- round(adj_width)
      if (last_break_is_short){
        adj_width <- as.integer(adj_width)
      }
    }
    if (isTRUE(abs(adj_start - round(adj_start)) < sqrt(.Machine$double.eps))){
      adj_start <- round(adj_start)
      if (last_break_is_short){
        adj_start <- as.integer(adj_start)
      }
    }


    # Breaks

    n_breaks <- n + 1
    if (expand_max){
      n_breaks <- n_breaks + 2 # 2 for good measure
    }

    if (expand_min && adj_start >= start){
      adj_start <- adj_start - adj_width
    }

    out <- seq(adj_start, by = adj_width, length.out = n_breaks)

    rm <- which_(out > end)

    if (expand_max && (length(rm) > 0)){
      rm <- rm[-1L]
    }

    # Remove outlier breaks

    if (length(rm) > 0){
      out <- out[-rm]
    }

    out
  }
}
#' @export
get_breaks.integer <- get_breaks.numeric
#' @rdname get_breaks
#' @export
get_breaks.integer64 <- function(x, n = 7, ...){
  get_breaks(cpp_int64_to_numeric(x), n, ...)
}

## Based on the log10 scale of x, it is rounded down/up to the nearest order
## of magnitude

log_scale <- function(x, base = 10){
  y <- val_replace(x, 0, 1)
  floor(log(abs(y), base = base))
}
nearest_floor <- function(x, n){
  floor(x / n) * n
}
nearest_ceiling <- function(x, n){
  ceiling(x / n) * n
}
pretty_floor <- function(x, base = 10){
  scale <- log_scale(x, base)
  nearest_floor(x, (base ^ scale))
}
pretty_ceiling <- function(x, base = 10){
  scale <- log_scale(x, base)
  nearest_ceiling(x, (base ^ scale))
}
