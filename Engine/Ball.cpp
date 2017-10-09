#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball( const Vec2 & pos_in, const Vec2 & velocity_in )
	:
	pos(pos_in),
	velocity(velocity_in)
{
}

void Ball::Update( float dt )
{
	pos += velocity * dt;
}

void Ball::ReboundFromWalls( const RectF& walls )
{
	RectF ballRect = GetRect();
	if( ballRect.left < walls.left )
	{
		pos.x = walls.left + radius;
		ReboundX();
	}
	else if( ballRect.right > walls.right )
	{
		pos.x = walls.right - radius;
		ReboundX();
	}

	if( ballRect.top < walls.top )
	{
		pos.y = walls.top + radius;
		ReboundY();
	}
	else if( ballRect.bottom > walls.bottom )
	{
		pos.y = walls.bottom - radius;
		ReboundY();
	}
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall( pos, gfx );
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos,radius,radius);
}

Vec2 Ball::GetVelocity() const
{
	return velocity;
}
