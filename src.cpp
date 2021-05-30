#include "screenOutput.h"
#include "functions.h"

int main(void) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	auto wantTests = Menu::YES;
	auto wantContinue = Menu::YES;
	auto wantSave = Menu::YES;
	auto inputType = InputType::MANUAL;
	auto wantRewrite = Menu::YES;

	do {
		StartInformation();
		std::string filePath = "nothing";

		//wantTests = ModularTestsAsk();
		//if (wantTests == MENU::YES) {
		//	//сделать тесты
		//}

		//Ввод текстов
		inputType = InputAsk();

		Text firstText;
		Text secondText;

		if(inputType == InputType::FILE) {
			std::cout << "Ввод первого текста." << std::endl;
			ReadFromFile(firstText);

			std::cout << "Ввод второго текста." << std::endl;
			ReadFromFile(secondText);
		}
		else {
			ManualInput manual;

			std::cout << "Введите первый текст:" << std::endl;
			manual.Input(firstText);

			std::cout << "Введите второй текст:" << std::endl;
			manual.Input(secondText);
		}	

		//Вывод текстов
		ScreenOutput console;
		
		std::cout << "Первый текст:" << std::endl;
		console.TextOutput(firstText);

		std::cout << std::endl << "Второй текст:" << std::endl;
		console.TextOutput(secondText);


		//Поиск наибольшей общей подстроки
		FindSubstr(firstText, secondText);

		//Вывод информации о подстроке
		console.SubstrOutput(firstText, secondText);

		//Сохранение исходных данных
		if(inputType != InputType::FILE) {
			wantSave = SaveInputAsk();
			if (wantSave == Menu::YES) {
				std::cout << "Сохранение первого текста." << std::endl;
				WriteInFile(firstText);

				std::cout << "Сохранение второго текста." << std::endl;
				WriteInFile(secondText);
			}
		}

		//Сохранение результата
		wantSave = OutputFileAsk();
		if (wantSave == Menu::YES) {
			std::cout << "Введите имя файла:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "Введите новое имя файла:" << std::endl;
				filePath = outputSaveFile.ChangeName();
			}
			wantRewrite = RewriteAsk(filePath);
			if (wantRewrite == Menu::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "Введите новое имя файла:" << std::endl;
					newFilePath = newOutputSave.ChangeName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "Введите новое имя файла:" << std::endl;
						newFilePath = newOutputSave.ChangeName();
					}
				}
				FileOutput file(newFilePath);
				file.Output(firstText, secondText);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "Введите новое имя файла:" << std::endl;
					filePath = outputSaveFile.ChangeName();
				}
				FileOutput file(filePath);
				file.Output(firstText, secondText);
			}
		}

		wantContinue = RepeatAsk();
	} while (wantContinue == Menu::YES);
}