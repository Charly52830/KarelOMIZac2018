//https://omegaup.com/arena/problem/OMI-2017-Operaciones#problems
#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t,s=0,x,i;
    string napadas;
    char c;
    cin>>n>>napadas;
    napadas="0"+napadas;
    for(x=0;x<=n&&napadas[x]=='0';x++);
    i=x;
    c='0';
    t=0;
    for(x=n;x>i;x--,s++)
        {
        if(napadas[x]==c)
            {
            if(c=='1')
                t++;
            }
        else
            {
            if(c=='1')
                {
                s++;
                if(t>1)
                    c='0';
                }
            c=!(c-48)+48;
            t=1;
            }
        }
    if(c=='1')
        {
        s++;
        if(t>1)
            s++;
        }
    cout<<s<<endl;
    return 0;
}
