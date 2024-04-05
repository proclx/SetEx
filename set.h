#pragma once
#include <iostream>
template<typename T>
class Set
{
protected:
	template<typename T>
	struct Node
	{
		Node* next;
		T value;
		Node<T>(T val)
			: value(val), next(nullptr)
		{
		}
	};
	using List = Node<T>*;
	// List = Node*
	List head;
	unsigned size;
public:
	virtual ~Set();									// Artem & Ivan

	Set<T>& operator=(const Set<T>&);				// Ivan
	Set();											// Ivan
	Set(const Set<T>& S);							// Artem
	Set(const T* iterable, unsigned iterableSize);	// Ivan
	explicit Set(const T& value);					// Ivan

	void Add(const T& value);						// Ivan
	Set<T>& operator+=(const Set<T>& S);			// Mark
	bool Contains(const T& value) const;			// Mark
	Set<T> Difference(const Set<T>& S)const;		// Mark & Ivan
	Set<T> Intersection(const Set<T>& S)const;		// Mark
	void Remove(const T& value);					// Mark
	unsigned Size() const;							// Ivan
	bool IsEmpty() const;							// Mark
	void Print(std::ostream& os = std::cout) const; // Artem & Mark

	const T* Get(const T& value);
};

template<typename T>
inline Set<T>::Set(const Set<T>& S)
	: head(nullptr), size(0)
{
	Set<T>::Node<T>* otherCurrent = S.head;
	while (otherCurrent != nullptr)
	{
		Add(otherCurrent->value);
		otherCurrent = otherCurrent->next;
	}
}
template<typename T>
void Set<T>::Remove(const T& value) {
	Node<T>* current = head;
	Node<T>* previous = nullptr;
	if (!Contains(value))
	{
		std::cout << "No such value in the set\n";
	}
	while (current != nullptr) {
		if (current->value == value) {
			if (previous == nullptr) {
				head = current->next;
			}
			else {
				previous->next = current->next;
			}
			delete current;
			size--;
			return;
		}
		previous = current;
		current = current->next;
	}
}

template<typename T>
inline Set<T>::Set(const T& value)
{
	head = new Set<T>::Node<T>(value);
	size = 1;
}

template<typename T>
inline Set<T>::Set(const T* iterable, unsigned iterableSize)
{
	for (unsigned i = 0; i < iterableSize; ++i)
	{
		this->Add(iterable[i]);
	}
}

template<typename T>
inline bool Set<T>::IsEmpty() const
{
	return size == 0;;
}
template<typename T>
inline unsigned Set<T>::Size() const
{
	return size;
}

template<typename T>
inline Set<T>::~Set()
{
	Set<T>::Node<T>* current = head;
	while (current != nullptr)
	{
		Set<T>::Node<T>* temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
	size = 0;
}

template<typename T>
inline void Set<T>::Print(std::ostream& os) const
{
	Set<T>::Node<T>* current = head;
	if (IsEmpty())
	{
		os << "Empty set.";
	}
	while (current != nullptr)
	{
		os << current->value << " ";
		current = current->next;
	}
	os << std::endl;
}

template<typename T>
inline const T* Set<T>::Get(const T& value)
{
	T* result = nullptr;
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			result = &current->value;
			return result;
		}
		current = current->next;
	}
}

template<typename T>
inline Set<T>::Set()
	: size(0), head(nullptr)
{
}

template<typename T>
inline void Set<T>::Add(const T& value)
{
	if (head == nullptr || head->value > value)
	{
		Node<T>* nodeToInsert = new Node<T>(value);
		nodeToInsert->next = head;
		head = nodeToInsert;
		++size;
		return;
	}
	Node<T>* curr = head;
	while (curr->next != nullptr && value > curr->next->value)
	{
		curr = curr->next;
	}
	if (curr->next == nullptr && value > curr->value)
	{
		curr->next = new Node<T>(value);
		++size;
	}
	else if (curr->next != nullptr && curr->next->value > value && (curr->value > value || value > curr->value))
	{
		Node<T>* nodeToRemember = curr->next;
		curr->next = new Node<T>(value);
		curr->next->next = nodeToRemember;
		++size;
	}
}

template<typename T>
inline Set<T> Set<T>::Intersection(const Set<T>& S) const  //trouble to fix
{
	Set<T> result;
	Node <T>* current = head;
	while (current != nullptr)
	{
		if (S.Contains(current->value))
		{
			result.Add(current->value);
		}
		current = current->next;
	}
	return result;
}

template<typename T>
inline Set<T> Set<T>::Difference(const Set<T>& S) const
{
	Set<T>* result = new Set<T>;
	Node<T>* current = head;
	while (current != nullptr)
	{
		if (!S.Contains(current->value))
		{
			result->Add(current->value);
		}
		current = current->next;
	}
	return *result;
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>& S)
{
	if (this != &S)
	{
		this->~Set();
		Set<T>::Node<T>* prtToNewHead = new Set<T>::Node<T>(0);
		Set<T>::Node<T>* newHead = prtToNewHead;
		Set<T>::Node<T>* prtToOtherHead = S.head;
		while (prtToOtherHead != nullptr)
		{
			prtToNewHead->next = new Set<T>::Node<T>(prtToOtherHead->value);
			prtToNewHead = prtToNewHead->next;
			prtToOtherHead = prtToOtherHead->next;
		}
		head = newHead->next;
		delete newHead;
	}
	size = S.size;
	return *this;
}
template<typename T>
bool Set<T>::Contains(const T& value) const
{
	Node<T>* Current = head;
	while (Current != nullptr)
	{
		if (Current->value == value)
		{
			return true;
		}
		Current = Current->next;
	}
	return false;
}
template<typename T>
Set<T>& Set<T>::operator+=(const Set<T>& S)
{
	Node<T>* current = S.head;
	while (current != nullptr)
	{
		Add(current->value);
		current = current->next;
	}
	return *this;
}