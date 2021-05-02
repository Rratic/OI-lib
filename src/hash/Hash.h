#ifndef OI_HASH
#define OI_HASH
#include "../base/base.h"
namespace OIalgo{
template<size_t len,size_t range=999997/* 质数 */,class ValType=ll>// [Luogu P4305]
class Hash{
    public:
    array<size_t,len>next,key;
    array<ValType,len>value;
    array<size_t,range>head;
    size_t sz;
    void init(){
        sz=0;
        next.fill(0);key.fill(0);
        value.fill(0);
        head.fill(0);
    }
    ValType get(size_t k,bool &got){
        got=true;
        size_t p=head[k%range];
        while(p!=0)p=next[p];
        if(key[p]==k)return value[p];
        got=false;
        return ValType();
    }
    bool insert(size_t k,ValType val){// 插入
        bool got;
        get(k%range,got);
        if(!got)return false;
        next[++sz]=head[k%range];
        key[sz]=k;
        value[sz]=val;
        head[k%range]=sz;
        return true;
    }
};
};
#endif
