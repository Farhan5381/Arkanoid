#include "Pad.h"

void Pad::Update( const Keyboard & kbd, float dt )
{
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		pos.x -= speed * dt;
	}
	else if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		pos.x += speed * dt;
	}
}

void Pad::DoWallColision( const RectF & walls )
{
	RectF rect = GetRect();
	if( rect.left < walls.left )
	{
		pos.x = walls.left;
	}
	else if( rect.right > walls.right )
	{
		pos.x = walls.right - width;
	}
}

bool Pad::DoBallColision( Ball & ball )
{
	bool colided = false;
	if( !isCoolDown )
	{
		RectF rect = GetRect();
		if( rect.isColidingRect( ball.GetRect() ) )
		{
			const float b_collision = rect.bottom - ball.GetRect().top;
			const float t_collision = ball.GetRect().bottom - rect.top;
			const float l_collision = ball.GetRect().right - rect.left;
			const float r_collision = rect.right - ball.GetRect().left;

			if( t_collision < b_collision && t_collision < l_collision && t_collision < r_collision )
			{
				//Top collision
				ball.ReboundY();
			}
			if( b_collision < t_collision && b_collision < l_collision && b_collision < r_collision )
			{
				//bottom collision
				//ball.ReboundY();
			}
			else if( l_collision < r_collision && l_collision < t_collision && l_collision < b_collision )
			{
				//Left collision
				ball.ReboundX();
				ball.ReboundY();
			}
			else if( r_collision < l_collision && r_collision < t_collision && r_collision < b_collision )
			{
				//Right collision
				ball.ReboundX();
				ball.ReboundY();
			}
			isCoolDown = true;
			colided = true;
		}
	}
	return colided;
}

void Pad::Draw( Graphics & gfx )
{
	switch( padId )
	{
	case 0:
		SpriteCodex::DrawpadSmall( pos, gfx );
		width = 70.0f;
		break;
	case 1:
		SpriteCodex::DrawpadNormal( pos, gfx );
		width = 120.0f;
		break;
	case 2:
		SpriteCodex::DrawpadBig( pos, gfx );
		width = 170.0f;
		break;
	}
}

RectF Pad::GetRect() const
{
	return RectF(pos,width,height);
}

void Pad::ResetCoolDown()
{
	isCoolDown = false;
}

void Pad::SetPadId( int Id )
{
	padId = Id;
}
