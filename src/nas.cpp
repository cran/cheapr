#include "cheapr_cpp.h"
#include <cpp11.hpp>
#include <Rinternals.h>

R_xlen_t na_count(SEXP x){
  R_xlen_t n = Rf_xlength(x);
  R_xlen_t count = 0;
  int n_protections = 0;
  // This nicely handles NULL and avoids loop too
  if (n == 0){
    return count;
  }
  bool do_parallel = n >= 100000;
  int n_cores = do_parallel ? num_cores() : 1;
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    int *p_x = INTEGER(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores) reduction(+:count)
      for (R_xlen_t i = 0; i < n; ++i){
        count += (p_x[i] == NA_INTEGER);
      }
    } else {
      for (R_xlen_t i = 0; i < n; ++i){
        count += (p_x[i] == NA_INTEGER);
      }
    }
    break;
  }
  case REALSXP: {
    double *p_x = REAL(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores) reduction(+:count)
      for (R_xlen_t i = 0; i < n; ++i){
        count += (p_x[i] != p_x[i]);
      }
    } else {
      for (R_xlen_t i = 0; i < n; ++i){
        count += (p_x[i] != p_x[i]);
      }
    }
    break;
  }
  case STRSXP: {
    SEXP *p_x = STRING_PTR(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores) reduction(+:count)
      for (R_xlen_t i = 0; i < n; ++i){
        count += (p_x[i] == NA_STRING);
      }
    } else {
      for (R_xlen_t i = 0; i < n; ++i){
        count += (p_x[i] == NA_STRING);
      }
    }
    break;
  }
  case RAWSXP: {
    break;
  }
  case CPLXSXP: {
    Rcomplex *p_x = COMPLEX(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores) reduction(+:count)
      for (R_xlen_t i = 0; i < n; ++i){
        count += ( ((p_x[i]).r != (p_x[i]).r) || ((p_x[i]).i != (p_x[i]).i) );
      }
    } else {
      for (R_xlen_t i = 0; i < n; ++i){
        count += ( ((p_x[i]).r != (p_x[i]).r) || ((p_x[i]).i != (p_x[i]).i) );
      }
    }
    break;
  }
  case VECSXP: {
    // R_xlen_t num_row = cpp_vector_size(x);
    // SEXP is_empty = Rf_protect(cpp_missing_row(x, 1, true));
    // ++n_protections;
    // int *p_is_empty = LOGICAL(is_empty);
    // count = count_true(p_is_empty, num_row);
    const SEXP *p_x = VECTOR_PTR_RO(x);
    for (R_xlen_t i = 0; i < n; ++i){
      count += na_count(p_x[i]);
    }
    break;
  }
  default: {
    Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
    break;
  }
  }
  Rf_unprotect(n_protections);
  return count;
}

[[cpp11::register]]
SEXP cpp_num_na(SEXP x){
  return xlen_to_r(na_count(x));
}

[[cpp11::register]]
bool cpp_any_na(SEXP x){
  R_xlen_t n = Rf_xlength(x);
  bool out = false;
  if (n == 0){
    return out;
  }
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    // The commented-out code is a way to
    // do a pseudo while-loop in openMP
    // volatile bool flag = false;
    int *p_x = INTEGER(x);
// #pragma omp parallel for num_threads(num_cores()) shared(flag)
    for (R_xlen_t i = 0; i < n; ++i){
      // if (flag) continue;
      if (p_x[i] == NA_INTEGER){
        out = true;
        // flag = true;
        break;
      }
    }
    break;
  }
  case REALSXP: {
    double *p_x = REAL(x);
    for (R_xlen_t i = 0; i < n; ++i){
      if (p_x[i] != p_x[i]){
        out = true;
        break;
      }
    }
    break;
  }
  case STRSXP: {
    SEXP *p_x = STRING_PTR(x);
    for (R_xlen_t i = 0; i < n; ++i){
      if (p_x[i] == NA_STRING){
        out = true;
        break;
      }
    }
    break;
  }
  case RAWSXP: {
    break;
  }
  case CPLXSXP: {
    Rcomplex *p_x = COMPLEX(x);
    for (R_xlen_t i = 0; i < n; ++i){
      if (( ((p_x[i]).r != (p_x[i]).r) || ((p_x[i]).i != (p_x[i]).i) )){
        out = true;
        break;
      }
    }
    break;
  }
  case VECSXP: {
    for (int i = 0; i < n; ++i){
    out = cpp_any_na(VECTOR_ELT(x, i));
    if (out) break;
  }
    break;
  }
  default: {
    Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
    break;
  }
  }
  return out;
}

