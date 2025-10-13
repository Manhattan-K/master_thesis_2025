//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver1.cpp
//
// Code generation for function 'driver1'
//

// Include files
#include "driver1.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "phaseone.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const real_T H[1600], const real_T f_data[], f_struct_T &solution,
            c_struct_T &memspace, g_struct_T &workingset, d_struct_T &qrmanager,
            e_struct_T &cholmanager, b_struct_T &objective,
            const i_struct_T &options, const i_struct_T &runTimeOptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> b_solution;
  array<real_T, 1U> c_solution;
  array<real_T, 1U> r;
  int32_T i;
  int32_T idx;
  int32_T nVar;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  solution.iterations = 0;
  nVar = workingset.nVar;
  guard1 = false;
  if (workingset.probType == 3) {
    i = static_cast<uint16_T>(workingset.sizes[0]);
    for (idx = 0; idx < i; idx++) {
      solution.xstar.data[workingset.indexFixed.data[idx] - 1] =
          workingset.ub.data[workingset.indexFixed.data[idx] - 1];
    }
    i = static_cast<uint16_T>(workingset.sizes[3]);
    for (idx = 0; idx < i; idx++) {
      if (workingset.isActiveConstr
              .data[(workingset.isActiveIdx[3] + idx) - 1]) {
        solution.xstar.data[workingset.indexLB.data[idx] - 1] =
            -workingset.lb.data[workingset.indexLB.data[idx] - 1];
      }
    }
    i = static_cast<uint16_T>(workingset.sizes[4]);
    for (idx = 0; idx < i; idx++) {
      if (workingset.isActiveConstr
              .data[(workingset.isActiveIdx[4] + idx) - 1]) {
        solution.xstar.data[workingset.indexUB.data[idx] - 1] =
            workingset.ub.data[workingset.indexUB.data[idx] - 1];
      }
    }
    initialize::PresolveWorkingSet(solution, memspace, workingset, qrmanager);
    if (solution.state >= 0) {
      guard1 = true;
    }
  } else {
    solution.state = 82;
    guard1 = true;
  }
  if (guard1) {
    solution.iterations = 0;
    solution.maxConstr =
        WorkingSet::b_maxConstraintViolation(workingset, solution.xstar.data);
    if (solution.maxConstr > 1.0E-6) {
      phaseone(H, f_data, solution, memspace, workingset, qrmanager,
               cholmanager, objective, options.SolverName, runTimeOptions);
      if (solution.state != 0) {
        solution.maxConstr = WorkingSet::b_maxConstraintViolation(
            workingset, solution.xstar.data);
        if (solution.maxConstr > 1.0E-6) {
          idx = workingset.mConstrMax;
          for (nVar = 0; nVar < idx; nVar++) {
            solution.lambda[nVar] = 0.0;
          }
          solution.fstar =
              Objective::computeFval(objective, memspace.workspace_float, H,
                                     f_data, solution.xstar.data);
          solution.state = -2;
        } else {
          if (solution.maxConstr > 0.0) {
            real_T maxConstr_new;
            r.set_size(solution.searchDir.size[0]);
            idx = solution.searchDir.size[0];
            for (i = 0; i < idx; i++) {
              r[i] = solution.searchDir.data[i];
            }
            b_solution.set(&solution.xstar.data[0], solution.xstar.size[0]);
            if (nVar >= 1) {
              n_t = (ptrdiff_t)nVar;
              incx_t = (ptrdiff_t)1;
              incy_t = (ptrdiff_t)1;
              dcopy(&n_t, &(b_solution.data())[0], &incx_t, &(r.data())[0],
                    &incy_t);
            }
            idx = r.size(0);
            solution.searchDir.size[0] = r.size(0);
            for (i = 0; i < idx; i++) {
              solution.searchDir.data[i] = r[i];
            }
            initialize::PresolveWorkingSet(solution, memspace, workingset,
                                           qrmanager);
            maxConstr_new = WorkingSet::b_maxConstraintViolation(
                workingset, solution.xstar.data);
            if (maxConstr_new >= solution.maxConstr) {
              solution.maxConstr = maxConstr_new;
              r.set_size(solution.xstar.size[0]);
              idx = solution.xstar.size[0];
              for (i = 0; i < idx; i++) {
                r[i] = solution.xstar.data[i];
              }
              c_solution.set(&solution.searchDir.data[0],
                             solution.searchDir.size[0]);
              if (nVar >= 1) {
                n_t = (ptrdiff_t)nVar;
                incx_t = (ptrdiff_t)1;
                incy_t = (ptrdiff_t)1;
                dcopy(&n_t, &(c_solution.data())[0], &incx_t, &(r.data())[0],
                      &incy_t);
              }
              idx = r.size(0);
              solution.xstar.size[0] = r.size(0);
              for (i = 0; i < idx; i++) {
                solution.xstar.data[i] = r[i];
              }
            }
          }
          b_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                    cholmanager, objective, options.SolverName,
                    runTimeOptions.MaxIterations);
        }
      }
    } else {
      b_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                cholmanager, objective, options.SolverName,
                runTimeOptions.MaxIterations);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver1.cpp)
