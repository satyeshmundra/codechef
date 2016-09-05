#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<long long> fac;
map<long long, long long> M;

long long power(long long r, long long y)
{
    if(y == 0)
        return 1;
    else
    {
        long long p = power(r, y/2);
        p = (p*p)%MOD;
        if(y%2==0)
            return p;
        else
            return (r*p)%MOD;
    }
}

long long inverse(long long r)
{
    return power(r, MOD-2)%MOD;
}

long long getncr(long long n, long long start)
{
    long long ncr = fac[n];
    long long ans, ans1, ans2;

    ans1 = M[fac[start]];
    ans2 = M[fac[n-start]];

    ans = (ans1*ans2)%MOD;

    ncr = (ncr*ans)%MOD;
    return ncr;
}

void ways(long long n, long long k)
{
    long long start, i;
    long long ncr, res = 0;

    if(k%2 == 0)
    {
        start = 0;
        ncr = 1;
    }
    else
    {
        start = 1;
        ncr = n;
    }
    res = ncr;
    start += 2;

    while(start <= k && start <= n)
    {
        ncr = getncr(n, start);
        res += ncr;
        res = res%MOD;
        start += 2;
    }

    cout<<(res%MOD)<<endl;
}

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long t, i, j, n, k;
    cin>>t;
    long long ele;

    fac.push_back(1);
    for(i=1;i<=100000;i++)
    {
        long long ele = fac[i-1]%MOD * i;
        ele = ele%MOD;
        fac.push_back(ele);

        if(M.find(ele) == M.end())
            M[ele] = inverse(ele);
    }

    long long tmp;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        tmp = n;
        bool flag = false;
        for(j=0;j<n;j++)
        {
            cin>>ele;
            if(ele == 0)
            {
                tmp--;
                flag = true;
            }
        }
        if(flag)
            tmp++;
        ways(tmp,k);
    }

    return 0;
}
