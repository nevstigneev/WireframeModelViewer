#ifndef PB_VIEWPORT_H
#define PB_VIEWPORT_H

#include <vcclr.h>
#include "Vertex.h"
#include "Viewport.h"

class PictureBoxViewport : public Viewport
{
public:
    PictureBoxViewport(System::Drawing::Graphics^ graphics, int _width, int _height);
    ~PictureBoxViewport();

	double GetWidth() const;
	double GetHeight() const;

    void DrawLine(Vertex& from, Vertex& to);

private:
	gcroot<System::Drawing::Graphics^> graphics;
	int width, height;
};

#endif