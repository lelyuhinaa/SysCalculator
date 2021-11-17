#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Начальное число
string inputValue;
int inputNumBase, outputNumBase;

int convert_to_ten(string num, int q) {
	int result = 0;
	int n = num.length();
	int a;
	for (int i = 0; i < num.length(); i++)
	{
		char symbol;
		symbol = num[i];
		if (q == 16) {
			switch (symbol) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				a = symbol - '0';
				break;
			case 'A':
				a = 10;
				break;
			case 'B':
				a = 11;
				break;
			case 'C':
				a = 12;
				break;
			case 'D':
				a = 13;
				break;
			case 'E':
				a = 14;
				break;
			case 'F':
				a = 15;
				break;
			}
		}
		else {
			char symbol;
			symbol = num[i];
			a = symbol - '0';
		}
		result += a * pow(q, n - i - 1);
	}

	return result;
}

string convert_to_others(int num, int q) {
	string res;
	int r;
	bool flag = true;
	while (flag)
	{
		r = num % q;
		num = (num - r) / q;

		if (q != 16) {
			res.insert(0, to_string(r));
		}

		if (q == 16) {
			switch (r)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				res.insert(0, to_string(r));
				break;
			case 10:
				res.insert(0, "A");
				break;
			case 11:
				res.insert(0, "B");
				break;
			case 12:
				res.insert(0, "C");
				break;
			case 13:
				res.insert(0, "D");
				break;
			case 14:
				res.insert(0, "E");
				break;
			case 15:
				res.insert(0, "F");
				break;
			}
		}

		if (num == 0) {
			flag = false;
		}
	}
	return res;
}

int main()
{
	setlocale(0, "");

	cout << "Введите число которое хотите перевести: ";
	cin >> inputValue;
	cout << "Введите основание системы счисления исходного числа: ";
	cin >> inputNumBase;
	cout << "Введите основание системы счисление, в которую надо перевести число: ";
	cin >> outputNumBase;
	cout << endl;

	if (inputNumBase == outputNumBase) {
		cout << "Если вы так хотите узнать сколько будет " << inputValue << " в той же системе счисления, то вот: " << inputValue;
	}

	if (inputNumBase != 10 && outputNumBase != 10) {
		string result = convert_to_others(convert_to_ten(inputValue, inputNumBase), outputNumBase);
		cout << "Результат: " << result;
	}
	else if (outputNumBase == 10) {
		int result = convert_to_ten(inputValue, inputNumBase);
		cout << "Результат: " << result;
	}
	else if (inputNumBase == 10) {
		string result = convert_to_others(stoi(inputValue), outputNumBase);
		cout << "Результат: " << result;
	}
}