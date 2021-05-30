#include "screenOutput.h"

void ScreenOutput::TextOutput(Text &object) {
	for(std::string i : object.m_text) {
		std::cout << i << std::endl;
	}
}

void ScreenOutput::SubstrOutput(Text &firstObject, Text &secondObject) {
	if(firstObject.GetSubstr().empty()) {
		std::cout << "Общей подстроки нет." << std::endl;
	}
	else {
		std::cout << "Найденная строка:" << std::endl;
		std::cout << firstObject.GetSubstr() << std::endl << std::endl;

		std::cout << "В первом тексте строка начинается с " << firstObject.GetPosition() << " символа." << std::endl;
		std::cout << "Во втором тексте строка начинается с " << secondObject.GetPosition() << " символа." << std::endl << std::endl;

		std::cout << "Длина строки: " << firstObject.GetSubstr().length() << std::endl;
	}
}