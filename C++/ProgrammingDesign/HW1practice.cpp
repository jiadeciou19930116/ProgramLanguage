#include<iostream>
#include<iomanip>
using namespace std;

const int legMarAge[2] = {16, 18}; //Female and Male legal marriage age.
void problem1();
void problem2();
void problem3();

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
			case 2 :
				problem2();
				break;
			case 3 :
				problem3();
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
/* 輸入一對情侶的年齡(順序由使用者決定)，判斷兩者是否都大於法定結婚歲數，
 * 回傳他們是否可以結婚。
 * 男性法定結婚年齡為18歲，女性16歲，可多元成家。
 */	
	bool gender[2] = {0};
       	int age[2] =  {0};
	cout << endl << "問題1是用來判斷兩個人的年齡能不能合法結婚。" << endl
		 << "請連續輸入兩人的性別和年齡，中間空白鍵相隔。男性請輸入1, 女性請輸入0。" << endl
		 << "例如兩位男性結婚，輸入方式為：" << endl
		 << "1 25 1 30" << endl
		 << "現在請輸入兩位結婚人的性別與年齡：" << endl;
	cin >> gender[0] >> age[0] >> gender[1] >> age[1];
	for(int i = 0; i < 2; i++)
	{
		if(age[i] < legMarAge[static_cast<int>(gender[i])])
		{
			cout << "第" << i+1 << "位現年" << age[i] << "歲,未達法定結婚年齡喔！"
				<< "必須滿" << legMarAge[static_cast<int>(gender[i])]
				<< "才能結婚喔！" << endl;
			return;
		}
	}
	cout << "兩個人都符合法定結婚年齡，可以結婚喔～" << endl;
	return;
};

void problem2()
{
/*Converging to 1?
 *Input an integer, if it is odd, multiply it by 3 and then add it by 1;
 *if it is even, divide it by 2.
 *Repeat until it become 1.
 *我想加入一個參數用來控制每行印出的數字，另外還想控制每個數字的寬度，讓他們對齊。
 */
	int num = 0;
	int count = 0;
	cout << "請輸入一個整數：" << endl;
	cin >> num;
	while(num != 1)
	{
		if(num % 2)
		{
			num = num * 3 + 1;
		}
		else
		{
			num /= 2;
		}
		cout << setw(10) << num << " ";
		count = count % 10 + 1;
		if(count == 10)
			cout << endl;
	}
	return;
};

void problem3()
{
/*Monopoly pricing
 *The demand of the product is
 * demand = base demand - price sensitivity * price
 * profit = (base demand - price sensitivity * price)(price - cost)
 * Given demand, base demand, cost, find the maximun profit.
 */
	int baseDemand = 0;
	int priceSen = 0;
	int cost = 0;
	
	int demand = 0;
	int perProfit = 0; //profit per good
	int totProfit = 0; //profit for all goods
	int bestPrice = 0;
	int maxProfit = 0;
	
	cout << "Please input demand, price sensity and cost, seperate by space." << endl;
	cin >> baseDemand >> priceSen >> cost;
	for(int price = cost + 1; price <= baseDemand / priceSen; price++)
	{
		demand = baseDemand - priceSen * price;
		perProfit = price - cost;
		totProfit = demand * perProfit;
		if( totProfit > maxProfit)
		{
			maxProfit = totProfit;
			bestPrice = price;
		}
	}
	cout << bestPrice << " " << maxProfit;
	return;
};
