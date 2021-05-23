#ifndef RANDOMINPUT_H
#define RANDOMINPUT_H

#include "menu.h"
#include <ctime>

//Верхний и нижний предел случайных чисел
enum ConstsForRandom {
	LOWER_BORDER = -100,
	UPPER_BORDER = 100
};

//Класс для заполнения случайными числами
class RandomInput {
	unsigned int m_seed;
public:
	RandomInput(void);

	void Input(void); //Добавить что вводить
};

#endif // !RANDOMINPUT_H