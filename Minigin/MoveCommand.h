#pragma once
#include "Command.h"
#include "MoveComponent.h"

namespace dae
{
	class MoveCommand : public Command
	{

	public:
		MoveCommand(MoveComponent* ob, glm::vec2 dir) : m_ob{ ob }, m_dir{ dir } {};
		virtual ~MoveCommand() = default;

		virtual void Execute() override { m_ob->UpdateDirection(m_dir); };

	protected:
		MoveComponent* GetGameOb() const { return m_ob; }
		glm::vec2 GetDir() const { return m_dir; }

	private:
		MoveComponent* m_ob;
		glm::vec2 m_dir;
	};
}

