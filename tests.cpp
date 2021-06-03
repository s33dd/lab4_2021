#include "tests.h"

bool FileCheck(std::string path, int num) {
	std::ifstream check;
	check.open(path);
	if (!check.is_open()) {
		std::cout << "В проекте отсутствуют необходимые для проведения " << num + 1 << " теста файлы." << std::endl;
		std::cout << "Пожалуйста, убедитесь, что в папке проекта существует папка Tests с необходимыми файлами." << std::endl;
		std::cout << "Названия нужных файлов должны быть по шаблону: Номер теста_Номер текста. А так же файл с ответом: ANSWER_Номер теста." << std::endl << std::endl;
		check.close();
		return false;
	}
	check.close();
	return true;
}

bool Test::ReadTexts(std::string firstPath, std::string secondPath, int num) {
	std::ifstream inputFile;
	std::vector<std::string> text;
	std::string data;
	
	inputFile.open(firstPath);
	if(!FileCheck(firstPath, num)) {
		inputFile.close();
		return false;
	};
	while (!inputFile.eof()) {
		getline(inputFile, data);
		if (!data.empty()) {
			data += " ";
		}
		text.push_back(data);
	}
	m_first = Text(text);
	inputFile.close();

	text.clear();
	
	inputFile.open(secondPath);
	if(!FileCheck(secondPath, num)) {
		inputFile.close();
		return false;
	};
	while (!inputFile.eof()) {
		getline(inputFile, data);
		if (!data.empty()) {
			data += " ";
		}
		text.push_back(data);
	}
	m_second = Text(text);
	inputFile.close();
	return true;
}

bool Test::ReadAnswers(std::string path, int num) {
	std::ifstream answersFile;
	std::string data;

	answersFile.open(path);
	if(!FileCheck(path, num)) {
		answersFile.close();
		return false;
	};

	getline(answersFile, data);
	m_answers["substr"] = data;

	getline(answersFile, data);
	m_answers["firstIndex"] = data;

	getline(answersFile, data);
	m_answers["secondIndex"] = data;

	getline(answersFile, data);
	m_answers["length"] = data;

	answersFile.close();
	return true;
}

bool Test::Check() {
	if (m_first.GetSubstr() != m_answers["substr"]) {
		return false;
	}
	if (m_first.GetPosition() != stoi(m_answers["firstIndex"])) {
		return false;
	}
	if (m_second.GetPosition() != stoi(m_answers["secondIndex"])) {
		return false;
	}
	if (m_first.GetSubstr().length() != static_cast<unsigned int>(stoi(m_answers["length"]))) {
		return false;
	}
	return true;
}

bool Test::MakeTest(int fileIndex, const std::string* names, int number) {
	if(!(ReadTexts(names[fileIndex], names[fileIndex + 1], number))) {
		return false;
	}

	if(!(ReadAnswers(names[fileIndex + 2], number))) {
		return false;
	}

	FindSubstr(m_first, m_second);

	if(!Check()) {
		ScreenOutput screen;
		std::cout << "Ошибка в выполнении " << number + 1 << " теста." << std::endl;
		std::cout << "Полученные результаты:" << std::endl << std::endl;
		screen.SubstrOutput(m_first, m_second);
		std::cout << std::endl << "Правильный ответ:" << std::endl << std::endl;
		std::cout << "Строка: " << m_answers["substr"] << std::endl;
		std::cout << "Позиция в первом тексте: " << m_answers["firstIndex"] << std::endl;
		std::cout << "Позиция во втором тексте: " << m_answers["secondIndex"] << std::endl;
		std::cout << "Длина: " << m_answers["length"] << std::endl;
		return false;
	}
	return true;
}

void MakeTests() {
	const std::string testFiles[] = {
	"Tests/1_1.txt",
	"Tests/1_2.txt",
	"Tests/ANSWERS_1.txt",
	"Tests/2_1.txt",
	"Tests/2_2.txt",
	"Tests/ANSWERS_2.txt",
	"Tests/3_1.txt",
	"Tests/3_2.txt",
	"Tests/ANSWERS_3.txt",
	"Tests/4_1.txt",
	"Tests/4_2.txt",
	"Tests/ANSWERS_4.txt",
	"Tests/5_1.txt",
	"Tests/5_2.txt",
	"Tests/ANSWERS_5.txt"
	};

	for (int testNum = 0; testNum < 5; testNum++) {
		for (int filesSet = 0; filesSet < 15; filesSet += 3) {
			Test test;
			if (!(test.MakeTest(filesSet, testFiles, testNum))) {
				return;
			}
			testNum++;
		}
	}
	std::cout << "Тесты выполнены успешно!" << std::endl;
}