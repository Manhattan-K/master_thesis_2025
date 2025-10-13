/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexFunctions_terminate.c
 *
 * Code generation for function 'mexFunctions_terminate'
 *
 */

/* Include files */
#include "mexFunctions_terminate.h"
#include "_coder_mexFunctions_mex.h"
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Function Declarations */
static void emlrtExitTimeCleanupDtorFcn(const void *r);

/* Function Definitions */
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void mexFunctions_atexit(void)
{
  static jmp_buf emlrtJBEnviron;
  mexFunctionCreateRootTLS();
  emlrtLoadLibrary("C:\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\3P."
                   "instrset\\mingw_w64.instrset\\bin\\libgomp-1.dll");
  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&mexFunctions_nestLockGlobal);
  emlrtSetJmpBuf(emlrtRootTLSGlobal, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    emlrtPushHeapReferenceStackR2021a(emlrtRootTLSGlobal, false, NULL,
                                      (void *)&emlrtExitTimeCleanupDtorFcn,
                                      NULL, NULL, NULL);
    emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
    emlrtProfilerUnregisterMEXFcn((char_T *)evaluateObstacles_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)getObstacleInfo_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)getqiFromShape_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)constMatrices_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)c_followerMPCandUpdate_complete,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)completeName, isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)constraints_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)stateEvolution_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)modelDynamics_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)b_completeName, isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)followerCost_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)c_leaderMPCandUpdate_complete_n,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)c_completeName, isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)d_completeName, isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)leaderCost_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)c_leaderMPCandUpdateHalt_comple,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)e_completeName, isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)f_completeName, isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)leaderCostHalt_complete_name,
                                  isMexOutdated);
    emlrtProfilerUnregisterMEXFcn((char_T *)Rmat_complete_name, isMexOutdated);
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&mexFunctions_nestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&mexFunctions_nestLockGlobal);
    emlrtReportParallelRunTimeError(emlrtRootTLSGlobal);
  }
}

void mexFunctions_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (mexFunctions_terminate.c) */
