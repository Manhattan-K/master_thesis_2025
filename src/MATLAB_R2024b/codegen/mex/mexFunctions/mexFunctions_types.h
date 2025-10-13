//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mexFunctions_types.h
//
// Code generation for function 'evaluateObstacles'
//

#pragma once

// Include files
#include "anonymous_function.h"
#include "mexFunctions_types2.h"
#include "rtwtypes.h"
#include "stickyStruct.h"
#include "string1.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "emlrt.h"

// Type Definitions
struct struct7_T {
  real_T iterations;
  real_T funcCount;
  char_T algorithm[3];
  real_T constrviolation;
  real_T stepsize;
  real_T lssteplength;
  real_T firstorderopt;
};

struct struct6_T {
  real_T QPexitflag;
  struct7_T QPoutput;
};

struct struct4_T {
  real_T M_l;
  real_T M_f;
  coder::array<real_T, 2U> A_bar_l;
  coder::array<real_T, 1U> B_bar_l;
  coder::array<real_T, 2U> A_bar_f;
  coder::array<real_T, 1U> B_bar_f;
};

struct b_struct_T {
  coder::bounded_array<real_T, 4241U, 1U> grad;
  coder::bounded_array<real_T, 4240U, 1U> Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

struct c_struct_T {
  coder::array<real_T, 2U> workspace_float;
  coder::bounded_array<int32_T, 8481U, 1U> workspace_int;
  coder::bounded_array<int32_T, 8481U, 1U> workspace_sort;
};

struct f_struct_T {
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[40];
  real_T xstarsqp_old[40];
  coder::bounded_array<real_T, 4241U, 1U> cIneq;
  coder::bounded_array<real_T, 4241U, 1U> cIneq_old;
  coder::bounded_array<real_T, 4241U, 1U> grad;
  coder::bounded_array<real_T, 4241U, 1U> grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  coder::array<real_T, 1U> lambdasqp;
  coder::array<real_T, 1U> lambdaStopTest;
  coder::array<real_T, 1U> lambdaStopTestPrev;
  real_T steplength;
  coder::bounded_array<real_T, 4241U, 1U> delta_x;
  coder::bounded_array<real_T, 4241U, 1U> socDirection;
  coder::bounded_array<int32_T, 8481U, 1U> workingset_old;
  coder::array<real_T, 2U> JacCineqTrans_old;
  coder::bounded_array<real_T, 4241U, 1U> gradLag;
  coder::bounded_array<real_T, 4241U, 1U> delta_gradLag;
  coder::bounded_array<real_T, 4241U, 1U> xstar;
  real_T fstar;
  real_T firstorderopt;
  coder::array<real_T, 1U> lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  coder::bounded_array<real_T, 4241U, 1U> searchDir;
};

struct g_struct_T {
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  coder::array<real_T, 1U> Aineq;
  coder::bounded_array<real_T, 4200U, 1U> bineq;
  coder::empty_bounded_array<real_T, 1U> Aeq;
  coder::bounded_array<real_T, 4241U, 1U> lb;
  coder::bounded_array<real_T, 4241U, 1U> ub;
  coder::bounded_array<int32_T, 4241U, 1U> indexLB;
  coder::bounded_array<int32_T, 4241U, 1U> indexUB;
  coder::bounded_array<int32_T, 4241U, 1U> indexFixed;
  int32_T mEqRemoved;
  coder::array<real_T, 1U> ATwset;
  coder::array<real_T, 1U> bwset;
  int32_T nActiveConstr;
  coder::array<real_T, 1U> maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  coder::bounded_array<boolean_T, 8481U, 1U> isActiveConstr;
  coder::bounded_array<int32_T, 8481U, 1U> Wid;
  coder::bounded_array<int32_T, 8481U, 1U> Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

struct maxConstraintViolation {
  g_struct_T obj;
};

struct followerMPCandUpdate_api {
  struct5_T obstacles;
};

struct struct0_T {
  coder::rtString type;
  real_T center[2];
  real_T radius;
  boolean_T is_x_wall;
  real_T wall_pos;
  real_T a;
  real_T b;
  real_T theta;
};

struct o_struct_T {
  coder::anonymous_function objfun;
  coder::b_anonymous_function nonlin;
  real_T f_1;
  coder::bounded_array<real_T, 800U, 1U> cIneq_1;
  int32_T mIneq;
  int32_T numEvals;
  boolean_T hasLB[40];
  boolean_T hasUB[40];
  boolean_T hasBounds;
};

struct fmincon {
  f_struct_T TrialState;
  g_struct_T WorkingSet;
  b_struct_T QPObjective;
  c_struct_T memspace;
  o_struct_T obj;
};

struct p_struct_T {
  coder::c_anonymous_function objfun;
  coder::d_anonymous_function nonlin;
  real_T f_1;
  coder::bounded_array<real_T, 4200U, 1U> cIneq_1;
  int32_T mIneq;
  int32_T numEvals;
  boolean_T hasLB[40];
  boolean_T hasUB[40];
  boolean_T hasBounds;
};

struct b_fmincon {
  f_struct_T TrialState;
  g_struct_T WorkingSet;
  p_struct_T FiniteDifferences;
  coder::internal::i_stickyStruct FcnEvaluator;
  b_struct_T QPObjective;
  c_struct_T memspace;
};

struct q_struct_T {
  coder::e_anonymous_function objfun;
  coder::d_anonymous_function nonlin;
  real_T f_1;
  coder::bounded_array<real_T, 4200U, 1U> cIneq_1;
  int32_T mIneq;
  int32_T numEvals;
  boolean_T hasLB[40];
  boolean_T hasUB[40];
  boolean_T hasBounds;
};

struct c_fmincon {
  f_struct_T TrialState;
  g_struct_T WorkingSet;
  q_struct_T FiniteDifferences;
  coder::internal::r_stickyStruct FcnEvaluator;
  b_struct_T QPObjective;
  c_struct_T memspace;
};

struct b_followerMPCandUpdate {
  coder::b_anonymous_function constraintsF;
};

struct b_leaderMPCandUpdate {
  coder::d_anonymous_function constraintsF;
};

struct b_leaderMPCandUpdateHalt {
  coder::d_anonymous_function constraintsF;
};

struct leaderMPCandUpdate_api {
  struct1_T robotParams;
  struct5_T obstacles;
};

struct leaderMPCandUpdateHalt_api {
  struct1_T robotParams;
  struct5_T obstacles;
};

struct mexFunctionsStackData {
  maxConstraintViolation f0;
  fmincon f1;
  b_fmincon f2;
  c_fmincon f3;
  b_followerMPCandUpdate f4;
  b_leaderMPCandUpdate f5;
  b_leaderMPCandUpdateHalt f6;
  followerMPCandUpdate_api f7;
  leaderMPCandUpdate_api f8;
  leaderMPCandUpdateHalt_api f9;
};

// End of code generation (mexFunctions_types.h)