[[cpp11::register]]
bool cpp_all_na(SEXP x, bool return_true_on_empty){
  R_xlen_t n = Rf_xlength(x);
  bool out = true;
  if (n == 0){
    if (return_true_on_empty){
      return true;
    } else {
      return false;
    }
  }
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    int *p_x = INTEGER(x);
    for (R_xlen_t i = 0; i < n; ++i){
      if (p_x[i] != NA_INTEGER){
        out = false;
        break;
      }
    }
    break;
  }
  case REALSXP: {
    double *p_x = REAL(x);
    for (R_xlen_t i = 0; i < n; ++i){
      if (p_x[i] == p_x[i]){
        out = false;
        break;
      }
    }
    break;
  }
  case STRSXP: {
    SEXP *p_x = STRING_PTR(x);
    for (R_xlen_t i = 0; i < n; ++i){
      if (p_x[i] != NA_STRING){
        out = false;
        break;
      }
    }
    break;
  }
  case RAWSXP: {
    break;
  }
  case CPLXSXP: {
    Rcomplex *p_x = COMPLEX(x);
    for (R_xlen_t i = 0; i < n; ++i){
      if (( ((p_x[i]).r == (p_x[i]).r) && ((p_x[i]).i == (p_x[i]).i) )){
        out = false;
        break;
      }
    }
    break;
  }
  case VECSXP: {
    for (int i = 0; i < n; ++i){
    out = cpp_all_na(VECTOR_ELT(x, i), return_true_on_empty);
    if (!out) break;
  }
    break;
  }
  default: {
    Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
    break;
  }
  }
  return out;
}

// Memory-efficient which(is.na(x))

[[cpp11::register]]
SEXP cpp_which_na(SEXP x){
  R_xlen_t n = Rf_xlength(x);
  bool is_short = (n <= integer_max_);
  if (n == 0){
    SEXP out = Rf_protect(Rf_allocVector(INTSXP, 0));
    Rf_unprotect(1);
    return out;
  }
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    R_xlen_t count = na_count(x);
    int *p_x = INTEGER(x);
    if (is_short){
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, count));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] == NA_INTEGER);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, count));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] == NA_INTEGER);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
  case REALSXP: {
    R_xlen_t count = na_count(x);
    double *p_x = REAL(x);
    if (is_short){
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, count));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] != p_x[i]);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, count));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] != p_x[i]);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
  case STRSXP: {
    R_xlen_t count = na_count(x);
    // R_xlen_t count = Rf_asReal(Rf_protect(cpp_num_na(x)));
    SEXP *p_x = STRING_PTR(x);
    if (is_short){
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, count));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] == NA_STRING);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, count));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] == NA_STRING);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
  case RAWSXP: {
    SEXP out = Rf_protect(Rf_allocVector(INTSXP, 0));
    Rf_unprotect(1);
    return out;
  }
  case CPLXSXP: {
    R_xlen_t count = na_count(x);
    Rcomplex *p_x = COMPLEX(x);
    if (is_short){
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, count));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += ( ( !((p_x[i]).r == (p_x[i]).r) ) || ( !((p_x[i]).i == (p_x[i]).i) ) );
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, count));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < count){
        p_out[whichi] = i + 1;
        whichi += ( ( !((p_x[i]).r == (p_x[i]).r) ) || ( !((p_x[i]).i == (p_x[i]).i) ) );
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
  // case VECSXP: {
  //   if (Rf_inherits(x, "vctrs_rcrd")){
  //   SEXP rcrd_df = Rf_protect(cpp11::package("cheapr")["vctrs_rcrd_as_df"](x));
  //   SEXP is_empty = Rf_protect(cpp_missing_row(rcrd_df, 1, true));
  //   SEXP out = Rf_protect(cpp_which_(is_empty, false));
  //   Rf_unprotect(3);
  //   return out;
  // }
  // }
  default: {
    Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
    break;
  }
  }
}

