#include "App.h"
#include "Input.h"
#include "Render.h"
#include "Textures.h"

#include "Tabern.h"

Tabern::Tabern(iPoint position) :Npc(EntityType::TABERN, position)
{
	/*bounds = { 0,0, 16,32 };
	type = EntityType::TABERN;*/
}

Tabern::~Tabern()
{
}

bool Tabern::Load()
{
	//texture = app->tex->Load("Assets/Textures/hunter_spritesheet.png");
	return true;
}

bool Tabern::Update(float dt)
{


	return true;
}

void Tabern::Draw(bool showColliders)
{
	if (showColliders) app->render->DrawRectangle(bounds, 255, 0, 0);
	SDL_Rect textureRect = { 23, 14, 51,81 };
	app->render->DrawTexture(texture, bounds.x, bounds.y, &textureRect);
}

bool Tabern::UnLoad()
{
	return true;
}


bool Tabern::SaveState(pugi::xml_node& node)
{
	Npc::SaveState(node);
	pugi::xml_node auxiliar1;
	auxiliar1 = node.append_child("NpcType");

	auxiliar1.append_attribute("type").set_value("TABERN");
	return true;
}