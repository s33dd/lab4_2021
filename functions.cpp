#include "functions.h"

void FindSubstr(Text &text1, Text &text2) {
	std::vector<std::string> first = text1.GetText();
	std::vector<std::string> second = text2.GetText();

	std::string firstText;
	std::string secondText;

	std::string found;
	std::string temp;
	bool matched = false;


	
	for(std::string str : first) {
		firstText += str;
	}
	for (std::string str : second) {
		secondText += str;
	}

	for (unsigned int i = 0; i < firstText.length(); i++) {
		for (unsigned int j = 0; j < secondText.length(); j++) {
			if (firstText[i] == secondText[j]) {
				matched = true;
				if (temp.empty()) {
					temp = firstText[i];
				}
				while (matched) {
					for (unsigned int k = i + 1; k < firstText.length(); k++) {
						unsigned int f = k;
						for (unsigned int z = j + 1; z < secondText.length(); z++) {
							if (firstText[f] == secondText[z]) {
								temp += firstText[f];
								if (f < firstText.length()) {
									f++;
								}
							}
							else {
								matched = false;
								if (temp.length() > found.length()) {
									found = temp;
								}
								temp.clear();
							}
						}
					}
					matched = false;
				}
			}
		}
	}

	text1.SetSubstring(found);
	text2.SetSubstring(found);

	int pos = firstText.find(found);
	//text1.SetSubstrPosition(firstText.find(found));
	//text2.SetSubstrPosition(secondText.find(found));
}