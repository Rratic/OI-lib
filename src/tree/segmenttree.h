#include "../base/base.h"
namespace OIalgo{
template<const size_t len,class ValType=ll>// 线段树 [Luogu P3372,3373]
class SegmentTree{
    public:
    size_t ls(size_t x){return x/2;}
    size_t rs(size_t x){return x/2|1;}// 保证不论奇偶都能正常使用
};
};
