//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mexFunctions_initialize.cpp
//
// Code generation for function 'mexFunctions_initialize'
//

// Include files
#include "mexFunctions_initialize.h"
#include "_coder_mexFunctions_mex.h"
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Declarations
static void mexFunctions_once();

// Function Definitions
static void mexFunctions_once()
{
  mex_InitInfAndNan();
}

void mexFunctions_initialize()
{
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2022a(emlrtRootTLSGlobal,
                          "EMLRT:runTime:MexFunctionNeedsLicense",
                          "optimization_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    mexFunctions_once();
  }
}

// End of code generation (mexFunctions_initialize.cpp)
