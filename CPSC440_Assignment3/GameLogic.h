//Aiden D'Antuono

#pragma once
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Snowball.h"
#include "Cannon.h"
#include "Penguin.h"

class game {
	public:
		game(int numS, int numE, ALLEGRO_FONT *f, ALLEGRO_FONT *bf);
		game();
		~game();
		void runGame();
		void drawGame();
		int getScore() { return score; }
		void addScore() { score++; }
		int getLives() { return lives; }
		void removeLife() { lives--; }
	private:
		cannon Cannon;
		snowball *Snowball;
		penguin *Enemies;
		int numSnowballs;
		int numEnemies;
		int score;
		int lives;
		bool lost;
		ALLEGRO_BITMAP *background;
		ALLEGRO_FONT *font;
		ALLEGRO_FONT *bigFont;
};