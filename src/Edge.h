#ifndef EDGE_H
#define EDGE_H

#include "SceneObject.h"
#include "Vertex.h"

class Edge : public SceneObject
{
public:
	Edge();
	Edge(Vertex *_from, Vertex *_to);
	~Edge();

	void Transform(const Matrix& m);

	Vertex* GetFrom();
	Vertex* GetTo();

	void SetFrom(Vertex *_from);
	void SetTo(Vertex *_to);

private:
	Vertex *from, *to;
};

#endif