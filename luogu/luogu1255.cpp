#include<bits/stdc++.h>
using namespace std;
int a[10006][10006],la,lb,lc;
void sum(int c[],int b[],int n){
	la=c[0];
	lb=b[0];
	lc=max(la,lb);
	for(int i=1;i<=lc;i++){
		a[n][i]+=c[i]+b[i];
		if(a[n][i]>9){
			a[n][i+1]+=a[n][i]/10;
			a[n][i]%=10;
		}
	}
	if(a[n][lc+1])lc++;
	a[n][0]=lc;
}
int main(){
	int n;cin>>n;
	a[1][1]=a[1][0]=1;
	a[2][0]=a[2][1]=1;
	for(int i=3;i<=n+1;i++){
		sum(a[i-1],a[i-2],i);
	}
	int len=a[n+1][0];
	for(int i=len;i>=1;i--){
		cout<<a[n+1][i];
	}
	return 0;
}
