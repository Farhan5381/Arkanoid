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

		if( ball.GetVelocity().x > 0.0f &&  ball.GetVelocity().y > 0.0f )
		{
			if( rect.top > ball.GetRect().bottom )
			{
				ball.ReboundY();
			}
			else if( rect.left > ball.GetRect().right )
			{
				ball.ReboundX();
			}
		}
		else if( ball.GetVelocity().x < 0.0f &&  ball.GetVelocity().y > 0.0f )
		{
			if( rect.top > ball.GetRect().bottom )
			{
				ball.ReboundY();
			}
			else if( rect.right > ball.GetRect().left )
			{
				ball.ReboundX();
			}
		}
		else if( ball.GetVelocity().x < 0.0f &&  ball.GetVelocity().y < 0.0f )
		{
			if( rect.bottom > ball.GetRect().top )
			{
				ball.ReboundY();
			}
			else if( rect.right > ball.GetRect().left )
			{
				ball.ReboundX();
			}
		}
		else if( ball.GetVelocity().x > 0.0f &&  ball.GetVelocity().y < 0.0f )
		{
			if( rect.bottom > ball.GetRect().top )
			{
				ball.ReboundY();
			}
			else if( rect.left > ball.GetRect().right )
			{
				ball.ReboundX();
			}
		}

		coliding = true;
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
