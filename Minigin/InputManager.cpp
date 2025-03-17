#include <SDL.h>
#include <SDL_keyboard.h>
#include "InputManager.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <iostream>

#include "PlayerComp.h"

bool dae::InputManager::ProcessInput(float deltaTime)
{
	dae::Move(m_PlayerTwo, { 0,0 }).Execute(deltaTime);

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
				dae::Move(m_PlayerTwo, { dirX,dirY }).Execute(deltaTime);
			}
			if (keys[SDL_SCANCODE_S]) 
			{
				++dirY;
				dae::Move(m_PlayerTwo, { dirX,dirY }).Execute(deltaTime);
			}
			if (keys[SDL_SCANCODE_A]) 
			{
				--dirX;
				dae::Move(m_PlayerTwo, { dirX,dirY }).Execute(deltaTime);
			};
			if (keys[SDL_SCANCODE_D]) 
			{
				++dirX;
				dae::Move(m_PlayerTwo, { dirX,dirY }).Execute(deltaTime);
			};
			if (keys[SDL_SCANCODE_SPACE])
			{
				PlayerComp* comp = (PlayerComp*)m_PlayerOne->GetComponent(PlayerComp(nullptr, 0));
				if (comp != nullptr)
				{
					comp->TakeDamage(1);
				}
			}
			if (keys[SDL_SCANCODE_C])
			{
				PlayerComp* comp = (PlayerComp*)m_PlayerOne->GetComponent(PlayerComp(nullptr, 0));
				if (comp != nullptr)
				{
					comp->AddScore(100);
				}
			}
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

			HandleControlerMoveInput(deltaTime);
		}
	}

	return true;
}


void dae::InputManager::HandleControlerMoveInput(float deltaTime)
{
	float dirX{}, dirY{};

	dae::Move(m_PlayerOne, { dirX,dirY }).Execute(deltaTime);

	if (IsPressed(XINPUT_GAMEPAD_DPAD_UP))
	{
		--dirY;
		dae::Move(m_PlayerOne, {dirX,dirY}).Execute(deltaTime);
	}
	if (IsPressed(XINPUT_GAMEPAD_DPAD_DOWN))
	{
		++dirY;
		dae::Move(m_PlayerOne, { dirX,dirY }).Execute(deltaTime);
	}
	if (IsPressed(XINPUT_GAMEPAD_DPAD_LEFT)) 
	{
		--dirX;
		dae::Move(m_PlayerOne, { dirX,dirY }).Execute(deltaTime);
	}
	if (IsPressed(XINPUT_GAMEPAD_DPAD_RIGHT)) 
	{
		++dirX;
		dae::Move(m_PlayerOne, { dirX,dirY }).Execute(deltaTime);
	}
	if (IsPressed(XINPUT_GAMEPAD_A))
	{
		PlayerComp* comp = (PlayerComp*)m_PlayerTwo->GetComponent(PlayerComp(nullptr, 0));
		if (comp != nullptr)
		{
			comp->TakeDamage(1);
		}
	}
	if (IsPressed(XINPUT_GAMEPAD_B))
	{
		PlayerComp* comp = (PlayerComp*)m_PlayerTwo->GetComponent(PlayerComp(nullptr, 0));
		if (comp != nullptr)
		{
			comp->AddScore(100);
		}
	}
}
