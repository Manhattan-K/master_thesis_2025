//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// phaseone.cpp
//
// Code generation for function 'phaseone'
//

// Include files
#include "phaseone.h"
#include "iterate.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "coder_bounded_array.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void phaseone(const real_T H[1600], const real_T f_data[], f_struct_T &solution,
              c_struct_T &memspace, g_struct_T &workingset,
              d_struct_T &qrmanager, e_struct_T &cholmanager,
              b_struct_T &objective, const char_T options_SolverName[7],
              const i_struct_T &runTimeOptions)
{
  int32_T PROBTYPE_ORIG;
  int32_T idxEndIneq_tmp;
  int32_T idxStartIneq;
  int32_T mConstr;
  int32_T nVar_tmp;
  PROBTYPE_ORIG = workingset.probType;
  nVar_tmp = workingset.nVar;
  solution.xstar.data[workingset.nVar] = solution.maxConstr + 1.0;
  if (workingset.probType == 3) {
    mConstr = 1;
  } else {
    mConstr = 4;
  }
  WorkingSet::setProblemType(workingset, mConstr);
  mConstr = workingset.nWConstr[0] + workingset.nWConstr[1];
  idxStartIneq = mConstr + 1;
  idxEndIneq_tmp = workingset.nActiveConstr;
  for (int32_T idx_global{idxStartIneq}; idx_global <= idxEndIneq_tmp;
       idx_global++) {
    workingset.isActiveConstr
        .data[(workingset.isActiveIdx[workingset.Wid.data[idx_global - 1] - 1] +
               workingset.Wlocalidx.data[idx_global - 1]) -
              2] = false;
  }
  workingset.nWConstr[2] = 0;
  workingset.nWConstr[3] = 0;
  workingset.nWConstr[4] = 0;
  workingset.nActiveConstr = mConstr;
  objective.prev_objtype = objective.objtype;
  objective.prev_nvar = objective.nvar;
  objective.prev_hasLinear = objective.hasLinear;
  objective.objtype = 5;
  objective.nvar = nVar_tmp + 1;
  objective.gammaScalar = 1.0;
  objective.hasLinear = true;
  solution.fstar = solution.xstar.data[nVar_tmp];
  solution.state = 5;
  iterate(H, f_data, solution, memspace, workingset, qrmanager, cholmanager,
          objective, options_SolverName, runTimeOptions.MaxIterations);
  if (workingset.isActiveConstr
          .data[(workingset.isActiveIdx[3] + workingset.sizes[3]) - 2]) {
    boolean_T exitg1;
    mConstr = workingset.sizes[0];
    exitg1 = false;
    while ((!exitg1) && (mConstr + 1 <= workingset.nActiveConstr)) {
      if ((workingset.Wid.data[mConstr] == 4) &&
          (workingset.Wlocalidx.data[mConstr] == workingset.sizes[3])) {
        WorkingSet::removeConstr(workingset, mConstr + 1);
        exitg1 = true;
      } else {
        mConstr++;
      }
    }
  }
  mConstr = workingset.nActiveConstr;
  idxStartIneq = workingset.sizes[0];
  while ((mConstr > idxStartIneq) && (mConstr > nVar_tmp)) {
    WorkingSet::removeConstr(workingset, mConstr);
    mConstr--;
  }
  solution.maxConstr = solution.xstar.data[nVar_tmp];
  WorkingSet::setProblemType(workingset, PROBTYPE_ORIG);
  objective.objtype = objective.prev_objtype;
  objective.nvar = objective.prev_nvar;
  objective.hasLinear = objective.prev_hasLinear;
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (phaseone.cpp)
