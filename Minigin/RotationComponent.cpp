#include "RotationComponent.h"
#include <iostream>

void dae::RotationComponent::Update(float deltaTime)
{
	const float radSpeed{ 90.f / 180.f * 3.1415f };
	m_rot += radSpeed * deltaTime;

	GameObject* ob = this->GetOwner()->GetParent();
	glm::vec3 pos = m_memPos;

	if (ob != nullptr)
		pos = { 0, 0, 0 };

	glm::vec3 rotOfset{ sinf(m_rot) * m_rad, cosf(m_rot) * m_rad, 0 };
	
	this->GetOwner()->SetLocalPosition(pos + rotOfset);
}
