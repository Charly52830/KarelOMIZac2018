//https://omegaup.com/arena/problem/OMI-2017-Logias#problems
#include<iostream>
using namespace std;
typedef long long ll;
ll f(ll n)
{
    return (n*(n-1))/2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    cout<<f(n/m)*(m-n%m)+f(n/m+1)*(n%m)<<" "<<f(n-(m-1))<<endl;
    return 0;
}
