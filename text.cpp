#include "text.h"

Text::Text() = default;

Text::Text(std::vector<std::string> text) {
	m_text = text;
	m_substring = std::vector<std::string>(1, "1");
}