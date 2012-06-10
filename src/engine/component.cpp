#include "timer.h"
#include "component.h"
#include "macro.h"

void MovementComponent::update()
{
};

PhysicsComponent::PhysicsComponent()
	:velocity(140.f), timeref(SDL_GetTicks())
{
	vel.x = vel.y = 0.f;
	acc.x = acc.y = 0;
	timestep=(1000.f/velocity);
	//timestep=(1000.f/33);
	accstep = velocity*((timestep * 4.f)/1000.f);//LOL ~4	//4 is meant to be an amount of pixels or something
	deaccstep = accstep * 4.f;
//	animation.setSpeed(2000/(velocity/5));
	
	pos.x = 0;
	pos.y = 0;
	//NEEDS a way to set spawn(passed in when PhysicsComponent is created)
//	pos.x = -(box.w / 2.0);
//	pos.y = -(box.h / 2.0);
};
void PhysicsComponent::update()
{};

void PhysicsComponent::update(unsigned char& ACTION, SDL_Rect& box)
{
//	update the acceleration and keep with bounds
//	update the velocity using the new acc. and deltaTime
//	add the velocity to the position, and return its value(float).
while (Timer::updateInterval(timestep, timeref)){	
	if ( (!hasFlag(ACTION, LEFT) && !hasFlag(ACTION, RIGHT)) || hasFlag(ACTION, (LEFT + RIGHT)) ){
			if (acc.x > 0){
				acc.x -= 12;
				if (acc.x < 0) acc.x = 0;
			}
			if (acc.x < 0){
				acc.x += 12;
				if (acc.x > 0) acc.x = 0;
			}
		}
		if ( (!hasFlag(ACTION, UP) && !hasFlag(ACTION, DOWN)) || hasFlag(ACTION, (UP + DOWN)) ){
			if (acc.y > 0){
				acc.y -= 12;
				if (acc.y < 0) acc.y = 0;
			}
			if (acc.y < 0){
				acc.y += 12;
				if (acc.y > 0) acc.y = 0;
			}
		}
		
		
	if (hasFlag(ACTION, LEFT))	{ acc.x -= 4; }
	if (hasFlag(ACTION, RIGHT))	{ acc.x += 4; }
	if (hasFlag(ACTION, UP))	{ acc.y -= 4; }
	if (hasFlag(ACTION, DOWN))	{ acc.y += 4; }

	if (acc.x > velocity) 	acc.x = velocity;
	if (acc.y > velocity) 	acc.y = velocity;
	if (acc.x < -velocity) 	acc.x = -velocity;
	if (acc.y < -velocity) 	acc.y = -velocity;
	
	vel.x = ((timestep/1000.f) * acc.x);
	vel.y = ((timestep/1000.f) * acc.y);
	pos.x += vel.x;
	pos.y += vel.y;
	box.x = pos.x;
	box.y = pos.y;
}
if (!ACTION){ timeref = SDL_GetTicks(); }
};

float PhysicsComponent::Velocity(){ return velocity; }





void PositionComponent::update()
{
};


InputComponent::InputComponent()
{
/*	This code allows the InputComponent to be a manager of itself. It maintains
 * 	a list of all InputComponents and adds itself when it is created.
	if (!inputComponents) inputComponents = new std::vector<Input>;
	inputComponents->push_back(*this);
*/
}

void InputComponent::update()
{	
};
	
void InputComponent::checkFor(SDL_Keycode keycode)
{
	for(std::vector<KeyBinding>::iterator itr = keyBindings.begin(); itr != keyBindings.end(); itr++)
	{
		if(itr->key == keycode){}//movement->move(itr.action)
	}
}
