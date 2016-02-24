#include "stdafx.h"
#include "Camera.h"
#include <math.h>

#define ToRadians(angle) angle * (3.14159265358979323846 / 180.0)

Camera::Camera()
{
	view_matrix = Matrix::IdentityMatrix();
	vertical_fov = ToRadians(60.0);
	z_near = 1.0;
	z_far = 10.0;
}

Camera::Camera(double _vertical_fov, double _z_near, double _z_far)
{
	view_matrix = Matrix::IdentityMatrix();
	vertical_fov = _vertical_fov;
	z_near = _z_near;
	z_far = _z_far;
}

Camera::~Camera()
{
	// nothing
}

void Camera::Reset()
{
	view_matrix = Matrix::IdentityMatrix();
}

Matrix& Camera::GetMatrix()
{
	return view_matrix;
}

void Camera::Transform(const Matrix& m)
{
	view_matrix = view_matrix * m;
}

Matrix Camera::CameraToNDC(double aspect)
{
	Matrix m;
	m = Matrix::ZeroMatrix();

	m(1, 1) = 1.0 / tan(vertical_fov / 2.0);
	m(0, 0) = m(1, 1) / aspect;
	m(2, 2) = (z_far) / (z_far - z_near);
	m(2, 3) = -1.0;
	m(3, 2) = -(z_near * z_far) / (z_far - z_near);

	return m;
}

Matrix Camera::NDCToViewport(double width, double height)
{
	Matrix m;

	m(0, 0) = width / 2.0; 
	m(1, 1) = -height / 2.0;
	m(2, 2) = 0.0;
	m(3, 0) = width / 2.0; 
	m(3, 1) = height / 2.0;

	return m;
}

Matrix Camera::ToViewport(double width, double height)
{
	double aspect = width / height;
	return CameraToNDC(aspect) * NDCToViewport(width, height);
}