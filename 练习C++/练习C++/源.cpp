//template<class T, size_t N = 10> 
//class Array{
//public:    
//	T& operator[](size_t index){ 
//		return _array[index];
//	}        
//	const T& operator[](size_t index)
//		const    { 
//		return _array[index]; 
//	}        
//	size_t Size()const{ 
//		return _size;
//	}        bool Empty()const{
//		return 0 == _size;
//	}    
//private:    
//	T _array[N];   
//	size_t _size;
//};


//#include<iostream>
////string类的模拟实现:动态的字符串
////传统的深拷贝
//class String{
//public:
//	String(char* str = "")//如果不传参的话可以构造一个空字符串
//	{
//		if (nullptr == str){
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];//多给一个空间用于存放\0
//		strcpy(_str, str);//strcpy会把\0一起拷贝过来,所以不需要手动添加\0
//	}
//
//	//string类经常需要释放内存,所以采用深拷贝的方法写拷贝构造,避免内存泄漏
//	String(const String& s) :_str(new char[strlen(s._str) + 1]){
//		strcpy(_str, s._str);
//	}
//
//	String& operator=(const String& s){
//		if (this != &s){
//			char* pStr = new char[strlen(s._str) + 1];
//				strcpy(pStr, s._str);
//			delete[] _str;
//			_str = pStr;
//		}
//		return *this;
//	}
//
//	~String(){
//		if (_str){
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};


//#include<iostream>
////string的模拟实现
////深拷贝:现代版
//class String{
//public:
//	String(char* str = "")//如果不传参的话可以构造一个空字符串
//	{
//		if (nullptr == str){
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];//多给一个空间用于存放\0
//		strcpy(_str, str);//strcpy会把\0一起拷贝过来,所以不需要手动添加\0
//	}
//
//	//string类经常需要释放内存,所以采用深拷贝的方法写拷贝构造,避免内存泄漏
//	String(const String& s) :_str(nullptr){
//		String strTemp(s._str);
//		swap(_str, strTemp._str);
//	}
//
//	//运算符重载第一个版本(考虑到了自己给自己赋值的情况,二三版没有)
//	//String& operator=(const String& s){
//	//	if (this != &s){//判空要不要都无所谓
//	//		String strTemp(s);
//	//		swap(_str, strTemp._str);
//	//	}
//	//	return *this;
//	//}
//
//	//第二个版本(和第三版本质是一样的,但是第二版在函数体中创建临时对象)
//	//String& operator=(const String& s){
//	//	String strTemp(s);//创建临时对象
//	//	swap(_str, strTemp._str);
//	//	}
//	//	return *this;
//	//}
//
//	//第三个版本把创建临时对象的事情交给编译器(最难理解)
//	String& operator=(String s){
//		swap(_str,s._str)
//		return *this;
//	}
//
//	~String(){
//		if (_str){
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};

