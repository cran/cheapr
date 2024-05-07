// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// altrep_utils.cpp
bool is_compact_seq(SEXP x);
extern "C" SEXP _cheapr_is_compact_seq(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(is_compact_seq(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// altrep_utils.cpp
SEXP compact_seq_data(SEXP x);
extern "C" SEXP _cheapr_compact_seq_data(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(compact_seq_data(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// attrs.cpp
SEXP cpp_set_rm_attributes(SEXP x);
extern "C" SEXP _cheapr_cpp_set_rm_attributes(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_rm_attributes(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// attrs.cpp
SEXP cpp_set_add_attr(SEXP x, SEXP which, SEXP value);
extern "C" SEXP _cheapr_cpp_set_add_attr(SEXP x, SEXP which, SEXP value) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_add_attr(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(which), cpp11::as_cpp<cpp11::decay_t<SEXP>>(value)));
  END_CPP11
}
// attrs.cpp
SEXP cpp_set_rm_attr(SEXP x, SEXP which);
extern "C" SEXP _cheapr_cpp_set_rm_attr(SEXP x, SEXP which) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_rm_attr(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(which)));
  END_CPP11
}
// attrs.cpp
SEXP cpp_set_add_attributes(SEXP x, SEXP attributes, bool add);
extern "C" SEXP _cheapr_cpp_set_add_attributes(SEXP x, SEXP attributes, SEXP add) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_add_attributes(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(attributes), cpp11::as_cpp<cpp11::decay_t<bool>>(add)));
  END_CPP11
}
// gcd.cpp
double cpp_gcd2(double x, double y, double tol, bool na_rm);
extern "C" SEXP _cheapr_cpp_gcd2(SEXP x, SEXP y, SEXP tol, SEXP na_rm) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_gcd2(cpp11::as_cpp<cpp11::decay_t<double>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(y), cpp11::as_cpp<cpp11::decay_t<double>>(tol), cpp11::as_cpp<cpp11::decay_t<bool>>(na_rm)));
  END_CPP11
}
// gcd.cpp
double cpp_lcm2(double x, double y, double tol, bool na_rm);
extern "C" SEXP _cheapr_cpp_lcm2(SEXP x, SEXP y, SEXP tol, SEXP na_rm) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lcm2(cpp11::as_cpp<cpp11::decay_t<double>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(y), cpp11::as_cpp<cpp11::decay_t<double>>(tol), cpp11::as_cpp<cpp11::decay_t<bool>>(na_rm)));
  END_CPP11
}
// gcd.cpp
SEXP cpp_gcd(SEXP x, double tol, bool na_rm, bool break_early, bool round);
extern "C" SEXP _cheapr_cpp_gcd(SEXP x, SEXP tol, SEXP na_rm, SEXP break_early, SEXP round) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_gcd(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(tol), cpp11::as_cpp<cpp11::decay_t<bool>>(na_rm), cpp11::as_cpp<cpp11::decay_t<bool>>(break_early), cpp11::as_cpp<cpp11::decay_t<bool>>(round)));
  END_CPP11
}
// gcd.cpp
SEXP cpp_lcm(SEXP x, double tol, bool na_rm);
extern "C" SEXP _cheapr_cpp_lcm(SEXP x, SEXP tol, SEXP na_rm) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lcm(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(tol), cpp11::as_cpp<cpp11::decay_t<bool>>(na_rm)));
  END_CPP11
}
// gcd.cpp
SEXP cpp_gcd2_vectorised(SEXP x, SEXP y, double tol, bool na_rm);
extern "C" SEXP _cheapr_cpp_gcd2_vectorised(SEXP x, SEXP y, SEXP tol, SEXP na_rm) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_gcd2_vectorised(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(y), cpp11::as_cpp<cpp11::decay_t<double>>(tol), cpp11::as_cpp<cpp11::decay_t<bool>>(na_rm)));
  END_CPP11
}
// gcd.cpp
SEXP cpp_lcm2_vectorised(SEXP x, SEXP y, double tol, bool na_rm);
extern "C" SEXP _cheapr_cpp_lcm2_vectorised(SEXP x, SEXP y, SEXP tol, SEXP na_rm) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lcm2_vectorised(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(y), cpp11::as_cpp<cpp11::decay_t<double>>(tol), cpp11::as_cpp<cpp11::decay_t<bool>>(na_rm)));
  END_CPP11
}
// lag.cpp
SEXP cpp_lag(SEXP x, R_xlen_t k, SEXP fill, bool set, bool recursive);
extern "C" SEXP _cheapr_cpp_lag(SEXP x, SEXP k, SEXP fill, SEXP set, SEXP recursive) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lag(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<R_xlen_t>>(k), cpp11::as_cpp<cpp11::decay_t<SEXP>>(fill), cpp11::as_cpp<cpp11::decay_t<bool>>(set), cpp11::as_cpp<cpp11::decay_t<bool>>(recursive)));
  END_CPP11
}
// lag.cpp
SEXP cpp_lag2(SEXP x, SEXP lag, SEXP order, SEXP run_lengths, SEXP fill, bool recursive);
extern "C" SEXP _cheapr_cpp_lag2(SEXP x, SEXP lag, SEXP order, SEXP run_lengths, SEXP fill, SEXP recursive) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lag2(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(lag), cpp11::as_cpp<cpp11::decay_t<SEXP>>(order), cpp11::as_cpp<cpp11::decay_t<SEXP>>(run_lengths), cpp11::as_cpp<cpp11::decay_t<SEXP>>(fill), cpp11::as_cpp<cpp11::decay_t<bool>>(recursive)));
  END_CPP11
}
// nas.cpp
SEXP cpp_num_na(SEXP x, bool recursive);
extern "C" SEXP _cheapr_cpp_num_na(SEXP x, SEXP recursive) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_num_na(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<bool>>(recursive)));
  END_CPP11
}
// nas.cpp
bool cpp_any_na(SEXP x, bool recursive);
extern "C" SEXP _cheapr_cpp_any_na(SEXP x, SEXP recursive) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_any_na(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<bool>>(recursive)));
  END_CPP11
}
// nas.cpp
bool cpp_all_na(SEXP x, bool return_true_on_empty, bool recursive);
extern "C" SEXP _cheapr_cpp_all_na(SEXP x, SEXP return_true_on_empty, SEXP recursive) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_all_na(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<bool>>(return_true_on_empty), cpp11::as_cpp<cpp11::decay_t<bool>>(recursive)));
  END_CPP11
}
// nas.cpp
SEXP cpp_is_na(SEXP x);
extern "C" SEXP _cheapr_cpp_is_na(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_is_na(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// nas.cpp
SEXP cpp_which_na(SEXP x);
extern "C" SEXP _cheapr_cpp_which_na(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_which_na(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// nas.cpp
SEXP cpp_which_not_na(SEXP x);
extern "C" SEXP _cheapr_cpp_which_not_na(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_which_not_na(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// nas.cpp
SEXP cpp_row_na_counts(SEXP x);
extern "C" SEXP _cheapr_cpp_row_na_counts(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_row_na_counts(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// nas.cpp
SEXP cpp_col_na_counts(SEXP x);
extern "C" SEXP _cheapr_cpp_col_na_counts(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_col_na_counts(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// nas.cpp
SEXP cpp_missing_row(SEXP x, double threshold, bool threshold_is_prop);
extern "C" SEXP _cheapr_cpp_missing_row(SEXP x, SEXP threshold, SEXP threshold_is_prop) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_missing_row(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(threshold), cpp11::as_cpp<cpp11::decay_t<bool>>(threshold_is_prop)));
  END_CPP11
}
// nas.cpp
SEXP cpp_missing_col(SEXP x, double threshold, bool threshold_is_prop);
extern "C" SEXP _cheapr_cpp_missing_col(SEXP x, SEXP threshold, SEXP threshold_is_prop) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_missing_col(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(threshold), cpp11::as_cpp<cpp11::decay_t<bool>>(threshold_is_prop)));
  END_CPP11
}
// nas.cpp
SEXP cpp_matrix_row_na_counts(SEXP x);
extern "C" SEXP _cheapr_cpp_matrix_row_na_counts(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_matrix_row_na_counts(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// nas.cpp
SEXP cpp_matrix_col_na_counts(SEXP x);
extern "C" SEXP _cheapr_cpp_matrix_col_na_counts(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_matrix_col_na_counts(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// nas.cpp
SEXP cpp_matrix_missing_row(SEXP x, double threshold, bool threshold_is_prop);
extern "C" SEXP _cheapr_cpp_matrix_missing_row(SEXP x, SEXP threshold, SEXP threshold_is_prop) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_matrix_missing_row(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(threshold), cpp11::as_cpp<cpp11::decay_t<bool>>(threshold_is_prop)));
  END_CPP11
}
// nas.cpp
SEXP cpp_matrix_missing_col(SEXP x, double threshold, bool threshold_is_prop);
extern "C" SEXP _cheapr_cpp_matrix_missing_col(SEXP x, SEXP threshold, SEXP threshold_is_prop) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_matrix_missing_col(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<double>>(threshold), cpp11::as_cpp<cpp11::decay_t<bool>>(threshold_is_prop)));
  END_CPP11
}
// nas.cpp
SEXP cpp_count_val(SEXP x, SEXP value, bool recursive);
extern "C" SEXP _cheapr_cpp_count_val(SEXP x, SEXP value, SEXP recursive) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_count_val(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(value), cpp11::as_cpp<cpp11::decay_t<bool>>(recursive)));
  END_CPP11
}
// sequences.cpp
SEXP cpp_int_sequence(SEXP size, SEXP from, SEXP by);
extern "C" SEXP _cheapr_cpp_int_sequence(SEXP size, SEXP from, SEXP by) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_int_sequence(cpp11::as_cpp<cpp11::decay_t<SEXP>>(size), cpp11::as_cpp<cpp11::decay_t<SEXP>>(from), cpp11::as_cpp<cpp11::decay_t<SEXP>>(by)));
  END_CPP11
}
// sequences.cpp
SEXP cpp_dbl_sequence(SEXP size, SEXP from, SEXP by);
extern "C" SEXP _cheapr_cpp_dbl_sequence(SEXP size, SEXP from, SEXP by) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_dbl_sequence(cpp11::as_cpp<cpp11::decay_t<SEXP>>(size), cpp11::as_cpp<cpp11::decay_t<SEXP>>(from), cpp11::as_cpp<cpp11::decay_t<SEXP>>(by)));
  END_CPP11
}
// sequences.cpp
SEXP cpp_sequence(SEXP size, SEXP from, SEXP by);
extern "C" SEXP _cheapr_cpp_sequence(SEXP size, SEXP from, SEXP by) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_sequence(cpp11::as_cpp<cpp11::decay_t<SEXP>>(size), cpp11::as_cpp<cpp11::decay_t<SEXP>>(from), cpp11::as_cpp<cpp11::decay_t<SEXP>>(by)));
  END_CPP11
}
// sequences.cpp
SEXP cpp_window_sequence(SEXP size, double k, bool partial, bool ascending);
extern "C" SEXP _cheapr_cpp_window_sequence(SEXP size, SEXP k, SEXP partial, SEXP ascending) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_window_sequence(cpp11::as_cpp<cpp11::decay_t<SEXP>>(size), cpp11::as_cpp<cpp11::decay_t<double>>(k), cpp11::as_cpp<cpp11::decay_t<bool>>(partial), cpp11::as_cpp<cpp11::decay_t<bool>>(ascending)));
  END_CPP11
}
// sequences.cpp
SEXP cpp_lag_sequence(SEXP size, double k, bool partial);
extern "C" SEXP _cheapr_cpp_lag_sequence(SEXP size, SEXP k, SEXP partial) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lag_sequence(cpp11::as_cpp<cpp11::decay_t<SEXP>>(size), cpp11::as_cpp<cpp11::decay_t<double>>(k), cpp11::as_cpp<cpp11::decay_t<bool>>(partial)));
  END_CPP11
}
// sequences.cpp
SEXP cpp_lead_sequence(SEXP size, double k, bool partial);
extern "C" SEXP _cheapr_cpp_lead_sequence(SEXP size, SEXP k, SEXP partial) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lead_sequence(cpp11::as_cpp<cpp11::decay_t<SEXP>>(size), cpp11::as_cpp<cpp11::decay_t<double>>(k), cpp11::as_cpp<cpp11::decay_t<bool>>(partial)));
  END_CPP11
}
// sequences.cpp
SEXP cpp_sequence_id(SEXP size);
extern "C" SEXP _cheapr_cpp_sequence_id(SEXP size) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_sequence_id(cpp11::as_cpp<cpp11::decay_t<SEXP>>(size)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_abs(SEXP x);
extern "C" SEXP _cheapr_cpp_set_abs(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_abs(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_floor(SEXP x);
extern "C" SEXP _cheapr_cpp_set_floor(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_floor(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_ceiling(SEXP x);
extern "C" SEXP _cheapr_cpp_set_ceiling(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_ceiling(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_trunc(SEXP x);
extern "C" SEXP _cheapr_cpp_set_trunc(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_trunc(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_change_sign(SEXP x);
extern "C" SEXP _cheapr_cpp_set_change_sign(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_change_sign(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_exp(SEXP x);
extern "C" SEXP _cheapr_cpp_set_exp(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_exp(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_sqrt(SEXP x);
extern "C" SEXP _cheapr_cpp_set_sqrt(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_sqrt(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_add(SEXP x, SEXP y);
extern "C" SEXP _cheapr_cpp_set_add(SEXP x, SEXP y) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_add(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(y)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_subtract(SEXP x, SEXP y);
extern "C" SEXP _cheapr_cpp_set_subtract(SEXP x, SEXP y) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_subtract(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(y)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_multiply(SEXP x, SEXP y);
extern "C" SEXP _cheapr_cpp_set_multiply(SEXP x, SEXP y) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_multiply(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(y)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_divide(SEXP x, SEXP y);
extern "C" SEXP _cheapr_cpp_set_divide(SEXP x, SEXP y) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_divide(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(y)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_pow(SEXP x, SEXP y);
extern "C" SEXP _cheapr_cpp_set_pow(SEXP x, SEXP y) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_pow(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(y)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_log(SEXP x, SEXP base);
extern "C" SEXP _cheapr_cpp_set_log(SEXP x, SEXP base) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_log(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(base)));
  END_CPP11
}
// set_math.cpp
SEXP cpp_set_round(SEXP x, SEXP digits);
extern "C" SEXP _cheapr_cpp_set_round(SEXP x, SEXP digits) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_set_round(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(digits)));
  END_CPP11
}
// sset.cpp
SEXP cpp_sset_range(SEXP x, R_xlen_t from, R_xlen_t to, R_xlen_t by);
extern "C" SEXP _cheapr_cpp_sset_range(SEXP x, SEXP from, SEXP to, SEXP by) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_sset_range(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<R_xlen_t>>(from), cpp11::as_cpp<cpp11::decay_t<R_xlen_t>>(to), cpp11::as_cpp<cpp11::decay_t<R_xlen_t>>(by)));
  END_CPP11
}
// sset.cpp
SEXP cpp_sset_df(SEXP x, SEXP indices);
extern "C" SEXP _cheapr_cpp_sset_df(SEXP x, SEXP indices) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_sset_df(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(indices)));
  END_CPP11
}
// utils.cpp
R_xlen_t cpp_vec_length(SEXP x);
extern "C" SEXP _cheapr_cpp_vec_length(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_vec_length(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// utils.cpp
SEXP cpp_r_unnested_length(SEXP x);
extern "C" SEXP _cheapr_cpp_r_unnested_length(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_r_unnested_length(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// utils.cpp
SEXP cpp_lengths(SEXP x);
extern "C" SEXP _cheapr_cpp_lengths(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_lengths(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// utils.cpp
SEXP cpp_new_list(R_xlen_t size, SEXP default_value);
extern "C" SEXP _cheapr_cpp_new_list(SEXP size, SEXP default_value) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_new_list(cpp11::as_cpp<cpp11::decay_t<R_xlen_t>>(size), cpp11::as_cpp<cpp11::decay_t<SEXP>>(default_value)));
  END_CPP11
}
// utils.cpp
SEXP cpp_drop_null(SEXP l, bool always_shallow_copy);
extern "C" SEXP _cheapr_cpp_drop_null(SEXP l, SEXP always_shallow_copy) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_drop_null(cpp11::as_cpp<cpp11::decay_t<SEXP>>(l), cpp11::as_cpp<cpp11::decay_t<bool>>(always_shallow_copy)));
  END_CPP11
}
// utils.cpp
SEXP cpp_list_as_df(SEXP x);
extern "C" SEXP _cheapr_cpp_list_as_df(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_list_as_df(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// utils.cpp
SEXP r_copy(SEXP x);
extern "C" SEXP _cheapr_r_copy(SEXP x) {
  BEGIN_CPP11
    return cpp11::as_sexp(r_copy(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x)));
  END_CPP11
}
// which.cpp
SEXP cpp_which_(SEXP x, bool invert);
extern "C" SEXP _cheapr_cpp_which_(SEXP x, SEXP invert) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_which_(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<bool>>(invert)));
  END_CPP11
}
// which.cpp
SEXP cpp_which_val(SEXP x, SEXP value, bool invert);
extern "C" SEXP _cheapr_cpp_which_val(SEXP x, SEXP value, SEXP invert) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_which_val(cpp11::as_cpp<cpp11::decay_t<SEXP>>(x), cpp11::as_cpp<cpp11::decay_t<SEXP>>(value), cpp11::as_cpp<cpp11::decay_t<bool>>(invert)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_cheapr_compact_seq_data",         (DL_FUNC) &_cheapr_compact_seq_data,         1},
    {"_cheapr_cpp_all_na",               (DL_FUNC) &_cheapr_cpp_all_na,               3},
    {"_cheapr_cpp_any_na",               (DL_FUNC) &_cheapr_cpp_any_na,               2},
    {"_cheapr_cpp_col_na_counts",        (DL_FUNC) &_cheapr_cpp_col_na_counts,        1},
    {"_cheapr_cpp_count_val",            (DL_FUNC) &_cheapr_cpp_count_val,            3},
    {"_cheapr_cpp_dbl_sequence",         (DL_FUNC) &_cheapr_cpp_dbl_sequence,         3},
    {"_cheapr_cpp_drop_null",            (DL_FUNC) &_cheapr_cpp_drop_null,            2},
    {"_cheapr_cpp_gcd",                  (DL_FUNC) &_cheapr_cpp_gcd,                  5},
    {"_cheapr_cpp_gcd2",                 (DL_FUNC) &_cheapr_cpp_gcd2,                 4},
    {"_cheapr_cpp_gcd2_vectorised",      (DL_FUNC) &_cheapr_cpp_gcd2_vectorised,      4},
    {"_cheapr_cpp_int_sequence",         (DL_FUNC) &_cheapr_cpp_int_sequence,         3},
    {"_cheapr_cpp_is_na",                (DL_FUNC) &_cheapr_cpp_is_na,                1},
    {"_cheapr_cpp_lag",                  (DL_FUNC) &_cheapr_cpp_lag,                  5},
    {"_cheapr_cpp_lag2",                 (DL_FUNC) &_cheapr_cpp_lag2,                 6},
    {"_cheapr_cpp_lag_sequence",         (DL_FUNC) &_cheapr_cpp_lag_sequence,         3},
    {"_cheapr_cpp_lcm",                  (DL_FUNC) &_cheapr_cpp_lcm,                  3},
    {"_cheapr_cpp_lcm2",                 (DL_FUNC) &_cheapr_cpp_lcm2,                 4},
    {"_cheapr_cpp_lcm2_vectorised",      (DL_FUNC) &_cheapr_cpp_lcm2_vectorised,      4},
    {"_cheapr_cpp_lead_sequence",        (DL_FUNC) &_cheapr_cpp_lead_sequence,        3},
    {"_cheapr_cpp_lengths",              (DL_FUNC) &_cheapr_cpp_lengths,              1},
    {"_cheapr_cpp_list_as_df",           (DL_FUNC) &_cheapr_cpp_list_as_df,           1},
    {"_cheapr_cpp_matrix_col_na_counts", (DL_FUNC) &_cheapr_cpp_matrix_col_na_counts, 1},
    {"_cheapr_cpp_matrix_missing_col",   (DL_FUNC) &_cheapr_cpp_matrix_missing_col,   3},
    {"_cheapr_cpp_matrix_missing_row",   (DL_FUNC) &_cheapr_cpp_matrix_missing_row,   3},
    {"_cheapr_cpp_matrix_row_na_counts", (DL_FUNC) &_cheapr_cpp_matrix_row_na_counts, 1},
    {"_cheapr_cpp_missing_col",          (DL_FUNC) &_cheapr_cpp_missing_col,          3},
    {"_cheapr_cpp_missing_row",          (DL_FUNC) &_cheapr_cpp_missing_row,          3},
    {"_cheapr_cpp_new_list",             (DL_FUNC) &_cheapr_cpp_new_list,             2},
    {"_cheapr_cpp_num_na",               (DL_FUNC) &_cheapr_cpp_num_na,               2},
    {"_cheapr_cpp_r_unnested_length",    (DL_FUNC) &_cheapr_cpp_r_unnested_length,    1},
    {"_cheapr_cpp_row_na_counts",        (DL_FUNC) &_cheapr_cpp_row_na_counts,        1},
    {"_cheapr_cpp_sequence",             (DL_FUNC) &_cheapr_cpp_sequence,             3},
    {"_cheapr_cpp_sequence_id",          (DL_FUNC) &_cheapr_cpp_sequence_id,          1},
    {"_cheapr_cpp_set_abs",              (DL_FUNC) &_cheapr_cpp_set_abs,              1},
    {"_cheapr_cpp_set_add",              (DL_FUNC) &_cheapr_cpp_set_add,              2},
    {"_cheapr_cpp_set_add_attr",         (DL_FUNC) &_cheapr_cpp_set_add_attr,         3},
    {"_cheapr_cpp_set_add_attributes",   (DL_FUNC) &_cheapr_cpp_set_add_attributes,   3},
    {"_cheapr_cpp_set_ceiling",          (DL_FUNC) &_cheapr_cpp_set_ceiling,          1},
    {"_cheapr_cpp_set_change_sign",      (DL_FUNC) &_cheapr_cpp_set_change_sign,      1},
    {"_cheapr_cpp_set_divide",           (DL_FUNC) &_cheapr_cpp_set_divide,           2},
    {"_cheapr_cpp_set_exp",              (DL_FUNC) &_cheapr_cpp_set_exp,              1},
    {"_cheapr_cpp_set_floor",            (DL_FUNC) &_cheapr_cpp_set_floor,            1},
    {"_cheapr_cpp_set_log",              (DL_FUNC) &_cheapr_cpp_set_log,              2},
    {"_cheapr_cpp_set_multiply",         (DL_FUNC) &_cheapr_cpp_set_multiply,         2},
    {"_cheapr_cpp_set_pow",              (DL_FUNC) &_cheapr_cpp_set_pow,              2},
    {"_cheapr_cpp_set_rm_attr",          (DL_FUNC) &_cheapr_cpp_set_rm_attr,          2},
    {"_cheapr_cpp_set_rm_attributes",    (DL_FUNC) &_cheapr_cpp_set_rm_attributes,    1},
    {"_cheapr_cpp_set_round",            (DL_FUNC) &_cheapr_cpp_set_round,            2},
    {"_cheapr_cpp_set_sqrt",             (DL_FUNC) &_cheapr_cpp_set_sqrt,             1},
    {"_cheapr_cpp_set_subtract",         (DL_FUNC) &_cheapr_cpp_set_subtract,         2},
    {"_cheapr_cpp_set_trunc",            (DL_FUNC) &_cheapr_cpp_set_trunc,            1},
    {"_cheapr_cpp_sset_df",              (DL_FUNC) &_cheapr_cpp_sset_df,              2},
    {"_cheapr_cpp_sset_range",           (DL_FUNC) &_cheapr_cpp_sset_range,           4},
    {"_cheapr_cpp_vec_length",           (DL_FUNC) &_cheapr_cpp_vec_length,           1},
    {"_cheapr_cpp_which_",               (DL_FUNC) &_cheapr_cpp_which_,               2},
    {"_cheapr_cpp_which_na",             (DL_FUNC) &_cheapr_cpp_which_na,             1},
    {"_cheapr_cpp_which_not_na",         (DL_FUNC) &_cheapr_cpp_which_not_na,         1},
    {"_cheapr_cpp_which_val",            (DL_FUNC) &_cheapr_cpp_which_val,            3},
    {"_cheapr_cpp_window_sequence",      (DL_FUNC) &_cheapr_cpp_window_sequence,      4},
    {"_cheapr_is_compact_seq",           (DL_FUNC) &_cheapr_is_compact_seq,           1},
    {"_cheapr_r_copy",                   (DL_FUNC) &_cheapr_r_copy,                   1},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_cheapr(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
