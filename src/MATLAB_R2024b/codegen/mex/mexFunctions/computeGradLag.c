/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGradLag.c
 *
 * Code generation for function 'computeGradLag'
 *
 */

/* Include files */
#include "computeGradLag.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_computeGradLag(emlrtCTX aTLS, emxArray_real_T *workspace, int32_T ldA,
                      int32_T nVar, const real_T grad_data[], int32_T mIneq,
                      const emxArray_real_T *AineqTrans,
                      const int32_T finiteFixed_data[], int32_T mFixed,
                      const int32_T finiteLB_data[], int32_T mLB,
                      const int32_T finiteUB_data[], int32_T mUB,
                      const emxArray_real_T *lambda)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  const real_T *AineqTrans_data;
  const real_T *lambda_data;
  real_T alpha1;
  real_T beta1;
  real_T *workspace_data;
  int32_T b_computeGradLag_numThreads;
  int32_T b_i;
  int32_T i;
  int32_T iL0;
  int32_T idx;
  char_T TRANSA;
  lambda_data = lambda->data;
  AineqTrans_data = AineqTrans->data;
  workspace_data = workspace->data;
  i = (uint16_T)nVar;
  if ((uint16_T)nVar < 1200) {
    for (b_i = 0; b_i < i; b_i++) {
      workspace_data[b_i] = grad_data[b_i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    b_computeGradLag_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_computeGradLag_numThreads)

    for (b_i = 0; b_i < i; b_i++) {
      workspace_data[b_i] = grad_data[b_i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  i = (uint16_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    workspace_data[finiteFixed_data[idx] - 1] += lambda_data[idx];
  }
  if (mIneq >= 1) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mIneq;
    lda_t = (ptrdiff_t)ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&AineqTrans_data[0], &lda_t,
          (real_T *)&lambda_data[mFixed], &incx_t, &beta1, &workspace_data[0],
          &incy_t);
  }
  iL0 = mFixed + mIneq;
  i = (uint16_T)mLB;
  for (idx = 0; idx < i; idx++) {
    workspace_data[finiteLB_data[idx] - 1] -= lambda_data[iL0 + idx];
  }
  if ((uint16_T)mLB - 1 >= 0) {
    iL0 += (uint16_T)mLB;
  }
  i = (uint16_T)mUB;
  for (idx = 0; idx < i; idx++) {
    workspace_data[finiteUB_data[idx] - 1] += lambda_data[iL0 + idx];
  }
}

void computeGradLag(emlrtCTX aTLS, real_T workspace_data[], int32_T ldA,
                    int32_T nVar, const real_T grad_data[], int32_T mIneq,
                    const emxArray_real_T *AineqTrans,
                    const int32_T finiteFixed_data[], int32_T mFixed,
                    const int32_T finiteLB_data[], int32_T mLB,
                    const int32_T finiteUB_data[], int32_T mUB,
                    const emxArray_real_T *lambda)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  const real_T *AineqTrans_data;
  const real_T *lambda_data;
  real_T alpha1;
  real_T beta1;
  int32_T b_i;
  int32_T computeGradLag_numThreads;
  int32_T i;
  int32_T iL0;
  int32_T idx;
  char_T TRANSA;
  lambda_data = lambda->data;
  AineqTrans_data = AineqTrans->data;
  i = (uint16_T)nVar;
  if ((uint16_T)nVar < 1200) {
    if (i - 1 >= 0) {
      memcpy(&workspace_data[0], &grad_data[0], (uint32_T)i * sizeof(real_T));
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    computeGradLag_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(computeGradLag_numThreads)

    for (b_i = 0; b_i < i; b_i++) {
      workspace_data[b_i] = grad_data[b_i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  i = (uint16_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    workspace_data[finiteFixed_data[idx] - 1] += lambda_data[idx];
  }
  if (mIneq >= 1) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mIneq;
    lda_t = (ptrdiff_t)ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&AineqTrans_data[0], &lda_t,
          (real_T *)&lambda_data[mFixed], &incx_t, &beta1, &workspace_data[0],
          &incy_t);
  }
  iL0 = mFixed + mIneq;
  i = (uint16_T)mLB;
  for (idx = 0; idx < i; idx++) {
    workspace_data[finiteLB_data[idx] - 1] -= lambda_data[iL0 + idx];
  }
  if ((uint16_T)mLB - 1 >= 0) {
    iL0 += (uint16_T)mLB;
  }
  i = (uint16_T)mUB;
  for (idx = 0; idx < i; idx++) {
    workspace_data[finiteUB_data[idx] - 1] += lambda_data[iL0 + idx];
  }
}

/* End of code generation (computeGradLag.c) */
