% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/combine.R
\name{cheapr_c}
\alias{cheapr_c}
\title{A cheapr version of \code{c()}}
\usage{
cheapr_c(..., .args = NULL)
}
\arguments{
\item{...}{Objects to combine.}

\item{.args}{An alternative to \code{...} for easier programming with lists.}
}
\value{
Combined objects.
}
\description{
cheapr's version of \code{c()}. It is quite a bit faster for atomic vectors
and combines data frame rows instead of cols.
}
\examples{
library(cheapr)

# Combine just like `c()`
cheapr_c(1, 2, 3:5)

# It combines rows by default instead of cols
cheapr_c(new_df(x = 1:3), new_df(x = 4:10))

# If you have a list of objects you want to combine
# use `.args` instead of `do.call` as it's more efficient

list_of_objs <- rep(list(0), 10^4)

 bench::mark(
    do.call(cheapr_c, list_of_objs),
    cheapr_c(.args = list_of_objs)
  )
}
