//#include<iostream>
//#include<assert.h>
//using namespace std;
//
//
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
//				reserve(2 * (_endOfStorage - _start));
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
//
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




#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T* Iterator;

public:
	Vector() //��vector
		:_start(nullptr), _finish(nullptr), _endOfStorage(nullptr){}


	Vector(size_t size, const T& data = T())//��size��
		: _start(new T[size]), _finish(_start + size), _endOfStorage(_start + size){
		for (size_t i = 0; i < size; ++i)
			_start[i] = data;
	}

	Vector(const T* first, const T* last){
		size_t size = last - first;
		_start = new T[size];
		for (size_t i = 0; i < size; ++i){
			_start[i] = first[i];
		}

		_finish = _start + size;
		_endOfStorage = _finish;
	}

	Vector(const Vector<T>& v);

	Vector<T>& operator=(const Vector<T>& v);

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = 0;
			_finish = 0;
			_endOfStorage = 0;
		}
	}



	Iterator Begin()
	{
		return _start;
	}

	Iterator End()
	{
		return _finish;
	}

	void PushBack(const T& data)
	{
		_CheckCapacity();
		*_finish = data;
		++_finish;
	}


	void PopBack()
	{
		if (_start == _finish)
			return;

		--_finish;
	}

	void Clear()
	{
		_finish = _start;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}


	size_t Size()const
	{
		return _finish - _start;
	}

	size_t Capacity()const
	{
		return _endOfStorage - _start;
	}

	bool Empty()const
	{
		return _start == _finish;
	}


	void ReSize(size_t newSize, const T& data = T())
	{
		size_t oldSize = Size();
		if (newSize <= oldSize)
			_finish = _start + newSize;
		else
		{
			size_t capacity = Capacity();
			if (newSize < capacity)
			{
				while (newSize != oldSize)
				{
					*_finish = data;
					++_finish;
					--newSize;
				}
			}
			else
			{

				T* pTmp = new T[newSize];
				if (_start)
				{

					for (size_t i = 0; i < oldSize; ++i)
						pTmp[i] = _start[i];

					for (size_t i = oldSize; i < newSize; ++i)
						pTmp[i] = data;


					delete[] _start;
				}


				_start = pTmp;
				_finish = _start + newSize;
				_endOfStorage = _finish;
			}
		}
	}

	void Reserve(size_t n)
	{
		if (n > Capacity())
		{

			size_t size = Size();
			T* pTmp = new T[n];
			if (_start)
			{

				for (size_t i = 0; i < size; ++i)
					pTmp[i] = _start[i];


				delete[] _start;
			}


			_start = pTmp;
			_finish = _start + size;
			_endOfStorage = _start + n;
		}
	}



	T& operator[](size_t index)
	{
		assert(index < Size());
		return _start[index];
	}

	const T& operator[](size_t)const
	{
		assert(index < Size());
		return _start[index];
	}

	T& Front()
	{
		return *_start;
	}

	const T& Front()const
	{
		return *_start;
	}

	T& Back()
	{
		return *(_finish - 1);
	}

	const T& Back()const
	{
		return *(_finish - 1);
	}

private:
	void _CheckCapacity()
	{
		if (_finish == _endOfStorage)
		{
			size_t size = Size();
			size_t newSize = size * 2 + 3;
			T* pTmp = new T[newSize];

			if (_start)
			{
				// �������T�Ƿ�Ϊ�������ͣ�
				if (false)
				{
					memcpy(pTmp, _start, size * sizeof(T));
				}
				else
				{
					for (size_t i = 0; i < size; ++i)
						pTmp[i] = _start[i];
				}

				delete[] _start;
			}

			_start = pTmp;
			_finish = _start + size;
			_endOfStorage = _start + newSize;
		}
	}

private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};
void TestVectorint()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	cout << v1.Size() << endl;
	cout << v1.Capacity() << endl;
	cout << v1.Front() << endl;
	cout << v1.Back() << endl;
	for (size_t i = 0; i < v1.Size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	v1.PopBack();
	v1.PopBack();
	cout << v1.Size() << endl;
	cout << v1.Capacity() << endl;
	cout << v1.Front() << endl;
	cout << v1.Back() << endl;
	for (size_t i = 0; i < v1.Size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	v1.ReSize(20, 9);
	Vector<int>::Iterator it = v1.Begin();
	while (it != v1.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	TestVectorint();
	return 0;
}
