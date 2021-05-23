#ifndef FILEINPUT_H
#define FILEINPUT_H

#include "file.h"

//Класс FileInput для ввода из файла
class FileInput {
	std::string m_path;
public:
	explicit FileInput(std::string path);

	bool Input(void); //Добавить что принимает

	std::string ChangeName(void);
};

#endif // !FILEINPUT_H