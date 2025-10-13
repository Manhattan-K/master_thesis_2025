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
#include "mexFunctions_emxutil.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "normal.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "soc.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include "omp.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void step(emlrtCTX aTLS, mexFunctionsStackData *SD, struct_T *stepFlags,
          real_T Hessian[1600], const real_T lb[40], const real_T ub[40],
          h_struct_T *TrialState, j_struct_T *MeritFunction,
          f_struct_T *memspace, i_struct_T *WorkingSet, g_struct_T *QRManager,
          m_struct_T *CholManager, e_struct_T *QPObjective,
          n_struct_T *qpoptions)
{
  jmp_buf *volatile emlrtJBStack;
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
  int32_T k;
  int32_T nVar;
  int32_T step_numThreads;
  boolean_T checkBoundViolation;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  stepFlags->stepAccepted = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar;
  emxInit_real_T(&r, 1);
  if (stepFlags->stepType != 3) {
    idx_global = (uint16_T)WorkingSet->nVar;
    if (idx_global < 1200) {
      for (k = 0; k < idx_global; k++) {
        TrialState->xstar.data[k] = TrialState->xstarsqp[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      step_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(step_numThreads)

      for (k = 0; k < idx_global; k++) {
        TrialState->xstar.data[k] = TrialState->xstarsqp[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  } else {
    idx_global = r->size[0];
    r->size[0] = TrialState->searchDir.size[0];
    emxEnsureCapacity_real_T(r, idx_global);
    r1 = r->data;
    idxStartIneq = TrialState->searchDir.size[0];
    if (idxStartIneq < 1200) {
      for (k = 0; k < idxStartIneq; k++) {
        r1[k] = TrialState->searchDir.data[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      step_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(step_numThreads)

      for (k = 0; k < idxStartIneq; k++) {
        r1[k] = TrialState->searchDir.data[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
    iH0 = r->size[0];
    if (r->size[0] < 1200) {
      for (k = 0; k < idxStartIneq; k++) {
        TrialState->searchDir.data[k] = r1[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      step_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(step_numThreads)

      for (k = 0; k < iH0; k++) {
        TrialState->searchDir.data[k] = r1[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  int32_T exitg1;
  boolean_T guard1;
  do {
    exitg1 = 0;
    guard1 = false;
    switch (stepFlags->stepType) {
    case 1:
      normal(aTLS, SD, Hessian, TrialState->grad.data, TrialState,
             MeritFunction, memspace, WorkingSet, QRManager, CholManager,
             QPObjective, qpoptions, stepFlags);
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
      idx_global = (uint16_T)WorkingSet->sizes[3];
      for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
        nrmGradInf =
            WorkingSet->lb.data[WorkingSet->indexLB.data[idxEndIneq] - 1];
        if (-tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] > nrmGradInf) {
          if (muDoubleScalarIsInf(
                  ub[WorkingSet->indexLB.data[idxEndIneq] - 1])) {
            tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] =
                -nrmGradInf + muDoubleScalarAbs(nrmGradInf);
          } else {
            tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] =
                (WorkingSet->ub.data[WorkingSet->indexLB.data[idxEndIneq] - 1] -
                 nrmGradInf) /
                2.0;
          }
        }
      }
      idx_global = (uint16_T)WorkingSet->sizes[4];
      for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
        nrmGradInf =
            WorkingSet->ub.data[WorkingSet->indexUB.data[idxEndIneq] - 1];
        if (tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] > nrmGradInf) {
          if (muDoubleScalarIsInf(
                  lb[WorkingSet->indexUB.data[idxEndIneq] - 1])) {
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
      for (idx_global = 0; idx_global < idxStartIneq; idx_global++) {
        TrialState->xstar.data[idx_global] = tmp_data[idx_global];
      }
      relaxed(aTLS, Hessian, TrialState->grad.data, TrialState, MeritFunction,
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
          soc(aTLS, Hessian, tmp_data, TrialState, memspace, WorkingSet,
              QRManager, CholManager, QPObjective, qpoptions);
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
    if (iH0 < 1200) {
      for (k = 0; k < iH0; k++) {
        tmp_data[k] = TrialState->delta_x.data[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      step_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(step_numThreads)

      for (k = 0; k < iH0; k++) {
        tmp_data[k] = TrialState->delta_x.data[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    idx_global = (uint16_T)WorkingSet->sizes[3];
    for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
      nrmGradInf = tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1];
      nrmDirInf =
          (TrialState->xstarsqp[WorkingSet->indexLB.data[idxEndIneq] - 1] +
           nrmGradInf) -
          lb[WorkingSet->indexLB.data[idxEndIneq] - 1];
      if (nrmDirInf < 0.0) {
        tmp_data[WorkingSet->indexLB.data[idxEndIneq] - 1] =
            nrmGradInf - nrmDirInf;
        TrialState->xstar.data[WorkingSet->indexLB.data[idxEndIneq] - 1] -=
            nrmDirInf;
      }
    }
    idx_global = (uint16_T)WorkingSet->sizes[4];
    for (idxEndIneq = 0; idxEndIneq < idx_global; idxEndIneq++) {
      nrmGradInf = tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1];
      nrmDirInf =
          (ub[WorkingSet->indexUB.data[idxEndIneq] - 1] -
           TrialState->xstarsqp[WorkingSet->indexUB.data[idxEndIneq] - 1]) -
          nrmGradInf;
      if (nrmDirInf < 0.0) {
        tmp_data[WorkingSet->indexUB.data[idxEndIneq] - 1] =
            nrmGradInf + nrmDirInf;
        TrialState->xstar.data[WorkingSet->indexUB.data[idxEndIneq] - 1] +=
            nrmDirInf;
      }
    }
    TrialState->delta_x.size[0] = idxStartIneq;
    if (idxStartIneq < 1200) {
      for (k = 0; k < idxStartIneq; k++) {
        TrialState->delta_x.data[k] = tmp_data[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      step_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(step_numThreads)

      for (k = 0; k < idxStartIneq; k++) {
        TrialState->delta_x.data[k] = tmp_data[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (step.c) */
