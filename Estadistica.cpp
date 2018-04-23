//https://omegaup.com/arena/problem/OMI-2017-Escalones#problems
#include<iostream>
using namespace std;

int A[1000001],B[1000001],C[1000001];
typedef long long ll;

ll s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,x,k,y,i,f;
	cin>>n>>m;
	for(x=0;x<n;x++)
		cin>>A[x];
	for(x=0;x<m;x++)
		{
		cin>>k;
		C[k]=1;
		}
	for(x=m=0;x<1000001;x++)
		if(C[x])
			 B[m++]=x;
			 
	//Caso especial 1: que el primer elemento sea 0
	//Caso especial 2: que el último elemento sea 0
	//Caso especial 3: que todos sean 0
	
	if(*A==0)
		{
		for(x=1;x<n && A[x]==0;x++);
		if(x==n) //caso 3
			for(y=0;y<n;y++)
				A[y]=*B;
		else //caso 1
			{
			k=A[x];
			i=0;
			f=m-1;
			while(f-i>1)
				{
				int M=(i+f)/2;	
				if(B[M]<=k)
					i=M;
				else
					f=M;
				}
			if(abs(k-B[f]) < abs(k-B[i]))
				i=f;
			for(int j=0;j<x;j++)
				A[j]=B[i];
			}
		}
	if(A[n-1]==0) //caso 2
		{
		for(x=n-1;A[x]==0;x--);
		k=A[x];
		i=0;
		f=m-1;
		while(f-i>1)
			{
			int M=(i+f)/2;	
			if(B[M]<=k)
				i=M;
			else
				f=M;
			}
		if(abs(k-B[f]) < abs(k-B[i]))
			i=f;
		for(int j=x+1;j<n;j++)
			A[j]=B[i];
		}
	
	for(x=0;x<n;x++)
		{
		if(A[x]==0)
			{
			for(y=x+1;A[y]==0;y++);
			k=(A[x-1]+A[y])/2;
			i=0;
			f=m-1;
			while(f-i>1)
				{
				int M=(i+f)/2;	
				if(B[M]<=k)
					i=M;
				else
					f=M;
				}
			if(abs(A[x-1]-B[f])+abs(A[y]-B[f]) < abs(A[x-1]-B[i])+abs(A[y]-B[i]) )
				i=f;
			for(int j=x;j<y;j++)
				A[j]=B[i];
			s+=abs(A[x-1]-B[i])+abs(A[y]-B[i]);
			x=y;
			}
		else if(x)
			s+=abs(A[x]-A[x-1]);
		}
	cout<<s<<endl;
	for(x=0;x<n;x++)
		cout<<A[x]<<" ";
	cout<<endl;
	return 0;
}
