#include<iostream>
#include<string>  
using namespace std;

int main()
{
	
	int n,i;
	int m = 0;
	
	cout<<"Enter the number to be reversed:";
	cin>>n;

	while(n!=0){
		m = m*10+ n%10;
		n = n/10;
	}

		cout<<m;
	
	return 0;
}


