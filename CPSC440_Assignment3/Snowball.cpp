//Aiden D'Antuono

#include "Snowball.h"
#include <cmath>
#include <stdio.h>

snowball::~snowball() {
	al_destroy_bitmap(image);
}

snowball::snowball() {
	snowball::image = al_load_bitmap("Snowball.png");
	live = false;
	speed = 10;
	boundx = 16;
	boundy = 16;
}

void snowball::drawSnowball() {
	if (live) {
		al_draw_bitmap(image, x, y, 0);
	}
}

bool snowball::fireSnowball(cannon &Cannon) {
	if (!live) {
		float angle = Cannon.getAngle();
		//Calculate speed in x and y direction based on angle
		speedx = std::sin(angle) * speed;
		speedy = std::cos(angle) * speed;

		//Determine where snowball should spawn to be at muzzle of cannon
		x = 450 + (std::sin(angle) * 115) - (boundx / 2) + (std::sin(angle) * (boundx / 2));
		y = (680) - (std::cos(angle) * 115) - (boundy / 2) - (std::cos(angle) * (boundy / 2));

		live = true;
		return true;
	}
	return false;
}

void snowball::updateSnowball(int WIDTH, int HEIGHT) {
	if (live) {
		x += speedx;
		y -= speedy;
		if (live) {
			if (x > WIDTH || x < 0 - boundx || y > HEIGHT || y < 0 - boundy) {
				live = false;
			}
		}
	}
}

bool snowball::collideSnowball(penguin penguins[], int cSize) {
	if (live) {
		for (int i = 0; i < cSize; i++) {
			if (penguins[i].getStatus()) {
				if (penguins[i].getLive()) {
					int penguinLeftBound = penguins[i].getX() + penguins[i].getBoundXL();
					int penguinRightBound = penguins[i].getX() + penguins[i].getBoundXR();
					int penguinTopBound = penguins[i].getY() + penguins[i].getBoundYT();
					int penguinBottomBound = penguins[i].getY() + penguins[i].getBoundYB();

					//Snowball must be fully in the penguin's hitbox
					if ((x >= penguinLeftBound) && ((x + boundx) <= penguinRightBound) && (y >= penguinTopBound) && ((y + boundy) <= penguinBottomBound)) {
						penguins[i].setLive(false);
						live = false;
						return true;
					}
				}
			}
		}
	}
	return false;
	
}