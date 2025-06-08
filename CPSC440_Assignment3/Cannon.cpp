//Aiden D'Antuono

#include "Cannon.h"

//Destructor
cannon::~cannon() {
	al_destroy_bitmap(image);
}

//Constructor
cannon::cannon() {
	cannon::image = al_load_bitmap("Cannon.png");
	cannon::angle = 0.0;
}

//Draw the cannon at the correct angle
void cannon::drawCannon() {
	al_draw_rotated_bitmap(image, 64, 120, 450, 680, angle, 0);
}

//Rotate the cannon to the left
void cannon::rotateLeft() {
	angle -= .05;
	if (angle < (-ALLEGRO_PI / 2))
		angle = -ALLEGRO_PI / 2;
}

//Rotate the cannon to the right
void cannon::rotateRight() {
	angle += .05;
	if (angle > (ALLEGRO_PI / 2))
		angle = ALLEGRO_PI / 2;
}