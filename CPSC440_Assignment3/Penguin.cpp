//Aiden D'Antuono

#include "Penguin.h"

penguin::~penguin() {
	al_destroy_bitmap(image[0]);
	al_destroy_bitmap(image[1]);
}

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

void penguin::startPenguin(int WIDTH, int HEIGHT) {
	if (!inPlay) {
		if (rand() % 500 == 0) {
			inPlay = true;
			alive = true;
			x = rand() % ((WIDTH - (al_get_bitmap_width(image[0]) - boundxl)) + boundxl + 1) - boundxl;
			y = 0 - boundyb;
		}
	}
}

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

bool penguin::collidePenguin(int WIDTH, int HEIGHT) {
	
	if (inPlay) {
		if (alive) {
			if ((x + boundxl) >= 90 && (x + boundxr) <= 800 && (y + boundyb) > 765) {
				inPlay = false;
				return true;
			}
		}
		if (y > HEIGHT) {
			inPlay = false;
		}
	}
	return false;
}