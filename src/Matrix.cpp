#include "stdafx.h"
#include "Vertex.h"
#include <string.h>
#include <math.h>

Matrix::Matrix()
{
	memset(e, 0, sizeof(e));
	e[0][0] = e[1][1] = e[2][2] = e[3][3] = 1.0;
}

Matrix::~Matrix()
{
	// nothing
}

Matrix Matrix::IdentityMatrix()
{
	Matrix r = ZeroMatrix();

	r(0, 0) = r(1, 1) = r(2, 2) = r(3, 3) = 1.0;

	return r;
}

Matrix Matrix::ZeroMatrix()
{
	Matrix r;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			r(i, j) = 0.0;
		}
	}

	return r;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			e[i][j] = m(i, j);
		}
	}
	return *this;
}

double& Matrix::operator()(int i, int j)
{
	return e[i][j];
}

const double& Matrix::operator()(int i, int j) const
{
	return e[i][j];
}

Matrix Matrix::Multiply(const Matrix& m)
{
	Matrix r;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			double a = 0.0;
			for (int k = 0; k < 4; k++) 
			{
				a += e[i][k] * m.e[k][j];
			}
			r.e[i][j] = a;
		}
	}
	return r;
}

Matrix Matrix::operator*(const Matrix& m)
{
	return Multiply(m);
}

Matrix Matrix::Invert()
{
	Matrix r;
	double d
		= e[0][3] * e[1][2] * e[2][1] * e[3][0] - e[0][2] * e[1][3] * e[2][1] * e[3][0] - e[0][3] * e[1][1] * e[2][2] * e[3][0] + e[0][1] * e[1][3] * e[2][2] * e[3][0]
	+ e[0][2] * e[1][1] * e[2][3] * e[3][0] - e[0][1] * e[1][2] * e[2][3] * e[3][0] - e[0][3] * e[1][2] * e[2][0] * e[3][1] + e[0][2] * e[1][3] * e[2][0] * e[3][1]
	+ e[0][3] * e[1][0] * e[2][2] * e[3][1] - e[0][0] * e[1][3] * e[2][2] * e[3][1] - e[0][2] * e[1][0] * e[2][3] * e[3][1] + e[0][0] * e[1][2] * e[2][3] * e[3][1]
	+ e[0][3] * e[1][1] * e[2][0] * e[3][2] - e[0][1] * e[1][3] * e[2][0] * e[3][2] - e[0][3] * e[1][0] * e[2][1] * e[3][2] + e[0][0] * e[1][3] * e[2][1] * e[3][2]
	+ e[0][1] * e[1][0] * e[2][3] * e[3][2] - e[0][0] * e[1][1] * e[2][3] * e[3][2] - e[0][2] * e[1][1] * e[2][0] * e[3][3] + e[0][1] * e[1][2] * e[2][0] * e[3][3]
	+ e[0][2] * e[1][0] * e[2][1] * e[3][3] - e[0][0] * e[1][2] * e[2][1] * e[3][3] - e[0][1] * e[1][0] * e[2][2] * e[3][3] + e[0][0] * e[1][1] * e[2][2] * e[3][3];

	r.e[0][0] = (e[1][2] * e[2][3] * e[3][1] - e[1][3] * e[2][2] * e[3][1] + e[1][3] * e[2][1] * e[3][2] - e[1][1] * e[2][3] * e[3][2] - e[1][2] * e[2][1] * e[3][3] + e[1][1] * e[2][2] * e[3][3]) / d;
	r.e[0][1] = (e[0][3] * e[2][2] * e[3][1] - e[0][2] * e[2][3] * e[3][1] - e[0][3] * e[2][1] * e[3][2] + e[0][1] * e[2][3] * e[3][2] + e[0][2] * e[2][1] * e[3][3] - e[0][1] * e[2][2] * e[3][3]) / d;
	r.e[0][2] = (e[0][2] * e[1][3] * e[3][1] - e[0][3] * e[1][2] * e[3][1] + e[0][3] * e[1][1] * e[3][2] - e[0][1] * e[1][3] * e[3][2] - e[0][2] * e[1][1] * e[3][3] + e[0][1] * e[1][2] * e[3][3]) / d;
	r.e[0][3] = (e[0][3] * e[1][2] * e[2][1] - e[0][2] * e[1][3] * e[2][1] - e[0][3] * e[1][1] * e[2][2] + e[0][1] * e[1][3] * e[2][2] + e[0][2] * e[1][1] * e[2][3] - e[0][1] * e[1][2] * e[2][3]) / d;

	r.e[1][0] = (e[1][3] * e[2][2] * e[3][0] - e[1][2] * e[2][3] * e[3][0] - e[1][3] * e[2][0] * e[3][2] + e[1][0] * e[2][3] * e[3][2] + e[1][2] * e[2][0] * e[3][3] - e[1][0] * e[2][2] * e[3][3]) / d;
	r.e[1][1] = (e[0][2] * e[2][3] * e[3][0] - e[0][3] * e[2][2] * e[3][0] + e[0][3] * e[2][0] * e[3][2] - e[0][0] * e[2][3] * e[3][2] - e[0][2] * e[2][0] * e[3][3] + e[0][0] * e[2][2] * e[3][3]) / d;
	r.e[1][2] = (e[0][3] * e[1][2] * e[3][0] - e[0][2] * e[1][3] * e[3][0] - e[0][3] * e[1][0] * e[3][2] + e[0][0] * e[1][3] * e[3][2] + e[0][2] * e[1][0] * e[3][3] - e[0][0] * e[1][2] * e[3][3]) / d;
	r.e[1][3] = (e[0][2] * e[1][3] * e[2][0] - e[0][3] * e[1][2] * e[2][0] + e[0][3] * e[1][0] * e[2][2] - e[0][0] * e[1][3] * e[2][2] - e[0][2] * e[1][0] * e[2][3] + e[0][0] * e[1][2] * e[2][3]) / d;

	r.e[2][0] = (e[1][1] * e[2][3] * e[3][0] - e[1][3] * e[2][1] * e[3][0] + e[1][3] * e[2][0] * e[3][1] - e[1][0] * e[2][3] * e[3][1] - e[1][1] * e[2][0] * e[3][3] + e[1][0] * e[2][1] * e[3][3]) / d;
	r.e[2][1] = (e[0][3] * e[2][1] * e[3][0] - e[0][1] * e[2][3] * e[3][0] - e[0][3] * e[2][0] * e[3][1] + e[0][0] * e[2][3] * e[3][1] + e[0][1] * e[2][0] * e[3][3] - e[0][0] * e[2][1] * e[3][3]) / d;
	r.e[2][2] = (e[0][1] * e[1][3] * e[3][0] - e[0][3] * e[1][1] * e[3][0] + e[0][3] * e[1][0] * e[3][1] - e[0][0] * e[1][3] * e[3][1] - e[0][1] * e[1][0] * e[3][3] + e[0][0] * e[1][1] * e[3][3]) / d;
	r.e[2][3] = (e[0][3] * e[1][1] * e[2][0] - e[0][1] * e[1][3] * e[2][0] - e[0][3] * e[1][0] * e[2][1] + e[0][0] * e[1][3] * e[2][1] + e[0][1] * e[1][0] * e[2][3] - e[0][0] * e[1][1] * e[2][3]) / d;

	r.e[3][0] = (e[1][2] * e[2][1] * e[3][0] - e[1][1] * e[2][2] * e[3][0] - e[1][2] * e[2][0] * e[3][1] + e[1][0] * e[2][2] * e[3][1] + e[1][1] * e[2][0] * e[3][2] - e[1][0] * e[2][1] * e[3][2]) / d;
	r.e[3][1] = (e[0][1] * e[2][2] * e[3][0] - e[0][2] * e[2][1] * e[3][0] + e[0][2] * e[2][0] * e[3][1] - e[0][0] * e[2][2] * e[3][1] - e[0][1] * e[2][0] * e[3][2] + e[0][0] * e[2][1] * e[3][2]) / d;
	r.e[3][2] = (e[0][2] * e[1][1] * e[3][0] - e[0][1] * e[1][2] * e[3][0] - e[0][2] * e[1][0] * e[3][1] + e[0][0] * e[1][2] * e[3][1] + e[0][1] * e[1][0] * e[3][2] - e[0][0] * e[1][1] * e[3][2]) / d;
	r.e[3][3] = (e[0][1] * e[1][2] * e[2][0] - e[0][2] * e[1][1] * e[2][0] + e[0][2] * e[1][0] * e[2][1] - e[0][0] * e[1][2] * e[2][1] - e[0][1] * e[1][0] * e[2][2] + e[0][0] * e[1][1] * e[2][2]) / d;

	return r;
}

