#include<iostream>
using namespace std;

int napadas[101][101],napadillas[101][101];

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};

int DFS(int x,int y)
{
	if(!napadillas[x][y])
		napadillas[x][y]=DFS(x+X[napadas[x][y]],y+Y[napadas[x][y]]);
	return napadillas[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,x,y,k=1,i,j;
	cin>>n>>m>>x>>y;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			{
			cin>>napadas[i][j];
			if(napadas[i][j]==-1)
				napadillas[i][j]=k++;
			}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(napadillas[i][j]==0)
				DFS(i,j);
	x--;
	y--;
	for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
			{
			if(napadillas[i][j]==napadillas[x][y])
				cout<<"1 ";
			else
				cout<<"0 ";
			}
		cout<<endl;
		}
	return 0;
}
