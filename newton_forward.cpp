#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x;
    double y;
};

class NewtonForword
{
private:
    double cal_u(double u, int n)
    {
        double res = u;
        for (int i = 1; i < n; i++)
        {
            res *= (u - i);
        }
        return res;
    }
    long long fact(int x)
    {
        int res = 1;
        for (int i = x; i >= 1; i--)
        {
            res *= i;
        }
        return res;
    }

public:
    double newtonSolve(vector<Point> v, double value)
    {
        int n = v.size();
        double diff[n][n];
        for (int i = 0; i < n; i++)
        {
            diff[i][0] = v[i].y;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1];
            }
        }
        double u = (value - v[0].x) / (v[1].x - v[0].x);
        double res = diff[0][0];
        for (int i = 1; i < n; i++)
        {
            res += (cal_u(u, i) * diff[0][i]) / (double)fact(i);
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    NewtonForword nf;
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