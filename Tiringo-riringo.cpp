#include<algorithm>
#include<iostream>
using namespace std;

int A[100001],B[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,x,k;
	cin>>n>>q;
	for(x=0;x<n;x++)
		cin>>A[x]>>B[x];
	sort(A,A+n);
	sort(B,B+n);
	while(q--)
		{
		cin>>k;
		int i=0,f=n;
		while(i<f)
			{
			int m=(i+f)/2;
			if(A[m]<=k)
				i=m+1;
			else
				f=m;
			}
		int a=i;
		i=-1;
		f=n-1;
		while(i<f)
			{
			int m=(i+f)/2;
			if(B[m]<k)
				{
				if(f-i>1)
					i=m;
				else
					break;
				}
			else
				f=m-1;
			
			}
		if(B[i+1]<k)
			i++;
		cout<<n-(n-a)-(i+1)<<endl;
		}
	return 0;
}
