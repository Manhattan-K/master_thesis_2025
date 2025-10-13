//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_mexFunctions_api.cpp
//
// Code generation for function '_coder_mexFunctions_api'
//

// Include files
#include "_coder_mexFunctions_api.h"
#include "Rmat.h"
#include "evaluateObstacles.h"
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "mexFunctions_types2.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Function Declarations
static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static real_T (*b_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[2];

static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[3]);

static coder::rtString b_emlrt_marshallIn(const mxArray *u,
                                          const emlrtMsgIdentifier *parentId);

static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6]);

static const mxArray *b_emlrt_marshallOut(coder::array<real_T, 2U> &u);

static const mxArray *b_emlrt_marshallOut(real_T u[40]);

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[7]);

static void c_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[42]);

static boolean_T c_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static struct3_T c_emlrt_marshallIn(const mxArray *b_nullptr,
                                    const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(real_T u[4]);

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static real_T (*d_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static void d_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static void d_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[4]);

static real_T (*d_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[3];

static coder::b_rtString e_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId);

static real_T (*e_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[60];

static void e_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4]);

static void e_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[5]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[2]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct2_T &y);

static real_T emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static real_T emlrt_marshallIn(const mxArray *a__output_of_feval_,
                               const char_T *identifier);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct5_T &y);

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct5_T &y);

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct1_T &y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T &y);

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct0_T y_data[], int32_T y_size[2]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             struct0_T y_data[], int32_T y_size[2]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[6]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T &y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T &y);

static const mxArray *emlrt_marshallOut(const struct6_T u);

static const mxArray *emlrt_marshallOut(real_T u[2]);

static const mxArray *emlrt_marshallOut(const struct4_T &u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(coder::array<real_T, 1U> &u);

static real_T (*f_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[40];

static coder::c_rtString f_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId);

static void f_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[6]);

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3600]);

static void g_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[3]);

static coder::d_rtString g_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId);

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[1600]);

static coder::e_rtString h_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId);

static void h_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[7]);

static void h_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[40]);

static struct3_T i_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void i_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[4]);

static void i_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[8]);

static void j_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[5]);

static void j_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[20]);

static real_T (*j_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static real_T (*k_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[60];

static int32_T k_emlrt_marshallIn(const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  real_T y_data[]);

static int32_T l_emlrt_marshallIn(const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  real_T y_data[]);

static real_T (*l_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[40];

static real_T m_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void m_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static boolean_T n_emlrt_marshallIn(const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static void n_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6]);

static void o_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[42]);

static real_T (*o_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static real_T (*p_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static void p_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

static real_T (*q_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[60];

static void q_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4]);

static void r_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[3600]);

static real_T (*r_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[40];

static void s_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[1600]);

static void t_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[40]);

static void u_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[8]);

static void v_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[20]);

static int32_T w_emlrt_marshallIn(const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  real_T ret_data[]);

static int32_T x_emlrt_marshallIn(const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  real_T ret_data[]);

