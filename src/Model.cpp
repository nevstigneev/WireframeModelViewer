#include "stdafx.h"
#include "Model.h"

Model::Model()
{
	Reset();
}

Model::~Model()
{
	edges.clear();
	vertices.clear();
}

void Model::Reset()
{
	transformation_matrix = Matrix::IdentityMatrix();
}

void Model::Transform(const Matrix& m)
{
	transformation_matrix = transformation_matrix * m;
}

Matrix& Model::GetMatrix()
{
	return transformation_matrix;
}

void Model::AddVertex(const Vertex& v)
{
	vertices.push_back(v);
}

void Model::AddEdge(const Edge& e)
{
	edges.push_back(e);
}

const Vertex& Model::GetVertex(int i)
{
	return vertices[i];
}

const Edge& Model::GetEdge(int i)
{
	return edges[i];
}

void Model::ClearVertices()
{
	vertices.clear();
}

void Model::ClearEdges()
{
	edges.clear();
}

int Model::VerticesCount() const
{
	return vertices.size();
}

int Model::EdgesCount() const
{
	return edges.size();
}