#pragma once

#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick( const RectF& rect_in, Color c_in, bool createBrick);
	bool CheckBallCollision( const Ball& ball ) const;
	void DoBallCollision( Ball& ball );
	void Draw(Graphics& gfx);
	Vec2 GetCenter() const;

private:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color c;
	bool destroyed = true;
};