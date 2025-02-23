#pragma once
#include <memory>
#include <vector>
#include "Transform.h"
#include "BaseComponent.h"

namespace dae
{
	class GameObject final
	{
	public:
		void Update(float deltaTime);
		void Render() const;

		void SetPosition(float x, float y);

		glm::vec3 GetPosition() const { return m_transform.GetPosition(); };

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};

		std::vector<std::shared_ptr<dae::BaseComponent>> m_Class{};
	};
}
