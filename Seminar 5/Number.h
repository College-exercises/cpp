#pragma once

class Number
{
	char* value;
	unsigned int base;
public:
	Number () = default;
	Number (const char* value, int base);	// base 2..16
	Number (const Number& other);
	Number (Number&& other) noexcept;
	Number (const int value);

	~Number ();

	Number& operator= (const Number& other);
	Number& operator= (Number&& other) noexcept;
	
	bool operator! () const;
	char& operator[] (unsigned int index);
	
	bool operator>  (const Number& other) const;
	bool operator>= (const Number& other) const;
	bool operator<  (const Number& other) const;
	bool operator<= (const Number& other) const;
	bool operator== (const Number& other) const;
	bool operator!= (const Number& other) const;	
	bool operator== (const int other) const;
	bool operator!= (const int other) const;

	operator bool ();

	Number operator|  (const Number& other) const;
	Number operator&  (const Number& other) const;
	Number operator^  (const Number& other) const; 
	Number operator|= (const Number& other);
	Number operator&= (const Number& other);
	Number operator^= (const Number& other);

	void operator= (const int& source);
	void operator= (const char* source);
	
	Number operator+= (const Number& other);
	
	Number& operator-- ();		// prefix
	Number& operator-- (int);	// postfix
	
	friend Number operator- (const Number& left, const Number& right);
	friend Number operator+ (const Number& left, const Number& right);

	void switchBase (int newBase);
	void print ();
	int  getDigitsCount ();
	int  getBase ();
};