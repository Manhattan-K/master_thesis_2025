//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver.h
//
// Code generation for function 'driver'
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

struct f_struct_T;

struct h_struct_T;

namespace coder {
namespace internal {
class bb_stickyStruct;

}
} // namespace coder
struct o_struct_T;

struct c_struct_T;

struct g_struct_T;

struct d_struct_T;

struct e_struct_T;

struct b_struct_T;

namespace coder {
namespace internal {
class i_stickyStruct;

}
} // namespace coder
struct p_struct_T;

namespace coder {
namespace internal {
class r_stickyStruct;

}
} // namespace coder
struct q_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void driver(mexFunctionsStackData *SD, const real_T lb[40], const real_T ub[40],
            f_struct_T &b_TrialState, h_struct_T &b_MeritFunction,
            const ::coder::internal::r_stickyStruct &FcnEvaluator,
            q_struct_T &FiniteDifferences, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

void driver(mexFunctionsStackData *SD, const real_T lb[40], const real_T ub[40],
            f_struct_T &b_TrialState, h_struct_T &b_MeritFunction,
            const ::coder::internal::i_stickyStruct &FcnEvaluator,
            p_struct_T &FiniteDifferences, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

void driver(mexFunctionsStackData *SD, const real_T lb[40], const real_T ub[40],
            f_struct_T &b_TrialState, h_struct_T &b_MeritFunction,
            const ::coder::internal::bb_stickyStruct &FcnEvaluator,
            o_struct_T &FiniteDifferences, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600]);

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver.h)
