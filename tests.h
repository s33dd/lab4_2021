#ifndef TESTS_H
#define TESTS_H

#include "functions.h"
#include "file.h"
#include "screenOutput.h"
#include <map>

class Test {
	std::map<std::string, std::string> m_answers;
	Text m_first;
	Text m_second;

public:
	Test() = default;
	
	~Test() = default;
	
	bool ReadTexts(std::string firstPath, std::string secondPath, int num);

	bool ReadAnswers(std::string path, int num);

	bool Check();
	
	bool MakeTest(int fileIndex, const std::string *names, int number);
};

void MakeTests(void);

#endif