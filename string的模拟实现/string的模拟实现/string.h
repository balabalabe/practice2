#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_size = strlen(str);
		_capacity = _size + 1;
		_str = new char[_size + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_size(s._size)
		, _capacity(s._capacity)
	{
		_str = new char[_size + 1];
		strcpy(_str, s._str);
	}

	void Swap(String& s);

	String& operator=(String s);

	~String()
	{
		if (nullptr != _str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	void Show();
	const char* c_Str();//获取String类中的C风格字符串
	const char& operator[](size_t index)const;//括号运算符

	void Expand(size_t n);//扩容
	void PushBack(char c);//插入一个字符
	void PushBack(const char* str);//插入一个字符串
	void PopBack();//尾部删除一个字符
	void Insert(size_t pos, char c);//pos位置插入一个字符
	void Insert(size_t pos, const char* str);//pos位置插入一个字符串
	void Erase(size_t pos, size_t n = 1);//在pos位置删除n个字符串

	size_t Find(char c);//返回String对象中第一次出现字符c的下标
	size_t Find(const char* str);//返回String对象中第一次出现str的下标

	String operator+(char c);
	String& operator+=(char c);
	String operator+(const char* str);
	String& operator+=(const char* str);

	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
