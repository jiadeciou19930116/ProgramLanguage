#include<iostream>
#include<iomanip>
using namespace std;

int min(int num1, int num2);
int gcd(int num1, int num2);
int gcd(int num1, int num2, int num3);
int highGradeCnt(int threshold, int gradeCnt, int* grades);
int mostHighGrades(int threshold, int assignmentCnt, int gradeCnt, int** grades);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();

int main()
 {
 	int proIndex = 0;
	
	do
	{
		cout << "If you want ot leave, input 0." << endl
					<<"Otherwise, please input the problem index which you want to test (1~5): ";
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
			default:
				cout << "Out of range, please input again.";
				break;
		}
		
	}while(proIndex);
	
 	return 0;
 }
 
int min(int num1, int num2)
{
	if(num1 < num2)
		return num1;
	return num2;
};

int gcd(int num1, int num2)
{
	if(num1 %  num2 == 0)
		return num2;
	return gcd(num2, num1 % num2);
}
int gcd(int num1, int num2, int num3)
{
	return gcd(gcd(num1,num2), num3);
}

int highGradeCnt(int threshold, int gradeCnt, int* grades)
{
	int cnt = 0;
	for(int i = 0; i < gradeCnt; i++)
	{
		if(grades[i] >= threshold)
			cnt++;
	}
	return cnt;
};

int mostHighGrades(int threshold, int assignmentCnt, int gradeCnt, int** grades)
{
	int cnt = 0;
	int maxCnt = 0;
	int opAssignment = 0;
	for(int i = 0; i < assignmentCnt; i++)
	{
		cnt = 0;
		for(int j = 0; j < gradeCnt; j++)
		{
			if(grades[i][j] >= threshold)
				cnt++;
		}
		if(cnt > maxCnt)
		{
			maxCnt = cnt;
			opAssignment = i + 1;
		}
	}
	return opAssignment;
};

void problem1()
{
	/* Problem 1: the smaller number
	*/
	int num1 = 0;
	int num2 = 0;
	cout << "Please input two integer: ";
	cin >> num1 >> num2;
	cout << min(num1, num2) << endl;
	return;
}
 
void problem2()
{
	/*Problem 2: greatest common divisor
	*/
	int num1 = 0;
	int num2 = 0;
	cout << "Please input two integer: ";
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl;
	return;
}

void problem3()
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	cout << "Please input three integer: ";
	cin >> num1 >> num2 >> num3;
	cout << gcd(num1, num2, num3) << endl;
	return;
}

void problem4()
{
	/* Problem 4: number of high grades
	*/
	int threshold = 0;
	int gradeCount = 0;
	int* grades = nullptr;
	cout << "Please input number of grades and threshold grade: ";
	cin >> gradeCount >> threshold;
	grades = new int[gradeCount];
	for(int i = 0; i < gradeCount; i++)
	{
		grades[i] = 0;
	}
	
	cout << "Please input all grades: ";
	for(int i = 0; i < gradeCount; i++)
	{
		cin >> grades[i];
	}
	
	cout << highGradeCnt(threshold, gradeCount, grades) << endl;
	
	delete [] grades;
	return;
}

void problem5()
{
	/* Problem 5: high grades of ?? assignments
	*/
	int threshold = 0;
	int gradeCount = 0;
	int assignmentCount;
	int cnt = 0; // grade counts no less then threshold for each assignment
	int opAssignment = 0;
	int** grades = nullptr;
	
	cout << "Please input number of assignments, grades and threshold grade: ";
	cin >> assignmentCount >> gradeCount >> threshold;
	grades = new int*[assignmentCount];
	for(int i = 0; i < assignmentCount; i++)
	{
		grades[i] = new int[gradeCount];
		for(int j = 0; j < gradeCount; j++)
		{
			grades[i][j] = 0;
		}
	}
	
	cout << "Please input all grades, each assignment a line:" << endl;
	for(int i = 0; i < assignmentCount; i++)
	{
		for(int j = 0; j < gradeCount; j++)
		{
			cin >> grades[i][j];
		}
	}
	opAssignment = mostHighGrades(threshold, assignmentCount, gradeCount, grades);
	cout << setw(10) << opAssignment<< endl;
	
	for(int i = 0; i < assignmentCount; i++)
	{
		delete [] grades[i];
	}
	
	return;
}
