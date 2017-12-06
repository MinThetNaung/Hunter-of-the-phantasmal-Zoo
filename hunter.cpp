// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "hunter.h"

//=============================================================================
// Constructor
//=============================================================================
Hunter::Hunter()
{}

//=============================================================================
// Destructor
//=============================================================================
Hunter::~Hunter()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Hunter::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError

							// nebula texture
	//if (!nebulaTexture.initialize(graphics, NEBULA_IMAGE))
		//throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

	// charactors textures
	if (!characterTextures.initialize(graphics, CHARACTERS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing characters textures"));
	// weapons textures
	if (!weaponTextures.initialize(graphics, WEAPON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing weapons textures"));

	// nebula image
	//if (!nebula.initialize(graphics, 0, 0, 0, &nebulaTexture))
		//throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));

	// planet
	//if (!planet.initialize(this, planetNS::WIDTH, planetNS::HEIGHT, 2, &gameTextures))
		//throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet"));
	
	// player
	if (!player1.initialize(this, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &characterTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	//player1.setFrames(playerNS::PLAYER_START_FRAME, playerNS::PLAYER_END_FRAME);
	player1.setCurrentFrame(playerNS::PLAYER_START_FRAME);
	player1.setX(GAME_WIDTH / 4);
	player1.setY(GAME_HEIGHT / 4);
	//player1.setLoop(false);
	
	//player1.setVelocity(VECTOR2(shipNS::SPEED, -shipNS::SPEED)); // VECTOR2(X, Y)
	// sword
	if (!hunterSword.initialize(this, swordNS::WIDTH, swordNS::HEIGHT, swordNS::TEXTURE_COLS, &weaponTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	
	hunterSword.setCurrentFrame(swordNS::SWORD_START_FRAME);
	hunterSword.setX(player1.getX() + Tilesize);
	hunterSword.setY(player1.getY() + Tilesize);
	hunterSword.setdamage(2);// set the starting damage to the sword
	hunterSword.setLoop(false);
	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Hunter::update()
{
	//planet.update(frameTime);
	//player1.update(frameTime);
	hunterSword.update(frameTime);

	if (input->isKeyDown(VK_RIGHT))           // if move right
	{
		hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);

	}
	else if (input->isKeyDown(VK_LEFT))           // if move left
	{
		hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);
	}
	else if (input->isKeyDown(VK_UP))           // if move up
	{
		hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);
	}
	else if (input->isKeyDown(VK_DOWN))           // if move down
	{
		hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);

	}
	if (input->isKeyDown(VK_ACCEPT))           // if move right
	{
		hunterSword.setX(player1.getX() + Tilesize);
		hunterSword.setY(player1.getY() + Tilesize);
	}

}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Hunter::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Hunter::collisions()
{
	VECTOR2 collisionVector;
	// if collision between ship and planet
	/*if (ship1.collidesWith(planet, collisionVector))
	{
		// bounce off planet
		ship1.bounce(collisionVector, planet);
		ship1.damage(PLANET);
	}
	if (ship2.collidesWith(planet, collisionVector))
	{
		// bounce off planet
		ship2.bounce(collisionVector, planet);
		ship2.damage(PLANET);
	}
	// if collision between ships
	if (ship1.collidesWith(ship2, collisionVector))
	{
		// bounce off ship
		ship1.bounce(collisionVector, ship2);
		ship1.damage(SHIP);
		// change the direction of the collisionVector for ship2
		ship2.bounce(collisionVector*-1, ship1);
		ship2.damage(SHIP);
	}*/
}

//=============================================================================
// Render game items
//=============================================================================
void Hunter::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	//nebula.draw();                          // add the orion nebula to the scene
	//planet.draw();                          // add the planet to the scene
	player1.draw();                           // add the player to the scene
	hunterSword.draw();

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Hunter::releaseAll()
{
	nebulaTexture.onLostDevice();
	characterTextures.onLostDevice();
	weaponTextures.onLostDevice();
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Hunter::resetAll()
{
	characterTextures.onResetDevice();
	nebulaTexture.onResetDevice();
	weaponTextures.onResetDevice();
	Game::resetAll();
	return;
}
