//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_mexFunctions_mex.cpp
//
// Code generation for function '_coder_mexFunctions_mex'
//

// Include files
#include "_coder_mexFunctions_mex.h"
#include "_coder_mexFunctions_api.h"
#include "mexFunctions_data.h"
#include "mexFunctions_initialize.h"
#include "mexFunctions_terminate.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include <cstdlib>
#include <cstring>
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexFunctionsStackData *mexFunctionsStackDataGlobal{nullptr};
  const char_T *entryPointTemplateNames[5]{
      "evaluateObstacles", "followerMPCandUpdate", "leaderMPCandUpdate",
      "leaderMPCandUpdateHalt", "Rmat"};
  mexFunctionsStackDataGlobal =
      static_cast<mexFunctionsStackData *>(new mexFunctionsStackData);
  mexAtExit(&mexFunctions_atexit);
  mexFunctions_initialize();
  try {
    switch (emlrtGetEntryPointIndexR2016a(
        emlrtRootTLSGlobal, nrhs, &prhs[0],
        (const char_T **)&entryPointTemplateNames[0], 5)) {
    case 0:
      unsafe_evaluateObstacles_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    case 1:
      unsafe_followerMPCandUpdate_mexFunction(mexFunctionsStackDataGlobal, nlhs,
                                              plhs, nrhs - 1, &prhs[1]);
      break;
    case 2:
      unsafe_leaderMPCandUpdate_mexFunction(mexFunctionsStackDataGlobal, nlhs,
                                            plhs, nrhs - 1, &prhs[1]);
      break;
    case 3:
      unsafe_leaderMPCandUpdateHalt_mexFunction(mexFunctionsStackDataGlobal,
                                                nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    case 4:
      unsafe_Rmat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    }
    mexFunctions_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete mexFunctionsStackDataGlobal;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void unsafe_Rmat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                             const mxArray *prhs[1])
{
  const mxArray *outputs;
  // Check for proper number of arguments.
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 1, 4, 4, "Rmat");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "Rmat");
  }
  // Call the function.
  Rmat_api(prhs[0], &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_evaluateObstacles_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[7])
{
  const mxArray *outputs;
  // Check for proper number of arguments.
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 7, 4, 17, "evaluateObstacles");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "evaluateObstacles");
  }
  // Call the function.
  evaluateObstacles_api(prhs, &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_followerMPCandUpdate_mexFunction(mexFunctionsStackData *SD,
                                             int32_T nlhs, mxArray *plhs[5],
                                             int32_T nrhs,
                                             const mxArray *prhs[7])
{
  const mxArray *outputs[5];
  int32_T i;
  // Check for proper number of arguments.
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 7, 4, 20, "followerMPCandUpdate");
  }
  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "followerMPCandUpdate");
  }
  // Call the function.
  b_followerMPCandUpdate_api(SD, prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void unsafe_leaderMPCandUpdateHalt_mexFunction(mexFunctionsStackData *SD,
                                               int32_T nlhs, mxArray *plhs[6],
                                               int32_T nrhs,
                                               const mxArray *prhs[6])
{
  const mxArray *outputs[6];
  int32_T i;
  // Check for proper number of arguments.
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 6, 4, 22, "leaderMPCandUpdateHalt");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "leaderMPCandUpdateHalt");
  }
  // Call the function.
  b_leaderMPCandUpdateHalt_api(SD, prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void unsafe_leaderMPCandUpdate_mexFunction(mexFunctionsStackData *SD,
                                           int32_T nlhs, mxArray *plhs[6],
                                           int32_T nrhs, const mxArray *prhs[6])
{
  const mxArray *outputs[6];
  int32_T i;
  // Check for proper number of arguments.
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 6, 4, 18, "leaderMPCandUpdate");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "leaderMPCandUpdate");
  }
  // Call the function.
  b_leaderMPCandUpdate_api(SD, prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

// End of code generation (_coder_mexFunctions_mex.cpp)
