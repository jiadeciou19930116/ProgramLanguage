/*HW 6 Classes
 */
 
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
	static bool display;
	
friend int whoIsEarlest(Time T1, Time T2, Time T3);
friend int whoIsLatest(Time T1, Time T2, Time T3);

public:
	Time();
	Time(int h, int m, int s);
	
	static void setDisplay(bool displayFormat);
	
	bool isEarlierThan(Time refTime);
	void print();
	void printNicely();
	void printNicely(bool displayFormat);
};

class Event
{
private:
	char* name;
	Time start;
	Time end;
public:
	Event(char* n, Time s, Time t);
	Event(const Event &e);
	~Event();
	void setName(char* n);
	void printNicely();
};

bool Time::display = false;
int whoIsEarlest(Time T1, Time T2, Time T3);
int whoIsLatest(Time T1, Time T2, Time T3);

void problem1();
void problem2();
void problem3();
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

//constructors, destructors and member functions of class Time
Time::Time()
{
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
};

void Time::setDisplay(bool displayFormat)
{
	Time::display = displayFormat;
	return;
};

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
	return;
}

void Time::printNicely()
{
	cout << setfill('0') << setw(2) << hour << ":";	
	cout << setfill('0') << setw(2) << minute << ":";
	cout << setfill('0') << setw(2) << second;
	return;
};

void Time::printNicely(bool displayFormat)
{
	string amOrPm;
	if(displayFormat)
	{
		if(hour < 12)
		{
			amOrPm = "AM";
			if(hour == 0)
				hour = 12;
		}
		else
		{
			amOrPm = "PM";
			hour -= 12;
		}
	}
	cout << setfill('0') << setw(2) << hour << ":";	
	cout << setfill('0') << setw(2) << minute << ":";
	cout << setfill('0') << setw(2) << second;
	cout << " " << amOrPm;
	return;
};

//constructors, destructors and member functions of class Event
Event::Event(char* n, Time s, Time t)
{
	int num = sizeof(n);
	name = new char[num];
	memcpy(name, n, num);
	start = s;
	end = t;
};

Event::Event(const Event &e)
{
	cout << *e.name << endl;
	*name = *e.name;
	cout << *name << endl;
	start = e.start;
	end = e.end;
};

Event::~Event()
{
	delete [] name;
};

void Event::setName(char* n)
{
	*name = *n;
	return;
};

void Event::printNicely()
{
	cout << "\"" << name;
	if(name[1] == '\0')
		cout << "0"; 
	cout << "\"" << endl << left << setfill(' ') << setw(7) << "Start:";
	start.printNicely();
	cout << endl << left << setfill(' ') << setw(7) << "End:";
	end.printNicely();
	cout << endl;
};

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
	/* Problem 2: Time::printNicely()
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
	
	switch (whoIsLatest(t1, t2, t3))
	{
		case 1:
			t1.printNicely();
			break;
		case 2:
			t2.printNicely();
			break;
		case 3:
			t3.printNicely();
			break;
		default:
			break;
	}
	cout << endl;
	return;
};
void problem3()
{
	/* Problem 3: Time::displayFormat
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
	int format = 0;
	bool displayFormat = false;
	
	cout << "Please input three time moments:" << endl;
	cin >> h1 >> m1 >> s1;
	cin >> h2 >> m2 >> s2;
	cin >> h3 >> m3 >> s3;
	Time t1(h1, m1, s1);
	Time t2(h2, m2, s2);
	Time t3(h3, m3, s3);
	
	while(true)
	{
		cout << "Please input the display format is 12 or 24: ";
		cin >> format;	
		if(format == 12 or format == 24)
			break;
		cout << "The display format which you input is wrong." << endl;
	}
	if(format == 12)
		displayFormat = true;
	
	switch (whoIsLatest(t1, t2, t3))
	{
		case 1:
			t1.printNicely(displayFormat);
			break;
		case 2:
			t2.printNicely(displayFormat);
			break;
		case 3:
			t3.printNicely(displayFormat);
			break;
		default:
			break;
	}
	cout << endl;
	
	return;
};

void problem5()
{
	/* Problem 5: Event
	 */
	char n1[] = "PD";
	Event e1(n1, Time(14, 20, 0), Time(17, 20, 0));
	e1.printNicely(); // "PD"
	// Start: 14:20:00
	// End: 17:20:00
	return;
};
void problem6()
{
	/* Problem 6: Event::setName()
	 */
	char n1[] = "PD";
	Event e1(n1, Time(14, 20, 0), Time(17, 20, 0));
	e1.printNicely();
	Event e2(e1); // copy an object
	char n2[] = "Calculus";
	e2.setName(n2);
	e2.printNicely();
	e1.printNicely(); // "Calculus" ?
	// run-time error?
	
	return;
};
void problem7()
{
	return;
};
