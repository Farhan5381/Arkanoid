#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float top_in, float right_in, float bottom_in, float left_in);
	RectF( const Vec2& top_left, const Vec2& bottom_right );
	RectF( const Vec2& top_left, const float& width, const float& height );
	static RectF FromCenter( const Vec2& center_pos, const float& halfWidth, const float& halfHeight );
	bool isColidingRect( const RectF& rect );
public:
	float top;
	float right;
	float bottom;
	float left;
};