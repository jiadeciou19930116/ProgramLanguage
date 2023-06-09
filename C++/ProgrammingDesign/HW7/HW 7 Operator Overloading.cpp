/*HW 7 Operator Overloading
 */
 
#include<iostream>
#include "HW7_header/myVector.h"
using namespace std;



void problem1(const MyVector &Vector);
/*
void problem2(const MyVector &Vector);
void problem3(const MyVector &Vector);
void problem5(const MyVector &Vector);
void problem6(const MyVector &Vector);
void problem7(const MyVector &Vector);
*/
int main()
 {
 	int dimention = 0;
 	cout << "Please input vector dimention: ";
 	cin >> dimention;
 	double* magnitude = new double[dimention]; 
 	for(int i = 0; i < dimention; i++)
 	{
 		magnitude[i] = 0;
	}
 	
 	cout << "Please input vector magnitude, separate by white space:" << endl;
 	for(int i = 0; i < dimention; i++)
 	{
 		cin >> magnitude[i];
	}
 	
	 MyVector v(dimention, magnitude);
	
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
				problem1(v);
				break;
			/*
			case 2:
				problem2(MyVector Vector);
				break;
			case 3:
				problem3(MyVector Vector);
				break;
			case 5:
				problem5(MyVector Vector);
				break;
			case 6:
				problem6(MyVector Vector);
				break;
				*/
			default:
				cout << "Out of range, please input again.";
				break;
		}
		
	}while(proIndex);
	
	delete [] magnitude;
 	return 0;
 }
 
void problem1(const MyVector &Vector)
{
	double reference = 0;
	cout << "Please input reference value: ";
	cin >> reference;
	if(Vector == reference)
	{
		cout << "Vector is equal to reference." << endl;
	}
	else
	{
		cout << "Vector isn't' equal to reference." << endl;
	}
	
	return;
};
/*
void problem2(MyVector Vector)
{
	return;
};
void problem3(MyVector Vector){
	return;
};
void problem5(MyVector Vector)
{
	return;
};
void problem6(MyVector Vector)
{
	return;
};
void problem7(MyVector Vector)
{
	return;
};
*/

