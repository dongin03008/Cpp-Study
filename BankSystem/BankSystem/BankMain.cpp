/*
* Banking System Ver 0.1
* �ۼ��� : ������
* ���� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
*/
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void); //�޴����
void MakeAccount(void); //���°����� ���� �Լ�
void DepositMoney(void); //�Ա�
void WithdrawMoney(void); //���
void ShowAllAccInfo(void); //�ܾ���ȸ

enum {MAKE=1,DEPOSIT,WITHDRAW,INQUIRE,EXIT};

typedef struct 
{
	int accID; //���¹�ȣ
	int balance; //�ܾ�
	char cusName[NAME_LEN]; //���̸�
}Account;

Account acccArr[100];
int accNum = 0;

int main(void) 
{
	int choice;

	while (1) 
	{
		ShowMenu();
		cout << "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
			break;
		default:
			cout << "Illegal selection." << endl;
		}
	}
	return 0;
}
void ShowMenu(void) 
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void MakeAccount(void) 
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << endl;

	acccArr[accNum].accID = id;
	acccArr[accNum].balance = balance;
	strcpy_s(acccArr[accNum].cusName, name);
	accNum++;
}
void DepositMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (acccArr[i].accID == id)
		{
			acccArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}
void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (acccArr[i].accID == id)
		{
			if (acccArr[i].balance < money)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			acccArr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
}
void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++) 
	{
		cout << "����ID : " << acccArr[i].accID << endl;
		cout << "�̸� : " << acccArr[i].cusName << endl;
		cout << "�ܾ� : " << acccArr[i].balance << endl << endl;
	}
}