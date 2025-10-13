/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexFunctions_types.h
 *
 * Code generation for function 'evaluateObstacles'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include <stddef.h>

/* Type Definitions */
#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  real_T n;
  real_T m;
  real_T Ts;
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef typedef_rtString
#define typedef_rtString
typedef struct {
  char_T Value[6];
} rtString;
#endif /* typedef_rtString */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  rtString type;
  real_T center[2];
  real_T radius;
  boolean_T is_x_wall;
  real_T wall_pos;
  real_T a;
  real_T b;
  real_T theta;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_b_rtString
#define typedef_b_rtString
typedef struct {
  char_T Value[3];
} b_rtString;
#endif /* typedef_b_rtString */

#ifndef typedef_c_rtString
#define typedef_c_rtString
typedef struct {
  char_T Value[7];
} c_rtString;
#endif /* typedef_c_rtString */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T Px[6];
  real_T v_max;
  real_T w_max;
  b_rtString pos_color;
  c_rtString pred_color;
  rtString constraint_color;
  boolean_T show_predictions;
  boolean_T show_constraints;
  boolean_T keep_predictions;
  real_T initRobotShape[42];
  real_T robotShape[42];
  real_T W[9];
  real_T Z[9];
  real_T R[4];
  real_T W_hat[3600];
  real_T R_hat[1600];
  real_T lb[40];
  real_T ub[40];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_d_rtString
#define typedef_d_rtString
typedef struct {
  char_T Value[4];
} d_rtString;
#endif /* typedef_d_rtString */

#ifndef typedef_e_rtString
#define typedef_e_rtString
typedef struct {
  char_T Value[5];
} e_rtString;
#endif /* typedef_e_rtString */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T d_FL;
  real_T Px[6];
  real_T v_max;
  real_T w_max;
  d_rtString pos_color;
  d_rtString pred_color;
  e_rtString constraint_color;
  boolean_T show_predictions;
  boolean_T show_constraints;
  boolean_T keep_predictions;
  real_T initRobotShape[8];
  real_T robotShape[8];
  real_T d_FL_sq[20];
  real_T C;
  real_T beta;
  real_T beta_N[20];
  real_T lb[40];
  real_T ub[40];
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef typedef_struct7_T
#define typedef_struct7_T
typedef struct {
  real_T iterations;
  real_T funcCount;
  char_T algorithm[3];
  real_T constrviolation;
  real_T stepsize;
  real_T lssteplength;
  real_T firstorderopt;
} struct7_T;
#endif /* typedef_struct7_T */

#ifndef typedef_struct6_T
#define typedef_struct6_T
typedef struct {
  real_T QPexitflag;
  struct7_T QPoutput;
} struct6_T;
#endif /* typedef_struct6_T */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  real_T x0[3];
  struct3_T sys;
  real_T N;
  real_T X_L_stacked[60];
  struct2_T robotParams;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  real_T x0[3];
  struct3_T sys;
  struct1_T robotParams;
  real_T N;
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  real_T x0[3];
  struct3_T sys;
  real_T N;
  struct1_T robotParams;
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_anonymous_function
#define typedef_anonymous_function
typedef struct {
  b_struct_T workspace;
} anonymous_function;
#endif /* typedef_anonymous_function */

#ifndef c_typedef_coder_internal_sticky
#define c_typedef_coder_internal_sticky
typedef struct {
  anonymous_function value;
} coder_internal_stickyStruct;
#endif /* c_typedef_coder_internal_sticky */

#ifndef typedef_b_anonymous_function
#define typedef_b_anonymous_function
typedef struct {
  c_struct_T workspace;
} b_anonymous_function;
#endif /* typedef_b_anonymous_function */

#ifndef c_typedef_b_coder_internal_stic
#define c_typedef_b_coder_internal_stic
typedef struct {
  b_anonymous_function value;
} b_coder_internal_stickyStruct;
#endif /* c_typedef_b_coder_internal_stic */

