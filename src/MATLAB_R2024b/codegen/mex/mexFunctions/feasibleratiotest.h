//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// feasibleratiotest.h
//
// Code generation for function 'feasibleratiotest'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
real_T feasibleratiotest(
    const real_T solution_xstar_data[], const real_T solution_searchDir_data[],
    array<real_T, 2U> &workspace, int32_T workingset_nVar,
    int32_T workingset_ldA, const array<real_T, 1U> &workingset_Aineq,
    const real_T workingset_bineq_data[], const real_T workingset_lb_data[],
    const real_T workingset_ub_data[], const int32_T workingset_indexLB_data[],
    const int32_T workingset_indexUB_data[], const int32_T workingset_sizes[5],
    const int32_T workingset_isActiveIdx[6],
    const boolean_T workingset_isActiveConstr_data[],
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T &newBlocking, int32_T &constrType, int32_T &constrIdx);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (feasibleratiotest.h)
