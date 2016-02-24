#ifndef CAMERA_H
#define CAMERA_H

#include "Object.h"
#include "Matrix.h"

class Camera : public Object
{
public:
	Camera();
	Camera(double _vertical_fov, double _z_near, double _z_far);
	~Camera();

	void Reset();
	Matrix& GetMatrix();

	void Transform(const Matrix& m);
    Matrix ToViewport(double width, double height);

private:
	Matrix CameraToNDC(double aspect);
	Matrix NDCToViewport(double width, double height);

	Matrix view_matrix;
	double vertical_fov, z_near, z_far;
};

#endif