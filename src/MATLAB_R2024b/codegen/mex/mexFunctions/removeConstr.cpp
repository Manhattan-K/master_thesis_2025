//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// removeConstr.cpp
//
// Code generation for function 'removeConstr'
//

// Include files
#include "removeConstr.h"
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
void removeConstr(g_struct_T &obj, int32_T idx_global)
{
  int32_T TYPE_tmp;
  TYPE_tmp = obj.Wid.data[idx_global - 1] - 1;
  obj.isActiveConstr
      .data[(obj.isActiveIdx[TYPE_tmp] + obj.Wlocalidx.data[idx_global - 1]) -
            2] = false;
  if (idx_global < obj.nActiveConstr) {
    int32_T i;
    i = obj.nActiveConstr - 1;
    obj.Wid.data[idx_global - 1] = obj.Wid.data[i];
    obj.Wlocalidx.data[idx_global - 1] = obj.Wlocalidx.data[i];
    i = static_cast<uint16_T>(obj.nVar);
    for (int32_T idx{0}; idx < i; idx++) {
      obj.ATwset[idx + obj.ldA * (idx_global - 1)] =
          obj.ATwset[idx + obj.ldA * (obj.nActiveConstr - 1)];
    }
    obj.bwset[idx_global - 1] = obj.bwset[obj.nActiveConstr - 1];
  }
  obj.nActiveConstr--;
  obj.nWConstr[TYPE_tmp]--;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (removeConstr.cpp)
