/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * step.c
 *
 * Code generation for function 'step'
 *
 */

/* Include files */
#include "step.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "normal.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "soc.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void step(evaluateObstacles_mexStackData *SD, struct_T *stepFlags,
          real_T Hessian[1600], const real_T lb_data[],
          const int32_T lb_size[2], const real_T ub_data[],
          const int32_T ub_size[2], j_struct_T *TrialState,
          l_struct_T *MeritFunction, e_struct_T *memspace,
          k_struct_T *WorkingSet, f_struct_T *QRManager,
          n_struct_T *CholManager, d_struct_T *QPObjective,
          o_struct_T *qpoptions)
{
  emxArray_real_T b_TrialState;
  emxArray_real_T c_TrialState;
  emxArray_real_T d_TrialState;
  emxArray_real_T *r;
  real_T tmp_data[4241];
  real_T nrmDirInf;
  real_T nrmGradInf;
  real_T *r1;
  int32_T iH0;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T idx_global;
  int32_T nVar;
  boolean_T checkBoundViolation;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  stepFlags->stepAccepted = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar;
  emxInit_real_T(&r, 1);
  if (stepFlags->stepType != 3) {
    idx_global = (uint16_T)WorkingSet->nVar;
    for (idxStartIneq = 0; idxStartIneq < idx_global; idxStartIneq++) {
      TrialState->xstar.data[idxStartIneq] = TrialState->xstarsqp[idxStartIneq];
    }
  } else {
    idx_global = r->size[0];
    r->size[0] = TrialState->searchDir.size[0];
    emxEnsureCapacity_real_T(r, idx_global);
    r1 = r->data;
    idxStartIneq = TrialState->searchDir.size[0];
    for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
      r1[idx_global] = TrialState->searchDir.data[idx_global];
    }
    b_TrialState.data = &TrialState->xstar.data[0];
    b_TrialState.size = &TrialState->xstar.size[0];
    b_TrialState.allocatedSize = 4241;
    b_TrialState.numDimensions = 1;
    b_TrialState.canFreeData = false;
    xcopy(WorkingSet->nVar, &b_TrialState, r);
    r1 = r->data;
    idxStartIneq = r->size[0];
    TrialState->searchDir.size[0] = r->size[0];
    for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
      TrialState->searchDir.data[idx_global] = r1[idx_global];
    }
  }
  int32_T exitg1;
  boolean_T guard1;
  do {
    exitg1 = 0;
    guard1 = false;
    switch (stepFlags->stepType) {
    case 1:
      normal(SD, Hessian, TrialState->grad.data, TrialState, MeritFunction,
             memspace, WorkingSet, QRManager, CholManager, QPObjective,
             qpoptions, stepFlags);
      if (stepFlags->stepType != 2) {
        idx_global = r->size[0];
        r->size[0] = TrialState->delta_x.size[0];
        emxEnsureCapacity_real_T(r, idx_global);
        r1 = r->data;
        idxStartIneq = TrialState->delta_x.size[0];
        for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
          r1[idx_global] = TrialState->delta_x.data[idx_global];
        }
        c_TrialState.data = &TrialState->xstar.data[0];
        c_TrialState.size = &TrialState->xstar.size[0];
        c_TrialState.allocatedSize = 4241;
        c_TrialState.numDimensions = 1;
        c_TrialState.canFreeData = false;
        xcopy(nVar, &c_TrialState, r);
        r1 = r->data;
        idxStartIneq = r->size[0];
        TrialState->delta_x.size[0] = r->size[0];
        for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
          TrialState->delta_x.data[idx_global] = r1[idx_global];
        }
        guard1 = true;
      }
      break;
    case 2:
      iH0 = WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1];
      idxStartIneq = iH0 + 1;
      idxEndIneq = WorkingSet->nActiveConstr;
      for (idx_global = idxStartIneq; idx_global <= idxEndIneq; idx_global++) {
        WorkingSet->isActiveConstr
            .data[(WorkingSet
                       ->isActiveIdx[WorkingSet->Wid.data[idx_global - 1] - 1] +
                   WorkingSet->Wlocalidx.data[idx_global - 1]) -
                  2] = false;
      }
      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr = iH0;
      idxStartIneq = TrialState->xstar.size[0];
      iH0 = TrialState->xstar.size[0];
      for (idx_global = 0; idx_global < iH0; idx_global++) {
        tmp_data[idx_global] = TrialState->xstar.data[idx_global];
      }
      if ((lb_size[0] != 0) && (lb_size[1] != 0)) {
        if ((ub_size[0] == 0) || (ub_size[1] == 0)) {
          idx_global = (uint16_T)WorkingSet->sizes[3];
          for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
            nrmGradInf =
                WorkingSet->lb.data[WorkingSet->indexLB.data[idxEndIneq] - 1];
            if (-tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] >
                nrmGradInf) {
              tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] =
                  -nrmGradInf + muDoubleScalarAbs(nrmGradInf);
            }
          }
        } else {
          idx_global = (uint16_T)WorkingSet->sizes[3];
          for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
            nrmGradInf =
                WorkingSet->lb.data[WorkingSet->indexLB.data[idxEndIneq] - 1];
            if (-tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] >
                nrmGradInf) {
              if (muDoubleScalarIsInf(
                      ub_data[WorkingSet->indexLB.data[idxEndIneq] - 1])) {
                tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] =
                    -nrmGradInf + muDoubleScalarAbs(nrmGradInf);
              } else {
                tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] =
                    (WorkingSet->ub
                         .data[WorkingSet->indexLB.data[idxEndIneq] - 1] -
                     nrmGradInf) /
                    2.0;
              }
            }
          }
        }
      }
      if ((ub_size[0] != 0) && (ub_size[1] != 0)) {
        if ((lb_size[0] == 0) || (lb_size[1] == 0)) {
          idx_global = (uint16_T)WorkingSet->sizes[4];
          for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
            nrmGradInf =
                WorkingSet->ub.data[WorkingSet->indexUB.data[idxEndIneq] - 1];
            if (tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] >
                nrmGradInf) {
              tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] =
                  nrmGradInf - muDoubleScalarAbs(nrmGradInf);
            }
          }
        } else {
          idx_global = (uint16_T)WorkingSet->sizes[4];
          for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
            nrmGradInf =
                WorkingSet->ub.data[WorkingSet->indexUB.data[idxEndIneq] - 1];
            if (tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] >
                nrmGradInf) {
              if (muDoubleScalarIsInf(
                      lb_data[WorkingSet->indexUB.data[idxEndIneq] - 1])) {
                tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] =
                    nrmGradInf - muDoubleScalarAbs(nrmGradInf);
              } else {
                tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] =
                    (nrmGradInf -
                     WorkingSet->lb
                         .data[WorkingSet->indexUB.data[idxEndIneq] - 1]) /
                    2.0;
              }
            }
          }
        }
      }
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        TrialState->xstar.data[idx_global] = tmp_data[idx_global];
      }
      relaxed(Hessian, TrialState->grad.data, TrialState, MeritFunction,
              memspace, WorkingSet, QRManager, CholManager, QPObjective,
              qpoptions);
      idx_global = r->size[0];
      r->size[0] = TrialState->delta_x.size[0];
      emxEnsureCapacity_real_T(r, idx_global);
      r1 = r->data;
      idxStartIneq = TrialState->delta_x.size[0];
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        r1[idx_global] = TrialState->delta_x.data[idx_global];
      }
      d_TrialState.data = &TrialState->xstar.data[0];
      d_TrialState.size = &TrialState->xstar.size[0];
      d_TrialState.allocatedSize = 4241;
      d_TrialState.numDimensions = 1;
      d_TrialState.canFreeData = false;
      xcopy(nVar, &d_TrialState, r);
      r1 = r->data;
      idxStartIneq = r->size[0];
      TrialState->delta_x.size[0] = r->size[0];
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        TrialState->delta_x.data[idx_global] = r1[idx_global];
      }
      guard1 = true;
      break;
    default: {
      idxStartIneq = TrialState->grad.size[0];
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        tmp_data[idx_global] = TrialState->grad.data[idx_global];
      }
      checkBoundViolation =
          soc(Hessian, tmp_data, TrialState, memspace, WorkingSet, QRManager,
              CholManager, QPObjective, qpoptions);
      stepFlags->stepAccepted = checkBoundViolation;
      if (stepFlags->stepAccepted && (TrialState->state != -6)) {
        idx_global = (uint16_T)nVar;
        iH0 = ((uint16_T)nVar >> 2) << 2;
        idxStartIneq = iH0 - 4;
        for (idxEndIneq = 0; idxEndIneq <= idxStartIneq; idxEndIneq += 4) {
          __m256d r2;
          __m256d r3;
          r2 = _mm256_loadu_pd(&TrialState->xstar.data[idxEndIneq]);
          r3 = _mm256_loadu_pd(&TrialState->socDirection.data[idxEndIneq]);
          _mm256_storeu_pd(&TrialState->delta_x.data[idxEndIneq],
                           _mm256_add_pd(r2, r3));
        }
        for (idxEndIneq = iH0; idxEndIneq < idx_global; idxEndIneq++) {
          TrialState->delta_x.data[idxEndIneq] =
              TrialState->xstar.data[idxEndIneq] +
              TrialState->socDirection.data[idxEndIneq];
        }
      }
      guard1 = true;
    } break;
    }
    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        nrmGradInf = 0.0;
        nrmDirInf = 1.0;
        for (idxEndIneq = 0; idxEndIneq < 40; idxEndIneq++) {
          nrmGradInf = muDoubleScalarMax(
              nrmGradInf, muDoubleScalarAbs(TrialState->grad.data[idxEndIneq]));
          nrmDirInf = muDoubleScalarMax(
              nrmDirInf, muDoubleScalarAbs(TrialState->xstar.data[idxEndIneq]));
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
            memset(&Hessian[iH0 + 1], 0,
                   (uint32_T)(idx_global + 1) * sizeof(real_T));
          }
        }
      }
    }
  } while (exitg1 == 0);
  emxFree_real_T(&r);
  if (checkBoundViolation) {
    idxStartIneq = TrialState->delta_x.size[0];
    iH0 = TrialState->delta_x.size[0];
    for (idx_global = 0; idx_global < iH0; idx_global++) {
      tmp_data[idx_global] = TrialState->delta_x.data[idx_global];
    }
    if ((lb_size[0] != 0) && (lb_size[1] != 0)) {
      idx_global = (uint16_T)WorkingSet->sizes[3];
      for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
        nrmGradInf = tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1];
        nrmDirInf =
            (TrialState->xstarsqp[WorkingSet->indexLB.data[idxEndIneq] - 1] +
             nrmGradInf) -
            lb_data[WorkingSet->indexLB.data[idxEndIneq] - 1];
        if (nrmDirInf < 0.0) {
          tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] =
              nrmGradInf - nrmDirInf;
          TrialState->xstar.data[WorkingSet->indexLB.data[idxEndIneq] - 1] -=
              nrmDirInf;
        }
      }
    }
    if ((ub_size[0] != 0) && (ub_size[1] != 0)) {
      idx_global = (uint16_T)WorkingSet->sizes[4];
      for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
        nrmGradInf = tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1];
        nrmDirInf =
            (ub_data[WorkingSet->indexUB.data[idxEndIneq] - 1] -
             TrialState->xstarsqp[WorkingSet->indexUB.data[idxEndIneq] - 1]) -
            nrmGradInf;
        if (nrmDirInf < 0.0) {
          tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] =
              nrmGradInf + nrmDirInf;
          TrialState->xstar.data[WorkingSet->indexUB.data[idxEndIneq] - 1] +=
              nrmDirInf;
        }
      }
    }
    for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
      TrialState->delta_x.data[idx_global] = tmp_data[idx_global];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (step.c) */
