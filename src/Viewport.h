#ifndef VIEWPORT_H
#define VIEWPORT_H

class Viewport
{
public:
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;

    virtual void DrawLine(Vertex& from, Vertex& to) = 0;
private:
	int width, height;
};

#endif