// Function Definitions
static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  d_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[3])
{
  g_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*b_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static coder::rtString b_emlrt_marshallIn(const mxArray *u,
                                          const emlrtMsgIdentifier *parentId)
{
  coder::rtString y;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues;
  const char_T *propClasses{"coder.internal.string"};
  const char_T *propNames{"Value"};
  propValues = nullptr;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      emlrtRootTLSGlobal, u, 0, "coder.internal.string"));
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u,
                           "coder.internal.string");
  emlrtGetAllProperties(emlrtRootTLSGlobal, u, 0, 1,
                        (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  thisId.fIdentifier = "Value";
  emlrt_marshallIn(emlrtAlias(propValues), &thisId, y.Value);
  emlrtDestroyArrays(1, &propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6])
{
  n_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(coder::array<real_T, 2U> &u)
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, &(u.data())[0]);
  emlrtSetDimensions((mxArray *)m, u.size(), 2);
  u.no_free();
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *b_emlrt_marshallOut(real_T u[40])
{
  static const int32_T i{0};
  static const int32_T i1{40};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[7])
{
  h_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{4200, 60};
  int32_T b_iv[2];
  boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret.set_size(b_iv[0], b_iv[1]);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[42])
{
  o_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T c_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = n_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static struct3_T c_emlrt_marshallIn(const mxArray *b_nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  struct3_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = i_emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static const mxArray *c_emlrt_marshallOut(real_T u[4])
{
  static const int32_T b_iv[2]{0, 0};
  static const int32_T iv1[2]{2, 2};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  p_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*d_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = o_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{800, 60};
  int32_T b_iv[2];
  boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret.set_size(b_iv[0], b_iv[1]);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[4])
{
  i_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*d_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static coder::b_rtString e_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId)
{
  coder::b_rtString y;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues;
  const char_T *propClasses{"coder.internal.string"};
  const char_T *propNames{"Value"};
  propValues = nullptr;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      emlrtRootTLSGlobal, u, 0, "coder.internal.string"));
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u,
                           "coder.internal.string");
  emlrtGetAllProperties(emlrtRootTLSGlobal, u, 0, 1,
                        (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  thisId.fIdentifier = "Value";
  b_emlrt_marshallIn(emlrtAlias(propValues), &thisId, y.Value);
  emlrtDestroyArrays(1, &propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4])
{
  q_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*e_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[60]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[60];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = k_emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[5])
{
  j_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[6])
{
  f_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const mxArray *a__output_of_feval_,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(emlrtAlias(a__output_of_feval_), &thisId);
  emlrtDestroyArray(&a__output_of_feval_);
  return y;
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct5_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[6]{"M_l",     "M_f",     "A_bar_l",
                                     "B_bar_l", "A_bar_f", "B_bar_f"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 6,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "M_l";
  y.M_l = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0, "M_l")),
      &thisId);
  thisId.fIdentifier = "M_f";
  y.M_f = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1, "M_f")),
      &thisId);
  thisId.fIdentifier = "A_bar_l";
  emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2, "A_bar_l")),
      &thisId, y.A_bar_l);
  thisId.fIdentifier = "B_bar_l";
  y.B_bar_l.size[0] = k_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3, "B_bar_l")),
      &thisId, y.B_bar_l.data);
  thisId.fIdentifier = "A_bar_f";
  b_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4, "A_bar_f")),
      &thisId, y.A_bar_f);
  thisId.fIdentifier = "B_bar_f";
  y.B_bar_f.size[0] = l_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5, "B_bar_f")),
      &thisId, y.B_bar_f.data);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct5_T &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  c_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct0_T y_data[], int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId, y_data, y_size);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             struct0_T y_data[], int32_T y_size[2])
{
  static const boolean_T bv[2]{false, true};
  emlrtMsgIdentifier thisId;
  int32_T b_iv[2];
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b_iv[0] = 1;
  b_iv[1] = 24;
  emlrtCheckVsCell(emlrtRootTLSGlobal, parentId, u, 2U, &b_iv[0], &bv[0],
                   &y_size[0]);
  for (int32_T i{0}; i < y_size[1]; i++) {
    emlrtMexSnprintf(&str[0], (size_t)11U, "%d", i + 1);
    thisId.fIdentifier = &str[0];
    emlrt_marshallIn(
        emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, parentId, u, i)), &thisId,
        y_data[i]);
  }
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[8]{
      "type", "center", "radius", "is_x_wall", "wall_pos", "a", "b", "theta"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 8,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "type";
  y.type = b_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0, "type")),
      &thisId);
  thisId.fIdentifier = "center";
  emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1, "center")),
      &thisId, y.center);
  thisId.fIdentifier = "radius";
  y.radius = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2, "radius")),
      &thisId);
  thisId.fIdentifier = "is_x_wall";
  y.is_x_wall = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3, "is_x_wall")),
      &thisId);
  thisId.fIdentifier = "wall_pos";
  y.wall_pos = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4, "wall_pos")),
      &thisId);
  thisId.fIdentifier = "a";
  y.a = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5, "a")),
      &thisId);
  thisId.fIdentifier = "b";
  y.b = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 6, "b")),
      &thisId);
  thisId.fIdentifier = "theta";
  y.theta = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 7, "theta")),
      &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[2])
{
  m_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct1_T &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[18]{"Px",
                                      "v_max",
                                      "w_max",
                                      "pos_color",
                                      "pred_color",
                                      "constraint_color",
                                      "show_predictions",
                                      "show_constraints",
                                      "keep_predictions",
                                      "initRobotShape",
                                      "robotShape",
                                      "W",
                                      "Z",
                                      "R",
                                      "W_hat",
                                      "R_hat",
                                      "lb",
                                      "ub"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 18,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "Px";
  b_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0, "Px")),
      &thisId, y.Px);
  thisId.fIdentifier = "v_max";
  y.v_max = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1, "v_max")),
      &thisId);
  thisId.fIdentifier = "w_max";
  y.w_max = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2, "w_max")),
      &thisId);
  thisId.fIdentifier = "pos_color";
  y.pos_color = e_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3, "pos_color")),
      &thisId);
  thisId.fIdentifier = "pred_color";
  y.pred_color =
      f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u,
                                                        0, 4, "pred_color")),
                         &thisId);
  thisId.fIdentifier = "constraint_color";
  y.constraint_color =
      b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 5, "constraint_color")),
                         &thisId);
  thisId.fIdentifier = "show_predictions";
  y.show_predictions =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 6, "show_predictions")),
                         &thisId);
  thisId.fIdentifier = "show_constraints";
  y.show_constraints =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 7, "show_constraints")),
                         &thisId);
  thisId.fIdentifier = "keep_predictions";
  y.keep_predictions =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 8, "keep_predictions")),
                         &thisId);
  thisId.fIdentifier = "initRobotShape";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 9,
                                                    "initRobotShape")),
                     &thisId, y.initRobotShape);
  thisId.fIdentifier = "robotShape";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                    10, "robotShape")),
                     &thisId, y.robotShape);
  thisId.fIdentifier = "W";
  d_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 11, "W")),
      &thisId, y.W);
  thisId.fIdentifier = "Z";
  d_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 12, "Z")),
      &thisId, y.Z);
  thisId.fIdentifier = "R";
  e_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 13, "R")),
      &thisId, y.R);
  thisId.fIdentifier = "W_hat";
  f_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 14, "W_hat")),
      &thisId, y.W_hat);
  thisId.fIdentifier = "R_hat";
  g_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 15, "R_hat")),
      &thisId, y.R_hat);
  thisId.fIdentifier = "lb";
  h_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 16, "lb")),
      &thisId, y.lb);
  thisId.fIdentifier = "ub";
  h_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 17, "ub")),
      &thisId, y.ub);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *b_nullptr, const char_T *identifier,
                             struct2_T &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[18]{"d_FL",
                                      "Px",
                                      "v_max",
                                      "w_max",
                                      "pos_color",
                                      "pred_color",
                                      "constraint_color",
                                      "show_predictions",
                                      "show_constraints",
                                      "keep_predictions",
                                      "initRobotShape",
                                      "robotShape",
                                      "d_FL_sq",
                                      "C",
                                      "beta",
                                      "beta_N",
                                      "lb",
                                      "ub"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 18,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "d_FL";
  y.d_FL = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0, "d_FL")),
      &thisId);
  thisId.fIdentifier = "Px";
  b_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1, "Px")),
      &thisId, y.Px);
  thisId.fIdentifier = "v_max";
  y.v_max = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2, "v_max")),
      &thisId);
  thisId.fIdentifier = "w_max";
  y.w_max = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3, "w_max")),
      &thisId);
  thisId.fIdentifier = "pos_color";
  y.pos_color = g_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4, "pos_color")),
      &thisId);
  thisId.fIdentifier = "pred_color";
  y.pred_color =
      g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u,
                                                        0, 5, "pred_color")),
                         &thisId);
  thisId.fIdentifier = "constraint_color";
  y.constraint_color =
      h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 6, "constraint_color")),
                         &thisId);
  thisId.fIdentifier = "show_predictions";
  y.show_predictions =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 7, "show_predictions")),
                         &thisId);
  thisId.fIdentifier = "show_constraints";
  y.show_constraints =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 8, "show_constraints")),
                         &thisId);
  thisId.fIdentifier = "keep_predictions";
  y.keep_predictions =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 9, "keep_predictions")),
                         &thisId);
  thisId.fIdentifier = "initRobotShape";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                    10, "initRobotShape")),
                     &thisId, y.initRobotShape);
  thisId.fIdentifier = "robotShape";
  i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                    11, "robotShape")),
                     &thisId, y.robotShape);
  thisId.fIdentifier = "d_FL_sq";
  j_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 12, "d_FL_sq")),
      &thisId, y.d_FL_sq);
  thisId.fIdentifier = "C";
  y.C = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 13, "C")),
      &thisId);
  thisId.fIdentifier = "beta";
  y.beta = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 14, "beta")),
      &thisId);
  thisId.fIdentifier = "beta_N";
  j_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 15, "beta_N")),
      &thisId, y.beta_N);
  thisId.fIdentifier = "lb";
  h_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 16, "lb")),
      &thisId, y.lb);
  thisId.fIdentifier = "ub";
  h_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 17, "ub")),
      &thisId, y.ub);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(real_T u[2])
{
  static const int32_T i{0};
  static const int32_T i1{2};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct4_T &u)
{
  static const char_T *sv[6]{"M_l",     "M_f",     "A_bar_l",
                             "B_bar_l", "A_bar_f", "B_bar_f"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&sv[0]));
  b_y = nullptr;
  m = emlrtCreateDoubleScalar(u.M_l);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "M_l", b_y, 0);
  c_y = nullptr;
  m = emlrtCreateDoubleScalar(u.M_f);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "M_f", c_y, 1);
  emlrtSetFieldR2017b(y, 0, "A_bar_l", emlrt_marshallOut(u.A_bar_l), 2);
  d_y = nullptr;
  m = emlrtCreateNumericArray(1,
                              ((coder::array<real_T, 1U> *)&u.B_bar_l)->size(),
                              mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.B_bar_l.size(0); b_i++) {
    pData[i] = u.B_bar_l[b_i];
    i++;
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "B_bar_l", d_y, 3);
  emlrtSetFieldR2017b(y, 0, "A_bar_f", emlrt_marshallOut(u.A_bar_f), 4);
  e_y = nullptr;
  m = emlrtCreateNumericArray(1,
                              ((coder::array<real_T, 1U> *)&u.B_bar_f)->size(),
                              mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.B_bar_f.size(0); b_i++) {
    pData[i] = u.B_bar_f[b_i];
    i++;
  }
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "B_bar_f", e_y, 5);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct6_T u)
{
  static const int32_T b_iv[2]{1, 3};
  static const char_T *sv1[7]{"iterations",      "funcCount", "algorithm",
                              "constrviolation", "stepsize",  "lssteplength",
                              "firstorderopt"};
  static const char_T *sv[2]{"QPexitflag", "QPoutput"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  b_y = nullptr;
  m = emlrtCreateDoubleScalar(u.QPexitflag);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "QPexitflag", b_y, 0);
  c_y = nullptr;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&sv1[0]));
  d_y = nullptr;
  m = emlrtCreateDoubleScalar(u.QPoutput.iterations);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(c_y, 0, "iterations", d_y, 0);
  e_y = nullptr;
  m = emlrtCreateDoubleScalar(u.QPoutput.funcCount);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(c_y, 0, "funcCount", e_y, 1);
  f_y = nullptr;
  m = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 3, m, &u.QPoutput.algorithm[0]);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(c_y, 0, "algorithm", f_y, 2);
  g_y = nullptr;
  m = emlrtCreateDoubleScalar(u.QPoutput.constrviolation);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(c_y, 0, "constrviolation", g_y, 3);
  h_y = nullptr;
  m = emlrtCreateDoubleScalar(u.QPoutput.stepsize);
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(c_y, 0, "stepsize", h_y, 4);
  i_y = nullptr;
  m = emlrtCreateDoubleScalar(u.QPoutput.lssteplength);
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(c_y, 0, "lssteplength", i_y, 5);
  j_y = nullptr;
  m = emlrtCreateDoubleScalar(u.QPoutput.firstorderopt);
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(c_y, 0, "firstorderopt", j_y, 6);
  emlrtSetFieldR2017b(y, 0, "QPoutput", c_y, 1);
  return y;
}

