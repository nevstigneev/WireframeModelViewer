#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Scene.h"
#include "FileManager.h"
#include "Renderer.h"

class Dispatcher
{
public:
	static Dispatcher* Instance();
	bool LoadScene(const char* path);
	void ClearScene();

	void TranslateCamera(double dx, double dy, double dz, int camera_index);
	void RotateCamera(double x, double y, double z, double angle, int camera_index);

	void TranslateModel(double dx, double dy, double dz, int model_index);
	void RotateModel(double x, double y, double z, double angle, int model_index);
	void ScaleModel(double factor, int model_index);

	void RenderScene(PictureBoxViewport& v, int camera_index);
private:
	Dispatcher() {};
	Dispatcher(const Dispatcher& root);
	Dispatcher& operator=(const Dispatcher& root);
	Scene scene;
	FileManager file_manager;
	Renderer renderer;
};

#endif