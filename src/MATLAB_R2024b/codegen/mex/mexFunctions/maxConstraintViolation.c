/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation.c
 *
 * Code generation for function 'maxConstraintViolation'
 *
 */

/* Include files */
#include "maxConstraintViolation.h"
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "maxConstraintViolation_AMats_regularized_.h"
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T b_maxConstraintViolation(emlrtCTX aTLS, i_struct_T *obj,
                                const emxArray_real_T *x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  const real_T *x_data;
  real_T alpha1;
  real_T b_vPrime;
  real_T beta1;
  real_T c_vPrime;
  real_T d;
  real_T d_vPrime;
  real_T v;
  real_T vPrime;
  int32_T b_maxConstraintViolation_numThreads;
  int32_T i;
  int32_T idx;
  int32_T idxLB;
  char_T TRANSA;
  x_data = x->data;
  if (obj->probType == 2) {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      if (obj->sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj->sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj->bineq.data[0], &incx_t,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      if (obj->sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)40;
        n_t = (ptrdiff_t)obj->sizes[2];
        lda_t = (ptrdiff_t)obj->ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &obj->Aineq->data[0], &lda_t,
              (real_T *)&x_data[0], &incx_t, &beta1,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      i = (uint16_T)obj->sizes[2];
      if (i < 1200) {
        for (idx = 0; idx < i; idx++) {
          d = obj->maxConstrWorkspace->data[idx] - x_data[idx + 40];
          obj->maxConstrWorkspace->data[idx] = d;
          v = muDoubleScalarMax(v, d);
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        b_maxConstraintViolation_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel num_threads(b_maxConstraintViolation_numThreads) private( \
        b_vPrime, d)
        {
          b_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx < i; idx++) {
            d = obj->maxConstrWorkspace->data[idx] - x_data[idx + 40];
            obj->maxConstrWorkspace->data[idx] = d;
            b_vPrime = muDoubleScalarMax(b_vPrime, d);
          }
          omp_set_nest_lock(&mexFunctions_nestLockGlobal);
          {

            v = muDoubleScalarMax(v, b_vPrime);
          }
          omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    }
  } else {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      if (obj->sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj->sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj->bineq.data[0], &incx_t,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      if (obj->sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)obj->nVar;
        n_t = (ptrdiff_t)obj->sizes[2];
        lda_t = (ptrdiff_t)obj->ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &obj->Aineq->data[0], &lda_t,
              (real_T *)&x_data[0], &incx_t, &beta1,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      i = (uint16_T)obj->sizes[2];
      if (i < 1200) {
        for (idx = 0; idx < i; idx++) {
          v = muDoubleScalarMax(v, obj->maxConstrWorkspace->data[idx]);
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        b_maxConstraintViolation_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel num_threads(b_maxConstraintViolation_numThreads) private( \
        b_vPrime)
        {
          b_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx < i; idx++) {
            b_vPrime =
                muDoubleScalarMax(b_vPrime, obj->maxConstrWorkspace->data[idx]);
          }
          omp_set_nest_lock(&mexFunctions_nestLockGlobal);
          {

            v = muDoubleScalarMax(v, b_vPrime);
          }
          omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    }
  }
  if (obj->sizes[3] > 0) {
    i = (uint16_T)obj->sizes[3];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        idxLB = obj->indexLB.data[idx] - 1;
        v = muDoubleScalarMax(v, -x_data[idxLB] - obj->lb.data[idxLB]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_maxConstraintViolation_numThreads) private( \
        vPrime, idxLB)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          idxLB = obj->indexLB.data[idx] - 1;
          vPrime =
              muDoubleScalarMax(vPrime, -x_data[idxLB] - obj->lb.data[idxLB]);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (obj->sizes[4] > 0) {
    i = (uint16_T)obj->sizes[4];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        idxLB = obj->indexUB.data[idx] - 1;
        v = muDoubleScalarMax(v, x_data[idxLB] - obj->ub.data[idxLB]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_maxConstraintViolation_numThreads) private( \
        c_vPrime, idxLB)
      {
        c_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          idxLB = obj->indexUB.data[idx] - 1;
          c_vPrime =
              muDoubleScalarMax(c_vPrime, x_data[idxLB] - obj->ub.data[idxLB]);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, c_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (obj->sizes[0] > 0) {
    i = (uint16_T)obj->sizes[0];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(
            v, muDoubleScalarAbs(x_data[obj->indexFixed.data[idx] - 1] -
                                 obj->ub.data[obj->indexFixed.data[idx] - 1]));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_maxConstraintViolation_numThreads) private( \
        d_vPrime)
      {
        d_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          d_vPrime = muDoubleScalarMax(
              d_vPrime,
              muDoubleScalarAbs(x_data[obj->indexFixed.data[idx] - 1] -
                                obj->ub.data[obj->indexFixed.data[idx] - 1]));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, d_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  return v;
}

real_T c_maxConstraintViolation(emlrtCTX aTLS, i_struct_T *obj,
                                const emxArray_real_T *x, int32_T ix0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  const real_T *x_data;
  real_T alpha1;
  real_T b_vPrime;
  real_T beta1;
  real_T c_vPrime;
  real_T d_vPrime;
  real_T v;
  real_T vPrime;
  real_T y;
  int32_T c_maxConstraintViolation_numThreads;
  int32_T i;
  int32_T idx;
  char_T TRANSA;
  x_data = x->data;
  if (obj->probType == 2) {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      if (obj->sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj->sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj->bineq.data[0], &incx_t,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      if (obj->sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)40;
        n_t = (ptrdiff_t)obj->sizes[2];
        lda_t = (ptrdiff_t)obj->ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &obj->Aineq->data[0], &lda_t,
              (real_T *)&x_data[ix0 - 1], &incx_t, &beta1,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      i = (uint16_T)obj->sizes[2];
      if (i < 1200) {
        for (idx = 0; idx < i; idx++) {
          y = obj->maxConstrWorkspace->data[idx] - x_data[(ix0 + idx) + 39];
          obj->maxConstrWorkspace->data[idx] = y;
          v = muDoubleScalarMax(v, y);
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        c_maxConstraintViolation_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel num_threads(c_maxConstraintViolation_numThreads) private( \
        b_vPrime, y)
        {
          b_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx < i; idx++) {
            y = obj->maxConstrWorkspace->data[idx] - x_data[(ix0 + idx) + 39];
            obj->maxConstrWorkspace->data[idx] = y;
            b_vPrime = muDoubleScalarMax(b_vPrime, y);
          }
          omp_set_nest_lock(&mexFunctions_nestLockGlobal);
          {

            v = muDoubleScalarMax(v, b_vPrime);
          }
          omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    }
  } else {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      if (obj->sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj->sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj->bineq.data[0], &incx_t,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      if (obj->sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)obj->nVar;
        n_t = (ptrdiff_t)obj->sizes[2];
        lda_t = (ptrdiff_t)obj->ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &obj->Aineq->data[0], &lda_t,
              (real_T *)&x_data[ix0 - 1], &incx_t, &beta1,
              &obj->maxConstrWorkspace->data[0], &incy_t);
      }
      i = (uint16_T)obj->sizes[2];
      if (i < 1200) {
        for (idx = 0; idx < i; idx++) {
          v = muDoubleScalarMax(v, obj->maxConstrWorkspace->data[idx]);
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        c_maxConstraintViolation_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel num_threads(c_maxConstraintViolation_numThreads) private( \
        b_vPrime)
        {
          b_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx < i; idx++) {
            b_vPrime =
                muDoubleScalarMax(b_vPrime, obj->maxConstrWorkspace->data[idx]);
          }
          omp_set_nest_lock(&mexFunctions_nestLockGlobal);
          {

            v = muDoubleScalarMax(v, b_vPrime);
          }
          omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    }
  }
  if (obj->sizes[3] > 0) {
    i = (uint16_T)obj->sizes[3];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(v, -x_data[(ix0 + obj->indexLB.data[idx]) - 2] -
                                     obj->lb.data[obj->indexLB.data[idx] - 1]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      c_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(c_maxConstraintViolation_numThreads) private( \
        vPrime, y)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          y = -x_data[(ix0 + obj->indexLB.data[idx]) - 2] -
              obj->lb.data[obj->indexLB.data[idx] - 1];
          vPrime = muDoubleScalarMax(vPrime, y);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (obj->sizes[4] > 0) {
    i = (uint16_T)obj->sizes[4];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(v, x_data[(ix0 + obj->indexUB.data[idx]) - 2] -
                                     obj->ub.data[obj->indexUB.data[idx] - 1]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      c_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(c_maxConstraintViolation_numThreads) private( \
        c_vPrime, y)
      {
        c_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          y = x_data[(ix0 + obj->indexUB.data[idx]) - 2] -
              obj->ub.data[obj->indexUB.data[idx] - 1];
          c_vPrime = muDoubleScalarMax(c_vPrime, y);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, c_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (obj->sizes[0] > 0) {
    i = (uint16_T)obj->sizes[0];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(
            v, muDoubleScalarAbs(x_data[(ix0 + obj->indexFixed.data[idx]) - 2] -
                                 obj->ub.data[obj->indexFixed.data[idx] - 1]));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      c_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(c_maxConstraintViolation_numThreads) private( \
        d_vPrime, y)
      {
        d_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          y = x_data[(ix0 + obj->indexFixed.data[idx]) - 2] -
              obj->ub.data[obj->indexFixed.data[idx] - 1];
          d_vPrime = muDoubleScalarMax(d_vPrime, muDoubleScalarAbs(y));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, d_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  return v;
}

real_T d_maxConstraintViolation(emlrtCTX aTLS, i_struct_T *obj,
                                const real_T x_data[])
{
  jmp_buf *volatile emlrtJBStack;
  real_T b_vPrime;
  real_T c_vPrime;
  real_T v;
  real_T vPrime;
  int32_T d_maxConstraintViolation_numThreads;
  int32_T i;
  int32_T idx;
  int32_T idxLB;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = c_maxConstraintViolation_AMats_(aTLS, obj, x_data);
  } else {
    v = d_maxConstraintViolation_AMats_(aTLS, obj, x_data);
  }
  if (mLB > 0) {
    i = (uint16_T)mLB;
    if ((uint16_T)mLB < 1200) {
      for (idx = 0; idx < i; idx++) {
        idxLB = obj->indexLB.data[idx] - 1;
        v = muDoubleScalarMax(v, -x_data[idxLB] - obj->lb.data[idxLB]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      d_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(d_maxConstraintViolation_numThreads) private( \
        vPrime, idxLB)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          idxLB = obj->indexLB.data[idx] - 1;
          vPrime =
              muDoubleScalarMax(vPrime, -x_data[idxLB] - obj->lb.data[idxLB]);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (mUB > 0) {
    i = (uint16_T)mUB;
    if ((uint16_T)mUB < 1200) {
      for (idx = 0; idx < i; idx++) {
        idxLB = obj->indexUB.data[idx] - 1;
        v = muDoubleScalarMax(v, x_data[idxLB] - obj->ub.data[idxLB]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      d_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(d_maxConstraintViolation_numThreads) private( \
        b_vPrime, idxLB)
      {
        b_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          idxLB = obj->indexUB.data[idx] - 1;
          b_vPrime =
              muDoubleScalarMax(b_vPrime, x_data[idxLB] - obj->ub.data[idxLB]);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, b_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (mFixed > 0) {
    i = (uint16_T)mFixed;
    if ((uint16_T)mFixed < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(
            v, muDoubleScalarAbs(x_data[obj->indexFixed.data[idx] - 1] -
                                 obj->ub.data[obj->indexFixed.data[idx] - 1]));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      d_maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(d_maxConstraintViolation_numThreads) private( \
        c_vPrime)
      {
        c_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          c_vPrime = muDoubleScalarMax(
              c_vPrime,
              muDoubleScalarAbs(x_data[obj->indexFixed.data[idx] - 1] -
                                obj->ub.data[obj->indexFixed.data[idx] - 1]));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, c_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  return v;
}

real_T maxConstraintViolation(emlrtCTX aTLS, mexFunctionsStackData *SD,
                              const i_struct_T *obj, const real_T x_data[])
{
  jmp_buf *volatile emlrtJBStack;
  real_T b_vPrime;
  real_T c_vPrime;
  real_T v;
  real_T vPrime;
  int32_T i;
  int32_T idx;
  int32_T maxConstraintViolation_numThreads;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  emxInitStruct_struct_T(&SD->f0.obj);
  if (obj->probType == 2) {
    emxCopyStruct_struct_T(&SD->f0.obj, obj);
    v = c_maxConstraintViolation_AMats_(aTLS, &SD->f0.obj, x_data);
  } else {
    emxCopyStruct_struct_T(&SD->f0.obj, obj);
    v = d_maxConstraintViolation_AMats_(aTLS, &SD->f0.obj, x_data);
  }
  if (obj->sizes[3] > 0) {
    i = (uint16_T)obj->sizes[3];
    if ((uint16_T)obj->sizes[3] < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(
            v, -x_data[SD->f0.obj.indexLB.data[idx] - 1] -
                   SD->f0.obj.lb.data[SD->f0.obj.indexLB.data[idx] - 1]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(maxConstraintViolation_numThreads) private(   \
        vPrime)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          vPrime = muDoubleScalarMax(
              vPrime, -x_data[SD->f0.obj.indexLB.data[idx] - 1] -
                          SD->f0.obj.lb.data[SD->f0.obj.indexLB.data[idx] - 1]);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (obj->sizes[4] > 0) {
    i = (uint16_T)obj->sizes[4];
    if ((uint16_T)obj->sizes[4] < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(
            v, x_data[SD->f0.obj.indexUB.data[idx] - 1] -
                   SD->f0.obj.ub.data[SD->f0.obj.indexUB.data[idx] - 1]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(maxConstraintViolation_numThreads) private(   \
        b_vPrime)
      {
        b_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          b_vPrime = muDoubleScalarMax(
              b_vPrime,
              x_data[SD->f0.obj.indexUB.data[idx] - 1] -
                  SD->f0.obj.ub.data[SD->f0.obj.indexUB.data[idx] - 1]);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, b_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  if (obj->sizes[0] > 0) {
    i = (uint16_T)obj->sizes[0];
    if ((uint16_T)obj->sizes[0] < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(
            v, muDoubleScalarAbs(
                   x_data[SD->f0.obj.indexFixed.data[idx] - 1] -
                   SD->f0.obj.ub.data[SD->f0.obj.indexFixed.data[idx] - 1]));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      maxConstraintViolation_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(maxConstraintViolation_numThreads) private(   \
        c_vPrime)
      {
        c_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          c_vPrime = muDoubleScalarMax(
              c_vPrime,
              muDoubleScalarAbs(
                  x_data[SD->f0.obj.indexFixed.data[idx] - 1] -
                  SD->f0.obj.ub.data[SD->f0.obj.indexFixed.data[idx] - 1]));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, c_vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  emxFreeStruct_struct_T(&SD->f0.obj);
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
  return v;
}

/* End of code generation (maxConstraintViolation.c) */
