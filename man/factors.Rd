% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/factors.R
\name{factor_}
\alias{factor_}
\alias{levels_factor}
\alias{used_levels}
\alias{unused_levels}
\title{A faster version of \code{factor()}}
\usage{
factor_(
  x = integer(),
  levels = NULL,
  order = TRUE,
  na_exclude = TRUE,
  ordered = is.ordered(x)
)

levels_factor(x)

used_levels(x)

unused_levels(x)
}
\arguments{
\item{x}{A vector.}

\item{levels}{Optional factor levels.}

\item{order}{Should factor levels be sorted? Default is \code{TRUE}.
It typically is faster to set this to \code{FALSE}, in which case the levels
are sorted by order of first appearance.}

\item{na_exclude}{Should \code{NA} values be excluded from the factor levels?
Default is \code{TRUE}.}

\item{ordered}{Should the result be an ordered factor?}
}
\value{
A \code{factor} or \code{character} in the case of \code{used_levels} and \code{unused_levels}.
}
\description{
A fast version of \code{factor()} using the collapse package.
There are some additional utilities such as
\code{levels_factor()} which returns the levels of a factor, as a factor,
\code{used_levels()} which returns the used levels of a factor,
and \code{unused_levels()} which returns the unused levels of a factor.
}
\details{
This operates similarly to \code{collapse::qF()}. \cr
The main difference internally is that \code{collapse::funique()} is used
and therefore s3 methods can be written for it. \cr
Furthermore, for date-times \code{factor_} differs in that it differentiates
all instances in time whereas \code{factor} differentiates calendar times.
Using a daylight savings example where the clocks go back: \cr
\code{factor(as.POSIXct(1729984360, tz = "Europe/London") + 3600 *(1:5))}
produces 4 levels whereas \cr
\code{factor_(as.POSIXct(1729984360, tz = "Europe/London") + 3600 *(1:5))}
produces 5 levels.
}
