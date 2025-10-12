/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * constraints.c
 *
 * Code generation for function 'constraints'
 *
 */

/* Include files */
#include "constraints.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void binary_expand_op(emxArray_real_T *in1, const real_T in2_data[],
                      const int32_T *in2_size, const real_T in3_data[],
                      const int32_T *in3_size)
{
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in3_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in3_size;
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in3_size != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_0] - in3_data[i * stride_1_0];
  }
}

int32_T constraints(const real_T U[40], const real_T x0[3], real_T M,
                    const emxArray_real_T *A_bar, const real_T B_bar_data[],
                    int32_T B_bar_size, real_T N, real_T sys_n, real_T sys_Ts,
                    real_T c_data[])
{
  emxArray_real_T *c_obst_av;
  real_T tmp_data[4200];
  real_T *c_obst_av_data;
  int32_T c_size;
  int32_T i;
  int32_T tmp_size;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)constraints_complete_name,
                                 isMexOutdated);
  /*  Obtain the number of vertices */
  /*  Obtain the number of states n and number of inputs m */
  /*  Obstacle avoidance */
  /*  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0 */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  emlrtMEXProfilingStatement(4, isMexOutdated);
  emxInit_real_T(&c_obst_av, 1);
  c_obst_av_data = c_obst_av->data;
  if (M >= 1.0) {
    emlrtMEXProfilingStatement(5, isMexOutdated);
    stateEvolution(U, x0, sys_n, sys_Ts, N, c_obst_av);
    emlrtMEXProfilingStatement(6, isMexOutdated);
    tmp_size = mtimes(A_bar, c_obst_av, tmp_data);
    if (tmp_size == B_bar_size) {
      int32_T vectorUB;
      i = c_obst_av->size[0];
      c_obst_av->size[0] = tmp_size;
      emxEnsureCapacity_real_T(c_obst_av, i);
      c_obst_av_data = c_obst_av->data;
      c_size = (tmp_size / 4) << 2;
      vectorUB = c_size - 4;
      for (i = 0; i <= vectorUB; i += 4) {
        __m256d r;
        r = _mm256_loadu_pd(&tmp_data[i]);
        _mm256_storeu_pd(&c_obst_av_data[i],
                         _mm256_sub_pd(r, _mm256_loadu_pd(&B_bar_data[i])));
      }
      for (i = c_size; i < tmp_size; i++) {
        c_obst_av_data[i] = tmp_data[i] - B_bar_data[i];
      }
    } else {
      binary_expand_op(c_obst_av, tmp_data, &tmp_size, B_bar_data, &B_bar_size);
      c_obst_av_data = c_obst_av->data;
    }
    emlrtMEXProfilingStatement(9, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(7, isMexOutdated);
    /*  If there are no constraints */
    emlrtMEXProfilingStatement(8, isMexOutdated);
    c_obst_av->size[0] = 0;
    emlrtMEXProfilingStatement(9, isMexOutdated);
  }
  /*  Input constraints */
  /*  Defined in the fmincon function */
  /*  Final output */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  tmp_size = c_obst_av->size[0];
  c_size = c_obst_av->size[0];
  for (i = 0; i < tmp_size; i++) {
    c_data[i] = c_obst_av_data[i];
  }
  emxFree_real_T(&c_obst_av);
  emlrtMEXProfilingStatement(12, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return c_size;
}

/* End of code generation (constraints.c) */
