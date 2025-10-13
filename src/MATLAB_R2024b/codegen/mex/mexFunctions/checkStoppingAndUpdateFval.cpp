//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkStoppingAndUpdateFval.cpp
//
// Code generation for function 'checkStoppingAndUpdateFval'
//

// Include files
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
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
namespace qpactiveset {
namespace stopping {
void b_checkStoppingAndUpdateFval(int32_T &activeSetChangeID,
                                  f_struct_T &solution, c_struct_T &memspace,
                                  const b_struct_T &objective,
                                  g_struct_T &workingset, d_struct_T &qrmanager,
                                  int32_T runTimeOptions_MaxIterations,
                                  boolean_T &updateFval)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> b_solution;
  array<real_T, 1U> r;
  int32_T nVar_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  solution.iterations++;
  nVar_tmp = objective.nvar;
  if ((solution.iterations >= runTimeOptions_MaxIterations) &&
      ((solution.state != 1) || (objective.objtype == 5))) {
    solution.state = 0;
  }
  if (solution.iterations - solution.iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    tempMaxConstr =
        WorkingSet::b_maxConstraintViolation(workingset, solution.xstar.data);
    solution.maxConstr = tempMaxConstr;
    if (objective.objtype == 5) {
      tempMaxConstr =
          solution.maxConstr - solution.xstar.data[objective.nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      int32_T loop_ub;
      boolean_T nonDegenerateWset;
      loop_ub = solution.searchDir.size[0];
      r.set_size(loop_ub);
      for (int32_T i{0}; i < loop_ub; i++) {
        r[i] = solution.searchDir.data[i];
      }
      b_solution.set(&solution.xstar.data[0], solution.xstar.size[0]);
      if (nVar_tmp >= 1) {
        n_t = (ptrdiff_t)nVar_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_solution.data())[0], &incx_t, &(r.data())[0], &incy_t);
      }
      loop_ub = r.size(0);
      solution.searchDir.size[0] = r.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        solution.searchDir.data[i] = r[i];
      }
      nonDegenerateWset = initialize::feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.searchDir.data, workingset,
          qrmanager);
      if ((!nonDegenerateWset) && (solution.state != 0)) {
        solution.state = -2;
      }
      activeSetChangeID = 0;
      tempMaxConstr = WorkingSet::b_maxConstraintViolation(
          workingset, solution.searchDir.data);
      if (tempMaxConstr < solution.maxConstr) {
        for (loop_ub = 0; loop_ub < nVar_tmp; loop_ub++) {
          solution.xstar.data[loop_ub] = solution.searchDir.data[loop_ub];
        }
        solution.maxConstr = tempMaxConstr;
      }
    }
  }
  if (updateFval) {
    updateFval = false;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void checkStoppingAndUpdateFval(int32_T &activeSetChangeID,
                                const real_T f_data[], f_struct_T &solution,
                                c_struct_T &memspace,
                                const b_struct_T &objective,
                                g_struct_T &workingset, d_struct_T &qrmanager,
                                int32_T runTimeOptions_MaxIterations,
                                const boolean_T &updateFval)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> b_solution;
  array<real_T, 1U> r;
  int32_T nVar_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  solution.iterations++;
  nVar_tmp = objective.nvar;
  if ((solution.iterations >= runTimeOptions_MaxIterations) &&
      ((solution.state != 1) || (objective.objtype == 5))) {
    solution.state = 0;
  }
  if (solution.iterations - solution.iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    solution.maxConstr =
        WorkingSet::b_maxConstraintViolation(workingset, solution.xstar.data);
    tempMaxConstr = solution.maxConstr;
    if (objective.objtype == 5) {
      tempMaxConstr =
          solution.maxConstr - solution.xstar.data[objective.nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      int32_T loop_ub;
      boolean_T nonDegenerateWset;
      r.set_size(solution.searchDir.size[0]);
      loop_ub = solution.searchDir.size[0];
      for (int32_T i{0}; i < loop_ub; i++) {
        r[i] = solution.searchDir.data[i];
      }
      b_solution.set(&solution.xstar.data[0], solution.xstar.size[0]);
      if (nVar_tmp >= 1) {
        n_t = (ptrdiff_t)nVar_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_solution.data())[0], &incx_t, &(r.data())[0], &incy_t);
      }
      loop_ub = r.size(0);
      solution.searchDir.size[0] = r.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        solution.searchDir.data[i] = r[i];
      }
      nonDegenerateWset = initialize::feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.searchDir.data, workingset,
          qrmanager);
      if ((!nonDegenerateWset) && (solution.state != 0)) {
        solution.state = -2;
      }
      activeSetChangeID = 0;
      tempMaxConstr = WorkingSet::b_maxConstraintViolation(
          workingset, solution.searchDir.data);
      if (tempMaxConstr < solution.maxConstr) {
        for (loop_ub = 0; loop_ub < nVar_tmp; loop_ub++) {
          solution.xstar.data[loop_ub] = solution.searchDir.data[loop_ub];
        }
        solution.maxConstr = tempMaxConstr;
      }
    }
  }
  if (updateFval) {
    solution.fstar = Objective::computeFval_ReuseHx(
        objective, memspace.workspace_float, f_data, solution.xstar.data);
    if ((solution.fstar < 1.0E-6) &&
        ((solution.state != 0) || (objective.objtype != 5))) {
      solution.state = 2;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace stopping
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkStoppingAndUpdateFval.cpp)
