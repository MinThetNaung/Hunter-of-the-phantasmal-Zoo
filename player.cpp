// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 ship.cpp v1.0

#include "player.h"
//test
//=============================================================================
// default constructor
//=============================================================================
player::player() : Entity()
{
	spriteData.width = playerNS::WIDTH;        // size of Ship1
	spriteData.height = playerNS::HEIGHT;
	spriteData.x = playerNS::X;                   // location on screen
	spriteData.y = playerNS::Y;
	spriteData.rect.bottom = playerNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = playerNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = playerNS::PLAYER_ANIMATION_DELAY;
	startFrame = playerNS::PLAYER_START_FRAME;     // first frame of ship animation
	endFrame = playerNS::PLAYER_END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = playerNS::WIDTH / 2.0;

	mass = playerNS::MASS;
	collisionType = entityNS::BOX;
}

//=============================================================================
// Initialize the player.
// Post: returns true if successful, false if failed
//=============================================================================
bool player::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	
	shield.initialize(gamePtr->getGraphics(), width, height, ncols, textureM);
	shield.setFrames(shipNS::SHIELD_START_FRAME, shipNS::SHIELD_END_FRAME);
	shield.setCurrentFrame(shipNS::SHIELD_START_FRAME);
	shield.setFrameDelay(shipNS::SHIELD_ANIMATION_DELAY);
	shield.setLoop(false);                  // do not loop animation
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void player::draw()
{
	Image::draw();              // draw ship
	if (shieldOn)
		// draw shield using colorFilter 50% alpha
		shield.draw(spriteData, graphicsNS::ALPHA50 & colorFilter);
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void player::update(float frameTime)
{
	Entity::update(frameTime);
	//spriteData.angle += frameTime * playerNS::ROTATION_RATE;  // rotate the ship
	//spriteData.x += frameTime * velocity.x;         // move ship along X 
	//spriteData.y += frameTime * velocity.y;         // move ship along Y



	if (input->isKeyDown(VK_RIGHT))           // if move right
	{
		spriteData.x + frameTime * 32;
	}
	if (input->isKeyDown(VK_LEFT))           // if move left
	{
		spriteData.x - frameTime * 32;
	}
	if (input->isKeyDown(VK_UP))           // if move up
	{
		spriteData.y - frameTime * 32;
	}
	if (input->isKeyDown(VK_DOWN))           // if move down
	{
		spriteData.y + frameTime * 32;
	}
	if (input->isKeyDown(VK_ACCEPT))           // if move down
	{
		
	}






													// Bounce off walls
	if (spriteData.x > GAME_WIDTH - playerNS::WIDTH)    // if hit right screen edge
	{
		spriteData.x = GAME_WIDTH - playerNS::WIDTH;    // position at right screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	else if (spriteData.x < 0)                    // else if hit left screen edge
	{
		spriteData.x = 0;                           // position at left screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	if (spriteData.y > GAME_HEIGHT - playerNS::HEIGHT)  // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - playerNS::HEIGHT;  // position at bottom screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	if (shieldOn)
	{
		shield.update(frameTime);
		if (shield.getAnimationComplete())
		{
			shieldOn = false;
			shield.setAnimationComplete(false);
		}
	}
}

//=============================================================================
// damage
//=============================================================================
void player::damage(WEAPON weapon)
{
	shieldOn = true;
}

