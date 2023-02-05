#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main()
{
string a[2][4]={{ "p","c","a","p"},{"e","x","a","m"}};
int b[2][4]={{ 1,2,4,3},{2,4,3,2}};
string p;

clock_t start = clock();
for(int i=0;i<2;i++){
for(int j=0;j<4;j++){
for(int k=0;k<b[i][j];k++){
p = p + a[i][j];
}
}
}
cout<<p<<endl;
clock_t end = clock();
double time_elapsed = double(end - start) / CLOCKS_PER_SEC;
cout << "Time elapsed in seconds: " << time_elapsed;
return 0;
}
