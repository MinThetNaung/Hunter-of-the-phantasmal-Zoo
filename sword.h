#pragma once
// inherits from Entity class
#include "entity.h"
#include "constants.h"
namespace swordNS
{
	const int WIDTH = 48;                   // image width
	const int HEIGHT = 48;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const int   TEXTURE_COLS = 6;
	const int   SWORD_START_FRAME = 7;      // player down start
	const int   SWORD_END_FRAME = 9;
	const float SWORD_ANIMATION_DELAY = 0.2f;
}
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
	float setdamage(float d);
};