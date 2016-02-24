#ifndef RENDERER_H
#define RENDERER_H

#include "Scene.h"
#include "PBViewport.h"

class Renderer
{
public:
	void RenderScene(Scene& scene, int camera_index, PictureBoxViewport& v);
private:
	void RenderModel(Model& model, const Matrix& m, PictureBoxViewport& v);
};

#endif