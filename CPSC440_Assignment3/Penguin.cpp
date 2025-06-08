//Aiden D'Antuono

#include "Penguin.h"

//Destructor
penguin::~penguin() {
	al_destroy_bitmap(image[0]);
	al_destroy_bitmap(image[1]);
}

//Constructor
penguin::penguin() {
	penguin::image[0] = al_load_bitmap("PenguinParatrooper.png");
	penguin::image[1] = al_load_bitmap("PenguinParatrooperDowned.png");
	
	penguin::inPlay = false;
	penguin::alive = true;
	penguin::speed = 2;

	penguin::boundxl = 26;
	penguin::boundxr = 102;
	penguin::boundyt = 10;
	penguin::boundyb = 117;
}

//Draws penguin if it is in the game and with the correct image based on if it is alive or not
void penguin::drawPenguin() {

	if (inPlay) {
		if (alive) {
			al_draw_bitmap(image[0], x, y, 0);
		}
		else {
			al_draw_bitmap(image[1], x, y, 0);
		}
	}
}

//Tries to start the penguin if it isn't already in the game
void penguin::startPenguin(int WIDTH, int HEIGHT) {
	if (!inPlay) {
		if (rand() % 500 == 0) {
			inPlay = true;
			alive = true;

			//generate an x based on hitbox of the penguin
			x = rand() % ((WIDTH - (al_get_bitmap_width(image[0]) - boundxl)) + boundxl + 1) - boundxl;
			y = 0 - boundyb;
		}
	}
}

//update penguin height based on if alive or not (dead ones fall faster)
void penguin::updatePenguin() {
	
	if (inPlay) {
		if (alive) {
			y += speed;
		}
		else {
			y += speed * 4;
		}
	}
}

//Check if the penguin collided with iceberg or went outside the display returns true if landed on iceberg
bool penguin::collidePenguin(int WIDTH, int HEIGHT) {
	
	if (inPlay) {
		//If the penguin is alive then the penguin can land on the iceberg
		if (alive) {
			if ((x + boundxl) >= 90 && (x + boundxr) <= 800 && (y + boundyb) > 765) {
				inPlay = false;
				return true;
			}
		}
		//Penguins that won't hit the iceberg or dead ones are deleted once outside the display's area
		if (y > HEIGHT) {
			inPlay = false;
		}
	}
	return false;
}