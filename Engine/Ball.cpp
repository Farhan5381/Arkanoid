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

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall( pos, gfx );
}
