#include<iostream>
using namespace std;

class Test
{
public:
	Test();
	~Test();
};

Test::Test(void)
{
	cout<<"Test is being created"<<endl;
}
Test::~Test(void)
{
    cout << "Test is being deleted" << endl;
}

class Math: public Test
{
public:
  Math();
	~Math();
};

Math::Math(void)
{
	cout<<"Math is being created"<<endl;
}
Math::~Math(void)
{
    cout << "Math is being deleted" << endl;
}
int main()
{
	Math t;
	return 0;
}