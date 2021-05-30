#include "fileOutput.h"

FileOutput::FileOutput(std::string path) {
	m_path = path;
}

void FileOutput::Output(Text &text1, Text &text2) {
	std::ofstream outputFile;
	outputFile.open(m_path);
	outputFile << "Первый текст:" << std::endl;
	for (std::string i : text1.m_text) {
		outputFile << i << std::endl;
	}
	outputFile << std::endl << "Второй текст:" << std::endl;
	for (std::string i : text2.m_text) {
		outputFile << i << std::endl;
	}

	if (text1.GetSubstr().empty()) {
		outputFile << "Общей подстроки нет." << std::endl;
	}
	else {
		outputFile << "Найденная строка:" << std::endl;
		outputFile << text1.GetSubstr() << std::endl << std::endl;

		outputFile << "В первом тексте строка начинается с " << text1.GetPosition() << " символа." << std::endl;
		outputFile << "Во втором тексте строка начинается с " << text2.GetPosition() << " символа." << std::endl << std::endl;

		outputFile << "Длина строки: " << text1.GetSubstr().length() << std::endl;
	}

	outputFile.close();
}

void FileOutput::SaveData(Text &object) {
	std::ofstream dataFile;
	dataFile.open(m_path);
	for (std::string i : object.m_text) {
		dataFile << i << std::endl;
	}
	dataFile.close();
}