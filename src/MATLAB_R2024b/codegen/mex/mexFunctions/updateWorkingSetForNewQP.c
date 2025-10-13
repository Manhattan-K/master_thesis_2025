/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateWorkingSetForNewQP.c
 *
 * Code generation for function 'updateWorkingSetForNewQP'
 *
 */

/* Include files */
#include "updateWorkingSetForNewQP.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_updateWorkingSetForNewQP(emlrtCTX aTLS, const real_T xk[40],
                                i_struct_T *WorkingSet, int32_T mIneq,
                                int32_T mNonlinIneq, const real_T cIneq_data[],
                                int32_T mLB, const real_T lb[40], int32_T mUB,
                                const real_T ub[40], int32_T mFixed)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  int32_T b_updateWorkingSetForNewQP_numThreads;
  int32_T i;
  int32_T idx;
  int32_T ineqStart;
  int32_T vectorUB;
  i = (uint16_T)mIneq;
  ineqStart = ((uint16_T)mIneq >> 2) << 2;
  vectorUB = ineqStart - 4;
  for (idx = 0; idx <= vectorUB; idx += 4) {
    _mm256_storeu_pd(
        &WorkingSet->bineq.data[idx],
        _mm256_mul_pd(_mm256_loadu_pd(&cIneq_data[idx]), _mm256_set1_pd(-1.0)));
  }
  if ((uint16_T)mIneq - ineqStart < 1200) {
    for (idx = ineqStart; idx < i; idx++) {
      WorkingSet->bineq.data[idx] = -cIneq_data[idx];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    b_updateWorkingSetForNewQP_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_updateWorkingSetForNewQP_numThreads)

    for (idx = ineqStart; idx < i; idx++) {
      WorkingSet->bineq.data[idx] = -cIneq_data[idx];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  i = (uint16_T)mLB;
  for (vectorUB = 0; vectorUB < i; vectorUB++) {
    WorkingSet->lb.data[WorkingSet->indexLB.data[vectorUB] - 1] =
        -lb[WorkingSet->indexLB.data[vectorUB] - 1] +
        xk[WorkingSet->indexLB.data[vectorUB] - 1];
  }
  i = (uint16_T)mUB;
  for (vectorUB = 0; vectorUB < i; vectorUB++) {
    WorkingSet->ub.data[WorkingSet->indexUB.data[vectorUB] - 1] =
        ub[WorkingSet->indexUB.data[vectorUB] - 1] -
        xk[WorkingSet->indexUB.data[vectorUB] - 1];
  }
  i = (uint16_T)mFixed;
  for (vectorUB = 0; vectorUB < i; vectorUB++) {
    real_T d;
    d = ub[WorkingSet->indexFixed.data[vectorUB] - 1] -
        xk[WorkingSet->indexFixed.data[vectorUB] - 1];
    WorkingSet->ub.data[WorkingSet->indexFixed.data[vectorUB] - 1] = d;
    WorkingSet->bwset->data[vectorUB] = d;
  }
  if (WorkingSet->nActiveConstr > mFixed) {
    i = mFixed + 1;
    ineqStart = muIntScalarMax_sint32(i, 1);
    i = WorkingSet->nActiveConstr;
    for (vectorUB = ineqStart; vectorUB <= i; vectorUB++) {
      switch (WorkingSet->Wid.data[vectorUB - 1]) {
      case 4:
        WorkingSet->bwset->data[vectorUB - 1] =
            WorkingSet->lb
                .data[WorkingSet->indexLB
                          .data[WorkingSet->Wlocalidx.data[vectorUB - 1] - 1] -
                      1];
        break;
      case 5:
        WorkingSet->bwset->data[vectorUB - 1] =
            WorkingSet->ub
                .data[WorkingSet->indexUB
                          .data[WorkingSet->Wlocalidx.data[vectorUB - 1] - 1] -
                      1];
        break;
      default:
        WorkingSet->bwset->data[vectorUB - 1] =
            WorkingSet->bineq
                .data[WorkingSet->Wlocalidx.data[vectorUB - 1] - 1];
        if ((mNonlinIneq > 0) &&
            (WorkingSet->Wlocalidx.data[vectorUB - 1] > mIneq - mNonlinIneq)) {
          n_t = (ptrdiff_t)WorkingSet->nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t,
                &WorkingSet->Aineq
                     ->data[WorkingSet->ldA *
                            (WorkingSet->Wlocalidx.data[vectorUB - 1] - 1)],
                &incx_t,
                &WorkingSet->ATwset->data[WorkingSet->ldA * (vectorUB - 1)],
                &incy_t);
        }
        break;
      }
    }
  }
}

void updateWorkingSetForNewQP(emlrtCTX aTLS, const real_T xk[40],
                              i_struct_T *WorkingSet, int32_T mIneq,
                              const real_T cIneq_data[], int32_T mLB,
                              const real_T lb[40], int32_T mUB,
                              const real_T ub[40], int32_T mFixed)
{
  jmp_buf *volatile emlrtJBStack;
  int32_T i;
  int32_T idx;
  int32_T scalarLB;
  int32_T updateWorkingSetForNewQP_numThreads;
  int32_T vectorUB;
  i = (uint16_T)mIneq;
  scalarLB = ((uint16_T)mIneq >> 2) << 2;
  vectorUB = scalarLB - 4;
  for (idx = 0; idx <= vectorUB; idx += 4) {
    _mm256_storeu_pd(
        &WorkingSet->bineq.data[idx],
        _mm256_mul_pd(_mm256_loadu_pd(&cIneq_data[idx]), _mm256_set1_pd(-1.0)));
  }
  if ((uint16_T)mIneq - scalarLB < 1200) {
    for (idx = scalarLB; idx < i; idx++) {
      WorkingSet->bineq.data[idx] = -cIneq_data[idx];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    updateWorkingSetForNewQP_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(updateWorkingSetForNewQP_numThreads)

    for (idx = scalarLB; idx < i; idx++) {
      WorkingSet->bineq.data[idx] = -cIneq_data[idx];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  i = (uint16_T)mLB;
  for (scalarLB = 0; scalarLB < i; scalarLB++) {
    WorkingSet->lb.data[WorkingSet->indexLB.data[scalarLB] - 1] =
        -lb[WorkingSet->indexLB.data[scalarLB] - 1] +
        xk[WorkingSet->indexLB.data[scalarLB] - 1];
  }
  i = (uint16_T)mUB;
  for (scalarLB = 0; scalarLB < i; scalarLB++) {
    WorkingSet->ub.data[WorkingSet->indexUB.data[scalarLB] - 1] =
        ub[WorkingSet->indexUB.data[scalarLB] - 1] -
        xk[WorkingSet->indexUB.data[scalarLB] - 1];
  }
  i = (uint16_T)mFixed;
  for (scalarLB = 0; scalarLB < i; scalarLB++) {
    real_T d;
    d = ub[WorkingSet->indexFixed.data[scalarLB] - 1] -
        xk[WorkingSet->indexFixed.data[scalarLB] - 1];
    WorkingSet->ub.data[WorkingSet->indexFixed.data[scalarLB] - 1] = d;
    WorkingSet->bwset->data[scalarLB] = d;
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
