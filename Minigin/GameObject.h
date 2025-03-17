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
		void FixedUpdate(float fixedTime);
		void Render() const;

		void SetPosition(float x, float y);

		//glm::vec3 GetPosition() const { return m_worldPosition; };

		void AddComponent(BaseComponent* comp);

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void SetParent(GameObject* parent, bool keepWorldPosition);

		void SetLocalPosition(const glm::vec3& pos);

		void MarktForDel() { 
			m_IsDead = true;
			for (const auto& comp : m_Components)
				comp->MarktDead();
		}
		bool IsMarktDead() { return m_IsDead; }
		void RemoveComp();

		const glm::vec3& GetWorldPosition();
		//const glm::vec3& GetLocalPosition() { return m_localPosition; }
		GameObject* GetParent() { return m_parent; }
		size_t GetChildCount() const { return m_children.size(); }
		GameObject* GetChildAt(unsigned int idx) const { return m_children[idx]; }

		BaseComponent* GetComponent(const BaseComponent& comp);

	private:
		bool m_IsDead{ false };

		//Transform m_transform{};
		void SetPositionDirty();
		std::vector<BaseComponent*> m_Components{};

		GameObject* m_parent{};
		std::vector<GameObject*> m_children{};

		bool m_positionIsDirty{false};

		glm::vec3 m_worldPosition{};
		glm::vec3 m_localPosition{};

		void UpdateWorldPosition();

		bool IsChild(GameObject* ob);

		void RemoveChild(GameObject* child)
		{
			m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
		}

		void AddChild(GameObject* child) { m_children.emplace_back(child); }
	};
}
