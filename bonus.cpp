#include "bonus.h"

void bonus::drowBonus(sf::RenderWindow* window, Field* field) {
	int width{ 80 }, height{ 80 };
	int pos_x = x * width;
	int pos_y = y * height;
	sf::CircleShape square(30, 4);
	square.setPosition(static_cast<float>(pos_x), static_cast<float>(pos_y));
	window->draw(square);
}

void bomb::trigger(Field* field) {
	int t_x, t_y;
	field->removeGem(getX(), getY(), getX() - 1, getX() + 1, getY() - 1, getY() + 1);

	for (int i = 0; i < bombedNumber - 1; i++) {
		t_x = rand() % 8 + 1;
		t_y = rand() % 8 + 1;
		field->removeGem(t_x, t_y, t_x - 1, t_x + 1, t_y - 1, t_y + 1);
	}
}

bool painter::GemIsBad(Field* field, int x, int y) {
	bool empty = false;

	if (x < field->GemAmount() && y < field->GemAmount()) {
		empty = field->GemIsEmpty(x, y);

		return empty;
	}
	else {
		return true;
	}
}

void painter::trigger(Field* field) {
	int rand_X = 0, rand_Y = 0;

	for (int i = 0; i < paintedNumber; i++) {
		do {
			rand_X = getX() + (rand() % (paintedRadius - 1) + 2) * (int)pow(-1, rand() % 2);
			rand_Y = getY() + (rand() % (paintedRadius - 1) + 2) * (int)pow(-1, rand() % 2);

		} while (GemIsBad(field, rand_X, rand_Y));

		field->SetColorToOneGem(rand_X, rand_Y);
	}
}