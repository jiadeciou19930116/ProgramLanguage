#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int legMarAge[2] = {16, 18}; //Female and Male legal marriage age.
void problem1();
void problem2();
void problem3();
void problem4();

int main()
{
	int whichProblem = 1;
	while(whichProblem)
	{
		cout << "Please input the number which problem you will test: "<< endl;
	        cin >> whichProblem;
		switch(whichProblem){
			case 0 :
				cout << "See you next time!";
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
			case 4 :
				problem4();
				break;
			default:
				cout << "The number you input is out of range, please input again.";
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

void problem4()
{/*problem 4: Safe location
	*On a two-dimensional plane, there are 6 �� 6 = 36 grid points within the square
	* whose vertices are (0, 0), (5, 0), (0, 5), and (5, 5). 
	* We are given the locations of 3 snippers (x1, y1), (x2, y2), and (x3, y3).
  */
  int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int y1 = 0;
	int y2 = 0;
	int y3 = 0;
  cout << "Please input location of three snippers. Separated by one white space:" << endl;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  for(int x = 0; x < 6; x++)
  {
  	if(x == x1 or x == x2 or x == x3)
  	{
  		continue;
		}
  	for(int y = 0; y < 6; y++)
  	{
  		if(y == y1 or y == y2 or y == y3)
  		{
  			continue;
			}
			if( abs(x - x1) == abs(y - y1) or abs(x - x2) == abs(y - y2) 
				or abs(x - x3) == abs(y - y3))
			{
				continue;
			}
			cout << x << " " << y << endl;
		}
	}
	return;
};