[[cpp11::register]]
SEXP cpp_which_not_na(SEXP x){
  R_xlen_t n = Rf_xlength(x);
  bool is_short = (n <= integer_max_);
  if (n == 0){
    SEXP out = Rf_protect(Rf_allocVector(INTSXP, 0));
    Rf_unprotect(1);
    return out;
  }
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    R_xlen_t count = na_count(x);
    int *p_x = INTEGER(x);
    if (is_short){
      int out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, out_size));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] != NA_INTEGER);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      R_xlen_t out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, out_size));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] != NA_INTEGER);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
  case REALSXP: {
    R_xlen_t count = na_count(x);
    double *p_x = REAL(x);
    if (is_short){
      int out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, out_size));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] == p_x[i]);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      R_xlen_t out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, out_size));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] == p_x[i]);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
  case STRSXP: {
    R_xlen_t count = na_count(x);
    SEXP *p_x = STRING_PTR(x);
    if (is_short){
      int out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, out_size));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] != NA_STRING);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      R_xlen_t out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, out_size));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += (p_x[i] != NA_STRING);
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
  case RAWSXP: {
    if (is_short){
    SEXP out = Rf_protect(Rf_allocVector(INTSXP, n));
    int *p_out = INTEGER(out);
    for (int i = 0; i < n; ++i){
      p_out[i] = i + 1;
    }
    Rf_unprotect(1);
    return out;
  } else {
    SEXP out = Rf_protect(Rf_allocVector(REALSXP, n));
    double *p_out = REAL(out);
    for (R_xlen_t i = 0; i < n; ++i){
      p_out[i] = i + 1;
    }
    Rf_unprotect(1);
    return out;
  }
  }
  case CPLXSXP: {
    R_xlen_t count = na_count(x);
    Rcomplex *p_x = COMPLEX(x);
    if (is_short){
      int out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(INTSXP, out_size));
      int *p_out = INTEGER(out);
      int whichi = 0;
      int i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += ( ( ((p_x[i]).r == (p_x[i]).r) ) && ( ((p_x[i]).i == (p_x[i]).i) ) );
        ++i;
      }
      Rf_unprotect(1);
      return out;
    } else {
      R_xlen_t out_size = n - count;
      SEXP out = Rf_protect(Rf_allocVector(REALSXP, out_size));
      double *p_out = REAL(out);
      R_xlen_t whichi = 0;
      R_xlen_t i = 0;
      while (whichi < out_size){
        p_out[whichi] = i + 1;
        whichi += ( ( ((p_x[i]).r == (p_x[i]).r) ) && ( ((p_x[i]).i == (p_x[i]).i) ) );
        ++i;
      }
      Rf_unprotect(1);
      return out;
    }
  }
    // case VECSXP: {
    //   if (Rf_inherits(x, "vctrs_rcrd")){
    //   SEXP rcrd_df = Rf_protect(cpp11::package("cheapr")["vctrs_rcrd_as_df"](x));
    //   SEXP is_empty = Rf_protect(cpp_missing_row(rcrd_df, 1, true));
    //   SEXP out = Rf_protect(cpp_which_(is_empty, true));
    //   Rf_unprotect(3);
    //   return out;
    // }
    // }
  default: {
    Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
    break;
  }
  }
}

