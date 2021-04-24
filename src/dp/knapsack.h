#ifndef OI_KNAPSACK
#define OI_KNAPSACK
#include "../base/base.h"
namespace OIalgo{
/*
推荐阅读 [背包问题9讲](https://github.com/tianyicui/pack) 以及 [洛谷日报 #61](https://www.luogu.com.cn/blog/RPdreamer/bei-bao-wen-ti)

n: 数量
v[i]: 第i个物品的价值
w[i]: 第i个物品空间
c[i]: 第i个物品数量
mw: 背包大小

dp[i][j]: 前i件物品放入容量j的背包 ===优化==> dp[i]: 背包空间i时的结果
*/
template<class ValType=size_t>// 01背包 [Luogu P2925,P1049]
ValType ZeroOnePack(ValType n,ValType mw,ValType w[],ValType v[],ValType *dp){
    for(ValType i=1;i<=n;++i){
        for(ValType j=mw;j>=w[i];--j){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }// 逆序遍历，不会导致重复使用物品
        // if(dp[mw]==mw)return mw;
    }
    return dp[mw];
}

template<class ValType=size_t>// 完全背包 [Luogu P1616]
ValType CompletePack(ValType n,ValType mw,ValType w[],ValType v[],ValType *dp){
    for(ValType i=1;i<=n;++i){
        for(ValType j=w[i];j<=mw;++j){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    return dp[mw];
}

template<class ValType=size_t>// 多重背包（单调队列优化） [Luogu P1776]
ValType MultiplePack(ValType n,ValType mw,ValType w[],ValType v[],ValType c[],ValType *dp){
}

template<class ValType=size_t>// 混合背包 [Luogu P1833,P1507]
ValType MixedKnapsack(ValType n,ValType mw,ValType w[],ValType v[],ValType c[],ValType *dp){
}
};
#endif
