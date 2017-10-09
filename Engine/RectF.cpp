#include "RectF.h"

RectF::RectF( float top_in, float right_in, float bottom_in, float left_in )
	:
	top( top_in ),
	right( right_in ),
	bottom( bottom_in ),
	left(left_in)
{
}

RectF::RectF( const Vec2 & top_left, const Vec2 & bottom_right )
	:
	RectF(top_left.y, bottom_right.x,bottom_right.y,top_left.x)
{
}

RectF::RectF( const Vec2 & top_left, const float & width, const float & height )
	:
	RectF(top_left,Vec2(top_left.x + width, top_left.y + height))
{
}

bool RectF::isColidingRect( const RectF & rect )
{
	return 
		top <= rect.bottom &&
		right >= rect.left &&
		bottom >= rect.top &&
		left <= rect.right;
}
