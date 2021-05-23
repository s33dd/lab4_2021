#ifndef SCREENOUTPUT_H
#define SCREENOUTPUT_H

#include "menu.h"
#include "text.h"
#include <Windows.h>

//Класс для вывода данных на экран
class ScreenOutput {
public:
	void Output(Text &object);
};

#endif // !SCREENOUTPUT_H