////写时拷贝(一定要注意线程安全)
//#include<iostream>
//class String{
//public:
//	String(const char* str = ""):_count(new int(1)){
//		if (nullptr == str){
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	String(const String& s) :_str(s._str), _count(s._count){
//		++(*_count);
//	}
//
//	String& operator=(const String& s){
//		if (this != &s){
//			Release();
//			_str = s._str;
//			_count = s._count;
//			++(*_count);
//		}
//		return *this;
//	}
//
//	~String(){
//		Release();
//	}
//
//	char& operator[](size_t index){
//		if (GetRefCount() > 1){
//			//多个对象共用一个资源时,把当前对象分离出来,避免一个对象改,所有对象改的问题
//			String strTemp(_str);
//			swap(_str, strTemp._str);
//			this->Swap(strTemp);
//		}
//		return _str[index];
//	}
//
//	const char& operator[](size_t index)const{
//		return _str[index];
//	}
//
//	int GetRefCount() const{//检查是否共用资源
//		return *_count;
//	}
//
//	void Swap(String& s){
//		swap(_str, s._str);
//		swap(_count, s._count);
//	}
//
//private:
//	char* _str;
//	//int  _count;  错误的计数器
//	//计数器不能给成普通的成员变量,否则资源一释放计数器无法传给别的对象
//	int* _count;
//
//	void Release(){
//		if (0 == --*_count && _str){
//			delete[] _str;
//			_str = nullptr;
//
//			delete[] _count;
//			_count = nullptr;
//		}
//	}
//};


//namespace str{//为了不和库函数String冲突,放进命名空间里
//	class string{
//	public:
//		string(const char)
//	private:
//		char _str[16];
//		size_t _size;
//		size_t _capacity;
//	};
//}

//int transform(int c){
//	while (c > 0){
//		c = c * 10;
//	}
//	return c;
//}
//
//int small(int a, int b){
//	int num = 0;
//	int tmp = 0;
//	int count1 = 0;
//	int count2 = 0;
//	int arr1[1024] = { 0 };
//	int arr2[1024] = { 0 };
//	while (a > 0){
//		tmp = a % 10;
//		arr1[count1] = tmp;
//		count1++;
//
//	}
//	tmp = 0;//清零
//	while (b > 0){
//		tmp = b % 10;
//		arr2[count2] = tmp;
//		count2++;
//	}
//	while (count1 > 0){
//		while (count2 > 0){
//			num =num + arr1[count1 - 1] * transform(count1) * arr2[count2 - 1] * transform(count2);
//			count2--;
//		}
//		count1--;
//	}
//	return num;
//}
//
//int main(void){
//	int u = 123;
//	int v = 456;
//	printf("%d\n", small(u, v));
//	return 0;
//}

//#include <stdio.h>
//int main(int argc, char *argv[]){ 
//	extern char **environ;    
//	int i = 0;    
//	for (; environ[i]; i++){ 
//		printf("%s\n", environ[i]); 
//	}    
//	return 0; 
//}

//#include <stdio.h>
//int main(int argc, char *argv[], char *env[]){ 
//	int i = 0;    
//	for (; env[i]; i++){ 
//		printf("%s\n", env[i]); 
//	}    
//	return 0; 
//}

//#include<stdio.h>
//#include<stdlib.h>
//char *my_strcpy(char *dst, char const *src){
//	char *ds = dst;
//	if ((NULL == dst) || (NULL == src)){
//		exit(EXIT_FAILURE);
//	}
//	while ((*dst++ = *src++) != '\0'){
//		;
//	}
//	return ds;
//}
//int main(){
//	char ch[] = "fafasfa";
//	const char che[] = "zzffzz";
//	printf("%s", my_strcpy(ch, "ffasfsafaa"));
//	exit(EXIT_SUCCESS);
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h> 
//#include <string.h>
////写文件
//int main() {
//	FILE *fp = fopen("myfile", "w");    
//	if (!fp){ printf("fopen error!\n"); }
//
//	const char *msg = "hello bit!\n";    
//	int count = 5;    
//	while (count--){ 
//		fwrite(msg, strlen(msg), 1, fp); 
//	}
//
//	fclose(fp);
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h> 
//#include <string.h>
////读文件
//int main() {
//	FILE *fp = fopen("myfile", "r");    
//	if (!fp){ 
//		printf("fopen error!\n"); 
//	}
//	char buf[1024];    
//	const char *msg = "hello bit!\n";
//	while (1){        
//		//注意返回值和参数，此处有坑，仔细查看man手册关于该函数的说明        
//		size_t s = fread(buf, 1, strlen(msg), fp);        
//		if(s > 0){            
//			buf[s] = 0;            
//			printf("%s", buf);        }        
//		if(feof(fp)){            
//			break;        
//		}    
//	}
//		fclose(fp);    
//		return 0;
//	}


////电话摁键匹配
//string letterMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tux", "wxyz" };
//
//class Solution{
//public:
//	void _letterCombinations(string& digits, string strRet, vector<string>& vRet, int index){
//		if (index >= digits.size()){
//			vRet.push_back(strRet);
//			return;
//		}
//
//		string& strLetter = letterMap[digits[index] - '0'];
//		for (size_t = 0; i < strLetter.size(); ++i){
//			strRet += strLetter[i];
//			_letterCombinations(digits, strRet, vRet, index + 1);
//		}
//	}
//
//	vector<string> letterCombinations(string digits){
//		vector<string> vRet;
//		if (digits.empty())
//			return vRet;
//
//		string strRet;
//		int index = 0;
//		_letterCombinations(digits, strRet, vRet, index);
//		return vRet;
//	}
//}**********************************************************电话摁键在线OJ******************************************************

//#include<iostream>
//#include<assert.h>
//using namespace std;
////模拟实现vector
//namespace bit{
//	template<class T>
//	class vector{
//	public:
//		typedef T* iterator;
//		typedef T* reverse_iterator;
//		typedef const T* const_iterator;
//		//在vector里迭代器就是指针 T*
//	public:
//		//构造函数可以重载多个,拷贝构造只能有一个
//		vector() :_start(nullptr), _finish(nullptr), _endOfStorage(nullptr){
//			//空vector
//		}
//
//		vector(size_t n, const T& data = T()){
//			//把n个值为data的元素放到vector里去
//			_start = new T[n];
//			for (size_t = 0; i < n; ++i){
//				_start[i] = data;
//
//				_finish = _start + n;
//				_endOfStorage = _finish;
//			}
//
//		}
//
//		vector(T* first, T* last){
//			//用区间构造vector
//			size_t size = last - first;
//			_start = new T[size];
//			_finish = _start;
//			while (first != last){
//				*_finish = *first;
//				++_finish;
//				++first;
//			}
//			_endOfStorage = _finish;
//		}
//
//		//浅拷贝问题
//		vector(const vector<T>& v);
//
//		//浅拷贝问题
//		vector<T>& operator=(const vector<T>& v);
//
//		~vector(){
//			if (_start){
//				delete[] _start;
//				_start = nullptr;
//				_finish = nullptr;
//				_endOfStorage = nullptr;
//			}
//		}
//
//		////////iterator
//		iterator begin(){
//			return _start;
//		}
//
//		iterator end(){
//			return _finish;
//		}
//
//		reverse_iterator rbegin(){
//			return rend();
//		}
//
//		reverse_iterator rend(){
//			return bagin();
//		}
//
//		const_iterator begin(){
//			return _start;
//		}
//
//		const_iterator end(){
//			return _finish;
//		}
//		////////
//
//		////////capacity
//		size_t size()const{
//			return _finish - _start;
//		}
//
//		size_t capacity()const{
//			return _endOfStorage - _start;
//		}
//
//		bool empty()const{
//			return _start == finish;
//		}
//
//		void reserve(size_t newCapacity){/////////////////////尚有问题
//			size_t oldCapacity = capacity();
//			if (newCapacity > oldCapacity){
//				size_t oldSize = size();
//				T* temp = new T[newCapacity];
//
//				if (_start){
//				//memcpy(temp, _start, oldSize*sizeof(T));
//				//memcpy是浅拷贝,在拷贝时会连地址一起拷贝过去,所以一释放的话便无法再读写数据
//				//因此在遇到自定义类型的资源管理时会出错
//				//比如我们自定义了一个string类:
//				//bit::vector<string> s;
//				//s.push_back("1111");
//				//s.push_back("2222");
//				//s.push_back("3333");
//				//PrintVector(s);
//				//s.push_back("4444");//程序崩溃
//				//原因就是第四个push开始增容,增容后销毁原地址,因为memcpy拷贝的数据地址和原地址相同,所以导致拷贝的数据也一起销毁
//					for (size_t i = 0; i < oldSize; ++i)
//						temp[i] = _start[i];
//					delete[] _start;
//				}
//				
//				_start = temp;
//				_finish = _start + oldSize;
//				_endOfStorage = _start + newCapacity;
//			}
//		}
//
//		void resize(size_t newSize, const T& data = T()){
//			size_t oldSize = size();
//			if (newsize < oldSize)
//				_finish = _start + newSize;
//			else{
//				if (newSize > capacity()){
//					T* temp = new T[newSize];
//					if (_start){
//						//memcpy(temp, _start, sizeof(T)*oldSize);
//						//缺点同上,也是浅拷贝,遇到自定义类型管理资源时可能会出错
//						//但也有其优点:效率高
//
//						//for+=:优点是一定不会出错,缺点是效率低
//
//						//结合memcpy和for的优点可以进行优化:先判断T是否是内置类型,如果是用memcpy如果不是用for
//						for (size_t i = 0; i < oldSize; ++i)
//							temp[i] = _start[i];
//						delete[] _start;
//
//					}
//		
//	
//					_start = temp;
//					_endOfStorage = _start + newSize;
//				}
//				for (size_t i = oldSize; i < newSize; ++i)
//					_start[i] = data;
//				_finish = _start + newSize;
//			}
//		
//		}
//		////////
//
//		////////acess
//		T& operator[](size_t index)const{
//			assert(index < size());
//			return _start[index];
//		}
//
//		T& front(){
//			return _start[0];
//		}
//
//		const T& front()const{
//			return _start[0];
//		}
//
//		T& back(){
//			return *(_finish - 1);
//		}
//
//		const T& back()const{
//			return *(_finish - 1);
//		}
//		////////
//
//		////////modify
//		void push_back(const T& data){
//			if (size() == capacity())
//				reserve(2 * (_endOfStorage - _start);
//
//			*_finish++ = data;
//		
//		}
//
//		void pop_back(){
//			--_finish;
//		}
//
//
//		iterator insert(iterator position, const T& data);
//		
//		iterator erase(iterator position);
//		////////
//	private:
//		T* _start;
//		T* _finish;
//		T* _endOfStorage;
//	};
//}
//
//
//template<class T>
//void PrintVector(const bit::vector<T>& v){
//	for (const auto& e : v)
//		cout << e << " ";
//	//范围for循环迭代的范围必须是确定的,如果是类类型则需调用begin和end,所以即使我们定义了const_begin和const_end无法通过编译
//
//	cout << endl;
//}

//void TestVector1(){
//	bit::vector<int> v1;
//	bit::vector<int> v2(10, 5);
//
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	bit::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
//
//	cout << v2.size() << endl;
//	cout << v2.capacity() << endl;
//	cout << v3[5] << endl;
//	cout << v3.front() << endl;
//	cout << v3.back() << endl;
//
//	PrintVector(v2);
//	PrintVector(v3);
//}
//
//void TestVector2(){
//	bit::vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	PrintVector(v);
//}
//
//void TestVector3(){
//	int array[] = { 1, 2, 3, 4 };
//	bit::vector<int> v(array, array + sizeof(array) / sizeof(array[0]));
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	PrintVector(v);
//
//	v.resize(10, 5);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	PrintVector(v);
//
//	v.resize(6);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	PrintVector(v);
//
//	v.resize(8, 6);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	PrintVector(v);
//
//	v.reserve(5);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//
//	v.reserve(20);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//}
//
//
//
//int main(){
//	void TestVector1();
//	return 0;
//}

namespace{
    template<class T>
	struct ListNode{
		ListNode(const T& data = T()) :_pPrev(nullptr), _pNext(nullptr), _data(data);
		ListNode<T>* _pPrev;
		ListNode<T>* _pNext;
		T _data;
	};

	//operator*()
	//operator->()
	//operator++()
	//operator--()
	//operator==()
	//operator!=()
	template<class T, class Ref, class Ptr>
	struct ListIterator{
		//把list当成指针来使用
		typedef ListNode<T>* PNode;
	public:
		ListIterator(PNode pNode = nullptr) :_pNode(pNode){

		}
		ListIterator(const Self& s) :_pNode(s._pNode){

		}

		Ref operator*(){
			return _pNode->_data;
		}

		Ptr operator->(){
			return &(operator*());
		}

		Self& operator++(){
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int){
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}

		Self& operator--(int){
			_pNode = _pNode->_pPrev;
			return *this;
		}

		Self operator--(int){
			Self temp(*this);
			_pNode = _pNode->_pPrev;
			return temp;
		}

		bool operator!=(const Self& s){
			return _pNode != s._pNode;
		}

		bool operator==(const Self& s){
			return _pNode == s._pNode;
		}

	private:
		PNode _pNode;.........................................
	};

	template<class T>
	class list{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		//typedef T* iterator;  
		//list的迭代器不能用T*,因为list是链式结构,不是连续空间,迭代器++不能找到下一个
		typedef ListIterator<T, T&, T*> iterator;

	public:
		list(){
			CreateHead();
		}
		list(size_t n, const T& data = T()){
			CreateHead();
			for (size_t i = 0; i < n; ++i)
				push_back(data);
		}
		list(T* first, T* last){
			CreateHead();
			while (first != last){
				push_back(*first);
				++first;
			}
		}
		list(list<T>& L);
		list<T>& operator=(const list<T>& l);

		~list(){
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
		//////////////iterator
		iterator begin(){
			return iterator(_pHead->_pNext);
		}

		iterator end(){
			return iterator(_pHead);
		}



		//////////////capacity
		size_t size()const{
			size_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur){
				count++;
				pCur = pCur->_pNext;
			}
			return count;
		}

		bool empty()const{
			return _pHead->_pNext == _pHead;
		}

		void resize(size_t newSize, const T&data = T()){
			size_t oldSize = size();
			if (newSize > oldSize){
				for (size_t i = oldSize; i < newSize; ++i)
					push_back(data);
			}
			else{
				for (size_t i = newSize; i < oldSize; ++i)
					pop_back();
			}
		}
		//////////////

		//////////////acess
		T& front(){
			return _pHead->_pNext->_data;
		}

		const T& front()const{
			return _pHead->_pNext->_data;
		}

		T& back(){
			return _pHead->_pPrev->_data;
		}

		const T& back()const{
			return _pHead->_pPrev->_data;
		}
		//////////////

		//////////////modify
		void push_back(const T& data){
			insert(end(), data);
		}
		void pop_back(){
			erase(--end());
		}
		void push_front(const T& data){
			insert(begain(), data);
		}
		void pop_front(){
			erase(begin());
		}
		iterator insert(iterator position, const T& data);
		iterator erase(iterator position);
		void clear(){
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead){
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPrev = _pHead;
		}
		//////////////
	private:
		void CreateHead(){
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPrev = _pHead;
		}
	};
}

