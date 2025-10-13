//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// addBoundToActiveSetMatrix_.cpp
//
// Code generation for function 'addBoundToActiveSetMatrix_'
//

// Include files
#include "addBoundToActiveSetMatrix_.h"
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
namespace WorkingSet {
void addBoundToActiveSetMatrix_(g_struct_T &obj, int32_T TYPE,
                                int32_T idx_local)
{
  int32_T colOffset;
  int32_T i;
  int32_T idx_bnd_local;
  obj.nWConstr[TYPE - 1]++;
  obj.isActiveConstr.data[(obj.isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj.nActiveConstr++;
  i = obj.nActiveConstr - 1;
  obj.Wid.data[i] = TYPE;
  obj.Wlocalidx.data[i] = idx_local;
  colOffset = obj.ldA * i - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj.indexUB.data[idx_local - 1];
    obj.bwset[obj.nActiveConstr - 1] = obj.ub.data[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj.indexLB.data[idx_local - 1];
    obj.bwset[obj.nActiveConstr - 1] = obj.lb.data[idx_bnd_local - 1];
  }
  i = static_cast<uint16_T>(idx_bnd_local - 1);
  for (int32_T idx{0}; idx < i; idx++) {
    obj.ATwset[(idx + colOffset) + 1] = 0.0;
  }
  obj.ATwset[idx_bnd_local + colOffset] =
      2.0 * static_cast<real_T>(TYPE == 5) - 1.0;
  i = idx_bnd_local + 1;
  idx_bnd_local = obj.nVar;
  for (int32_T idx{i}; idx <= idx_bnd_local; idx++) {
    obj.ATwset[idx + colOffset] = 0.0;
  }
  switch (obj.probType) {
  case 3:
  case 2:
    break;
  default:
    obj.ATwset[obj.nVar + colOffset] = -1.0;
    break;
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (addBoundToActiveSetMatrix_.cpp)
