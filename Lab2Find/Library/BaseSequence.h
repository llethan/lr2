#pragma once

#include <iostream>
#include <string>

namespace lib
{
	template <class TKey, class TValue>
	struct Pair //структура: пара ключ - значение
	{
		TKey key;       //ключ
		TValue value;   //значение
		bool undefined; //неопределённое значение
		void clear() { TKey k = TKey(); TValue v = TValue(); key = k; value = v; } // очистить пару
		bool operator< (const Pair<TKey, TValue>& P) const
		{
			return key < P.key;
		} //сравнение

		friend std::ostream& operator << (std::ostream& o, const Pair& P)
		{
			o << P.key << " " << P.value;
			return o; //вывод
		}
		static Pair<TKey, TValue> undef()
		{
			Pair<TKey, TValue> p;
			p.undefined = true;
			return p;
		} //сделать неопредлённым
		Pair() : undefined(false) {}
		Pair(TKey key, TValue value) : key(key), value(value), undefined(false) {}
	};

	//базовый класс последовательности
	template <class TKey, class TValue>
	class BaseSequence
	{
	public:
		BaseSequence() = default;
		virtual ~BaseSequence() = default;

		//добавить значение
		virtual void add(TKey key, TValue value) = 0;
		//пребразовать в строку
		virtual std::string toString() const = 0;
		//вывести
		friend std::ostream& operator<< (std::ostream& o, const BaseSequence<TKey, TValue>& T)
		{
			o << T.toString() << endl;
			return o;
		}
		//найти
		virtual Pair<TKey, TValue> find(TKey key, int& clk) = 0;
	};
}