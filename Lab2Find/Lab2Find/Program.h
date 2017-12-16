#pragma once
#include "..\Library\BaseSequence.h"

#include <iostream>
#include <array>
class Program
{
	enum Actions { exit = 1, show, add, find, random};

private:
	static const int maxCount = 2;
	std::array<lib::BaseSequence<int, std::string>*, maxCount> seq;

	void printMenu();
	int result[4][maxCount];
public:
	Program();
	
	int run();
	static int getInt();
	//функции, для работы с гуи
	std::string toString(int) const;
	void addPair(int key, std::string value);
	std::string findValue(int key);
	void generate(int count);
	void test();
	int getTest(int ts, int tr);
	static int totalCount() { return  maxCount; }
};

