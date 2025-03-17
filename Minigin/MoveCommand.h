#pragma once
#include "Command.h"

namespace dae
{
	class MoveCommand : public Command
	{

	public:
		MoveCommand(GameObject* ob, glm::vec2 dir, float speed) : m_ob{ ob }, m_dir{ dir }, m_speed{speed} {}
		virtual ~MoveCommand() = default;

		virtual void Execute() override { }

	protected:
		GameObject* GetGameOb() const { return m_ob; }
		glm::vec2 GetDir() const { return m_dir; }
		glm::vec2 m_dir;
		float m_speed;

	private:
		GameObject* m_ob;
	};

	class Move : public MoveCommand
	{
	public:
		Move(GameObject* ob, glm::vec2 dir) : MoveCommand(ob, dir, 10) {}
		void Execute(float deltaTime) 
		{
			if (m_dir.x != 0 || m_dir.y != 0)
				m_dir = glm::normalize(m_dir);

			glm::vec2 pos = GetGameOb()->GetWorldPosition();
			pos += m_dir * m_speed * deltaTime;
			GetGameOb()->SetLocalPosition({ pos.x, pos.y, 0 });
		}
	};
}

