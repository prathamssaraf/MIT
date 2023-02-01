#include<iostream>
#include<string>  
using namespace std;

int main(int argc, char *argv[])
{
    int a[3][3]={{ 2,4,3},{1,5,7},{0,2,3}};
    int b[]={2,5,6};
    int c[3];
	
	for (int i=0;i<3;i++){
         c[i]=0;
    }


	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			c[i]+=(a[i][j]*b[j]);
		}
	}
	
	for (int i=0;i<3;i++){
         cout<<c[i]<<endl;
    }

	return 0;
}


