#include "FPSComponent.h"

void dae::FPSComponent::Update(float deltaTime)
{
	std::string fps{ std::to_string(int(deltaTime * 1000)) };

	m_FPSTexture->SetText(fps);
}

void dae::FPSComponent::FixedUpdate(float)
{
}

void dae::FPSComponent::Render() const
{
}
