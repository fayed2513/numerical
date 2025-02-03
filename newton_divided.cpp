#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x;
    double y;
};

class NewtonDivided
{
public:
    double newtonSolve(vector<Point> v, double value)
    {
    double res,term=1;
    int n=v.size();
    double diff[n][n];
    for(int i=0;i<n;i++){
        diff[i][0]=v[i].y;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
           diff[j][i]=(diff[j+1][i-1]-diff[j][i-1])/(v[j+i].x-v[j].x);
        }
    }
    res=diff[0][0];
    for(int i=1;i<n;i++){
        term*=(value-v[i-1].x);
res+=(term*diff[0][i]);
    }
    return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    NewtonDivided nf;
    vector<Point> v;
    double x, y, value;
    cin >> value;
    while (cin >> x >> y)
    {
        v.push_back({x, y});
    }
    double res = nf.newtonSolve(v, value);
    cout << res;
    return 0;
}