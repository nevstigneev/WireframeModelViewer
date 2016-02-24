#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Scene.h"
#include <stdio.h>

typedef FILE* ModelFile;

class FileManager
{
public:
	FileManager();
	~FileManager();

	bool OpenFile(const char* path);
	bool LoadScene(Scene& scene);
	void CloseFile();

	bool IsOpened();
	int GetModelsCount();

private:
	bool LoadNumber(int& n);
	bool LoadVertex(Vertex& v);
	bool LoadEdge(Edge& e);
	bool LoadModel(Model& model);

	ModelFile f;
	bool is_opened;
	int models_count;
};

#endif