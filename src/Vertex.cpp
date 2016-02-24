#include "stdafx.h"
#include "Vertex.h"

Vertex::Vertex()
{
	x = y = z = 0;
}

Vertex::Vertex(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vertex::~Vertex()
{
	// nothing
}

void Vertex::Transform(const Matrix& m)
{
	Vertex r;
	r.x = x * m(0, 0) + y * m(1, 0) + z * m(2, 0) + m(3, 0);
	r.y = x * m(0, 1) + y * m(1, 1) + z * m(2, 1) + m(3, 1);
	r.z = x * m(0, 2) + y * m(1, 2) + z * m(2, 2) + m(3, 2);
	double w = x * m(0, 3) + y * m(1, 3) + z * m(2, 3) + m(3, 3);
	*this = Vertex(r.x / w, r.y / w, r.z / w);
}

double Vertex::GetX()
{
	return x;
}

double Vertex::GetY()
{
	return y;
}

double Vertex::GetZ()
{
	return z;
}

void Vertex::SetX(double _x)
{
	x = _x;
}

void Vertex::SetY(double _y)
{
	y = _y;
}

void Vertex::SetZ(double _z)
{
	z = _z;
}