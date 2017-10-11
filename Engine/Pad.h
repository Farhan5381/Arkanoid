#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"
#include "SpriteCodex.h"

class Pad
{
public:
	void Update( const Keyboard& kbd, float dt );
	void DoWallColision( const RectF& walls );
	bool DoBallColision( Ball& ball );
	void Draw( Graphics& gfx );
	RectF GetRect() const;
	void ResetCoolDown();
	void SetPadId( int Id );

private:
	Vec2 pos = Vec2( 400.0f, 500.0f );
	int padId = 1;
	float width = 120.0f;
	static constexpr float height = 20.0f;
	static constexpr float speed = 200.0f;
	bool isCoolDown = false;
};