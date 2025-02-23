#pragma once
namespace dae
{
	class GameObject;
	class BaseComponent
	{
		GameObject* m_pOwner;
	public:
		virtual ~BaseComponent() = default;
		BaseComponent(const				BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const	BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float fixedDeltaTime);
		virtual void Render();

	protected:
		explicit BaseComponent(GameObject* pOwner) : m_pOwner{ pOwner } {};
		GameObject* GetOwner() const { return m_pOwner; }
	};
}

