#include "screenOutput.h"

void ScreenOutput::TextOutput(Text &object) {
	for(std::string i : object.m_text) {
		std::cout << i << std::endl;
	}
}

void ScreenOutput::SubstrOutput(Text &firstObject, Text &secondObject) {
	std::cout << "Найденная строка:" << std::endl;
	std::cout << firstObject.GetSubstr() << std::endl << std::endl;

	std::cout << "Позиция в первом тексте: " << firstObject.GetPosition() << std::endl;
	std::cout << "Позиция во втором тексте: " << secondObject.GetPosition() << std::endl << std::endl;

	std::cout << "Длина строки: " << firstObject.GetSubstr().length() << std::endl;
}