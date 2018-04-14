#include<stack>
#include<iostream>
using namespace std;

char A[256];

bool f(string s)
{
    stack<char> p;
    for(int x=0;x<s.size();x++)
        {
        if(s[x]=='(' || s[x]=='{' || s[x]=='[')
            p.push(s[x]);
        else
            {
            if(!p.empty() && p.top()==A[s[x]])
                p.pop();
            else
                return false;
            }
        }
    if(!p.empty())
        return false;
    return true;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    A['}']='{';
    A[']']='[';
    A[')']='(';
    int t;
    cin>>t;
    string s;
    while(t--)
        {
        cin>>s;
        if(f(s))
            cout<<"SI\n";
        else
            cout<<"NO\n";
        }
    return 0;
}
