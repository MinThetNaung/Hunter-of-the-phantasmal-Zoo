//  Module:             Gameplay Programming
//  Assignment1:        Hunter of the phantasmal zoo
//  Student Name:       Bryan Boh, 
//  Student Number:     S10171537F, 

#include "sword.h"


Sword::Sword() : Entity()
{
	collisionType = entityNS::BOX;
	spriteData.width = swordNS::WIDTH;        // size of sword
	spriteData.height = swordNS::HEIGHT;
	spriteData.x = swordNS::X;                   // location on screen
	spriteData.y = swordNS::Y;
	spriteData.rect.bottom = swordNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = swordNS::WIDTH;
	frameDelay = swordNS::SWORD_ANIMATION_DELAY;
	startFrame = swordNS::SWORD_START_FRAME;     // first frame of sword animation
	endFrame = swordNS::SWORD_END_FRAME;     // last frame of sword animation
	currentFrame = startFrame;
}
float Sword::setdamage(float d) 
{
	Damage = d;
	return Damage;
}
void Sword::update(float frameTime)
{
	Entity::update(frameTime);

}
void Sword::damage(WEAPON)
{
}
void Sword::draw()
{
	Image::draw();              
}
bool Sword::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}