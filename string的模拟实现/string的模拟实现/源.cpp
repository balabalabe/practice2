#include "string.h"

void String::Show()
{
	cout << "_str" << _str << endl;
}

void String::Swap(String& s)
{
	_size = s._size;
	_capacity = s._capacity;
	delete[] _str;
	_str = s._str;
	s._str = new char[1];
}

String& String::operator=(String s)
{
	Swap(s);
	return *this;
}

const char* String::c_Str()
{
	return _str;
}

void String::Expand(size_t n)
{
	char* tmp = new char[n];
	memcpy(tmp, _str, _size + 1);//浅拷贝
	delete[] _str;
	_str = tmp;
	_capacity = n;
}

void String::PushBack(char c)
{
	Insert(_size, c);
}

void String::PushBack(const char* str)
{
	Insert(_size, str);
}

void String::Insert(size_t pos, char c)
{
	assert(_size > pos);
	if (_size >= _capacity - 1)
	{
		Expand(2 * _capacity + 1);
	}
	for (int i = _size; i > pos; i--)
	{
		_str[i] = _str[i - 1];

	}
	_str[pos] = c;
	++_size;
}

void String::Insert(size_t pos, const char* str)
{
	assert(pos < _size);
	const char* tmp = str;
	size_t size = 0;
	for (; *tmp != '\0'; tmp++)
	{
		++size;
	}

	if (_capacity < _size + size)
	{
		Expand(_capacity + size);
	}
	for (int i = _size; i >= pos; i--)
	{
		_str[i + size] = _str[i];
	}
	int i = 0;
	while (*(str + i) != '\0')
	{
		_str[pos + i] = str[i];
		++i;
	}
	_size = _size + size;
}

void String::PopBack()
{
	Erase(_size - 1, 1);
}

void String::Erase(size_t pos, size_t n)
{
	if (0 == _size)
	{
		return;
	}
	if (0 == n)
	{
		return;
	}
	assert(pos <= _size);
	while ((pos + n) <= _capacity)
	{
		_str[pos] = _str[pos + n];
		++pos;
	}
	if (_size - n > 0)
	{
		_size = _size - n;
	}
	else
	{
		_size = 0;
	}
	_str[_size] = 0;
}

size_t String::Find(char c)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_str[i] == c)
		{
			return i;
		}
	}
	return (size_t)-1;
}

size_t String::Find(const char* str)
{
	//快慢指针法
	const char* _fast = _str;
	const char* _slow = _str;
	const char* cur = str;
	while (_slow < (_str + _size))
	{
		_fast = _slow;
		if (*_fast == *cur)
		{
			while (*_fast == *cur)
			{
				if (*_fast == '\0')
				{
					break;
				}
				cur++;
				_fast++;
			}
			if (*cur == '\0')
			{
				return _slow - str;
			}
		}
		_slow++;
		cur = str;
	}
	return (size_t)-1;
}

String String::operator+(char c)
{
	String tmp(*this);
	tmp.PushBack(c);
	return tmp;
}

String& String::operator+=(char c)
{
	this->PushBack(c);
	return *this;
}

String String::operator+(const char* str)
{
	String tmp(*this);
	tmp.PushBack(str);
	return tmp;
}

String& String::operator+=(const char* str)
{
	this->PushBack(str);
	return *this;
}

bool String::operator>(const String& s)
{
	const char* _tmp = _str;
	const char* tmp = s._str;
	while (*tmp != '\0' && *_tmp != '\0' && *tmp == *_tmp)
	{
		tmp++;
		_tmp++;
	}
	if (*_tmp > *tmp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator>=(const String& s)
{
	if (*this > s || *this == s)
	{
		return true;
	}
	return false;
}

bool String::operator<(const String& s)
{
	const char* _tmp = _str;
	const char* tmp = s._str;
	while (*_tmp != '\0' && *tmp != '\0' && *_tmp == *tmp)
	{
		_tmp++;
		tmp++;
	}
	if (*_tmp < *tmp)
	{
		return true;
	}
	return false;
}


bool String::operator<=(const String& s)
{
	if (*this < s || *this == s)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator==(const String& s)
{
	const char* _tmp = _str;
	const char* tmp = s._str;
	while (*_tmp == *tmp)
	{
		if (*_tmp == '\0' && *tmp == '\0')
		{
			return true;
		}
		tmp++;
		_tmp++;
	}
	return false;
}

bool String::operator!=(const String& s)
{
	if (!(*this == s))
	{
		return true;
	}
	return false;
}


int main(){

	return 0;
}