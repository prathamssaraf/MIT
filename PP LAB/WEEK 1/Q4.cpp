#include<iostream>
#include<string>  
using namespace std;

int main()
{
	
	string a,b,c;
	cout<<"enter the str:";
	cin>>a;	
	for(int i=0;i<a.length();i++){
		for(int j=0;j<i+1;j++){
			b= b+a[i];
		}
		
	}
	cout<<b;
	return 0;
}


