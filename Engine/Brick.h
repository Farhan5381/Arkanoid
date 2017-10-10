#pragma once

#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick( const RectF& rect_in, Color c_in);
	bool ColidedWithBall( Ball& ball );
	void Draw(Graphics& gfx);

private:
	RectF rect;
	Color c;
	bool destroyed = false;
};