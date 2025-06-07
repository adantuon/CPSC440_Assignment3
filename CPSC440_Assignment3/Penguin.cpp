//Aiden D'Antuono

#include "Penguin.h"
#include <stdio.h>

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

	penguin::boundx = al_get_bitmap_width(image[0]);
	penguin::boundy = al_get_bitmap_height(image[0]);
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
			x = rand() % (HEIGHT - boundx);
			y = 0 - boundy;
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

void penguin::collidePenguin(int WIDTH, int HEIGHT) {
	
	if (inPlay) {
		if (y > HEIGHT) {
			printf("Penguin removed\n");
			inPlay = false;
		}
	}
}