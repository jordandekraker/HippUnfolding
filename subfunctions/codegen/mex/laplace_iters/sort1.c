/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "laplace_iters.h"
#include "sort1.h"
#include "laplace_iters_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sortIdx.h"
#include "laplace_iters_data.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = { 50,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 71,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 74,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 76,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 79,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 82,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 84,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 1, /* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "sort",                              /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sort.m"/* pName */
};

/* Function Definitions */
void sort(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T dim;
  int32_T i7;
  emxArray_real_T *vwork;
  int32_T j;
  int32_T vstride;
  int32_T k;
  emxArray_int32_T *oc_emlrtRSI;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  st.site = &i_emlrtRSI;
  if (dim <= 1) {
    i7 = x->size[0];
  } else {
    i7 = 1;
  }

  emxInit_real_T2(sp, &vwork, 1, &o_emlrtRTEI, true);
  j = vwork->size[0];
  vwork->size[0] = i7;
  emxEnsureCapacity(sp, (emxArray__common *)vwork, j, sizeof(real_T),
                    &f_emlrtRTEI);
  st.site = &j_emlrtRSI;
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  st.site = &k_emlrtRSI;
  st.site = &l_emlrtRSI;
  if ((!(1 > vstride)) && (vstride > 2147483646)) {
    b_st.site = &q_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  j = 0;
  emxInit_int32_T1(sp, &oc_emlrtRSI, 1, &f_emlrtRTEI, true);
  while (j + 1 <= vstride) {
    st.site = &m_emlrtRSI;
    if ((!(1 > i7)) && (i7 > 2147483646)) {
      b_st.site = &q_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k + 1 <= i7; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    st.site = &n_emlrtRSI;
    sortIdx(&st, vwork, oc_emlrtRSI);
    st.site = &o_emlrtRSI;
    for (k = 0; k + 1 <= i7; k++) {
      x->data[j + k * vstride] = vwork->data[k];
    }

    j++;
  }

  emxFree_int32_T(&oc_emlrtRSI);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sort1.c) */
