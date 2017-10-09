#pragma once

#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick( const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx);

private:
	RectF rect;
	Color c;
	bool destroyed = false;
};