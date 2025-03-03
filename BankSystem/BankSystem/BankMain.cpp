/*
* Banking System Ver 0.1
* 작성자 : 강동인
* 내용 : OOP 단계별 프로젝트의 기본 틀 구성
*/
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void); //메뉴출력
void MakeAccount(void); //계좌개설을 위한 함수
void DepositMoney(void); //입금
void WithdrawMoney(void); //출금
void ShowAllAccInfo(void); //잔액조회

enum {MAKE=1,DEPOSIT,WITHDRAW,INQUIRE,EXIT};

typedef struct 
{
	int accID; //계좌번호
	int balance; //잔액
	char cusName[NAME_LEN]; //고객이름
}Account;

Account acccArr[100];
int accNum = 0;

int main(void) 
{
	int choice;

	while (1) 
	{
		ShowMenu();
		cout << "선택 : ";
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void MakeAccount(void) 
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
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
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (acccArr[i].accID == id)
		{
			acccArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다" << endl << endl;
}
void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (acccArr[i].accID == id)
		{
			if (acccArr[i].balance < money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			acccArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}
void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++) 
	{
		cout << "계좌ID : " << acccArr[i].accID << endl;
		cout << "이름 : " << acccArr[i].cusName << endl;
		cout << "잔액 : " << acccArr[i].balance << endl << endl;
	}
}