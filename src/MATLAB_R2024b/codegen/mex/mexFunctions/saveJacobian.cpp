//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// saveJacobian.cpp
//
// Code generation for function 'saveJacobian'
//

// Include files
#include "saveJacobian.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void saveJacobian(f_struct_T &obj, int32_T nVar, int32_T mIneq,
                  const array<real_T, 1U> &JacCineqTrans, int32_T ineqCol0,
                  int32_T ldJ)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 2U> y;
  int32_T i;
  int32_T iCol;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  iCol = ldJ * (ineqCol0 - 1);
  i = mIneq - ineqCol0;
  for (int32_T idx_col{0}; idx_col <= i; idx_col++) {
    int32_T i1;
    int32_T loop_ub_tmp;
    i1 = obj.JacCineqTrans_old.size(0);
    loop_ub_tmp = obj.JacCineqTrans_old.size(1);
    y.set_size(i1, loop_ub_tmp);
    loop_ub_tmp *= i1;
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      y[i1] = obj.JacCineqTrans_old[i1];
    }
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    i1 = idx_col * ldJ;
    dcopy(&n_t, (real_T *)&JacCineqTrans[iCol + i1], &incx_t, &y[i1], &incy_t);
    obj.JacCineqTrans_old.set_size(y.size(0), y.size(1));
    loop_ub_tmp = y.size(0) * y.size(1);
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      obj.JacCineqTrans_old[i1] = y[i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace TrialState
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (saveJacobian.cpp)
