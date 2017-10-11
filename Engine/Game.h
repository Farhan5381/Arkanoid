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
	static constexpr int wallWidth = 11;
	RectF outerwalls = RectF( Vec2( 55.0f, 0.0f ), Vec2( 745.0f, 600.0f ) );
	RectF innerwalls = outerwalls.GetScaled( -wallWidth );
	Vec2 GridStart = Vec2( innerwalls.left + 4, innerwalls.top + 10);
	Vec2 GridEnd = Vec2( innerwalls.right, innerwalls.bottom);
	static constexpr int rows = 5;
	static constexpr int cols = 20;
	static constexpr int nBricks = rows * cols;
	static constexpr float rowOffset = 25.0f;
	Brick bricks[nBricks];
	Sound brickSound;
	Sound padSound;
	Sound lifelost;
	Sound gameOverSound;
	int lives = 5;
	bool isGameOver = false;
	bool isGameStarted = false;
	bool gameIsPaused = false;
	/********************************/
};