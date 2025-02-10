#include<bits/stdc++.h>
using namespace std;
void shuchu(int n){
	int res[105],cur=0;
	int base=1;
	int cnt=0;
	while(n){
		if(n&1)res[++cur]=cnt;
		base*=2;
		n>>=1;
		cnt++;
	}
	for(int i=cur;i>=1;i--){
		if(res[i]==1)cout<<2;
		else{
			cout<<2<<'(';
			if(res[i]<=2)cout<<res[i];
			else shuchu(res[i]);
			cout<<')';
		}
		if(i!=1)cout<<'+';
	}
}
int main(){
	int n;
	cin>>n;
	shuchu(n);
	return 0;
}
