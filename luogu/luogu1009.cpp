//阶乘的和
#include<iostream>
#include<cstring>
using namespace std;
int a[1005],b[1005],c[1005],d[1005];
int main(){
	int n;
	cin>>n;
	a[1]=1;
	b[1]=1;
	int la,lb,lc;
	lb=1;
	la=1;
	for(int m=1;m<=n;m++){
		//c作为中间的数组拿到每次的a,b乘法
		for(int j=1;j<=lb;j++){
			for(int i=1;i<=la;i++){
				c[i+j-1]+=a[i]*b[j];
				c[i+j]+=c[i+j-1]/10;
				c[i+j-1]%=10;
			}
		}
		lc=la+lb;
		//消去前导0
		while(c[lc]==0&&lc>1)lc--;
		//传给a和d累加同时重置c为0
		for(int i=1;i<=lc;i++){
			a[i]=c[i];
			d[i]+=c[i];
			d[i+1]+=d[i]/10;
			d[i]%=10;
			c[i]=0;
		}
		la=lc;
		b[1]++;
		b[2]+=b[1]/10;
		if(b[2]!=0){
			lb=2;
		}
		b[1]%=10;
	}
	if(d[la+1]>0)la++;
	for(int i=la;i>=1;i--){
		cout<<d[i];
	}
	return 0;
}
