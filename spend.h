#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*�������������һ����ѧ���������ѹ���ϵͳ����Ҫʵ�ֶԴ�ѧ��ÿ�µĸ���ѽ��й���
	�������Ѽ�¼��¼�롢�޸ġ���ѯ��ɾ��������ͳ�ƺ�����Ĺ��ܡ�
	������Ҫ�����Է����ѡ��绰���ѡ����黨�ѡ����λ��ѡ��������ѡ��ڹ���ѧ���롢����֧���ȡ�*/
	
struct Student{//���ṹ��
	int month;//�·�
	char season[6];//����
	int foodSpend;//�Է�����
	int phoneSpend;//�绰����
	int bookSpend;//��������
	int otherSpend;//��������
	int workStudyIncome;//�ڹ���ѧ����
	int totalSpend;//����֧��
	int state;//״̬--ѧ���Ƿ�����У��¼���ѣ�1��¼ 0����¼�����ܲ���ѧУ��
};

//����ṹ������洢ѧ��������Ϣ
struct Student Spends[20];

//�����ļ�ָ�룬�����ļ�
FILE *fp;

//����洢��ǰ���������
int maxIndex = -1;
//��������
//��ҵ��
//1.¼��ѧ��������Ϣ
void addStudentSpend();
//2.ɾ��ѧ��������Ϣ
void deleteStudentSpend();
//3.����ѧ��������Ϣ
void searchStudentSpend();
//4.�޸�ѧ��������Ϣ
void updateStudentSpend();
void queryByMonth();
void queryBySeason();
//void queryByName();
//5.��ӡѧ��������Ϣ
void printfStudentSpend();
//6.ѧ�����ѷ���
void analysisSyudentSpend();
void getMaxSpend();
void getAvgSpend();
//����ҵ��
//7.���ļ�
int readData();
//8.д�ļ�
int writeData();
//9.�Զ������·�
int createMonth();
//10.�����·ݲ�������
int findIndex(int month);
//11.��ʾ��ǰѧ��������Ϣ
void printCurrentSpend(int index);
//12.��ӭ����
int welcome();
//13.���˵�
void mainMenu();