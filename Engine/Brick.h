#pragma once

#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick( const Vec2& pos_in, int brickTypeId, bool createBrick);
	bool CheckBallCollision( const Ball& ball ) const;
	void DoBallCollision( Ball& ball );
	void Draw(Graphics& gfx);
	RectF GetRect() const;
	Vec2 GetCenter() const;
	static Vec2 GetDimension();

private:
	int TypeId;
	Vec2 pos;
	static constexpr float width = 31.0f;
	static constexpr float height = 15.0f ;
	bool destroyed = true;
};