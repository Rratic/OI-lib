#include "../base/base.h"
namespace OIalgo{
template<const size_t len>
class DisjointSetUnion{// 并查集 [Luogu P3367]
    public:
    array<size_t,len>fa;
    void init(size_t n){
        for(size_t i=1;i<=n;++i)fa[i]=i;
    }
    size_t find(size_t x){
        if(x==fa[x])return x;
        return fa[x]=find(fa[x]);// 路径压缩
    }
    void merge(size_t a,size_t b){
        a=find(a);b=find(b);
        fa[a]=b;
    }
    size_t count(size_t left=1,size_t right=len-1){
        size_t c=0;
        for(size_t i=left;i<=right;++i){
            if(fa[i]==i)++c;
        }
        return c;
    }
};
};
