#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x;
    double y;
};

class NewtonBackward
{
private:
    double cal_u(double u, int n)
    {
        double res = u;
        for (int i = 1; i < n; i++)
        {
            res *= (u + i);
        }
        return res;
    }
    long long fact(int x)
    {
        long long res = 1;
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
            for (int j = n - 1; j >= i; j--)
            {
                diff[j][i] = diff[j][i - 1] - diff[j - 1][i - 1];
            }
        }

        double u = (value - v[n - 1].x) / (v[1].x - v[0].x);
        double res = diff[n - 1][0];
        for (int i = 1; i < n; i++)
        {
            res += (cal_u(u, i) * diff[n - 1][i]) / (double)fact(i);
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    NewtonBackward nb;
    vector<Point> v;
    double x, y, value;
    cin >> value;
    while (cin >> x >> y)
    {
        v.push_back({x, y});
    }
    double res = nb.newtonSolve(v, value);
    cout << res;
    return 0;
}