// Code Samples C++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sorts.h"
#include "Calculator.h"
#include "LongCalc.h"
#include "InfoIO.h"
#include "FileIO.h"
#include "Hamming.h"
#include "BSGame.h"
#include "BSMainMenu.h"
#include "ChessFigure.h"
#include "Matrix.h"
#include "Knight.h"
#include "Zebra.h"
#include "MapArray.h"
#include "Pair.h"
#include "Random.h"
#pragma region Common
FileIO fileIO = FileIO();
InfoIO io = IO();
Random r = Random();
#pragma endregion

#pragma region Enums
enum actions {
	sum = 0,
	sub,
	mul,
	divide,
	mod,
	more,
	less,
	equal,
};
string ActionsToStr(int action) {
	switch (action) {
	case 0:
		return "addition";
	case 1:
		return "subtraction";
	case 2:
		return "multiply";
	case 3:
		return "divide";
	case 4:
		return "mod";
	case 5:
		return "more";
	case 6:
		return "less";
	case 7:
		return "equal";
	}
}
string ActionsSignToStr(int action) {
	switch (action) {
	case 0:
		return "+";
	case 1:
		return "-";
	case 2:
		return "*";
	case 3:
		return "/";
	case 4:
		return "%";
	case 5:
		return ">";
	case 6:
		return "<";
	case 7:
		return "==";
	}
}
#pragma endregion

#pragma region Long Calculator
vector<Pair>pairs = {
	//Pair("4","1"),
	//Pair("-4","-1"),
	//Pair("-4","1"),
	//Pair("4","-1"),
	//Pair("8","-10"),
	//Pair("5","5")
};
vector<vector<string>> expected(8);
vector<vector<string>> actual(8);
LongCalc calc = LongCalc();
#pragma endregion
void FillPairs(int count) {
	vector<int> keys = r.GetArrayInt(1, 100, count, false);
	vector<int> values = r.GetArrayInt(1, 100, count, false);
	for (int i = 0; i < count; i++)
		pairs.push_back(Pair(to_string(keys[i]), to_string(values[i])));
}

void FillExpected() {
	for (int i = 0; i < pairs.size(); i++)
	{
		expected[actions::more].push_back((atoi(pairs[i].key.c_str()) > atoi(pairs[i].value.c_str())) ? "true" : "false");
		expected[actions::less].push_back((atoi(pairs[i].key.c_str()) < atoi(pairs[i].value.c_str())) ? "true" : "false");
		expected[actions::equal].push_back((atoi(pairs[i].key.c_str()) == atoi(pairs[i].value.c_str())) ? "true" : "false");
		expected[actions::sum].push_back(to_string(atoi(pairs[i].key.c_str()) + atoi(pairs[i].value.c_str())));
		expected[actions::sub].push_back(to_string(atoi(pairs[i].key.c_str()) - atoi(pairs[i].value.c_str())));
		expected[actions::mul].push_back(to_string(atoi(pairs[i].key.c_str()) * atoi(pairs[i].value.c_str())));
		expected[actions::divide].push_back(to_string(atoi(pairs[i].key.c_str()) / atoi(pairs[i].value.c_str())));
		expected[actions::mod].push_back(to_string(atoi(pairs[i].key.c_str()) % atoi(pairs[i].value.c_str())));
	}
}

void FillActual() {
	for (int i = 0; i < pairs.size(); i++)
	{
		LongVal a = LongVal(pairs[i].key), b = LongVal(pairs[i].value);
		actual[actions::more].push_back((a > b) ? "true" : "false");
		actual[actions::less].push_back((a < b) ? "true" : "false");
		actual[actions::equal].push_back((a == b) ? "true" : "false");
		actual[actions::sum].push_back((a + b).ToStr());
		actual[actions::sub].push_back((a - b).ToStr());
		actual[actions::mul].push_back((a * b).ToStr());
		actual[actions::divide].push_back((a / b).ToStr());
		actual[actions::mod].push_back((a % b).ToStr());
	}
}

