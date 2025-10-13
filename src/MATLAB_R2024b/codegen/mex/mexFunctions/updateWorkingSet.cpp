//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// updateWorkingSet.cpp
//
// Code generation for function 'updateWorkingSet'
//

// Include files
#include "updateWorkingSet.h"
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
namespace step {
namespace soc {
void updateWorkingSet(g_struct_T &WorkingSet,
                      const real_T TrialState_cIneq_data[],
                      const real_T TrialState_searchDir_data[],
                      int32_T workspace_int_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  real_T alpha1;
  real_T beta1;
  int32_T idxIneqOffset;
  char_T TRANSA;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  idxIneqOffset = WorkingSet.isActiveIdx[2];
  if (WorkingSet.sizes[2] > 0) {
    int32_T i;
    int32_T idx_Aineq;
    int32_T idx_lower;
    int32_T idx_upper;
    i = static_cast<uint16_T>(WorkingSet.sizes[2]);
    for (int32_T idx{0}; idx < i; idx++) {
      WorkingSet.bineq.data[idx] = -TrialState_cIneq_data[idx];
    }
    y.set_size(WorkingSet.bineq.size[0]);
    idx_Aineq = WorkingSet.bineq.size[0];
    for (i = 0; i < idx_Aineq; i++) {
      y[i] = WorkingSet.bineq.data[i];
    }
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)WorkingSet.nVar;
    n_t = (ptrdiff_t)WorkingSet.sizes[2];
    lda_t = (ptrdiff_t)WorkingSet.ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(WorkingSet.Aineq.data())[0], &lda_t,
          (real_T *)&TrialState_searchDir_data[0], &incx_t, &beta1,
          &(y.data())[0], &incy_t);
    idx_Aineq = y.size(0);
    WorkingSet.bineq.size[0] = y.size(0);
    for (i = 0; i < idx_Aineq; i++) {
      WorkingSet.bineq.data[i] = y[i];
    }
    idx_Aineq = 1;
    idx_lower = WorkingSet.sizes[2] + 1;
    idx_upper = (WorkingSet.sizes[2] + WorkingSet.sizes[3]) + 1;
    i = WorkingSet.nActiveConstr;
    for (int32_T idx{idxIneqOffset}; idx <= i; idx++) {
      int32_T idx_Partition;
      switch (WorkingSet.Wid.data[idx - 1]) {
      case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        WorkingSet.bwset[idx - 1] = y[WorkingSet.Wlocalidx.data[idx - 1] - 1];
        break;
      case 4:
        idx_Partition = idx_lower;
        idx_lower++;
        break;
      default:
        idx_Partition = idx_upper;
        idx_upper++;
        break;
      }
      workspace_int_data[idx_Partition - 1] =
          WorkingSet.Wlocalidx.data[idx - 1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace soc
} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (updateWorkingSet.cpp)
