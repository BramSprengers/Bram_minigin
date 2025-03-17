#pragma once
#include "Singleton.h"
#include "MoveCommand.h"
#include <Windows.h>
#include <Xinput.h>
#include <glm.hpp>

#include "Observer.h"

namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput(float deltaTime);
		void HandleControlerMoveInput(float deltaTime);

		bool IsDown(unsigned int button) const { return buttonsPressedThisFrame & button; }
		bool IsUp(unsigned int button) const { return buttonsReleasedThisFrame & button; }
		bool IsPressed(unsigned int button) const { return state.Gamepad.wButtons & button; }

		void SetPlayerOne(GameObject* player) { m_PlayerOne = player; }
		void SetPlayerTwo(GameObject* player) { m_PlayerTwo = player; }

		glm::vec2 LeftStick() const { 
			int x = state.Gamepad.sThumbLX;
			int y = state.Gamepad.sThumbLY;
			if (abs(x) < deadZone) x = 0;
			if (abs(y) < deadZone) y = 0;

			return glm::vec2(x, y);
		}

		glm::vec2 RightStick() const {
			int x = state.Gamepad.sThumbRX;
			int y = state.Gamepad.sThumbRY;
			if (abs(x) < deadZone) x = 0;
			if (abs(y) < deadZone) y = 0;

			return glm::vec2(x, y);
		}

		int LeftTriger() const { return state.Gamepad.bLeftTrigger; }
		int RightTriger() const { return state.Gamepad.bRightTrigger; }

	private:

		XINPUT_STATE state{};
		XINPUT_STATE prevState{};

		int buttonsPressedThisFrame{};
		int	buttonsReleasedThisFrame{};

		int deadZone{ 2000 };

		dae::GameObject* m_PlayerOne{};
		dae::GameObject* m_PlayerTwo{};
	};

}
