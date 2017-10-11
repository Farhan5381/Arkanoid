#include "Pad.h"

Pad::Pad( const Vec2 & pos_in, float width_in, float height_in )
	:
	pos( pos_in ),
	halfWidth(width_in/2),
	halfHeight(height_in/2)
{
}

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
		pos.x = walls.left + halfWidth;
	}
	else if( rect.right > walls.right )
	{
		pos.x = walls.right - halfWidth;
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
				ball.ReboundY();
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
	RectF outerRect = GetRect();
	RectF innerRect = RectF( Vec2( outerRect.left + wingWidth, outerRect.top ), Vec2( outerRect.right - wingWidth, outerRect.bottom ) );
	gfx.DrawRect( outerRect, wingColor );
	gfx.DrawRect( innerRect, padColor );
}

RectF Pad::GetRect() const
{
	return RectF::FromCenter( pos, halfWidth, halfHeight );
}

void Pad::ResetCoolDown()
{
	isCoolDown = false;
}
