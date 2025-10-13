//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// updateWorkingSetForNewQP.cpp
//
// Code generation for function 'updateWorkingSetForNewQP'
//

// Include files
#include "updateWorkingSetForNewQP.h"
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
namespace fminconsqp {
namespace internal {
void updateWorkingSetForNewQP(const real_T xk[40], g_struct_T &WorkingSet,
                              int32_T mIneq, const real_T cIneq_data[],
                              int32_T mLB, const real_T lb[40], int32_T mUB,
                              const real_T ub[40], int32_T mFixed)
{
  int32_T i;
  i = static_cast<uint16_T>(mIneq);
  for (int32_T idx{0}; idx < i; idx++) {
    WorkingSet.bineq.data[idx] = -cIneq_data[idx];
  }
  i = static_cast<uint16_T>(mLB);
  for (int32_T idx{0}; idx < i; idx++) {
    WorkingSet.lb.data[WorkingSet.indexLB.data[idx] - 1] =
        -lb[WorkingSet.indexLB.data[idx] - 1] +
        xk[WorkingSet.indexLB.data[idx] - 1];
  }
  i = static_cast<uint16_T>(mUB);
  for (int32_T idx{0}; idx < i; idx++) {
    WorkingSet.ub.data[WorkingSet.indexUB.data[idx] - 1] =
        ub[WorkingSet.indexUB.data[idx] - 1] -
        xk[WorkingSet.indexUB.data[idx] - 1];
  }
  i = static_cast<uint16_T>(mFixed);
  for (int32_T idx{0}; idx < i; idx++) {
    real_T d;
    d = ub[WorkingSet.indexFixed.data[idx] - 1] -
        xk[WorkingSet.indexFixed.data[idx] - 1];
    WorkingSet.ub.data[WorkingSet.indexFixed.data[idx] - 1] = d;
    WorkingSet.bwset[idx] = d;
  }
}

void updateWorkingSetForNewQP(const real_T xk[40], g_struct_T &WorkingSet,
                              int32_T mIneq, int32_T mNonlinIneq,
                              const real_T cIneq_data[], int32_T mLB,
                              const real_T lb[40], int32_T mUB,
                              const real_T ub[40], int32_T mFixed)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T i;
  i = static_cast<uint16_T>(mIneq);
  for (int32_T idx{0}; idx < i; idx++) {
    WorkingSet.bineq.data[idx] = -cIneq_data[idx];
  }
  i = static_cast<uint16_T>(mLB);
  for (int32_T idx{0}; idx < i; idx++) {
    WorkingSet.lb.data[WorkingSet.indexLB.data[idx] - 1] =
        -lb[WorkingSet.indexLB.data[idx] - 1] +
        xk[WorkingSet.indexLB.data[idx] - 1];
  }
  i = static_cast<uint16_T>(mUB);
  for (int32_T idx{0}; idx < i; idx++) {
    WorkingSet.ub.data[WorkingSet.indexUB.data[idx] - 1] =
        ub[WorkingSet.indexUB.data[idx] - 1] -
        xk[WorkingSet.indexUB.data[idx] - 1];
  }
  i = static_cast<uint16_T>(mFixed);
  for (int32_T idx{0}; idx < i; idx++) {
    real_T d;
    d = ub[WorkingSet.indexFixed.data[idx] - 1] -
        xk[WorkingSet.indexFixed.data[idx] - 1];
    WorkingSet.ub.data[WorkingSet.indexFixed.data[idx] - 1] = d;
    WorkingSet.bwset[idx] = d;
  }
  if (WorkingSet.nActiveConstr > mFixed) {
    int32_T ineqStart;
    i = mFixed + 1;
    ineqStart = muIntScalarMax_sint32(i, 1);
    i = WorkingSet.nActiveConstr;
    for (int32_T idx{ineqStart}; idx <= i; idx++) {
      switch (WorkingSet.Wid.data[idx - 1]) {
      case 4:
        WorkingSet.bwset[idx - 1] =
            WorkingSet.lb
                .data[WorkingSet.indexLB
                          .data[WorkingSet.Wlocalidx.data[idx - 1] - 1] -
                      1];
        break;
      case 5:
        WorkingSet.bwset[idx - 1] =
            WorkingSet.ub
                .data[WorkingSet.indexUB
                          .data[WorkingSet.Wlocalidx.data[idx - 1] - 1] -
                      1];
        break;
      default:
        WorkingSet.bwset[idx - 1] =
            WorkingSet.bineq.data[WorkingSet.Wlocalidx.data[idx - 1] - 1];
        if ((mNonlinIneq > 0) &&
            (WorkingSet.Wlocalidx.data[idx - 1] > mIneq - mNonlinIneq)) {
          n_t = (ptrdiff_t)WorkingSet.nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t,
                &WorkingSet.Aineq[WorkingSet.ldA *
                                  (WorkingSet.Wlocalidx.data[idx - 1] - 1)],
                &incx_t, &WorkingSet.ATwset[WorkingSet.ldA * (idx - 1)],
                &incy_t);
        }
        break;
      }
    }
  }
}

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (updateWorkingSetForNewQP.cpp)
