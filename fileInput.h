#ifndef FILEINPUT_H
#define FILEINPUT_H

#include "file.h"

//����� FileInput ��� ����� �� �����
class FileInput {
	std::string m_path;
public:
	explicit FileInput(std::string path);

	bool Input(void); //�������� ��� ���������

	std::string ChangeName(void);
};

#endif // !FILEINPUT_H