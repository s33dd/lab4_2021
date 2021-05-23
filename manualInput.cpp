#include "manualInput.h"

void ManualInput::Input(Text &object) const {
	std::vector<std::string> text;
	std::string data;
	bool endInput = false;
	std::cout << "Нажмите Enter для начала ввода строки и её сохранения." << std::endl;
	std::cout << "Нажмите Esc для завершения ввода." << std::endl;
	int pressedKey = 0;
	while (pressedKey != ESC) {
		pressedKey = _getch();
		switch (pressedKey) {
		case (ENTER):
			getline(std::cin, data);
			text.push_back(data);
			break;
		case (ESC):
			std::cout << "Ввод завершён" << std::endl;
			endInput = true;
			break;
		default:
			std::cout << "Нажмите либо Enter для начала ввода новой строки, либо Esc для выхода" << std::endl;
			text.push_back(data);
		break;
		}
	}
	object = Text(text);
}