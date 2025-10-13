//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// setProblemType.cpp
//
// Code generation for function 'setProblemType'
//

// Include files
#include "setProblemType.h"
#include "mexFunctions_types.h"
#include "modifyOverheadPhaseOne_.h"
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
void setProblemType(g_struct_T &obj, int32_T PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
  case 3: {
    int32_T i;
    obj.nVar = 40;
    obj.mConstr = obj.mConstrOrig;
    if (obj.nWConstr[4] > 0) {
      int32_T idxUpperExisting;
      idxUpperExisting = obj.isActiveIdx[4] - 2;
      i = static_cast<uint16_T>(obj.sizesNormal[4]);
      for (int32_T idxStartIneq{0}; idxStartIneq < i; idxStartIneq++) {
        int32_T i1;
        i1 = (idxUpperExisting + idxStartIneq) + 1;
        obj.isActiveConstr.data[(obj.isActiveIdxNormal[4] + idxStartIneq) - 1] =
            obj.isActiveConstr.data[i1];
        obj.isActiveConstr.data[i1] = false;
      }
    }
    for (i = 0; i < 5; i++) {
      obj.sizes[i] = obj.sizesNormal[i];
    }
    for (i = 0; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxNormal[i];
    }
  } break;
  case 1:
    obj.nVar = 41;
    obj.mConstr = obj.mConstrOrig + 1;
    for (int32_T i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (int32_T i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxPhaseOne[i];
    }
    break;
  case 2: {
    int32_T i;
    obj.nVar = obj.nVarMax - 1;
    obj.mConstr = obj.mConstrMax - 1;
    for (i = 0; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegularized[i];
    }
    if (obj.probType != 4) {
      int32_T i1;
      int32_T i2;
      int32_T idxStartIneq;
      int32_T idxUpperExisting;
      i = static_cast<uint16_T>(obj.sizes[0]);
      for (int32_T idx_col{0}; idx_col < i; idx_col++) {
        idxUpperExisting = obj.ldA * idx_col;
        i1 = obj.nVar;
        for (int32_T idx_row{41}; idx_row <= i1; idx_row++) {
          obj.ATwset[(idx_row + idxUpperExisting) - 1] = 0.0;
        }
      }
      i = static_cast<uint16_T>(obj.sizes[2]);
      for (int32_T idx_col{0}; idx_col < i; idx_col++) {
        idxUpperExisting = obj.ldA * idx_col - 1;
        i1 = idx_col + 40;
        for (int32_T idx_row{41}; idx_row <= i1; idx_row++) {
          obj.Aineq[idx_row + idxUpperExisting] = 0.0;
        }
        obj.Aineq[(idx_col + idxUpperExisting) + 41] = -1.0;
        i1 = idx_col + 42;
        i2 = obj.nVar;
        for (int32_T idx_row{i1}; idx_row <= i2; idx_row++) {
          obj.Aineq[idx_row + idxUpperExisting] = 0.0;
        }
      }
      idxUpperExisting = 40;
      i = obj.sizesNormal[3] + 1;
      i1 = obj.sizesRegularized[3];
      for (idxStartIneq = i; idxStartIneq <= i1; idxStartIneq++) {
        idxUpperExisting++;
        obj.indexLB.data[idxStartIneq - 1] = idxUpperExisting;
      }
      if (obj.nWConstr[4] > 0) {
        i = static_cast<uint16_T>(obj.sizesRegularized[4]);
        for (idxStartIneq = 0; idxStartIneq < i; idxStartIneq++) {
          obj.isActiveConstr
              .data[obj.isActiveIdxRegularized[4] + idxStartIneq] =
              obj.isActiveConstr.data[(obj.isActiveIdx[4] + idxStartIneq) - 1];
        }
      }
      i = obj.isActiveIdx[4];
      i1 = obj.isActiveIdxRegularized[4];
      if (i <= i1 - 1) {
        std::memset(&obj.isActiveConstr.data[i + -1], 0,
                    static_cast<uint32_T>(i1 - i) * sizeof(boolean_T));
      }
      i = obj.sizes[2] + 40;
      if (i >= 41) {
        std::memset(&obj.lb.data[40], 0,
                    static_cast<uint32_T>(i - 40) * sizeof(real_T));
      }
      idxStartIneq = obj.isActiveIdx[2];
      i = obj.nActiveConstr;
      for (int32_T idx_col{idxStartIneq}; idx_col <= i; idx_col++) {
        idxUpperExisting = obj.ldA * (idx_col - 1) - 1;
        if (obj.Wid.data[idx_col - 1] == 3) {
          i1 = obj.Wlocalidx.data[idx_col - 1] + 39;
          for (int32_T idx_row{41}; idx_row <= i1; idx_row++) {
            obj.ATwset[idx_row + idxUpperExisting] = 0.0;
          }
          obj.ATwset[(obj.Wlocalidx.data[idx_col - 1] + idxUpperExisting) +
                     40] = -1.0;
          i1 = obj.Wlocalidx.data[idx_col - 1] + 41;
          i2 = obj.nVar;
          for (int32_T idx_row{i1}; idx_row <= i2; idx_row++) {
            obj.ATwset[idx_row + idxUpperExisting] = 0.0;
          }
        } else {
          i1 = obj.nVar;
          for (int32_T idx_row{41}; idx_row <= i1; idx_row++) {
            obj.ATwset[idx_row + idxUpperExisting] = 0.0;
          }
        }
      }
    }
    for (i = 0; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegularized[i];
    }
  } break;
  default:
    obj.nVar = obj.nVarMax;
    obj.mConstr = obj.mConstrMax;
    for (int32_T i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegPhaseOne[i];
    }
    modifyOverheadPhaseOne_(obj);
    for (int32_T i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegPhaseOne[i];
    }
    break;
  }
  obj.probType = PROBLEM_TYPE;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (setProblemType.cpp)
