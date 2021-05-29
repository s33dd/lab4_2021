#include "text.h"

Text::Text() = default;

Text::Text(std::vector<std::string> text) {
	m_text = text;
	m_substring = "1";
	m_substrPosition = 0;
}

std::vector<std::string> Text::GetText(void) const {
	return m_text;
}

std::string Text::GetSubstr(void) const {
	return m_substring;
}

int Text::GetPosition(void) const {
	return m_substrPosition;
}

void Text::SetSubstrPosition(int position) {
	if (position <= static_cast<int>(m_substring.length())) {
		m_substrPosition = position;
	}
}

void Text::SetSubstring(std::string substr) {
	m_substring = substr;
}
