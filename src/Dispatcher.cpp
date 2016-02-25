#include "stdafx.h"
#include "Dispatcher.h"

Dispatcher* Dispatcher::Instance()
{
	static Dispatcher* the_single_instance = new Dispatcher;
	return the_single_instance;
}

bool Dispatcher::LoadScene(const char* path)
{
	bool status = file_manager.OpenFile(path);
	if (!status)
	{
		return false;
	}

	status = file_manager.LoadScene(scene);
	if (status)
	{
		Camera camera;
		scene.AddCamera(camera);
	}
	return status;
}

void Dispatcher::ClearScene()
{
	scene.DeleteAllCamers();
	scene.DeleteAllModels();
}

void Dispatcher::RotateCamera(double x, double y, double z, double angle, int camera_index)
{
	Vertex axis(x, y, z);
	Matrix m = Matrix::Rotation(axis, angle);
	scene.TransformCamera(camera_index, m);
}

void Dispatcher::TranslateCamera(double dx, double dy, double dz, int camera_index)
{
	Vertex offset(dx, dy, dz);
	Matrix m = Matrix::Translation(offset);
	scene.TransformCamera(camera_index, m);
}

void Dispatcher::TranslateModel(double dx, double dy, double dz, int model_index)
{
	Vertex offset(dx, dy, dz);
	Matrix m = Matrix::Translation(offset);
	scene.TransformModel(model_index, m);
}

void Dispatcher::RotateModel(double x, double y, double z, double angle, int model_index)
{
	Vertex axis(x, y, z);
	Matrix m = Matrix::Rotation(axis, angle);
	scene.TransformModel(model_index, m);
}

void Dispatcher::ScaleModel(double factor, int model_index)
{
	Matrix m = Matrix::Scaling(factor);
	scene.TransformModel(model_index, m);
}

void Dispatcher::RenderScene(PictureBoxViewport& v, int camera_index)
{
	renderer.RenderScene(scene, camera_index, v);
}