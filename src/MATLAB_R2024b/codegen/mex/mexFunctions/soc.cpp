//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// soc.cpp
//
// Code generation for function 'soc'
//

// Include files
#include "soc.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSet.h"
#include "xnrm2.h"
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
namespace step {
boolean_T b_soc(const real_T Hessian[1600], const real_T grad_data[],
                f_struct_T &b_TrialState, c_struct_T &memspace,
                g_struct_T &WorkingSet, d_struct_T &b_QRManager,
                e_struct_T &b_CholManager, b_struct_T &QPObjective,
                const i_struct_T &qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T idxStartIneq;
  int32_T idx_global;
  int32_T mIneq;
  int32_T mLB;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  int32_T n_tmp;
  boolean_T success;
  nWIneq_old = WorkingSet.nWConstr[2];
  nWLower_old = WorkingSet.nWConstr[3];
  nWUpper_old = WorkingSet.nWConstr[4];
  idxStartIneq = WorkingSet.nVar;
  idx_global = static_cast<uint16_T>(WorkingSet.nVar);
  std::copy(&b_TrialState.xstarsqp_old[0],
            &b_TrialState.xstarsqp_old[idx_global], &b_TrialState.xstarsqp[0]);
  std::copy(&b_TrialState.xstar.data[0], &b_TrialState.xstar.data[idx_global],
            &b_TrialState.socDirection.data[0]);
  n_tmp = WorkingSet.mConstrMax;
  if (n_tmp >= 1) {
    n_t = (ptrdiff_t)n_tmp;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.lambda.data())[0], &incx_t,
          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
  }
  soc::updateWorkingSet(WorkingSet, b_TrialState.cIneq.data,
                        b_TrialState.searchDir.data,
                        b_TrialState.workingset_old.data);
  idx_global = static_cast<uint16_T>(WorkingSet.nVar);
  std::copy(&b_TrialState.xstarsqp[0], &b_TrialState.xstarsqp[idx_global],
            &b_TrialState.xstar.data[0]);
  ::coder::optim::coder::qpactiveset::driver(
      Hessian, grad_data, b_TrialState, memspace, WorkingSet, b_QRManager,
      b_CholManager, QPObjective, qpoptions, qpoptions);
  idx_global = static_cast<uint16_T>(idxStartIneq);
  for (int32_T idx{0}; idx < idx_global; idx++) {
    real_T d;
    real_T oldDirIdx;
    d = b_TrialState.socDirection.data[idx];
    oldDirIdx = d;
    d = b_TrialState.xstar.data[idx] - d;
    b_TrialState.socDirection.data[idx] = d;
    b_TrialState.xstar.data[idx] = oldDirIdx;
  }
  success = (::coder::internal::blas::xnrm2(idxStartIneq,
                                            b_TrialState.socDirection.data) <=
             2.0 * ::coder::internal::blas::xnrm2(idxStartIneq,
                                                  b_TrialState.xstar.data));
  mIneq = WorkingSet.sizes[2];
  mLB = WorkingSet.sizes[3];
  if (WorkingSet.sizes[2] > 0) {
    idx_global = static_cast<uint16_T>(WorkingSet.sizes[2]);
    for (int32_T idx{0}; idx < idx_global; idx++) {
      WorkingSet.bineq.data[idx] = -b_TrialState.cIneq.data[idx];
    }
    if (!success) {
      int32_T idxEndIneq;
      n_tmp = WorkingSet.nWConstr[0] + WorkingSet.nWConstr[1];
      idxStartIneq = n_tmp + 1;
      idxEndIneq = WorkingSet.nActiveConstr;
      for (idx_global = idxStartIneq; idx_global <= idxEndIneq; idx_global++) {
        WorkingSet.isActiveConstr.data
            [(WorkingSet.isActiveIdx[WorkingSet.Wid.data[idx_global - 1] - 1] +
              WorkingSet.Wlocalidx.data[idx_global - 1]) -
             2] = false;
      }
      WorkingSet.nWConstr[2] = 0;
      WorkingSet.nWConstr[3] = 0;
      WorkingSet.nWConstr[4] = 0;
      WorkingSet.nActiveConstr = n_tmp;
      for (int32_T idx{0}; idx < nWIneq_old; idx++) {
        n_tmp = b_TrialState.workingset_old.data[idx];
        WorkingSet.nWConstr[2]++;
        WorkingSet.isActiveConstr
            .data[(WorkingSet.isActiveIdx[2] + n_tmp) - 2] = true;
        WorkingSet.nActiveConstr++;
        idx_global = WorkingSet.nActiveConstr - 1;
        WorkingSet.Wid.data[idx_global] = 3;
        WorkingSet.Wlocalidx.data[idx_global] = n_tmp;
        idxStartIneq = WorkingSet.ldA * (n_tmp - 1);
        idxEndIneq = WorkingSet.ldA * idx_global;
        idx_global = WorkingSet.nVar;
        for (int32_T b_idx{0}; b_idx < idx_global; b_idx++) {
          WorkingSet.ATwset[idxEndIneq + b_idx] =
              WorkingSet.Aineq[idxStartIneq + b_idx];
        }
        WorkingSet.bwset[WorkingSet.nActiveConstr - 1] =
            WorkingSet.bineq.data[n_tmp - 1];
      }
      for (int32_T idx{0}; idx < nWLower_old; idx++) {
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            WorkingSet, 4, b_TrialState.workingset_old.data[idx + mIneq]);
      }
      for (int32_T idx{0}; idx < nWUpper_old; idx++) {
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            WorkingSet, 5,
            b_TrialState.workingset_old.data[(idx + mIneq) + mLB]);
      }
    }
  }
  if (!success) {
    n_tmp = WorkingSet.mConstrMax;
    if (n_tmp >= 1) {
      n_t = (ptrdiff_t)n_tmp;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
            &(b_TrialState.lambda.data())[0], &incy_t);
    }
  } else {
    qpactiveset::parseoutput::sortLambdaQP(
        b_TrialState.lambda, WorkingSet.nActiveConstr, WorkingSet.sizes,
        WorkingSet.isActiveIdx, WorkingSet.Wid.data, WorkingSet.Wlocalidx.data,
        memspace.workspace_float);
  }
  return success;
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (soc.cpp)
