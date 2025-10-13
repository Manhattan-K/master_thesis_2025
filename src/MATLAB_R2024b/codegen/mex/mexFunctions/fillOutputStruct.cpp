//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fillOutputStruct.cpp
//
// Code generation for function 'fillOutputStruct'
//

// Include files
#include "fillOutputStruct.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace parseoutput {
real_T fillOutputStruct(
    int32_T TrialState_FunctionEvaluations, int32_T TrialState_sqpIterations,
    real_T TrialState_steplength, const real_T TrialState_delta_x_data[],
    real_T c_MeritFunction_nlpPrimalFeasEr, real_T MeritFunction_firstOrderOpt,
    real_T &output_funcCount, char_T output_algorithm[3],
    real_T &output_constrviolation, real_T &output_stepsize,
    real_T &output_lssteplength, real_T &output_firstorderopt)
{
  real_T output_iterations;
  real_T scale;
  real_T y;
  output_algorithm[0] = 's';
  output_algorithm[1] = 'q';
  output_algorithm[2] = 'p';
  output_iterations = TrialState_sqpIterations;
  output_funcCount = TrialState_FunctionEvaluations;
  output_constrviolation = c_MeritFunction_nlpPrimalFeasEr;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T k{0}; k < 40; k++) {
    real_T absxk;
    absxk = muDoubleScalarAbs(TrialState_delta_x_data[k]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }
  output_stepsize = scale * muDoubleScalarSqrt(y);
  output_lssteplength = TrialState_steplength;
  output_firstorderopt = MeritFunction_firstOrderOpt;
  return output_iterations;
}

} // namespace parseoutput
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (fillOutputStruct.cpp)
