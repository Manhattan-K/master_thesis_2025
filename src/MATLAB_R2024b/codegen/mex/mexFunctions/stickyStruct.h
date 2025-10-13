//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// stickyStruct.h
//
// Code generation for function 'stickyStruct'
//

#pragma once

// Include files
#include "anonymous_function.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder {
namespace internal {
class stickyStruct {
public:
  c_anonymous_function value;
};

class b_stickyStruct {
public:
  d_anonymous_function value;
  stickyStruct next;
};

class c_stickyStruct {
public:
  b_stickyStruct next;
};

class d_stickyStruct {
public:
  int32_T value;
  c_stickyStruct next;
};

class e_stickyStruct {
public:
  d_stickyStruct next;
};

class f_stickyStruct {
public:
  e_stickyStruct next;
};

class g_stickyStruct {
public:
  f_stickyStruct next;
};

class h_stickyStruct {
public:
  g_stickyStruct next;
};

class i_stickyStruct {
public:
  h_stickyStruct next;
};

class j_stickyStruct {
public:
  e_anonymous_function value;
};

class k_stickyStruct {
public:
  d_anonymous_function value;
  j_stickyStruct next;
};

class l_stickyStruct {
public:
  k_stickyStruct next;
};

class m_stickyStruct {
public:
  int32_T value;
  l_stickyStruct next;
};

class n_stickyStruct {
public:
  m_stickyStruct next;
};

class o_stickyStruct {
public:
  n_stickyStruct next;
};

class p_stickyStruct {
public:
  o_stickyStruct next;
};

class q_stickyStruct {
public:
  p_stickyStruct next;
};

class r_stickyStruct {
public:
  q_stickyStruct next;
};

class s_stickyStruct {
public:
  anonymous_function value;
};

class t_stickyStruct {
public:
  b_anonymous_function value;
  s_stickyStruct next;
};

class u_stickyStruct {
public:
  t_stickyStruct next;
};

class v_stickyStruct {
public:
  int32_T value;
  u_stickyStruct next;
};

class w_stickyStruct {
public:
  v_stickyStruct next;
};

class x_stickyStruct {
public:
  w_stickyStruct next;
};

class y_stickyStruct {
public:
  x_stickyStruct next;
};

class ab_stickyStruct {
public:
  y_stickyStruct next;
};

class bb_stickyStruct {
public:
  ab_stickyStruct next;
};

} // namespace internal
} // namespace coder

// End of code generation (stickyStruct.h)
