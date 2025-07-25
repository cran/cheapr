% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/attrs.R
\name{attrs}
\alias{attrs}
\alias{attrs_modify}
\alias{attrs_add}
\alias{attrs_clear}
\alias{attrs_rm}
\title{Add and remove attributes}
\usage{
attrs_modify(x, ..., .set = FALSE, .args = NULL)

attrs_add(x, ..., .set = FALSE, .args = NULL)

attrs_clear(x, .set = FALSE)

attrs_rm(x, .set = FALSE)
}
\arguments{
\item{x}{Object to add/remove attributes.}

\item{...}{Named attributes, e.g 'key = value'.}

\item{.set}{Should attributes be added in-place without shallow-copying \code{x}?
Default is \code{FALSE}.}

\item{.args}{An alternative to \code{...} for easier programming with lists.}
}
\value{
The object \code{x} with attributes removed or added.
}
\description{
Simple tools to add and remove attributes, both normally and in-place.
To remove specific attributes, set those attributes to \code{NULL}.
}
\seealso{
\link{shallow_copy}
}
