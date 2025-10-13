//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fmincon.h
//
// Code generation for function 'fmincon'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct mexFunctionsStackData;

namespace coder {
class anonymous_function;

class b_anonymous_function;

class c_anonymous_function;

class d_anonymous_function;

class e_anonymous_function;

} // namespace coder

// Function Declarations
namespace coder {
real_T d_fmincon(mexFunctionsStackData *SD, const e_anonymous_function &fun,
                 real_T x0[40], const real_T lb[40], const real_T ub[40],
                 const d_anonymous_function &nonlcon, real_T &exitflag,
                 real_T &output_iterations, real_T &output_funcCount,
                 char_T output_algorithm[3], real_T &output_constrviolation,
                 real_T &output_stepsize, real_T &output_lssteplength,
                 real_T &output_firstorderopt);

real_T d_fmincon(mexFunctionsStackData *SD, const c_anonymous_function &fun,
                 real_T x0[40], const real_T lb[40], const real_T ub[40],
                 const d_anonymous_function &nonlcon, real_T &exitflag,
                 real_T &output_iterations, real_T &output_funcCount,
                 char_T output_algorithm[3], real_T &output_constrviolation,
                 real_T &output_stepsize, real_T &output_lssteplength,
                 real_T &output_firstorderopt);

real_T d_fmincon(mexFunctionsStackData *SD, const anonymous_function &fun,
                 real_T x0[40], const real_T lb[40], const real_T ub[40],
                 const b_anonymous_function &nonlcon, real_T &exitflag,
                 real_T &output_iterations, real_T &output_funcCount,
                 char_T output_algorithm[3], real_T &output_constrviolation,
                 real_T &output_stepsize, real_T &output_lssteplength,
                 real_T &output_firstorderopt);

} // namespace coder

// End of code generation (fmincon.h)
