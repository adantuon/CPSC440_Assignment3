//Aiden D'Antuono

#pragma once
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

class penguin
{
public:
	penguin();
	~penguin();
	void drawPenguin();
	void startPenguin(int WIDTH, int HEIGHT);
	void updatePenguin();
	void collidePenguin(int WIDTH, int HEIGHT);
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
	bool getLive() { return inPlay; }
	void setLive(bool l) { inPlay = l; }
private:
	int x;
	int y;
	bool inPlay;
	bool alive;
	int speed;
	int boundx;
	int boundy;
	ALLEGRO_BITMAP *image[2];
};