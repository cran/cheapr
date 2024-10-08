#' Greatest common divisor and smallest common multiple
#'
#' @description
#' Fast greatest common divisor and smallest common multiple
#' using the Euclidean algorithm.
#'
#' `gcd()` returns the greatest common divisor. \cr
#' `scm()` returns the smallest common multiple. \cr
#' `gcd2()` is a vectorised binary version of `gcd`. \cr
#' `scm2()` is a vectorised binary version of `scm`.
#'
#' @param x A [numeric] vector.
#' @param tol Tolerance. This must
#' be a single positive number strictly less than 1.
#' @param na_rm If `TRUE` the default, `NA` values are ignored.
#' @param round If `TRUE` the output is rounded as
#' `round(gcd, digits)` where digits is
#' `ceiling(abs(log10(tol))) + 1`. \cr
#' This can potentially reduce floating point errors on
#' further calculations. \cr
#' The default is `TRUE`.
#' @param break_early This is experimental and
#' applies only to floating-point numbers.
#' When `TRUE` the algorithm will end once `gcd > 0 && gcd < 2 * tol`.
#' This can offer a tremendous speed improvement.
#' If `FALSE` the algorithm finishes once it has gone through all elements of `x`.
#' The default is `TRUE`. \cr
#' For integers, the algorithm always breaks early once `gcd > 0 && gcd <= 1`.
#' @param y A [numeric] vector.
#'
#' @returns
#' A number representing the GCD or SCM.
#'
#' @details
#'
#' ## Method
#'
#' ### GCD (Greatest Common Divisor)
#'
#' The GCD is calculated using a binary function that takes input
#' `GCD(gcd, x[i + 1])` where the output of this function is passed as input
#' back into the same function iteratively along the length of `x`.
#' The first gcd value is `x[1]`.
#'
#' Zeroes are handled in the following way: \cr
#' `GCD(0, 0) = 0` \cr
#' `GCD(a, 0) = a` \cr
#'
#' This has the nice property that zeroes are essentially ignored.
#'
#' ### SCM (Smallest Common Multiple)
#'
#' This is calculated using the GCD and the formula is: \cr
#' `SCM(x, y) = (abs(x) / GCD(x, y) ) * abs(y)`
#'
#'
#' If you want to calculate the gcd & lcm for 2 values
#' or across 2 vectors of values, use `gcd2` and `scm2`.
#'
#' ### A note on performance
#'
#' A very common solution to finding the GCD of a vector of values is to use
#' `Reduce()` along with a binary function like `gcd2()`. \cr
#' e.g. `Reduce(gcd2, seq(5, 20, 5))`. \cr
#' This is exactly identical to `gcd(seq(5, 20, 5))`, with `gcd()` being much
#' faster and overall cheaper as it is written in C++ and heavily optimised.
#' Therefore it is recommended to always use `gcd()`.
#'
#' For example we can compare the two approaches below, \cr
#' `x <- seq(5L, length = 10^6, by = 5L)` \cr
#' `bench::mark(Reduce(gcd2, x), gcd(x))` \cr
#' This example code shows `gcd()` being ~200x faster on my machine than
#' the `Reduce` + `gcd2` approach, even though `gcd2` itself is written in C++
#' and has little overhead.
#'
#' @examples
#' library(cheapr)
#' library(bench)
#'
#' # Binary versions
#' gcd2(15, 25)
#' gcd2(15, seq(5, 25, 5))
#' scm2(15, seq(5, 25, 5))
#' scm2(15, 25)
#'
#' # GCD across a vector
#' gcd(c(0, 5, 25))
#' mark(gcd(c(0, 5, 25)))
#'
#' x <- rnorm(10^5)
#' gcd(x)
#' gcd(x, round = FALSE)
#' mark(gcd(x))
#' @rdname gcd
#' @export
gcd <- function(x, tol = sqrt(.Machine$double.eps),
                na_rm = TRUE, round = TRUE,
                break_early = TRUE) {
  .Call(`_cheapr_cpp_gcd`, x,
        as.double(tol),
        na_rm,
        break_early,
        round)
}
#' @rdname gcd
#' @export
scm <- function(x, tol = sqrt(.Machine$double.eps), na_rm = TRUE) {
  .Call(`_cheapr_cpp_lcm`, x, as.double(tol), na_rm)
}
#' @rdname gcd
#' @export
gcd2 <- function(x, y, tol = sqrt(.Machine$double.eps), na_rm = TRUE){
  .Call(`_cheapr_cpp_gcd2_vectorised`, x, y, as.double(tol), na_rm)
}
#' @rdname gcd
#' @export
scm2 <- function(x, y, tol = sqrt(.Machine$double.eps), na_rm = TRUE){
  .Call(`_cheapr_cpp_lcm2_vectorised`, x, y, as.double(tol), na_rm)
}
