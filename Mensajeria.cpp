//https://omegaup.com/arena/problem/OMI-2017-Mensajeria#problems
#include<iostream>
#define MAX(a,b) (a>b?a:b)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,s=0,a,x,m=-1;
    cin>>n>>k;
    for(x=0;x<n;x++)
        {
        cin>>a;
        s+=(a<k?a:k);
        m=MAX(m,a);
        }
    if(m<k)
        s+=k-m;
    cout<<s<<endl;
    return 0;
}
