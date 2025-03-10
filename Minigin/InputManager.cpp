#include <SDL.h>
#include <SDL_keyboard.h>
#include "InputManager.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <iostream>

bool dae::InputManager::ProcessInput()
{
	dae::MoveCommand(m_PlayerTwo, { 0,0 }).Execute();

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			
			auto keys = SDL_GetKeyboardState(nullptr);

			float dirX{}, dirY{};

			if (keys[SDL_SCANCODE_W])
			{
				--dirY;
				dae::MoveCommand(m_PlayerTwo, { dirX,dirY }).Execute();
			}
			if (keys[SDL_SCANCODE_S]) {
				++dirY;
				dae::MoveCommand(m_PlayerTwo, { dirX,dirY }).Execute();
			}
			if (keys[SDL_SCANCODE_A]) {
				--dirX;
				dae::MoveCommand(m_PlayerTwo, { dirX,dirY }).Execute();
			};
			if (keys[SDL_SCANCODE_D]) {
				++dirX;
				dae::MoveCommand(m_PlayerTwo, { dirX,dirY }).Execute();
			};
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...
		ImGui_ImplSDL2_ProcessEvent(&e);
		
	}

	DWORD dwResult;
	for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
	{
		ZeroMemory(&state, sizeof(XINPUT_STATE));
		CopyMemory(&prevState, &state, sizeof(XINPUT_STATE));

		// Simply get the state of the controller from XInput.
		dwResult = XInputGetState(i, &state);

		if (dwResult == ERROR_SUCCESS)
		{
			auto buttonChanges = state.Gamepad.wButtons ^ prevState.Gamepad.wButtons;
			buttonsPressedThisFrame = buttonChanges & state.Gamepad.wButtons;
			buttonsReleasedThisFrame = buttonChanges & (~state.Gamepad.wButtons);

			HandleControlerMoveInput();
		}
	}

	return true;
}


void dae::InputManager::HandleControlerMoveInput()
{
	float dirX{}, dirY{};

	dae::MoveCommand(m_PlayerOne, { dirX,dirY }).Execute();

	if (IsPressed(XINPUT_GAMEPAD_DPAD_UP))
	{
		--dirY;
		dae::MoveCommand(m_PlayerOne, {dirX,dirY}).Execute();
	}
	if (IsPressed(XINPUT_GAMEPAD_DPAD_DOWN))
	{
		++dirY;
		dae::MoveCommand(m_PlayerOne, { dirX,dirY }).Execute();
	}
	if (IsPressed(XINPUT_GAMEPAD_DPAD_LEFT)) 
	{
		--dirX;
		dae::MoveCommand(m_PlayerOne, { dirX,dirY }).Execute();
	};
	if (IsPressed(XINPUT_GAMEPAD_DPAD_RIGHT)) 
	{
		++dirX;
		dae::MoveCommand(m_PlayerOne, { dirX,dirY }).Execute();
	};
}
