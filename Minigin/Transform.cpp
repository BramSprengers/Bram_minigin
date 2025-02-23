#include "Transform.h"

void dae::Transform::SetWorldPosition(const float x, const float y, const float z)
{
	m_worldPosition.x = x;
	m_worldPosition.y = y;
	m_worldPosition.z = z;
}

void dae::Transform::SetLocalposition(float x, float y, float z)
{
	m_localPosition.x = x;
	m_localPosition.y = y;
	m_localPosition.z = z;
}
