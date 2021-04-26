#pragma once

#include <tuple>

template <class Key, class T>
class Iterator
{
public:

	Iterator& operator++ ();
	bool operator!= (const Iterator<Key, T>& other);
	std::tuple<Key, T, size_t> operator* ();	

	Key* keyPtr;
	T* valPtr;
	size_t index;
};

template <class Key, class T>
Iterator<Key, T>& Iterator<Key, T>::operator++ ()
{
	keyPtr++;
	valPtr++;
	index++;

	return *this;
}

template<class Key, class T>
bool Iterator<Key, T>::operator!= (const Iterator<Key, T>& other)
{
	return valPtr != other.valPtr || keyPtr != other.keyPtr || index != other.index;
}

template<class Key, class T>
std::tuple<Key, T, size_t> Iterator<Key, T>::operator* ()
{
	return std::tuple<Key, T, size_t> (*keyPtr, *valPtr, index);
}
