//高精度减法
//1字符串读入
//2转数组
//3竖式减法，大的在上，小的在下
//4去前导零
//倒序输出
#include<bits/stdc++.h>
using namespace std;
string x,y;
int a[10100],b[10100],c[100100];
int main(){
	cin>>x>>y;
	int la,lb;
	la=x.size();
	lb=y.size();
	//假设a是较大的
	if(la<lb||la==lb&&x<y){
		swap(x,y);
		swap(la,lb);
		cout<<'-';
	}
	for(int i=0;i<la;i++){
		a[la-i]=x[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-i]=y[i]-'0';
	}
	for(int i=1;i<=la;i++){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
	}
	while(c[la]==0&&la>1)la--;
	for(int i=la;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