// A parallelised version of `is.na()`
// lists are handled differently in that each element
// must contain only NA in all nested elements to be regarded as NA

[[cpp11::register]]
SEXP cpp_is_na(SEXP x){
  R_xlen_t n = Rf_xlength(x);
  bool do_parallel = n >= 100000;
  int n_cores = do_parallel ? num_cores() : 1;
  R_xlen_t i;
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n));
    int *p_out = LOGICAL(out);
    int *p_x = INTEGER(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores)
      for (i = 0; i < n; ++i){
        p_out[i] = (p_x[i] == NA_INTEGER);
      }
    } else {
      for (i = 0; i < n; ++i){
        p_out[i] = (p_x[i] == NA_INTEGER);
      }
    }
    Rf_unprotect(1);
    return out;
    // break;
  }
  case REALSXP: {
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n));
    int *p_out = LOGICAL(out);
    double *p_x = REAL(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores)
      for (i = 0; i < n; ++i){
        p_out[i] = (p_x[i] != p_x[i]);
      }
    } else {
      for (i = 0; i < n; ++i){
        p_out[i] = (p_x[i] != p_x[i]);
      }
    }
    Rf_unprotect(1);
    return out;
    // break;
  }
  case STRSXP: {
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n));
    int *p_out = LOGICAL(out);
    SEXP *p_x = STRING_PTR(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores)
      for (i = 0; i < n; ++i){
        p_out[i] = (p_x[i] == NA_STRING);
      }
    } else {
      for (i = 0; i < n; ++i){
        p_out[i] = (p_x[i] == NA_STRING);
      }
    }
    Rf_unprotect(1);
    return out;
    // break;
  }
  case RAWSXP: {
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n));
    int *p_out = LOGICAL(out);
    memset(p_out, 0, n * sizeof(int));
    Rf_unprotect(1);
    return out;
    // break;
  }
  case CPLXSXP: {
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n));
    int *p_out = LOGICAL(out);
    Rcomplex *p_x = COMPLEX(x);
    if (do_parallel){
#pragma omp parallel for simd num_threads(n_cores)
      for (i = 0; i < n; ++i){
        p_out[i] = ( ((p_x[i]).r != (p_x[i]).r) || ((p_x[i]).i != (p_x[i]).i) );
      }
    } else {
      for (i = 0; i < n; ++i){
        p_out[i] = ( ((p_x[i]).r != (p_x[i]).r) || ((p_x[i]).i != (p_x[i]).i) );
      }
    }
    Rf_unprotect(1);
    return out;
    // break;
  }
  case VECSXP: {
  //   if (Rf_inherits(x, "vctrs_rcrd")){
  //   SEXP rcrd_df = Rf_protect(cpp11::package("cheapr")["vctrs_rcrd_as_df"](x));
  //   SEXP out = Rf_protect(cpp_missing_row(rcrd_df, 1, true));
  //   Rf_unprotect(2);
  //   return out;
  // } else {
  if (!Rf_isObject(x)){
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n));
    int *p_out = LOGICAL(out);
    const SEXP *p_x = VECTOR_PTR_RO(x);
    for (i = 0; i < n; ++i){
      p_out[i] = cpp_all_na(p_x[i], false);
    }
    Rf_unprotect(1);
    return out;
  }
  // SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n));
  //   int *p_out = LOGICAL(out);
  //   const SEXP *p_x = VECTOR_PTR_RO(x);
  //   for (i = 0; i < n; ++i){
  //     p_out[i] = cpp_all_na(p_x[i], false);
  //   }
  //   Rf_unprotect(1);
  //   return out;
  // }
    // break;
  }
  default: {
    SEXP out = Rf_protect(cpp11::package("base")["is.na"](x));
    Rf_unprotect(1);
    return out;
    // Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
    // break;
  }
  }
  // Rf_unprotect(n_protections);
  // return out;
}