static const mxArray *emlrt_marshallOut(coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(u.data())[0]);
  emlrtSetDimensions((mxArray *)m, u.size(), 1);
  u.no_free();
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_iv[2];
  int32_T i;
  y = nullptr;
  b_iv[0] = u.size(0);
  b_iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.size(1); b_i++) {
    for (int32_T c_i{0}; c_i < u.size(0); c_i++) {
      pData[i] = u[c_i + u.size(0) * b_i];
      i++;
    }
  }
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[6])
{
  static const int32_T dims[2]{1, 6};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 6);
  emlrtDestroyArray(&src);
}

static coder::c_rtString f_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId)
{
  coder::c_rtString y;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues;
  const char_T *propClasses{"coder.internal.string"};
  const char_T *propNames{"Value"};
  propValues = nullptr;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      emlrtRootTLSGlobal, u, 0, "coder.internal.string"));
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u,
                           "coder.internal.string");
  emlrtGetAllProperties(emlrtRootTLSGlobal, u, 0, 1,
                        (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  thisId.fIdentifier = "Value";
  c_emlrt_marshallIn(emlrtAlias(propValues), &thisId, y.Value);
  emlrtDestroyArrays(1, &propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3600])
{
  r_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*f_emlrt_marshallIn(const mxArray *b_nullptr,
                                   const char_T *identifier))[40]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[40];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static coder::d_rtString g_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId)
{
  coder::d_rtString y;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues;
  const char_T *propClasses{"coder.internal.string"};
  const char_T *propNames{"Value"};
  propValues = nullptr;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      emlrtRootTLSGlobal, u, 0, "coder.internal.string"));
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u,
                           "coder.internal.string");
  emlrtGetAllProperties(emlrtRootTLSGlobal, u, 0, 1,
                        (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  thisId.fIdentifier = "Value";
  d_emlrt_marshallIn(emlrtAlias(propValues), &thisId, y.Value);
  emlrtDestroyArrays(1, &propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[1600])
{
  s_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[3])
{
  static const int32_T dims[2]{1, 3};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 3);
  emlrtDestroyArray(&src);
}

static coder::e_rtString h_emlrt_marshallIn(const mxArray *u,
                                            const emlrtMsgIdentifier *parentId)
{
  coder::e_rtString y;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues;
  const char_T *propClasses{"coder.internal.string"};
  const char_T *propNames{"Value"};
  propValues = nullptr;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u, "string");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      emlrtRootTLSGlobal, u, 0, "coder.internal.string"));
  emlrtCheckMcosClass2017a(emlrtRootTLSGlobal, parentId, u,
                           "coder.internal.string");
  emlrtGetAllProperties(emlrtRootTLSGlobal, u, 0, 1,
                        (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  thisId.fIdentifier = "Value";
  e_emlrt_marshallIn(emlrtAlias(propValues), &thisId, y.Value);
  emlrtDestroyArrays(1, &propValues);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[7])
{
  static const int32_T dims[2]{1, 7};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 7);
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[40])
{
  t_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static struct3_T i_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[3]{"n", "m", "Ts"};
  emlrtMsgIdentifier thisId;
  struct3_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "n";
  y.n = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0, "n")),
      &thisId);
  thisId.fIdentifier = "m";
  y.m = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1, "m")),
      &thisId);
  thisId.fIdentifier = "Ts";
  y.Ts = emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2, "Ts")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[4])
{
  static const int32_T dims[2]{1, 4};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 4);
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[8])
{
  u_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*j_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = p_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[5])
{
  static const int32_T dims[2]{1, 5};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 5);
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[20])
{
  v_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*k_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[60]
{
  real_T(*y)[60];
  y = q_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T k_emlrt_marshallIn(const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  real_T y_data[])
{
  int32_T y_size;
  y_size = w_emlrt_marshallIn(emlrtAlias(u), parentId, y_data);
  emlrtDestroyArray(&u);
  return y_size;
}

static int32_T l_emlrt_marshallIn(const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  real_T y_data[])
{
  int32_T y_size;
  y_size = x_emlrt_marshallIn(emlrtAlias(u), parentId, y_data);
  emlrtDestroyArray(&u);
  return y_size;
}

static real_T (*l_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[40]
{
  real_T(*y)[40];
  y = r_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T m_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static void m_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims{2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims[2]{2, 3};
  real_T(*r)[6];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[6])emlrtMxGetData(src);
  for (int32_T i{0}; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static boolean_T n_emlrt_marshallIn(const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  boolean_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "logical", false, 0U,
                          (const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void o_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[42])
{
  static const int32_T dims[2]{2, 21};
  real_T(*r)[42];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[42])emlrtMxGetData(src);
  for (int32_T i{0}; i < 42; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T (*o_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims{2};
  real_T(*ret)[2];
  int32_T i;
  boolean_T b{false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*p_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims{3};
  real_T(*ret)[3];
  int32_T i;
  boolean_T b{false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void p_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2]{3, 3};
  real_T(*r)[9];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (int32_T i{0}; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2]{2, 2};
  real_T(*r)[4];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

static real_T (*q_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[60]
{
  static const int32_T dims{60};
  real_T(*ret)[60];
  int32_T i;
  boolean_T b{false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[60])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void r_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[3600])
{
  static const int32_T dims[2]{60, 60};
  real_T(*r)[3600];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[3600])emlrtMxGetData(src);
  for (int32_T i{0}; i < 3600; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T (*r_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[40]
{
  static const int32_T dims{40};
  real_T(*ret)[40];
  int32_T i;
  boolean_T b{false};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[40])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void s_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[1600])
{
  static const int32_T dims[2]{40, 40};
  real_T(*r)[1600];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[1600])emlrtMxGetData(src);
  for (int32_T i{0}; i < 1600; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[40])
{
  static const int32_T dims{40};
  real_T(*r)[40];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[40])emlrtMxGetData(src);
  for (int32_T i{0}; i < 40; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[8])
{
  static const int32_T dims[2]{2, 4};
  real_T(*r)[8];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[8])emlrtMxGetData(src);
  for (int32_T i{0}; i < 8; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[20])
{
  static const int32_T dims[2]{1, 20};
  real_T(*r)[20];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[20])emlrtMxGetData(src);
  for (int32_T i{0}; i < 20; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static int32_T w_emlrt_marshallIn(const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  real_T ret_data[])
{
  static const int32_T dims{4200};
  int32_T ret_size;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &ret_size);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
  return ret_size;
}

static int32_T x_emlrt_marshallIn(const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  real_T ret_data[])
{
  static const int32_T dims{800};
  int32_T ret_size;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &ret_size);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
  return ret_size;
}

void Rmat_api(const mxArray *prhs, const mxArray **plhs)
{
  real_T(*R)[4];
  real_T theta;
  R = (real_T(*)[4])mxMalloc(sizeof(real_T[4]));
  // Marshall function inputs
  theta = emlrt_marshallIn(emlrtAliasP(prhs), "theta");
  // Invoke the target function
  Rmat(theta, *R);
  // Marshall function outputs
  *plhs = c_emlrt_marshallOut(*R);
}

void b_followerMPCandUpdate_api(mexFunctionsStackData *SD,
                                const mxArray *const prhs[7], int32_T nlhs,
                                const mxArray *plhs[5])
{
  coder::array<real_T, 2U> X_F;
  coder::array<real_T, 1U> p_tp1;
  struct2_T robotParams;
  struct3_T sys;
  struct6_T c_error;
  real_T(*X_L_stacked)[60];
  real_T(*U_f_old)[40];
  real_T(*u_opt)[40];
  real_T(*x0)[3];
  real_T(*u_t)[2];
  real_T N;
  u_t = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  u_opt = (real_T(*)[40])mxMalloc(sizeof(real_T[40]));
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  // Marshall function inputs
  sys = c_emlrt_marshallIn(emlrtAliasP(prhs[0]), "sys");
  x0 = d_emlrt_marshallIn(emlrtAlias(prhs[1]), "x0");
  X_L_stacked = e_emlrt_marshallIn(emlrtAlias(prhs[2]), "X_L_stacked");
  N = emlrt_marshallIn(emlrtAliasP(prhs[3]), "N");
  emlrt_marshallIn(emlrtAliasP(prhs[4]), "robotParams", robotParams);
  emlrt_marshallIn(emlrtAliasP(prhs[5]), "obstacles", SD->f7.obstacles);
  U_f_old = f_emlrt_marshallIn(emlrtAlias(prhs[6]), "U_f_old");
  // Invoke the target function
  followerMPCandUpdate(SD, &sys, *x0, *X_L_stacked, N, &robotParams,
                       &SD->f7.obstacles, *U_f_old, p_tp1, X_F, &c_error, *u_t,
                       *u_opt);
  // Marshall function outputs
  p_tp1.no_free();
  plhs[0] = emlrt_marshallOut(p_tp1);
  if (nlhs > 1) {
    X_F.no_free();
    plhs[1] = b_emlrt_marshallOut(X_F);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(c_error);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(*u_t);
  }
  if (nlhs > 4) {
    plhs[4] = b_emlrt_marshallOut(*u_opt);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void b_leaderMPCandUpdateHalt_api(mexFunctionsStackData *SD,
                                  const mxArray *const prhs[6], int32_T nlhs,
                                  const mxArray *plhs[6])
{
  coder::array<real_T, 2U> X_L;
  coder::array<real_T, 1U> X_L_stacked;
  coder::array<real_T, 1U> p_tp1;
  struct3_T sys;
  struct6_T c_error;
  real_T(*U_l_old)[40];
  real_T(*u_opt)[40];
  real_T(*x0)[3];
  real_T(*u_t)[2];
  real_T N;
  u_t = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  u_opt = (real_T(*)[40])mxMalloc(sizeof(real_T[40]));
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  // Marshall function inputs
  sys = c_emlrt_marshallIn(emlrtAliasP(prhs[0]), "sys");
  x0 = d_emlrt_marshallIn(emlrtAlias(prhs[1]), "x0");
  N = emlrt_marshallIn(emlrtAliasP(prhs[2]), "N");
  emlrt_marshallIn(emlrtAliasP(prhs[3]), "robotParams", SD->f9.robotParams);
  emlrt_marshallIn(emlrtAliasP(prhs[4]), "obstacles", SD->f9.obstacles);
  U_l_old = f_emlrt_marshallIn(emlrtAlias(prhs[5]), "U_l_old");
  // Invoke the target function
  leaderMPCandUpdateHalt(SD, &sys, *x0, N, &SD->f9.robotParams,
                         &SD->f9.obstacles, *U_l_old, p_tp1, X_L, X_L_stacked,
                         &c_error, *u_t, *u_opt);
  // Marshall function outputs
  p_tp1.no_free();
  plhs[0] = emlrt_marshallOut(p_tp1);
  if (nlhs > 1) {
    X_L.no_free();
    plhs[1] = b_emlrt_marshallOut(X_L);
  }
  if (nlhs > 2) {
    X_L_stacked.no_free();
    plhs[2] = emlrt_marshallOut(X_L_stacked);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(c_error);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(*u_t);
  }
  if (nlhs > 5) {
    plhs[5] = b_emlrt_marshallOut(*u_opt);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void b_leaderMPCandUpdate_api(mexFunctionsStackData *SD,
                              const mxArray *const prhs[6], int32_T nlhs,
                              const mxArray *plhs[6])
{
  coder::array<real_T, 2U> X_L;
  coder::array<real_T, 1U> X_L_stacked;
  coder::array<real_T, 1U> p_tp1;
  struct3_T sys;
  struct6_T c_error;
  real_T(*U_l_old)[40];
  real_T(*u_opt)[40];
  real_T(*x0)[3];
  real_T(*u_t)[2];
  real_T N;
  u_t = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  u_opt = (real_T(*)[40])mxMalloc(sizeof(real_T[40]));
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  // Marshall function inputs
  sys = c_emlrt_marshallIn(emlrtAliasP(prhs[0]), "sys");
  x0 = d_emlrt_marshallIn(emlrtAlias(prhs[1]), "x0");
  N = emlrt_marshallIn(emlrtAliasP(prhs[2]), "N");
  emlrt_marshallIn(emlrtAliasP(prhs[3]), "robotParams", SD->f8.robotParams);
  emlrt_marshallIn(emlrtAliasP(prhs[4]), "obstacles", SD->f8.obstacles);
  U_l_old = f_emlrt_marshallIn(emlrtAlias(prhs[5]), "U_l_old");
  // Invoke the target function
  leaderMPCandUpdate(SD, &sys, *x0, N, &SD->f8.robotParams, &SD->f8.obstacles,
                     *U_l_old, p_tp1, X_L, X_L_stacked, &c_error, *u_t, *u_opt);
  // Marshall function outputs
  p_tp1.no_free();
  plhs[0] = emlrt_marshallOut(p_tp1);
  if (nlhs > 1) {
    X_L.no_free();
    plhs[1] = b_emlrt_marshallOut(X_L);
  }
  if (nlhs > 2) {
    X_L_stacked.no_free();
    plhs[2] = emlrt_marshallOut(X_L_stacked);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(c_error);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(*u_t);
  }
  if (nlhs > 5) {
    plhs[5] = b_emlrt_marshallOut(*u_opt);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void evaluateObstacles_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  struct0_T obstacles_data[24];
  struct1_T leaderParams;
  struct2_T followerParams;
  struct3_T sys;
  struct4_T obstaclesInRange;
  real_T(*x_f)[2];
  real_T(*x_l)[2];
  real_T N;
  int32_T obstacles_size[2];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  // Marshall function inputs
  emlrt_marshallIn(emlrtAliasP(prhs[0]), "obstacles", obstacles_data,
                   obstacles_size);
  x_l = b_emlrt_marshallIn(emlrtAlias(prhs[1]), "x_l");
  x_f = b_emlrt_marshallIn(emlrtAlias(prhs[2]), "x_f");
  emlrt_marshallIn(emlrtAliasP(prhs[3]), "leaderParams", leaderParams);
  emlrt_marshallIn(emlrtAliasP(prhs[4]), "followerParams", followerParams);
  sys = c_emlrt_marshallIn(emlrtAliasP(prhs[5]), "sys");
  N = emlrt_marshallIn(emlrtAliasP(prhs[6]), "N");
  // Invoke the target function
  evaluateObstacles(obstacles_data, obstacles_size, *x_l, *x_f, &leaderParams,
                    &followerParams, &sys, N, &obstaclesInRange);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(obstaclesInRange);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

// End of code generation (_coder_mexFunctions_api.cpp)
