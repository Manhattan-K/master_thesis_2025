//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// maxConstraintViolation.cpp
//
// Code generation for function 'maxConstraintViolation'
//

// Include files
#include "maxConstraintViolation.h"
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "maxConstraintViolation_AMats_regularized_.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
real_T b_maxConstraintViolation(g_struct_T &obj, const array<real_T, 2U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  real_T v;
  int32_T i;
  int32_T idxLB;
  char_T TRANSA;
  if (obj.probType == 2) {
    v = 0.0;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.bineq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      if (obj.sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)40;
        n_t = (ptrdiff_t)obj.sizes[2];
        lda_t = (ptrdiff_t)obj.ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(obj.Aineq.data())[0], &lda_t,
              &(x.data())[0], &incx_t, &beta1,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      i = static_cast<uint16_T>(obj.sizes[2]);
      for (int32_T idx{0}; idx < i; idx++) {
        alpha1 = obj.maxConstrWorkspace[idx] - x[idx + 40];
        obj.maxConstrWorkspace[idx] = alpha1;
        v = muDoubleScalarMax(v, alpha1);
      }
    }
  } else {
    v = 0.0;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.bineq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      if (obj.sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)obj.nVar;
        n_t = (ptrdiff_t)obj.sizes[2];
        lda_t = (ptrdiff_t)obj.ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(obj.Aineq.data())[0], &lda_t,
              &(x.data())[0], &incx_t, &beta1,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      i = static_cast<uint16_T>(obj.sizes[2]);
      for (int32_T idx{0}; idx < i; idx++) {
        v = muDoubleScalarMax(v, obj.maxConstrWorkspace[idx]);
      }
    }
  }
  if (obj.sizes[3] > 0) {
    i = static_cast<uint16_T>(obj.sizes[3]);
    for (int32_T idx{0}; idx < i; idx++) {
      idxLB = obj.indexLB.data[idx] - 1;
      v = muDoubleScalarMax(v, -x[idxLB] - obj.lb.data[idxLB]);
    }
  }
  if (obj.sizes[4] > 0) {
    i = static_cast<uint16_T>(obj.sizes[4]);
    for (int32_T idx{0}; idx < i; idx++) {
      idxLB = obj.indexUB.data[idx] - 1;
      v = muDoubleScalarMax(v, x[idxLB] - obj.ub.data[idxLB]);
    }
  }
  if (obj.sizes[0] > 0) {
    i = static_cast<uint16_T>(obj.sizes[0]);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[obj.indexFixed.data[idx] - 1] -
                               obj.ub.data[obj.indexFixed.data[idx] - 1]));
    }
  }
  return v;
}

real_T b_maxConstraintViolation(g_struct_T &obj, const array<real_T, 2U> &x,
                                int32_T ix0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  real_T v;
  int32_T i;
  char_T TRANSA;
  if (obj.probType == 2) {
    v = 0.0;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.bineq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      if (obj.sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)40;
        n_t = (ptrdiff_t)obj.sizes[2];
        lda_t = (ptrdiff_t)obj.ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(obj.Aineq.data())[0], &lda_t,
              (real_T *)&x[ix0 - 1], &incx_t, &beta1,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      i = static_cast<uint16_T>(obj.sizes[2]);
      for (int32_T idx{0}; idx < i; idx++) {
        alpha1 = obj.maxConstrWorkspace[idx] - x[(ix0 + idx) + 39];
        obj.maxConstrWorkspace[idx] = alpha1;
        v = muDoubleScalarMax(v, alpha1);
      }
    }
  } else {
    v = 0.0;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[2];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.bineq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      if (obj.sizes[2] >= 1) {
        alpha1 = 1.0;
        beta1 = -1.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)obj.nVar;
        n_t = (ptrdiff_t)obj.sizes[2];
        lda_t = (ptrdiff_t)obj.ldA;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(obj.Aineq.data())[0], &lda_t,
              (real_T *)&x[ix0 - 1], &incx_t, &beta1,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      i = static_cast<uint16_T>(obj.sizes[2]);
      for (int32_T idx{0}; idx < i; idx++) {
        v = muDoubleScalarMax(v, obj.maxConstrWorkspace[idx]);
      }
    }
  }
  if (obj.sizes[3] > 0) {
    i = static_cast<uint16_T>(obj.sizes[3]);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(v, -x[(ix0 + obj.indexLB.data[idx]) - 2] -
                                   obj.lb.data[obj.indexLB.data[idx] - 1]);
    }
  }
  if (obj.sizes[4] > 0) {
    i = static_cast<uint16_T>(obj.sizes[4]);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(v, x[(ix0 + obj.indexUB.data[idx]) - 2] -
                                   obj.ub.data[obj.indexUB.data[idx] - 1]);
    }
  }
  if (obj.sizes[0] > 0) {
    i = static_cast<uint16_T>(obj.sizes[0]);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[(ix0 + obj.indexFixed.data[idx]) - 2] -
                               obj.ub.data[obj.indexFixed.data[idx] - 1]));
    }
  }
  return v;
}

