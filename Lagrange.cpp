#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x;
    double y;
};

class Lagrange
{
public:
    double lagSolve(vector<Point> v, double value)
    {
        double res = 0;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            double term = v[i].y;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                term = term * (value - v[j].x) / (double)(v[i].x - v[j].x);
            }
            res += term;
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Lagrange nf;
    vector<Point> v;
    double x, y, value;
    cin >> value;
    while (cin >> x >> y)
    {
        v.push_back({x, y});
    }
    double res = nf.lagSolve(v, value);
    cout << res;
    return 0;
}