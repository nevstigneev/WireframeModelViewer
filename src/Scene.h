#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "Model.h"
#include "Camera.h"

class Scene : public Object
{
public:
	Scene();
	~Scene();

	void Transform(const Matrix& m);
	void TransformModel(int model_index, const Matrix& m);
	void TransformCamera(int camera_index, const Matrix& m);

	void AddModel(const Model& model);
	void AddCamera(const Camera& camera);

	void DeleteAllModels();
	void DeleteAllCamers();

	int ModelsCount() const;
	int CamersCount() const;

	const Model& GetModel(int model_index);
	const Camera& GetCamera(int camera_index);

private:
	std::vector<Model> models;
	std::vector<Camera> camers;
};

#endif