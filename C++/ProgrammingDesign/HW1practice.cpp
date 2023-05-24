#include<iostream>
#include<string>
using namespace std;

class date
{
private
	int month;
	int day;
public
};

class time
{
private
	int hour;
	int minute;
	int second;
public
};

class Human = 0 //abstract class
{
protected
	int age;
	int height;
	int weight;
	string acdQlf; // academic qualification
	string work;

public

};

class Man : public Human
{
private
	string name;
	string sexuality;

};	

void problem1();

int main()
{
	int whichProblem = 1;
	while(whichProblem)
	{
		cout << "請輸入你要測試的題號（1～4），若不測試請輸入0離開。"<< endl;
	        cin >> whichProblem;
		switch(whichProblem){
			case 0 :
				cout << "你要離開了，再見！" ;
				break;
			case 1 :
				problem1();
				break;
			default:
				cout << "你輸入的題號不存在，請重新輸入。";
				break;
		}
		cout << endl << endl;
	}
	return 0;
}

void problem1()
{
	
	cout << "問題一是用來判斷兩個人的年齡能不能合法結婚。" << endl;

	return;
};
