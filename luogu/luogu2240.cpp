#include<bits/stdc++.h>
using namespace std;
struct p{
	double m;
	double v;
}s[200];
bool cmp(p x,p y)
{
	return x.v*y.m>y.v*x.m;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i].m>>s[i].v;
	}
	sort(s+1,s+1+n,cmp);
	double sum=0;
	for(int i=1;i<=n;i++){
		if(s[i].m<=k){
			sum+=s[i].v;
			k-=s[i].m;
		}else if(k<s[i].m){
			sum+=(s[i].v/s[i].m)*k;
			break;
		}
	}
	printf("%.2f",sum);
	return 0;
}
