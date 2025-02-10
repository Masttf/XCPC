//快速幂取余
#include<iostream>
using namespace std;
int solve(int a,int b,int p){
	long long base=a,ans=1%p;
	while(b>0){
		if(b&1){
			ans*=base;
			ans%=p;
		}
		base*=base;
		base%=p;
		b>>=1;
	}
	return ans;
}
int main (){
	int a,b,p;
	cin>>a>>b>>p;
	cout<<a<<'^'<<b<<" mod "<<p<<'='<<solve(a,b,p);
	return 0;
}
