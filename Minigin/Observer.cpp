#include "Observer.h"
//#include "PlayerComp.h"
#include "TextObject.h"
#include <iostream>

void dae::GamePlay::OnNotify(GameObject* ob, const Event& event)
{
	//PlayerComp* comp = (PlayerComp*)ob->GetComponent(PlayerComp(nullptr, 0));
	TextObject* textOb;
	ob = nullptr;
	switch (event)
	{
	case dae::Event::POINT_INCREASE:
		//if (comp != nullptr)
		{
			//if (comp->GetScore() == 500)
			{
				//unlock achievment
			}
		}
	case dae::Event::TOOK_DAMAGE:
		//if (comp != nullptr)
		{
			textOb = (TextObject*)m_UI->GetComponent(TextObject("", nullptr));
			if (textOb != nullptr)
			{
				//std::string text = "life: " + std::to_string(comp->GetHP()) + " score: " + std::to_string(comp->GetScore());

				//textOb->SetText(text);
			}
		}

		break;

	case dae::Event::IS_DEAD:
		std::cout << "a player hase died\n";
		break;
	}
}