void Check(vector<string>expected, vector<string> actual) {
	for (int i = 0; i < max(expected.size(), actual.size()); i++) {

	}
}
/// <summary>
/// 
/// </summary>
void CommonTest(int testLogId) {
	vector<Pair> total;
	for (int i = 0; i < min(expected.size(), actual.size()); i++)
	{

		int passedCount = pairs.size();
		//io.PrintLn("compare test:");
		if (i == testLogId)
			printf("%s test:\n", ActionsToStr(i).c_str());
		for (int j = 0; j < pairs.size(); j++) {
			bool passed = (expected[i][j] == actual[i][j]);
			if (!passed)
				passedCount--;
			if (i == testLogId) {
				io.PrintSeparator(50);
				printf("%s %s %s=%s\n", pairs[j].key.c_str(), ActionsSignToStr(testLogId).c_str(), pairs[j].value.c_str(), actual[i][j].c_str());
				if (passed)
					io.SetColor(ConsoleColor::White, ConsoleColor::Green);
				else
					io.SetColor(ConsoleColor::White, ConsoleColor::Red);
				printf("Expected:%s Actual:%s Passed:%s\n", expected[i][j].c_str(), actual[i][j].c_str(), passed ? "true" : "false");
				io.SetColor(ConsoleColor::White, ConsoleColor::Black);
				io.PrintSeparator(50);
			}
		}
		if (passedCount == pairs.size())
			io.SetColor(ConsoleColor::White, ConsoleColor::Green);
		else
			io.SetColor(ConsoleColor::White, ConsoleColor::Red);
		printf("%s tests passed:%i/%i \n", ActionsToStr(i).c_str(), passedCount, pairs.size());
		io.SetColor(ConsoleColor::White, ConsoleColor::Black);
		total.push_back(Pair(ActionsToStr(testLogId), to_string(passedCount)));
	}
}

int GetArraySum() {
	const int32_t dim = 5;
	int32_t array1[dim] = { 1, 2, 3, 4, 5 };
	int32_t array2[dim] = { 10, 20, 30, 40, 50 };
	int32_t arrayResult[dim] = {};

	__asm {
		lea eax, array1
		lea ebx, array2
		lea edx, arrayResult
		mov ecx, [dim]
		shr ecx, 1
		jz one

		repeat :
		movq mm0, [eax]
			movq mm1, [ebx]
			paddd mm1, mm0
			movq[edx], mm1
			add eax, 8
			add ebx, 8
			add edx, 8
			loop repeat

			mov ecx, [dim]
			bt ecx, 0

			one:
		jnc end; В т.ч.защита от пустого массива

			movd mm0, [eax]
			movd mm1, [ebx]
			paddd mm1, mm0
			movd[edx], mm1
			end :
	}

	for (auto i : arrayResult)
		std::cout << " " << i;
}

/// <summary>
/// точка входа
/// </summary>
/// <returns></returns>
int main()
{
	//LongVal a = LongVal("1") - LongVal("22");
	//cout << a.ToStr();
	//cout<<(LongVal("82") > LongVal("43"))<<endl;
	srand(time(NULL));
	io.SetRusIO();
	FillPairs(100);
	FillExpected();
	FillActual();
	//TODO: доделать вычитание
	//CommonTest(actions::sub);


	//LongVal res= calc.Sum("122379128379182391283791827319230192830192830192830192830192238123", "81881818818819819811989183");
	//TODO: додлетаь операции на длинных числах
	//проверить сложение
	//LongVal a = LongVal("-1");
	//LongVal res = calc.Sum("1", "-40");
	//cout << res.ToStr() << endl;

	/*BSGame game = BSGame();
	BSMainMenu menu = BSMainMenu(&game);
	menu.Start();*/

	/*MapArray map = MapArray();
	map.Add("1", "lol");
	map.Add("1", "lol");
	map.Add("2", "lo2");
	cout << map.GetStr();*/

	Matrix m = Matrix(10, 10, Matrix::MatrixType::zero);

	for (int n = 1; n <= 4; n++) {
		for (int k = 1; k <= 4; k++) {
			m.matrix[n][k] = m.matrix[n][k] + 1;
			m.matrix[k][n] = m.matrix[k][n] + 1;
		}
	}
	io.Print(m.matrix);


	io.Pause();
	return 0;
}