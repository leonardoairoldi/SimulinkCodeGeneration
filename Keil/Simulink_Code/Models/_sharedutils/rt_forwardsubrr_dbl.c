/* Copyright 1994-2010 The MathWorks, Inc.
 *
 * File: rt_forwardsubrr_dbl.c     
 *
 * Abstract:
 *      Simulink Coder support routine which performs
 *      forward substitution: solving Lx=b
 *
 */

#include "rt_matrixlib.h"

/* Function: rt_ForwardSubstitutionRR_Dbl ======================================
 * Abstract: Forward substitution: solving Lx=b 
 *           L: Real, double
 *           b: Real, double
 *           L is a lower (or unit lower) triangular full matrix.
 *           The entries in the upper triangle are ignored.
 *           L is a NxN matrix
 *           X is a NxP matrix
 *           B is a NxP matrix
 */
void rt_ForwardSubstitutionRR_Dbl(double        *pL,
                                  const double  *pb,
                                  double        *x,
                                  int          N,
                                  int          P,
                                  const int32_t *piv,
                                  bool      unit_lower)
{  
  /* Real inputs: */
  int i, k;
  for(k=0; k<P; k++) {
    double *pLcol = pL;
    for(i=0; i<N; i++) {
      double *xj = x + k*N;
      double s = 0.0;
      double *pLrow = pLcol++;          /* access current row of L */

      {
        int j = i;
        while(j-- > 0) {
          s += *pLrow * *xj;
          pLrow += N;
          xj++;
        }
      }

      if (unit_lower) {
        *xj = pb[piv[i]] - s;
      } else {
        *xj = (pb[piv[i]] - s) / *pLrow;
      }
    }
    pb += N;
  }
}

/* [EOF] rt_forwardsubrr_dbl.c */
