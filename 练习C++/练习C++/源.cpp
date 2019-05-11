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
////string���ģ��ʵ��:��̬���ַ���
////��ͳ�����
//class String{
//public:
//	String(char* str = "")//��������εĻ����Թ���һ�����ַ���
//	{
//		if (nullptr == str){
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];//���һ���ռ����ڴ��\0
//		strcpy(_str, str);//strcpy���\0һ�𿽱�����,���Բ���Ҫ�ֶ����\0
//	}
//
//	//string�ྭ����Ҫ�ͷ��ڴ�,���Բ�������ķ���д��������,�����ڴ�й©
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
////string��ģ��ʵ��
////���:�ִ���
//class String{
//public:
//	String(char* str = "")//��������εĻ����Թ���һ�����ַ���
//	{
//		if (nullptr == str){
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];//���һ���ռ����ڴ��\0
//		strcpy(_str, str);//strcpy���\0һ�𿽱�����,���Բ���Ҫ�ֶ����\0
//	}
//
//	//string�ྭ����Ҫ�ͷ��ڴ�,���Բ�������ķ���д��������,�����ڴ�й©
//	String(const String& s) :_str(nullptr){
//		String strTemp(s._str);
//		swap(_str, strTemp._str);
//	}
//
//	//��������ص�һ���汾(���ǵ����Լ����Լ���ֵ�����,������û��)
//	//String& operator=(const String& s){
//	//	if (this != &s){//�п�Ҫ��Ҫ������ν
//	//		String strTemp(s);
//	//		swap(_str, strTemp._str);
//	//	}
//	//	return *this;
//	//}
//
//	//�ڶ����汾(�͵����汾����һ����,���ǵڶ����ں������д�����ʱ����)
//	//String& operator=(const String& s){
//	//	String strTemp(s);//������ʱ����
//	//	swap(_str, strTemp._str);
//	//	}
//	//	return *this;
//	//}
//
//	//�������汾�Ѵ�����ʱ��������齻��������(�������)
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

////дʱ����(һ��Ҫע���̰߳�ȫ)
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
//			//���������һ����Դʱ,�ѵ�ǰ����������,����һ�������,���ж���ĵ�����
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
//	int GetRefCount() const{//����Ƿ�����Դ
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
//	//int  _count;  ����ļ�����
//	//���������ܸ�����ͨ�ĳ�Ա����,������Դһ�ͷż������޷�������Ķ���
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


//namespace str{//Ϊ�˲��Ϳ⺯��String��ͻ,�Ž������ռ���
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
//	tmp = 0;//����
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
////д�ļ�
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
////���ļ�
//int main() {
//	FILE *fp = fopen("myfile", "r");    
//	if (!fp){ 
//		printf("fopen error!\n"); 
//	}
//	char buf[1024];    
//	const char *msg = "hello bit!\n";
//	while (1){        
//		//ע�ⷵ��ֵ�Ͳ������˴��пӣ���ϸ�鿴man�ֲ���ڸú�����˵��        
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


////�绰����ƥ��
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
//}**********************************************************�绰��������OJ******************************************************

//#include<iostream>
//#include<assert.h>
//using namespace std;
////ģ��ʵ��vector
//namespace bit{
//	template<class T>
//	class vector{
//	public:
//		typedef T* iterator;
//		typedef T* reverse_iterator;
//		typedef const T* const_iterator;
//		//��vector�����������ָ�� T*
//	public:
//		//���캯���������ض��,��������ֻ����һ��
//		vector() :_start(nullptr), _finish(nullptr), _endOfStorage(nullptr){
//			//��vector
//		}
//
//		vector(size_t n, const T& data = T()){
//			//��n��ֵΪdata��Ԫ�طŵ�vector��ȥ
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
//			//�����乹��vector
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
//		//ǳ��������
//		vector(const vector<T>& v);
//
//		//ǳ��������
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
//		void reserve(size_t newCapacity){/////////////////////��������
//			size_t oldCapacity = capacity();
//			if (newCapacity > oldCapacity){
//				size_t oldSize = size();
//				T* temp = new T[newCapacity];
//
//				if (_start){
//				//memcpy(temp, _start, oldSize*sizeof(T));
//				//memcpy��ǳ����,�ڿ���ʱ������ַһ�𿽱���ȥ,����һ�ͷŵĻ����޷��ٶ�д����
//				//����������Զ������͵���Դ����ʱ�����
//				//���������Զ�����һ��string��:
//				//bit::vector<string> s;
//				//s.push_back("1111");
//				//s.push_back("2222");
//				//s.push_back("3333");
//				//PrintVector(s);
//				//s.push_back("4444");//�������
//				//ԭ����ǵ��ĸ�push��ʼ����,���ݺ�����ԭ��ַ,��Ϊmemcpy���������ݵ�ַ��ԭ��ַ��ͬ,���Ե��¿���������Ҳһ������
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
//						//ȱ��ͬ��,Ҳ��ǳ����,�����Զ������͹�����Դʱ���ܻ����
//						//��Ҳ�����ŵ�:Ч�ʸ�
//
//						//for+=:�ŵ���һ���������,ȱ����Ч�ʵ�
//
//						//���memcpy��for���ŵ���Խ����Ż�:���ж�T�Ƿ�����������,�������memcpy���������for
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
//	//��Χforѭ�������ķ�Χ������ȷ����,������������������begin��end,���Լ�ʹ���Ƕ�����const_begin��const_end�޷�ͨ������
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
		//��list����ָ����ʹ��
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
		//list�ĵ�����������T*,��Ϊlist����ʽ�ṹ,���������ռ�,������++�����ҵ���һ��
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

