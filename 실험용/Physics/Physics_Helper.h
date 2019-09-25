#pragma once
#include "pch.h"

#pragma warning(push, 0)
#include <LinearMath/btQuaternion.h>
#pragma warning(pop)

namespace BulletPhysicsHelper
{
	inline const D3DXVECTOR3 ToD3DXVector3(const btVector3& vec)
	{
		return D3DXVECTOR3(vec.getX(), vec.getY(), vec.getZ());
	}

	inline const D3DXVECTOR4 ToVector4(const btVector4& vec)
	{
		return D3DXVECTOR4(vec.getX(), vec.getY(), vec.getZ(), vec.getW());
	}

	inline const D3DXQUATERNION ToD3DXQuaternion(const btQuaternion& qut)
	{
		return D3DXQUATERNION(qut.getX(), qut.getY(), qut.getZ(), qut.getW());
	}

	inline const btVector3 ToBtVector3(const D3DXVECTOR3& vec)
	{
		return btVector3(vec.x, vec.y, vec.z);
	}

	inline const btQuaternion ToBtQuaternion(const D3DXQUATERNION& qut)
	{
		return btQuaternion(qut.x, qut.y, qut.z, qut.w);
	}

}