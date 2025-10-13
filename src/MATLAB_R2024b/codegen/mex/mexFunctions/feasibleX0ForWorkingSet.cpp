//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// feasibleX0ForWorkingSet.cpp
//
// Code generation for function 'feasibleX0ForWorkingSet'
//

// Include files
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xcopy.h"
#include "xdot.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xgeqp3.h"
#include "xtrsm.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
boolean_T feasibleX0ForWorkingSet(array<real_T, 2U> &workspace,
                                  real_T xCurrent_data[],
                                  g_struct_T &workingset, d_struct_T &qrmanager)
{
  array<real_T, 2U> b_workspace;
  int32_T mWConstr;
  int32_T nVar;
  boolean_T nonDegenerateWset;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mWConstr = workingset.nActiveConstr;
  nVar = workingset.nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    real_T tol;
    int32_T minmn;
    if (mWConstr >= nVar) {
      int32_T i;
      int32_T i1;
      int32_T loop_ub;
      int32_T rankQR;
      i = static_cast<uint16_T>(nVar);
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        minmn = qrmanager.ldq * loop_ub;
        for (rankQR = 0; rankQR < mWConstr; rankQR++) {
          qrmanager.QR[rankQR + minmn] =
              workingset.ATwset[loop_ub + workingset.ldA * rankQR];
        }
      }
      std::memset(&qrmanager.jpvt.data[0], 0,
                  static_cast<uint32_T>(i) * sizeof(int32_T));
      if (mWConstr * nVar == 0) {
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        qrmanager.minRowCol = 0;
      } else {
        qrmanager.usedPivoting = true;
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        qrmanager.minRowCol = muIntScalarMin_sint32(mWConstr, nVar);
        internal::lapack::xgeqp3(qrmanager.QR, mWConstr, nVar,
                                 qrmanager.jpvt.data, qrmanager.jpvt.size[0],
                                 qrmanager.tau);
      }
      QRManager::computeQ_(qrmanager, qrmanager.mrows);
      rankQR = 0;
      minmn = muIntScalarMin_sint32(qrmanager.mrows, qrmanager.ncols);
      if (minmn > 0) {
        tol = muDoubleScalarMin(1.4901161193847656E-8,
                                2.2204460492503131E-15 *
                                    static_cast<real_T>(muIntScalarMax_sint32(
                                        qrmanager.mrows, qrmanager.ncols))) *
              muDoubleScalarAbs(qrmanager.QR[0]);
        while ((rankQR < minmn) &&
               (!(muDoubleScalarAbs(
                      qrmanager.QR[rankQR + qrmanager.QR.size(0) * rankQR]) <=
                  tol))) {
          rankQR++;
        }
      }
      for (minmn = 0; minmn < mWConstr; minmn++) {
        tol = workingset.bwset[minmn];
        workspace[minmn] = tol;
        workspace[minmn + workspace.size(0)] = tol;
      }
      internal::blas::xgemv(nVar, mWConstr, workingset.ATwset, workingset.ldA,
                            xCurrent_data, workspace);
      b_workspace.set_size(workspace.size(0), workspace.size(1));
      loop_ub = workspace.size(0) * workspace.size(1) - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        b_workspace[i1] = workspace[i1];
      }
      internal::blas::xgemm(nVar, mWConstr, qrmanager.Q, qrmanager.ldq,
                            b_workspace, workspace.size(0), workspace,
                            workspace.size(0));
      internal::blas::xtrsm(rankQR, qrmanager.QR, qrmanager.ldq, workspace,
                            workspace.size(0));
      i1 = rankQR + 1;
      for (minmn = i1; minmn <= nVar; minmn++) {
        workspace[minmn - 1] = 0.0;
        workspace[(minmn + workspace.size(0)) - 1] = 0.0;
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace[(qrmanager.jpvt.data[minmn] + workspace.size(0) * 2) - 1] =
            workspace[minmn];
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace[minmn] = workspace[minmn + workspace.size(0) * 2];
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace[(qrmanager.jpvt.data[minmn] + workspace.size(0) * 2) - 1] =
            workspace[minmn + workspace.size(0)];
      }
      for (minmn = 0; minmn < i; minmn++) {
        workspace[minmn + workspace.size(0)] =
            workspace[minmn + workspace.size(0) * 2];
      }
    } else {
      int32_T i;
      int32_T loop_ub;
      int32_T rankQR;
      if (mWConstr - 1 >= 0) {
        std::memset(&qrmanager.jpvt.data[0], 0,
                    static_cast<uint32_T>(mWConstr) * sizeof(int32_T));
      }
      QRManager::factorQRE(qrmanager, workingset.ATwset, nVar, mWConstr,
                           workingset.ldA);
      QRManager::computeQ_(qrmanager, qrmanager.minRowCol);
      rankQR = 0;
      minmn = muIntScalarMin_sint32(qrmanager.mrows, qrmanager.ncols);
      if (minmn > 0) {
        tol = muDoubleScalarMin(1.4901161193847656E-8,
                                2.2204460492503131E-15 *
                                    static_cast<real_T>(muIntScalarMax_sint32(
                                        qrmanager.mrows, qrmanager.ncols))) *
              muDoubleScalarAbs(qrmanager.QR[0]);
        while ((rankQR < minmn) &&
               (!(muDoubleScalarAbs(
                      qrmanager.QR[rankQR + qrmanager.QR.size(0) * rankQR]) <=
                  tol))) {
          rankQR++;
        }
      }
      for (minmn = 0; minmn < mWConstr; minmn++) {
        i = qrmanager.jpvt.data[minmn];
        workspace[minmn] =
            workingset.bwset[i - 1] -
            internal::blas::xdot(nVar, workingset.ATwset,
                                 (i - 1) * workingset.ldA + 1, xCurrent_data);
        workspace[minmn + workspace.size(0)] = workingset.bwset[i - 1];
      }
      minmn = workspace.size(0);
      internal::blas::b_xtrsm(rankQR, qrmanager.QR, qrmanager.ldq, workspace,
                              workspace.size(0));
      b_workspace.set_size(workspace.size(0), workspace.size(1));
      loop_ub = workspace.size(0) * workspace.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_workspace[i] = workspace[i];
      }
      internal::blas::b_xgemm(nVar, rankQR, qrmanager.Q, qrmanager.ldq,
                              b_workspace, minmn, workspace, minmn);
    }
    minmn = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (minmn <= static_cast<uint16_T>(nVar) - 1) {
        tol = workspace[minmn];
        if (muDoubleScalarIsInf(tol) || muDoubleScalarIsNaN(tol)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          tol = workspace[minmn + workspace.size(0)];
          if (muDoubleScalarIsInf(tol) || muDoubleScalarIsNaN(tol)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            minmn++;
          }
        }
      } else {
        real_T constrViolation_basicX;
        internal::blas::xaxpy(nVar, xCurrent_data, workspace);
        tol = WorkingSet::b_maxConstraintViolation(workingset, workspace);
        constrViolation_basicX = WorkingSet::b_maxConstraintViolation(
            workingset, workspace, workspace.size(0) + 1);
        if ((tol <= 2.2204460492503131E-16) || (tol < constrViolation_basicX)) {
          internal::blas::xcopy(nVar, workspace, xCurrent_data);
        } else {
          internal::blas::xcopy(nVar, workspace, workspace.size(0) + 1,
                                xCurrent_data);
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return nonDegenerateWset;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (feasibleX0ForWorkingSet.cpp)
