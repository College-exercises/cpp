#pragma once

#include <algorithm>

#include "Compare.h"
#include "Exceptions.h"
#include "Iterator.h"

template<class T>
class Array
{
public:
	Array ();						// Lista nu e alocata, Capacity si Size = 0
	Array (size_t count);			// Lista e alocata cu 'capacity' elemente
	Array (const Array<T>& other);	// constructor de copiere
	~Array ();						// destructor

	T& operator[] (size_t index);									// arunca exceptie daca index este out of range
	const T& operator[] (size_t index) const;
	const Array<T>& operator+= (T& element);						// adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& insert (size_t index, T& element);				// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& insert (size_t index, Array<T>& other);			// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
																	// !!! zona de memorie nu mai este contigua, iteratorul nu mai parcurge tot
	const Array<T>& del (size_t index);								// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
																	// !!! zona de memorie nu mai este contigua, iteratorul nu mai parcurge tot + nu se sterge corect

	bool operator== (const Array<T>& other);

	void sort ();									// sorteaza folosind comparatia intre elementele din T
	void sort (int(*compare)(const T&, const T&));	// sorteaza folosind o functie de comparatie
	void sort (Compare* comparator);				// sorteaza folosind un obiect de comparatie

	size_t binarySearch (const T& element) const;										// cauta un element folosind binary search in Array
	size_t binarySearch (const T& element, int(*compare)(const T&, const T&)) const;	// cauta un element folosind binary search si o functie de comparatie
	size_t binarySearch (const T& element, Compare* comparator) const;					// cauta un element folosind binary search si un comparator

	size_t find (const T& element) const;										// cauta un element in Array
	size_t find (const T& element, int(*compare)(const T&, const T&)) const;	// cauta un element folosind o functie de comparatie
	size_t find (const T& element, Compare* comparator) const;					// cauta un element folosind un comparator

	size_t size () const;
	size_t capacity () const;

	ArrayIterator<T> begin ();
	ArrayIterator<T> end ();
	const ArrayIterator<T> begin () const;
	const ArrayIterator<T> end () const;
private:
	T** list;
	size_t count, maxCount;
	bool sorted;
	bool checkSorted ();
};


template<class T>
inline bool Array<T>::checkSorted ()
{
	for (int i = 0; i < count - 1; i++)
		if (list[i] > list[i + 1])
			return false;
	return true;
}

template <class T>
inline Array<T>::Array ()
	: list (nullptr), count (0), maxCount (1), sorted (true)
{
	list = new T*;
}

template <class T>
inline Array<T>::Array (size_t count)
	: list (nullptr), count (0), maxCount (count), sorted (true)
{
	list = new T * [maxCount];
}

template <class T>
inline Array<T>::Array (const Array<T>& other)
	: count (other.count), maxCount (other.maxCount), sorted (other.sorted)
{
	delete[] list;
	list = new T * [maxCount];

	for (int i = 0; i < maxCount; i++)
		list[i] = other.list[i];
}

template <class T>
inline Array<T>::~Array ()
{
	delete[] list;
}

template <class T>
inline T& Array<T>::operator[] (size_t index)
{
	if (index >= count)
		throw std::out_of_range ("Index out of range");
	return *list[index];
}

template<class T>
inline const T& Array<T>::operator[] (size_t index) const
{
	if (index >= count)
		throw std::out_of_range ("Index out of range");
	return *list[index];
}

template <class T>
inline const Array<T>& Array<T>::operator+= (T& newElem)
{
	if (count == maxCount)
	{
		Array<T> temp = *this;
		maxCount *= 2;

		delete[] list;
		list = new T * [maxCount];
		for (int i = 0; i < count; i++)
			list[i] = temp.list[i];
	}

	if (sorted && count > 1 && *list[count - 1] > newElem)
		sorted = false;
	list[count++] = &newElem;
	return *this;
}

template <class T>
inline const Array<T>& Array<T>::insert (size_t index, T& element)
{
	if (index >= count)
		throw std::out_of_range ("Index out of range");

	if (count == maxCount)
	{
		Array<T> temp = *this;
		maxCount *= 2;

		delete[] list;
		list = new T * [maxCount];
		for (int i = 0; i < index; i++)
			list[i] = temp.list[i];
		list[index] = &element;
		for (int i = index; i < count; i++)
			list[i + 1] = temp.list[i];
	}
	else
	{
		for (int i = count; i > index; i--)
			list[i] = list[i - 1];
		list[index] = &element;
	}

	sorted = checkSorted ();
	count++;
	return *this;
}

