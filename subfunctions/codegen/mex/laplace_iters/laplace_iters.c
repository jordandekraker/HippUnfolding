/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * laplace_iters.c
 *
 * Code generation for function 'laplace_iters'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "laplace_iters.h"
#include "laplace_iters_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "imfilter.h"
#include "eml_setop.h"
#include "sort1.h"
#include "laplace_iters_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 21,    /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 26,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 33,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 37,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 43,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 49,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 31,  /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 19, /* lineNo */
  "setdiff",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/setdiff.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 70, /* lineNo */
  "eml_setop",                         /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/private/eml_setop.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 16, /* lineNo */
  "abs",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 67, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 7,  /* lineNo */
  "nansum",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/nansum.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 74, /* lineNo */
  "nan_sum_or_mean",                   /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 140,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  30,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 21,/* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 24,/* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 121,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "nan_sum_or_mean",                   /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo w_emlrtRTEI = { 30,/* lineNo */
  27,                                  /* colNo */
  "nan_sum_or_mean",                   /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 13,/* lineNo */
  15,                                  /* colNo */
  "rdivide",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/rdivide.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  43,                                  /* lineNo */
  37,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  18,                                  /* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 23,    /* lineNo */
  23,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 23,  /* lineNo */
  23,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 17,  /* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 17,  /* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 18,  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 19,  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 20,  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 22,  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 24,  /* lineNo */
  29,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  21,                                  /* colNo */
  "insulate_correction",               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  41,                                  /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  51,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "nan_sum_or_mean",                   /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/stats/eml/private/nan_sum_or_mean.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  17,                                  /* colNo */
  "iter_change",                       /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  20,                                  /* colNo */
  "iter_change",                       /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/home/jordandekraker/matlab/Laplace_unfolding/subfunctions/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void laplace_iters(const emlrtStack *sp, const emxArray_real_T *fg, const
                   emxArray_real_T *source, const emxArray_real_T *sink, const
                   emxArray_real_T *init, real_T maxiters, const real_T sz[3],
                   emxArray_real_T *LP, emxArray_real_T *iter_change)
{
  real_T d;
  emxArray_real_T *elems;
  int32_T i0;
  int32_T n;
  emxArray_int32_T *ia;
  int32_T ixstart;
  int32_T ix;
  int32_T b_LP;
  emxArray_real_T *x;
  emxArray_real_T *bg;
  emxArray_real_T *c;
  int32_T ib_size[1];
  emxArray_real_T *insulate_correction;
  uint32_T iters;
  emxArray_real_T *velup;
  emxArray_real_T *varargin_1;
  boolean_T exitg1;
  boolean_T overflow;
  int32_T b_varargin_1[3];
  boolean_T p;
  int32_T varargin_2[3];
  boolean_T exitg2;
  uint32_T x_idx_0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* filter set-up (26 nearest neighbours) */
  /*  filter set-up (6 NN) (safer, especially in cases of coronal non-oblique */
  /*  where dark band is more likely to 'leak' across diagonals */
  /*  hl = strel('sphere',1); */
  /*  hl = double(hl.Neighborhood); */
  d = sz[0] * sz[1] * sz[2];
  emxInit_real_T(sp, &elems, 2, &b_emlrtRTEI, true);
  if (muDoubleScalarIsNaN(d)) {
    i0 = elems->size[0] * elems->size[1];
    elems->size[0] = 1;
    elems->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)elems, i0, sizeof(real_T),
                      &emlrtRTEI);
    elems->data[0] = rtNaN;
  } else if (d < 1.0) {
    i0 = elems->size[0] * elems->size[1];
    elems->size[0] = 1;
    elems->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)elems, i0, sizeof(real_T),
                      &emlrtRTEI);
  } else if (muDoubleScalarIsInf(d) && (1.0 == d)) {
    i0 = elems->size[0] * elems->size[1];
    elems->size[0] = 1;
    elems->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)elems, i0, sizeof(real_T),
                      &emlrtRTEI);
    elems->data[0] = rtNaN;
  } else {
    i0 = elems->size[0] * elems->size[1];
    elems->size[0] = 1;
    elems->size[1] = (int32_T)muDoubleScalarFloor(d - 1.0) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)elems, i0, sizeof(real_T),
                      &emlrtRTEI);
    n = (int32_T)muDoubleScalarFloor(d - 1.0);
    for (i0 = 0; i0 <= n; i0++) {
      elems->data[elems->size[0] * i0] = 1.0 + (real_T)i0;
    }
  }

  /* set up all requisite variables */
  for (i0 = 0; i0 < 3; i0++) {
    if (!(sz[i0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(sz[i0], &c_emlrtDCI, sp);
    }

    if (sz[i0] != (int32_T)muDoubleScalarFloor(sz[i0])) {
      emlrtIntegerCheckR2012b(sz[i0], &d_emlrtDCI, sp);
    }
  }

  i0 = LP->size[0] * LP->size[1] * LP->size[2];
  LP->size[0] = (int32_T)sz[0];
  LP->size[1] = (int32_T)sz[1];
  LP->size[2] = (int32_T)sz[2];
  emxEnsureCapacity(sp, (emxArray__common *)LP, i0, sizeof(real_T), &emlrtRTEI);
  n = (int32_T)sz[0] * (int32_T)sz[1] * (int32_T)sz[2];
  for (i0 = 0; i0 < n; i0++) {
    LP->data[i0] = rtNaN;
  }

  emxInit_int32_T(sp, &ia, 1, &emlrtRTEI, true);
  ixstart = (int32_T)sz[0] * (int32_T)sz[1] * (int32_T)sz[2];
  i0 = ia->size[0];
  ia->size[0] = fg->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T), &emlrtRTEI);
  n = fg->size[0];
  for (i0 = 0; i0 < n; i0++) {
    d = fg->data[i0];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &e_emlrtDCI, sp);
    }

    ix = (int32_T)d;
    if (!((ix >= 1) && (ix <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, ixstart, &b_emlrtBCI, sp);
    }

    ia->data[i0] = ix;
  }

  i0 = ia->size[0];
  ix = init->size[0] * init->size[1];
  if (i0 != ix) {
    emlrtSizeEqCheck1DR2012b(i0, ix, &b_emlrtECI, sp);
  }

  n = ia->size[0];
  for (i0 = 0; i0 < n; i0++) {
    LP->data[ia->data[i0] - 1] = init->data[i0];
  }

  b_LP = LP->size[0] * LP->size[1] * LP->size[2];
  i0 = ia->size[0];
  ia->size[0] = source->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T), &emlrtRTEI);
  n = source->size[0];
  for (i0 = 0; i0 < n; i0++) {
    d = source->data[i0];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, sp);
    }

    ix = (int32_T)d;
    if (!((ix >= 1) && (ix <= b_LP))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &c_emlrtBCI, sp);
    }

    ia->data[i0] = ix;
  }

  n = ia->size[0];
  for (i0 = 0; i0 < n; i0++) {
    LP->data[ia->data[i0] - 1] = 0.0;
  }

  b_LP = LP->size[0] * LP->size[1] * LP->size[2];
  i0 = ia->size[0];
  ia->size[0] = sink->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T), &emlrtRTEI);
  n = sink->size[0];
  for (i0 = 0; i0 < n; i0++) {
    d = sink->data[i0];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &g_emlrtDCI, sp);
    }

    ix = (int32_T)d;
    if (!((ix >= 1) && (ix <= b_LP))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &d_emlrtBCI, sp);
    }

    ia->data[i0] = ix;
  }

  n = ia->size[0];
  for (i0 = 0; i0 < n; i0++) {
    LP->data[ia->data[i0] - 1] = 1.0;
  }

  emxInit_real_T1(sp, &x, 1, &emlrtRTEI, true);
  st.site = &emlrtRSI;
  i0 = x->size[0];
  x->size[0] = (fg->size[0] + source->size[0]) + sink->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i0, sizeof(real_T), &emlrtRTEI);
  n = fg->size[0];
  for (i0 = 0; i0 < n; i0++) {
    x->data[i0] = fg->data[i0];
  }

  n = source->size[0];
  for (i0 = 0; i0 < n; i0++) {
    x->data[i0 + fg->size[0]] = source->data[i0];
  }

  n = sink->size[0];
  for (i0 = 0; i0 < n; i0++) {
    x->data[(i0 + fg->size[0]) + source->size[0]] = sink->data[i0];
  }

  emxInit_real_T1(&st, &bg, 1, &c_emlrtRTEI, true);
  emxInit_real_T(&st, &c, 2, &emlrtRTEI, true);
  b_st.site = &g_emlrtRSI;
  sort(&b_st, x);
  st.site = &emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  do_vectors(&c_st, elems, x, c, ia, ib_size);
  i0 = bg->size[0];
  bg->size[0] = c->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)bg, i0, sizeof(real_T), &emlrtRTEI);
  n = c->size[1];
  emxFree_real_T(&elems);
  for (i0 = 0; i0 < n; i0++) {
    bg->data[i0] = c->data[c->size[0] * i0];
  }

  emxFree_real_T(&c);

  /*  bg in indices */
  b_LP = LP->size[0] * LP->size[1] * LP->size[2];
  i0 = ia->size[0];
  ia->size[0] = bg->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T), &emlrtRTEI);
  n = bg->size[0];
  for (i0 = 0; i0 < n; i0++) {
    d = bg->data[i0];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &h_emlrtDCI, sp);
    }

    ix = (int32_T)d;
    if (!((ix >= 1) && (ix <= b_LP))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &e_emlrtBCI, sp);
    }

    ia->data[i0] = ix;
  }

  n = ia->size[0];
  for (i0 = 0; i0 < n; i0++) {
    LP->data[ia->data[i0] - 1] = 0.0;
  }

  /* must be insulated after filtering */
  i0 = iter_change->size[0] * iter_change->size[1];
  iter_change->size[0] = 1;
  if (!(maxiters >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxiters, &b_emlrtDCI, sp);
  }

  if (maxiters != (int32_T)muDoubleScalarFloor(maxiters)) {
    emlrtIntegerCheckR2012b(maxiters, &emlrtDCI, sp);
  }

  iter_change->size[1] = (int32_T)maxiters;
  emxEnsureCapacity(sp, (emxArray__common *)iter_change, i0, sizeof(real_T),
                    &emlrtRTEI);
  if (!(maxiters >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxiters, &b_emlrtDCI, sp);
  }

  if (maxiters != (int32_T)muDoubleScalarFloor(maxiters)) {
    emlrtIntegerCheckR2012b(maxiters, &emlrtDCI, sp);
  }

  n = (int32_T)maxiters;
  for (i0 = 0; i0 < n; i0++) {
    iter_change->data[i0] = 0.0;
  }

  for (i0 = 0; i0 < 3; i0++) {
    if (sz[i0] != (int32_T)muDoubleScalarFloor(sz[i0])) {
      emlrtIntegerCheckR2012b(sz[i0], &i_emlrtDCI, sp);
    }
  }

  emxInit_real_T2(sp, &insulate_correction, 3, &d_emlrtRTEI, true);
  i0 = insulate_correction->size[0] * insulate_correction->size[1] *
    insulate_correction->size[2];
  insulate_correction->size[0] = (int32_T)sz[0];
  insulate_correction->size[1] = (int32_T)sz[1];
  insulate_correction->size[2] = (int32_T)sz[2];
  emxEnsureCapacity(sp, (emxArray__common *)insulate_correction, i0, sizeof
                    (real_T), &emlrtRTEI);
  n = (int32_T)sz[0] * (int32_T)sz[1] * (int32_T)sz[2];
  for (i0 = 0; i0 < n; i0++) {
    insulate_correction->data[i0] = 0.0;
  }

  ixstart = (int32_T)sz[0] * (int32_T)sz[1] * (int32_T)sz[2];
  i0 = ia->size[0];
  ia->size[0] = (fg->size[0] + source->size[0]) + sink->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T), &emlrtRTEI);
  n = fg->size[0];
  for (i0 = 0; i0 < n; i0++) {
    ix = (int32_T)fg->data[i0];
    if (!((ix >= 1) && (ix <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, ixstart, &f_emlrtBCI, sp);
    }

    ia->data[i0] = ix;
  }

  n = source->size[0];
  for (i0 = 0; i0 < n; i0++) {
    ix = (int32_T)source->data[i0];
    if (!((ix >= 1) && (ix <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, ixstart, &f_emlrtBCI, sp);
    }

    ia->data[i0 + fg->size[0]] = ix;
  }

  n = sink->size[0];
  for (i0 = 0; i0 < n; i0++) {
    ix = (int32_T)sink->data[i0];
    if (!((ix >= 1) && (ix <= ixstart))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, ixstart, &f_emlrtBCI, sp);
    }

    ia->data[(i0 + fg->size[0]) + source->size[0]] = ix;
  }

  n = ia->size[0];
  for (i0 = 0; i0 < n; i0++) {
    insulate_correction->data[ia->data[i0] - 1] = 1.0;
  }

  st.site = &b_emlrtRSI;
  imfilter(&st, insulate_correction);

  /*  apply filter */
  iters = 0U;
  emxInit_real_T2(sp, &velup, 3, &e_emlrtRTEI, true);
  emxInit_real_T1(sp, &varargin_1, 1, &emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (iters < maxiters)) {
    /* max iterations */
    iters++;
    i0 = velup->size[0] * velup->size[1] * velup->size[2];
    velup->size[0] = LP->size[0];
    velup->size[1] = LP->size[1];
    velup->size[2] = LP->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)velup, i0, sizeof(real_T),
                      &emlrtRTEI);
    n = LP->size[0] * LP->size[1] * LP->size[2];
    for (i0 = 0; i0 < n; i0++) {
      velup->data[i0] = LP->data[i0];
    }

    st.site = &c_emlrtRSI;
    imfilter(&st, velup);

    /* apply averaging filter */
    /* insulate the grey matter so gradient doesn't pass between folds - */
    /* inspired by ndnanfilter */
    st.site = &d_emlrtRSI;
    for (i0 = 0; i0 < 3; i0++) {
      b_varargin_1[i0] = velup->size[i0];
      varargin_2[i0] = insulate_correction->size[i0];
    }

    overflow = false;
    p = true;
    ixstart = 0;
    exitg2 = false;
    while ((!exitg2) && (ixstart < 3)) {
      if (!(b_varargin_1[ixstart] == varargin_2[ixstart])) {
        p = false;
        exitg2 = true;
      } else {
        ixstart++;
      }
    }

    if (p) {
      overflow = true;
    }

    if (!overflow) {
      emlrtErrorWithMessageIdR2012b(&st, &x_emlrtRTEI, "MATLAB:dimagree", 0);
    }

    i0 = velup->size[0] * velup->size[1] * velup->size[2];
    emxEnsureCapacity(&st, (emxArray__common *)velup, i0, sizeof(real_T),
                      &emlrtRTEI);
    b_LP = velup->size[0];
    ixstart = velup->size[1];
    n = velup->size[2];
    n *= b_LP * ixstart;
    for (i0 = 0; i0 < n; i0++) {
      velup->data[i0] /= insulate_correction->data[i0];
    }

    b_LP = velup->size[0] * velup->size[1] * velup->size[2];
    i0 = ia->size[0];
    ia->size[0] = bg->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T),
                      &emlrtRTEI);
    n = bg->size[0];
    for (i0 = 0; i0 < n; i0++) {
      ix = (int32_T)bg->data[i0];
      if (!((ix >= 1) && (ix <= b_LP))) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &g_emlrtBCI, sp);
      }

      ia->data[i0] = ix;
    }

    n = ia->size[0];
    for (i0 = 0; i0 < n; i0++) {
      velup->data[ia->data[i0] - 1] = 0.0;
    }

    b_LP = velup->size[0] * velup->size[1] * velup->size[2];
    i0 = ia->size[0];
    ia->size[0] = source->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T),
                      &emlrtRTEI);
    n = source->size[0];
    for (i0 = 0; i0 < n; i0++) {
      ix = (int32_T)source->data[i0];
      if (!((ix >= 1) && (ix <= b_LP))) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &h_emlrtBCI, sp);
      }

      ia->data[i0] = ix;
    }

    n = ia->size[0];
    for (i0 = 0; i0 < n; i0++) {
      velup->data[ia->data[i0] - 1] = 0.0;
    }

    b_LP = velup->size[0] * velup->size[1] * velup->size[2];
    i0 = ia->size[0];
    ia->size[0] = sink->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T),
                      &emlrtRTEI);
    n = sink->size[0];
    for (i0 = 0; i0 < n; i0++) {
      ix = (int32_T)sink->data[i0];
      if (!((ix >= 1) && (ix <= b_LP))) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &i_emlrtBCI, sp);
      }

      ia->data[i0] = ix;
    }

    n = ia->size[0];
    for (i0 = 0; i0 < n; i0++) {
      velup->data[ia->data[i0] - 1] = 1.0;
    }

    /* stopping condition */
    st.site = &e_emlrtRSI;
    indexShapeCheck(&st, *(int32_T (*)[3])LP->size, fg->size[0]);
    st.site = &e_emlrtRSI;
    indexShapeCheck(&st, *(int32_T (*)[3])velup->size, fg->size[0]);
    b_LP = LP->size[0] * LP->size[1] * LP->size[2];
    n = fg->size[0];
    for (i0 = 0; i0 < n; i0++) {
      ix = (int32_T)fg->data[i0];
      if (!((ix >= 1) && (ix <= b_LP))) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &j_emlrtBCI, sp);
      }
    }

    b_LP = velup->size[0] * velup->size[1] * velup->size[2];
    n = fg->size[0];
    for (i0 = 0; i0 < n; i0++) {
      ix = (int32_T)fg->data[i0];
      if (!((ix >= 1) && (ix <= b_LP))) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &k_emlrtBCI, sp);
      }
    }

    i0 = fg->size[0];
    ix = fg->size[0];
    if (i0 != ix) {
      emlrtSizeEqCheck1DR2012b(i0, ix, &emlrtECI, sp);
    }

    st.site = &e_emlrtRSI;
    i0 = x->size[0];
    x->size[0] = fg->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)x, i0, sizeof(real_T), &emlrtRTEI);
    n = fg->size[0];
    for (i0 = 0; i0 < n; i0++) {
      x->data[i0] = LP->data[(int32_T)fg->data[i0] - 1] - velup->data[(int32_T)
        fg->data[i0] - 1];
    }

    b_st.site = &ec_emlrtRSI;
    x_idx_0 = (uint32_T)x->size[0];
    i0 = varargin_1->size[0];
    varargin_1->size[0] = (int32_T)x_idx_0;
    emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, i0, sizeof(real_T),
                      &emlrtRTEI);
    c_st.site = &fc_emlrtRSI;
    overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (ixstart = 0; ixstart + 1 <= x->size[0]; ixstart++) {
      varargin_1->data[ixstart] = muDoubleScalarAbs(x->data[ixstart]);
    }

    st.site = &e_emlrtRSI;
    b_st.site = &gc_emlrtRSI;
    if ((varargin_1->size[0] == 1) || (varargin_1->size[0] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (!overflow) {
      emlrtErrorWithMessageIdR2012b(&b_st, &w_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (varargin_1->size[0] == 0) {
      d = 0.0;
    } else {
      d = 0.0;
      c_st.site = &hc_emlrtRSI;
      overflow = (varargin_1->size[0] > 2147483646);
      if (overflow) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (ixstart = 1; ixstart <= varargin_1->size[0]; ixstart++) {
        i0 = varargin_1->size[0];
        if (!((ixstart >= 1) && (ixstart <= i0))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, &emlrtBCI, &b_st);
        }

        if (!muDoubleScalarIsNaN(varargin_1->data[ixstart - 1])) {
          i0 = varargin_1->size[0];
          if (!((ixstart >= 1) && (ixstart <= i0))) {
            emlrtDynamicBoundsCheckR2012b(ixstart, 1, i0, &l_emlrtBCI, &b_st);
          }

          d += varargin_1->data[ixstart - 1];
        }
      }
    }

    i0 = iter_change->size[1];
    ix = (int32_T)iters;
    if (!((ix >= 1) && (ix <= i0))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i0, &m_emlrtBCI, sp);
    }

    iter_change->data[ix - 1] = d;

    /* compute change from last iteration */
    i0 = LP->size[0] * LP->size[1] * LP->size[2];
    LP->size[0] = velup->size[0];
    LP->size[1] = velup->size[1];
    LP->size[2] = velup->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)LP, i0, sizeof(real_T), &emlrtRTEI);
    n = velup->size[0] * velup->size[1] * velup->size[2];
    for (i0 = 0; i0 < n; i0++) {
      LP->data[i0] = velup->data[i0];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }

    i0 = iter_change->size[1];
    ix = (int32_T)iters;
    if (!((ix >= 1) && (ix <= i0))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, i0, &n_emlrtBCI, sp);
    }

    if (iter_change->data[ix - 1] < 0.001) {
      exitg1 = true;
    }
  }

  emxFree_real_T(&varargin_1);
  emxFree_real_T(&x);
  emxFree_real_T(&velup);
  emxFree_real_T(&insulate_correction);
  st.site = &f_emlrtRSI;
  b_st.site = &ic_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  if ((LP->size[0] * LP->size[1] * LP->size[2] == 1) || (LP->size[0] * LP->size
       [1] * LP->size[2] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (!(LP->size[0] * LP->size[1] * LP->size[2] > 0)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &u_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &kc_emlrtRSI;
  ixstart = 1;
  n = LP->size[0] * LP->size[1] * LP->size[2];
  d = LP->data[0];
  if (LP->size[0] * LP->size[1] * LP->size[2] > 1) {
    if (muDoubleScalarIsNaN(LP->data[0])) {
      e_st.site = &mc_emlrtRSI;
      overflow = ((!(2 > LP->size[0] * LP->size[1] * LP->size[2])) && (LP->size
        [0] * LP->size[1] * LP->size[2] > 2147483646));
      if (overflow) {
        f_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(LP->data[ix - 1])) {
          d = LP->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < LP->size[0] * LP->size[1] * LP->size[2]) {
      e_st.site = &lc_emlrtRSI;
      overflow = ((!(ixstart + 1 > LP->size[0] * LP->size[1] * LP->size[2])) &&
                  (LP->size[0] * LP->size[1] * LP->size[2] > 2147483646));
      if (overflow) {
        f_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (ixstart + 1 <= n) {
        if (LP->data[ixstart] > d) {
          d = LP->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  i0 = LP->size[0] * LP->size[1] * LP->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)LP, i0, sizeof(real_T), &emlrtRTEI);
  b_LP = LP->size[0];
  ixstart = LP->size[1];
  n = LP->size[2];
  n *= b_LP * ixstart;
  for (i0 = 0; i0 < n; i0++) {
    LP->data[i0] /= d;
  }

  b_LP = LP->size[0] * LP->size[1] * LP->size[2];
  i0 = ia->size[0];
  ia->size[0] = (source->size[0] + sink->size[0]) + bg->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ia, i0, sizeof(int32_T), &emlrtRTEI);
  n = source->size[0];
  for (i0 = 0; i0 < n; i0++) {
    ix = (int32_T)source->data[i0];
    if (!((ix >= 1) && (ix <= b_LP))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &o_emlrtBCI, sp);
    }

    ia->data[i0] = ix;
  }

  n = sink->size[0];
  for (i0 = 0; i0 < n; i0++) {
    ix = (int32_T)sink->data[i0];
    if (!((ix >= 1) && (ix <= b_LP))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &o_emlrtBCI, sp);
    }

    ia->data[i0 + source->size[0]] = ix;
  }

  n = bg->size[0];
  for (i0 = 0; i0 < n; i0++) {
    ix = (int32_T)bg->data[i0];
    if (!((ix >= 1) && (ix <= b_LP))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, b_LP, &o_emlrtBCI, sp);
    }

    ia->data[(i0 + source->size[0]) + sink->size[0]] = ix;
  }

  emxFree_real_T(&bg);
  n = ia->size[0];
  for (i0 = 0; i0 < n; i0++) {
    LP->data[ia->data[i0] - 1] = rtNaN;
  }

  emxFree_int32_T(&ia);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (laplace_iters.c) */
