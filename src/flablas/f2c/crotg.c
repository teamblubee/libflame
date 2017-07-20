/* crotg.f -- translated by f2c (version 19991025). You must link the resulting object file with the libraries: -lf2c -lm (in that order) */
#include "FLA_f2c.h"
/* Subroutine */
int crotg_(complex *ca, complex *cb, real *c__, complex *s)
{
    /* System generated locals */
    real r__1, r__2;
    complex q__1, q__2, q__3;
    /* Builtin functions */
    double c_f2c_abs(complex *), sqrt(doublereal);
    void r_cnjg(complex *, complex *);
    /* Local variables */
    real norm;
    complex alpha;
    real scale;
    if (c_f2c_abs(ca) != 0.f)
    {
        goto L10;
    }
    *c__ = 0.f;
    s->r = 1.f, s->i = 0.f;
    ca->r = cb->r, ca->i = cb->i;
    goto L20;
L10:
    scale = c_f2c_abs(ca) + c_f2c_abs(cb);
    q__1.r = ca->r / scale, q__1.i = ca->i / scale;
    /* Computing 2nd power */
    r__1 = c_f2c_abs(&q__1);
    q__2.r = cb->r / scale, q__2.i = cb->i / scale;
    /* Computing 2nd power */
    r__2 = c_f2c_abs(&q__2);
    norm = scale * sqrt(r__1 * r__1 + r__2 * r__2);
    r__1 = c_f2c_abs(ca);
    q__1.r = ca->r / r__1, q__1.i = ca->i / r__1;
    alpha.r = q__1.r, alpha.i = q__1.i;
    *c__ = c_f2c_abs(ca) / norm;
    r_cnjg(&q__3, cb);
    q__2.r = alpha.r * q__3.r - alpha.i * q__3.i, q__2.i = alpha.r * q__3.i + alpha.i * q__3.r;
    q__1.r = q__2.r / norm, q__1.i = q__2.i / norm;
    s->r = q__1.r, s->i = q__1.i;
    q__1.r = norm * alpha.r, q__1.i = norm * alpha.i;
    ca->r = q__1.r, ca->i = q__1.i;
L20:
    return 0;
}
/* crotg_ */

