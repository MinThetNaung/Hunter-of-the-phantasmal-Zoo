// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "hunter.h"
#include "player.h"
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
	if (!nebulaTexture.initialize(graphics, NEBULA_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

	// charactors textures
	if (!characterTextures.initialize(graphics, CHARACTERS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing characters textures"));
	// weapons textures
	if (!weaponTextures.initialize(graphics, WEAPON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing weapons textures"));

	// nebula image
	if (!nebula.initialize(graphics, 0, 0, 0, &nebulaTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));

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
	hunterSword.setFrames(swordNS::SWORD_START_FRAME,swordNS::SWORD_END_FRAME);
	hunterSword.setCurrentFrame(swordNS::SWORD_START_FRAME);

	//hunterSword.setColorFilter(SETCOLOR_ARGB(255, 230, 230, 255));
	hunterSword.setdamage(2);// set the starting damage to the sword
	return;


	// enemy
	if (!enemy.initialize(this, enemyNS::WIDTH, enemyNS::HEIGHT, enemyNS::TEXTURE_COLS, &enemyTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spider"));
	enemy.setFrames(enemyNS::ENEMY_START_FRAME, enemyNS::ENEMY_END_FRAME);
	enemy.setCurrentFrame(enemyNS::ENEMY_START_FRAME);
	enemy.setColorFilter(SETCOLOR_ARGB(255, 230, 230, 255));   // light blue, used for shield and torpedo
	enemy.setMass(enemyNS::MASS);
	// Start spider in the middle of left
	enemy.setX(GAME_WIDTH / 4 - enemyNS::WIDTH);
	enemy.setY(GAME_HEIGHT / 4 - enemyNS::HEIGHT);
}

//=============================================================================
// Update all game items
//=============================================================================
void Hunter::update()
{
	//planet.update(frameTime);
	//player1.update(frameTime);
	hunterSword.update(frameTime);
	//player1.update(frameTime);
	if (input->isKeyDown(VK_RIGHT))           // if move right
	{
		//hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);

	}
	else if (input->isKeyDown(VK_LEFT))           // if move left
	{
		//hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);
	}
	else if (input->isKeyDown(VK_UP))           // if move up
	{
		//hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);
	}
	else if (input->isKeyDown(VK_DOWN))           // if move down
	{
		//hunterSword.setFrames(swordNS::SWORD_START_FRAME, swordNS::SWORD_END_FRAME);
		player1.update(frameTime);
	}
	//hunterSword.update(frameTime);

	/*/ enemy
	float enemyX;

	enemy.update(frameTime);			// move the enemy

	enemyX = enemy.getX();
	if (enemyX < 0)                  // if enemy off screen left
	{
	mapX -= enemy.getVelocity().x * frameTime;  // scroll map right
	enemy.setX(0);              // put enemy at left edge
	}
	// if enemy off screen right
	else if (enemyX > GAME_WIDTH - enemy.getWidth())
	{
	mapX -= enemy.getVelocity().x * frameTime;  // scroll map left
	// put enemy at right edge
	enemy.setX((float)(GAME_WIDTH - enemy.getWidth()));
	}

	if (mapX > 0)    // if map past left edge
	{
	mapX = 0;   // stop at left edge of map
	enemy.setVelocityX(0);  // stop enemy
	}
	// if map past right edge
	else if (mapX < (-MAP_WIDTH * TEXTURE_SIZE) + GAME_WIDTH)
	{
	// stop at right edge of map
	mapX = (-MAP_WIDTH * TEXTURE_SIZE) + GAME_WIDTH;
	enemy.setVelocityX(0);  // stop spider
	}*/


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
	if (hunterSword.collidesWith(enemy, collisionVector))
	{
		// bounce off sword
		enemy.bounce(collisionVector, hunterSword);
		//enemy.damage(ENEMY);
	}
	if (enemy.collidesWith(player1, collisionVector))
	{
		// bounce off player
		player1.bounce(collisionVector, enemy);
		//player1.damage(PLAYER);
	}
	/*/ if collision between ships
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

	nebula.draw();                          // add the orion nebula to the scene
	//planet.draw();                          // add the planet to the scene
	player1.draw();                           // add the player to the scene
	enemy.draw();							  // add the enemy to the scene

	//hunterSword.draw();
	if (input->isKeyDown(VK_SPACE))//(player1.interact == true)//render the huntersword if space is pressed
	{
		player1.Getplayerlocation();
		hunterSword.setX(player1.PositionX);
		hunterSword.setY(player1.PositionY);
		hunterSword.draw();
		if (hunterSword.getCurrentFrame() == swordNS::SWORD_END_FRAME)
		{
			//player1.interact = false;
			hunterSword.setCurrentFrame(swordNS::SWORD_START_FRAME);
		}
	}
	

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
	enemyTextures.onLostDevice();
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
	enemyTextures.onLostDevice();
	Game::resetAll();
	return;
}
