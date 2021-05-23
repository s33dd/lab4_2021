#ifndef MANUALINPUT_H
#define MANUALINPUT_H

#include "menu.h"
#include "text.h"
#include <conio.h>

enum Keys {
	ENTER = 13,
	ESC = 27
};

//Класс для заполнения с клавиатуры
class ManualInput {
public:
	void Input(Text &object) const;
};

#endif // !MANUALINPUT_H