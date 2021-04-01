#pragma once

#include <algorithm>

template <class T>
class Vector
{
private:
	unsigned int index, size;
	T* array;
public:
	Vector ();
	Vector (unsigned int size);
	Vector (std::initializer_list<T>);
	Vector (const Vector& other);
	Vector (Vector&& other) noexcept;

	~Vector ();

	void push (T element);
	T& pop ();
	void remove (unsigned int index);
	void clear ();
	void insert (unsigned int index, T element);
	void sort (bool (*function)(T left, T right) = nullptr);
	void suitch (Vector& other);

	T& get (unsigned int index);
	const T& get (unsigned int index) const;
	void set (unsigned int index, T element);
	int firstIndexOf (T element, bool (*function)(T element) = nullptr);

	unsigned int count ();
	unsigned int capacity ();

	Vector& operator= (const Vector& other);
	template <typename Y>
	friend std::ostream& operator<< (std::ostream& stream, const Vector<Y>& vector);
};

using VectorIn = Vector<int>;
using VectorFl = Vector<float>;
using VectorUIn = Vector<unsigned int>;

template <class T>
Vector<T>::Vector ()
	: index (0), size (1)
{
	array = new T;
}

template<class T>
Vector<T>::Vector (unsigned int size)
	: index (0), size (size)
{
	array = new T[size];
}

template<class T>
Vector<T>::Vector (std::initializer_list<T> list)
	: index (0), size ((unsigned int)list.size ())
{
	array = new T[size];

	for (auto i : list)
		array[index++] = i;
}

template<class T>
Vector<T>::Vector (const Vector& other)
	: index (other.index), size (other.size)
{
	array = new T[size];

	for (int i = 0; i < size; i++)
		array[i] = other.array[i];
}

template<class T>
Vector<T>::Vector (Vector&& other) noexcept
	: index (other.index), size (other.size)
{
	array = other.array;
	other.array = nullptr;
}

template<class T>
Vector<T>::~Vector ()
{
	delete[] array;
}

template<class T>
void Vector<T>::push (T element)
{
	if (index == size)
	{
		Vector<T> copy (*this);
		size *= 2;
		array = new T[size];

		for (int i = 0; i < index; i++)
			array[i] = copy.array[i];
	}

	array[index++] = element;
}

template<class T>
T& Vector<T>::pop ()
{
	return array[--index];
}

template<class T>
void Vector<T>::remove (unsigned int index)
{
	if (index >= this->index)
	{
		printf ("%d is out of bounds!\n", index);
		return;
	}

	for (int i = index; i < size - 1; i++)
		array[i] = array[i + 1];

	this->index--;
}

template<class T>
void Vector<T>::clear ()
{
	size = 1;
	index = 0;
}

template<class T>
void Vector<T>::insert (unsigned int index, T element)
{
	if (index >= this->index)
	{
		printf ("Out of bounds!\n");
		return;
	}

	if (index + 1 == size)
	{
		Vector<T> copy (*this);

		size *= 2;
		array = new T[size];
		for (int i = 0; i < index; i++)
			array[i] = copy.array[i];
		array[index] = element;

		for (int i = index + 1; i < this->index; i++)
			array[i] = copy.array[i - 1];
	}
	else
	{
		for (int i = this->index; i > index; i--)
			array[i] = array[i - 1];
		array[index] = element;
	}
	this->index++;
}

template<class T>
void Vector<T>::sort (bool (*function)(T left, T right))
{
	if (function == nullptr)
		std::sort (array, array + index);
	else
		std::sort (array, array + index, function);

}

template<class T>
void Vector<T>::suitch ( Vector& other)
{
	Vector temp (other);							  // aux = a
	other = *this;									  // a = b
	*this = temp;									  // b = aux
}

template<class T>
T& Vector<T>::get (unsigned int index)
{
	if (index >= this->index)
	{
		printf ("Out of bounds!\n");
		return array[0];
	}
	return array[index];
}

template<class T>
const T& Vector<T>::get (unsigned int index) const
{
	if (index >= this->index)
	{
		printf ("Out of bounds!\n");
		return array[0];
	}

	return array[index];
}

template<class T>
void Vector<T>::set (unsigned int index, T element)
{
	if (index >= this->index)
	{
		printf ("Out of bounds!\n");
		return;
	}

	array[index] = element;
}

template<class T>
int Vector<T>::firstIndexOf (T element, bool (*function)(T element))
{
	if (function == nullptr)
		for (int i = 0; i < index; i++)
			if (array[i] == element)
				return i;
			else;
	else
		for (int i = 0; i < index; i++)
			if (function (array[i]) == function (element))
				return i;

	return -1;
}

template<class T>
unsigned int Vector<T>::count ()
{
	return index;
}

template<class T>
unsigned int Vector<T>::capacity ()
{
	return size;
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
	if (this != &other)
	{
		index = other.index;
		size = other.size;
		array = new T[size];

		for (int i = 0; i < index; i++)
			array[i] = other.array[i];
	}

	return *this;
}

template <class T>
std::ostream& operator<< (std::ostream& stream, const Vector<T>& vector)
{
	if (vector.index == 0)
		stream << "[]\n";
	else
	{
		stream << "[";
		for (int i = 0; i < vector.index; i++)
			stream << vector.array[i] << ", ";
		stream << "\b\b]\n";
	}
	return stream;
}
