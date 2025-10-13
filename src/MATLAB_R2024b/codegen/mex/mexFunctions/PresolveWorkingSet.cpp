//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// PresolveWorkingSet.cpp
//
// Code generation for function 'PresolveWorkingSet'
//

// Include files
#include "PresolveWorkingSet.h"
#include "RemoveDependentEq_.h"
#include "RemoveDependentIneq_.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void PresolveWorkingSet(f_struct_T &solution, c_struct_T &memspace,
                        g_struct_T &workingset, d_struct_T &qrmanager)
{
  int32_T idxStartIneq_tmp;
  solution.state = 82;
  idxStartIneq_tmp = RemoveDependentEq_(memspace, workingset, qrmanager);
  if ((idxStartIneq_tmp != -1) && (workingset.nActiveConstr <= qrmanager.ldq)) {
    boolean_T guard1;
    boolean_T okWorkingSet;
    RemoveDependentIneq_(workingset, qrmanager, memspace);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace.workspace_float, solution.xstar.data, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      b_RemoveDependentIneq_(workingset, qrmanager, memspace);
      okWorkingSet = feasibleX0ForWorkingSet(
          memspace.workspace_float, solution.xstar.data, workingset, qrmanager);
      if (!okWorkingSet) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 &&
        (workingset.nWConstr[0] + workingset.nWConstr[1] == workingset.nVar)) {
      real_T constrViolation;
      constrViolation =
          WorkingSet::b_maxConstraintViolation(workingset, solution.xstar.data);
      if (constrViolation > 1.0E-6) {
        solution.state = -2;
      }
    }
  } else {
    int32_T idxEndIneq;
    int32_T idxStartIneq;
    solution.state = -3;
    idxStartIneq_tmp = workingset.nWConstr[0] + workingset.nWConstr[1];
    idxStartIneq = idxStartIneq_tmp + 1;
    idxEndIneq = workingset.nActiveConstr;
    for (int32_T idx_global{idxStartIneq}; idx_global <= idxEndIneq;
         idx_global++) {
      workingset.isActiveConstr.data
          [(workingset.isActiveIdx[workingset.Wid.data[idx_global - 1] - 1] +
            workingset.Wlocalidx.data[idx_global - 1]) -
           2] = false;
    }
    workingset.nWConstr[2] = 0;
    workingset.nWConstr[3] = 0;
    workingset.nWConstr[4] = 0;
    workingset.nActiveConstr = idxStartIneq_tmp;
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (PresolveWorkingSet.cpp)
