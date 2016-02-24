#ifndef MATRIX_H
#define MATRIX_H

class Vertex;

class Matrix
{
public:
	Matrix();
	~Matrix();

	static Matrix IdentityMatrix();
	static Matrix ZeroMatrix();

	double& operator()(int i, int j);
	const double& operator()(int i, int j) const;

	Matrix Multiply(const Matrix& m);
	Matrix operator*(const Matrix& m);

	Matrix Invert();
	Matrix operator~();

	static Matrix Translation(Vertex& offset);
	static Matrix Scaling(double factor);
	static Matrix RotationX(double angle);
	static Matrix RotationY(double angle);
	static Matrix RotationZ(double angle);
	static Matrix Rotation(Vertex& axis, double angle);

	Matrix& operator=(const Matrix& m);

private:
	double e[4][4];
};

#endif