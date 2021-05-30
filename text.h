#ifndef TEXT_H
#define TEXT_H

#include <vector>
#include <string>

//Класс для хранения текста и подстроки
class Text {
	std::vector<std::string> m_text;
	std::string m_substring;
	int m_substrPosition;

public:
	Text();
	
	explicit Text(std::vector<std::string> text);

	std::vector<std::string> GetText(void) const;

	std::string GetSubstr(void) const;

	int GetPosition(void) const;

	void SetSubstrPosition(int position);

	void SetSubstring(std::string substr);
	
	friend class ScreenOutput;
	friend class FileOutput;
};
#endif // TEXT_H