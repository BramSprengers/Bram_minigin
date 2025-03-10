#pragma once
#include "BaseComponent.h"
#include "GameObject.h"

namespace dae
{
	class MoveComponent : public BaseComponent
	{
	public:
		MoveComponent(GameObject* pOwner) : BaseComponent{ pOwner } {};
		~MoveComponent() = default;

		MoveComponent(const				MoveComponent& other) = delete;
		MoveComponent(					MoveComponent&& other) = delete;
		MoveComponent& operator=(const	MoveComponent& other) = delete;
		MoveComponent& operator=(		MoveComponent&& other) = delete;

		void SetSpeed(float speed) { m_speed = speed; }
		void UpdateDirection(glm::vec2 dir) { m_dir = dir; }

		void Update(float deltaTime) override;
		void FixedUpdate(float fixedDeltaTime) override;
		void Render() const override;

	private:
		glm::vec2 m_dir{};
		float m_speed{};
	};
}

