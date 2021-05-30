#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include "file.h"
#include "text.h"

//Класс для вывода в файл
class FileOutput {
	std::string m_path;
public:
	FileOutput(std::string path);

	void Output(Text &text1, Text &text2);

	void SaveData(Text &object);
};

#endif // !FILEOUTPUT_H