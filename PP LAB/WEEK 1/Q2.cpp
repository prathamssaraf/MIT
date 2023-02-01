#include<iostream>
#include<string>  
using namespace std;

int main()
{
	
	int a,b,c,d;
	int m = 0;
	
	cout<<"Enter the number A:";
	cin>>a;
	cout<<"Enter the number A:";
	cin>>b;
	cout<<"Enter the operation to be performed : 1 - addition , 2 - subtraction, 3 - multiplication, 4 - division";
	cin>>c;
	
	if(c==1){
		d = a+ b;
	}else if(c == 2){
		d = a-b;
	}else if(c == 3){
		d = a*b;
	}else if(c == 4){
		d = a/b;
	}
	
	cout<<d;
	
	return 0;
}


