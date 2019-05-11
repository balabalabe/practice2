//#include<iostream>
//#include<assert.h>
//template<class T>
//
//class SeqList{//顺序表
//public:
//	SeqList(size_t capacity = 3) :_array(new T[capacity]), _size(0), _capacity(capacity){
//
//	}
//	//SeqList(const SeqList<T>& s);
//	//SeqList<T>& operator=(const SeqList<T>& s);
//	SeqList(size_t n, const T& data = T()) :_array(new T[n]), _capacity(n), _size(n){//date引用无名对象
//		//memset(_array, date, _size*sizeof(T));  
//		//memset是将_array连续空间中每个字节设置成data,在这里不合适用
//		for (size_t i = 0; i < size; ++i){
//			_array[i] = date;
//		}
//	}
//	~SeqList(){
//
//	}
//	void PushBack(const T& date){
//		_CheckCapacity();
//		_array[_size++] = data;
//	}
//	void PopBack(){
//		--size;
//	}
//	void Insert(size_t pos);//任意位置插入
//	void Erase(size_t pos);//任意位置删除
//
//	T& operator[](size_t index){
//		assert(index < _size);
//		return _array[index];
//	}
//	const T& operator[](size_t index)const{
//		assert(index < _size);
//		return _array[index];
//	}
//	size_t Capacity()const{
//		return _capacity;
//	}
//	size_t Size()const{
//		return _size;
//	}
//	bool Empty()const{
//		return _size == 0;
//	}
//	void Clear(){
//		_size = 0;
//	}
//private:
//	void _CheckCapacity(){
//		if (_size >= _capacity){
//			size_t newCapacity = (_capacity << 1);
//			T* temp = new T[newCapacity];
//			for (size_t i = 0; i < _size; i++){
//				temp[i] = _array[i];
//			}
//			delete[] _array;
//			_array = temp;
//			_capacity = newCapacity;
//		}
//	}
//private:
//	T* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//template<class T>//函数在模板类外进行定义,首先要添加模板的参数列表
//SeqList<T>::~SeqList(){
//	if (_array){
//		delete[] _array;
//		_array = nullptr;
//		_capacity = 0;
//		_size = 0;
//	}
//}
//
//int main(){
//	const SeqList<int> s1(10, 5);//类模板不是真正的类,使用类模板时要先实例化类模板
//	SeqList<double> s2;
//	SeqList<int> s3;
//	s3.PushBack(1);
//	s3.PushBack(2);
//	s3.PushBack(3);
//	std::cout << s3.Size() << std::endl;
//	std::cout << s3.Capacity() << std::endl;
//	std::cout << s3[1] << std::endl;
//
//	s3.PushBack(4);
//	s3.PushBack(5);
//	s3.PushBack(6);
//	std::cout << s3.Size() << std::endl;
//	std::cout << s3.Capacity() << std::endl;
//	std::cout << s3[1] << std::endl;
//
//	s3.Clear();
//	std::cout << s3.Size() << std::endl;
//	std::cout << s3.Capacity() << std::endl;
//	std::cout << s3[1] << std::endl;
//	return 0;
//}
//

//123*456=>(100+20+3)*(400+50+3)
//=>(1*4*10000)+(1*5*1000)+(1*3*100)+(2*4*1000)+(2*5*100)+(2*3*10)+(3*4*100)+(3*5*10)+(3*3*1);
//#include<stdio.h>
//int transform(int c){
//	int back = 1;
//	while (c-1 > 0){
//		back = back * 10;
//		c--;
//	}
//	return back;
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
//		a = a / 10;
//		count1++;
//
//	}
//	tmp = 0;//清零
//	while (b > 0){
//		tmp = b % 10;
//		arr2[count2] = tmp;
//		b = b / 10;
//		count2++;
//	}
//	int record = count2;
//	while (count1 > 0){
//		while (count2 > 0){
//			num = num + arr1[count1 - 1] * transform(count1) * arr2[count2 - 1] * transform(count2);
//			count2--;
//		}
//		if (count2 <= 0){
//			count2 = record;
//		}
//		count1--;
//	}
//	return num;
//}
//
//int main(void){
//	int u = 222;
//	int v = 369;
//	printf("%d\n", small(u, v));
//	return 0;
//}


//void func(int **a){
//	**a = 6;
//}
//
//int main(void){
//	int x = 2;
//	int *a = &x;
//	func(&a);
//	printf("a= %d\n", a);
//	return 0;
////}
//
// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
//
//  int main(void) {
//close(0);
// //close(2);  
//	   int fd = open("myfile", O_RDONLY);
//   if (fd < 0){
//	    perror("open");
//	    return 1;
//
//	}
//   printf("fd: %d\n", fd);
//
//	       close(fd);
//
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////#include<error.h>
//int main(){
//	FILE *fp;
//	char *str;
//	int sum = 0, i = 0, j = 0;
//	char a[20] = { '\0' };
//	fp = fopen("/etc/passwd", "rb");
//	if (fp == NULL)
//		 {
//		   perror("read the passwd file error");
//		   exit(1);
//		 }
//	 while (fgets(str=0, 1024, fp) != NULL)
//		 {
//		   sum = sum + 1;
//		   j = 0;
//		   i = 0;
//		   while (str[i] != '\0')
//			  {
//			    if (str[i] == ':')
//				       break;
//			    a[j++] = str[i++];
//			
//				  }
//		   printf("the sum %d,account user is :%s", sum, a);
//		 }
//	
//}

//#include<stdio.h>
//#include<uniste.h>
//#include<string.h>
//#include<fcntl.h>
//#include<time.h>
//
//int main(){
//	FILE* fp = fopen("date.txt", "w+");
//	setbuf(fp, NULL);
//	int pid = fork();
//	if (pid == 0){
//		while (1){
//			sleep(1);
//			char buff[1024] = { 0 };
//			fseek(fp, -31, SEEK_END);
//			fread(buff, 1023, 1, fp);
//			printf("%s\n", buff);
//		}
//	}
//	else if (pid > 0){
//		while (1){
//			time_t t;
//			struct tm* tp;
//			time(&t);
//			tp = localtime(&t);
//			fprintf(fp, "当前时间:%d-%d-%d-%d-%d-%d\n",
//				tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
//			fflush(fp);
//			sleep(1);
//		}
//	}
//	else
//		return -1;
//	fclose(fp);
//	return 0;
//}

#include<iostream>
#include<list>
using namespace std;

void PrintList(list<int>& l) {
	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}

// push_back/pop_back/push_front/pop_front 
void TestList1() {
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));

	// 在list的尾部插入4，头部插入0    
	L.push_back(4);
	L.push_front(0);
	PrintList(L);

	// 删除list尾部节点和头部节点    
	L.pop_back();
	L.pop_front();
	PrintList(L);
}