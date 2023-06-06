/* HW2 Practice
 *Programming Design In-class Practices
 *Variables and Arrays
 */
 #include<iostream>
 #include <iomanip>
 #include<cmath>
 using namespace std;
 
 float* movingAverage(int window, int phase, int magnitudeArr[]);
 float computeMAE(float predicted[] , int observed[], int simpleSize);
 
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
			case 3:
				problem3();
				break;
			case 4:
				problem4();
				break;
			default:
				cout << "Out of range, please input again.";
				break;
		}
		
	}while(proIndex);
	
 	return 0;
 }
 
 float* movingAverage(int window, int phase, int magnitudeArr[])
 {
 	int movePhase = phase - window + 1; //phase of moving window
	float* averageArr = new float[movePhase];
	for(int i = 0; i < movePhase; i++)
	{
		averageArr[i] = 0;
		for(int j = 0; j < window; j++)
		{
			averageArr[i] += magnitudeArr[i + j];
		}
		averageArr[i] /= window;
	}
	return averageArr;
 };
 
 float computeMAE(float predicted[] , int observed[], int simpleSize)
 {
 	float MAE = 0;
 	for(int i = 0; i < simpleSize; i++)
 	{
 		MAE += abs(predicted[i] - observed[i]);
	}
	MAE /= simpleSize;
	
 	return MAE;
 };
 
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
	/*Problem 3: moving average
	*/
	int windowWidth = 0;
	int phaseNum = 0;
	int movePhase = 0;
	int* demandArr = nullptr;
	float* forecastArr = nullptr;
	
	cout << "Please input the window width: ";
	cin >> windowWidth;
	cout << "Please input number of phase: ";
	cin >> phaseNum;
	
	movePhase = phaseNum - windowWidth + 1;
	demandArr = new int[phaseNum];
	
	cout << "Please input demand for every phase: ";
	for(int i = 0; i < phaseNum; i++)
	{
		cin >> demandArr[i];
	}
	
	forecastArr = movingAverage(windowWidth, phaseNum, demandArr);
	for(int i = 0; i < movePhase; i++)
	{
		cout << forecastArr[i];
		if(i < movePhase - 1)
		{
			cout << ",";
		}
		else
		{
			cout << endl;
		}
	}
	
	delete [] demandArr;
	for(int i = 0; i < movePhase; i++)
	{
		delete (forecastArr + i);
	}
	forecastArr = nullptr;
 	return;
};
 
void problem4()
{	
	/* Problem 4: choosing the window size ?
	*/
	int wwLimit = 0; // window width limit
	int phaseNum = 0;
	int movePhase = 0;
	int opWindowWidth = 0; // optimal
	float MAE = 0;
	float minMAE = 1000; //minimize MAE
	int* demandArr = nullptr;
	float* forecastArr = nullptr;
	
	cout << "Please input the window width limit: ";
	cin >> wwLimit;
	cout << "Please input number of phase: ";
	cin >> phaseNum;

	demandArr = new int[phaseNum];
	cout << "Please input demand for every phase: ";
	for(int i = 0; i < phaseNum; i++)
	{
		cin >> demandArr[i];
	}
	for(int wwl = 2; wwl <= wwLimit; wwl ++)
	{
		movePhase = phaseNum - wwl;
		forecastArr = movingAverage(wwl, phaseNum, demandArr);
		if(wwl == 2)
		{
			for(int i = 0; i < movePhase; i++)
			{
				cout << forecastArr[i];
				if(i < movePhase - 1)
				{
					cout << ",";
				}
				else
				{
					cout << endl;
				}
			}
		}
		
		MAE = computeMAE(forecastArr , demandArr + wwl, movePhase);
		if(minMAE > MAE)
		{
			minMAE = MAE;
			opWindowWidth = wwl;
		}
	}
	cout << opWindowWidth << " " << minMAE;
	
	delete [] demandArr;
	for(int i = 0; i < phaseNum - 1; i++) // The longest movePhase = phaseNum - 1
	{
		delete (forecastArr + i);
	}
	forecastArr = nullptr;
	
 	return;
};
