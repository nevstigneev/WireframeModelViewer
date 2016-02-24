#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "Matrix.h"

class SceneObject
{
public:
	virtual ~SceneObject() = 0 {};
	virtual void Transform(const Matrix& m) = 0;
};

#endif