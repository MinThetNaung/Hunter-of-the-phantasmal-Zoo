// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 ship.h v1.0
//test
#ifndef _PLAYER_H                 // Prevent multiple definitions if this 
#define _PLAYER_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"


namespace playerNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	//const float ROTATION_RATE = (float)PI / 4; // radians per second
	const float SPEED = 100;                // 100 pixels per second
	const float MASS = 300.0f;              // mass
	const int   TEXTURE_COLS = 12;           // texture has 8 columns
	const int   PLAYER_START_FRAME = 49;      // player down start
	const int   PLAYER_END_FRAME = 51;        // Player down end
	const int   PLAYERUP_START_FRAME = 85;      // player up start
	const int   PLAYERUP_END_FRAME = 97;        // Player up end
	const int   PLAYERLEFT_START_FRAME = 61;      // player  left start
	const int   PLAYERLEFT_END_FRAME = 63;        // Player left end
	const int   PLAYERRIGHT_START_FRAME = 73;      // player right start
	const int   PLAYERRIGHT_END_FRAME = 75;        // Player right end
	//const int   PLAYER_START_FRAME = 8;      // ship2 starts at frame 8
	//const int   PLAYER_END_FRAME = 11;       // ship2 animation frames 8,9,10,11
	const float PLAYER_ANIMATION_DELAY = 0.2f;    // time between frames
	//const int   SHIELD_START_FRAME = 24;    // shield start frame
	//const int   SHIELD_END_FRAME = 27;      // shield end frame
	//const float SHIELD_ANIMATION_DELAY = 0.1f; // time between frames
}

// inherits from Entity class
class player : public Entity
{
private:
	
	float MaxHealth;
	Entity Invenarray[10]; 
public:
	// constructor
	player();
	
	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	void damage(WEAPON);
};
#endif

#pragma once