real_T b_maxConstraintViolation(g_struct_T &obj, const real_T x_data[])
{
  real_T v;
  int32_T i;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  mLB = obj.sizes[3];
  mUB = obj.sizes[4];
  mFixed = obj.sizes[0];
  if (obj.probType == 2) {
    v = c_maxConstraintViolation_AMats_(obj, x_data);
  } else {
    v = d_maxConstraintViolation_AMats_(obj, x_data);
  }
  if (mLB > 0) {
    i = static_cast<uint16_T>(mLB);
    for (int32_T idx{0}; idx < i; idx++) {
      mLB = obj.indexLB.data[idx] - 1;
      v = muDoubleScalarMax(v, -x_data[mLB] - obj.lb.data[mLB]);
    }
  }
  if (mUB > 0) {
    i = static_cast<uint16_T>(mUB);
    for (int32_T idx{0}; idx < i; idx++) {
      mLB = obj.indexUB.data[idx] - 1;
      v = muDoubleScalarMax(v, x_data[mLB] - obj.ub.data[mLB]);
    }
  }
  if (mFixed > 0) {
    i = static_cast<uint16_T>(mFixed);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x_data[obj.indexFixed.data[idx] - 1] -
                               obj.ub.data[obj.indexFixed.data[idx] - 1]));
    }
  }
  return v;
}

real_T b_maxConstraintViolation(mexFunctionsStackData *SD,
                                const g_struct_T &obj, const real_T x_data[])
{
  real_T v;
  int32_T i;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  if (obj.probType == 2) {
    SD->f0.obj = obj;
    v = c_maxConstraintViolation_AMats_(SD->f0.obj, x_data);
  } else {
    SD->f0.obj = obj;
    v = d_maxConstraintViolation_AMats_(SD->f0.obj, x_data);
  }
  if (obj.sizes[3] > 0) {
    i = static_cast<uint16_T>(obj.sizes[3]);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(
          v, -x_data[SD->f0.obj.indexLB.data[idx] - 1] -
                 SD->f0.obj.lb.data[SD->f0.obj.indexLB.data[idx] - 1]);
    }
  }
  if (obj.sizes[4] > 0) {
    i = static_cast<uint16_T>(obj.sizes[4]);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(
          v, x_data[SD->f0.obj.indexUB.data[idx] - 1] -
                 SD->f0.obj.ub.data[SD->f0.obj.indexUB.data[idx] - 1]);
    }
  }
  if (obj.sizes[0] > 0) {
    i = static_cast<uint16_T>(obj.sizes[0]);
    for (int32_T idx{0}; idx < i; idx++) {
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(
                 x_data[SD->f0.obj.indexFixed.data[idx] - 1] -
                 SD->f0.obj.ub.data[SD->f0.obj.indexFixed.data[idx] - 1]));
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return v;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (maxConstraintViolation.cpp)
