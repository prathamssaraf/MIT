#include<iostream>
#include<string>  
using namespace std;

int main()
{
	
	string a;
	cout<<"enter the string:";
	cin>>a;	
	for(int i=0;i<a.length();i++){
		if(64<int(a[i])<91){
			int p = int(a[i])+32;
			a[i]=char(p);
		}
		else if(96<int(a[i])<123){
			int p = int(a[i])-32;
			a[i]=char(p);
		}
	}
	cout<<a;
	return 0;
}


