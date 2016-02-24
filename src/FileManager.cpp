#include "stdafx.h"
#include "FileManager.h"

FileManager::FileManager()
{
	is_opened = false;
	models_count = 0;
}

FileManager::~FileManager()
{
	// nothing
}

bool FileManager::OpenFile(const char* path)
{
	bool status = true;
	if ((f = fopen(path, "r")) == nullptr)
	{
		return !status;
	}

	status = LoadNumber(models_count);
	return (is_opened = status);
}

bool FileManager::LoadNumber(int& n)
{
	bool status = (fscanf(f, "%d", &n) == 1);
	if (!status)
	{
		return false;
	}
	if (status && n <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool FileManager::LoadVertex(Vertex& v)
{
	double x, y, z;
	bool status = (fscanf(f, "%lf %lf %lf", &x, &y, &z) == 3);
	if (status)
	{
		v.SetX(x);
		v.SetY(y);
		v.SetZ(z);
	}
	return status;
}

bool FileManager::LoadEdge(Edge& e)
{
	int from, to;
	bool status = (fscanf(f, "%d %d", &from, &to) == 2);
	if (status)
	{
		e.from = from;
		e.to = to;
	}
	return status;
}

bool FileManager::LoadModel(Model& model)
{
	Vertex v;
	int vertices_count;

	bool status = LoadNumber(vertices_count);
	if (!status)
	{
		return false;
	}
	for (int i = 0; i < vertices_count && status; i++)
	{
		status = LoadVertex(v);
		model.AddVertex(v);
	}
	if (!status)
	{
		model.ClearVertices();
		return false;
	}

	Edge e;
	int edges_count;

	status = LoadNumber(edges_count);
	if (!status)
	{
		model.ClearVertices();
		return false;
	}
	for (int i = 0; i < edges_count && status; i++)
	{
		status = LoadEdge(e);
		model.AddEdge(e);
	}
	if (!status)
	{
		model.ClearEdges();
		model.ClearVertices();
		return false;
	}
	return true;
}

bool FileManager::LoadScene(Scene& scene)
{
	Model m;
	bool status = true;

	for (int i = 0; i < models_count && status; i++)
	{
		status = LoadModel(m);
		scene.AddModel(m);
	}
	return status;
}

void FileManager::CloseFile()
{
	fclose(f);
	is_opened = false;
}

bool FileManager::IsOpened()
{
	return is_opened;
}

int FileManager::GetModelsCount()
{
	return models_count;
}