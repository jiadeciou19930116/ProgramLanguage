/* HW2 Practice
 *Programming Design In-class Practices
 *Variables and Arrays
 */
 #include<iostream>
 #include <iomanip>
 using namespace std;
 
 void problem1();
 void problem2();
 void problem3();
 void problem4();
 
 int main()
 {
 	int proIndex = 0;
	
	do
	{
		cout << "If you want ot leave, input 0." << endl
					<<"Otherwise, please input the problem index which you want to test (1~4): ";
 		cin >> proIndex;
 		switch (proIndex)
		{
			case 0:
				cout << "Goodbye!";
				break;
			case 1:
				problem1();
				break;
			default:
				cout << "Out of range, please input again.";
				break;
		}
		cout << endl;
	}while(proIndex);
	
 	return 0;
 }
 
void problem1()
{
	/* Problem 1: 0.1 + 0.2 = ?
	 */
	float num1 = 0;
	float num2 = 0;
	cout << "Please input 2 float, we will show you the sumary." << endl;
	cin >> num1 >> num2;
	cout << setw(10) << num1 + num2 << "  " << setprecision(10) << num1 + num2 << endl;
 	return;
};
 
void problem2()
{
 	return;
};
 
void problem3()
{
 	return;
};
 
void problem4()
{
 	return;
};
