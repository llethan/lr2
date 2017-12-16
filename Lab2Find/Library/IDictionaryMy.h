#pragma once
//интерфейс из задания
template <class TKey, class TValue>
class IDictionaryMy
{
public:
	virtual int GetCount() = 0;
	//int GetCapacit - unused (hash table with lists)
	virtual TValue Get(TKey key) = 0;
	virtual bool GetFirst(TKey key) = 0;
	virtual void Add(TKey key, TValue element) = 0;
	virtual void Remove(TKey key) = 0;
};

