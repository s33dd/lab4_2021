#include "screenOutput.h"

void ScreenOutput::TextOutput(Text &object) {
	for(std::string i : object.m_text) {
		std::cout << i << std::endl;
	}
}

void ScreenOutput::SubstrOutput(Text &firstObject, Text &secondObject) {
	std::cout << "��������� ������:" << std::endl;
	std::cout << firstObject.GetSubstr() << std::endl << std::endl;

	std::cout << "������� � ������ ������: " << firstObject.GetPosition() << std::endl;
	std::cout << "������� �� ������ ������: " << secondObject.GetPosition() << std::endl << std::endl;

	std::cout << "����� ������: " << firstObject.GetSubstr().length() << std::endl;
}