//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// iterate.cpp
//
// Code generation for function 'iterate'
//

// Include files
#include "iterate.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "checkUnboundedOrIllPosed.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "strcmp.h"
#include "xaxpy.h"
#include "xnrm2.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void b_iterate(const real_T H[1600], const real_T f_data[],
               f_struct_T &solution, c_struct_T &memspace,
               g_struct_T &workingset, d_struct_T &qrmanager,
               e_struct_T &cholmanager, b_struct_T &objective,
               const char_T options_SolverName[7],
               int32_T runTimeOptions_MaxIterations)
{
  array<real_T, 1U> y;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T iAineq0;
  int32_T k;
  int32_T nVar_tmp;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective.objtype;
  nVar_tmp = workingset.nVar;
  globalActiveConstrIdx = 0;
  Objective::computeGrad_StoreHx(objective, H, f_data, solution.xstar.data);
  solution.fstar = Objective::computeFval_ReuseHx(
      objective, memspace.workspace_float, f_data, solution.xstar.data);
  if (solution.iterations < runTimeOptions_MaxIterations) {
    solution.state = -5;
  } else {
    solution.state = 0;
  }
  iAineq0 = workingset.mConstrMax;
  for (k = 0; k < iAineq0; k++) {
    solution.lambda[k] = 0.0;
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      real_T minLambda;
      int32_T iAw0;
      boolean_T guard1;
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          QRManager::squareQ_appendCol(
              qrmanager, workingset.ATwset,
              workingset.ldA * (workingset.nActiveConstr - 1) + 1);
          break;
        case -1:
          QRManager::deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;
        default:
          QRManager::factorQR(qrmanager, workingset.ATwset, nVar_tmp,
                              workingset.nActiveConstr, workingset.ldA);
          QRManager::computeQ_(qrmanager, qrmanager.mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager, objective,
                       internal::b_strcmp(options_SolverName));
        if (solution.state != -5) {
          exitg1 = 1;
        } else if ((internal::blas::xnrm2(nVar_tmp, solution.searchDir.data) <
                    1.0E-6) ||
                   (workingset.nActiveConstr >= nVar_tmp)) {
          guard1 = true;
        } else {
          minLambda = feasibleratiotest(
              solution.xstar.data, solution.searchDir.data,
              memspace.workspace_float, workingset.nVar, workingset.ldA,
              workingset.Aineq, workingset.bineq.data, workingset.lb.data,
              workingset.ub.data, workingset.indexLB.data,
              workingset.indexUB.data, workingset.sizes, workingset.isActiveIdx,
              workingset.isActiveConstr.data, workingset.nWConstr, TYPE == 5,
              updateFval, i, k);
          if (updateFval) {
            switch (i) {
            case 3:
              workingset.nWConstr[2]++;
              workingset.isActiveConstr
                  .data[(workingset.isActiveIdx[2] + k) - 2] = true;
              workingset.nActiveConstr++;
              i = workingset.nActiveConstr - 1;
              workingset.Wid.data[i] = 3;
              workingset.Wlocalidx.data[i] = k;
              iAineq0 = workingset.ldA * (k - 1);
              iAw0 = workingset.ldA * i;
              i = workingset.nVar;
              for (int32_T idx{0}; idx < i; idx++) {
                workingset.ATwset[iAw0 + idx] = workingset.Aineq[iAineq0 + idx];
              }
              workingset.bwset[workingset.nActiveConstr - 1] =
                  workingset.bineq.data[k - 1];
              break;
            case 4:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 4, k);
              break;
            default:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 5, k);
              break;
            }
            activeSetChangeID = 1;
          } else {
            stopping::checkUnboundedOrIllPosed(solution, objective);
            subProblemChanged = false;
            if (workingset.nActiveConstr == 0) {
              solution.state = 1;
            }
          }
          internal::blas::xaxpy(nVar_tmp, minLambda, solution.searchDir.data,
                                solution.xstar.data);
          Objective::computeGrad_StoreHx(objective, H, f_data,
                                         solution.xstar.data);
          updateFval = true;
          stopping::b_checkStoppingAndUpdateFval(
              activeSetChangeID, solution, memspace, objective, workingset,
              qrmanager, runTimeOptions_MaxIterations, updateFval);
        }
      } else {
        iAw0 = solution.searchDir.size[0];
        y.set_size(iAw0);
        iAineq0 = solution.searchDir.size[0];
        for (i = 0; i < iAineq0; i++) {
          y[i] = solution.searchDir.data[i];
        }
        for (k = 0; k < nVar_tmp; k++) {
          y[k] = 0.0;
        }
        for (i = 0; i < iAw0; i++) {
          solution.searchDir.data[i] = y[i];
        }
        guard1 = true;
      }
      if (guard1) {
        compute_lambda(memspace.workspace_float, solution, objective,
                       qrmanager);
        if ((solution.state != -7) || (workingset.nActiveConstr > nVar_tmp)) {
          iAineq0 = 0;
          minLambda = 0.0;
          i = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          iAw0 = workingset.nActiveConstr;
          for (int32_T idx{i}; idx <= iAw0; idx++) {
            real_T d;
            d = solution.lambda[idx - 1];
            if (d < minLambda) {
              minLambda = d;
              iAineq0 = idx;
            }
          }
          if (iAineq0 == 0) {
            solution.state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = iAineq0;
            subProblemChanged = true;
            WorkingSet::removeConstr(workingset, iAineq0);
            if (iAineq0 < workingset.nActiveConstr + 1) {
              solution.lambda[iAineq0 - 1] =
                  solution.lambda[workingset.nActiveConstr];
            }
            solution.lambda[workingset.nActiveConstr] = 0.0;
          }
        } else {
          iAineq0 = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          WorkingSet::removeConstr(workingset, workingset.nActiveConstr);
          solution.lambda[iAineq0 - 1] = 0.0;
        }
        updateFval = false;
        stopping::b_checkStoppingAndUpdateFval(
            activeSetChangeID, solution, memspace, objective, workingset,
            qrmanager, runTimeOptions_MaxIterations, updateFval);
      }
    } else {
      if (!updateFval) {
        solution.fstar = Objective::computeFval_ReuseHx(
            objective, memspace.workspace_float, f_data, solution.xstar.data);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void iterate(const real_T H[1600], const real_T f_data[], f_struct_T &solution,
             c_struct_T &memspace, g_struct_T &workingset,
             d_struct_T &qrmanager, e_struct_T &cholmanager,
             b_struct_T &objective, const char_T options_SolverName[7],
             int32_T runTimeOptions_MaxIterations)
{
  array<real_T, 1U> y;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T iAineq0;
  int32_T iAw0;
  int32_T idx_local;
  int32_T nVar_tmp;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  nVar_tmp = workingset.nVar;
  globalActiveConstrIdx = 0;
  Objective::computeGrad_StoreHx(objective, H, f_data, solution.xstar.data);
  solution.fstar = Objective::computeFval_ReuseHx(
      objective, memspace.workspace_float, f_data, solution.xstar.data);
  if (runTimeOptions_MaxIterations > 0) {
    solution.state = -5;
  } else {
    solution.state = 0;
  }
  iAineq0 = workingset.mConstrMax;
  for (iAw0 = 0; iAw0 < iAineq0; iAw0++) {
    solution.lambda[iAw0] = 0.0;
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      real_T minLambda;
      boolean_T guard1;
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          QRManager::squareQ_appendCol(
              qrmanager, workingset.ATwset,
              workingset.ldA * (workingset.nActiveConstr - 1) + 1);
          break;
        case -1:
          QRManager::deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;
        default:
          QRManager::factorQR(qrmanager, workingset.ATwset, nVar_tmp,
                              workingset.nActiveConstr, workingset.ldA);
          QRManager::computeQ_(qrmanager, qrmanager.mrows);
          break;
        }
        compute_deltax(H, solution, memspace, qrmanager, cholmanager, objective,
                       internal::b_strcmp(options_SolverName));
        if (solution.state != -5) {
          exitg1 = 1;
        } else if ((internal::blas::xnrm2(nVar_tmp, solution.searchDir.data) <
                    1.4901161193847657E-10) ||
                   (workingset.nActiveConstr >= nVar_tmp)) {
          guard1 = true;
        } else {
          minLambda = feasibleratiotest(
              solution.xstar.data, solution.searchDir.data,
              memspace.workspace_float, workingset.nVar, workingset.ldA,
              workingset.Aineq, workingset.bineq.data, workingset.lb.data,
              workingset.ub.data, workingset.indexLB.data,
              workingset.indexUB.data, workingset.sizes, workingset.isActiveIdx,
              workingset.isActiveConstr.data, workingset.nWConstr, true,
              updateFval, i, idx_local);
          if (updateFval) {
            switch (i) {
            case 3:
              workingset.nWConstr[2]++;
              workingset.isActiveConstr
                  .data[(workingset.isActiveIdx[2] + idx_local) - 2] = true;
              workingset.nActiveConstr++;
              i = workingset.nActiveConstr - 1;
              workingset.Wid.data[i] = 3;
              workingset.Wlocalidx.data[i] = idx_local;
              iAineq0 = workingset.ldA * (idx_local - 1);
              iAw0 = workingset.ldA * i;
              i = workingset.nVar;
              for (int32_T idx{0}; idx < i; idx++) {
                workingset.ATwset[iAw0 + idx] = workingset.Aineq[iAineq0 + idx];
              }
              workingset.bwset[workingset.nActiveConstr - 1] =
                  workingset.bineq.data[idx_local - 1];
              break;
            case 4:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 4, idx_local);
              break;
            default:
              WorkingSet::addBoundToActiveSetMatrix_(workingset, 5, idx_local);
              break;
            }
            activeSetChangeID = 1;
          } else {
            stopping::checkUnboundedOrIllPosed(solution, objective);
            subProblemChanged = false;
            if (workingset.nActiveConstr == 0) {
              solution.state = 1;
            }
          }
          internal::blas::xaxpy(nVar_tmp, minLambda, solution.searchDir.data,
                                solution.xstar.data);
          Objective::computeGrad_StoreHx(objective, H, f_data,
                                         solution.xstar.data);
          updateFval = true;
          stopping::checkStoppingAndUpdateFval(
              activeSetChangeID, f_data, solution, memspace, objective,
              workingset, qrmanager, runTimeOptions_MaxIterations, updateFval);
        }
      } else {
        iAineq0 = solution.searchDir.size[0];
        y.set_size(iAineq0);
        for (i = 0; i < iAineq0; i++) {
          y[i] = solution.searchDir.data[i];
        }
        for (iAw0 = 0; iAw0 < nVar_tmp; iAw0++) {
          y[iAw0] = 0.0;
        }
        for (i = 0; i < iAineq0; i++) {
          solution.searchDir.data[i] = y[i];
        }
        guard1 = true;
      }
      if (guard1) {
        compute_lambda(memspace.workspace_float, solution, objective,
                       qrmanager);
        if ((solution.state != -7) || (workingset.nActiveConstr > nVar_tmp)) {
          iAineq0 = 0;
          minLambda = 0.0;
          i = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          iAw0 = workingset.nActiveConstr;
          for (int32_T idx{i}; idx <= iAw0; idx++) {
            real_T d;
            d = solution.lambda[idx - 1];
            if (d < minLambda) {
              minLambda = d;
              iAineq0 = idx;
            }
          }
          if (iAineq0 == 0) {
            solution.state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = iAineq0;
            subProblemChanged = true;
            WorkingSet::removeConstr(workingset, iAineq0);
            if (iAineq0 < workingset.nActiveConstr + 1) {
              solution.lambda[iAineq0 - 1] =
                  solution.lambda[workingset.nActiveConstr];
            }
            solution.lambda[workingset.nActiveConstr] = 0.0;
          }
        } else {
          iAineq0 = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          WorkingSet::removeConstr(workingset, workingset.nActiveConstr);
          solution.lambda[iAineq0 - 1] = 0.0;
        }
        updateFval = false;
        stopping::checkStoppingAndUpdateFval(
            activeSetChangeID, f_data, solution, memspace, objective,
            workingset, qrmanager, runTimeOptions_MaxIterations, updateFval);
      }
    } else {
      if (!updateFval) {
        solution.fstar = Objective::computeFval_ReuseHx(
            objective, memspace.workspace_float, f_data, solution.xstar.data);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (iterate.cpp)
