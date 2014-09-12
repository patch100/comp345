#include "Projectile.h"


Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}

void Projectile::calculate()
{
	move();
	
	if(hit())
		die();

}

void Projectile::move()
{

	//move according to target position, and current location, and speed;

}

bool Projectile::hit()
{
	//if target position and projectile position are close, like 2 px or 1 px;
	return true;
	//else does not hit;
	return false;
}

void Projectile::die()
{

	//delete object
	//~Projectile();
}

