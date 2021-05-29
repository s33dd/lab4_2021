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
		//	//сделать тесты
		//}

		inputType = InputAsk();

		ManualInput manual;
		Text firstText;
		Text secondText;
		ScreenOutput console;
		
		std::cout << "¬ведите первый текст:" << std::endl;
		manual.Input(firstText);

		std::cout << "¬ведите второй текст:" << std::endl;
		manual.Input(secondText);

		std::cout << "ѕервый текст:" << std::endl;
		console.TextOutput(firstText);

		std::cout << "¬торой текст:" << std::endl;
		console.TextOutput(secondText);

		
		FindSubstr(firstText, secondText);

		console.SubstrOutput(firstText, secondText);
		
		wantContinue = RepeatAsk();

	} while (wantContinue == Menu::YES);
}