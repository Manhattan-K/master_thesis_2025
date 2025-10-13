//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// saveState.cpp
//
// Code generation for function 'saveState'
//

// Include files
#include "saveState.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void saveState(f_struct_T &obj)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  int32_T k;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  obj.sqpFval_old = obj.sqpFval;
  for (k = 0; k < 40; k++) {
    obj.xstarsqp_old[k] = obj.xstarsqp[k];
    obj.grad_old.data[k] = obj.grad.data[k];
  }
  y.set_size(obj.cIneq_old.size[0]);
  k = obj.cIneq_old.size[0];
  for (int32_T i{0}; i < k; i++) {
    y[i] = obj.cIneq_old.data[i];
  }
  if (obj.mIneq >= 1) {
    n_t = (ptrdiff_t)obj.mIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &obj.cIneq.data[0], &incx_t, &(y.data())[0], &incy_t);
  }
  k = y.size(0);
  obj.cIneq_old.size[0] = y.size(0);
  for (int32_T i{0}; i < k; i++) {
    obj.cIneq_old.data[i] = y[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace TrialState
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (saveState.cpp)
