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

bool Ball::ReboundFromWalls( const RectF& walls )
{
	bool rebound = false;
	RectF ballRect = GetRect();
	if( ballRect.left < walls.left )
	{
		pos.x = walls.left + radius;
		ReboundX();
		rebound = true;
	}
	else if( ballRect.right > walls.right )
	{
		pos.x = walls.right - radius;
		ReboundX();
		rebound = true;
	}

	if( ballRect.top < walls.top )
	{
		pos.y = walls.top + radius;
		ReboundY();
		rebound = true;
	}
	else if( ballRect.bottom > walls.bottom )
	{
		pos.y = walls.bottom - radius;
		ReboundY();
		outOfBounds = true;
	}
	return rebound;
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

bool Ball::GetOutOfBounds() const
{
	return outOfBounds;
}

void Ball::SetOutofBoundsFalse()
{
	outOfBounds = false;
}
