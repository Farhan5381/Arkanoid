#include "Brick.h"
#include <assert.h>

Brick::Brick( const Vec2& pos_in, int brickTypeId, bool createBrick )
	:
	pos(pos_in),
	TypeId(brickTypeId),
	destroyed(!createBrick)
{
}

bool Brick::CheckBallCollision( const Ball & ball ) const
{
	return !destroyed && GetRect().isColidingRect( ball.GetRect() );
}

void Brick::DoBallCollision( Ball & ball )
{
	assert( CheckBallCollision( ball ) );

	const float b_collision = GetRect().bottom - ball.GetRect().top;
	const float t_collision = ball.GetRect().bottom - GetRect().top;
	const float l_collision = ball.GetRect().right - GetRect().left;
	const float r_collision = GetRect().right - ball.GetRect().left;

	if( t_collision < b_collision && t_collision < l_collision && t_collision < r_collision )
	{
		//Top collision
		if( !ball.GetFlamingBallState() )
		{
			ball.ReboundY();
		}
	}
	if( b_collision < t_collision && b_collision < l_collision && b_collision < r_collision )
	{
		//bottom collision
		if( !ball.GetFlamingBallState() )
		{
			ball.ReboundY();
		}
	}
	if( l_collision < r_collision && l_collision < t_collision && l_collision < b_collision )
	{
		//Left collision
		if( !ball.GetFlamingBallState() )
		{
			ball.ReboundX();
		}
	}
	if( r_collision < l_collision && r_collision < t_collision && r_collision < b_collision )
	{
		//Right collision
		if( !ball.GetFlamingBallState() )
		{
			ball.ReboundX();
		}
	}

	destroyed = true;

}

void Brick::Draw( Graphics& gfx )
{
	if( !destroyed )
	{
		switch( TypeId )
		{
		case 0:
			SpriteCodex::DrawRedBrick( pos, gfx );
			break;
		case 1:
			SpriteCodex::DrawGreenBrick( pos, gfx );
			break;
		case 2:
			SpriteCodex::DrawBlueBrick( pos, gfx );
			break;
		case 3:
			SpriteCodex::DrawYellowBrick( pos, gfx );
			break;
		case 4:
			SpriteCodex::DrawOrangeBrick( pos, gfx );
			break;
		}
	}
}

RectF Brick::GetRect() const
{
	return RectF(pos,width, height);
}

Vec2 Brick::GetCenter() const
{
	return GetRect().GetCenter();
}

Vec2 Brick::GetDimension()
{
	return Vec2(width,height);
}
