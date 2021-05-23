#include "manualInput.h"

void ManualInput::Input(Text &object) const {
	std::vector<std::string> text;
	std::string data;
	bool endInput = false;
	std::cout << "������� Enter ��� ������ ����� ������ � � ����������." << std::endl;
	std::cout << "������� Esc ��� ���������� �����." << std::endl;
	int pressedKey = 0;
	while (pressedKey != ESC) {
		pressedKey = _getch();
		switch (pressedKey) {
		case (ENTER):
			getline(std::cin, data);
			text.push_back(data);
			break;
		case (ESC):
			std::cout << "���� ��������" << std::endl;
			endInput = true;
			break;
		default:
			std::cout << "������� ���� Enter ��� ������ ����� ����� ������, ���� Esc ��� ������" << std::endl;
			text.push_back(data);
		break;
		}
	}
	object = Text(text);
}