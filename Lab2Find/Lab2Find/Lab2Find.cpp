// Lab2Find.cpp: определяет точку входа для консольного приложения.
//

#include "Program.h"
#include <iostream>
#include <exception>
#include <clocale>

using namespace std;

int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");
		Program p;
		return p.run();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << " Завершение программы." << endl;
	}
	catch (...)
	{
		cout << "Неизвестная ошибка. Завершение программы." << endl;
	}

    return 0;
}