Matrix Matrix::operator~()
{
	return Invert();
}

Matrix Matrix::Translation(Vertex& offset)
{
	Matrix r;

	r(3, 0) = offset.GetX();
	r(3, 1) = offset.GetY();
	r(3, 2) = offset.GetZ();

	return r;
}

Matrix Matrix::Scaling(double factor)
{
	Matrix r;

	r(0, 0) = factor;
	r(1, 1) = factor;
	r(2, 2) = factor;

	return r;
}

Matrix Matrix::RotationX(double angle)
{
	Matrix r;

	r(1, 1) = cos(angle);
	r(1, 2) = -sin(angle);
	r(2, 1) = sin(angle);
	r(2, 2) = cos(angle);

	return r;
}

Matrix Matrix::RotationY(double angle)
{
	Matrix r;

	r(0, 0) = cos(angle);
	r(2, 0) = -sin(angle);
	r(0, 2) = sin(angle);
	r(2, 2) = cos(angle);

	return r;
}

Matrix Matrix::RotationZ(double angle)
{
	Matrix r;

	r(0, 0) = cos(angle);
	r(0, 1) = -sin(angle);
	r(1, 0) = sin(angle);
	r(1, 1) = cos(angle);

	return r;
}

Matrix Matrix::Rotation(Vertex& axis, double angle)
{
	Matrix r;
	r = RotationX(angle * axis.GetX()) * RotationY(angle * axis.GetY()) * RotationZ(angle * axis.GetZ());
	return r;
}