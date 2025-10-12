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
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_updateWorkingSetForNewQP(const real_T xk[40], k_struct_T *WorkingSet,
                                int32_T mIneq, int32_T mNonlinIneq,
                                const real_T cIneq_data[], int32_T mLB,
                                const real_T lb_data[],
                                const int32_T lb_size[2], int32_T mUB,
                                const real_T ub_data[],
                                const int32_T ub_size[2], int32_T mFixed)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T i;
  int32_T idx;
  int32_T ineqStart;
  int32_T vectorUB;
  boolean_T hasLB;
  boolean_T hasUB;
  i = (uint16_T)mIneq;
  ineqStart = ((uint16_T)mIneq >> 2) << 2;
  vectorUB = ineqStart - 4;
  for (idx = 0; idx <= vectorUB; idx += 4) {
    _mm256_storeu_pd(
        &WorkingSet->bineq.data[idx],
        _mm256_mul_pd(_mm256_loadu_pd(&cIneq_data[idx]), _mm256_set1_pd(-1.0)));
  }
  for (idx = ineqStart; idx < i; idx++) {
    WorkingSet->bineq.data[idx] = -cIneq_data[idx];
  }
  hasLB = ((lb_size[0] != 0) && (lb_size[1] != 0));
  hasUB = ((ub_size[0] != 0) && (ub_size[1] != 0));
  if (hasLB) {
    i = (uint16_T)mLB;
    for (idx = 0; idx < i; idx++) {
      WorkingSet->lb.data[WorkingSet->indexLB.data[idx] - 1] =
          -lb_data[WorkingSet->indexLB.data[idx] - 1] +
          xk[WorkingSet->indexLB.data[idx] - 1];
    }
  }
  if (hasUB) {
    i = (uint16_T)mUB;
    for (idx = 0; idx < i; idx++) {
      WorkingSet->ub.data[WorkingSet->indexUB.data[idx] - 1] =
          ub_data[WorkingSet->indexUB.data[idx] - 1] -
          xk[WorkingSet->indexUB.data[idx] - 1];
    }
  }
  if (hasLB && hasUB) {
    i = (uint16_T)mFixed;
    for (idx = 0; idx < i; idx++) {
      real_T d;
      d = ub_data[WorkingSet->indexFixed.data[idx] - 1] -
          xk[WorkingSet->indexFixed.data[idx] - 1];
      WorkingSet->ub.data[WorkingSet->indexFixed.data[idx] - 1] = d;
      WorkingSet->bwset->data[idx] = d;
    }
  }
  if (WorkingSet->nActiveConstr > mFixed) {
    i = mFixed + 1;
    ineqStart = muIntScalarMax_sint32(i, 1);
    i = WorkingSet->nActiveConstr;
    for (idx = ineqStart; idx <= i; idx++) {
      switch (WorkingSet->Wid.data[idx - 1]) {
      case 4:
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->lb
                .data[WorkingSet->indexLB
                          .data[WorkingSet->Wlocalidx.data[idx - 1] - 1] -
                      1];
        break;
      case 5:
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->ub
                .data[WorkingSet->indexUB
                          .data[WorkingSet->Wlocalidx.data[idx - 1] - 1] -
                      1];
        break;
      default:
        WorkingSet->bwset->data[idx - 1] =
            WorkingSet->bineq.data[WorkingSet->Wlocalidx.data[idx - 1] - 1];
        if ((mNonlinIneq > 0) &&
            (WorkingSet->Wlocalidx.data[idx - 1] > mIneq - mNonlinIneq)) {
          n_t = (ptrdiff_t)WorkingSet->nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t,
                &WorkingSet->Aineq
                     ->data[WorkingSet->ldA *
                            (WorkingSet->Wlocalidx.data[idx - 1] - 1)],
                &incx_t, &WorkingSet->ATwset->data[WorkingSet->ldA * (idx - 1)],
                &incy_t);
        }
        break;
      }
    }
  }
}

void updateWorkingSetForNewQP(const real_T xk[40], k_struct_T *WorkingSet,
                              int32_T mIneq, const real_T cIneq_data[],
                              int32_T mLB, const real_T lb_data[],
                              const int32_T lb_size[2], int32_T mUB,
                              const real_T ub_data[], const int32_T ub_size[2],
                              int32_T mFixed)
{
  int32_T i;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T hasLB;
  boolean_T hasUB;
  i = (uint16_T)mIneq;
  scalarLB = ((uint16_T)mIneq >> 2) << 2;
  vectorUB = scalarLB - 4;
  for (idx = 0; idx <= vectorUB; idx += 4) {
    _mm256_storeu_pd(
        &WorkingSet->bineq.data[idx],
        _mm256_mul_pd(_mm256_loadu_pd(&cIneq_data[idx]), _mm256_set1_pd(-1.0)));
  }
  for (idx = scalarLB; idx < i; idx++) {
    WorkingSet->bineq.data[idx] = -cIneq_data[idx];
  }
  hasLB = ((lb_size[0] != 0) && (lb_size[1] != 0));
  hasUB = ((ub_size[0] != 0) && (ub_size[1] != 0));
  if (hasLB) {
    i = (uint16_T)mLB;
    for (idx = 0; idx < i; idx++) {
      WorkingSet->lb.data[WorkingSet->indexLB.data[idx] - 1] =
          -lb_data[WorkingSet->indexLB.data[idx] - 1] +
          xk[WorkingSet->indexLB.data[idx] - 1];
    }
  }
  if (hasUB) {
    i = (uint16_T)mUB;
    for (idx = 0; idx < i; idx++) {
      WorkingSet->ub.data[WorkingSet->indexUB.data[idx] - 1] =
          ub_data[WorkingSet->indexUB.data[idx] - 1] -
          xk[WorkingSet->indexUB.data[idx] - 1];
    }
  }
  if (hasLB && hasUB) {
    i = (uint16_T)mFixed;
    for (idx = 0; idx < i; idx++) {
      real_T d;
      d = ub_data[WorkingSet->indexFixed.data[idx] - 1] -
          xk[WorkingSet->indexFixed.data[idx] - 1];
      WorkingSet->ub.data[WorkingSet->indexFixed.data[idx] - 1] = d;
      WorkingSet->bwset->data[idx] = d;
    }
  }
}

/* End of code generation (updateWorkingSetForNewQP.c) */
