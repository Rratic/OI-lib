#ifndef OI_SEGMENTTREE
#define OI_SEGMENTTREE
#include "../base/base.h"
namespace OIalgo{
template<size_t len,class ValType=ll>// 线段树 [Luogu P3372,3373]
class SegmentTree{
    public:
    ValType tag[len*4]/* 懒惰标记 */,ans[len*4];
    size_t lch(size_t x){return x*2;}
    size_t rch(size_t x){return x*2|1;}
    void push_up(size_t x){// 合并子节点信息
        ans[x]=ans[lch(x)]+ans[rch(x)];
    }
    void build(size_t pl,size_t left,size_t right,ValType *data/* 导入数据（数组） */){// 建树
        tag[pl]=0;
        if(left==right){
            ans[pl]==data[left];
            return;
        }
        size_t mid=(left+right)/2;
        build(lch(pl),left,mid,data);// 建左树
        build(rch(pl),mid+1,right,data);// 建右树
        push_up(pl);// 向上维护信息
    }
    void note(size_t pl,size_t left,size_t right,ValType val){
        tag[pl]+=val;
        ans[pl]+=k*(right-left+1);
    }
    void push_down(size_t pl,size_t left,size_t right){
        size_t mid=(left+right)/2;
        note(lch(pl),left,mid,tag[pl]);// 因为是懒惰标记，需要在此时更新数据
        note(rch(pl),mid+1,right,tag[pl]);
        tag[pl]=0;
    }
    void update(size_t left,size_t right,size_t l,size_t r,size_t pl,ValType val){// 进行改变操作
/*
[left,right]: 需要修改的区间
[l,r]: 存的区间
*/
        if(left<=l&&r<=right){// 在区间内
            ans[pl]+=val*(r-l+1);
            tag[pl]+=val;
            return;
        }
        push_down(pl,l,r);
        size_t mid=(l+r)/2;
        if(left<=mid)update(left,right,l,mid,lch(pl),val);
        if(right>=mid+1)update(left,right,mid+1,r,rch(p),val);
        push_up(pl);
    }
    ValType query(size_t left,size_t right,size_t l,size_t r,size_t pl){// 进行询问操作
        ValType anss=0;
        if(left<=l&&r<=right)return ans[pl];
        size_t mid=(left+right)/2;
        push_down(pl,l,r);
        if(left<=mid)anss+=query(left,right,l,mid,lch(pl));
        if(mid+1<=right)anss+=query(left,right,mid+1,r,rch(pl));
        return anss;
    }
};
};
#endif
