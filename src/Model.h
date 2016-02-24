#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Vertex.h"

struct Edge
{
	int from, to;
};

class Model : public Object
{
public:
	Model();
	~Model();

	void Transform(const Matrix& m);
	void Reset();

	Matrix& GetMatrix();

	void AddVertex(const Vertex& v);
	void AddEdge(const Edge& e);

	const Vertex& GetVertex(int i);
	const Edge& GetEdge(int i);
	
	void ClearVertices();
	void ClearEdges();

	int VerticesCount() const;
	int EdgesCount() const;

private:
	Matrix transformation_matrix;
	std::vector<Vertex> vertices;
	std::vector<Edge> edges;
};

#endif