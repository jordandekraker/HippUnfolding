/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "laplace_iters.h"
#include "sortIdx.h"
#include "laplace_iters_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "laplace_iters_data.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = { 70,  /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 247, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 255, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 256, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 264, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 272, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 329, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 357, /* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 364,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 524,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 526,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 554,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 436,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 444,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 451,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 498,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 467,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = { 1, /* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 322,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 324,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 247,/* lineNo */
  14,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 247,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pName */
};

/* Function Declarations */
static void merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                  *x, int32_T offset, int32_T np, int32_T nq, emxArray_int32_T
                  *iwork, emxArray_real_T *xwork);
static void merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel,
  emxArray_int32_T *iwork, emxArray_real_T *xwork);

/* Function Definitions */
static void merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                  *x, int32_T offset, int32_T np, int32_T nq, emxArray_int32_T
                  *iwork, emxArray_real_T *xwork)
{
  int32_T n;
  int32_T qend;
  int32_T p;
  int32_T iout;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq != 0) {
    n = np + nq;
    st.site = &jb_emlrtRSI;
    if ((!(1 > n)) && (n > 2147483646)) {
      b_st.site = &q_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (qend = 0; qend + 1 <= n; qend++) {
      iwork->data[qend] = idx->data[offset + qend];
      xwork->data[qend] = x->data[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[n]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[n];
        x->data[iout] = xwork->data[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          st.site = &ib_emlrtRSI;
          if ((!(p + 1 > np)) && (np > 2147483646)) {
            b_st.site = &q_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          while (p + 1 <= np) {
            idx->data[n + p] = iwork->data[p];
            x->data[n + p] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel,
  emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int32_T nPairs;
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &eb_emlrtRSI;
        merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      st.site = &gb_emlrtRSI;
      merge(&st, idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen, iwork,
            xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    st.site = &hb_emlrtRSI;
    merge(&st, idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

void sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  int32_T ib;
  int32_T m;
  int32_T n;
  int32_T b_n;
  int32_T i;
  emxArray_int32_T *iwork;
  real_T x4[4];
  int32_T idx4[4];
  emxArray_real_T *xwork;
  int32_T nNaNs;
  boolean_T overflow;
  int32_T k;
  int32_T wOffset;
  int8_T perm[4];
  int32_T nNonNaN;
  int32_T i4;
  int32_T nBlocks;
  int32_T bLen2;
  int32_T nPairs;
  int32_T b_iwork[256];
  real_T b_xwork[256];
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  ib = x->size[0];
  m = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity(sp, (emxArray__common *)idx, m, sizeof(int32_T),
                    &g_emlrtRTEI);
  for (m = 0; m < ib; m++) {
    idx->data[m] = 0;
  }

  st.site = &r_emlrtRSI;
  n = x->size[0];
  b_st.site = &s_emlrtRSI;
  b_n = x->size[0];
  for (i = 0; i < 4; i++) {
    x4[i] = 0.0;
    idx4[i] = 0;
  }

  emxInit_int32_T(&b_st, &iwork, 1, &r_emlrtRTEI, true);
  m = iwork->size[0];
  iwork->size[0] = ib;
  emxEnsureCapacity(&b_st, (emxArray__common *)iwork, m, sizeof(int32_T),
                    &p_emlrtRTEI);
  i = iwork->size[0];
  m = iwork->size[0];
  iwork->size[0] = i;
  emxEnsureCapacity(&b_st, (emxArray__common *)iwork, m, sizeof(int32_T),
                    &g_emlrtRTEI);
  for (m = 0; m < i; m++) {
    iwork->data[m] = 0;
  }

  emxInit_real_T1(&b_st, &xwork, 1, &s_emlrtRTEI, true);
  i = x->size[0];
  m = xwork->size[0];
  xwork->size[0] = i;
  emxEnsureCapacity(&b_st, (emxArray__common *)xwork, m, sizeof(real_T),
                    &q_emlrtRTEI);
  i = xwork->size[0];
  m = xwork->size[0];
  xwork->size[0] = i;
  emxEnsureCapacity(&b_st, (emxArray__common *)xwork, m, sizeof(real_T),
                    &g_emlrtRTEI);
  for (m = 0; m < i; m++) {
    xwork->data[m] = 0.0;
  }

  nNaNs = 0;
  ib = 0;
  c_st.site = &x_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &q_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= b_n; k++) {
    if (muDoubleScalarIsNaN(x->data[k])) {
      idx->data[(b_n - nNaNs) - 1] = k + 1;
      xwork->data[(b_n - nNaNs) - 1] = x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = x->data[k];
      if (ib == 4) {
        i = k - nNaNs;
        if (x4[0] <= x4[1]) {
          ib = 1;
          m = 2;
        } else {
          ib = 2;
          m = 1;
        }

        if (x4[2] <= x4[3]) {
          wOffset = 3;
          i4 = 4;
        } else {
          wOffset = 4;
          i4 = 3;
        }

        if (x4[ib - 1] <= x4[wOffset - 1]) {
          if (x4[m - 1] <= x4[wOffset - 1]) {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else if (x4[m - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)m;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)m;
          }
        } else if (x4[ib - 1] <= x4[i4 - 1]) {
          if (x4[m - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)wOffset;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)m;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)wOffset;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)m;
          }
        } else {
          perm[0] = (int8_T)wOffset;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)ib;
          perm[3] = (int8_T)m;
        }

        idx->data[i - 3] = idx4[perm[0] - 1];
        idx->data[i - 2] = idx4[perm[1] - 1];
        idx->data[i - 1] = idx4[perm[2] - 1];
        idx->data[i] = idx4[perm[3] - 1];
        x->data[i - 3] = x4[perm[0] - 1];
        x->data[i - 2] = x4[perm[1] - 1];
        x->data[i - 1] = x4[perm[2] - 1];
        x->data[i] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = (b_n - nNaNs) - 1;
  if (ib > 0) {
    for (i = 0; i < 4; i++) {
      perm[i] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    c_st.site = &y_emlrtRSI;
    if (ib > 2147483646) {
      d_st.site = &q_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= ib; k++) {
      idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  m = (nNaNs >> 1) + 1;
  c_st.site = &ab_emlrtRSI;
  for (k = 1; k < m; k++) {
    i = idx->data[wOffset + k];
    idx->data[wOffset + k] = idx->data[b_n - k];
    idx->data[b_n - k] = i;
    x->data[wOffset + k] = xwork->data[b_n - k];
    x->data[b_n - k] = xwork->data[wOffset + k];
  }

  if ((nNaNs & 1) != 0) {
    x->data[wOffset + m] = xwork->data[wOffset + m];
  }

  nNonNaN = n - nNaNs;
  i = 2;
  if (nNonNaN > 1) {
    if (n >= 256) {
      nBlocks = nNonNaN >> 8;
      if (nBlocks > 0) {
        b_st.site = &t_emlrtRSI;
        for (i4 = 1; i4 <= nBlocks; i4++) {
          b_st.site = &u_emlrtRSI;
          nNaNs = (i4 - 1) << 8;
          for (b_n = 0; b_n < 6; b_n++) {
            n = 1 << (b_n + 2);
            bLen2 = n << 1;
            nPairs = 256 >> (b_n + 3);
            c_st.site = &bb_emlrtRSI;
            for (k = 1; k <= nPairs; k++) {
              ib = nNaNs + (k - 1) * bLen2;
              c_st.site = &cb_emlrtRSI;
              for (i = 0; i + 1 <= bLen2; i++) {
                b_iwork[i] = idx->data[ib + i];
                b_xwork[i] = x->data[ib + i];
              }

              wOffset = 0;
              m = n;
              i = ib - 1;
              do {
                exitg1 = 0;
                i++;
                if (b_xwork[wOffset] <= b_xwork[m]) {
                  idx->data[i] = b_iwork[wOffset];
                  x->data[i] = b_xwork[wOffset];
                  if (wOffset + 1 < n) {
                    wOffset++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[i] = b_iwork[m];
                  x->data[i] = b_xwork[m];
                  if (m + 1 < bLen2) {
                    m++;
                  } else {
                    i = (i - wOffset) + 1;
                    c_st.site = &db_emlrtRSI;
                    while (wOffset + 1 <= n) {
                      idx->data[i + wOffset] = b_iwork[wOffset];
                      x->data[i + wOffset] = b_xwork[wOffset];
                      wOffset++;
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        i = nBlocks << 8;
        ib = nNonNaN - i;
        if (ib > 0) {
          b_st.site = &v_emlrtRSI;
          merge_block(&b_st, idx, x, i, ib, 2, iwork, xwork);
        }

        i = 8;
      }
    }

    b_st.site = &w_emlrtRSI;
    merge_block(&b_st, idx, x, 0, nNonNaN, i, iwork, xwork);
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sortIdx.c) */
