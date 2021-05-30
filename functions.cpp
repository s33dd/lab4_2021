#include "functions.h"

void CleanUp(std::string &str) {
	char space = *" ";
	int firstChar = 0;
	while(str[firstChar] == space) {
		str.erase(firstChar, 1);
	}
	if(str.empty()) {
		return;
	}
	int lastChar = str.length() - 1;
	while(str[lastChar] == space) {
		str.erase(lastChar, 1);
	}
}

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
	
	CleanUp(found);
	text1.SetSubstring(found);
	text2.SetSubstring(found);
	text1.SetSubstrPosition(firstText.find(found) + 1);
	text2.SetSubstrPosition(secondText.find(found) + 1);
}

void ReadFromFile(Text& object) {
	bool dataReaded = false;
	std::string path;
	
	std::cout << "Âגוהטעו טלÿ פאיכא:" << std::endl;
	path = GetInput<std::string>();
	FileWork checkFile(path);
	
	while (checkFile.NameForbidden()) {
		std::cout << "Âגוהטעו םמגמו טלÿ פאיכא:" << std::endl;
		path = checkFile.ChangeName();
	}
	
	FileInput input(path);
	
	dataReaded = input.Input(object);
	while (!dataReaded) {
		std::cout << "Âגוהטעו םמגמו טלÿ פאיכא:" << std::endl;
		path = input.ChangeName();
		dataReaded = input.Input(object);
	}
}

void WriteInFile(Text& object) {
	std::string path;
	Menu rewrite = Menu::YES;

	std::cout << "Âגוהטעו טלÿ פאיכא:" << std::endl;
	FileWork inputSaveFile(path);
	while (!inputSaveFile.SaveFileNormal()) {
		std::cout << "Âגוהטעו םמגמו טלÿ פאיכא:" << std::endl;
		path = inputSaveFile.ChangeName();
	}
	
	rewrite = RewriteAsk(path);
	
	if (rewrite == Menu::YES) {
		std::string newFilePath = path;
		FileWork newInputSave(newFilePath);
		
		while (newFilePath == path) {
			std::cout << "Âגוהטעו םמגמו טלÿ פאיכא:" << std::endl;
			newFilePath = newInputSave.ChangeName();
			while (!newInputSave.SaveFileNormal()) {
				std::cout << "Âגוהטעו םמגמו טלÿ פאיכא:" << std::endl;
				newFilePath = newInputSave.ChangeName();
			}
		}
		
		FileOutput file(newFilePath);
		file.SaveData(object);
	}
	
	else {
		while (inputSaveFile.FileReadOnly()) {
			std::cout << "Âגוהטעו םמגמו טלÿ פאיכא:" << std::endl;
			path = inputSaveFile.ChangeName();
		}
		
		FileOutput file(path);
		file.SaveData(object);
	}
}