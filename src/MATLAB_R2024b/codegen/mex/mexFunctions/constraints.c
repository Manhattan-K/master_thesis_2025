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
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "omp.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void binary_expand_op(emlrtCTX aTLS, emxArray_real_T *in1,
                      const real_T in2_data[], const int32_T *in2_size,
                      const real_T in3_data[], const int32_T *in3_size)
{
  jmp_buf *volatile emlrtJBStack;
  real_T *in1_data;
  int32_T binary_expand_op_numThreads;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in3_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in3_size;
  }
  stride_0_0 = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, stride_0_0);
  in1_data = in1->data;
  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in3_size != 1);
  if (loop_ub < 1200) {
    for (i = 0; i < loop_ub; i++) {
      in1_data[i] = in2_data[i * stride_0_0] - in3_data[i * stride_1_0];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    binary_expand_op_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_numThreads)

    for (i = 0; i < loop_ub; i++) {
      in1_data[i] = in2_data[i * stride_0_0] - in3_data[i * stride_1_0];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
}

int32_T constraints(emlrtCTX aTLS, const real_T U[40], const real_T x0[3],
                    real_T M, const emxArray_real_T *A_bar,
                    const real_T B_bar_data[], int32_T B_bar_size, real_T N,
                    real_T sys_n, real_T sys_Ts, real_T c_data[])
{
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T *c_obst_av;
  real_T tmp_data[4200];
  real_T *c_obst_av_data;
  int32_T c_size;
  int32_T constraints_numThreads;
  int32_T i;
  int32_T scalarLB;
  int32_T vectorUB;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
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
    c_size = mtimes(A_bar, c_obst_av, tmp_data);
    if (c_size == B_bar_size) {
      scalarLB = c_obst_av->size[0];
      c_obst_av->size[0] = c_size;
      emxEnsureCapacity_real_T(c_obst_av, scalarLB);
      c_obst_av_data = c_obst_av->data;
      scalarLB = (c_size / 4) << 2;
      vectorUB = scalarLB - 4;
      for (i = 0; i <= vectorUB; i += 4) {
        __m256d r;
        r = _mm256_loadu_pd(&tmp_data[i]);
        _mm256_storeu_pd(&c_obst_av_data[i],
                         _mm256_sub_pd(r, _mm256_loadu_pd(&B_bar_data[i])));
      }
      if (c_size - scalarLB < 1200) {
        for (i = scalarLB; i < c_size; i++) {
          c_obst_av_data[i] = tmp_data[i] - B_bar_data[i];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        constraints_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(constraints_numThreads)

        for (i = scalarLB; i < c_size; i++) {
          c_obst_av_data[i] = tmp_data[i] - B_bar_data[i];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    } else {
      binary_expand_op(aTLS, c_obst_av, tmp_data, &c_size, B_bar_data,
                       &B_bar_size);
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
  scalarLB = c_obst_av->size[0];
  c_size = c_obst_av->size[0];
  vectorUB = c_obst_av->size[0];
  if (c_obst_av->size[0] < 1200) {
    for (i = 0; i < scalarLB; i++) {
      c_data[i] = c_obst_av_data[i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    constraints_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(constraints_numThreads)

    for (i = 0; i < vectorUB; i++) {
      c_data[i] = c_obst_av_data[i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  emxFree_real_T(&c_obst_av);
  emlrtMEXProfilingStatement(12, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
  return c_size;
}

/* End of code generation (constraints.c) */
