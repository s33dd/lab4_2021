#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include "file.h"

//����� ��� ������ � ����
class FileOutput {
	std::string m_path;
public:
	FileOutput(std::string path);

	void Output(void); //�������� ��� ��������

	void SaveData(void); //�������� ��� ���������
};

#endif // !FILEOUTPUT_H