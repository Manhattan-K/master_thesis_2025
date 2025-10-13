/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
real_T b_sumColumnB(emlrtCTX aTLS, const emxArray_real_T *x, int32_T vlen)
{
  jmp_buf *volatile emlrtJBStack;
  const real_T *x_data;
  real_T b_y;
  real_T b_yPrime;
  real_T c_y;
  real_T y;
  real_T yPrime;
  int32_T b_k;
  int32_T b_sumColumnB_numThreads;
  int32_T c_k;
  int32_T inb;
  int32_T k;
  int32_T nfb;
  int32_T vstart;
  x_data = x->data;
  if (vlen <= 1024) {
    y = x_data[0];
    if (vlen - 1 < 1200) {
      for (k = 0; k <= vlen - 2; k++) {
        y += x_data[k + 1];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_sumColumnB_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_sumColumnB_numThreads) private(yPrime)
      {
        yPrime = 0.0;
#pragma omp for nowait
        for (k = 0; k <= vlen - 2; k++) {
          yPrime += x_data[k + 1];
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          y += yPrime;
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  } else {
    nfb = vlen / 1024;
    inb = nfb << 10;
    y = x_data[0];
    for (b_k = 0; b_k < 1023; b_k++) {
      y += x_data[b_k + 1];
    }
    if ((nfb - 1) * 1023 < 1200) {
      for (k = 2; k <= nfb; k++) {
        vstart = (k - 1) << 10;
        b_y = x_data[vstart];
        for (c_k = 0; c_k < 1023; c_k++) {
          b_y += x_data[(vstart + c_k) + 1];
        }
        y += b_y;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_sumColumnB_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_sumColumnB_numThreads) private(             \
        yPrime, vstart, b_y, c_k)
      {
        yPrime = 0.0;
#pragma omp for nowait
        for (k = 2; k <= nfb; k++) {
          vstart = (k - 1) << 10;
          b_y = x_data[vstart];
          for (c_k = 0; c_k < 1023; c_k++) {
            b_y += x_data[(vstart + c_k) + 1];
          }
          yPrime += b_y;
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          y += yPrime;
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    if (vlen > inb) {
      c_y = x_data[inb];
      b_k = vlen - inb;
      if (b_k - 1 < 1200) {
        for (k = 0; k <= b_k - 2; k++) {
          c_y += x_data[(inb + k) + 1];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        b_sumColumnB_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel num_threads(b_sumColumnB_numThreads) private(b_yPrime)
        {
          b_yPrime = 0.0;
#pragma omp for nowait
          for (k = 0; k <= b_k - 2; k++) {
            b_yPrime += x_data[(inb + k) + 1];
          }
          omp_set_nest_lock(&mexFunctions_nestLockGlobal);
          {

            c_y += b_yPrime;
          }
          omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
      y += c_y;
    }
  }
  return y;
}

real_T c_sumColumnB(emlrtCTX aTLS, const emxArray_real_T *x, int32_T vlen,
                    int32_T vstart)
{
  jmp_buf *volatile emlrtJBStack;
  const real_T *x_data;
  real_T b_y;
  real_T b_yPrime;
  real_T c_y;
  real_T y;
  real_T yPrime;
  int32_T b_k;
  int32_T b_vstart;
  int32_T c_k;
  int32_T c_sumColumnB_numThreads;
  int32_T inb;
  int32_T k;
  int32_T nfb;
  x_data = x->data;
  if (vlen <= 1024) {
    y = x_data[vstart - 1];
    if (vlen - 1 < 1200) {
      for (k = 0; k <= vlen - 2; k++) {
        y += x_data[vstart + k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      c_sumColumnB_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(c_sumColumnB_numThreads) private(yPrime)
      {
        yPrime = 0.0;
#pragma omp for nowait
        for (k = 0; k <= vlen - 2; k++) {
          yPrime += x_data[vstart + k];
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          y += yPrime;
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  } else {
    nfb = vlen / 1024;
    inb = nfb << 10;
    y = x_data[vstart - 1];
    for (b_k = 0; b_k < 1023; b_k++) {
      y += x_data[vstart + b_k];
    }
    if ((nfb - 1) * 1023 < 1200) {
      for (k = 2; k <= nfb; k++) {
        b_vstart = vstart + ((k - 1) << 10);
        b_y = x_data[b_vstart - 1];
        for (c_k = 0; c_k < 1023; c_k++) {
          b_y += x_data[b_vstart + c_k];
        }
        y += b_y;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      c_sumColumnB_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(c_sumColumnB_numThreads) private(             \
        yPrime, b_vstart, b_y, c_k)
      {
        yPrime = 0.0;
#pragma omp for nowait
        for (k = 2; k <= nfb; k++) {
          b_vstart = vstart + ((k - 1) << 10);
          b_y = x_data[b_vstart - 1];
          for (c_k = 0; c_k < 1023; c_k++) {
            b_y += x_data[b_vstart + c_k];
          }
          yPrime += b_y;
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          y += yPrime;
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    if (vlen > inb) {
      nfb = vstart + inb;
      c_y = x_data[nfb - 1];
      b_k = vlen - inb;
      if (b_k - 1 < 1200) {
        for (k = 0; k <= b_k - 2; k++) {
          c_y += x_data[nfb + k];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        c_sumColumnB_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel num_threads(c_sumColumnB_numThreads) private(b_yPrime)
        {
          b_yPrime = 0.0;
#pragma omp for nowait
          for (k = 0; k <= b_k - 2; k++) {
            b_yPrime += x_data[nfb + k];
          }
          omp_set_nest_lock(&mexFunctions_nestLockGlobal);
          {

            c_y += b_yPrime;
          }
          omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
      y += c_y;
    }
  }
  return y;
}

real_T sumColumnB(const emxArray_real_T *x, int32_T col)
{
  const real_T *x_data;
  int32_T i0;
  x_data = x->data;
  i0 = (col - 1) << 1;
  return x_data[i0] + x_data[i0 + 1];
}

real_T sumColumnB4(const emxArray_real_T *x, int32_T vstart)
{
  const real_T *x_data;
  real_T psum2;
  real_T psum3;
  real_T psum4;
  real_T y;
  int32_T k;
  x_data = x->data;
  y = x_data[vstart - 1];
  psum2 = x_data[vstart + 1023];
  psum3 = x_data[vstart + 2047];
  psum4 = x_data[vstart + 3071];
  for (k = 0; k < 1023; k++) {
    int32_T psum1_tmp;
    psum1_tmp = vstart + k;
    y += x_data[psum1_tmp];
    psum2 += x_data[psum1_tmp + 1024];
    psum3 += x_data[psum1_tmp + 2048];
    psum4 += x_data[psum1_tmp + 3072];
  }
  return (y + psum2) + (psum3 + psum4);
}

/* End of code generation (sumMatrixIncludeNaN.c) */
