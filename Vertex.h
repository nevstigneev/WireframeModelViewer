#ifndef VERTEX_H
#define VERTEX_H

#include "Object.h"

class Vertex : public Object
{
public:
	Vertex();
	Vertex(double _x, double _y, double _z);
	~Vertex();

	void Transform(const Matrix& m);

	double GetX();
	double GetY();
	double GetZ();

	void SetX(double _x);
	void SetY(double _y);
	void SetZ(double _z);

private:
	double x, y, z;
};

#endif