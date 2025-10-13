//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// revertSolution.cpp
//
// Code generation for function 'revertSolution'
//

// Include files
#include "revertSolution.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void revertSolution(f_struct_T &obj)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  obj.sqpFval = obj.sqpFval_old;
  std::copy(&obj.xstarsqp_old[0], &obj.xstarsqp_old[40], &obj.xstarsqp[0]);
  y.set_size(obj.cIneq.size[0]);
  loop_ub = obj.cIneq.size[0];
  for (int32_T i{0}; i < loop_ub; i++) {
    y[i] = obj.cIneq.data[i];
  }
  if (obj.mIneq >= 1) {
    n_t = (ptrdiff_t)obj.mIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &obj.cIneq_old.data[0], &incx_t, &(y.data())[0], &incy_t);
  }
  loop_ub = y.size(0);
  obj.cIneq.size[0] = y.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    obj.cIneq.data[i] = y[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace TrialState
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (revertSolution.cpp)
