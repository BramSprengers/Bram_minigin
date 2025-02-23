#pragma once
#include "BaseComponent.h"

namespace dae
{
	class GameObject;
	class RotationComponent : public BaseComponent
		{
		public:
			RotationComponent(GameObject* ob, float radius) : BaseComponent(ob), m_rad{ radius } {};
			virtual ~RotationComponent() {};
			RotationComponent(const				RotationComponent& other) = delete;
			RotationComponent(					RotationComponent&& other) = delete;
			RotationComponent& operator=(const	RotationComponent& other) = delete;
			RotationComponent& operator=(		RotationComponent&& other) = delete;

			void Update(float deltaTime) override;

		private:
			float m_rot{};
			const float m_rad;
		};
	}

