#pragma once

#include <sstream>
#include "BaseSequence.h"

namespace lib
{
	//узел дерева
	template <class TKey, class TValue>
	struct Node
	{
		TKey key;     //ключ
		TValue value; //значение
		Node* parent; //указатель на родителя
		Node* left;   //указатель на левое поддерово
		Node* right;  //указатель на правое поддерево
		Node(TKey key, TValue value) : Node(key, value, nullptr) {};
		Node(TKey key, TValue value, Node* parent) : Node(key, value, parent, nullptr, nullptr) {}
		Node(TKey key, TValue value, Node* parent, Node* left, Node* right) :
			key(key), value(value), parent(parent), left(left), right(right) {}
		//вывод
		friend std::ostream& operator << (std::ostream& o, const Node& T)
		{
			o << T.key << " " << T.value;
			return o;
		}
	};
	
	//BST - binary search tree, бинарное дерево поиска
	template <class TKey, class TValue>
	class BST : public BaseSequence<TKey, TValue>
	{
	private:
		Node<TKey, TValue>* root;
		//очистить дерево
		void clear(Node<TKey, TValue>* node);
		//копия
		void copy(Node<TKey, TValue>* node);
		void copy(Node<TKey, TValue>* parent, Node<TKey, TValue>* node);
		//вывод узла
		std::string printNode(const Node<TKey, TValue>& node, std::string offset) const;
	public:
		BST();
		BST(const BST& T);
		BST(BST&& T);
		virtual ~BST();
		BST& operator= (const BST& T);
		BST& operator= (BST&& T);
		//добавить значение
		virtual void add(TKey key, TValue value) override;
		//преобразование в строку
		virtual std::string toString() const override;
		//поиск пары
		virtual Pair<TKey, TValue> find(TKey key, int& clk) override;

	};
	//конструкторы
	template <class TKey, class TValue>
	BST<TKey, TValue>::BST() : root(nullptr) {}
	
	template <class TKey, class TValue>
	BST<TKey, TValue>::BST(const BST& T)
	{
		if (*this == T)
			return;
		clear(root);
		root = nullptr;
		copy(T.root);
	}

	template <class TKey, class TValue>
	BST<TKey, TValue>::BST(BST&& T)
	{
		if (*this == T)
			return;
		root = T.root;
		T.root = nullptr;
	}
	//очистка 
	template <class TKey, class TValue>
	void BST<TKey, TValue>::clear(Node<TKey, TValue>* node)
	{
		if (node == nullptr)
			return;
		clear(node->left);
		clear(node->right);
		delete node;
	}
	//деструктор
	template <class TKey, class TValue>
	BST<TKey, TValue>::~BST()
	{
		clear(root);
	}

	template <class TKey, class TValue>
	BST<TKey, TValue>& BST<TKey, TValue>::operator= (const BST<TKey, TValue>& T)
	{
		if (*this == T)
			return;
		clear(root);
		root = nullptr;
		copy(T.root);
		return *this;
	}
	
	template <class TKey, class TValue>
	BST<TKey, TValue>& BST<TKey, TValue>::operator= (BST<TKey, TValue>&& T)
	{
		if (*this == T)
			return *this;
		root = T.root;
		T.root = nullptr;
		return *this;
	}

	//копия дерева
	template <class TKey, class TValue>
	void BST<TKey, TValue>::copy(Node<TKey, TValue>* node)
	{
		if (node == nullptr)
			return;
		root = new Node<TKey, TValue>(node->key, node->value);
		copy(root, node->left);
		copy(root, node->right);
	}

	template <class TKey, class TValue>
	void BST<TKey, TValue>::copy(Node<TKey, TValue>* parent, Node<TKey, TValue>* node)
	{
		if (parent == nullptr || node == nullptr)
			return;
		if (node->parent->right == node)
		{
			parent->right = new Node<TKey, TValue>(node->key, node->value, parent);
			copy(parent->right, node->left);
			copy(parent->right, node->right);
		}
		else
		{
			parent->left = new Node<TKey, TValue>(node->key, node->value, parent);
			copy(parent->left, node->left);
			copy(parent->left, node->right);
		}
	}


	//добавить занчение
	template <class TKey, class TValue>
	void BST<TKey, TValue>::add(TKey key, TValue value)
	{
		if (root == nullptr)
		{
			root = new Node<TKey, TValue>(key, value);
		}
		else
		{
			auto parent = root;
			while (true)
				if (parent->key > key)
					if (parent->left != nullptr)
						parent = parent->left;
					else
						break;
				else
					if (parent->right != nullptr)
						parent = parent->right;
					else
						break;
			if (parent->key > key)
				parent->left = new Node<TKey, TValue>(key, value, parent);
			else
				parent->right = new Node<TKey, TValue>(key, value, parent);

		}
	}
	//преобраховать в строку
	template <class TKey, class TValue>
	std::string BST<TKey, TValue>::toString() const
	{
		std::ostringstream o;
		if (root != nullptr)
			o << printNode(*root, "");
		else
			o << "BST не содержит элементов." << endl;
		return o.str();
	}
	//вывести узел
	template <class TKey, class TValue>
	std::string BST<TKey, TValue>::printNode(const Node<TKey, TValue>& node, std::string offset) const
	{
		std::ostringstream o;
		if (node.left != nullptr)
			o << printNode(*node.left, offset + " ");
		o << offset << node << endl;
		if (node.right != nullptr)
			o << printNode(*node.right, offset + " ");
		return o.str();
	}
	//поиск значения
	template <class TKey, class TValue>
	Pair<TKey, TValue> BST<TKey, TValue>::find(TKey key, int& clk)
	{
		if (root == nullptr)
			return Pair<TKey, TValue>::undef();
		auto node = root;
		while (node != nullptr)
		{
			if (node->key == key)
				return Pair<TKey, TValue>(key, node->value);
			else if (node->key > key)
				node = node->left;
			else
				node = node->right;
			++clk;
		}
		return Pair<TKey, TValue>::undef();
	}
}