/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorQR.c
 *
 * Code generation for function 'factorQR'
 *
 */

/* Include files */
#include "factorQR.h"
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void factorQR(emlrtCTX aTLS, g_struct_T *obj, const emxArray_real_T *A,
              int32_T mrows, int32_T ncols, int32_T ldA)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T *tau;
  const real_T *A_data;
  real_T *tau_data;
  int32_T b_i;
  int32_T b_idx;
  int32_T factorQR_numThreads;
  int32_T i;
  int32_T idx;
  int32_T minmn;
  boolean_T guard1;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  i = mrows * ncols;
  emxInit_real_T(&tau, 1);
  guard1 = false;
  if (i > 0) {
    for (idx = 0; idx < ncols; idx++) {
      n_t = (ptrdiff_t)mrows;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&A_data[ldA * idx], &incx_t,
            &obj->QR->data[obj->ldq * idx], &incy_t);
    }
    guard1 = true;
  } else if (i == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    int32_T minmana;
    int16_T y_size_idx_0;
    int16_T y_size_idx_1;
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    minmn = (ncols / 8) << 3;
    idx = minmn - 8;
    for (b_idx = 0; b_idx <= idx; b_idx += 8) {
      _mm256_storeu_si256(
          (__m256i *)&obj->jpvt.data[b_idx],
          _mm256_add_epi32(
              _mm256_add_epi32(_mm256_set1_epi32(b_idx),
                               _mm256_loadu_si256((const __m256i *)&iv1[0])),
              _mm256_set1_epi32(1)));
    }
    if (ncols - minmn < 1200) {
      for (b_idx = minmn; b_idx < ncols; b_idx++) {
        obj->jpvt.data[b_idx] = b_idx + 1;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      factorQR_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(factorQR_numThreads)

      for (b_idx = minmn; b_idx < ncols; b_idx++) {
        obj->jpvt.data[b_idx] = b_idx + 1;
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    i = muIntScalarMin_sint32(mrows, ncols);
    obj->minRowCol = i;
    y_size_idx_0 = (int16_T)obj->QR->size[0];
    y_size_idx_1 = (int16_T)obj->QR->size[1];
    minmana = muIntScalarMin_sint32(y_size_idx_0, y_size_idx_1);
    idx = tau->size[0];
    tau->size[0] = minmana;
    emxEnsureCapacity_real_T(tau, idx);
    tau_data = tau->data;
    if (ncols == 0) {
      i = tau->size[0];
      tau->size[0] = minmana;
      emxEnsureCapacity_real_T(tau, i);
      tau_data = tau->data;
      for (i = 0; i < minmana; i++) {
        tau_data[i] = 0.0;
      }
    } else {
      n_t = LAPACKE_dgeqrf(102, (ptrdiff_t)mrows, (ptrdiff_t)ncols,
                           &obj->QR->data[0], (ptrdiff_t)y_size_idx_0,
                           &tau_data[0]);
      if ((int32_T)n_t != 0) {
        for (minmn = 0; minmn < ncols; minmn++) {
          idx = (uint16_T)mrows;
          for (b_i = 0; b_i < idx; b_i++) {
            obj->QR->data[minmn * y_size_idx_0 + b_i] = rtNaN;
          }
        }
        minmn = i - 1;
        if (i < 1200) {
          for (b_idx = 0; b_idx <= minmn; b_idx++) {
            tau_data[b_idx] = rtNaN;
          }
        } else {
          emlrtEnterParallelRegion(aTLS, omp_in_parallel());
          emlrtPushJmpBuf(aTLS, &emlrtJBStack);
          factorQR_numThreads =
              emlrtAllocRegionTLSs(aTLS, omp_in_parallel(),
                                   omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(factorQR_numThreads)

          for (b_idx = 0; b_idx <= minmn; b_idx++) {
            tau_data[b_idx] = rtNaN;
          }
          emlrtPopJmpBuf(aTLS, &emlrtJBStack);
          emlrtExitParallelRegion(aTLS, omp_in_parallel());
        }
        i = minmn + 2;
        for (b_i = i; b_i <= minmana; b_i++) {
          tau_data[b_i - 1] = 0.0;
        }
      }
    }
    idx = tau->size[0];
    i = obj->tau->size[0];
    obj->tau->size[0] = tau->size[0];
    emxEnsureCapacity_real_T(obj->tau, i);
    minmn = tau->size[0];
    if (tau->size[0] < 1200) {
      for (b_idx = 0; b_idx < idx; b_idx++) {
        obj->tau->data[b_idx] = tau_data[b_idx];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      factorQR_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(factorQR_numThreads)

      for (b_idx = 0; b_idx < minmn; b_idx++) {
        obj->tau->data[b_idx] = tau_data[b_idx];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  emxFree_real_T(&tau);
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (factorQR.c) */