[[cpp11::register]]
SEXP cpp_row_na_counts(SEXP x){
  if (!Rf_isFrame(x)){
    Rf_error("x must be a data frame");
  }
  const SEXP *p_x = VECTOR_PTR_RO(x);
  int num_col = Rf_length(x);
  int n_protections = 0;
  R_xlen_t num_row = cpp_df_nrow(x);
  SEXP n_empty = Rf_protect(Rf_allocVector(INTSXP, num_row));
  ++n_protections;
  int *p_n_empty = INTEGER(n_empty);
  memset(p_n_empty, 0, num_row * sizeof(int));
  int do_parallel = num_row >= 100000;
  int n_cores = do_parallel ? num_cores() : 1;
  for (int j = 0; j < num_col; ++j){
    switch ( TYPEOF(p_x[j]) ){
    case LGLSXP:
    case INTSXP: {
      int *p_xj = INTEGER(p_x[j]);
#pragma omp parallel num_threads(n_cores) if(do_parallel)
// #pragma omp for
#pragma omp for simd
      for (R_xlen_t i = 0; i < num_row; ++i){
// #pragma omp atomic
        p_n_empty[i] += (p_xj[i] == NA_INTEGER);
      }
      break;
    }
    case REALSXP: {
      double *p_xj = REAL(p_x[j]);
#pragma omp parallel num_threads(n_cores) if(do_parallel)
// #pragma omp for
#pragma omp for simd
      for (R_xlen_t i = 0; i < num_row; ++i){
// #pragma omp atomic
        p_n_empty[i] += (p_xj[i] != p_xj[i]);
      }
      break;
    }
    case STRSXP: {
      SEXP *p_xj = STRING_PTR(p_x[j]);
#pragma omp parallel num_threads(n_cores) if(do_parallel)
// #pragma omp for
#pragma omp for simd
      for (R_xlen_t i = 0; i < num_row; ++i){
// #pragma omp atomic
        p_n_empty[i] += (p_xj[i] == NA_STRING);
      }
      break;
    }
    case RAWSXP: {
      break;
    }
    case CPLXSXP: {
      Rcomplex *p_xj = COMPLEX(p_x[j]);
#pragma omp parallel num_threads(n_cores) if(do_parallel)
// #pragma omp for
#pragma omp for simd
      for (R_xlen_t i = 0; i < num_row; ++i){
// #pragma omp atomic
        p_n_empty[i] += (p_xj[i]).r != (p_xj[i]).r || (p_xj[i]).i != (p_xj[i]).i;
      }
      break;
    }
    case VECSXP: {
      // SEXP is_empty_nested = Rf_protect(cpp_missing_row(VECTOR_ELT(x, j), 1, true));
      // ++n_protections;
      // int *p_is_empty_nested = LOGICAL(is_empty_nested);
      // for (R_xlen_t k = 0; k < num_row; ++k){
      //   p_n_empty[k] += p_is_empty_nested[k];
      // }


      // if (Rf_inherits(p_x[j], "vctrs_rcrd")){
      //   SEXP rcrd_df = Rf_protect(cpp11::package("cheapr")["vctrs_rcrd_as_df"](p_x[j]));
      //   ++n_protections;
      //   SEXP is_empty_nested = Rf_protect(cpp_missing_row(rcrd_df, 1, true));
      //   ++n_protections;
      //   int *p_is_empty_nested = LOGICAL(is_empty_nested);
      //   for (R_xlen_t k = 0; k < num_row; ++k){
      //     p_n_empty[k] += p_is_empty_nested[k];
      //   }
      // } else {
      if (Rf_xlength(p_x[j]) != num_row){
      int int_nrows = num_row;
      int element_length = Rf_xlength(p_x[j]);
      ++n_protections;
      SEXP names = Rf_protect(Rf_getAttrib(x, R_NamesSymbol));
      Rf_unprotect(n_protections);
      Rf_error("list variable %s has length (%d) not equal to number of rows (%d)",
               CHAR(STRING_ELT(names, j)), element_length, int_nrows);
    }
      const SEXP *p_xj = VECTOR_PTR_RO(p_x[j]);
      for (R_xlen_t i = 0; i < num_row; ++i){
        p_n_empty[i] += cpp_all_na(p_xj[i], false);
      }
      // }
      break;
    }
    default: {
      Rf_unprotect(n_protections);
      Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(p_x[j])));
    }
    }
  }
  Rf_unprotect(n_protections);
  return n_empty;
}

