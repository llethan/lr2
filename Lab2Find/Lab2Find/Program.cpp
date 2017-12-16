#include "Program.h"
#include "..\Library\BST.h"
#include "..\Library\Hash.h"
#include <ctime>

using namespace lib;
using namespace std;

Program::Program()
{
	try
	{
		seq = { new BST<int, string>(), new Hash<int, string, 100>() };
		memset(result, 0, sizeof(result));
		cout << "Объекты созданы." << endl;
	}
	catch (const bad_alloc&)
	{
		cout << "Памяти не хватило. Хранилища не могут быть созданы." << endl;
		throw;
	}
}

int Program::run()
{
	while (true)
	{
		printMenu();
		cout << "Выберите действие: ";
		int choice = getInt();
		switch (choice)
		{
		case exit:
			return 0;
		case show:
			for (auto s : seq)
				cout << *s << endl;
			break;
		case add:
		{
			
			int key = 0;
			cout << "Введите ключ: ";
			key = getInt();
			cout << "Введите значение: ";
			string value;
			cin >> value;
			addPair(key, value);
			break;
		}
		case find:
		{
			int key = 0;
			cout << "Введите ключ: ";
			key = getInt();
			for (auto s : seq)
			{
				int l = 0;
				auto p = s->find(key, l);
				if (p.undefined)
					cout << "Ключ не найден" << endl;
				else
					cout << p << endl;
			}
			break;
		}
		case random:
		{
			cout << "Введите количество" << endl;
			int count = getInt();
			for (int i = 0; i <  maxCount; ++i)
			{
				int number = 1000 * rand() % 1000 + rand() % 1000;
				for (auto s : seq)
					s->add(number, "rand");
			}
		}
		default:
			cout << "Некорректный пункт." << endl;
		}
	}
}

void Program::printMenu()
{
	cout << "1 Выход, 2 Вывод деревьев, 3 Добавить элемент (в каждое дерево), " << endl 
		<< "4 Найти элемент, 5 Сгенерировать элементы." << endl;
}

int Program::getInt()
{
	int num;
	cin >> num;
	while (cin.fail())
	{
		cin.clear();
		cout << "Повторите ввод целочисленного значения: ";
		cin >> num;
	}
	return num;
}

void Program::addPair(int key, std::string value)
{
	for (auto s : seq)
		s->add(key, value);
}

std::string Program::toString(int i) const
{
	return string(seq[i]->toString().c_str());
}

std::string Program::findValue(int key)
{
	int l;
	auto res = seq[0]->find(key, l);
	return res.undefined ? "Ключ не найден" : res.value.c_str();
}

void Program::generate(int count)
{
	for (int i = 0; i < count; ++i)
	{
		int num = rand() % 10000;
		for (auto tree : seq)
			tree->add(num, "random");
	}
}

void Program::test()
{
	int size = 1;
	int count = 0;
	array<BaseSequence<int, string>*, 2> seq = { new BST<int, string>(), new Hash<int, string, 1000>() };
	for (int i = 0; i < 4; ++i)
	{
		size *= 20;
		for (; count < size; ++count)
		{
			int num = rand() % size;
			for (auto s : seq)
				s->add(num, "");
		}
		for (int k = 0; k < maxCount; ++k)
		{
			auto t = 0;
			for (int j = 0; j < 10000; ++j)
			{
				int clk = 0;
				seq[k]->find(rand() % size, clk);
				t += clk;
			}
			result[i][k] = t;
		}
	}
}

int Program::getTest(int ts, int tr)
{
	return result[ts][tr];
}