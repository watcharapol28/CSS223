#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[100100];
int c[10010];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        vec[a].push_back({c,b});
        vec[b].push_back({c,a});
    }
    for(int i = 0; i < m; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    for(int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        int base = c[a-1] + c[b-1];
        (vec[a][0].first + vec[b][0].first > base)?cout << base << " 2" <<endl :cout << vec[a][0].first + vec[b][0].first<< " 4"<<endl;
    }
}