#ifndef typedef_c_anonymous_function
#define typedef_c_anonymous_function
typedef struct {
  d_struct_T workspace;
} c_anonymous_function;
#endif /* typedef_c_anonymous_function */

#ifndef c_typedef_c_coder_internal_stic
#define c_typedef_c_coder_internal_stic
typedef struct {
  c_anonymous_function value;
} c_coder_internal_stickyStruct;
#endif /* c_typedef_c_coder_internal_stic */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_struct4_T
#define typedef_struct4_T
typedef struct {
  real_T M_l;
  real_T M_f;
  emxArray_real_T *A_bar_l;
  emxArray_real_T *B_bar_l;
  emxArray_real_T *A_bar_f;
  emxArray_real_T *B_bar_f;
} struct4_T;
#endif /* typedef_struct4_T */

#ifndef struct_emxArray_real_T_4200
#define struct_emxArray_real_T_4200
struct emxArray_real_T_4200 {
  real_T data[4200];
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_4200 */
#ifndef typedef_emxArray_real_T_4200
#define typedef_emxArray_real_T_4200
typedef struct emxArray_real_T_4200 emxArray_real_T_4200;
#endif /* typedef_emxArray_real_T_4200 */

#ifndef struct_emxArray_real_T_800
#define struct_emxArray_real_T_800
struct emxArray_real_T_800 {
  real_T data[800];
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_800 */
#ifndef typedef_emxArray_real_T_800
#define typedef_emxArray_real_T_800
typedef struct emxArray_real_T_800 emxArray_real_T_800;
#endif /* typedef_emxArray_real_T_800 */

#ifndef typedef_struct5_T
#define typedef_struct5_T
typedef struct {
  real_T M_l;
  real_T M_f;
  emxArray_real_T *A_bar_l;
  emxArray_real_T_4200 B_bar_l;
  emxArray_real_T *A_bar_f;
  emxArray_real_T_800 B_bar_f;
} struct5_T;
#endif /* typedef_struct5_T */

#ifndef struct_emxArray_real_T_4241
#define struct_emxArray_real_T_4241
struct emxArray_real_T_4241 {
  real_T data[4241];
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_4241 */
#ifndef typedef_emxArray_real_T_4241
#define typedef_emxArray_real_T_4241
typedef struct emxArray_real_T_4241 emxArray_real_T_4241;
#endif /* typedef_emxArray_real_T_4241 */

#ifndef struct_emxArray_int32_T_8481
#define struct_emxArray_int32_T_8481
struct emxArray_int32_T_8481 {
  int32_T data[8481];
  int32_T size[1];
};
#endif /* struct_emxArray_int32_T_8481 */
#ifndef typedef_emxArray_int32_T_8481
#define typedef_emxArray_int32_T_8481
typedef struct emxArray_int32_T_8481 emxArray_int32_T_8481;
#endif /* typedef_emxArray_int32_T_8481 */

#ifndef struct_emxArray_real_T_4240
#define struct_emxArray_real_T_4240
struct emxArray_real_T_4240 {
  real_T data[4240];
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_4240 */
#ifndef typedef_emxArray_real_T_4240
#define typedef_emxArray_real_T_4240
typedef struct emxArray_real_T_4240 emxArray_real_T_4240;
#endif /* typedef_emxArray_real_T_4240 */

#ifndef struct_emxArray_int32_T_4241
#define struct_emxArray_int32_T_4241
struct emxArray_int32_T_4241 {
  int32_T data[4241];
  int32_T size[1];
};
#endif /* struct_emxArray_int32_T_4241 */
#ifndef typedef_emxArray_int32_T_4241
#define typedef_emxArray_int32_T_4241
typedef struct emxArray_int32_T_4241 emxArray_int32_T_4241;
#endif /* typedef_emxArray_int32_T_4241 */

#ifndef struct_emxArray_boolean_T_8481
#define struct_emxArray_boolean_T_8481
struct emxArray_boolean_T_8481 {
  boolean_T data[8481];
  int32_T size[1];
};
#endif /* struct_emxArray_boolean_T_8481 */
#ifndef typedef_emxArray_boolean_T_8481
#define typedef_emxArray_boolean_T_8481
typedef struct emxArray_boolean_T_8481 emxArray_boolean_T_8481;
#endif /* typedef_emxArray_boolean_T_8481 */

#ifndef typedef_e_struct_T
#define typedef_e_struct_T
typedef struct {
  emxArray_real_T_4241 grad;
  emxArray_real_T_4240 Hx;
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
} e_struct_T;
#endif /* typedef_e_struct_T */

#ifndef typedef_f_struct_T
#define typedef_f_struct_T
typedef struct {
  emxArray_real_T *workspace_float;
  emxArray_int32_T_8481 workspace_int;
  emxArray_int32_T_8481 workspace_sort;
} f_struct_T;
#endif /* typedef_f_struct_T */

#ifndef typedef_g_struct_T
#define typedef_g_struct_T
typedef struct {
  int32_T ldq;
  emxArray_real_T *QR;
  emxArray_real_T *Q;
  emxArray_int32_T_8481 jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T *tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
} g_struct_T;
#endif /* typedef_g_struct_T */

#ifndef struct_emxArray_ptrdiff_t
#define struct_emxArray_ptrdiff_t
struct emxArray_ptrdiff_t {
  ptrdiff_t *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_ptrdiff_t */
#ifndef typedef_emxArray_ptrdiff_t
#define typedef_emxArray_ptrdiff_t
typedef struct emxArray_ptrdiff_t emxArray_ptrdiff_t;
#endif /* typedef_emxArray_ptrdiff_t */

#ifndef typedef_h_struct_T
#define typedef_h_struct_T
typedef struct {
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
  emxArray_real_T_4241 cIneq;
  emxArray_real_T_4241 cIneq_old;
  emxArray_real_T_4241 grad;
  emxArray_real_T_4241 grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T *lambdasqp;
  emxArray_real_T *lambdaStopTest;
  emxArray_real_T *lambdaStopTestPrev;
  real_T steplength;
  emxArray_real_T_4241 delta_x;
  emxArray_real_T_4241 socDirection;
  emxArray_int32_T_8481 workingset_old;
  emxArray_real_T *JacCineqTrans_old;
  emxArray_real_T_4241 gradLag;
  emxArray_real_T_4241 delta_gradLag;
  emxArray_real_T_4241 xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T *lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_4241 searchDir;
} h_struct_T;
#endif /* typedef_h_struct_T */

#ifndef struct_emxArray_real_T_0
#define struct_emxArray_real_T_0
struct emxArray_real_T_0 {
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_0 */
#ifndef typedef_emxArray_real_T_0
#define typedef_emxArray_real_T_0
typedef struct emxArray_real_T_0 emxArray_real_T_0;
#endif /* typedef_emxArray_real_T_0 */

#ifndef typedef_i_struct_T
#define typedef_i_struct_T
typedef struct {
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T *Aineq;
  emxArray_real_T_4200 bineq;
  emxArray_real_T_0 Aeq;
  emxArray_real_T_4241 lb;
  emxArray_real_T_4241 ub;
  emxArray_int32_T_4241 indexLB;
  emxArray_int32_T_4241 indexUB;
  emxArray_int32_T_4241 indexFixed;
  int32_T mEqRemoved;
  emxArray_real_T *ATwset;
  emxArray_real_T *bwset;
  int32_T nActiveConstr;
  emxArray_real_T *maxConstrWorkspace;
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
  emxArray_boolean_T_8481 isActiveConstr;
  emxArray_int32_T_8481 Wid;
  emxArray_int32_T_8481 Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
} i_struct_T;
#endif /* typedef_i_struct_T */

#ifndef typedef_k_struct_T
#define typedef_k_struct_T
typedef struct {
  real_T x0[3];
  struct5_T obstacles;
  real_T N;
  struct3_T sys;
} k_struct_T;
#endif /* typedef_k_struct_T */

#ifndef typedef_d_anonymous_function
#define typedef_d_anonymous_function
typedef struct {
  k_struct_T workspace;
} d_anonymous_function;
#endif /* typedef_d_anonymous_function */

#ifndef c_typedef_d_coder_internal_stic
#define c_typedef_d_coder_internal_stic
typedef struct {
  d_anonymous_function value;
  coder_internal_stickyStruct next;
} d_coder_internal_stickyStruct;
#endif /* c_typedef_d_coder_internal_stic */

#ifndef c_typedef_e_coder_internal_stic
#define c_typedef_e_coder_internal_stic
typedef struct {
  d_coder_internal_stickyStruct next;
} e_coder_internal_stickyStruct;
#endif /* c_typedef_e_coder_internal_stic */

#ifndef c_typedef_f_coder_internal_stic
#define c_typedef_f_coder_internal_stic
typedef struct {
  int32_T value;
  e_coder_internal_stickyStruct next;
} f_coder_internal_stickyStruct;
#endif /* c_typedef_f_coder_internal_stic */

#ifndef c_typedef_g_coder_internal_stic
#define c_typedef_g_coder_internal_stic
typedef struct {
  f_coder_internal_stickyStruct next;
} g_coder_internal_stickyStruct;
#endif /* c_typedef_g_coder_internal_stic */

#ifndef c_typedef_h_coder_internal_stic
#define c_typedef_h_coder_internal_stic
typedef struct {
  g_coder_internal_stickyStruct next;
} h_coder_internal_stickyStruct;
#endif /* c_typedef_h_coder_internal_stic */

#ifndef c_typedef_i_coder_internal_stic
#define c_typedef_i_coder_internal_stic
typedef struct {
  h_coder_internal_stickyStruct next;
} i_coder_internal_stickyStruct;
#endif /* c_typedef_i_coder_internal_stic */

#ifndef c_typedef_j_coder_internal_stic
#define c_typedef_j_coder_internal_stic
typedef struct {
  i_coder_internal_stickyStruct next;
} j_coder_internal_stickyStruct;
#endif /* c_typedef_j_coder_internal_stic */

#ifndef c_typedef_k_coder_internal_stic
#define c_typedef_k_coder_internal_stic
typedef struct {
  j_coder_internal_stickyStruct next;
} k_coder_internal_stickyStruct;
#endif /* c_typedef_k_coder_internal_stic */

#ifndef typedef_l_struct_T
#define typedef_l_struct_T
typedef struct {
  anonymous_function objfun;
  d_anonymous_function nonlin;
  real_T f_1;
  emxArray_real_T_800 cIneq_1;
  int32_T mIneq;
  int32_T numEvals;
  boolean_T hasLB[40];
  boolean_T hasUB[40];
  boolean_T hasBounds;
} l_struct_T;
#endif /* typedef_l_struct_T */

#ifndef typedef_m_struct_T
#define typedef_m_struct_T
typedef struct {
  emxArray_real_T *FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  boolean_T ConvexCheck;
  real_T workspace_;
  real_T workspace2_;
} m_struct_T;
#endif /* typedef_m_struct_T */

#ifndef c_typedef_l_coder_internal_stic
#define c_typedef_l_coder_internal_stic
typedef struct {
  d_anonymous_function value;
  b_coder_internal_stickyStruct next;
} l_coder_internal_stickyStruct;
#endif /* c_typedef_l_coder_internal_stic */

#ifndef c_typedef_m_coder_internal_stic
#define c_typedef_m_coder_internal_stic
typedef struct {
  l_coder_internal_stickyStruct next;
} m_coder_internal_stickyStruct;
#endif /* c_typedef_m_coder_internal_stic */

#ifndef c_typedef_n_coder_internal_stic
#define c_typedef_n_coder_internal_stic
typedef struct {
  int32_T value;
  m_coder_internal_stickyStruct next;
} n_coder_internal_stickyStruct;
#endif /* c_typedef_n_coder_internal_stic */

#ifndef c_typedef_o_coder_internal_stic
#define c_typedef_o_coder_internal_stic
typedef struct {
  n_coder_internal_stickyStruct next;
} o_coder_internal_stickyStruct;
#endif /* c_typedef_o_coder_internal_stic */

#ifndef c_typedef_p_coder_internal_stic
#define c_typedef_p_coder_internal_stic
typedef struct {
  o_coder_internal_stickyStruct next;
} p_coder_internal_stickyStruct;
#endif /* c_typedef_p_coder_internal_stic */

#ifndef c_typedef_q_coder_internal_stic
#define c_typedef_q_coder_internal_stic
typedef struct {
  p_coder_internal_stickyStruct next;
} q_coder_internal_stickyStruct;
#endif /* c_typedef_q_coder_internal_stic */

#ifndef c_typedef_r_coder_internal_stic
#define c_typedef_r_coder_internal_stic
typedef struct {
  q_coder_internal_stickyStruct next;
} r_coder_internal_stickyStruct;
#endif /* c_typedef_r_coder_internal_stic */

#ifndef c_typedef_s_coder_internal_stic
#define c_typedef_s_coder_internal_stic
typedef struct {
  r_coder_internal_stickyStruct next;
} s_coder_internal_stickyStruct;
#endif /* c_typedef_s_coder_internal_stic */

#ifndef typedef_o_struct_T
#define typedef_o_struct_T
typedef struct {
  b_anonymous_function objfun;
  d_anonymous_function nonlin;
  real_T f_1;
  emxArray_real_T_4200 cIneq_1;
  int32_T mIneq;
  int32_T numEvals;
  boolean_T hasLB[40];
  boolean_T hasUB[40];
  boolean_T hasBounds;
} o_struct_T;
#endif /* typedef_o_struct_T */

#ifndef c_typedef_t_coder_internal_stic
#define c_typedef_t_coder_internal_stic
typedef struct {
  d_anonymous_function value;
  c_coder_internal_stickyStruct next;
} t_coder_internal_stickyStruct;
#endif /* c_typedef_t_coder_internal_stic */

#ifndef c_typedef_u_coder_internal_stic
#define c_typedef_u_coder_internal_stic
typedef struct {
  t_coder_internal_stickyStruct next;
} u_coder_internal_stickyStruct;
#endif /* c_typedef_u_coder_internal_stic */

#ifndef c_typedef_v_coder_internal_stic
#define c_typedef_v_coder_internal_stic
typedef struct {
  int32_T value;
  u_coder_internal_stickyStruct next;
} v_coder_internal_stickyStruct;
#endif /* c_typedef_v_coder_internal_stic */

#ifndef c_typedef_w_coder_internal_stic
#define c_typedef_w_coder_internal_stic
typedef struct {
  v_coder_internal_stickyStruct next;
} w_coder_internal_stickyStruct;
#endif /* c_typedef_w_coder_internal_stic */

#ifndef c_typedef_x_coder_internal_stic
#define c_typedef_x_coder_internal_stic
typedef struct {
  w_coder_internal_stickyStruct next;
} x_coder_internal_stickyStruct;
#endif /* c_typedef_x_coder_internal_stic */

#ifndef c_typedef_y_coder_internal_stic
#define c_typedef_y_coder_internal_stic
typedef struct {
  x_coder_internal_stickyStruct next;
} y_coder_internal_stickyStruct;
#endif /* c_typedef_y_coder_internal_stic */

#ifndef c_typedef_ab_coder_internal_sti
#define c_typedef_ab_coder_internal_sti
typedef struct {
  y_coder_internal_stickyStruct next;
} ab_coder_internal_stickyStruct;
#endif /* c_typedef_ab_coder_internal_sti */

#ifndef c_typedef_bb_coder_internal_sti
#define c_typedef_bb_coder_internal_sti
typedef struct {
  ab_coder_internal_stickyStruct next;
} bb_coder_internal_stickyStruct;
#endif /* c_typedef_bb_coder_internal_sti */

#ifndef typedef_p_struct_T
#define typedef_p_struct_T
typedef struct {
  c_anonymous_function objfun;
  d_anonymous_function nonlin;
  real_T f_1;
  emxArray_real_T_4200 cIneq_1;
  int32_T mIneq;
  int32_T numEvals;
  boolean_T hasLB[40];
  boolean_T hasUB[40];
  boolean_T hasBounds;
} p_struct_T;
#endif /* typedef_p_struct_T */

#ifndef c_typedef_e_maxConstraintViolat
#define c_typedef_e_maxConstraintViolat
typedef struct {
  i_struct_T obj;
} e_maxConstraintViolation;
#endif /* c_typedef_e_maxConstraintViolat */

#ifndef typedef_d_fmincon
#define typedef_d_fmincon
typedef struct {
  h_struct_T TrialState;
  i_struct_T WorkingSet;
  e_struct_T QPObjective;
  f_struct_T memspace;
  l_struct_T obj;
} d_fmincon;
#endif /* typedef_d_fmincon */

#ifndef typedef_e_fmincon
#define typedef_e_fmincon
typedef struct {
  h_struct_T TrialState;
  i_struct_T WorkingSet;
  o_struct_T FiniteDifferences;
  s_coder_internal_stickyStruct FcnEvaluator;
  e_struct_T QPObjective;
  f_struct_T memspace;
} e_fmincon;
#endif /* typedef_e_fmincon */

#ifndef typedef_f_fmincon
#define typedef_f_fmincon
typedef struct {
  h_struct_T TrialState;
  i_struct_T WorkingSet;
  p_struct_T FiniteDifferences;
  bb_coder_internal_stickyStruct FcnEvaluator;
  e_struct_T QPObjective;
  f_struct_T memspace;
} f_fmincon;
#endif /* typedef_f_fmincon */

#ifndef c_typedef_b_followerMPCandUpdat
#define c_typedef_b_followerMPCandUpdat
typedef struct {
  struct5_T obstacles;
} b_followerMPCandUpdate_api;
#endif /* c_typedef_b_followerMPCandUpdat */

#ifndef c_typedef_b_leaderMPCandUpdate_
#define c_typedef_b_leaderMPCandUpdate_
typedef struct {
  struct1_T robotParams;
  struct5_T obstacles;
} b_leaderMPCandUpdate_api;
#endif /* c_typedef_b_leaderMPCandUpdate_ */

#ifndef c_typedef_b_leaderMPCandUpdateH
#define c_typedef_b_leaderMPCandUpdateH
typedef struct {
  struct1_T robotParams;
  struct5_T obstacles;
} b_leaderMPCandUpdateHalt_api;
#endif /* c_typedef_b_leaderMPCandUpdateH */

#ifndef typedef_mexFunctionsStackData
#define typedef_mexFunctionsStackData
typedef struct {
  e_maxConstraintViolation f0;
  union {
    d_fmincon f1;
    e_fmincon f2;
    f_fmincon f3;
  } u2;
  union {
    b_followerMPCandUpdate_api f4;
    b_leaderMPCandUpdate_api f5;
    b_leaderMPCandUpdateHalt_api f6;
  } u3;
} mexFunctionsStackData;
#endif /* typedef_mexFunctionsStackData */

/* End of code generation (mexFunctions_types.h) */
