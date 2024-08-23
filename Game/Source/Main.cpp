#include "Engine.h"
#include "MyGame.h"
#include "Components/PlayerComponent.h"

#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char* argv[])
{

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();
	
	std::unique_ptr<MyGame> game = std::make_unique<MyGame>(engine.get());
	game->Initialize();


	while (!engine->IsQuit())
	{
		// update
		engine->Update();
		game->Update(engine->GetTime().GetDeltaTime());
		// render
		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();

		game->Draw(engine->GetRenderer());

		engine->GetRenderer().EndFrame();
	}

	game->Shutdown();
	ResourceManager::Instance().Clear();
	engine->Shutdown();

	return 0;
}