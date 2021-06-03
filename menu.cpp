#include "menu.h"
#include <fstream>

void StartInformation() {
	std::cout << "________________________" << std::endl;
	std::cout << "������������ ������ �� ���������������� �4" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "������� 25" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "��� ���� �������� ������� ����� ����� ������� ����� ���������." << std::endl;
	std::cout << "��������� ������ �������� �������, � ������� ����� ���������� � ������ ";
	std::cout << "�� ������, ����� ������ � ����� ����� ������." << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "�������� ������� 403 ������ ";
	std::cout << "����������� ����� ����������.  2021 ���" << std::endl;
	std::cout << "________________________" << std::endl << std::endl;
}

bool RightMenuChoice(Menu choice) {
	if ((choice == Menu::NO) || (choice == Menu::YES)) {
		return true;
	}
	else {
		std::cout << "����������� ��������� ��������!" << std::endl;
		return false;
	}
}

bool RightInputChoice(InputType choice) {
	if ((choice == InputType::MANUAL) || (choice == InputType::FILE)) {
		return true;
	}
	else {
		std::cout << "����������� ��������� ��������!" << std::endl;
		return false;
	}
}

Menu ModularTestsAsk(void) {
	std::cout << "������� ��������� ��������� �����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

InputType InputAsk(void) {
	std::cout << "��� �� ������� ������ �����?" << std::endl;
	std::cout << "1 � �� ����� / 0 � � ����������" << std::endl;
	std::cout << "��� �����: ";
	InputType decision = static_cast<InputType>(GetInput<int>());
	while (!RightInputChoice(decision)) {
		decision = static_cast<InputType>(GetInput<int>());
	}
	return decision;
}

Menu SaveInputAsk(void) {
	std::cout << "������� ��������� �������� ������ � ����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

Menu OutputFileAsk(void) {
	std::cout << "������� ��������� ��������� � ����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

Menu RewriteAsk(std::string path) {
	std::ifstream checkFile;
	checkFile.open(path);
	Menu decision = Menu::NO;
	if (checkFile.is_open()) {
		std::cout << "���� � ����� ������ ��� ����������!" << std::endl;
		std::cout << "��� �� ������� ������� � ������?" << std::endl;
		std::cout << "1 � ������� ����� / 0 � ������������ ������������" << std::endl;
		std::cout << "��� �����: ";
		decision = static_cast<Menu>(GetInput<int>());
		while (!RightMenuChoice(decision)) {
			decision = static_cast<Menu>(GetInput<int>());
		}
		checkFile.close();
		return decision;
	}
	else {
		checkFile.close();
		return decision;
	}
}

Menu RepeatAsk(void) {
	std::cout << "������� �� �� �������� ��������� ���������?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}