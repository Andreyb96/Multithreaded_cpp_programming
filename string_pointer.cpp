#include <iostream>
#include <string>

#include <iostream>
#include <string>

class StringPointer
{
public:
	StringPointer(std::string* ptr) : ptr(ptr), raw(false) {}
	std::string* operator->()
	{
		checkPtr();
		return ptr;
	}

	std::string operator*()
	{
		checkPtr();
		return *ptr;
	}

	operator std::string*()
	{
		checkPtr();
		return ptr;
	}
	~StringPointer()
	{
		if (raw)
		{
			delete ptr;
		}
	}

private:
	void checkPtr()
	{
		if (ptr == NULL)
		{
			raw = true;
			ptr = new std::string();
		}
	}
	std::string* ptr;
	bool raw;
};