/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.c
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "laplace_iters.h"
#include "eml_setop.h"
#include "laplace_iters_emxutil.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo mb_emlrtRSI = { 225,/* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 228,/* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 134,/* lineNo */
  22,                                  /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 434,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 430,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 392,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pName */
};

/* Function Declarations */
static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x);

/* Function Definitions */
static real_T skip_to_last_equal_value(int32_T *k, const emxArray_real_T *x)
{
  real_T xk;
  boolean_T exitg1;
  real_T absxk;
  int32_T exponent;
  boolean_T p;
  xk = x->data[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x->size[1])) {
    absxk = muDoubleScalarAbs(xk / 2.0);
    if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((muDoubleScalarAbs(xk - x->data[*k]) < absxk) || (muDoubleScalarIsInf
         (x->data[*k]) && muDoubleScalarIsInf(xk) && ((x->data[*k] > 0.0) == (xk
           > 0.0)))) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return xk;
}

void do_vectors(const emlrtStack *sp, const emxArray_real_T *a, const
                emxArray_real_T *b, emxArray_real_T *c, emxArray_int32_T *ia,
                int32_T ib_size[1])
{
  int32_T na;
  uint32_T unnamed_idx_1;
  int32_T iblast;
  boolean_T y;
  int32_T iafirst;
  boolean_T exitg1;
  boolean_T p;
  int32_T nc;
  int32_T nia;
  int32_T ialast;
  int32_T b_ialast;
  real_T ak;
  real_T bk;
  real_T absxk;
  emxArray_int32_T *b_ia;
  int32_T exponent;
  int32_T b_exponent;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  na = a->size[1];
  unnamed_idx_1 = (uint32_T)a->size[1];
  iblast = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = (int32_T)unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)c, iblast, sizeof(real_T),
                    &h_emlrtRTEI);
  iblast = ia->size[0];
  ia->size[0] = a->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)ia, iblast, sizeof(int32_T),
                    &h_emlrtRTEI);
  ib_size[0] = 0;
  y = true;
  if (a->size[1] != 0) {
    iafirst = 1;
    exitg1 = false;
    while ((!exitg1) && (iafirst <= a->size[1] - 1)) {
      if ((a->data[iafirst - 1] <= a->data[iafirst]) || muDoubleScalarIsNaN
          (a->data[iafirst])) {
        p = true;
      } else {
        p = false;
      }

      if (!p) {
        y = false;
        exitg1 = true;
      } else {
        iafirst++;
      }
    }
  }

  if (!y) {
    st.site = &mb_emlrtRSI;
    error(&st);
  }

  y = true;
  if (b->size[0] != 0) {
    iafirst = 1;
    exitg1 = false;
    while ((!exitg1) && (iafirst <= b->size[0] - 1)) {
      if ((b->data[iafirst - 1] <= b->data[iafirst]) || muDoubleScalarIsNaN
          (b->data[iafirst])) {
        p = true;
      } else {
        p = false;
      }

      if (!p) {
        y = false;
        exitg1 = true;
      } else {
        iafirst++;
      }
    }
  }

  if (!y) {
    st.site = &ob_emlrtRSI;
    b_error(&st);
  }

  nc = 0;
  nia = 0;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  while ((ialast <= na) && (iblast <= b->size[0])) {
    b_ialast = ialast;
    ak = skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    bk = b->data[iblast - 1];
    exitg1 = false;
    while ((!exitg1) && (iblast < b->size[0])) {
      absxk = muDoubleScalarAbs(bk / 2.0);
      if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
        if (absxk <= 2.2250738585072014E-308) {
          absxk = 4.94065645841247E-324;
        } else {
          frexp(absxk, &b_exponent);
          absxk = ldexp(1.0, b_exponent - 53);
        }
      } else {
        absxk = rtNaN;
      }

      if ((muDoubleScalarAbs(bk - b->data[iblast]) < absxk) ||
          (muDoubleScalarIsInf(b->data[iblast]) && muDoubleScalarIsInf(bk) &&
           ((b->data[iblast] > 0.0) == (bk > 0.0)))) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        iblast++;
      } else {
        exitg1 = true;
      }
    }

    absxk = muDoubleScalarAbs(bk / 2.0);
    if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((muDoubleScalarAbs(bk - ak) < absxk) || (muDoubleScalarIsInf(ak) &&
         muDoubleScalarIsInf(bk) && ((ak > 0.0) == (bk > 0.0)))) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast++;
    } else {
      if ((ak < bk) || muDoubleScalarIsNaN(bk)) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        nc++;
        nia++;
        c->data[nc - 1] = ak;
        ia->data[nia - 1] = iafirst + 1;
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast++;
      }
    }
  }

  while (ialast <= na) {
    iafirst = ialast;
    ak = skip_to_last_equal_value(&iafirst, a);
    nc++;
    nia++;
    c->data[nc - 1] = ak;
    ia->data[nia - 1] = ialast;
    ialast = iafirst + 1;
  }

  if (a->size[1] > 0) {
    if (!(nia <= a->size[1])) {
      emlrtErrorWithMessageIdR2012b(sp, &bb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nia) {
      iafirst = 0;
    } else {
      iafirst = nia;
    }

    emxInit_int32_T(sp, &b_ia, 1, &h_emlrtRTEI, true);
    iblast = b_ia->size[0];
    b_ia->size[0] = iafirst;
    emxEnsureCapacity(sp, (emxArray__common *)b_ia, iblast, sizeof(int32_T),
                      &h_emlrtRTEI);
    for (iblast = 0; iblast < iafirst; iblast++) {
      b_ia->data[iblast] = ia->data[iblast];
    }

    iblast = ia->size[0];
    ia->size[0] = b_ia->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ia, iblast, sizeof(int32_T),
                      &h_emlrtRTEI);
    iafirst = b_ia->size[0];
    for (iblast = 0; iblast < iafirst; iblast++) {
      ia->data[iblast] = b_ia->data[iblast];
    }

    emxFree_int32_T(&b_ia);
    if (!(nc <= a->size[1])) {
      emlrtErrorWithMessageIdR2012b(sp, &ab_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    iblast = c->size[0] * c->size[1];
    if (1 > nc) {
      c->size[1] = 0;
    } else {
      c->size[1] = nc;
    }

    emxEnsureCapacity(sp, (emxArray__common *)c, iblast, sizeof(real_T),
                      &i_emlrtRTEI);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (eml_setop.c) */
