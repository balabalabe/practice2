//#pragma once
////����:�����ļ�
//
//
////1.�ĳɶ�̬
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////ͨѶ¼,��Ҫ�ڴ����б�ʾ���ɸ���
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
//	//ָ�������ָ��
//	PersonInfo* preson_info;
//
//	//[0,size)�����������
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
//	FIND,     //��
//	PRINT,    //��ӡ
//	CLEAR     //���
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
//	//��ӡ���û��ṩ�Ĳ���
//	printf("===============================\n");
//	printf("           1.���\n");
//	printf("           2.ɾ��\n");
//	printf("	   3.�޸�\n");
//	printf("	   4.����\n");
//	printf("	   5.��ʾ\n");
//	printf("	   6.���\n");
//	printf("	   0.�˳�\n");
//	printf("===============================\n");
//	printf("���������ѡ��:\n");
//	int choice = -1;
//	scanf("%d", &choice);
//	return choice;
//	//�����û���������
//	//���û����뷵�ػ���
//}
//
//void CheckRealloc()
//{
//	//����Ҫ����
//	if (g_addr_book.size < g_addr_book.capacity){
//		return ;
//	}
//	//����(Ҫ����ʱ�������������������)
//	//������ʱ����ֱ������Ȼ��������ݼӽ�ȥ�Ļ�,ԭ�����ڴ���µ��ڴ���ܲ���ͬһ���ڴ�
//	//�Ϳ��ܻᵼ��ԭ�����ڴ淢�������޷��ҵ�,���ҷ����ڴ�й©
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
//	//���һ���û���Ϣ
//	//��ʾ�������Ӧ����
//	CheckRealloc();
//	printf("���һ�����û�!\n");
//	printf("�������û���:\n");
//	scanf("%s", g_addr_book.preson_info[g_addr_book.size].name);
//	printf("������绰����:\n");
//	scanf("%s", g_addr_book.preson_info[g_addr_book.size].phone);
//	++g_addr_book.size;
//	printf("����ɹ�!\n");
//	return;
//}
//
//void DELersonInfo()
//{
//	printf("ɾ��ָ����¼!\n");
//	printf("������Ҫɾ���ı��:\n");
//	int num = 0;
//	scanf("%d", &num);
//	if (num < 0 || num >= g_addr_book.size)
//	{
//		printf("����Ƿ�,ɾ��ʧ��!\n");
//		return;
//	}
//	//��ʱ��ȡ�ıȽϼ򵥵ķ���
//	//1.����û�Ҫɾ���������һ��Ԫ�� ��ôֱ��--size
//	//2.�м�λ��,�Ⱥ����һ������,��--size
//	if (num != g_addr_book.size - 1)
//	{
//		strcpy(g_addr_book.preson_info[num].name, g_addr_book.preson_info[g_addr_book.size - 1].name);
//		strcpy(g_addr_book.preson_info[num].phone, g_addr_book.preson_info[g_addr_book.size - 1].phone);
//	}
//	--g_addr_book.size;
//	printf("ɾ���ɹ�!\n");
//}
//
////�޸�ĳ���û���Ϣ,�û�����һ�������޸ĵı��,���ݱ�Ž����޸�
//void MODIFYPersonInfo()
//{
//	printf("�޸�ָ����¼!\n");
//	printf("������Ҫ�޸ĵı��:\n");
//	int num = 0;
//	scanf("%d", &num);
//	if (num < 0 || num >= g_addr_book.size)
//	{
//		printf("����Ƿ�,�޸�ʧ��!\n");
//		return;
//	}
//
//	printf("�������û���:\n");
//	scanf("%s", g_addr_book.preson_info[num].name);
//	printf("������绰����:\n");
//	scanf("%s", g_addr_book.preson_info[num].phone);
//	printf("�޸ĳɹ�!\n");
//}
//
////�����û�����Ӧ�ĵ绰����
//void FINDPersonInfo()
//{
//	printf("����������ҵ��û���:\n");
//	char name[1024] = { 0 };
//	scanf("%s", &name);
//	for (int i = 0; i < g_addr_book.size; i++)
//	{
//		if (strcmp(name, g_addr_book.preson_info[i].name) == 0)
//		{
//			printf("�ҵ���!\n");
//			printf("�绰������ %s\n", g_addr_book.preson_info[i].phone);
//			return;
//		}
//	}
//	printf("û�ҵ�!\n");
//}
//
//void PRINTPersonInfo()
//{
//	printf("��ӡ�����û���Ϣ!\n");
//	for (int i = 0; i < g_addr_book.size; ++i)
//	{
//		printf("[%d] ", i);
//		printf("%s", g_addr_book.preson_info[i].name);
//		printf(" %s\n", g_addr_book.preson_info[i].phone);
//	}
//	printf("��ӡ���!����ӡ��%d����¼!\n", g_addr_book.size);
//}
//
//void CLEARPersonInfo()
//{
//	printf("��ȷ��Ҫɾ������������?1.yes 2.no \n");
//	int i = 0;
//	scanf("%d", &i);
//	if (i == 1)
//	{
//		g_addr_book.size = 0;
//		printf("����ɹ�!\n");
//		return;
//	}
//	else
//		printf("�����ɹ�!\n");
//}
//
//
////��д��ʽҪһ��
//
//void Save()  //�����˳�֮ǰ����
//{
//	FILE *fp = fopen("../test.txt", "w");
//	if (fp == NULL)
//	{
//		printf("�ļ���ʧ��!����ʧ��!\n");
//		return;
//	}
//	for (int i = 0; i < g_addr_book.size; ++i)
//	{
//		fwrite(&g_addr_book.preson_info[i], sizeof(PersonInfo), 1, fp);
//	}
//
//	fclose(fp);
//	printf("�ļ�����ɹ�!,������%d������\n", g_addr_book.size);
//}
//
//void Load()  //��������ʱ�� ����
//{
//	FILE *fp = fopen("../test.txt", "r");
//	if (fp == NULL)
//	{
//		printf("ʧ��\n");
//		return;
//	}
//	PersonInfo tmp = { 0 };
//	//fread����ֵ��ʵ�ʶ���Ԫ�ظ���
//	//�˴�freadҪô��1 Ҫô��0
//	while (fread(&tmp, sizeof(tmp), 1, fp))
//	{
//		//����
//		g_addr_book.preson_info[g_addr_book.size] = tmp;
//		++g_addr_book.size;
//	}
//	fclose(fp);
//	printf("��ʼ����,���سɹ��� %d ������\n", g_addr_book.size);
//}
//
//int main()
//{
//	//1.�ȴ���һ��ͨѶ¼�ı���, ������Ҫ��ʼ���������
//	Init();
//	Load();
//	while (1){
//		int choice = Menu();
//		//2.����ѭ��,��ӡһ���û��˵�,������ʾ�û����в���
//		//��ɾ���
//		//3.�û�������Ӧ�ı��֮��,�͵��ö�Ӧ�Ĳ�������,��ɾ������ɾ�Ĳ�
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