template <class T>
inline const Array<T>& Array<T>::insert (size_t index, Array<T>& other)
{
	if (index >= count)
		throw std::out_of_range ("Index out of range");

	if (count + other.count >= std::max (maxCount, other.maxCount))
	{
		Array<T> temp = *this;
		maxCount = std::max (maxCount, other.maxCount) * 2;

		delete[] list;
		list = new T * [maxCount];
		for (int i = 0; i < index; i++)
			list[i] = temp.list[i];
		for (int i = 0; i < other.count; i++)
			list[i + index] = other.list[i];
		for (int i = 0; i < other.count; i++)
			list[i + index + other.count] = temp.list[i + index];
	}
	else
	{
		for (int i = count + other.count; i > index; i--)
			list[i] = list[i - index];
		for (int i = index; i < index + other.count; i++)
			list[i] = other.list[i - index];
	}

	sorted = checkSorted ();
	count += other.count;
	for (int i = 0; i < size (); i++)
		std::cout << *list[i] << " ";
	std::cout << '\n';
	return *this;
}

template <class T>
inline const Array<T>& Array<T>::del (size_t index)
{
	if (index >= count)
		throw std::out_of_range ("Index out of range");

	count--;
	for (int i = index; i < count; i++)
		list[i] = list[i + 1];

	sorted = checkSorted ();
	return *this;
}

template <class T>
inline bool Array<T>::operator== (const Array<T>& other)
{
	if (count != other.count)
		return false;
	for (int i = 0; i < count; i++)
		if (list[i] != other.list[i])
			return false;
	return true;
}

template <class T>
inline void Array<T>::sort ()
{
	std::sort (*list, *list + count);
	sorted = true;
}

template <class T>
inline void Array<T>::sort (int(*compare)(const T&, const T&))
{
	std::sort (*list, *list + count, compare);
	sorted = true;
}

template<class T>
inline void Array<T>::sort (Compare* comparator)
{
	//std::sort (list, list + count, comparator->compareElements()); // ?
	sorted = true;
}

template <class T>
inline size_t Array<T>::binarySearch (const T& elem) const
{
	return binarySearch (elem, [](const T& left, const T& right)->int { if (left < right) return -1; return left > right; });
}

template <class T>
inline size_t Array<T>::binarySearch (const T& elem, int(*compare)(const T&, const T&)) const
{
	if (!sorted)
		throw NotSorted ();

	int left = 0, right = count;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (compare (*list[mid], elem) == 0)
			return mid;
		if (compare (*list[mid], elem) < 0)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

template <class T>
inline size_t Array<T>::binarySearch (const T& elem, Compare* comparator) const
{
	return binarySearch (elem, comparator); // ?
}

template <class T>
inline size_t Array<T>::find (const T& elem) const
{
	return find (elem, [](const T& left, const T& right)->int { if (left < right) return -1; return left > right; });
}

template <class T>
inline size_t Array<T>::find (const T& elem, int(*compare)(const T&, const T&)) const
{
	for (int i = 0; i < count; i++)
		if (compare (*list[i], elem) == 0)
			return i;
	return -1;
}

template <class T>
inline size_t Array<T>::find (const T& elem, Compare* comparator) const
{
	return find (elem, *comparator); // ?
}

template <class T>
inline size_t Array<T>::size () const
{
	return count;
}

template <class T>
inline size_t Array<T>::capacity () const
{
	return maxCount;
}

template <class T>
inline ArrayIterator<T> Array<T>::begin ()
{
	ArrayIterator<T> temp;
	temp.ptr = *list;
	return temp;
}

template<class T>
inline const ArrayIterator<T> Array<T>::begin () const
{
	ArrayIterator<T> temp;
	temp.ptr = *list;
	return temp;
}

template <class T>
inline ArrayIterator<T> Array<T>::end ()
{
	ArrayIterator<T> temp;
	temp.ptr = *list + count;
	return temp;
}

template<class T>
inline const ArrayIterator<T> Array<T>::end () const
{
	ArrayIterator<T> temp;
	temp.ptr = *list + count;
	return temp;
}
