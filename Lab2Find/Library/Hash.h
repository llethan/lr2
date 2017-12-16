#pragma once

#include "BaseSequence.h"
#include "IDictionaryMy.h"
#include <algorithm>
#include <sstream>
#include <array>

namespace lib
{
	//узед хеш-таблицы
	template <class TKey, class TValue>
	struct HashNode
	{
		TKey key;     //ключ
		TValue value; //значение
		HashNode* next;//следующий элемент в списке коллизий
		HashNode() {}
		HashNode(TKey key, TValue value) : key(key), value(value), next(nullptr) {}

		friend std::ostream& operator << (std::ostream& o, const HashNode& T)
		{
			o << T.key << " " << T.value;
			return o;
		}
	};
	//Hash - Hash-table - Хэш-таблица
	//тип ключа, тип значения, размер основной части таблицы
	//используется хеш-таблица со списками для разрешения коллизий
	template <class TKey, class TValue, int TSize>
	class Hash : public BaseSequence<TKey, TValue>, public IDictionaryMy<TKey, TValue>
	{
	private:
		HashNode<TKey, TValue> nodes[TSize];
		void clear();
	public:
		Hash();
		virtual ~Hash() { clear(); }
		Hash(const Hash&) = delete;
		Hash(Hash&&) = delete;
		Hash& operator= (const Hash&) = delete;
		Hash& operator= (Hash&& T) = delete;
		//добавить
		virtual void add(TKey key, TValue value) override;
		//удалить
		virtual void remove(TKey key);
		//вывести в строку
		virtual std::string toString() const override;
		//вывести список
		std::string Hash<TKey, TValue, TSize>::printList(const HashNode<TKey, TValue>* node) const;
		//удалить список
		void deleteList(HashNode<TKey, TValue>* node);
		//поиск 
		virtual Pair<TKey, TValue> find(TKey key, int& clk) override;
		//вставить в список
		void insertToList(HashNode<TKey, TValue>* node, TKey key, TValue value);
		//IDictionary
		virtual int GetCount();
		//int GetCapacit - unused (hash table with lists)
		//получить значение
		virtual TValue Get(TKey key);
		//получить рпервый элемент
		virtual bool GetFirst(TKey key);
		//добавить
		virtual void Add(TKey key, TValue element);
		//удалить
		virtual void Remove(TKey key);
	};
	//конструктор
	template <class TKey, class TValue, int TSize>
	Hash<TKey, TValue, TSize>::Hash()
	{ 
		static_assert(TSize > 2, "Размер должен быть больше 2");
		memset(nodes, 0, TSize * sizeof(HashNode<TKey, TValue>));
	}
	//очистка таблицы
	template <class TKey, class TValue, int TSize>
	void Hash<TKey, TValue, TSize>::clear()
	{
		for (int i = 0; i < TSize; ++i)
			deleteList(nodes[i].next);
		memset(nodes, 0, TSize * sizeof(HashNode<TKey, TValue>));
	}
	//удалить список
	template <class TKey, class TValue, int TSize>
	void Hash<TKey, TValue, TSize>::deleteList(HashNode<TKey, TValue>* node)
	{
		if (node == nullptr)
			return;
		deleteList(node->next);
		delete node;
	}
	//добавить ключ
	template <class TKey, class TValue, int TSize>
	void Hash<TKey, TValue, TSize>::add(TKey key, TValue value)
	{
		insertToList(&nodes[key % TSize], key, value);
	}
	//вставить в список
	template <class TKey, class TValue, int TSize>
	void Hash<TKey, TValue, TSize>::insertToList(HashNode<TKey, TValue>* node, TKey key, TValue value)
	{
		while (node->next != nullptr)
		{
			node = node->next;
		}
		node->next = new HashNode<TKey, TValue>(key, value);
	}
	//удалить из списка
	template <class TKey, class TValue, int TSize>
	void Hash<TKey, TValue, TSize>::remove(TKey key)
	{
		auto node = &nodes[key % TSize];
		while (node && node->next)
		{
			if (node->next->key == key)
			{
				auto temp = node->next;
				node->next = temp->next;
				delete temp;
			}
		}
	}
	//вывести в строку
	template <class TKey, class TValue, int TSize>
	std::string Hash<TKey, TValue, TSize>::toString() const
	{
		std::ostringstream o;
		for (int i = 0; i < TSize; ++i)
			o << i << ": " << endl << printList(&nodes[i]);
		return o.str();
	}
	//Вывести список
	template <class TKey, class TValue, int TSize>
	std::string Hash<TKey, TValue, TSize>::printList(const HashNode<TKey, TValue>* node) const
	{
		std::ostringstream o;
		while (node->next != nullptr)
		{
			o << "  " << *(node->next) << endl;
			node = node->next;
		}
		return o.str();
	}
	//поиск в спсике
	template <class TKey, class TValue, int TSize>
	Pair<TKey, TValue> Hash<TKey, TValue, TSize>::find(TKey key, int& clk)
	{
		auto node = &nodes[key % TSize];
		while (node->next != nullptr)
		{
			++clk;
			if (node->next->key == key)
				return Pair<TKey, TValue>(node->next->key, node->next->value);
			node = node->next;
		}
		return Pair<TKey, TValue>::undef();
	}
	//получить число элементов в таблице
	template <class TKey, class TValue, int TSize>
	int Hash<TKey, TValue, TSize>::GetCount()
	{
		int count = 0;
		for (int i = 0; i < TSize; ++i)
		{
			auto node = &nodes[i];
			while (node->next)
			{
				++count;node = node->next;
			}
		}
		return count;
	}
	//получить элемент по ключу
	template <class TKey, class TValue, int TSize>
	TValue Hash<TKey, TValue, TSize>::Get(TKey key)
	{
		int i;
		if (find(key, i).undefined)
			throw std::runtime_error("no key");
	}

	template <class TKey, class TValue, int TSize>
	bool Hash<TKey, TValue, TSize>::GetFirst(TKey key)
	{
		int i;
		return find(key, i).undefined;
	}
	//добавить знаечние
	template <class TKey, class TValue, int TSize>
	void  Hash<TKey, TValue, TSize>::Add(TKey key, TValue element)
	{
		add(key, element);
	}
	//удалить
	template <class TKey, class TValue, int TSize>
	void Hash<TKey, TValue, TSize>::Remove(TKey key)
	{
		remove(key);
	}

}