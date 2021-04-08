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
		easingType = 0;
	}
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 1;
	}
	if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 2;
	}
	if (app->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 3;
	}
	if (app->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 4;
	}
	if (app->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 5;
	}
	if (app->input->GetKey(SDL_SCANCODE_U) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 6;
	}
	if (app->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 7;
	}
	if (app->input->GetKey(SDL_SCANCODE_O) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 8;
	}
	if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 9;
	}
	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
	{
		currentIteration = 0;
		position_x = 0;
		easingActivated = true;
		easingType = 10;
	}

	if (easingActivated == true)
	{
		if (easingType == 0)
		{
			position_x = easing->backEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "BACK";
		}
		else if (easingType == 1)
		{
			position_x = easing->bounceEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "BOUNCE";
		}
		else if (easingType == 2)
		{
			position_x = easing->circularEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "CIRCULAR";
		}
		else if (easingType == 3)
		{
			position_x = easing->cubicEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "CUBIC";
		}
		else if (easingType == 4)
		{
			position_x = easing->elasticEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "ELASTIC";
		}
		else if (easingType == 5)
		{
			position_x = easing->exponentialEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "EXPONENTIAL";
		}
		else if (easingType == 6)
		{
			position_x = easing->linearEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "LINEAR";
		}
		else if (easingType == 7)
		{
			position_x = easing->quadEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "QUAD";
		}
		else if (easingType == 8)
		{
			position_x = easing->quartEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "QUART";
		}
		else if (easingType == 9)
		{
			position_x = easing->quintEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "QUINT";
		}
		else if (easingType == 10)
		{
			position_x = easing->sineEaseOut(currentIteration, initialPosition, deltaPosition, totalIterations);
			tmp = "SINE";
		}
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

	SDL_Color color = { 0, 0, 255, 255 };
	if (easingActivated) app->render->DrawText(font, tmp, 500, 350, 100, 3, color);
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
