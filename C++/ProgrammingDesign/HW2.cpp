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
		case 2:
				problem2();
				break;
			default:
				cout << "Out of range, please input again.";
				break;
		}
		
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
	/*Problem2: the knapsack problem
	*/
	int carry = 0;
	int numofItem = 0;
	int totalWeight = 0;
	int totalValue = 0;
	
	cout << "Please input the number of items and bag carry: ";
	cin >> numofItem >> carry;
	
	int* itemWeight = new int[numofItem];
	int* itemValue = new int[numofItem];
	bool* itemSelect = new bool[numofItem];
	
	cout << "Please input the weights of items: ";
	for(int i = 0; i < numofItem; i++)
	{
		cin >> itemWeight[i];
	}
	
	cout << "Please input the values of items: ";
	for(int i = 0; i < numofItem; i++)
	{
		cin >> itemValue[i];
	}
	
	cout << "Input 1 if the item is selected or 0 otherwise for each items: ";
	for(int i = 0; i < numofItem; i++)
	{
		cin >> itemSelect[i];
	}
	
	//solve total weight and value
	for(int i = 0; i < numofItem; i++)
	{
		if(itemSelect[i])
		{
			totalWeight += itemWeight[i];
			totalValue += itemValue[i];
		}
	}
	if(totalWeight > carry)
	{
		cout << "Out of carry!" << endl;
	}
	else
	{
		cout << "Total weight and value are " << totalWeight << " " << totalValue << "." << endl;
	}
	
	/*delete [] itemWeight;
	delete [] itemValue;
	delete [] itemSelect;
	*/
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
