#include "MyGame.h"
#include "Engine.h"

#include <memory>

bool MyGame::Initialize()
{
	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	m_scene = std::make_unique<Scene>(m_engine);
	m_scene->Read(document);
	m_scene->Initialize();

	ADD_OBSERVER(PlayerDead, MyGame::OnPlayerDead);
	ADD_OBSERVER(AddPoints, MyGame::OnAddPoints);

    return true;
}

void MyGame::Shutdown()
{

	m_scene->RemoveAll();
}

void MyGame::Update(float dt)
{
	m_scene->Update(m_engine->GetTime().GetDeltaTime());
}

void MyGame::Draw(Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnPlayerDead(const Event& event)
{
	std::cout << "game player dead\n";
}

void MyGame::OnAddPoints(const Event& event)
{
	m_score += std::get<int>(event.data);
	std::cout << m_score << std::endl;
}
