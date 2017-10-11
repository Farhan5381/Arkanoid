#include "Ball.h"

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
		pos.x = walls.right - (radius * 2);
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
		pos.y = walls.bottom - (radius * 2);
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
	if( flamingBall )
	{
		SpriteCodex::DrawBallFlame( pos, gfx );
	}
	else
	{
		SpriteCodex::DrawBallNormal( pos, gfx );
	}
}

RectF Ball::GetRect() const
{
	return RectF(pos, radius * 2.0f, radius * 2.0f);
}

bool Ball::GetOutOfBounds() const
{
	return outOfBounds;
}

void Ball::SetOutofBoundsFalse()
{
	outOfBounds = false;
}

void Ball::SwapFlamingBallState()
{
	if( flamingBall )
	{
		flamingBall = false;
	}
	else
	{
		flamingBall = true;
	}
}

bool Ball::GetFlamingBallState()
{
	return flamingBall;
}
