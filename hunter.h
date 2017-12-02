// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _HUNTER_H             // Prevent multiple definitions if this 
#define _HUNTER_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "planet.h"
#include "player.h"
#include "sword.h"
//=============================================================================
// This class is the core of the game
//=============================================================================
class Hunter : public Game
{
private:
	// game items
	TextureManager nebulaTexture;   // nebula texture
	TextureManager characterTextures;    // character texture
	TextureManager weaponTextures;    // weapon texture
	player    player1;           // player
	Planet  planet;         // the planet
	Image   nebula;         // backdrop image
	Sword hunterSword;
public:
	// Constructor
	Hunter();

	// Destructor
	virtual ~Hunter();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
	
};

#endif
