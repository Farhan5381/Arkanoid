#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"

class Pad
{
public:
	Pad( const Vec2& pos_in, float width, float height);
	void Update( const Keyboard& kbd, float dt );
	void DoWallColision( const RectF& walls );
	bool DoBallColision( Ball& ball );
	void Draw( Graphics& gfx );
	RectF GetRect() const;
	void ResetCoolDown();

private:
	Vec2 pos;
	float halfWidth;
	float halfHeight;
	float wingWidth = 25.0f;
	float speed = 300.0f;
	Color padColor = Colors::Gray;
	Color wingColor = Colors::LightGray;
	bool isCoolDown = false;
};