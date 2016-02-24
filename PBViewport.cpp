#include "stdafx.h"
#include "PBViewport.h"


PictureBoxViewport::PictureBoxViewport(System::Drawing::Graphics^ _graphics, int _width, int _height)
{
	graphics = _graphics;
	width = _width;
	height = _height;
}

PictureBoxViewport::~PictureBoxViewport()
{
	// nothing
}

double PictureBoxViewport::GetWidth() const
{
	return width;
}

double PictureBoxViewport::GetHeight() const
{
	return height;
}

void PictureBoxViewport::DrawLine(Vertex& from, Vertex& to) 
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
