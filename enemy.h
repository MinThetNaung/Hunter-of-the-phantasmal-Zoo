#pragma once
#pragma once

#ifndef _ENEMY_H            // Prevent multiple definitions if this 
#define _ENEMY_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace enemyNS
{
	const int   WIDTH = 48;                // image width (each frame)
	const int   HEIGHT = 48;               // image height
	const int   X = GAME_WIDTH / 2 - WIDTH / 2; // location on screen
	const int   Y = GAME_HEIGHT / 6 - HEIGHT;
	const int   EDGE_TOP = -50;             // For BOX and ROTATE_BOX collison.
	const int   EDGE_BOTTOM = 50;           // "   relative to center
	const int   EDGE_LEFT = -50;            // "
	const int   EDGE_RIGHT = 50;            // "
											//const float ROTATION_RATE = (float)PI; // radians per second
	const float SPEED = 50;                 // pixels per second
	const float MAX_SPEED = 100;
	const float MASS = 3.0f;                // mass
	const int   TEXTURE_COLS = 12;			// texture has 8 columns
	const int   ENEMY_START_FRAME = 3;      // player down start
	const int   ENEMY_END_FRAME = 5;        // Player down end
	const int   ENEMYUP_START_FRAME = 39;      // player up start
	const int   ENEMYUP_END_FRAME = 41;        // Player up end
	const int   ENEMYLEFT_START_FRAME = 15;      // player  left start
	const int   ENEMYLEFT_END_FRAME = 17;        // Player left end
	const int   ENEMYRIGHT_START_FRAME = 27;      // player right start
	const int   ENEMYRIGHT_END_FRAME = 29;        // Player right end
	const float ENEMY_ANIMATION_DELAY = 0.1f;    // time between frames
	enum DIRECTION { LEFT, RIGHT, UP, DOWN };
}

// inherits from Entity class
class Enemy : public Entity
{
private:
	float   oldX, oldY, oldAngle;
	float   rotation;                       // current rotation rate (radians/second)
	enemyNS::DIRECTION direction;            // direction of rotation

public:
	// constructor
	Enemy();

	// inherited member functions
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	void repair();

	// new functions
	void setVelocityX(float v) { velocity.x = v; }
};
#endif
