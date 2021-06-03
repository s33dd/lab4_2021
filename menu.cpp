#include "menu.h"
#include <fstream>

void StartInformation() {
	std::cout << "________________________" << std::endl;
	std::cout << "Лабораторная работа по программированию №4" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Вариант 25" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Для двух заданных текстов найти самую длинную общую подстроку." << std::endl;
	std::cout << "Программа должна выводить позицию, с которой текст начинается в каждом ";
	std::cout << "из файлов, длину строки и текст самой строки." << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Выполнил студент 403 группы ";
	std::cout << "Суховериков Денис Дмитриевич.  2021 год" << std::endl;
	std::cout << "________________________" << std::endl << std::endl;
}

bool RightMenuChoice(Menu choice) {
	if ((choice == Menu::NO) || (choice == Menu::YES)) {
		return true;
	}
	else {
		std::cout << "Используйте указанные варианты!" << std::endl;
		return false;
	}
}

bool RightInputChoice(InputType choice) {
	if ((choice == InputType::MANUAL) || (choice == InputType::FILE)) {
		return true;
	}
	else {
		std::cout << "Используйте указанные варианты!" << std::endl;
		return false;
	}
}

Menu ModularTestsAsk(void) {
	std::cout << "Желаете выполнить модульные тесты?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

InputType InputAsk(void) {
	std::cout << "Как вы желаете ввести текст?" << std::endl;
	std::cout << "1 — Из файла / 0 — С клавиатуры" << std::endl;
	std::cout << "Ваш выбор: ";
	InputType decision = static_cast<InputType>(GetInput<int>());
	while (!RightInputChoice(decision)) {
		decision = static_cast<InputType>(GetInput<int>());
	}
	return decision;
}

Menu SaveInputAsk(void) {
	std::cout << "Желаете сохранить исходные данные в файл?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

Menu OutputFileAsk(void) {
	std::cout << "Желаете сохранить результат в файл?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
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
		std::cout << "Файл с таким именем уже существует!" << std::endl;
		std::cout << "Что вы желаете сделать с файлом?" << std::endl;
		std::cout << "1 — Создать новый / 0 — Перезаписать существующий" << std::endl;
		std::cout << "Ваш выбор: ";
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
	std::cout << "Желаете ли вы повторно выполнить программу?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}