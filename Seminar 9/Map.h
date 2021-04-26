#pragma once

#include "Iterator.h"

template <class Key, class T>
class Map
{
public:
	Map ();
	Map (const Map<Key, T>& other);
	~Map ();

	size_t size () const;
	size_t capacity () const;

	void set (const Key& key, const T& value);
	bool get (const Key& key, T& value);
	T& operator[] (const Key& key);

	void clear ();
	bool del (const Key& key);

	bool includes (const Map<Key, T>& other) const;

	Iterator<Key, T>& begin ();
	Iterator<Key, T>& end ();

	Map<Key, T>& operator= (const Map<Key, T>& other);
private:
	size_t find (const Key& key) const;

	size_t count, maxCount;

	Key* keys;
	T* values;
};

template<class Key, class T>
Map<Key, T>::Map ()
	: count (0), maxCount (1), keys (nullptr), values (nullptr)
{
	keys = new Key;
	values = new T;
}

template<class Key, class T>
Map<Key, T>::Map (const Map<Key, T>& other)
	: count (other.count), maxCount (other.maxCount)
{
	keys = new Key[maxCount];
	values = new T[maxCount];

	for (int i = 0; i < maxCount; i++)
	{
		keys[i] = other.keys[i];
		values[i] = other.values[i];
	}
}

template<class Key, class T>
Map<Key, T>::~Map ()
{
	if (keys != nullptr)
		delete[] keys, values;
}

template<class Key, class T>
void Map<Key, T>::set (const Key& key, const T& value)
{
	size_t pos = find (key);
	if (pos != -1)
	{
		values[pos] = value;
		return;
	}

	if (count == maxCount)
	{
		Map<Key, T> temp = *this;

		maxCount *= 2;
		keys = new Key[maxCount];
		values = new T[maxCount];

		for (int i = 0; i < count; i++)
		{
			keys[i] = temp.keys[i];
			values[i] = temp.values[i];
		}
		keys[count] = key;
		values[count++] = value;
	}
	else
	{
		keys[count] = key;
		values[count++] = value;
	}
}

template<class Key, class T>
bool Map<Key, T>::get (const Key& key, T& value)
{
	size_t pos = find (key);
	if (pos == -1)
		return false;

	value = values[pos];
	return true;
}

template<class Key, class T>
T& Map<Key, T>::operator[] (const Key& key)
{
	set (key, T ());
	return *(values + find (key));
}

template<class Key, class T>
size_t Map<Key, T>::size () const
{
	return maxCount;
}

template<class Key, class T>
size_t Map<Key, T>::capacity () const
{
	return maxCount;
}

template<class Key, class T>
void Map<Key, T>::clear ()
{
	count = 0;
	maxCount = 1;
	delete[] keys;
	delete[] values;
	keys = nullptr;
	values = nullptr;
}

template<class Key, class T>
bool Map<Key, T>::del (const Key& key)
{
	size_t pos = find (key);
	if (pos == -1)
		return false;
	for (int i = pos; i < count; i++)
	{
		keys[i] = keys[i + 1];
		values[i] = values[i + 1];
	}
	count--;
	return true;
}

template<class Key, class T>
bool Map<Key, T>::includes (const Map<Key, T>& other) const
{
	if (other.count > count)
		return false;
	for (int i = 0; i < count; i++)
	{
		size_t pos = other.find (keys[i]);
		if (pos == -1)
			return false;
		if (values[pos] != other.values[pos])
			return false;
	}
	return true;
}

template<class Key, class T>
Iterator<Key, T>& Map<Key, T>::begin ()
{
	Iterator<Key, T> temp;

	temp.keyPtr = keys;
	temp.valPtr = values;
	temp.index = 0;

	return temp;
}

template<class Key, class T>
Iterator<Key, T>& Map<Key, T>::end ()
{
	Iterator<Key, T> temp;

	temp.keyPtr = keys + count;
	temp.valPtr = values + count;
	temp.index = count;

	return temp;
}

template<class Key, class T>
Map<Key, T>& Map<Key, T>::operator= (const Map<Key, T>& other)
{
	if (this != &other)
	{
		count = other.count;
		maxCount = other.maxCount;
		delete[] keys;
		delete[] values;
		keys = new Key[maxCount];
		values = new T[maxCount];

		for (int i = 0; i < maxCount; i++)
		{
			keys[i] = other.keys[i];
			values[i] = other.values[i];
		}
	}
	return *this;
}

template<class Key, class T>
size_t Map<Key, T>::find (const Key& key) const
{
	if (count == 0)
		return -1;
	for (int i = 0; i < maxCount; i++)
		if (keys[i] == key)
			return i;

	return -1;
}
