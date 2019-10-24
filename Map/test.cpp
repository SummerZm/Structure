/*************************************************************************
 > File Name: test.cpp
 > Author: Leafxu
 > Created Time: 2019年10月24日 15:26:19
 ************************************************************************/
 #include<iostream>
 using namespace std;

 class A{
	public:
		A(int val):a(val){};
		//int&  getA() {  cout<<"Call referenct!: "<<a<<endl; return a;};
		int  getA() {  cout<<"Call val"<<a<<endl; return a;};

	private:
		int a;
 };

 int main(int argc, char** argv)
 {
	A a(10);
	int b=a.getA();
	b = 100;
	a.getA();
	return 0;
 }