[[cpp11::register]]
SEXP cpp_col_na_counts(SEXP x){
  if (!Rf_isFrame(x)){
    Rf_error("x must be a data frame");
  }
  const SEXP *p_x = VECTOR_PTR_RO(x);
  int num_col = Rf_length(x);
  int n_protections = 0;
  R_xlen_t num_row = cpp_df_nrow(x);
  SEXP out = Rf_protect(Rf_allocVector(INTSXP, num_col));
  ++n_protections;
  int *p_out = INTEGER(out);
  memset(p_out, 0, num_col * sizeof(int));
  for (int j = 0; j < num_col; ++j){
    switch ( TYPEOF(p_x[j]) ){
    case VECSXP: {
      //   if (Rf_inherits(p_x[j], "vctrs_rcrd")){
      //   SEXP rcrd_df = Rf_protect(cpp11::package("cheapr")["vctrs_rcrd_as_df"](p_x[j]));
      //   ++n_protections;
      //   SEXP is_empty_nested = Rf_protect(cpp_missing_row(rcrd_df, 1, true));
      //   ++n_protections;
      //   int *p_is_empty_nested = LOGICAL(is_empty_nested);
      //   for (R_xlen_t k = 0; k < num_row; ++k){
      //     p_out[j] += p_is_empty_nested[k];
      //   }
      // } else {
      if (Rf_xlength(p_x[j]) != num_row){
      int int_nrows = num_row;
      int element_length = Rf_xlength(p_x[j]);
      ++n_protections;
      SEXP names = Rf_protect(Rf_getAttrib(x, R_NamesSymbol));
      Rf_unprotect(n_protections);
      Rf_error("list variable %s has length (%d) not equal to number of rows (%d)",
               CHAR(STRING_ELT(names, j)), element_length, int_nrows);
    }
      for (R_xlen_t i = 0; i < num_row; ++i){
        p_out[j] += cpp_all_na(VECTOR_ELT(p_x[j], i), false);
      }
      // }
      break;
    }
    default: {
      p_out[j] = na_count(p_x[j]);
      break;
    }
    }
  }
  Rf_unprotect(n_protections);
  return out;
}

R_xlen_t cpp_clean_threshold(double threshold, bool threshold_is_prop, R_xlen_t n){
  if (threshold != threshold){
    Rf_error("threshold cannot be NA");
  }
  R_xlen_t out = threshold;
  if (threshold_is_prop){
    if (threshold < 0){
      out = 0;
    } else if (threshold == R_PosInf){
      out = n + 1;
    } else {
      out = std::floor( (threshold * n) + 0.0000000001);
    }
  } else {
    if (threshold < 0){
      out = 0;
    }
    if (threshold == R_PosInf){
      out = n + 1;
    }
  }
  return out;
}

// Are rows empty for at least ncol (>= threshold)?
// or ncol >= floor(threshold * ncol(x)) if threshold is a proportion

[[cpp11::register]]
SEXP cpp_missing_row(SEXP x, double threshold, bool threshold_is_prop){
  if (!Rf_isFrame(x)){
    Rf_error("x must be a data frame");
  }
  if (threshold != threshold){
    Rf_error("threshold cannot be NA");
  }
  R_xlen_t n_rows = cpp_df_nrow(x);
  int n_cols = Rf_length(x);
  int over_threshold;
  int col_threshold = cpp_clean_threshold(threshold, threshold_is_prop, n_cols);
  // Special case when there are 0 cols
  if (n_cols == 0){
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n_rows));
    int *p_out = INTEGER(out);
    memset(p_out, 0, n_rows * sizeof(int));
    Rf_unprotect(1);
    return out;
    // All rows always have >= 0 empty values
  } else if (col_threshold <= 0){
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n_rows));
    int *p_out = INTEGER(out);
