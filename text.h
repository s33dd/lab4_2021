#ifndef TEXT_H
#define TEXT_H

#include <vector>
#include <string>

//Класс для хранения текста и подстроки
class Text {
private:
	
	std::vector<std::string> m_text;
	std::vector<std::string> m_substring;

public:

	Text();
	
	explicit Text(std::vector<std::string> text);

	friend class ScreenOutput;
	
};
#endif // TEXT_H