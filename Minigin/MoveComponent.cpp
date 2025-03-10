#include "MoveComponent.h"

void dae::MoveComponent::Update(float deltaTime)
{
	if(m_dir.x != 0 || m_dir.y != 0)
	m_dir = glm::normalize(m_dir);

	glm::vec2 pos = GetOwner()->GetWorldPosition();
	pos += m_dir * m_speed * deltaTime;
	GetOwner()->SetLocalPosition({ pos.x, pos.y, 0 });
}

void dae::MoveComponent::FixedUpdate(float)
{
}

void dae::MoveComponent::Render() const
{
}
