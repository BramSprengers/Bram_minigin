#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "BaseComponent.h"
#include "TextObject.h"
#include "Texture2D.h"
#include "FPSComponent.h"
#include "RotationComponent.h"
#include "ImGuiComponent.h"
#include "Scene.h"
#include "InputManager.h"
#include <chrono>
#include "PlayerComp.h"
//#include "Observer.h"

void load()
{
	auto& input = dae::InputManager::GetInstance();

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent(new dae::Texture2D(go.get(), dae::ResourceManager::GetInstance().LoadTexture("background.tga").get()->GetSDLTexture()));
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent(new dae::Texture2D(go.get(), dae::ResourceManager::GetInstance().LoadTexture("logo.tga").get()->GetSDLTexture()));
	go->SetPosition(216, 180);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	std::shared_ptr<dae::GameObject> to{ new dae::GameObject() };
	to->AddComponent(new dae::TextObject(to.get(), "Programming 4 Assignment", font));
	to->SetPosition(80, 20);
	scene.Add(to);

	to = std::make_shared<dae::GameObject>();
	dae::TextObject* text{ new dae::TextObject(to.get(), "0", font) };
	dae::FPSComponent* fps{ new dae::FPSComponent(to.get(),text) };
	to->AddComponent(text);
	to->AddComponent(fps);
	scene.Add(to);

	float ofset = 60;

	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 16);
	to = std::make_shared<dae::GameObject>();
	to->SetPosition(0, ofset);
	text = new dae::TextObject(to.get(), "Playe one movement: W,A,S,D. damage: space bar. adding score: C.", font);
	to->AddComponent(text);
	scene.Add(to);

	ofset += 16;

	to = std::make_shared<dae::GameObject>();
	to->SetPosition(0, ofset);
	text = new dae::TextObject(to.get(), "Playe two movement: DEPAD. damage: A button. adding score: B button.", font);
	to->AddComponent(text);
	scene.Add(to);

	ofset += 30;

	std::shared_ptr<dae::GameObject> orb{ new dae::GameObject() };
	orb->SetPosition(50, 100);
	dae::Texture2D* texture{ new dae::Texture2D(orb.get(),
		dae::ResourceManager::GetInstance().LoadTexture("greenOrb.png").get()->GetSDLTexture()) };

	//dae::RotationComponent* rot{new dae::RotationComponent(orb.get(),5)};
	//orb->AddComponent(rot);
	/*float speed{ 10 };*/

	dae::PlayerComp* player = new dae::PlayerComp(orb.get(), 3);

	to = std::make_shared<dae::GameObject>();
	to->SetPosition(0, ofset);
	text = new dae::TextObject(to.get(), "life: 3 score: 0", font);
	to->AddComponent(text);
	scene.Add(to);

	dae::GamePlay* ui = new dae::GamePlay(to.get());

	player->AddObserver(ui);
	orb->AddComponent(player);
	orb->AddComponent(texture);
	scene.Add(orb);

	input.SetPlayerTwo(orb.get());

	std::shared_ptr<dae::GameObject> sosig{ new dae::GameObject() };
	texture = new dae::Texture2D(sosig.get(),
		dae::ResourceManager::GetInstance().LoadTexture("redSosig.png").get()->GetSDLTexture());

	//rot = new dae::RotationComponent(sosig.get(),10);
	//sosig->AddComponent(rot);

	ofset += 16;


	to = std::make_shared<dae::GameObject>();
	to->SetPosition(0, ofset);
	text = new dae::TextObject(to.get(), "life: 3 score: 0", font);
	to->AddComponent(text);
	scene.Add(to);

	ui = new dae::GamePlay(to.get());

	player = new dae::PlayerComp(sosig.get(), 3);
	player->AddObserver(ui);

	sosig->AddComponent(texture);
	sosig->AddComponent(player);

	scene.Add(sosig);

	input.SetPlayerOne(sosig.get());
	//std::shared_ptr<dae::GameObject> gui{ new dae::GameObject() };
	//dae::ImGuiComponent* imgui = new dae::ImGuiComponent(gui.get());
	//gui->AddComponent(imgui);
	//scene.Add(gui);


}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}