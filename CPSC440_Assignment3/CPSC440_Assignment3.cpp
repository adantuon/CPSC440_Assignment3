// Aiden D'Antuono
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Snowball.h"
#include "Cannon.h"
#include "Penguin.h"
#include "GameLogic.h"


int main() {
	
	const int WIDTH = 900;
	const int HEIGHT = 900;
	const int numSnowballs = 5;
	const int numEnemies = 10;
	enum KEYS{LEFT, RIGHT, SPACE};
	bool keys[3] = { false, false, false };

	bool exit = false;
	bool draw = true;
	const int FPS = 60;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	if (!al_init())
		return -1;

	display = al_create_display(WIDTH, HEIGHT);

	if (!display)
		return -1;

	if (!al_init_font_addon())
		return -1;

	if (!al_init_ttf_addon())
		return -1;

	//Fonts
	ALLEGRO_FONT *font = al_load_font("PressStart2P.ttf", 24, 0);
	if (font == NULL) {
		return(-1);
	}
	ALLEGRO_FONT *bigFont = al_load_font("PressStart2P.ttf", 64, 0);
	if (bigFont == NULL) {
		return(-1);
	}

	al_install_keyboard();
	al_init_image_addon();
	
	game Game(numSnowballs, numEnemies, font, bigFont);
	

	eventQueue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	srand(time(NULL));
	al_start_timer(timer);
	
	while (!exit) {
		ALLEGRO_EVENT event;
		al_wait_for_event(eventQueue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit = true;
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = true;
					break;
			}
		}
		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			draw = true;
			Game.runGame(keys);
		}

		if (draw) {
			draw = false;
			Game.drawGame();

			al_flip_display();
		}
	}
	
}
