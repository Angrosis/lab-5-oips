#include <iostream>

#include <fstream>

using namespace std;

int input(double& x1, double& x2, double& step, double& n, bool& record) { // Функция для ввода данных
	cout << "input start: " << endl;
	cin >> x1;
	cout << "input end:" << endl;
	cin >> x2;
	if (x2 < x1) {
		cout << "end mast be higer than start";
		return 1;
	}
	cout << "input step:" << endl;
	cin >> step;
	if (step > (x2 - x1)) {
		cout << "step to high";
		return 1;
	}
	else if (((x2 - x1) / step) - (int)((x2 - x1) / step) != 0) {
		cout << "step not multiple" << endl;
		return 1;
	}
	cout << "input n: ";
	cin >> n;

	cout << "record results to file? (1 - yes, 0 - no) ";
	cin >> record;
}

void checkValidParams(double n) { // Проверка n на int
	if (n != int(n)) {
		throw "n must be integer";
	}
}

double add(double x, double n) { // Функция при х < 0
	double y = 0;
	for (int j = 1; j <= n; j++)
	{
		double s = 0;
		for (int i = 1; i <= n; i++)
		{
			s += 1 / (x - i - j);
		}
		y += s;
	}

	return y;
}

double mult(double x, double n) { // Функция при x => 0
	double y1 = 1;
	for (int i = 0; i <= (n - 3); i++) {
		y1 *= (-x - i);
	}
	return y1;
}

double calculate(double x, double n) {
	double y = 0;
	if (x < 0) {
		y = add(x, n);
	}
	else {
		y = mult(x, n);
	}
	return y;
}

int main()
{
	double x1, x2, step, n, s = 0;
	ofstream results;
	bool record;
	try {
		input(x1, x2, step, n, record);
		checkValidParams(n);
		if (record) results.open("results.txt");
		for (double x = x1; x <= x2; x += step)
		{
			cout << "x = " << x << " y = ";
			printf("%.3g\n", calculate(x, n));
			if (record) results << "x = " << x << "; y = " << calculate(n,
				x) << endl; // добавление результата в файл
		}

	}
	catch (const char* ex)
	{
		cout << ex << endl;
		return -1;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
		return -2;
	}
}