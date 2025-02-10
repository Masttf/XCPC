#include<bits/stdc++.h>
using namespace std;
bool isprime[100000005];
bool isPalindromes[100000005];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	isprime[1]=true;
	int a,b;
	cin>>a>>b;
	if(b>=9989899){
		b=9989899;
	}
	for(int i=2;i*i<b;i++){
		if(!isprime[i]){
			for(int j=i*i;j<=b;j+=i){
				isprime[j]=true;
			}
		}
	}
	//枚举回文数//枚举四位产生最多9位回文数
	for(int i=1;i<=9989;i++){
		int dit=0,tot=0;
		int x=i,r1=i,r2=i;
		while(x){
			dit=x%10;
			r1=r1*10+dit;
			if(tot!=0){
				r2=r2*10+dit;
			}
			tot=1;
			x/=10;
		}
		isPalindromes[r1]=true;
		isPalindromes[r2]=true;
	}
	for(int i=a;i<=b;i++){
		if(!isprime[i]&&isPalindromes[i]){
			cout<<i<<'\n';
		}
	}
	return 0;
}
