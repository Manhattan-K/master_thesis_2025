/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeConstraints_.c
 *
 * Code generation for function 'computeConstraints_'
 *
 */

/* Include files */
#include "computeConstraints_.h"
#include "checkVectorNonFinite.h"
#include "constraints.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_types.h"
#include "followerMPCandUpdate.h"
#include "rt_nonfinite.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
int32_T b_computeConstraints_(int32_T c_obj_next_next_next_next_next_,
                              const real_T d_obj_next_next_next_next_next_[3],
                              const struct5_T *e_obj_next_next_next_next_next_,
                              real_T f_obj_next_next_next_next_next_,
                              const struct3_T g_obj_next_next_next_next_next_,
                              const real_T x[40], real_T Cineq_workspace_data[],
                              int32_T ineq0)
{
  real_T varargout_1_data[4200];
  int32_T ineqRange_data[4200];
  int32_T i;
  int32_T k;
  int32_T status;
  int32_T vectorUB;
  int32_T yk;
  if (c_obj_next_next_next_next_next_ - 1 < 0) {
    status = 0;
  } else {
    status = (uint16_T)(c_obj_next_next_next_next_next_ - 1) + 1;
  }
  if (status > 0) {
    ineqRange_data[0] = 0;
    yk = 0;
    for (k = 2; k <= status; k++) {
      yk++;
      ineqRange_data[k - 1] = yk;
    }
  }
  yk = status - 1;
  k = (status / 8) << 3;
  vectorUB = k - 8;
  for (i = 0; i <= vectorUB; i += 8) {
    __m256i r;
    r = _mm256_loadu_si256((const __m256i *)&ineqRange_data[i]);
    _mm256_storeu_si256((__m256i *)&ineqRange_data[i],
                        _mm256_add_epi32(r, _mm256_set1_epi32(ineq0)));
  }
  for (i = k; i <= yk; i++) {
    ineqRange_data[i] += ineq0;
  }
  emlrtMEXProfilingFunctionEntry((char_T *)c_completeName, isMexOutdated);
  constraints(
      x, d_obj_next_next_next_next_next_, e_obj_next_next_next_next_next_->M_l,
      e_obj_next_next_next_next_next_->A_bar_l,
      e_obj_next_next_next_next_next_->B_bar_l.data,
      e_obj_next_next_next_next_next_->B_bar_l.size[0],
      f_obj_next_next_next_next_next_, g_obj_next_next_next_next_next_.n,
      g_obj_next_next_next_next_next_.Ts, varargout_1_data);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  for (i = 0; i < status; i++) {
    Cineq_workspace_data[ineqRange_data[i] - 1] = varargout_1_data[i];
  }
  return checkVectorNonFinite(c_obj_next_next_next_next_next_,
                              Cineq_workspace_data, ineq0);
}

int32_T c_computeConstraints_(int32_T c_obj_next_next_next_next_next_,
                              const real_T d_obj_next_next_next_next_next_[3],
                              const struct5_T *e_obj_next_next_next_next_next_,
                              real_T f_obj_next_next_next_next_next_,
                              const struct3_T g_obj_next_next_next_next_next_,
                              const real_T x[40], real_T Cineq_workspace_data[],
                              int32_T ineq0)
{
  real_T varargout_1_data[4200];
  int32_T ineqRange_data[4200];
  int32_T i;
  int32_T k;
  int32_T status;
  int32_T vectorUB;
  int32_T yk;
  if (c_obj_next_next_next_next_next_ - 1 < 0) {
    status = 0;
  } else {
    status = (uint16_T)(c_obj_next_next_next_next_next_ - 1) + 1;
  }
  if (status > 0) {
    ineqRange_data[0] = 0;
    yk = 0;
    for (k = 2; k <= status; k++) {
      yk++;
      ineqRange_data[k - 1] = yk;
    }
  }
  yk = status - 1;
  k = (status / 8) << 3;
  vectorUB = k - 8;
  for (i = 0; i <= vectorUB; i += 8) {
    __m256i r;
    r = _mm256_loadu_si256((const __m256i *)&ineqRange_data[i]);
    _mm256_storeu_si256((__m256i *)&ineqRange_data[i],
                        _mm256_add_epi32(r, _mm256_set1_epi32(ineq0)));
  }
  for (i = k; i <= yk; i++) {
    ineqRange_data[i] += ineq0;
  }
  emlrtMEXProfilingFunctionEntry((char_T *)e_completeName, isMexOutdated);
  constraints(
      x, d_obj_next_next_next_next_next_, e_obj_next_next_next_next_next_->M_l,
      e_obj_next_next_next_next_next_->A_bar_l,
      e_obj_next_next_next_next_next_->B_bar_l.data,
      e_obj_next_next_next_next_next_->B_bar_l.size[0],
      f_obj_next_next_next_next_next_, g_obj_next_next_next_next_next_.n,
      g_obj_next_next_next_next_next_.Ts, varargout_1_data);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  for (i = 0; i < status; i++) {
    Cineq_workspace_data[ineqRange_data[i] - 1] = varargout_1_data[i];
  }
  return checkVectorNonFinite(c_obj_next_next_next_next_next_,
                              Cineq_workspace_data, ineq0);
}

int32_T computeConstraints_(int32_T c_obj_next_next_next_next_next_,
                            const real_T d_obj_next_next_next_next_next_[3],
                            const struct5_T *e_obj_next_next_next_next_next_,
                            real_T f_obj_next_next_next_next_next_,
                            const struct3_T g_obj_next_next_next_next_next_,
                            const real_T x[40], real_T Cineq_workspace_data[],
                            int32_T ineq0)
{
  real_T varargout_1_data[800];
  int32_T ineqRange_data[800];
  int32_T k;
  int32_T status;
  int32_T yk;
  uint16_T y_data[4200];
  if (c_obj_next_next_next_next_next_ - 1 < 0) {
    status = 0;
  } else {
    status = (uint16_T)(c_obj_next_next_next_next_next_ - 1) + 1;
  }
  if (status > 0) {
    y_data[0] = 0U;
    yk = 0;
    for (k = 2; k <= status; k++) {
      yk++;
      y_data[k - 1] = (uint16_T)yk;
    }
  }
  for (yk = 0; yk < status; yk++) {
    ineqRange_data[yk] = y_data[yk] + ineq0;
  }
  followerMPCandUpdate_anonFcn2(
      d_obj_next_next_next_next_next_, e_obj_next_next_next_next_next_->M_f,
      e_obj_next_next_next_next_next_->A_bar_f,
      e_obj_next_next_next_next_next_->B_bar_f.data,
      e_obj_next_next_next_next_next_->B_bar_f.size[0],
      f_obj_next_next_next_next_next_, g_obj_next_next_next_next_next_.n,
      g_obj_next_next_next_next_next_.Ts, x, varargout_1_data);
  for (yk = 0; yk < status; yk++) {
    Cineq_workspace_data[ineqRange_data[yk] - 1] = varargout_1_data[yk];
  }
  return checkVectorNonFinite(c_obj_next_next_next_next_next_,
                              Cineq_workspace_data, ineq0);
}

/* End of code generation (computeConstraints_.c) */
