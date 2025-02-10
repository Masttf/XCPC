//高精度/单精
#include<bits/stdc++.h>
#define int long long
using namespace std;
string x;
int a[10005],la;
int b;
signed main(){
	cin>>x>>b;
	la=x.size();
	for(int i=0;i<la;i++){
		a[la-i]=x[i]-'0';
	}
	for(int i=la;i>=1;i--){
		a[i-1]+=a[i]%b*10;
		a[i]/=b;  
	}
	while(a[la]==0&&la>1)la--;
	for(int i=la;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
