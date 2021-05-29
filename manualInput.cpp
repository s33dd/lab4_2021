#include "manualInput.h"

void ManualInput::Input(Text &object) const {
	std::vector<std::string> text;
	std::string data;
	bool shown = false;
	bool endInput = false;
	std::cout << "������� Enter ��� ������ ����� ������ � � ����������." << std::endl;
	std::cout << "������� Esc ��� ���������� �����." << std::endl;
	int pressedKey = 0;
	while (pressedKey != ESC) {
		pressedKey = _getch();
		switch (pressedKey) {
		case (ENTER):
			getline(std::cin, data);
			data += " ";
			shown = false;
			text.push_back(data);
			break;
		case (ESC):
			std::cout << std::endl << "���� ��������" << std::endl << std::endl;
			endInput = true;
			shown = false;
			break;
		default:
			if (!shown) {
				std::cout << "������� ���� Enter ��� ������ ����� ����� ������, ���� Esc ��� ������" << std::endl;
			}
			shown = true;
		break;
		}
	}
	object = Text(text);
}