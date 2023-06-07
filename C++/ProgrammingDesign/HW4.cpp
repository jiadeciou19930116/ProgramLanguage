/* HW4 Complexity and Graphs 
 * Problem 5 Shortest path implementation
 */
#include<iostream>
#include<iomanip>
using namespace std;

const int outOfDistance = 101;

int findShortestPath(int numofV, int s, int d, int** distanceMatrix);

int main()
{
	int numofVertices = 0;
	int numofEdge = 0;
	int source = 0;
	int destination = 0;
	cout << "Please input number of vertices, number of edges, source and destination vertex: ";
	cin >> numofVertices >> numofEdge >> source >> destination;
	source--; // difference between array index and vertex index
	destination--; // difference between array index and vertex index
	
	int** disMatrix = new int*[numofVertices]; // Distance Matrix
	for(int i = 0; i < numofVertices; i++)
	{
		disMatrix[i] = new int[numofVertices];
		
		for(int j = 0; j < numofVertices; j++)
		{
			disMatrix[i][j] = 0;
		}
	}
	
	cout << "Please in put the distance matrix (-1 for the same vertix):" << endl;
	for(int i = 0; i < numofVertices; i++)
	{
		for(int j = 0; j < numofVertices; j++)
		{
			cin >> disMatrix[i][j];
			if(i == j)
				disMatrix[i][j] = 0;
			if(disMatrix[i][j] < 0)
				disMatrix[i][j] = outOfDistance;
		}
	}
	
	cout << "The shortest distance from source to destination is: " 
			<< findShortestPath(numofVertices, source, destination, disMatrix) << "." << endl;
	
	for(int i = 0; i < numofVertices; i++)
	{
		delete [] disMatrix[i];
	}
	delete [] disMatrix;
	
	return 0;
}

int findShortestPath(int numofV, int s, int d, int** distanceMatrix)
{
	for(int i = 0; i < numofV; i++)
	{
		for(int j = 0; j < numofV; j++)
		{
			if(distanceMatrix[s][i] > distanceMatrix[s][j] + distanceMatrix[j][i])
				distanceMatrix[s][i] = distanceMatrix[s][j] + distanceMatrix[j][i];
		}
	}
	return distanceMatrix[s][d];
};
