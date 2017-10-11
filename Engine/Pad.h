#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"

class Pad
{
public:
	void Update( const Keyboard& kbd, float dt );
	void DoWallColision( const RectF& walls );
	bool DoBallColision( Ball& ball );
	void Draw( Graphics& gfx );
	RectF GetRect() const;
	void ResetCoolDown();

private:
	Vec2 pos = Vec2( 400.0f, 500.0f );
	float halfWidth = 40.0f;
	float halfHeight = 10.0f;
	float wingWidth = (20.0f/100.0f) * ( halfWidth * 2.0f);
	float speed = 200.0f;
	Color padColor = Colors::Gray;
	Color wingColor = Colors::LightGray;
	bool isCoolDown = false;
};