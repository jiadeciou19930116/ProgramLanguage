/*HW5  Pointers
*/
#include<iostream>
#include<iomanip>
using namespace std;

int inputGraphInfo(int** neighbors, int degrees[]);
void printGraph(int** neighbors, const int degrees[], int nodeCnt);
void releaseMemory(int** neighbors, int nodeCnt);

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6and7();

int* maxPtr(int* a, int* b)
{
	return *a > *b ? a : b;
}
int* max(int &a, int &b)
{
	int* c = &a;
	if(b > a)
		c = &b;
	return c;
}
int* max2(int a, int b)
{
	int* cPtr = new int(a);
	if(b > a)
	*cPtr = b;
	return cPtr;
}



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
				problem6and7();
				break;
			case 7:
				problem6and7();
				break;
			default:
				cout << "Out of range, please input again.";
				break;
		}
		
	}while(proIndex);
	
 	return 0;
 }
  
int inputGraphInfo(int** neighbors, int degrees[])
{
	int nodeCnt = 0;
	cout << "Please input number of vertex: ";
	cin >> nodeCnt;
	for(int i = 0; i < nodeCnt; i++)
	{
		cout << "Node " << i << "\'s degree is: ";
		cin >> degrees[i];
		neighbors[i] = new int[degrees[i]];
		cout << "Node " << i << "\'s neighbors: ";
		
		for(int j = 0; j < degrees[i]; j++)
			cin >> neighbors[i][j];
	}
	return nodeCnt;
}

void printGraph(int** neighbors, const int degrees[], int nodeCnt)
{
	for(int i = 0; i < nodeCnt; i++)
	{
		int adjListCnt = 0;
		for(int j = 0; j < nodeCnt; j++)
		{
			if(j == neighbors[i][adjListCnt])
			{
				cout << "1 ";
				adjListCnt++;
				
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << "\n";
	}
}

void releaseMemory(int** neighbors, int nodeCnt)
{
	for(int i = 0; i < nodeCnt; i++)
		delete [] neighbors[i];
}

void problem1()
{
 	/*Problem 1: See memory allocation
	 */

	int anInteger = 0;
	cout << &anInteger << endl;
	for(int i = 0; i < 10; i++)
	{
		int anotherInteger = 0;
		cout << &anotherInteger << endl;
	}
 	return;
};
 
void problem2()
{
	/* Problem 2: Modify a variable
	*/
	int num1 = 0;
	int* num1ptr = &num1;
	cout << "Please input a integer: ";
	cin >> *num1ptr;
	cout << num1 << "\n";
	return;
};
 
void problem3()
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << *maxPtr(&a, &b) << "\n";
	return;
};

void problem4()
{
	/* Problem 4: Find an error, if any
	*/
	int a = 0, b = 0;
	cin >> a >> b;
	int* maxAddr = max(a, b);
	cout << *maxAddr << "\n";
	return;
};

void problem5()
{
	/* Problem 5: Find an error, if any (2)
	*/
	int a = 0, b = 0;
	cin >> a >> b;
	int* maxAddr = max2(a, b);
	cout << *maxAddr << "\n";
	return;
};

void problem6and7()
{
	int numofNode = 0;
	cout << "Please input number of node: ";
	cin >> numofNode;
	int** neighbors = new int*[numofNode];
	int degrees[numofNode] = {0};
	int nodeCnt = inputGraphInfo(neighbors, degrees);
	printGraph(neighbors, degrees, nodeCnt);
	releaseMemory(neighbors, nodeCnt);
	return;
};

