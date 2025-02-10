n =int(input())
res1=1
res2=1
for i in range(1,n+1):
	s=input().split(" ")
	t=int(s[0])
	x=int(s[1])
	if (t==1) :
		res1=res1*x
	else : res2=res2*x

m =int(input())
res3=1
res4=1
for i in range(1,m+1):
	s=input().split(" ")
	t=int(s[0])
	x=int(s[1])
	if (t==1) :
		res3=res3*x
	else : res4=res4*x

if(res1*res4==res2*res3): print("YES")
else :print("NO")