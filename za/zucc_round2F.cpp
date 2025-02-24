#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int mo=1e9+7;
const int N=2e5+5;
int res[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long nn,kk;
	cin>>nn>>kk;
	int n,k;
	n=nn;k=kk;
	int zcnt=0,fcnt=0;
	long long x;
	for(int i=1;i<=n;i++){
		cin>>x;
		res[i]=x;
		if(res[i]<0)fcnt++;
		else zcnt++;
	}
	int sum=1;
	sort(res+1,res+1+n);
	if(k%2==0){//如果是偶则必须正拿偶个负的拿偶个
		int left=1,right=n;
		while(k){
			//正负要有数可取
			if(zcnt>1&&fcnt>1){
				if(res[right]*res[right-1]>res[left]*res[left+1]){
					zcnt-=2;
					sum*=res[right]*res[right-1]%mo;
					sum%=mo;                                                                                                              
					right-=2;
				}
				else{
					fcnt-=2;
					sum*=res[left]*res[left+1]%mo;
					sum%=mo;
					left+=2;
				}
			}else if(zcnt>1&&fcnt<2){//正数可取
				zcnt-=2;
				sum*=res[right]*res[right-1]%mo;
				sum%=mo;
				right-=2;
			}
			else if(fcnt>1&&zcnt<2){//表示负数可取
				fcnt-=2;
				sum*=res[left]*res[left+1]%mo;
				sum%=mo;
				left+=2;
			}else{//说明正的还有一个负的还有一个
				sum*=res[left]*res[left+1]%mo;
				sum%=mo;
				sum+=mo;
			}
			k-=2;
		}
		long long s1=sum;
		cout<<s1;
	}else if(k%2!=0){//判断结果是不是正数
		if(zcnt==0){//结果为负的情况
			while(k--){
				sum*=res[n--]%mo;
				sum%=mo;
			}
			sum+=mo;
			long long s1=sum;
			cout<<s1;
		}else{
			int left=1,right=n;
			sum*=res[right--];
			sum%=mo;
			k--;
			while(k){
				//正负要有数可取
				if(zcnt>1&&fcnt>1){
					if(res[right]*res[right-1]>res[left]*res[left+1]){
						zcnt-=2;
						sum*=res[right]*res[right-1]%mo;
						sum%=mo;                                                                                                              
						right-=2;
					}
					else{
						fcnt-=2;
						sum*=res[left]*res[left+1]%mo;
						sum%=mo;
						left+=2;
					}
				}else if(zcnt>1&&fcnt<2){//正数可取
					zcnt-=2;
					sum*=res[right]*res[right-1]%mo;
					sum%=mo;
					right-=2;
				}
				else if(fcnt>1&&zcnt<2){//表示负数可取
					fcnt-=2;
					sum*=res[left]*res[left+1]%mo;
					sum%=mo;
					left+=2;
				}else{//说明正的还有一个负的还有一个
					sum*=res[left]*res[left+1]%mo;
					sum%=mo;
					sum+=mo;
				}
				k-=2;
			}
			long long s1=sum;
			cout<<s1;
		}
	}
	return 0;
}
