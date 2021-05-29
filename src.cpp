#include "menu.h"
#include "screenOutput.h"
#include "functions.h"

int main(void) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	auto wantTests = Menu::YES;
	auto wantContinue = Menu::YES;
	auto wantSave = Menu::YES;
	auto wantRewrite = Menu::YES;
	auto inputType = InputType::MANUAL;
	bool dataReaded = false;

	do {
		StartInformation();
		std::string filePath = "nothing";

		//wantTests = ModularTestsAsk();
		//if (wantTests == MENU::YES) {
		//	//������� �����
		//}

		inputType = InputAsk();

		ManualInput manual;
		Text firstText;
		Text secondText;
		ScreenOutput console;
		
		std::cout << "������� ������ �����:" << std::endl;
		manual.Input(firstText);

		std::cout << "������� ������ �����:" << std::endl;
		manual.Input(secondText);

		std::cout << "������ �����:" << std::endl;
		console.TextOutput(firstText);

		std::cout << "������ �����:" << std::endl;
		console.TextOutput(secondText);

		
		FindSubstr(firstText, secondText);

		console.SubstrOutput(firstText, secondText);
		
		wantContinue = RepeatAsk();

	} while (wantContinue == Menu::YES);
}