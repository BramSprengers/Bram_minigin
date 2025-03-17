#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Singleton.h"
#include "steamAchievements.h"

namespace dae
{
	enum EAchievements
	{
		ACH_WIN_ONE_GAME = 0,
		ACH_WIN_100_GAMES = 1,
		ACH_TRAVEL_FAR_ACCUM = 2,
		ACH_TRAVEL_FAR_SINGLE = 3,
	};

	class GameObject;

	enum class Event
	{
		TOOK_DAMAGE,
		POINT_INCREASE,
		IS_DEAD
	};

	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void OnNotify(GameObject* ob, const Event& event) = 0;
	};

	class GamePlay : public Observer
	{
	public:
		GamePlay(GameObject* ob) : m_UI{ ob }
		{
			bool bRet = SteamAPI_Init();
			// Create the SteamAchievements object if Steam was successfully initialized
			if (bRet)
			{
				g_SteamAchievements = new steamAchievements(g_Achievements, 4);
			}
		}
		~GamePlay() override {
			SteamAPI_Shutdown();

			if (g_SteamAchievements)
				delete g_SteamAchievements;
		}

		void OnNotify(GameObject* ob, const Event& event) override;
	private:
		GameObject* m_UI;

		Achievement_t g_Achievements[4]
		{
			_ACH_ID(ACH_WIN_ONE_GAME, "Winner"),
			_ACH_ID(ACH_WIN_100_GAMES, "Champion"),
			_ACH_ID(ACH_TRAVEL_FAR_ACCUM, "Interstellar"),
			_ACH_ID(ACH_TRAVEL_FAR_SINGLE, "Orbiter"),
		};

		steamAchievements* g_SteamAchievements = NULL;
	};
}

