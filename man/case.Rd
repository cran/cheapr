% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/case.R
\name{case}
\alias{case}
\alias{val_match}
\title{A cheapr case-when and switch}
\usage{
case(..., .default = NULL)

val_match(.x, ..., .default = NULL)
}
\arguments{
\item{...}{Logical expressions or scalar values in the case of \code{val_match}.}

\item{.default}{Catch-all value or vector.}

\item{.x}{Vector used to switch values.}
}
\value{
A vector the same length as \code{.x} or same length as the first condition in the
case of \code{case}, unless the condition length is smaller than the
rhs, in which case the length of the rhs is used.
}
\description{
\code{case} and \code{val_match} are cheaper alternatives to \code{dplyr::case_when} and
\code{dplyr::case_match} respectively.
}
\details{
\code{val_match()} is a very efficient special case of the
\code{case()} function when all lhs expressions are scalars,
i.e. length-1 vectors. RHS expressions can be vectors the
same length as \code{.x}.
The below 2 expressions are equivalent.

\preformatted{
val_match(
  x,
  1 ~ "one",
  2 ~ "two",
  .default = "Unknown"
 )
case(
  x == 1 ~ "one",
  x == 2 ~ "two",
  .default = "Unknown"
 )
}
}
\seealso{
\link{cheapr_if_else}
}