#pragma omp for simd
    for (R_xlen_t i = 0; i < n_rows; ++i){
      p_out[i] = 1;
    }
    Rf_unprotect(1);
    return out;
  } else {
    SEXP out = Rf_protect(cpp_row_na_counts(x));
    int *p_out = INTEGER(out);
#pragma omp for simd
    for (R_xlen_t i = 0; i < n_rows; ++i){
      over_threshold = (p_out[i] - col_threshold + 1) >= 1;
      p_out[i] = over_threshold;
    }
    SET_TYPEOF(out, LGLSXP);
    Rf_unprotect(1);
    return out;
  }
}

[[cpp11::register]]
SEXP cpp_missing_col(SEXP x, double threshold, bool threshold_is_prop){
  if (!Rf_isFrame(x)){
    Rf_error("x must be a data frame");
  }
  if (threshold != threshold){
    Rf_error("threshold cannot be NA");
  }
  R_xlen_t n_rows = cpp_df_nrow(x);
  int n_cols = Rf_length(x);
  int over_threshold;
  int row_threshold = cpp_clean_threshold(threshold, threshold_is_prop, n_rows);
  // Special case when there are 0 rows
  if (n_rows == 0){
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n_cols));
    int *p_out = INTEGER(out);
    memset(p_out, 0, n_cols * sizeof(int));
    Rf_unprotect(1);
    return out;
    // All cols always have >= 0 empty values
  } else if (row_threshold <= 0){
    SEXP out = Rf_protect(Rf_allocVector(LGLSXP, n_cols));
    int *p_out = INTEGER(out);
#pragma omp for simd
    for (R_xlen_t i = 0; i < n_rows; ++i){
      p_out[i] = 1;
    }
    Rf_unprotect(1);
    return out;
  } else {
    SEXP out = Rf_protect(cpp_col_na_counts(x));
    int *p_out = INTEGER(out);
#pragma omp for simd
    for (R_xlen_t i = 0; i < n_cols; ++i){
      over_threshold = (p_out[i] - row_threshold + 1) >= 1;
      p_out[i] = over_threshold;
    }
    SET_TYPEOF(out, LGLSXP);
    Rf_unprotect(1);
    return out;
  }
}

// Matrix methods
// The methods for matrices are substantially different

