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
	bool collidePenguin(int WIDTH, int HEIGHT);
	int getBoundXL() { return boundxl; }
	int getBoundXR() { return boundxr; }
	int getBoundYT() { return boundyt; }
	int getBoundYB() { return boundyb; }
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
	int boundxl;
	int boundxr;
	int boundyt;
	int boundyb;
	ALLEGRO_BITMAP *image[2];
};