//Aiden D'Antuono

#include "GameLogic.h"

game::~game() {
	al_destroy_bitmap(background);
	al_destroy_bitmap(igloo);
}

game::game() {
	game::numSnowballs = 0;
	game::numEnemies = 0;

	game::Snowball = NULL;
	game::Enemies = NULL;

	game::background = al_load_bitmap("Background.png");
	game::igloo = al_load_bitmap("BackgroundIgloo.png");
	game::lives = 5;
	game::score = 0;
	game::lost = false;
}

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
	game::lost = false;
}

void game::runGame(bool *keys) {
	if (!lost) {
		if (keys[0]) {
			Cannon.rotateLeft();
		}
		if (keys[1]) {
			Cannon.rotateRight();
		}
		if (keys[1]) {

		}
		for (int i = 0; i < numEnemies; i++) {
			Enemies[i].startPenguin(900, 900);
		}
		for (int i = 0; i < numEnemies; i++) {
			Enemies[i].updatePenguin();
		}
		for (int i = 0; i < numEnemies; i++) {
			if (Enemies[i].collidePenguin(900, 900)) {
				game::removeLife();
			}
		}

		if (lives == 0) {
			lost = true;
		}
	}
}

void game::drawGame() {
	al_draw_bitmap(background, 0, 0, 0);
	Cannon.drawCannon();
	al_draw_bitmap(igloo, 0, 0, 0);

	for (int i = 0; i < numEnemies; i++) {
		Enemies[i].drawPenguin();
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