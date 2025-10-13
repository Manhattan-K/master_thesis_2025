/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "xgeqp3.h"
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void xgeqp3(emlrtCTX aTLS, emxArray_real_T *A, int32_T m, int32_T n,
            int32_T jpvt_data[], const int32_T *jpvt_size, emxArray_real_T *tau)
{
  ptrdiff_t *jpvt_t_data;
  jmp_buf *volatile emlrtJBStack;
  emxArray_ptrdiff_t *jpvt_t;
  real_T *A_data;
  real_T *tau_data;
  int32_T i;
  int32_T k;
  int32_T ma;
  int32_T minmana;
  int32_T na;
  int32_T xgeqp3_numThreads;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  ma = A->size[0];
  na = A->size[1];
  minmana = muIntScalarMin_sint32(ma, na);
  i = tau->size[0];
  tau->size[0] = minmana;
  emxEnsureCapacity_real_T(tau, i);
  tau_data = tau->data;
  if (n < 1) {
    i = tau->size[0];
    tau->size[0] = minmana;
    emxEnsureCapacity_real_T(tau, i);
    tau_data = tau->data;
    for (i = 0; i < minmana; i++) {
      tau_data[i] = 0.0;
    }
    na = (n / 8) << 3;
    ma = na - 8;
    for (k = 0; k <= ma; k += 8) {
      _mm256_storeu_si256(
          (__m256i *)&jpvt_data[k],
          _mm256_add_epi32(
              _mm256_add_epi32(_mm256_set1_epi32(k),
                               _mm256_loadu_si256((const __m256i *)&iv1[0])),
              _mm256_set1_epi32(1)));
    }
    if (n - na < 1200) {
      for (k = na; k < n; k++) {
        jpvt_data[k] = k + 1;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      xgeqp3_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(xgeqp3_numThreads)

      for (k = na; k < n; k++) {
        jpvt_data[k] = k + 1;
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  } else {
    ptrdiff_t info_t;
    emxInit_ptrdiff_t(&jpvt_t);
    na = *jpvt_size;
    i = jpvt_t->size[0];
    jpvt_t->size[0] = na;
    emxEnsureCapacity_ptrdiff_t(jpvt_t, i);
    jpvt_t_data = jpvt_t->data;
    if (na < 1200) {
      for (k = 0; k < na; k++) {
        jpvt_t_data[k] = (ptrdiff_t)jpvt_data[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      xgeqp3_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(xgeqp3_numThreads)

      for (k = 0; k < na; k++) {
        jpvt_t_data[k] = (ptrdiff_t)jpvt_data[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    info_t =
        LAPACKE_dgeqp3(102, (ptrdiff_t)m, (ptrdiff_t)n, &A_data[0],
                       (ptrdiff_t)A->size[0], &jpvt_t_data[0], &tau_data[0]);
    if ((int32_T)info_t != 0) {
      for (na = 0; na < n; na++) {
        for (i = 0; i < m; i++) {
          A_data[na * ma + i] = rtNaN;
        }
      }
      na = muIntScalarMin_sint32(m, n) - 1;
      if (na + 1 < 1200) {
        for (k = 0; k <= na; k++) {
          tau_data[k] = rtNaN;
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        xgeqp3_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(xgeqp3_numThreads)

        for (k = 0; k <= na; k++) {
          tau_data[k] = rtNaN;
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
      i = na + 2;
      for (na = i; na <= minmana; na++) {
        tau_data[na - 1] = 0.0;
      }
      na = (n / 8) << 3;
      ma = na - 8;
      for (k = 0; k <= ma; k += 8) {
        _mm256_storeu_si256(
            (__m256i *)&jpvt_data[k],
            _mm256_add_epi32(
                _mm256_add_epi32(_mm256_set1_epi32(k),
                                 _mm256_loadu_si256((const __m256i *)&iv1[0])),
                _mm256_set1_epi32(1)));
      }
      if (n - na < 1200) {
        for (k = na; k < n; k++) {
          jpvt_data[k] = k + 1;
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        xgeqp3_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(xgeqp3_numThreads)

        for (k = na; k < n; k++) {
          jpvt_data[k] = k + 1;
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    } else if (n < 1200) {
      for (k = 0; k < n; k++) {
        jpvt_data[k] = (int32_T)jpvt_t_data[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      xgeqp3_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(xgeqp3_numThreads)

      for (k = 0; k < n; k++) {
        jpvt_data[k] = (int32_T)jpvt_t_data[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    emxFree_ptrdiff_t(&jpvt_t);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (xgeqp3.c) */
