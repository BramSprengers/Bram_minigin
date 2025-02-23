#pragma once
namespace dae
{
	class GameObject;
	class BaseComponent
	{
	public:
		explicit BaseComponent(GameObject* pOwner) : m_pOwner{ pOwner } {};
		BaseComponent() : m_pOwner{} {};
		virtual ~BaseComponent();
		BaseComponent(const	BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const	BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float fixedDeltaTime);
		virtual void Render() const;

	protected:
		GameObject* GetOwner() const { return m_pOwner; }

	private:
		GameObject* m_pOwner;
	};
}

