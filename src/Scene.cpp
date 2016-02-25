#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	// nothing
}

Scene::~Scene()
{
	models.clear();
	camers.clear();
}

void Scene::Transform(const Matrix& m)
{
	for (int i = 0; i < ModelsCount(); i++)
	{
		models[i].Transform(m);
	}
}

void Scene::TransformModel(int model_index, const Matrix& m)
{
	models[model_index].Transform(m);
}

void Scene::TransformCamera(int camera_index, const Matrix& m)
{
	camers[camera_index].Transform(m);
}

void Scene::AddModel(const Model& model)
{
	models.push_back(model);
}

void Scene::AddCamera(const Camera& camera)
{
	camers.push_back(camera);
}

void Scene::DeleteAllModels()
{
	models.clear();
}

void Scene::DeleteAllCamers()
{
	camers.clear();
}

int Scene::ModelsCount() const
{
	return models.size();
}

int Scene::CamersCount() const
{
	return camers.size();
}

const Model& Scene::GetModel(int model_index)
{
	return models[model_index];
}

const Camera& Scene::GetCamera(int camera_index)
{
	return camers[camera_index];
}