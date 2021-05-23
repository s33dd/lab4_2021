#ifndef RANDOMINPUT_H
#define RANDOMINPUT_H

#include "menu.h"
#include <ctime>

//������� � ������ ������ ��������� �����
enum ConstsForRandom {
	LOWER_BORDER = -100,
	UPPER_BORDER = 100
};

//����� ��� ���������� ���������� �������
class RandomInput {
	unsigned int m_seed;
public:
	RandomInput(void);

	void Input(void); //�������� ��� �������
};

#endif // !RANDOMINPUT_H