#include<iostream>

class ABC{
private:
	ABC(){
		std::cout << "������һ������" << std::endl;
	}
	ABC(const ABC&);
	ABC& operator=(const ABC&);
	~ABC(){
		std::cout << "������һ������" << std::endl;
	}
	static ABC use;

public:
	static ABC* getABC(){
		return &use;
	}
};

//ABC ABC::use;     //��̬����ֻ����������


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
//		cout << "������һ����������" << endl;
//	}
//	Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//	~Singleton(){
//		//������������Ҳ��Ҫ������private��
//		//��Ϊ������Ҫ���ʵ���ڳ������е����������ж�����
//		//�������ǲ�����ʵ���Լ������������������ͷŶ���
//		cout << "������һ����������" << endl;
//	}
//	static Singleton instance;  //�������ǵĵ�������ע������һ����������������������
//public:
//	static Singleton* getInstance();
//};
//
////���������̬��Ա����������ص�ʱ����Ѿ���ʼ������
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