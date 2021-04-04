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

	position_x = 0.0f;
	position_y = 250.0f;

	currentIteration = 0;
	totalIterations = 180;
	initialPosition = 0;
	deltaPosition = 700;
	easingActivated = false;

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
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
	}

	if (easingActivated == true)
	{
		position_x = easing->backEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
	}

	if (currentIteration < totalIterations)
	{
		++currentIteration;
	}

	else
	{
		currentIteration = 0;
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
