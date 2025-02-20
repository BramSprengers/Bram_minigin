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
#include "TextObject.h"
#include "Scene.h"

#include <chrono>

std::shared_ptr<dae::GameObject> m_fps{ new dae::GameObject() };

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	go->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->SetTexture("logo.tga");
	go->SetPosition(216, 180);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	std::shared_ptr<dae::GameObject> to{ new dae::GameObject() };
	to->SetTextObject(std::make_shared<dae::TextObject>("Programming 4 Assignment", font));
	to->SetPosition(80, 20);
	scene.Add(to);

	m_fps->SetTextObject(std::make_shared<dae::TextObject>("0", font));
	scene.Add(m_fps);
}

void update(float deltaTime)
{
	const int fpsCoiunter{ int(deltaTime * 1000) };
	m_fps->GetTextObject()->SetText(std::to_string(fpsCoiunter));
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load,update);
    return 0;
}