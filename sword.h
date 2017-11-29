#pragma once
// inherits from Entity class
#include "entity.h"
#include "constants.h"
class Sword : public Entity
{
private:
	float Damage;
public:
	// constructor
	Sword();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	void damage(WEAPON);
};