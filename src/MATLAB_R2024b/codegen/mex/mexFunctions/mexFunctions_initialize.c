/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexFunctions_initialize.c
 *
 * Code generation for function 'mexFunctions_initialize'
 *
 */

/* Include files */
#include "mexFunctions_initialize.h"
#include "_coder_mexFunctions_mex.h"
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void mexFunctions_once(void);

/* Function Definitions */
static void mexFunctions_once(void)
{
  static const int32_T c_lineInfo[34] = {
      11, 12, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 27, 28, 29,
      31, 34, 35, 36, 37, 38, 39, 42, 49, 50, 52, 54, 55, 56, 57, 58, 59};
  static const int32_T d_lineInfo[17] = {4,  7,  10, 14, 15, 16, 17, 18, 19,
                                         20, 21, 22, 23, 24, 27, 28, 30};
  static const int32_T lineInfo[17] = {5,  6,  7,  9,  11, 13, 14, 15, 16,
                                       17, 22, 25, 30, 31, 34, 37, 39};
  static const int32_T b_lineInfo[15] = {4,  5,  6,  8,  10, 11, 12, 13,
                                         14, 15, 16, 17, 18, 19, 20};
  static const int32_T j_lineInfo[14] = {5,  8,  11, 15, 16, 18, 19,
                                         23, 24, 27, 28, 29, 30, 32};
  static const int32_T e_lineInfo[13] = {5,  8,  11, 15, 16, 18, 19,
                                         23, 24, 27, 28, 29, 33};
  static const int32_T f_lineInfo[12] = {4,  7,  12, 14, 16, 17,
                                         19, 20, 21, 28, 29, 31};
  static const int32_T i_lineInfo[12] = {9,  10, 11, 14, 18, 24,
                                         25, 26, 29, 32, 36, 38};
  static const int32_T g_lineInfo[10] = {8, 9, 11, 12, 13, 14, 16, 17, 18, 20};
  static const int32_T l_lineInfo[7] = {6, 7, 8, 9, 12, 15, 18};
  static const int32_T k_lineInfo[6] = {7, 9, 10, 11, 13, 15};
  static const int32_T h_lineInfo[5] = {3, 5, 6, 7, 9};
  int32_T b_iv[2];
  mex_InitInfAndNan();
  Rmat_complete_name = "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                       "2025\\src\\MATLAB_R2024b\\Rmat.m>Rmat(codegen)";
  leaderCostHalt_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderCostHalt.m>leaderCostHalt(codegen)";
  f_completeName =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderMPCandUpdateHalt.m>@(U)leaderCostHalt(U,x0,sys,N,"
      "robotParams)(codegen)";
  e_completeName =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderMPCandUpdateHalt.m>@(U)constraints(U,x0,obstacles"
      ".M_l,obstacles.A_bar_l,obstacles.B_bar_l,N,robotParams.robotShape,sys)("
      "codegen)";
  c_leaderMPCandUpdateHalt_comple =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderMPCandUpdateHalt.m>leaderMPCandUpdateHalt(codegen"
      ")";
  leaderCost_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderCost.m>leaderCost(codegen)";
  d_completeName =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderMPCandUpdate.m>@(U)leaderCost(U,x0,sys,robotParam"
      "s.W,robotParams.W_hat,robotParams.R_hat,N)(codegen)";
  c_completeName =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderMPCandUpdate.m>@(U)constraints(U,x0,obstacles.M_l"
      ",obstacles.A_bar_l,obstacles.B_bar_l,N,robotParams.robotShape,sys)("
      "codegen)";
  c_leaderMPCandUpdate_complete_n =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\leaderMPCandUpdate.m>leaderMPCandUpdate(codegen)";
  followerCost_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\followerCost.m>followerCost(codegen)";
  b_completeName =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\followerMPCandUpdate.m>@(U)followerCost(U,x0,sys,N,X_L_"
      "stacked,robotParams)(codegen)";
  modelDynamics_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\modelDynamics.m>modelDynamics(codegen)";
  stateEvolution_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\stateEvolution.m>stateEvolution(codegen)";
  constraints_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\constraints.m>constraints(codegen)";
  completeName =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\followerMPCandUpdate.m>@(U)constraints(U,x0,obstacles.M"
      "_f,obstacles.A_bar_f,obstacles.B_bar_f,N,robotParams.robotShape,sys)("
      "codegen)";
  c_followerMPCandUpdate_complete =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\followerMPCandUpdate.m>followerMPCandUpdate(codegen)";
  constMatrices_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\constMatrices.m>constMatrices(codegen)";
  getqiFromShape_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\getqiFromShape.m>getqiFromShape(codegen)";
  getObstacleInfo_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\getObstacleInfo.m>getObstacleInfo(codegen)";
  evaluateObstacles_complete_name =
      "C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_2025\\src\\MATLAB_"
      "R2024b\\evaluateObstacles.m>evaluateObstacles(codegen)";
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  emlrtProfilerRegisterMEXFcn(
      (char_T *)evaluateObstacles_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\evaluateObstacles.m",
      (char_T *)"evaluateObstacles", 17, &lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)getObstacleInfo_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\getObstacleInfo.m",
      (char_T *)"getObstacleInfo", 15, &b_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)getqiFromShape_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\getqiFromShape.m",
      (char_T *)"getqiFromShape", 34, &c_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)constMatrices_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\constMatrices.m",
      (char_T *)"constMatrices", 17, &d_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_followerMPCandUpdate_complete,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\followerMPCandUpdate.m",
      (char_T *)"followerMPCandUpdate", 13, &e_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)completeName,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\followerMPCandUpdate.m",
      (char_T *)"followerMPCandUpdate>@(U)constraints(U,x0,obstacles.M_f,"
                "obstacles.A_bar_f,obstacles.B_bar_f,N,robotParams.robotShape,"
                "sys)",
      0, (int32_T *)NULL, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)constraints_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\constraints.m",
      (char_T *)"constraints", 12, &f_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)stateEvolution_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\stateEvolution.m",
      (char_T *)"stateEvolution", 10, &g_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)modelDynamics_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\modelDynamics.m",
      (char_T *)"modelDynamics", 5, &h_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)b_completeName,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\followerMPCandUpdate.m",
      (char_T *)"followerMPCandUpdate>@(U)followerCost(U,x0,sys,N,X_L_stacked,"
                "robotParams)",
      0, (int32_T *)NULL, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)followerCost_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\followerCost.m",
      (char_T *)"followerCost", 12, &i_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_leaderMPCandUpdate_complete_n,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderMPCandUpdate.m",
      (char_T *)"leaderMPCandUpdate", 14, &j_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_completeName,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderMPCandUpdate.m",
      (char_T
           *)"leaderMPCandUpdate>@(U)constraints(U,x0,obstacles.M_l,obstacles."
             "A_bar_l,obstacles.B_bar_l,N,robotParams.robotShape,sys)",
      0, (int32_T *)NULL, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)d_completeName,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderMPCandUpdate.m",
      (char_T *)"leaderMPCandUpdate>@(U)leaderCost(U,x0,sys,robotParams.W,"
                "robotParams.W_hat,robotParams.R_hat,N)",
      0, (int32_T *)NULL, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)leaderCost_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderCost.m",
      (char_T *)"leaderCost", 6, &k_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_leaderMPCandUpdateHalt_comple,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderMPCandUpdateHalt.m",
      (char_T *)"leaderMPCandUpdateHalt", 14, &j_lineInfo[0], isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)e_completeName,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderMPCandUpdateHalt.m",
      (char_T *)"leaderMPCandUpdateHalt>@(U)constraints(U,x0,obstacles.M_l,"
                "obstacles.A_bar_l,obstacles.B_bar_l,N,robotParams.robotShape,"
                "sys)",
      0, (int32_T *)NULL, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)f_completeName,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderMPCandUpdateHalt.m",
      (char_T *)"leaderMPCandUpdateHalt>@(U)leaderCostHalt(U,x0,sys,N,"
                "robotParams)",
      0, (int32_T *)NULL, isMexOutdated);
  emlrtProfilerRegisterMEXFcn(
      (char_T *)leaderCostHalt_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\leaderCostHalt.m",
      (char_T *)"leaderCostHalt", 7, &l_lineInfo[0], isMexOutdated);
  b_iv[0] = 2;
  b_iv[1] = 3;
  emlrtProfilerRegisterMEXFcn(
      (char_T *)Rmat_complete_name,
      (char_T *)"C:\\Users\\kovac\\Desktop\\TESI\\master_thesis_"
                "2025\\src\\MATLAB_R2024b\\Rmat.m",
      (char_T *)"Rmat", 2, &b_iv[0], isMexOutdated);
}

void mexFunctions_initialize(void)
{
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, NULL);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2022a(emlrtRootTLSGlobal,
                          "EMLRT:runTime:MexFunctionNeedsLicense",
                          "optimization_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    mexFunctions_once();
  }
  emlrtCheckProfilerStatus();
}

/* End of code generation (mexFunctions_initialize.c) */
