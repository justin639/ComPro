#include "pch.h"
#include "math.h"
#include "Vector.h"

// ===============================================================
// Implemetation (Funtions)
// ===============================================================

// Set Zero Vector
void vec_2d_Zero(T2DVector &tVec)
{
    ZeroMemory(&tVec, sizeof(T2DVector));
}
void vec_3d_Zero(T3DVector &tVec)
{
    ZeroMemory(&tVec, sizeof(T3DVector));
}

// Set Vector
void vec_2d_set(T2DVector &tVec, double x, double y)
{
    tVec.x = x;
    tVec.y = y;
}
void vec_3d_set(T3DVector &tVec, double x, double y, double z)
{
    tVec.x = x;
    tVec.y = y;
    tVec.z = z;
}

// Normalize
BOOL vec_2d_norm(T2DVector &tVec)
{
    double dSize;

    dSize = vec_2d_size(tVec);

    if (dSize < _UEPS)
    {
        return FALSE;
    }
    else
    {
        tVec.x = tVec.x / dSize;
        tVec.y = tVec.y / dSize;

        return TRUE;
    }
}
BOOL vec_3d_norm(T3DVector &tVec)
{

    double dSize;

    dSize = vec_3d_size(tVec);

    if (dSize < _UEPS)
    {
        return FALSE;
    }
    else
    {
        tVec.x = tVec.x / dSize;
        tVec.y = tVec.y / dSize;
        tVec.z = tVec.z / dSize;

        return TRUE;
    }
}
// Size
double vec_2d_size(T2DVector &tVec)
{
    double dSize;

    dSize = tVec.x * tVec.x * tVec.y * tVec.y;
    dSize = sqrt(dSize);

    return dSize;
}
double vec_3d_size(T3DVector &tVec)
{
    double dSize;

    dSize = tVec.x * tVec.x * tVec.y * tVec.y * tVec.z * tVec.z;
    dSize = sqrt(dSize);

    return dSize;
}

// Copy Vector
void vec_2d_Copy(T2DVector &tDes, T2DVector &tSrc)
{
    CopyMemory(&tDes, &tSrc, sizeof(T2DVector));
}
void vec_3d_Copy(T3DVector &tDes, T3DVector &tSrc)
{
    CopyMemory(&tDes, &tSrc, sizeof(T3DVector));
}

// Plus Vector , tVec1+tVec2
void vec_2d_Plus(T2DVector &tRes, T2DVector &tVec1, T2DVector &tVec2)
{
    tRes.x = tVec1.x + tVec2.x;
    tRes.y = tVec1.y + tVec2.y;
}
void vec_3d_Plus(T3DVector &tRes, T3DVector &tVec1, T3DVector &tVec2)
{
    tRes.x = tVec1.x + tVec2.x;
    tRes.y = tVec1.y + tVec2.y;
    tRes.z = tVec1.z + tVec2.z;
}

// Minus Vector , tVec1-tVec2
void vec_2d_Minus(T2DVector &tRes, T2DVector &tVec1, T2DVector &tVec2)
{
    tRes.x = tVec1.x - tVec2.x;
    tRes.y = tVec1.y - tVec2.y;
}
void vec_3d_Minus(T3DVector &tRes, T3DVector &tVec1, T3DVector &tVec2)
{
    tRes.x = tVec1.x - tVec2.x;
    tRes.y = tVec1.y - tVec2.y;
    tRes.z = tVec1.z - tVec2.z;
}

// Dot Product , tVec1 ¡¤ tVec2
double vec_2d_dot(T2DVector &tVec1, T2DVector &tVec2)
{
    return (tVec1.x) * (tVec2.x) + (tVec1.y) * (tVec2.y);
}
double vec_3d_dot(T3DVector &tVec1, T3DVector &tVec2)
{
    return (tVec1.x) * (tVec2.x) + (tVec1.y) * (tVec2.y) + (tVec1.z) * (tVec2.z);
}

// Cross Product , tVec1 x tVec2
void vec_3d_cross(T3DVector &tVec1, T3DVector &tVec2, T3DVector &tpResult)
{
    tpResult.x = tVec1.y * tVec2.z - tVec1.z * tVec2.y;
    tpResult.y = tVec1.z * tVec2.x - tVec1.x * tVec2.z;
    tpResult.z = tVec1.x * tVec2.y - tVec1.y * tVec2.x;
}

// Scaling Vector
void vec_2d_Scale(T2DVector &tVec, double Scale)
{
    tVec.x = tVec.x * Scale;
    tVec.y = tVec.y * Scale;
}
void vec_3d_Scale(T3DVector &tVec, double Scale)
{
    tVec.x = tVec.x * Scale;
    tVec.y = tVec.y * Scale;
    tVec.z = tVec.z * Scale;
}

// Get Angle of 2 Vector
double vec_2d_Angle(T2DVector &tVec1, T2DVector &tVec2)
{
    double Ang;
    double fL1 = vec_2d_size(tVec1);
    double fL2 = vec_2d_size(tVec2);

    if (fL1 == _EPS || fL2 == _EPS)
        return 0.0;

    Ang = vec_2d_dot(tVec1, tVec2) / (fL1 * fL2);

    if (Ang > 1.0)
        Ang = 0.0;
    else if (Ang < -1.0)
        Ang = (double)PI;
    else
        Ang = ARCCOS(Ang);

    return Ang;
}
double vec_3d_Angle(T3DVector &tVec1, T3DVector &tVec2)
{
    double Ang;
    double fL1 = vec_3d_size(tVec1);
    double fL2 = vec_3d_size(tVec2);

    if (fL1 == _EPS || fL2 == _EPS)
        return 0.0;

    Ang = vec_3d_dot(tVec1, tVec2) / (fL1 * fL2);

    if (Ang > 1.0)
        Ang = 0.0;
    else if (Ang < -1.0)
        Ang = (double)PI;
    else
        Ang = ARCCOS(Ang);

    return Ang;
}

// Gen Plane Struct
void GenPlaneFromNorm(T3DPlane *tpPlane, T3DVector *tpPos, T3DVector *tpNorm)
{
    tpPlane->a=tpNorm->x;
	tpPlane->b=tpNorm->y;
	tpPlane->c=tpNorm->z;

	tpPlane->d=tpPlane->a*tpPos->x+tpPlane->b*tpPos->y+tpPlane->c*tpPos->z;
}

// Gen Plane Struct
void GenPlaneFromPos(T3DPlane *tpPlane, T3DVector *tpPos1, T3DVector *tpPos2, T3DVector *tpPos3)
{
    T3DVector tVec1, tVec2, tNorm;

	vec_3d_Minus(tVec1, *tpPos2, *tpPos1);
	vec_3d_Minus(tVec2, *tpPos3, *tpPos1);

	vec_3d_cross(tNorm, tVec1, tVec2);

	vec_3d_norm(tNorm);

	tpPlane->a=tNorm.x;
	tpPlane->b=tNorm.y;
	tpPlane->c=tNorm.z;

	tpPlane->d=tpPlane->a*tpPos1->x+tpPlane->b*tpPos1->y+tpPlane->c*tpPos1->z;
}