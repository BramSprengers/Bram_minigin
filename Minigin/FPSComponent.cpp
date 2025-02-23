#include "FPSComponent.h"
#include <iostream>

void dae::FPSComponent::Update(float deltaTime)
{
	float time = deltaTime * 1000;

	std::string fps{ std::to_string(time) + " FPS" };

	m_FPSTexture->SetText(fps);
}

void dae::FPSComponent::FixedUpdate(float)
{
}

void dae::FPSComponent::Render() const
{
}
