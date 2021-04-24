#ifndef OI_BASE
#define OI_BASE
#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <vector>
namespace OIalgo{
using std::array;
using std::cin;
using std::cout;
using std::list;
using std::max;
using std::memset;
using std::string;
using std::system;
using std::swap;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short tocount;
void SetupFreopen(string s){
    freopen((s+".in").data(),"r",stdin);
    freopen((s+".out").data(),"w",stdout);
}
void SetupIO(){// 关闭流同步，解除绑定
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
template<class ValType>// 快速幂 [Luogu P1226]
ValType FastPow(ValType a,ValType b,ValType p){// 为提高效率，使用循环而不是递归
    a%=p;
    ValType ans=1;
    while(b>0){
		if(b%2==1)ans=ans*a%p;
		ans=ans*ans%p;
        b/=2;
    }
    return ans;
}
template<class UIntType>
string u_to_string(UIntType x){
    if(x==0)return "0";
    string s;
    while(x!=0){
        s=char('0'+x%10)+s;
        x/=10;
    }
    return s;
}
float FastInvSqrt(float number,bool accurate=false){// 平方根倒数速算法
    long i;
	float x2,y;
	const float threehalfs=1.5F;
	x2=number*0.5F;
	y=number;
	i=*(long*)&y;
	i=0x5f3759df-(i>>1);
	y=*(float*)&i;
	y=y*(threehalfs-(x2*y*y));
    if(accurate)y=y*(threehalfs-(x2*y*y));
	return y;
}
};
#endif
