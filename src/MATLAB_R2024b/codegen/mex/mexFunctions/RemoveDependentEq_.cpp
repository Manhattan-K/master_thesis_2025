//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// RemoveDependentEq_.cpp
//
// Code generation for function 'RemoveDependentEq_'
//

// Include files
#include "RemoveDependentEq_.h"
#include "computeQ_.h"
#include "countsort.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
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
namespace qpactiveset {
namespace initialize {
int32_T RemoveDependentEq_(c_struct_T &memspace, g_struct_T &workingset,
                           d_struct_T &qrmanager)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T mTotalWorkingEq_tmp;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  int32_T nVar;
  nVar = workingset.nVar;
  mWorkingFixed = workingset.nWConstr[0];
  mTotalWorkingEq_tmp = workingset.nWConstr[0] + workingset.nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    real_T tol;
    int32_T i;
    int32_T idxDiag;
    int32_T idx_col;
    i = static_cast<uint16_T>(nVar);
    for (idxDiag = 0; idxDiag < mTotalWorkingEq_tmp; idxDiag++) {
      for (idx_col = 0; idx_col < i; idx_col++) {
        qrmanager.QR[idxDiag + qrmanager.ldq * idx_col] =
            workingset.ATwset[idx_col + workingset.ldA * idxDiag];
      }
    }
    idxDiag = mTotalWorkingEq_tmp - workingset.nVar;
    nDepInd = muIntScalarMax_sint32(0, idxDiag);
    i = static_cast<uint16_T>(workingset.nVar);
    std::memset(&qrmanager.jpvt.data[0], 0,
                static_cast<uint32_T>(i) * sizeof(int32_T));
    if (mTotalWorkingEq_tmp * workingset.nVar == 0) {
      qrmanager.mrows = mTotalWorkingEq_tmp;
      qrmanager.ncols = workingset.nVar;
      qrmanager.minRowCol = 0;
    } else {
      qrmanager.usedPivoting = true;
      qrmanager.mrows = mTotalWorkingEq_tmp;
      qrmanager.ncols = workingset.nVar;
      qrmanager.minRowCol =
          muIntScalarMin_sint32(mTotalWorkingEq_tmp, workingset.nVar);
      internal::lapack::xgeqp3(qrmanager.QR, mTotalWorkingEq_tmp,
                               workingset.nVar, qrmanager.jpvt.data,
                               qrmanager.jpvt.size[0], qrmanager.tau);
    }
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 *
                                static_cast<real_T>(muIntScalarMax_sint32(
                                    mTotalWorkingEq_tmp, workingset.nVar)));
    idxDiag = muIntScalarMin_sint32(workingset.nVar, mTotalWorkingEq_tmp);
    idxDiag += qrmanager.ldq * (idxDiag - 1);
    while ((idxDiag > 0) && (muDoubleScalarAbs(qrmanager.QR[idxDiag - 1]) <
                             tol * muDoubleScalarAbs(qrmanager.QR[0]))) {
      idxDiag = (idxDiag - qrmanager.ldq) - 1;
      nDepInd++;
    }
    if (nDepInd > 0) {
      boolean_T exitg1;
      QRManager::computeQ_(qrmanager, qrmanager.mrows);
      idx_col = 0;
      exitg1 = false;
      while ((!exitg1) && (idx_col <= nDepInd - 1)) {
        real_T x;
        n_t = (ptrdiff_t)mTotalWorkingEq_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        x = ddot(
            &n_t,
            &qrmanager.Q[qrmanager.ldq * ((mTotalWorkingEq_tmp - idx_col) - 1)],
            &incx_t, &(workingset.bwset.data())[0], &incy_t);
        if (muDoubleScalarAbs(x) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          idx_col++;
        }
      }
    }
    if (nDepInd > 0) {
      n_t = (ptrdiff_t)nVar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      for (idx_col = 0; idx_col < mTotalWorkingEq_tmp; idx_col++) {
        dcopy(&n_t, &workingset.ATwset[workingset.ldA * idx_col], &incx_t,
              &qrmanager.QR[qrmanager.ldq * idx_col], &incy_t);
      }
      for (idx_col = 0; idx_col < mWorkingFixed; idx_col++) {
        qrmanager.jpvt.data[idx_col] = 1;
      }
      i = workingset.nWConstr[0] + 1;
      if (i <= mTotalWorkingEq_tmp) {
        std::memset(&qrmanager.jpvt.data[i + -1], 0,
                    static_cast<uint32_T>((mTotalWorkingEq_tmp - i) + 1) *
                        sizeof(int32_T));
      }
      if (workingset.nVar * mTotalWorkingEq_tmp == 0) {
        qrmanager.mrows = workingset.nVar;
        qrmanager.ncols = mTotalWorkingEq_tmp;
        qrmanager.minRowCol = 0;
      } else {
        qrmanager.usedPivoting = true;
        qrmanager.mrows = workingset.nVar;
        qrmanager.ncols = mTotalWorkingEq_tmp;
        qrmanager.minRowCol =
            muIntScalarMin_sint32(workingset.nVar, mTotalWorkingEq_tmp);
        internal::lapack::xgeqp3(qrmanager.QR, workingset.nVar,
                                 mTotalWorkingEq_tmp, qrmanager.jpvt.data,
                                 qrmanager.jpvt.size[0], qrmanager.tau);
      }
      for (idx_col = 0; idx_col < nDepInd; idx_col++) {
        memspace.workspace_int.data[idx_col] =
            qrmanager.jpvt.data[(mTotalWorkingEq_tmp - nDepInd) + idx_col];
      }
      utils::countsort(memspace.workspace_int.data, nDepInd,
                       memspace.workspace_sort.data, 1, mTotalWorkingEq_tmp);
      for (idx_col = nDepInd; idx_col >= 1; idx_col--) {
        i = workingset.nWConstr[0] + workingset.nWConstr[1];
        if (i != 0) {
          idxDiag = memspace.workspace_int.data[idx_col - 1];
          if (idxDiag <= i) {
            if ((workingset.nActiveConstr == i) || (idxDiag == i)) {
              workingset.mEqRemoved++;
              // A check that is always false is detected at compile-time.
              // Eliminating code that follows.
            } else {
              workingset.mEqRemoved++;
              // A check that is always false is detected at compile-time.
              // Eliminating code that follows.
            }
          }
        }
      }
    }
  }
  return nDepInd;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (RemoveDependentEq_.cpp)
