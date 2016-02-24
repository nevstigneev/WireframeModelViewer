#include "stdafx.h"
#include "Renderer.h"

void Renderer::RenderScene(Scene& scene, int camera_index, PictureBoxViewport& v)
{
	Camera camera = scene.GetCamera(camera_index);
	Matrix camera_matrix = camera.GetMatrix();
	Matrix to_viewport = camera.ToViewport(v.GetWidth(), v.GetHeight());
	for (int i = 0; i < scene.ModelsCount(); i++)
	{
		Model model = scene.GetModel(i);
		Matrix model_matrix = model.GetMatrix();
		Matrix model_to_viewport = model_matrix * ~camera_matrix * to_viewport;
		RenderModel(model, model_to_viewport, v);
	}
}

void Renderer::RenderModel(Model& model, const Matrix& m, PictureBoxViewport& v)
{
	for (int i = 0; i < model.EdgesCount(); i++)
	{
		Edge e = model.GetEdge(i);
		Vertex from = model.GetVertex(e.from);
		Vertex to = model.GetVertex(e.to);
		from.Transform(m);
		to.Transform(m);
		v.DrawLine(from, to);
	}
}