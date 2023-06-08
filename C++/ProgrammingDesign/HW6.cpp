/*HW 6 Classes
 */
 
 #include<iostream>
#include<iomanip>
using namespace std;



class Time
{
private:
	int hour;
	int minute;
	int second;
	
friend int whoIsEarlest(Time T1, Time T2, Time T3);
friend int whoIsLatest(Time T1, Time T2, Time T3);

public:
	Time(int h, int m, int s);
	bool isEarlierThan(Time refTime);
	void print();
};

int whoIsEarlest(Time T1, Time T2, Time T3);
int whoIsLatest(Time T1, Time T2, Time T3);

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

int main()
 {
 	int proIndex = 0;
	
	do
	{
		cout << "If you want ot leave, input 0." << endl
					<<"Otherwise, please input the problem index which you want to test (1~7): ";
 		cin >> proIndex;
 		switch (proIndex)
		{
			case 0:
				cout << "Goodbye!";
				break;
			case 1:
				problem1();
				break;
			case 2:
				problem2();
				break;
			case 3:
				problem3();
				break;
			case 4:
				problem4();
				break;
			case 5:
				problem5();
				break;
			case 6:
				problem6();
				break;
			case 7:
				problem7();
				break;
			default:
				cout << "Out of range, please input again.";
				break;
		}
		
	}while(proIndex);
	
 	return 0;
 }
 
Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

bool Time::isEarlierThan(Time refTime)
{
	/* Return true if and only if the invoking
	 * object¡¦s time is earlier than that of t.
	 */
	 int selfInSec = hour * 3600 + minute * 60 + second;
	 int refInSec = refTime.hour * 3600 + refTime.minute * 60 + refTime.second;
	 return (selfInSec < refInSec);
};

void Time::print()
{
	cout << hour << ":"	<< minute << ":" << second << endl;
}

int whoIsEarlest(Time T1, Time T2, Time T3)
{
	if(T1.isEarlierThan(T2))
	{
		if(T1.isEarlierThan(T3))
		{
			return 1;
		}
		return 3;
	}
	
	if(T2.isEarlierThan(T3))
	{
		return 2;
	}
	return 3;
};

int whoIsLatest(Time T1, Time T2, Time T3)
{
	if(T1.isEarlierThan(T2))
	{
		if(T2.isEarlierThan(T3))
		{
			return 3;
		}
		return 2;
	}
	
	if(T1.isEarlierThan(T3))
	{
		return 3;
	}
	return 1;
};
 
void problem1()
{
	/* Time::isEarlerThan()
	 */
	int h1 = 0;
	int h2 = 0;
	int h3 = 0;
	int m1 = 0;
	int m2 = 0;
	int m3 = 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	
	cout << "Please input three time moments:" << endl;
	cin >> h1 >> m1 >> s1;
	cin >> h2 >> m2 >> s2;
	cin >> h3 >> m3 >> s3;
	Time t1(h1, m1, s1);
	Time t2(h2, m2, s2);
	Time t3(h3, m3, s3);
	
	cout << whoIsLatest(t1, t2, t3) << endl;

	return;
};
void problem2()
{
	return;
};;
void problem3()
{
	return;
};;
void problem4()
{
	return;
};;
void problem5()
{
	return;
};;
void problem6()
{
	return;
};;
void problem7()
{
	return;
};;
