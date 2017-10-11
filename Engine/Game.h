/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Ball.h"
#include "Brick.h"
#include "Pad.h"
#include "Sound.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel( float dt );
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft;
	Ball ball;
	Pad pad;
	RectF walls = RectF( Vec2( 75.0f, 0.0f ), Vec2( 725.0f, 600.0f ) );
	Vec2 GridStart = Vec2( walls.left + wallWidth + 5, walls.top + wallWidth + 5 );
	Vec2 GridEnd = Vec2( walls.right - wallWidth - 5, walls.bottom - wallWidth - 5 );
	static constexpr int wallWidth = 11;
	static constexpr float brickWidth = 31.0f;
	static constexpr float brickHeight = 15.0f;
	static constexpr int rows = 4;
	static constexpr int cols = 20;
	static constexpr int nBricks = rows * cols;
	Brick bricks[nBricks];
	Sound brickSound;
	Sound padSound;
	bool isGameOver = false;
	bool isGameStarted = false;
	/********************************/
};