//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linesearch.h
//
// Code generation for function 'linesearch'
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

// Type Declarations
struct f_struct_T;

namespace coder {
namespace internal {
class bb_stickyStruct;

class i_stickyStruct;

class r_stickyStruct;

} // namespace internal
} // namespace coder

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
real_T b_linesearch(boolean_T &evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const array<real_T, 1U> &WorkingSet_Aineq,
                    f_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    const ::coder::internal::i_stickyStruct &FcnEvaluator,
                    boolean_T socTaken, int32_T &exitflag);

real_T c_linesearch(boolean_T &evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const array<real_T, 1U> &WorkingSet_Aineq,
                    f_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    const ::coder::internal::r_stickyStruct &FcnEvaluator,
                    boolean_T socTaken, int32_T &exitflag);

real_T linesearch(boolean_T &evalWellDefined, int32_T WorkingSet_nVar,
                  int32_T WorkingSet_ldA,
                  const array<real_T, 1U> &WorkingSet_Aineq,
                  f_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                  real_T MeritFunction_phiFullStep,
                  const ::coder::internal::bb_stickyStruct &FcnEvaluator,
                  boolean_T socTaken, int32_T &exitflag);

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (linesearch.h)
