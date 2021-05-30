#include "fileInput.h"

FileInput::FileInput(std::string path) {
	m_path = path;
}

std::string FileInput::ChangeName() {
	m_path = GetInput<std::string>();
	FileWork file(m_path);
	while (file.NameForbidden()) {
		m_path = file.ChangeName();
	}
	return m_path;
}

bool FileInput::Input(Text &object) {
	std::ifstream inputFile;
	std::vector<std::string> text;
	std::string data;
	inputFile.open(m_path);

	if(!inputFile.is_open()) {
		std::cout << "Файл не найден." << std::endl;
		return false;
	}
	
	while (!inputFile.eof()) {
		getline(inputFile, data);
		if (!data.empty()) {
			data += " ";
		}
		text.push_back(data);
	}
	
	int emptyCounter = 0;
	for (std::string str : text) {
		if (str.empty()) {
			emptyCounter++;
		}
	}

	if (emptyCounter == text.size()) {
		std::cout << "Файл пуст." << std::endl;
		inputFile.close();
		return false;
	}
	else {
		object = Text(text);
		inputFile.close();
		return true;
	}
}