/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(560.0f,560.0f),Vec2(200.0f,200.0f))
{
	Vec2 GridStart = Vec2( 20.0f, 20.0f );
	Color rowColors[rows] = { Colors::Red,Colors::Green,Colors::Blue,Colors::Gray };
	int i = 0;
	for( int x = 0; x < cols; x++ )
	{
		for( int y = 0; y < rows; y++ )
		{
			Color c = rowColors[y];
			float brick_x = GridStart.x + ( x * brickWidth );
			float brick_y = GridStart.y + ( y * brickHeight );
			bricks[i] = Brick( RectF( Vec2( brick_x, brick_y ), brickWidth , brickHeight ), c );
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Update( dt );
	ball.ReboundFromWalls(walls);
	for( int i = 0; i < nBricks; i++ )
	{
		if( bricks[i].ColidedWithBall( ball ) )
		{
			break;
		}
	}
}

void Game::ComposeFrame()
{
	ball.Draw( gfx );

	for( int i = 0; i < nBricks; i++ )
	{
		bricks[i].Draw( gfx );
	}
}
