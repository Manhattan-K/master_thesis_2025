//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct2.cpp
//
// Code generation for function 'factoryConstruct2'
//

// Include files
#include "factoryConstruct2.h"
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
void factoryConstruct(int32_T mIneqMax, int32_T nVarMax, int32_T mConstrMax,
                      g_struct_T &obj)
{
  obj.mConstr = 0;
  obj.mConstrOrig = 0;
  obj.mConstrMax = mConstrMax;
  obj.nVar = 40;
  obj.nVarOrig = 40;
  obj.nVarMax = nVarMax;
  obj.ldA = nVarMax;
  obj.Aineq.set_size(mIneqMax * nVarMax);
  obj.bineq.size[0] = mIneqMax;
  obj.Aeq.size[0] = 0;
  obj.lb.size[0] = nVarMax;
  obj.ub.size[0] = nVarMax;
  obj.indexLB.size[0] = nVarMax;
  obj.indexUB.size[0] = nVarMax;
  obj.indexFixed.size[0] = nVarMax;
  obj.mEqRemoved = 0;
  obj.ATwset.set_size(nVarMax * mConstrMax);
  obj.bwset.set_size(mConstrMax);
  obj.nActiveConstr = 0;
  obj.maxConstrWorkspace.set_size(mConstrMax);
  for (int32_T i{0}; i < 5; i++) {
    obj.sizes[i] = 0;
    obj.sizesNormal[i] = 0;
    obj.sizesPhaseOne[i] = 0;
    obj.sizesRegularized[i] = 0;
    obj.sizesRegPhaseOne[i] = 0;
  }
  for (int32_T i{0}; i < 6; i++) {
    obj.isActiveIdx[i] = 0;
    obj.isActiveIdxNormal[i] = 0;
    obj.isActiveIdxPhaseOne[i] = 0;
    obj.isActiveIdxRegularized[i] = 0;
    obj.isActiveIdxRegPhaseOne[i] = 0;
  }
  obj.isActiveConstr.size[0] = mConstrMax;
  obj.Wid.size[0] = mConstrMax;
  obj.Wlocalidx.size[0] = mConstrMax;
  for (int32_T i{0}; i < 5; i++) {
    obj.nWConstr[i] = 0;
  }
  obj.probType = 3;
  obj.SLACK0 = 1.0E-5;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct2.cpp)
