#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main()
{
    T_3D_Vector tVec1, tVec2;
    T3DMatrix tIMat;

    vec_3d_set(tVec1, 1.0, 1.0, 1.0);
    vec_3d_set(tVec2, -1.0, -1.0, 1.0);

    vec_3d_norm(tVec1);

    mat_i_get(tIMat);

    printf("Vect1( %lf, %lf, %lf )\n", tVec1.x, tVec1.y, tVec1.z);
    printf("Matrix %f\n", tIMat._11);
    printf("%d\n", TRUE);
    printf("About the path need to look where the lib file is.\n");

    return 0;
}
