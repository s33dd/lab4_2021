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
		//	//������� �����
		//}

		//���� �������
		inputType = InputAsk();

		Text firstText;
		Text secondText;

		if(inputType == InputType::FILE) {
			std::cout << "���� ������� ������." << std::endl;
			ReadFromFile(firstText);

			std::cout << "���� ������� ������." << std::endl;
			ReadFromFile(secondText);
		}
		else {
			ManualInput manual;

			std::cout << "������� ������ �����:" << std::endl;
			manual.Input(firstText);

			std::cout << "������� ������ �����:" << std::endl;
			manual.Input(secondText);
		}	

		//����� �������
		ScreenOutput console;
		
		std::cout << "������ �����:" << std::endl;
		console.TextOutput(firstText);

		std::cout << std::endl << "������ �����:" << std::endl;
		console.TextOutput(secondText);


		//����� ���������� ����� ���������
		FindSubstr(firstText, secondText);

		//����� ���������� � ���������
		console.SubstrOutput(firstText, secondText);

		//���������� �������� ������
		if(inputType != InputType::FILE) {
			wantSave = SaveInputAsk();
			if (wantSave == Menu::YES) {
				std::cout << "���������� ������� ������." << std::endl;
				WriteInFile(firstText);

				std::cout << "���������� ������� ������." << std::endl;
				WriteInFile(secondText);
			}
		}

		//���������� ����������
		wantSave = OutputFileAsk();
		if (wantSave == Menu::YES) {
			std::cout << "������� ��� �����:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = outputSaveFile.ChangeName();
			}
			wantRewrite = RewriteAsk(filePath);
			if (wantRewrite == Menu::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					newFilePath = newOutputSave.ChangeName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "������� ����� ��� �����:" << std::endl;
						newFilePath = newOutputSave.ChangeName();
					}
				}
				FileOutput file(newFilePath);
				file.Output(firstText, secondText);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = outputSaveFile.ChangeName();
				}
				FileOutput file(filePath);
				file.Output(firstText, secondText);
			}
		}

		wantContinue = RepeatAsk();
	} while (wantContinue == Menu::YES);
}