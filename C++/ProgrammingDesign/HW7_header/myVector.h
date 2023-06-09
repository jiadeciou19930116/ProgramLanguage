// myVector.h
const double ERROR_LIMIT = 0.00001;
class MyVector
{
friend const MyVector operator+(const MyVector& v, double d);
private:
  int n; 
  double* m; 
public:
  MyVector();
  MyVector(int n, double m[]);  
  MyVector(const MyVector& v);
  ~MyVector();
  void print() const; 
  
  bool operator==(const MyVector& v) const;
  bool operator==(const double d) const;
  bool operator!=(const MyVector& v) const;
  bool operator<(const MyVector& v) const;
  double operator[](int i) const;
  double& operator[](int i);
  const MyVector& operator=(const MyVector& v);
  const MyVector& operator+=(const MyVector& v);
};

// global function headers
const MyVector operator+(const MyVector& v, double d);
const MyVector operator+(double d, const MyVector& v);
const MyVector operator+(const MyVector& v1, const MyVector& v2);
const bool operator==(double d, const MyVector& v);
