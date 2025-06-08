//Aiden D'Antuono

#pragma once
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "Cannon.h"
#include "Penguin.h"

class snowball
{
public:
	snowball();
	~snowball();
	void drawSnowball();
	bool fireSnowball(cannon &Cannon);
	void updateSnowball(int WIDTH, int HEIGHT);
	bool collideSnowball(penguin penguins[], int cSize);
private:
	int x;
	int y;
	bool live;
	int speed;
	int speedx;
	int speedy;
	int boundx;
	int boundy;
	ALLEGRO_BITMAP *image;
};