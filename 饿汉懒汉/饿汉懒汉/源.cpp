#include<iostream>

class ABC{
private:
	ABC(){
		std::cout << "创建了一个对象" << std::endl;
	}
	ABC(const ABC&);
	ABC& operator=(const ABC&);
	~ABC(){
		std::cout << "销毁了一个对象" << std::endl;
	}
	static ABC use;

public:
	static ABC* getABC(){
		return &use;
	}
};

//ABC ABC::use;     //静态类型只能类外声明


int main(){
	ABC* test = ABC::getABC();
	return 0;
}


//#include <iostream>
//using namespace std;
//
//class Singleton{
//private:
//	Singleton(){
//		cout << "创建了一个单例对象" << endl;
//	}
//	Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//	~Singleton(){
//		//析构函数我们也需要声明成private的
//		//因为我们想要这个实例在程序运行的整个过程中都存在
//		//所以我们不允许实例自己主动调用析构函数释放对象
//		cout << "销毁了一个单例对象" << endl;
//	}
//	static Singleton instance;  //这是我们的单例对象，注意这是一个类对象，下面会更改这个类型
//public:
//	static Singleton* getInstance();
//};
//
////下面这个静态成员变量在类加载的时候就已经初始化好了
//Singleton Singleton::instance;
//
//Singleton* Singleton::getInstance(){
//	return &instance;
//}
//int main(){
//	cout << "Now we get the instance" << endl;
//	Singleton* instance1 = Singleton::getInstance();
//	Singleton* instance2 = Singleton::getInstance();
//	Singleton* instance3 = Singleton::getInstance();
//	cout << "Now we destroy the instance" << endl;
//	return 0;
//}