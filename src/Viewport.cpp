#include "stdafx.h"
#include "Viewport.h"


Viewport::Viewport(System::Drawing::Graphics^ _graphics, int _width, int _height)
{
	graphics = _graphics;
	width = _width;
	height = _height;
}

Viewport::~Viewport()
{
	// nothing
}

double Viewport::GetWidth() const
{
	return width;
}

double Viewport::GetHeight() const
{
	return height;
}

void Viewport::DrawLine(Vertex& from, Vertex& to) 
{
	try
	{
		graphics->DrawLine(System::Drawing::Pens::Black, (float)from.GetX(), (float)from.GetY(), (float)to.GetX(), (float)to.GetY());
	}
	catch (System::Exception^ e)
	{
		System::Diagnostics::Debugger::Break();
	}
}
