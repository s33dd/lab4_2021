#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <limits>
#include "manualInput.h"
#include "randomInput.h"
#include "fileInput.h"
#include "fileOutput.h"

//�������� ������������, ������� � ��������� ����������� ��� ���������������� ����������

//������������ ��� ��������� ������
enum class Menu {
	NO = 0,
	YES = 1
};

//������������ ��� ����� ����������
enum class InputType {
	MANUAL = 0,
	FILE = 1,
	RANDOM = 2
};

//���� � ����������
template <typename ElementType>
ElementType GetInput(void) {
	ElementType input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "������� ������������ ������! ��������� ����." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
	return input;
}

void StartInformation(void);

Menu ModularTestsAsk(void);

InputType InputAsk(void);

Menu SaveInputAsk(void);

Menu OutputFileAsk(void);

Menu RewriteAsk(std::string path);

Menu RepeatAsk(void);

#endif // !MENU_H