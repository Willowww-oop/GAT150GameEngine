#include "Engine.h"
#include "Components/PlayerComponent.h"

#include <iostream>
#include <cstdlib>
#include <vector>


int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	Factory::Instance().Register<EnginePhysicsComponent>(EnginePhysicsComponent::GetTypeName());
	Factory::Instance().Register<PlayerComponent>(PlayerComponent::GetTypeName());

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	// !! this code is not neccessary, it just shows the contents of the file !!
	std::string buffer;
	File::ReadFile("Scenes/scene.json", buffer);
	// show the contents of the json file
	std::cout << buffer << std::endl;

	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	scene->Read(document);
	scene->Initialize();
	while (!engine->IsQuit())
	{
		// update
		engine->Update();
		scene->Update(engine->GetTime().GetDeltaTime());

		// render
		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();

		scene->Draw(engine->GetRenderer());

		engine->GetRenderer().EndFrame();
	}

	ResourceManager::Instance().Clear();
	engine->Shutdown();

	return 0;
}