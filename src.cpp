#include "menu.h"
#include "screenOutput.h"

int main(void) {
	SetConsoleCP(CP_UTF8);
	setlocale(LC_ALL, "Russian");

	auto wantTests = Menu::YES;
	auto wantContinue = Menu::YES;
	auto wantSave = Menu::YES;
	auto wantRewrite = Menu::YES;
	auto inputType = InputType::RANDOM;
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
		Text text;
		ScreenOutput console;

		manual.Input(text);

		console.Output(text);

		wantContinue = RepeatAsk();

	} while (wantContinue == Menu::YES);
}