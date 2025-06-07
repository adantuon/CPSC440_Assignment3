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
	void DrawArrow();
	void FireArrow(cannon &Cannon);
	void UpdateArrow(int WIDTH, int HEIGHT);
	void CollideArrow(penguin penguins[], int cSize);
private:
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;
	ALLEGRO_BITMAP *image[2];
};