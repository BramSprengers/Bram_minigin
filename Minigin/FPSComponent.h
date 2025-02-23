#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "TextObject.h"
namespace dae
{
	class FPSComponent : public BaseComponent
	{
	public:
		FPSComponent(dae::GameObject* ob, TextObject* txt) : dae::BaseComponent(ob), m_FPSTexture{} { m_FPSTexture = txt; };
		~FPSComponent() = default;
		FPSComponent(const	FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const	FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;

		void Update(float deltaTime) override;
		void FixedUpdate(float fixedDeltaTime) override;
		void Render() const override;
	private:
		TextObject* m_FPSTexture;
	};
}

