#include "sword.h"


Sword::Sword() : Entity()
{
	collisionType = entityNS::BOX;

}
float Sword::setdamage(float d) 
{
	Damage = d;
}