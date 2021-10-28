#include "pch.h"
#include "math.h"
#include "windows.h"
#include "Vector.h"
#include "Matrix.h"
#include "Assignment1.h"

// Funtions =================================================================
// Zero Matrix


void mat_Zero(T3DMatrix &tMat)
{
    ZeroMemory(&tMat, sizeof(T3DMatrix));
}
// I-Matrix
void mat_Ident(T3DMatrix &tMat)
{
    mat_Zero(tMat);
    tMat._11 = tMat._22 = tMat._33 = tMat._44 = 1.0f;
}
// Inverse
BOOL mat_Inv(T3DMatrix &tInv, T3DMatrix &tMat)
{
    double dDivide = (tMat._11 * (tMat._22 * tMat._33 - tMat._23 * tMat._32) -
                      tMat._12 * (tMat._21 * tMat._33 - tMat._23 * tMat._31) +
                      tMat._13 * (tMat._21 * tMat._32 - tMat._22 * tMat._31));
    if (dDivide < _EPS)
        return FALSE;
    double DetInv = 1.0f / dDivide;

    tInv._11 = DetInv * (tMat._22 * tMat._33 - tMat._23 * tMat._32);
    tInv._12 = -DetInv * (tMat._12 * tMat._33 - tMat._13 * tMat._32);
    tInv._13 = DetInv * (tMat._12 * tMat._23 - tMat._13 * tMat._22);
    tInv._14 = -(tMat._14 * tMat._11 + tMat._24 * tMat._21 + tMat._34 * tMat._31);

    tInv._21 = -DetInv * (tMat._21 * tMat._33 - tMat._23 * tMat._31);
    tInv._22 = DetInv * (tMat._11 * tMat._33 - tMat._13 * tMat._31);
    tInv._23 = -DetInv * (tMat._11 * tMat._23 - tMat._13 * tMat._21);
    tInv._24 = -(tMat._14 * tMat._12 + tMat._24 * tMat._22 + tMat._34 * tMat._32);

    tInv._31 = DetInv * (tMat._21 * tMat._32 - tMat._22 * tMat._31);
    tInv._32 = -DetInv * (tMat._11 * tMat._32 - tMat._12 * tMat._31);
    tInv._33 = DetInv * (tMat._11 * tMat._22 - tMat._12 * tMat._21);
    tInv._34 = -(tMat._14 * tMat._13 + tMat._24 * tMat._23 + tMat._34 * tMat._33);

    tInv._41 = 0.0f;
    tInv._42 = 0.0f;
    tInv._43 = 0.0f;
    tInv._44 = 1.0f;
}
// Mult Mat
void mat_Mult_mat(T3DMatrix &tMat1, T3DMatrix &tMat2, T3DMatrix &tOutMat)
{
    int i, j, k;
    double *p1 = (double *)&tMat1;
    double *p2 = (double *)&tMat2;
    double pOut[16];

    ZeroMemory(pOut, sizeof(T3DMatrix));

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k++)
                pOut[4 * i + j] += p1[4 * i + k] * p2[4 * k + j];

    CopyMemory(&tOutMat, pOut, sizeof(T3DMatrix));
}
// Mult Mat x Vect
void mat_Mult_vect(T3DMatrix &tMat, T3DVector &tVec, T3DVector &tOutVec)
{
    double x = tVec.x * tMat._11 + tVec.y * tMat._12 + tVec.z * tMat._13 + tMat._14;
    double y = tVec.x * tMat._21 + tVec.y * tMat._22 + tVec.z * tMat._23 + tMat._24;
    double z = tVec.x * tMat._31 + tVec.y * tMat._32 + tVec.z * tMat._33 + tMat._34;
    double w = tVec.x * tMat._41 + tVec.y * tMat._42 + tVec.z * tMat._43 + tMat._44;

    if (fabs(w) < _EPS)
        return;

    tOutVec.x = x / w;
    tOutVec.y = y / w;
    tOutVec.z = z / w;
}
// Copy Mat
void mat_Copy(T3DMatrix &tSMat, T3DMatrix &tDMat)
{
}
// Trasnlate
void mat_Traslate(double dx, double dy, double dz, T3DMatrix &tOutMat)
{
    tOutMat._14 += dx;
    tOutMat._24 += dy;
    tOutMat._34 += dz;
}
// Rotation (X axis = 0)
// nAxis : _MAT_AXIS_X : 0, _MAT_AXIS_Y : 1, _MAT_AXIS_Z : 2
void mat_Rotate(int nAxis, double dAng, T3DMatrix &tOutMat)
{
    double sin, cosin;

    sin = SIN(dAng);
    cosin = COS(dAng);

    switch (nAxis)
    {
    case _MAT_X_AXIS:
        tOutMat._22 = cosin;
        tOutMat._23 = -sin;
        tOutMat._32 = sin;
        tOutMat._33 = cosin;
        break;
    case _MAT_Y_AXIS:
        tOutMat._11 = cosin;
        tOutMat._13 = sin;
        tOutMat._31 = -sin;
        tOutMat._33 = cosin;
        break;
    case _MAT_Z_AXIS:
        tOutMat._11 = cosin;
        tOutMat._12 = -sin;
        tOutMat._21 = sin;
        tOutMat._22 = cosin;
        break;
    default:
        break;
    }
}
// Get Scale Matrix
void mat_Scale(double dx, double dy, double dz, T3DMatrix &tMat)
{
    tMat._11 *= dx;
    tMat._22 *= dy;
    tMat._33 *= dz;
}
// Input Matrix
void mat_Input(T3DMatrix &tMat, double faMat[16])
{
    tMat._11 = faMat[0];
    tMat._12 = faMat[4];
    tMat._13 = faMat[8];
    tMat._14 = faMat[12];
    tMat._21 = faMat[1];
    tMat._22 = faMat[5];
    tMat._23 = faMat[9];
    tMat._24 = faMat[13];
    tMat._31 = faMat[2];
    tMat._32 = faMat[6];
    tMat._33 = faMat[10];
    tMat._34 = faMat[14];
    tMat._41 = faMat[3];
    tMat._42 = faMat[7];
    tMat._43 = faMat[11];
    tMat._44 = faMat[15];
}
// Make Matrix Array
void mat_2_Array(T3DMatrix &tMat, double faMat[16])
{
    faMat[0] = tMat._11;
    faMat[4] = tMat._12;
    faMat[8] = tMat._13;
    faMat[12] = tMat._14;
    faMat[1] = tMat._21;
    faMat[5] = tMat._22;
    faMat[9] = tMat._23;
    faMat[13] = tMat._24;
    faMat[2] = tMat._31;
    faMat[6] = tMat._32;
    faMat[10] = tMat._33;
    faMat[14] = tMat._34;
    faMat[3] = tMat._41;
    faMat[7] = tMat._42;
    faMat[11] = tMat._43;
    faMat[15] = tMat._44;
}
// Make Matrix Shadow
void mat_Shadow(T3DMatrix *tpMat, T3DPlane *tpPlane, double fpLightPos[4])
{

    double fDot;
    fDot = tpPlane->a * fpLightPos[0] + tpPlane->b * fpLightPos[1] +
           tpPlane->c * fpLightPos[2] + tpPlane->d * fpLightPos[3];

    tpMat->_11 = fDot - fpLightPos[0] * tpPlane->a;
    tpMat->_12 = 0.0f - fpLightPos[0] * tpPlane->b;
    tpMat->_13 = 0.0f - fpLightPos[0] * tpPlane->c;
    tpMat->_14 = 0.0f - fpLightPos[0] * tpPlane->d;

    tpMat->_21 = 0.0f - fpLightPos[1] * tpPlane->a;
    tpMat->_22 = fDot - fpLightPos[1] * tpPlane->b;
    tpMat->_23 = 0.0f - fpLightPos[1] * tpPlane->c;
    tpMat->_24 = 0.0f - fpLightPos[1] * tpPlane->d;

    tpMat->_31 = 0.0f - fpLightPos[2] * tpPlane->a;
    tpMat->_32 = 0.0f - fpLightPos[2] * tpPlane->b;
    tpMat->_33 = fDot - fpLightPos[2] * tpPlane->c;
    tpMat->_34 = 0.0f - fpLightPos[2] * tpPlane->d;

    tpMat->_41 = 0.0f - fpLightPos[3] * tpPlane->a;
    tpMat->_42 = 0.0f - fpLightPos[3] * tpPlane->b;
    tpMat->_43 = 0.0f - fpLightPos[3] * tpPlane->c;
    tpMat->_44 = fDot - fpLightPos[3] * tpPlane->d;
}
// Add Matrix ,  tMat1 + tMat2
void mat_Add(T3DMatrix &tMat1, T3DMatrix &tMat2, T3DMatrix &tOutMat){
    for(int i =0;i<4;i++){
        for(int j=0; j<4; j++){
            tOutMat.m[i][j] = tMat1.m[i][j] + tMat2.m[i][j];
        }
    }
}
// Substract Matrix , tMat1 - tMat2
void mat_Sub(T3DMatrix &tMat1, T3DMatrix &tMat2, T3DMatrix &tOutMat){
    for(int i =0;i<4;i++){
        for(int j=0; j<4; j++){
            tOutMat.m[i][j] = tMat1.m[i][j] - tMat2.m[i][j];
        }
    }
}