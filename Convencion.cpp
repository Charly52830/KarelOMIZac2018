//https://omegaup.com/arena/problem/OMI-2017-Pandillas#problems
#include<set>
#include<map>
#include<iostream>
using namespace std;

map<int,set<int> > lista;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,x,a,b,k,c;
	cin>>n>>m;
	for(x=0;x<m;x++)
		{
		cin>>a>>b;
		if(b<a)
			swap(a,b);
		lista[a].insert(b);
		}
	m=1;
	for(x=n-1;x>=0;x--)
		{
		if(!lista.count(x))
			{
			c=x;
			continue;
			}
		k=x;
		for(set<int>::iterator it=lista[x].begin();it!=lista[x].end();it++)
			{
			if(*it==k+1)
				k++;
			else
				break;
			}
		k=min(k,c);
		m=max(k-x+1,m);
		c=k;
		}
	cout<<m<<endl;
	return 0;
}
