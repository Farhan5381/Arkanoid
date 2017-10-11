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
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(391.0f,480.0f),Vec2(-125.0f,-125.0f)),
	brickSound( L"Sounds\\arkbrick.wav" ),
	padSound(L"Sounds\\arkpad.wav"),
	lifelost( L"Sounds\\ah.wav" ),
	gameOverSound(L"Sounds\\gameOver.wav")
{
	int i = 0;
	for( int x = 0; x < cols; x++ )
	{
		for( int y = 0; y < rows; y++ )
		{
			float brick_x = GridStart.x + ( float (x) * (Brick::GetDimension().x + 2));
			float brick_y = GridStart.y + ( float (y) * (Brick::GetDimension().y + rowOffset) );
			bricks[i] = Brick( Vec2( brick_x, brick_y ), y, true );
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while( elapsedTime > 0.0f )
	{
		const float dt = std::min( 0.025f, elapsedTime );
		UpdateModel( dt );
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	if( isGameStarted && !isGameOver && !gameIsPaused )
	{
		ball.Update( dt );
		pad.Update( wnd.kbd, dt );
		pad.DoWallColision( innerwalls );
		
		if( wnd.kbd.KeyIsPressed( VK_NUMPAD0 ) )
		{
			pad.SetPadId( 0 );
		}
		else if( wnd.kbd.KeyIsPressed( VK_NUMPAD1 ) )
		{
			pad.SetPadId( 1 );
		}
		else if ( wnd.kbd.KeyIsPressed(VK_NUMPAD2) )
		{
			pad.SetPadId( 2 );
		}
		if( wnd.kbd.KeyIsPressed( VK_NUMPAD3 ) )
		{
			ball.SwapFlamingBallState();
		}

		/*
			Check the ball collision with the brick and determine which has collision has least amount
			of distance between ball and brick center.
		*/

		bool collisionHappend = false;
		float curColDistSq;
		int curColIndex;

		for( int i = 0; i < nBricks; i++ )
		{
			if( bricks[i].CheckBallCollision( ball ) )
			{
				const float newColDistSq = (ball.GetRect().GetCenter() - bricks[i].GetCenter()).GetLengthSq();
				if( collisionHappend )
				{
					if( newColDistSq < curColDistSq )
					{
						curColDistSq = newColDistSq;
						curColIndex = i;
					}
				}
				else
				{
					curColDistSq = newColDistSq;
					curColIndex = i;
					collisionHappend = true;
				}
			}
		}

		/*
			All collision which play sound are below
		*/
		if( collisionHappend )
		{
			bricks[curColIndex].DoBallCollision(ball);
			brickSound.Play();
			pad.ResetCoolDown();
		}
		if( pad.DoBallColision( ball ) )
		{
			padSound.Play();
		}
		if( ball.ReboundFromWalls( innerwalls ) )
		{
			pad.ResetCoolDown();
			padSound.Play();
		}

		/*
			Life reduction and GameOver check
		*/

		
		if( ball.GetOutOfBounds() )
		{
			lives--;
			if( lives > 0 )
			{
				lifelost.Play();
				pad = Pad();
				ball = Ball( Vec2( 391.0f, 480.0f ), Vec2( -125.0f, -125.0f ) );
				gameIsPaused = true;
			}
			else
			{
				gameOverSound.Play();
				isGameOver = true;
			}
		}
	}
	else
	{
		if( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			isGameStarted = true;
			gameIsPaused = false;
		}
	}
}

void Game::ComposeFrame()
{
	// Drawing walls
	gfx.DrawRect( outerwalls, Colors::Cyan );
	gfx.DrawRect( innerwalls, Colors::Black );
	pad.Draw( gfx );
	ball.Draw( gfx );
	
	for( int i = 0; i < nBricks; i++ )
	{
		bricks[i].Draw( gfx );
	}

	for( int i = 0; i < lives; i++ )
	{
		Vec2 livesPos = Vec2( innerwalls.left + 20.0f + ( i * 20 ), pad.GetRect().bottom + 25.0f );
		SpriteCodex::DrawBallFlame( livesPos, gfx );
	}
}
