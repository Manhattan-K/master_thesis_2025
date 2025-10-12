/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_evaluateObstacles_mex_mex.c
 *
 * Code generation for function '_coder_evaluateObstacles_mex_mex'
 *
 */

/* Include files */
#include "_coder_evaluateObstacles_mex_mex.h"
#include "_coder_evaluateObstacles_mex_api.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_initialize.h"
#include "evaluateObstacles_mex_terminate.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  evaluateObstacles_mexStackData *c_evaluateObstacles_mexStackDat = NULL;
  const char_T *entryPointTemplateNames[5] = {
      "evaluateObstacles", "followerMPCandUpdate", "leaderMPCandUpdate",
      "leaderMPCandUpdateHalt", "Rmat"};
  c_evaluateObstacles_mexStackDat =
      (evaluateObstacles_mexStackData *)emlrtMxCalloc(
          (size_t)1, (size_t)1U * sizeof(evaluateObstacles_mexStackData));
  mexAtExit(&evaluateObstacles_mex_atexit);
  evaluateObstacles_mex_initialize();
  switch (emlrtGetEntryPointIndexR2016a(
      emlrtRootTLSGlobal, nrhs, &prhs[0],
      (const char_T **)&entryPointTemplateNames[0], 5)) {
  case 0:
    unsafe_evaluateObstacles_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 1:
    unsafe_followerMPCandUpdate_mexFunction(c_evaluateObstacles_mexStackDat,
                                            nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 2:
    unsafe_leaderMPCandUpdate_mexFunction(c_evaluateObstacles_mexStackDat, nlhs,
                                          plhs, nrhs - 1, &prhs[1]);
    break;
  case 3:
    unsafe_leaderMPCandUpdateHalt_mexFunction(c_evaluateObstacles_mexStackDat,
                                              nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 4:
    unsafe_Rmat_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  }
  evaluateObstacles_mex_terminate();
  emlrtMxFree(c_evaluateObstacles_mexStackDat);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void unsafe_Rmat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                             const mxArray *prhs[1])
{
  const mxArray *outputs;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 1, 4, 4, "Rmat");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "Rmat");
  }
  /* Call the function. */
  Rmat_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_evaluateObstacles_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[7])
{
  const mxArray *outputs;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 7, 4, 17, "evaluateObstacles");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "evaluateObstacles");
  }
  /* Call the function. */
  evaluateObstacles_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void unsafe_followerMPCandUpdate_mexFunction(evaluateObstacles_mexStackData *SD,
                                             int32_T nlhs, mxArray *plhs[5],
                                             int32_T nrhs,
                                             const mxArray *prhs[7])
{
  const mxArray *outputs[5];
  int32_T i;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 7, 4, 20, "followerMPCandUpdate");
  }
  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "followerMPCandUpdate");
  }
  /* Call the function. */
  followerMPCandUpdate_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void unsafe_leaderMPCandUpdateHalt_mexFunction(
    evaluateObstacles_mexStackData *SD, int32_T nlhs, mxArray *plhs[6],
    int32_T nrhs, const mxArray *prhs[6])
{
  const mxArray *outputs[6];
  int32_T i;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 6, 4, 22, "leaderMPCandUpdateHalt");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "leaderMPCandUpdateHalt");
  }
  /* Call the function. */
  leaderMPCandUpdateHalt_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void unsafe_leaderMPCandUpdate_mexFunction(evaluateObstacles_mexStackData *SD,
                                           int32_T nlhs, mxArray *plhs[6],
                                           int32_T nrhs, const mxArray *prhs[6])
{
  const mxArray *outputs[6];
  int32_T i;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 6, 4, 18, "leaderMPCandUpdate");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "leaderMPCandUpdate");
  }
  /* Call the function. */
  leaderMPCandUpdate_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_evaluateObstacles_mex_mex.c) */
