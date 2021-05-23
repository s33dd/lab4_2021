#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include "file.h"

//Класс для вывода в файл
class FileOutput {
	std::string m_path;
public:
	FileOutput(std::string path);

	void Output(void); //Добавить что выводить

	void SaveData(void); //Добавить что сохранять
};

#endif // !FILEOUTPUT_H