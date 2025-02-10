#include<bits/stdc++.h>
#define int long long
using namespace std;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res*=a;
		b>>=1;
		a*=a;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;//考虑对与一个x要活到最后，那么他要经过所有的场次都成立，
	//以1为例但他经过第一次1时必须要有一个比他小的数当他经过第二个1就要要1+2个因为另一个比他小的数也要一个比他小以此类推
	
	int cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1')cnt++;
	}
	int l=qmi(2,cnt);
	int r=qmi(2,n)-qmi(2,n-cnt)+1;
	for(int i=l;i<=r;i++)cout<<i<<' ';
	return 0;
}
