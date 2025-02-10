//高精度乘法
#include<bits/stdc++.h>
using namespace std;
int a[5000],b[5000],c[5000];
int main(){
	string x,y;
	cin>>x>>y;
	int la=x.size(),lb=y.size();
	for(int i=0;i<la;i++){
		a[la-i]=x[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=y[i]-'0';
	}
	for(int i=1;i<=lb;i++){
		for(int j=1;j<=la;j++){
			c[i+j-1]+=b[i]*a[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		
	}
	int lc=la+lb;//乘0时需要消除前导0;判断最高位是否进位；
	while(c[lc]==0&&lc>1)lc--;
	for(int i=lc;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
