#pragma once
#include "playground.h"
#include "SFML\Graphics.hpp"

class bonus {
private:
	int x, y;
	int type;//1 - bomb		2 - painter
public:
	bonus(int new_x, int new_y, int new_type) {
		x = new_x;
		y = new_y;
		type = new_type;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	virtual void trigger(Field* field) = 0;
	void drowBonus(sf::RenderWindow* window, Field* field);
};

class bomb :public bonus {
private:
	int bombedNumber = 3;

public:
	bomb(int new_x, int new_y) :bonus(new_x, new_y, 1) {}
	void trigger(Field* field) override;
};

class painter :public bonus {
private:
	int paintedNumber = 2;
	int paintedRadius = 3;

public:
	painter(int new_x, int new_y) :bonus(new_x, new_x, 2) {};
	void trigger(Field* field) override;
	bool GemIsBad(Field* field, int x, int y);
};
