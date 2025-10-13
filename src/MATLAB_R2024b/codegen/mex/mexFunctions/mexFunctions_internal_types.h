//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mexFunctions_internal_types.h
//
// Code generation for function 'evaluateObstacles'
//

#pragma once

// Include files
#include "mexFunctions_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "emlrt.h"

// Type Definitions
struct struct_T {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
};

struct d_struct_T {
  int32_T ldq;
  coder::array<real_T, 2U> QR;
  coder::array<real_T, 2U> Q;
  coder::bounded_array<int32_T, 8481U, 1U> jpvt;
  int32_T mrows;
  int32_T ncols;
  coder::array<real_T, 1U> tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

struct e_struct_T {
  coder::array<real_T, 2U> FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_;
  real_T workspace2_;
};

struct h_struct_T {
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
};

struct i_struct_T {
  char_T SolverName[7];
  int32_T MaxIterations;
};

struct rtBoundsCheckInfo {
  int32_T iFirst;
  int32_T iLast;
  int32_T lineNo;
  int32_T colNo;
  const char_T *aName;
  const char_T *fName;
  const char_T *pName;
  int32_T checkKind;
};

struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

// End of code generation (mexFunctions_internal_types.h)
