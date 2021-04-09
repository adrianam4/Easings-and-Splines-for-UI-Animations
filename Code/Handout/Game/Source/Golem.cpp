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

	easingActivated = false;
	easingType = 0;
	easingMode = 1;

	//TODO 1: Initialize the variables you created before with the values you desire
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
	// TODO 2: Assign "easingMode" depending on the key you press (IN-OUT-IN/OUT)
	if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		easeModeString = "Easing Mode: In";
	}
	if (app->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		easeModeString = "Easing Mode: Out";
	}
	if (app->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		easeModeString = "Easing Mode: In/Out";
	}

	// TODO 3: Assign the "easingType" depending on the key you press (BOUNCE-CUBIC-CIRCULAR...)
	// Also reset the "position_x", the "currentIteration and enable "easingActivated"

	//BACK ("easingType" 1)
	if (app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
	
	}
	//BOUNCE ("easingType" 2)
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
	{
	
	}
	//CIRCULAR ("easingType" 3)
	if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
	
	}
	//CUBIC ("easingType" 4)
	if (app->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		
	}
	//ELASTIC ("easingType" 5)
	if (app->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN)
	{
		
	}
	//EXPONENTIAL ("easingType" 6)
	if (app->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)
	{
		
	}
	//LINEAR ("easingType" 7)
	if (app->input->GetKey(SDL_SCANCODE_U) == KEY_DOWN)
	{
	
	}
	//QUAD ("easingType" 8)
	if (app->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
	{
		
	}
	//QUART ("easingType" 9)
	if (app->input->GetKey(SDL_SCANCODE_O) == KEY_DOWN)
	{
		
	}
	//QUINT ("easingType" 10)
	if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
	{
		
	}
	//SINE ("easingType" 11)
	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
	{
		
	}

	// TODO 4: Call the functions you need depending on the "easingType" and the "easingMode". And assign the value you get to "position_x"
	if (easingActivated == true)
	{
		if (easingType == 1)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "BACK";
		}
		else if (easingType == 2)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "BOUNCE";
		}
		else if (easingType == 3)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "CIRCULAR";
		}
		else if (easingType == 4)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "CUBIC";
		}
		else if (easingType == 5)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "ELASTIC";
		}
		else if (easingType == 6)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "EXPONENTIAL";
		}
		else if (easingType == 7)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "LINEAR";
		}
		else if (easingType == 8)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "QUAD";
		}
		else if (easingType == 9)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "QUART";
		}
		else if (easingType == 10)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "QUINT";
		}
		else if (easingType == 11)
		{
			if (easingMode == 1) 
			if (easingMode == 2) 
			if (easingMode == 3) 
			easeTypeString = "SINE";
		}
	}

	// TODO 5: Make that while the number of "currentIterations" is lower than "totalIterations", "currentIterations" increase his value each frame
	
	// TODO 6: Make that if the "currentIterations" value is equal or higher to "totalIterations", the "easingActivated" must be disabled and the "currentIterations" value must be 0
	
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
	if (easingActivated) app->render->DrawText(font, easeTypeString, 500, 350, 100, 3, color);

	app->render->DrawText(font, easeModeString, 500, 450, 100, 3, color);

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
