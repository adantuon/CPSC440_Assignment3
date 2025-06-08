//Aiden D'Antuono

#include "GameLogic.h"

game::~game() {
	al_destroy_bitmap(background);
}

game::game() {
	game::numSnowballs = 0;
	game::numEnemies = 0;

	game::Snowball = NULL;
	game::Enemies = NULL;

	game::background = al_load_bitmap("Background.png");
	game::lives = 5;
	game::score = 0;
}

game::game(int numS, int numE) {
	game::numSnowballs = numS;
	game::numEnemies = numE;

	game::Snowball = new snowball[numSnowballs];
	game::Enemies = new penguin[numEnemies];

	game::background = al_load_bitmap("Background.png");
	game::lives = 5;
	game::score = 0;
}

void game::runGame() {
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
}

void game::drawGame() {
	al_draw_bitmap(background, 0, 0, 0);

	for (int i = 0; i < numEnemies; i++) {
		Enemies[i].drawPenguin();
	}
}