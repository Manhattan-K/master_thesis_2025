/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_mtimes_helper.c
 *
 * Code generation for function 'eml_mtimes_helper'
 *
 */

/* Include files */
#include "eml_mtimes_helper.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void binary_expand_op_1(emlrtCTX aTLS, emxArray_real_T *in1,
                        const real_T in2[6], const emxArray_real_T *in3,
                        const real_T in4[3], int32_T in5, const real_T in6[2])
{
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T c_in4;
  emxArray_real_T *b_in3;
  emxArray_real_T *b_in4;
  const real_T *in3_data;
  real_T *b_in3_data;
  real_T *in4_data;
  int32_T b_in6[2];
  int32_T b_loop_ub;
  int32_T binary_expand_op_1_numThreads;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  emxInit_real_T(&b_in4, 1);
  i = b_in4->size[0];
  b_in4->size[0] = in5 + 4;
  emxEnsureCapacity_real_T(b_in4, i);
  in4_data = b_in4->data;
  in4_data[0] = in4[0];
  in4_data[1] = in4[1];
  in4_data[2] = in4[2];
  if (in5 + 1 < 1200) {
    for (i1 = 0; i1 <= in5; i1++) {
      in4_data[i1 + 3] = in3_data[i1];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    binary_expand_op_1_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_1_numThreads)

    for (i1 = 0; i1 <= in5; i1++) {
      in4_data[i1 + 3] = in3_data[i1];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  emxInit_real_T(&b_in3, 1);
  loop_ub = b_in4->size[0];
  i = b_in3->size[0];
  b_in3->size[0] = b_in4->size[0];
  emxEnsureCapacity_real_T(b_in3, i);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  b_loop_ub = b_in4->size[0];
  i = (b_in4->size[0] < 1200);
  if (i) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in3_data[i1] = in3_data[i1 * stride_0_0] - in4_data[i1];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    binary_expand_op_1_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_1_numThreads)

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in3_data[i1] = in3_data[i1 * stride_0_0] - in4_data[i1];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  stride_0_0 = b_in4->size[0];
  b_in4->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in4, stride_0_0);
  in4_data = b_in4->data;
  if (i) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in4_data[i1] = b_in3_data[i1];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    binary_expand_op_1_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_1_numThreads)

    for (i1 = 0; i1 < loop_ub; i1++) {
      in4_data[i1] = b_in3_data[i1];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  emxFree_real_T(&b_in3);
  c_in4 = *b_in4;
  b_in6[0] = (int32_T)in6[0];
  b_in6[1] = (int32_T)in6[1];
  c_in4.size = &b_in6[0];
  c_in4.numDimensions = 2;
  b_mtimes(in2, &c_in4, in1);
  emxFree_real_T(&b_in4);
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

void binary_expand_op_3(emxArray_real_T *in1, const real_T in2[6],
                        const real_T in3[60], const emxArray_real_T *in4,
                        const real_T in5[2])
{
  emxArray_real_T c_in3;
  real_T b_in3[60];
  const real_T *in4_data;
  int32_T b_in5[2];
  int32_T i;
  int32_T stride_0_0;
  in4_data = in4->data;
  stride_0_0 = (in4->size[0] != 1);
  for (i = 0; i < 60; i++) {
    b_in3[i] = in3[i] - in4_data[i * stride_0_0];
  }
  c_in3.data = &b_in3[0];
  b_in5[0] = (int32_T)in5[0];
  b_in5[1] = (int32_T)in5[1];
  c_in3.size = &b_in5[0];
  c_in3.allocatedSize = 60;
  c_in3.numDimensions = 2;
  c_in3.canFreeData = false;
  b_mtimes(in2, &c_in3, in1);
}

/* End of code generation (eml_mtimes_helper.c) */
