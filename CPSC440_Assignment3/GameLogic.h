//Aiden D'Antuono

#pragma once
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class game {
	public:
		game();
		~game();
		void drawBackground();
		int getScore() { return score; }
		void addScore() { score++; }
		int getLives() { return lives; }
		void removeLife() { lives--; }
	private:
		int score;
		int lives;
		ALLEGRO_BITMAP *background;
};