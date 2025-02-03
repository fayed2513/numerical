#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x, y) uniform_real_distribution<double>(x, y)(rng)
class newtonRapson
{
private:
    float x1, x2, e;
    float func(float x)
    {
        return x * x * x - 2 * x - 5;
    }
    float derivative_func(float x)
    {
        return ((3 * x * x) - 2);
    }
    float posi, neg;
    void generateRandom()
    {
        float left = -10.0, right = 10.00;
        do
        {
            posi = rng(left, right);
            neg = rng(left, right);
        } while (func(posi) * func(neg) > 0);
        x2 = min(abs(posi), abs(neg));
    }

public:
    newtonRapson(float e) : e(e)
    {
        generateRandom();
    }
    float findroot()
    {
        do
        {
            x1 = x2;
            float h = func(x1) / derivative_func(x1);
            x2 = x1 - h;
        } while (abs(x2 - x1) > e);
        return x2;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    float e;
    cin >> e;
    newtonRapson bi(e);
    float root = bi.findroot();
    cout << root;
    return 0;
}