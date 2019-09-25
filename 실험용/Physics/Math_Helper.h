#pragma once
#include "pch.h"

static inline D3DXQUATERNION operator+(const D3DXQUATERNION& lhs, const D3DXVECTOR3& rhs)
{
	D3DXVECTOR3 qVec(lhs.x, lhs.y, lhs.z);
	D3DXVECTOR3 cross1(qVec.Cross(rhs));
	D3DXVECTOR3 cross2(qVec.Cross(cross1));

	return rhs + (cross1 * w + cross2) * 2.0f;
}