[[cpp11::register]]
SEXP cpp_matrix_row_na_counts(SEXP x){
  if (!Rf_isMatrix(x)){
    Rf_error("x must be a matrix");
  }
  int num_row = Rf_nrows(x);
  R_xlen_t n = Rf_xlength(x);
  SEXP out = Rf_protect(Rf_allocVector(INTSXP, num_row));
  int *p_out = INTEGER(out);
  memset(p_out, 0, num_row * sizeof(int));
  int do_parallel = n >= 100000;
  int n_cores = do_parallel ? num_cores() : 1;
#pragma omp parallel num_threads(n_cores) if(do_parallel)
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    int *p_x = INTEGER(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[i % num_row] += (p_x[i] == NA_INTEGER);
    }
    break;
  }
  case REALSXP: {
    double *p_x = REAL(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[i % num_row] += (p_x[i] != p_x[i]);
    }
    break;
  }
  case STRSXP: {
    SEXP *p_x = STRING_PTR(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[i % num_row] += (p_x[i] == NA_STRING);
    }
    break;
  }
  case RAWSXP: {
    break;
  }
  case CPLXSXP: {
    Rcomplex *p_x = COMPLEX(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[i % num_row] += (p_x[i]).r != (p_x[i]).r || (p_x[i]).i != (p_x[i]).i;
    }
    break;
  }
  default: {
    Rf_unprotect(1);
    Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
  }
  }
  Rf_unprotect(1);
  return out;
}
[[cpp11::register]]
SEXP cpp_matrix_col_na_counts(SEXP x){
  if (!Rf_isMatrix(x)){
    Rf_error("x must be a matrix");
  }
  int num_row = Rf_nrows(x);
  int num_col = Rf_ncols(x);
  R_xlen_t n = Rf_xlength(x);
  SEXP out = Rf_protect(Rf_allocVector(INTSXP, num_col));
  int *p_out = INTEGER(out);
  memset(p_out, 0, num_col * sizeof(int));
  int do_parallel = n >= 100000;
  int n_cores = do_parallel ? num_cores() : 1;
#pragma omp parallel num_threads(n_cores) if(do_parallel)
  switch ( TYPEOF(x) ){
  case LGLSXP:
  case INTSXP: {
    int *p_x = INTEGER(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[int_div(i, num_row)] += (p_x[i] == NA_INTEGER);
    }
    break;
  }
  case REALSXP: {
    double *p_x = REAL(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[int_div(i, num_row)] += (p_x[i] != p_x[i]);
    }
    break;
  }
  case STRSXP: {
    SEXP *p_x = STRING_PTR(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[int_div(i, num_row)] += (p_x[i] == NA_STRING);
    }
    break;
  }
  case RAWSXP: {
    break;
  }
  case CPLXSXP: {
    Rcomplex *p_x = COMPLEX(x);
#pragma omp for
    for (R_xlen_t i = 0; i < n; ++i){
#pragma omp atomic
      p_out[int_div(i, num_row)] += (p_x[i]).r != (p_x[i]).r || (p_x[i]).i != (p_x[i]).i;
    }
    break;
  }
  default: {
    Rf_unprotect(1);
    Rf_error("%s cannot handle an object of type %s", __func__, Rf_type2char(TYPEOF(x)));
  }
  }
  Rf_unprotect(1);
  return out;
}

[[cpp11::register]]
SEXP cpp_matrix_missing_row(SEXP x, double threshold, bool threshold_is_prop){
  if (!Rf_isMatrix(x)){
    Rf_error("x must be a matrix");
  }
  if (threshold != threshold){
    Rf_error("threshold cannot be NA");
  }
  int n_rows = Rf_nrows(x);
  int n_cols = Rf_ncols(x);
  int over_threshold;
  int col_threshold = cpp_clean_threshold(threshold, threshold_is_prop, n_cols);
  SEXP out = Rf_protect(cpp_matrix_row_na_counts(x));
  int *p_out = INTEGER(out);
#pragma omp for simd
  for (int i = 0; i < n_rows; ++i){
    over_threshold = (p_out[i] - col_threshold + 1) >= 1;
    p_out[i] = over_threshold;
  }
  SET_TYPEOF(out, LGLSXP);
  Rf_unprotect(1);
  return out;
}

[[cpp11::register]]
SEXP cpp_matrix_missing_col(SEXP x, double threshold, bool threshold_is_prop){
  if (!Rf_isMatrix(x)){
    Rf_error("x must be a matrix");
  }
  if (threshold != threshold){
    Rf_error("threshold cannot be NA");
  }
  int n_rows = Rf_nrows(x);
  int n_cols = Rf_ncols(x);
  int over_threshold;
  int row_threshold = cpp_clean_threshold(threshold, threshold_is_prop, n_rows);
  SEXP out = Rf_protect(cpp_matrix_col_na_counts(x));
  int *p_out = INTEGER(out);
#pragma omp for simd
  for (int i = 0; i < n_cols; ++i){
    over_threshold = (p_out[i] - row_threshold + 1) >= 1;
    p_out[i] = over_threshold;
  }
  SET_TYPEOF(out, LGLSXP);
  Rf_unprotect(1);
  return out;
}