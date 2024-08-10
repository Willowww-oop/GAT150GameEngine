#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>

/*class A
{
public:
	virtual ~A() { }
};
class B : public A 
{
	~B() { }
};
class BB : public B 
{
public: 
	~BB() { }
};


A* Create(std::string type)
{
	if (type == "B")
	{
		return new B();
	}
	if (type == "C")
	{
		return new C();
	}
	return nullptr;
}
*/

int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());


	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	std::string s;
	File::ReadFile("text.txt", s);
	std::cout << s << std::endl;

	rapidjson::Document document;
	Json::Load("text.txt", document);

	std::string name;
	int age;
	float speed;
	bool isSlay;
	VectorTwo position;
	Color color;


	READ_DATA(document, name);
	READ_DATA(document, age);
	READ_DATA(document, speed);
	READ_DATA(document, isSlay);
	READ_DATA(document, position);
	READ_DATA(document, color);

	std::cout << name << std::endl;
	std::cout << age << std::endl;
	std::cout << speed << std::endl;
	std::cout << isSlay << std::endl;
	std::cout << position.x << " " << position.y << std::endl;
	std::cout << color.r << "" << color.g << "" << color.b << "" << color.a << std::endl;


	{

		res_t <Texture> texture = ResourceManager::Instance().Get<Texture>("noted.png", engine->GetRenderer());

		Transform t ({ 30, 30 }, 0, 1);
		std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
		std::unique_ptr<TextureComponent> component = Factory::Instance().Create<TextureComponent>("TextureComponent");
		component->texture = texture;
		actor->AddComponent(std::move(component));

		res_t <Font> font = ResourceManager::Instance().Get<Font>("MoulinRougeFLF.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello", { 1, 1, 0, 1 });
		actor->SetTransform(Transform{ { 30, 30 }, 0, 1 });

		while (!engine->IsQuit())
		{
			engine->Update();

			actor->Update(engine->GetTime().GetDeltaTime());

			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();

			engine->GetRenderer().DrawTexture(texture.get(), 150, 150, 0);
			text->Draw(engine->GetRenderer(), 500, 500);

			actor->Draw(engine->GetRenderer());

			//g_engine.GetPS().Draw(g_engine.GetRenderer());

			engine->GetRenderer().EndFrame();

		}
	}

	ResourceManager::Instance().Clear();
	engine->Shutdown();

	return 0;
}
