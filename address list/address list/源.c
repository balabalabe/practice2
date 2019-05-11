//#pragma once
////升级:放入文件
//
//
////1.改成动态
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////通讯录,需要在代码中表示若干个人
//
//typedef struct PersonInfo
//{
//	char name[1024];
//	char phone[1024];
//}PersonInfo;
//
//
//typedef struct AddrBook
//{
//	//指向数组的指针
//	PersonInfo* preson_info;
//
//	//[0,size)有意义的区间
//	int capacity;
//	int size;
//}AddrBook;
//
//AddrBook g_addr_book;
//
//enum{
//	EXIT = 0,
//	ADD,
//	DEL,
//	MODIFY,
//	FIND,     //查
//	PRINT,    //打印
//	CLEAR     //清除
//};
//
//
//
//void Init()
//{
//	g_addr_book.size = 0;
//
//	g_addr_book.capacity = 100;
//	g_addr_book.preson_info = (PersonInfo*)malloc(sizeof(PersonInfo)*g_addr_book.capacity);
//}
//
//int Menu()
//{
//	//打印出用户提供的操作
//	printf("===============================\n");
//	printf("           1.添加\n");
//	printf("           2.删除\n");
//	printf("	   3.修改\n");
//	printf("	   4.查找\n");
//	printf("	   5.显示\n");
//	printf("	   6.清除\n");
//	printf("	   0.退出\n");
//	printf("===============================\n");
//	printf("请输入你的选择:\n");
//	int choice = -1;
//	scanf("%d", &choice);
//	return choice;
//	//并且用户进行输入
//	//将用户输入返回回来
//}
//
//void CheckRealloc()
//{
//	//不需要扩容
//	if (g_addr_book.size < g_addr_book.capacity){
//		return ;
//	}
//	//扩容(要用临时变量保存新申请的数据)
//	//不用临时变量直接扩容然后把新数据加进去的话,原来的内存和新的内存可能不是同一块内存
//	//就可能会导致原来的内存发生数据无法找到,并且发生内存泄漏
//
//	g_addr_book.capacity *= 2;
//	PersonInfo* tmp = (PersonInfo*)malloc(sizeof(PersonInfo)*g_addr_book.capacity);
//	for (int i = 0; i < g_addr_book.size; i++)
//	{
//		tmp[i] = g_addr_book.preson_info[i];
//	}
//	free(g_addr_book.preson_info);
//	g_addr_book.preson_info = tmp;
//}
//
//void ADDPersonInfo()
//{
//	//添加一个用户信息
//	//提示并输入对应数组
//	CheckRealloc();
//	printf("添加一个新用户!\n");
//	printf("请输入用户名:\n");
//	scanf("%s", g_addr_book.preson_info[g_addr_book.size].name);
//	printf("请输入电话号码:\n");
//	scanf("%s", g_addr_book.preson_info[g_addr_book.size].phone);
//	++g_addr_book.size;
//	printf("插入成功!\n");
//	return;
//}
//
//void DELersonInfo()
//{
//	printf("删除指定记录!\n");
//	printf("请输入要删除的编号:\n");
//	int num = 0;
//	scanf("%d", &num);
//	if (num < 0 || num >= g_addr_book.size)
//	{
//		printf("输入非法,删除失败!\n");
//		return;
//	}
//	//此时采取的比较简单的方案
//	//1.如果用户要删除的是最后一个元素 那么直接--size
//	//2.中间位置,先和最后一个交换,再--size
//	if (num != g_addr_book.size - 1)
//	{
//		strcpy(g_addr_book.preson_info[num].name, g_addr_book.preson_info[g_addr_book.size - 1].name);
//		strcpy(g_addr_book.preson_info[num].phone, g_addr_book.preson_info[g_addr_book.size - 1].phone);
//	}
//	--g_addr_book.size;
//	printf("删除成功!\n");
//}
//
////修改某个用户信息,用户输入一个进行修改的编号,根据编号进行修改
//void MODIFYPersonInfo()
//{
//	printf("修改指定记录!\n");
//	printf("请输入要修改的编号:\n");
//	int num = 0;
//	scanf("%d", &num);
//	if (num < 0 || num >= g_addr_book.size)
//	{
//		printf("输入非法,修改失败!\n");
//		return;
//	}
//
//	printf("请输入用户名:\n");
//	scanf("%s", g_addr_book.preson_info[num].name);
//	printf("请输入电话号码:\n");
//	scanf("%s", g_addr_book.preson_info[num].phone);
//	printf("修改成功!\n");
//}
//
////查找用户名对应的电话号码
//void FINDPersonInfo()
//{
//	printf("请输入想查找的用户名:\n");
//	char name[1024] = { 0 };
//	scanf("%s", &name);
//	for (int i = 0; i < g_addr_book.size; i++)
//	{
//		if (strcmp(name, g_addr_book.preson_info[i].name) == 0)
//		{
//			printf("找到了!\n");
//			printf("电话号码是 %s\n", g_addr_book.preson_info[i].phone);
//			return;
//		}
//	}
//	printf("没找到!\n");
//}
//
//void PRINTPersonInfo()
//{
//	printf("打印所有用户信息!\n");
//	for (int i = 0; i < g_addr_book.size; ++i)
//	{
//		printf("[%d] ", i);
//		printf("%s", g_addr_book.preson_info[i].name);
//		printf(" %s\n", g_addr_book.preson_info[i].phone);
//	}
//	printf("打印完成!共打印了%d条记录!\n", g_addr_book.size);
//}
//
//void CLEARPersonInfo()
//{
//	printf("你确定要删除所有数据吗?1.yes 2.no \n");
//	int i = 0;
//	scanf("%d", &i);
//	if (i == 1)
//	{
//		g_addr_book.size = 0;
//		printf("清除成功!\n");
//		return;
//	}
//	else
//		printf("保留成功!\n");
//}
//
//
////读写方式要一致
//
//void Save()  //程序退出之前保存
//{
//	FILE *fp = fopen("../test.txt", "w");
//	if (fp == NULL)
//	{
//		printf("文件打开失败!保存失败!\n");
//		return;
//	}
//	for (int i = 0; i < g_addr_book.size; ++i)
//	{
//		fwrite(&g_addr_book.preson_info[i], sizeof(PersonInfo), 1, fp);
//	}
//
//	fclose(fp);
//	printf("文件保存成功!,保存了%d条数据\n", g_addr_book.size);
//}
//
//void Load()  //程序启动时候 加载
//{
//	FILE *fp = fopen("../test.txt", "r");
//	if (fp == NULL)
//	{
//		printf("失败\n");
//		return;
//	}
//	PersonInfo tmp = { 0 };
//	//fread返回值是实际读到元素个数
//	//此处fread要么是1 要么是0
//	while (fread(&tmp, sizeof(tmp), 1, fp))
//	{
//		//扩容
//		g_addr_book.preson_info[g_addr_book.size] = tmp;
//		++g_addr_book.size;
//	}
//	fclose(fp);
//	printf("开始加载,加载成功了 %d 条数据\n", g_addr_book.size);
//}
//
//int main()
//{
//	//1.先创建一个通讯录的变量, 并且需要初始化这个变量
//	Init();
//	Load();
//	while (1){
//		int choice = Menu();
//		//2.进入循环,打印一个用户菜单,并且提示用户进行操作
//		//增删查改
//		//3.用户输入相应的编号之后,就调用对应的操作函数,完成具体的增删改查
//		switch (choice)
//		{
//		case ADD:     //1
//			ADDPersonInfo();
//			Save();
//			break;
//		case DEL:     //2
//			DELersonInfo();
//			Save();
//			break;
//		case MODIFY:  //3
//			MODIFYPersonInfo();
//			Save();
//			break;
//		case FIND:    //4
//			FINDPersonInfo();
//			break;
//		case PRINT:   //5
//			PRINTPersonInfo();
//			break;
//		case CLEAR:   //6
//			CLEARPersonInfo();
//			break;
//		case EXIT:    //0
//			printf("goodbye!");
//			Save();
//			return 0;
//		default:
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}