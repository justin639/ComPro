#include "pch.h"
#include "math.h"
#include "Matrix.h"

// Funtions =================================================================
// I-Matrix
void mat_i_get(T3DMatrix& tMat){
    tMat._11 = 1.0;
}
// Inverse
void mat_inv_get(T3DMatrix& tMat){

}
// Mult Mat
void mat_mult_mat(T3DMatrix& tMat1, T3DMatrix& tMat2, T3DMatrix& tOutMat){

}
// Mult Mat x Vect
void mat_mult_vect(T3DMatrix& tMat, T_3D_Vector& tVec, T3DMatrix& tOutVec){

}
// Copy Mat
void mat_copy(T3DMatrix& tSMat, T3DMatrix& tDMat){

}
// Trasnlate
void mat_traslate(double dx, double dy, double dz, T3DMatrix& tOutMat){

}
// Rotation (X axis = 0)
// nAxis : _MAT_AXIS_X : 0, _MAT_AXIS_Y : 1, _MAT_AXIS_Z : 2 
void mat_rotate( int nAxis, T3DMatrix& tOutMat){

}

