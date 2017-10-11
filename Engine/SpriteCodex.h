#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawTitleScreen( const Vec2& top_left, Graphics& gfx );
	static void DrawBallNormal( const Vec2& top_left, Graphics& gfx );
	static void DrawBallFlame( const Vec2& top_left, Graphics& gfx );
	static void DrawpadNormal( const Vec2& top_left, Graphics& gfx );
	static void DrawpadSmall( const Vec2& top_left, Graphics& gfx );
	static void DrawpadBig( const Vec2& top_left, Graphics& gfx );
	static void DrawRedBrick( const Vec2& top_left, Graphics& gfx );
	static void DrawBlueBrick( const Vec2& top_left, Graphics& gfx );
	static void DrawYellowBrick( const Vec2& top_left, Graphics& gfx );
	static void DrawGreenBrick( const Vec2& top_left, Graphics& gfx );
	static void DrawOrangeBrick( const Vec2 & top_left, Graphics & gfx );
	static void DrawExpandPowerup( const Vec2& top_left, Graphics& gfx );
	static void DrawContractPowerup( const Vec2& top_left, Graphics& gfx );
	static void DrawMultiplyBallPowerup( const Vec2& top_left, Graphics& gfx );
	static void DrawFlamingBallPowerup( const Vec2& top_left, Graphics& gfx );
	static void DrawGameOverScreen( const Vec2& top_left, Graphics& gfx );
};