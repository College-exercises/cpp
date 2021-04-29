#pragma once

template<class T>
class ArrayIterator
{
public:
	ArrayIterator ();

	ArrayIterator& operator++ ();
	ArrayIterator& operator-- ();

	bool operator== (const ArrayIterator<T>& other);
	bool operator!= (const ArrayIterator<T>& other);

	T& operator* ();

	T* ptr;
};

template<class T>
inline ArrayIterator<T>::ArrayIterator ()
	: ptr (nullptr)
{
}

template<class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator++ ()
{
	ptr++;
	return *this;
}

template<class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator-- ()
{
	ptr--;
	return *this;
}

template <class T>
inline bool ArrayIterator<T>::operator== (const ArrayIterator<T>& other)
{
	return ptr == other.ptr;
}

template <class T>
inline bool ArrayIterator<T>::operator!= (const ArrayIterator<T>& other)
{
	return ptr != other.ptr;
}

template<class T>
inline T& ArrayIterator<T>::operator* ()
{
	return *ptr;
}
