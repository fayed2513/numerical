#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_real_distribution<double>(x,y)(rng)
class BisectionMethod{
private:
    float posi,neg,e;
float func(float x){
    return x*x-2*x-5;
}
void generateRandom(){
 float left = -10.0, right = 10.0;
        do {
            posi = rng(left, right);
            neg = rng(left, right);
        } while(func(posi) * func(neg) > 0);
        if(func(posi)<0)swap(posi,neg);
    }
public:
    BisectionMethod(float e):e(e){
        generateRandom();
    }
 float findroot(){
    float root,res;
    do{
    root = (posi + neg) / 2.0;  
     res=func(root);
    // if (abs(res) < e) return root;
     if(res>0)posi=root;
     else neg=root;
    }while(abs(res)>e);
    return root;
 }
};
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
float e;cin>>e;
BisectionMethod bi(e);
float root=bi.findroot();
cout<<root;
    return 0;
}