#include <stdio.h>     
#include <string.h>     
#include <windows.h>     
#include <sql.h>     
#include <sqlext.h>     
#include <sqltypes.h>     
#include <odbcss.h> 

//��ų��м�����Ľṹ��
typedef struct CityMsg{
	char	city[50];	//����	city
	char	lon[50];	//����	longitude
	char	lat[50];	//γ��	latitude
	struct CityMsg	*next;		//��һ�ڵ�
}CityMsg;

//��������
CityMsg * nextNood(CityMsg * );//�������� ����
CityMsg * getCityMsg();		//��ȡ���м����� ����

//��������
CityMsg * nextNood(CityMsg * oldCM)
{
	//β�巨
	CityMsg * newCM;
	newCM = (CityMsg *)malloc(sizeof(CityMsg));//Ϊ�½ڵ㿪�ٿռ�
	newCM->next = NULL;	//��ʼ���½ڵ�
	oldCM->next = newCM;
	return newCM;	//�����½ڵ�
}

//��ȡ���м�����
CityMsg * getCityMsg()
{
	CityMsg * head,		//ͷָ�� 
			* citymsg;	//��ų��м�����Ľṹ��
	FILE *fp;			//�ļ�ָ��->��ų��м�������ļ�
	
	head = (CityMsg *)malloc(sizeof(CityMsg));//Ϊͷָ�뿪�ٿռ�
	citymsg = (CityMsg *)malloc(sizeof(CityMsg));//Ϊ�׽ڵ㿪�ٿռ�
	head->next = citymsg;			//��ʼ��ͷָ��
	citymsg->next = NULL;			//��ʼ���׽ڵ�

	fp = fopen("CityCoord.txt","rt");//���Դ��ļ�
	if(fp == NULL){					//���򲻿���������Ϣ���˳�
		printf("Cannot Open This File,Press Any Key to Exit.\n");
		getchar();
		exit(1);
	}
	while(!feof(fp)){		//ѭ����ȡ���м�������Ϣ��ֱ���ļ�ĩβ
		fscanf(fp,"%s %s %s",citymsg->city,citymsg->lon,citymsg->lat);//������м�����
		citymsg = nextNood(citymsg);								//���ٲ�ָ����һ�ڵ�
	}
	return head;
}
