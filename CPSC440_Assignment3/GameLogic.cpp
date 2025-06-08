//Aiden D'Antuono

#include "GameLogic.h"

//Deconstructor
game::~game() {
	al_destroy_bitmap(background);
	al_destroy_bitmap(igloo);
}

//Default Constructor
game::game() {
	game::numSnowballs = 0;
	game::numEnemies = 0;

	game::Snowball = NULL;
	game::Enemies = NULL;

	game::background = al_load_bitmap("Background.png");
	game::igloo = al_load_bitmap("BackgroundIgloo.png");
	game::lives = 5;
	game::score = 0;
	game::fireDelay = 30;
	game::fireCooldown = 30;
	game::lost = false;
}

//Constructor
game::game(int numS, int numE, ALLEGRO_FONT *f, ALLEGRO_FONT *bf) {
	game::numSnowballs = numS;
	game::numEnemies = numE;
	game::font = f;
	game::bigFont = bf;

	game::Snowball = new snowball[numSnowballs];
	game::Enemies = new penguin[numEnemies];

	game::background = al_load_bitmap("Background.png");
	game::igloo = al_load_bitmap("BackgroundIgloo.png");
	game::lives = 5;
	game::score = 0;
	game::fireDelay = 10;
	game::fireCooldown = 10;
	game::lost = false;
}

//Runs game logic
void game::runGame(bool *keys) {
	if (!lost) {
		//Handle the cooldown on firing the cannon
		if (fireDelay != fireCooldown) {
			fireCooldown++;
		}

		//Rotate the cannon left if necessary
		if (keys[0]) {
			Cannon.rotateLeft();
		}

		//Rotate the cannon right if necessary
		if (keys[1]) {
			Cannon.rotateRight();
		}

		//Fire one snowball if the cannon is capable of firing
		if (keys[2]) {
			if (fireDelay == fireCooldown) {
				for (int i = 0; i < numSnowballs; i++) {
					if (Snowball[i].fireSnowball(Cannon)) {
						fireCooldown = 0;
						break;
					}
				}
			}
		}

		//Update snowballs
		for (int i = 0; i < numSnowballs; i++) {
			Snowball[i].updateSnowball(900, 900);
		}

		//Try to start a penguin
		for (int i = 0; i < numEnemies; i++) {
			Enemies[i].startPenguin(900, 900);
		}

		//Update penguins
		for (int i = 0; i < numEnemies; i++) {
			Enemies[i].updatePenguin();
		}

		//Check for collision on snowballs
		for (int i = 0; i < numSnowballs; i++) {
			if (Snowball[i].collideSnowball(Enemies, 10)) {
				score++;
			}
		}

		//Check for collisions on Penguins
		for (int i = 0; i < numEnemies; i++) {
			if (Enemies[i].collidePenguin(900, 900)) {
				game::removeLife();
			}
		}

		//End game if necessary
		if (lives == 0) {
			lost = true;
		}
	}
}

//Draws game
void game::drawGame() {
	al_draw_bitmap(background, 0, 0, 0);
	Cannon.drawCannon();
	al_draw_bitmap(igloo, 0, 0, 0);

	for (int i = 0; i < numEnemies; i++) {
		Enemies[i].drawPenguin();
	}
	for (int i = 0; i < numSnowballs; i++) {
		Snowball[i].drawSnowball();
	}

	if (!lost) {
		al_draw_textf(font, al_map_rgb(0, 0, 0), 5, 870, ALLEGRO_ALIGN_LEFT, "Lives: %i", lives);
		al_draw_textf(font, al_map_rgb(0, 0, 0), 895, 870, ALLEGRO_ALIGN_RIGHT, "Score: %i", score);
	}
	else {
		al_draw_textf(bigFont, al_map_rgb(255, 0, 0), 450, 400, ALLEGRO_ALIGN_CENTER, "GAME OVER");
		al_draw_textf(font, al_map_rgb(255, 0, 0), 450, 475, ALLEGRO_ALIGN_CENTER, "FINAL SCORE: %i", score);
	}
	
}