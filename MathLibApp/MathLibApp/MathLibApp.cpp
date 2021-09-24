#include <iostream>
#include "Vector.h"

int main()
{
    T_3D_Vector tVec1, tVec2;

    vec_3d_set(tVec1, 1.0, 1.0, 1.0);
    vec_3d_set(tVec2, -1.0, -1.0, 1.0);

    vec_3d_norm(tVec1);

    printf("Vect1( %lf, %lf, %lf )", tVec1.x, tVec1.y, tVec1.z);

    printf("%d\n", TRUE);
    printf("Hello World\n");

    return 0;
}
