//Aiden D'Antuono

#include "Cannon.h"

cannon::~cannon() {
	al_destroy_bitmap(image);
}

cannon::cannon() {
	cannon::image = al_load_bitmap("Cannon.png");
	cannon::angle = 0.0;
}

void cannon::drawCannon() {
	al_draw_rotated_bitmap(image, 64, 120, 450, 680, angle, 0);
}

void cannon::rotateLeft() {
	angle -= .05;
	if (angle < (-ALLEGRO_PI / 2))
		angle = -ALLEGRO_PI / 2;
}

void cannon::rotateRight() {
	angle += .05;
	if (angle > (ALLEGRO_PI / 2))
		angle = ALLEGRO_PI / 2;
}