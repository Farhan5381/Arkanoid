#include "Brick.h"

Brick::Brick( const RectF & rect_in, Color c_in )
	:
	rect(rect_in),
	c(c_in)
{
}

bool Brick::ColidedWithBall( Ball & ball )
{
	bool coliding = false;
	if( !destroyed && rect.isColidingRect( ball.GetRect() ) )
	{
		destroyed = true;
		coliding = true;

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
		if( l_collision < r_collision && l_collision < t_collision && l_collision < b_collision )
		{
			//Left collision
			ball.ReboundX();
		}
		if( r_collision < l_collision && r_collision < t_collision && r_collision < b_collision )
		{
			//Right collision
			ball.ReboundX();
		}
	}
	return coliding;
}

void Brick::Draw( Graphics& gfx )
{
	RectF newRect = RectF( rect.top + 2.0f, rect.right - 2.0f, rect.bottom - 2.0f, rect.left + 2.0f );
	if( !destroyed )
	{
		gfx.DrawRect( newRect, c );
	}
}
