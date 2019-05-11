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
	const char* c_Str();//��ȡString���е�C����ַ���
	const char& operator[](size_t index)const;//���������

	void Expand(size_t n);//����
	void PushBack(char c);//����һ���ַ�
	void PushBack(const char* str);//����һ���ַ���
	void PopBack();//β��ɾ��һ���ַ�
	void Insert(size_t pos, char c);//posλ�ò���һ���ַ�
	void Insert(size_t pos, const char* str);//posλ�ò���һ���ַ���
	void Erase(size_t pos, size_t n = 1);//��posλ��ɾ��n���ַ���

	size_t Find(char c);//����String�����е�һ�γ����ַ�c���±�
	size_t Find(const char* str);//����String�����е�һ�γ���str���±�

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
