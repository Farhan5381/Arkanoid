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

		if( rect.top > ball.GetRect().bottom )
		{
			ball.ReboundY();
		}
		else if( rect.bottom > ball.GetRect().top )
		{
			ball.ReboundY();
		}
		else if( rect.left > ball.GetRect().right )
		{
			ball.ReboundX();
		}
		else if( rect.right > ball.GetRect().left )
		{
			ball.ReboundX();
		}

		coliding = true;
	}
	return coliding;
}

void Brick::Draw( Graphics& gfx )
{
	if( !destroyed )
	{
		gfx.DrawRect( rect, c );
	}
}
