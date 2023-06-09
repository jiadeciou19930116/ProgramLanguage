// myVector.cpp

#include<iostream>
#include<cmath>
#include "myVector.h"
using namespace std;


// MyVector's instance functions
MyVector::MyVector(): n(0), m(nullptr) 
{
}

MyVector::MyVector(int n, double m[])
{
  this->n = n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = m[i];
}

MyVector::MyVector(const MyVector& v)
{
  this->n = v.n;
  this->m = new double[n];
  for(int i = 0; i < n; i++)
    this->m[i] = v.m[i];	
}

MyVector::~MyVector() 
{ 
  delete [] m; 
}

// end of MyVector's instance functions

// MyVector's overloaded operators
bool MyVector::operator==(const double d) const
{
	for(int i = 0; i < this->n; i++)
	{
		if(abs(this->m[i] - d) > ERROR_LIMIT)
			return false; 
	}
	return true;
}
// end of MyVector's overloaded operators

// global functions
const bool operator==(double d, const MyVector& v)
{
	return (v == d);
}
