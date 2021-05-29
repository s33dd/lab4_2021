#ifndef SCREENOUTPUT_H
#define SCREENOUTPUT_H

#include "menu.h"
#include "text.h"
#include <Windows.h>

//Класс для вывода данных на экран
class ScreenOutput {
public:
	void TextOutput(Text &object);

	void SubstrOutput(Text &firstObject, Text &secondObject);
};

#endif // !SCREENOUTPUT_H