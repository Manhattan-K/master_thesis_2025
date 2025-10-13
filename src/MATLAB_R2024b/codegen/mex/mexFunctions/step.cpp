//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// step.cpp
//
// Code generation for function 'step'
//

// Include files
#include "step.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "normal.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "soc.h"
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
void b_step(mexFunctionsStackData *SD, struct_T &stepFlags,
            real_T Hessian[1600], const real_T lb[40], const real_T ub[40],
            f_struct_T &b_TrialState, h_struct_T &b_MeritFunction,
            c_struct_T &memspace, g_struct_T &WorkingSet,
            d_struct_T &b_QRManager, e_struct_T &b_CholManager,
            b_struct_T &QPObjective, i_struct_T &qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> c_TrialState;
  array<real_T, 1U> d_TrialState;
  array<real_T, 1U> e_TrialState;
  array<real_T, 1U> r;
  real_T tmp_data[4241];
  real_T nrmDirInf;
  real_T nrmGradInf;
  int32_T iH0;
  int32_T idxStartIneq;
  int32_T idx_global;
  int32_T nVar_tmp;
  boolean_T checkBoundViolation;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  stepFlags.stepAccepted = true;
  checkBoundViolation = true;
  nVar_tmp = WorkingSet.nVar;
  if (stepFlags.stepType != 3) {
    idx_global = static_cast<uint16_T>(WorkingSet.nVar);
    for (idxStartIneq = 0; idxStartIneq < idx_global; idxStartIneq++) {
      b_TrialState.xstar.data[idxStartIneq] =
          b_TrialState.xstarsqp[idxStartIneq];
    }
  } else {
    r.set_size(b_TrialState.searchDir.size[0]);
    idxStartIneq = b_TrialState.searchDir.size[0];
    for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
      r[idx_global] = b_TrialState.searchDir.data[idx_global];
    }
    c_TrialState.set(&b_TrialState.xstar.data[0], b_TrialState.xstar.size[0]);
    if (nVar_tmp >= 1) {
      n_t = (ptrdiff_t)nVar_tmp;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(c_TrialState.data())[0], &incx_t, &(r.data())[0], &incy_t);
    }
    idxStartIneq = r.size(0);
    b_TrialState.searchDir.size[0] = r.size(0);
    for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
      b_TrialState.searchDir.data[idx_global] = r[idx_global];
    }
  }
  int32_T exitg1;
  boolean_T guard1;
  do {
    int32_T idxEndIneq;
    exitg1 = 0;
    guard1 = false;
    switch (stepFlags.stepType) {
    case 1:
      step::normal(SD, Hessian, b_TrialState.grad.data, b_TrialState,
                   b_MeritFunction, memspace, WorkingSet, b_QRManager,
                   b_CholManager, QPObjective, qpoptions, stepFlags);
      if (stepFlags.stepType != 2) {
        r.set_size(b_TrialState.delta_x.size[0]);
        idxStartIneq = b_TrialState.delta_x.size[0];
        for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
          r[idx_global] = b_TrialState.delta_x.data[idx_global];
        }
        d_TrialState.set(&b_TrialState.xstar.data[0],
                         b_TrialState.xstar.size[0]);
        if (nVar_tmp >= 1) {
          n_t = (ptrdiff_t)nVar_tmp;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &(d_TrialState.data())[0], &incx_t, &(r.data())[0],
                &incy_t);
        }
        idxStartIneq = r.size(0);
        b_TrialState.delta_x.size[0] = r.size(0);
        for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
          b_TrialState.delta_x.data[idx_global] = r[idx_global];
        }
        guard1 = true;
      }
      break;
    case 2:
      iH0 = WorkingSet.nWConstr[0] + WorkingSet.nWConstr[1];
      idxStartIneq = iH0 + 1;
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
      WorkingSet.nActiveConstr = iH0;
      idxStartIneq = b_TrialState.xstar.size[0];
      iH0 = b_TrialState.xstar.size[0];
      for (idx_global = 0; idx_global < iH0; idx_global++) {
        tmp_data[idx_global] = b_TrialState.xstar.data[idx_global];
      }
      idx_global = static_cast<uint16_T>(WorkingSet.sizes[3]);
      for (iH0 = 0; iH0 < idx_global; iH0++) {
        nrmGradInf = WorkingSet.lb.data[WorkingSet.indexLB.data[iH0] - 1];
        if (-tmp_data[WorkingSet.indexLB.data[iH0] - 1] > nrmGradInf) {
          if (muDoubleScalarIsInf(ub[WorkingSet.indexLB.data[iH0] - 1])) {
            tmp_data[WorkingSet.indexLB.data[iH0] - 1] =
                -nrmGradInf + muDoubleScalarAbs(nrmGradInf);
          } else {
            tmp_data[WorkingSet.indexLB.data[iH0] - 1] =
                (WorkingSet.ub.data[WorkingSet.indexLB.data[iH0] - 1] -
                 nrmGradInf) /
                2.0;
          }
        }
      }
      idx_global = static_cast<uint16_T>(WorkingSet.sizes[4]);
      for (iH0 = 0; iH0 < idx_global; iH0++) {
        nrmGradInf = WorkingSet.ub.data[WorkingSet.indexUB.data[iH0] - 1];
        if (tmp_data[WorkingSet.indexUB.data[iH0] - 1] > nrmGradInf) {
          if (muDoubleScalarIsInf(lb[WorkingSet.indexUB.data[iH0] - 1])) {
            tmp_data[WorkingSet.indexUB.data[iH0] - 1] =
                nrmGradInf - muDoubleScalarAbs(nrmGradInf);
          } else {
            tmp_data[WorkingSet.indexUB.data[iH0] - 1] =
                (nrmGradInf -
                 WorkingSet.lb.data[WorkingSet.indexUB.data[iH0] - 1]) /
                2.0;
          }
        }
      }
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        b_TrialState.xstar.data[idx_global] = tmp_data[idx_global];
      }
      step::b_relaxed(Hessian, b_TrialState.grad.data,
                      b_TrialState.grad.size[0], b_TrialState, b_MeritFunction,
                      memspace, WorkingSet, b_QRManager, b_CholManager,
                      QPObjective, qpoptions);
      r.set_size(b_TrialState.delta_x.size[0]);
      idxStartIneq = b_TrialState.delta_x.size[0];
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        r[idx_global] = b_TrialState.delta_x.data[idx_global];
      }
      e_TrialState.set(&b_TrialState.xstar.data[0], b_TrialState.xstar.size[0]);
      if (nVar_tmp >= 1) {
        n_t = (ptrdiff_t)nVar_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(e_TrialState.data())[0], &incx_t, &(r.data())[0],
              &incy_t);
      }
      idxStartIneq = r.size(0);
      b_TrialState.delta_x.size[0] = r.size(0);
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        b_TrialState.delta_x.data[idx_global] = r[idx_global];
      }
      guard1 = true;
      break;
    default:
      idxStartIneq = b_TrialState.grad.size[0];
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        tmp_data[idx_global] = b_TrialState.grad.data[idx_global];
      }
      checkBoundViolation =
          step::b_soc(Hessian, tmp_data, b_TrialState, memspace, WorkingSet,
                      b_QRManager, b_CholManager, QPObjective, qpoptions);
      stepFlags.stepAccepted = checkBoundViolation;
      if (stepFlags.stepAccepted && (b_TrialState.state != -6)) {
        idx_global = static_cast<uint16_T>(nVar_tmp);
        for (iH0 = 0; iH0 < idx_global; iH0++) {
          b_TrialState.delta_x.data[iH0] = b_TrialState.xstar.data[iH0] +
                                           b_TrialState.socDirection.data[iH0];
        }
      }
      guard1 = true;
      break;
    }
    if (guard1) {
      if (b_TrialState.state != -6) {
        exitg1 = 1;
      } else {
        nrmGradInf = 0.0;
        nrmDirInf = 1.0;
        for (iH0 = 0; iH0 < 40; iH0++) {
          nrmGradInf = muDoubleScalarMax(
              nrmGradInf, muDoubleScalarAbs(b_TrialState.grad.data[iH0]));
          nrmDirInf = muDoubleScalarMax(
              nrmDirInf, muDoubleScalarAbs(b_TrialState.xstar.data[iH0]));
        }
        nrmGradInf =
            muDoubleScalarMax(2.2204460492503131E-16, nrmGradInf / nrmDirInf);
        for (idxEndIneq = 0; idxEndIneq < 40; idxEndIneq++) {
          iH0 = 40 * idxEndIneq;
          for (idxStartIneq = 0; idxStartIneq < idxEndIneq; idxStartIneq++) {
            Hessian[iH0 + idxStartIneq] = 0.0;
          }
          iH0 = idxEndIneq + 40 * idxEndIneq;
          Hessian[iH0] = nrmGradInf;
          idx_global = 38 - idxEndIneq;
          if (idx_global >= 0) {
            std::memset(&Hessian[iH0 + 1], 0,
                        static_cast<uint32_T>(idx_global + 1) * sizeof(real_T));
          }
        }
      }
    }
  } while (exitg1 == 0);
  if (checkBoundViolation) {
    idxStartIneq = b_TrialState.delta_x.size[0];
    iH0 = b_TrialState.delta_x.size[0];
    for (idx_global = 0; idx_global < iH0; idx_global++) {
      tmp_data[idx_global] = b_TrialState.delta_x.data[idx_global];
    }
    idx_global = static_cast<uint16_T>(WorkingSet.sizes[3]);
    for (iH0 = 0; iH0 < idx_global; iH0++) {
      nrmGradInf = tmp_data[WorkingSet.indexLB.data[iH0] - 1];
      nrmDirInf = (b_TrialState.xstarsqp[WorkingSet.indexLB.data[iH0] - 1] +
                   nrmGradInf) -
                  lb[WorkingSet.indexLB.data[iH0] - 1];
      if (nrmDirInf < 0.0) {
        tmp_data[WorkingSet.indexLB.data[iH0] - 1] = nrmGradInf - nrmDirInf;
        b_TrialState.xstar.data[WorkingSet.indexLB.data[iH0] - 1] -= nrmDirInf;
      }
    }
    idx_global = static_cast<uint16_T>(WorkingSet.sizes[4]);
    for (iH0 = 0; iH0 < idx_global; iH0++) {
      nrmGradInf = tmp_data[WorkingSet.indexUB.data[iH0] - 1];
      nrmDirInf = (ub[WorkingSet.indexUB.data[iH0] - 1] -
                   b_TrialState.xstarsqp[WorkingSet.indexUB.data[iH0] - 1]) -
                  nrmGradInf;
      if (nrmDirInf < 0.0) {
        tmp_data[WorkingSet.indexUB.data[iH0] - 1] = nrmGradInf + nrmDirInf;
        b_TrialState.xstar.data[WorkingSet.indexUB.data[iH0] - 1] += nrmDirInf;
      }
    }
    for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
      b_TrialState.delta_x.data[idx_global] = tmp_data[idx_global];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (step.cpp)
