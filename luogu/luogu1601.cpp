//高精度加法
#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],c[1000];
//1字符串读入
//2转化为数组
//3竖式加法
//4判断最高位进位
//5倒序输出
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
	int lc=max(la,lb);
	for(int i=1;i<=lc;i++){
		c[i]+=a[i]+b[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[lc+1]>0)lc++;
	for(int i=lc;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
