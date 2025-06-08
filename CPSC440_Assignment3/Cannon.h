//Aiden D'Antuono

#pragma once
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

class cannon
{
public:
	cannon();
	~cannon();
	void drawCannon();
	void rotateLeft();
	void rotateRight();
private:
	ALLEGRO_BITMAP *image;
	float angle;
};