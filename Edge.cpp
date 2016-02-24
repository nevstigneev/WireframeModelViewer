#include "stdafx.h"
#include "Edge.h"

Edge::Edge()
{
	from = to = &Vertex(0.0, 0.0, 0.0);
}

Edge::Edge(Vertex *_from, Vertex *_to)
{
	from = _from;
	to = _to;
}

Edge::~Edge()
{
	from = to = nullptr;
}

void Edge::Transform(const Matrix& m)
{
	from->Transform(m);
	to->Transform(m);
}

Vertex* Edge::GetFrom()
{
	return from;
}

Vertex* Edge::GetTo()
{
	return to;
}

void Edge::SetFrom(Vertex *_from)
{
	from = _from;
}

void Edge::SetTo(Vertex *_to)
{
	to = _to;
}