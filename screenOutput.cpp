#include "screenOutput.h"

void ScreenOutput::Output(Text &object) {
	for(std::string i : object.m_text) {
		std::cout << i << std::endl;
	}
}