#' Extra utilities
#'
#' @param x A vector or data frame.
#' @param y A vector or data frame.
#' @param dups Should duplicates be kept? Default is `TRUE`.
#' @param name The column name to assign the names of a vector.
#' @param value The column name to assign the values of a vector.
#' @param breaks See `?cut`.
#' @param labels See `?cut`.
#' @param include.lowest See `?cut`.
#' @param right See `?cut`.
#' @param dig.lab See `?cut`.
#' @param ordered_result See `?cut`.
#' @param table See `?collapse::fmatch`
#' @param ... Further arguments passed onto `cut` or `set.seed`.
#' @param size See `?sample`.
#' @param replace See `?sample`.
#' @param prob See `?sample`.
#'
#' @returns
#' `enframe()_` converts a vector to a data frame. \cr
#' `deframe()_` converts a 1-2 column data frame to a vector. \cr
#' `intersect_()` returns a vector of common values between `x` and `y`. \cr
#' `setdiff_()` returns a vector of values in `x` but not `y`. \cr
#' `cut_numeric()` places values of a numeric vector into buckets, defined
#' through the `breaks` argument and returns a factor unless `labels = FALSE`,
#' in which case an integer vector of break indices is returned. \cr
#' `%in_%` and `%!in_%` both return a logical vector signifying if the values of
#' `x` exist or don't exist in `table` respectively. \cr
#' `na_rm()` is a convenience function that removes `NA` values and
#' empty rows in the case of data frames.
#' For more advanced `NA` handling, see `?is_na`. \cr
#' `sample_()` is an alternative to `sample()` that natively samples
#' data frame rows through `sset()`. It also does not have a special case when
#' `length(x)` is 1. \cr
#'
#' @details
#' `intersect_()` and `setdiff_()` are faster and more efficient
#' alternatives to `intersect()` and `setdiff()` respectively. \cr
#' `enframe_()` and `deframe_()` are faster alternatives to
#' `tibble::enframe()` and `tibble::deframe()` respectively. \cr
#' `cut_numeric()` is a faster and more efficient alternative to
#' `cut.default()`.
#'
#' @export
#' @rdname extras
setdiff_ <- function(x, y, dups = TRUE){
  if (!dups){
    x <- collapse::funique(x)
  }
  sset(x, which_not_in(x, y))
}
#' @export
#' @rdname extras
intersect_ <- function(x, y, dups = TRUE){
  if (!dups){
    x <- collapse::funique(x)
  }
  sset(x, which_in(x, y))
}
#' @export
#' @rdname extras
cut_numeric <- function(x, breaks, labels = NULL, include.lowest = FALSE,
                        right = TRUE, dig.lab = 3L, ordered_result = FALSE, ...){
  if (!is.numeric(x))
    stop("'x' must be numeric")
  if (length(breaks) == 1L) {
    if (is.na(breaks) || breaks < 2L)
      stop("invalid number of intervals")
    nb <- as.integer(breaks + 1)
    dx <- diff(rx <- collapse::frange(x, na.rm = TRUE))
    if (isTRUE(dx == 0)) {
      dx <- if (rx[1L] != 0)
        abs(rx[1L])
      else 1
      breaks <- seq.int(rx[1L] - dx/1000, rx[2L] + dx/1000,
                        length.out = nb)
    }
    else {
      breaks <- seq.int(rx[1L], rx[2L], length.out = nb)
      breaks[c(1L, nb)] <- c(rx[1L] - dx/1000, rx[2L] +
                               dx/1000)
    }
  }
  else nb <- length(breaks <- sort.int(as.double(breaks)))
  if (anyDuplicated(breaks))
    stop("'breaks' are not unique")
  codes.only <- FALSE
  if (is.null(labels)) {
    for (dig in dig.lab:max(12L, dig.lab)) {
      ch.br <- formatC(0 + breaks, digits = dig, width = 1L)
      if (ok <- all(ch.br[-1L] != ch.br[-nb]))
        break
    }
    labels <- if (ok)
      paste0(if (right)
        "("
        else "[", ch.br[-nb], ",", ch.br[-1L], if (right)
          "]"
        else ")")
    else paste0("Range_", seq_len(nb - 1L))
    if (ok && include.lowest) {
      if (right)
        substr(labels[1L], 1L, 1L) <- "["
      else substring(labels[nb - 1L], nchar(labels[nb -
                                                     1L], "c")) <- "]"
    }
  }
  else if (is.logical(labels) && !labels)
    codes.only <- TRUE
  else if (length(labels) != nb - 1L)
    stop("number of intervals and length of 'labels' differ")
  code <- .bincode(x, breaks, right, include.lowest)
  if (!codes.only) {
    levels(code) <- as.character(labels)
    class(code) <- c(if (ordered_result) "ordered" else character(0), "factor")
  }
  code
}
#' @export
#' @rdname extras
`%in_%` <- function(x, table){
  collapse::fmatch(x, table, overid = 2L, nomatch = 0L) > 0L
}
#' @export
#' @rdname extras
`%!in_%` <- function(x, table){
  cpp_is_na(collapse::fmatch(x, table, overid = 2L, nomatch = NA_integer_))
}
#' @export
#' @rdname extras
enframe_ <- function(x, name = "name", value = "value"){
  if (inherits(x, "data.frame")) {
    x <- unclass(x)
    attr(x, "row.names") <- NULL
  }
  x_nms <- names(x)
  x <- unname(x)
  if (is.null(x_nms)) {
    out <- list(x)
    names(out) <- value
  }
  else {
    out <- list(x_nms, x)
    names(out) <- c(name, value)
  }
  class(out) <- c("tbl_df", "tbl", "data.frame")
  attr(out, "row.names") <- .set_row_names(length(x))
  out
}
#' @export
#' @rdname extras
deframe_ <- function(x){
  ncol <- length(names(x))
  if (!(inherits(x, "data.frame") && ncol %in% (1:2))) {
    stop("`x` must be a 1 or 2 col data frame")
  }
  out <- .subset2(x, ncol)
  if (ncol == 2) {
    names(out) <- as.character(.subset2(x, 1L))
  }
  out
}
#' @export
#' @rdname extras
na_rm <- function(x){
  n_na <- num_na(x, recursive = TRUE)
  if (n_na == unlisted_length(x)){
    sset(x, 0L)
  } else if (n_na == 0){
    x
  } else {
    sset(x, which_not_na(x))
  }
}
#' @export
#' @rdname extras
sample_ <- function(x, size = cpp_vec_length(x), replace = FALSE, prob = NULL){
  sset(x, sample.int(cpp_vec_length(x), size, replace, prob))
}
# head_ <- function(x, n = 1L){
#   check_length(n, 1L)
#   N <- cpp_vec_length(x)
#   if (n >= 0) {
#     size <- min(n, N)
#   }
#   else {
#     size <- max(0L, N + n)
#   }
#   sset(x, seq_len(size))
# }
# tail_ <- function (x, n = 1L){
#   check_length(n, 1L)
#   N <- cpp_vec_length(x)
#   if (n >= 0) {
#     size <- min(n, N)
#   }
#   else {
#     size <- max(0L, N + n)
#   }
#   sset(x, seq.int(from = N - size + 1L, by = 1L, length.out = size))
# }
# with_seed <- function (expr, .seed = NULL, ...){
#   old <- globalenv()[[".Random.seed"]]
#   if (is.null(old)) {
#     set.seed(NULL)
#     old <- globalenv()[[".Random.seed"]]
#   }
#   if (!is.null(.seed)) {
#     set.seed(.seed, ...)
#   }
#   on.exit({
#     assign(".Random.seed", old, envir = globalenv())
#   })
#   eval(expr, envir = parent.frame())
# }
