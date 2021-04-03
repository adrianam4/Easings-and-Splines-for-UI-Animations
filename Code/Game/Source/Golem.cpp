#include "App.h"
#include "Render.h"
#include "Textures.h"
#include "Font.h"
#include "Input.h"

#include "Golem.h"


Golem::Golem(iPoint pos) : Enemy(EntityType::GOLEM)
{
	bounds = { pos.x, pos.y, 49, 47 };
	texture = app->tex->Load("Assets/Textures/Enemies/golem.png");
	name = "Golem";
	
	health = 100.0f;
	mana = 50.0f;
	damage = 20.0f;
	defense = 20.0f;
	speed = 10.0f;

	font = new Font("Assets/Font/font3.xml", app->tex);

	position_x = 100.0f;
	position_y = 100.0f;

	currentFrame = 0;

	easingActivated = false;

	/*easing->currentIteration = 0;
	easing->totalIterations = 100;
	easing->initialPos = 100;
	easing->deltaPos = 400;*/
}

Golem::~Golem()
{
}

bool Golem::Load()
{
	

	return true;
}

bool Golem::Update(float dt)
{
	if (app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
		currentFrame = 0;
		position_x = 100;
		easingActivated = true;
	}

	if (easingActivated == true)
	{
		position_x = easing->linearEaseInOut(currentFrame, 100, 800, 250);
		position_y = easing->linearEaseInOut(currentFrame, 100, 300, 250);
	}

	if (currentFrame < 250)
	{
		currentFrame++;
	}
	else
	{
		currentFrame = 0;
		easingActivated = false;
	}
	
	return true;
}

bool Golem::CheckCollisions()
{
	return true;
}

void Golem::Draw(bool showColliders)
{
	if (showColliders) 	
		app->render->DrawRectangle(bounds, 0, 0, 255, 255);

	SDL_Rect rect = { 2,3,bounds.w,bounds.h };
	app->render->DrawTexture(texture, position_x, position_y, &rect);

	SDL_Color color = { 255,255,255,255 };
	app->render->DrawText(font, "GOLEM", bounds.x, bounds.y - 15, 15, 5, color);

	char tmp[32] = { 0 };

	sprintf_s(tmp, 32, "Health: %.0f", health);
	color = { 0,255,0,255 };
	app->render->DrawText(font, tmp, bounds.x + bounds.w + 5, bounds.y, 15, 5, color);

	sprintf_s(tmp, 32, "Mana: %.0f", mana);
	color = { 0,0,255,255 };
	app->render->DrawText(font, tmp, bounds.x + bounds.w + 5, bounds.y + 20, 15, 5, color);
}

bool Golem::UnLoad()
{
	return true;
}

bool Golem::LoadState(pugi::xml_node& node)
{
	return true;
}

bool Golem::SaveState(pugi::xml_node& node)
{
	return true;
}
