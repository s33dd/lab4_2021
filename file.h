#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <filesystem>
#include "menu.h"

//Класс для проверки имён файлов перед их использованием
class FileWork {
	std::string m_path;
public:
	FileWork(std::string path);

	bool NameForbidden(void) const;

	std::string ChangeName(void);

	bool FileExist(void) const;

	bool SaveFileNormal(void) const;

	bool FileReadOnly() const;
};

#endif // !FILE_H