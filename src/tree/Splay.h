#ifndef OI_SPLAY
#define OI_SPLAY
#include "../base/base.h"
namespace OIalgo{
/*
推荐阅读 [洛谷日报 #62](https://www.luogu.com.cn/blog/tiger0132/slay-notes)
Splay是一种经典的BST（二分搜索树），维护【左子树任意节点的值<根节点的值<右子树任意节点的值】
*/
template<size_t len,class ValType=ll>
class Splay{
    public:
    size_t rt;// 根节点编号
    size_t tot;// 节点个数
    array<size_t,len> fa;// 父亲编号
    array<array<size_t,len>,2>ch;// 左右孩子编号（0=左 1=右）
    array<ValType,len>val;// 节点权值
    array<size_t,len>cnt;// 存储的重复权值个数
    array<size_t,len>size;// 子树下存储的权值数（包括重复权值）
    size_t chk(size_t x){// 查询左还是右
        return ch[1][fa[x]]==x;
    }
    void push_up(size_t pl){
        size[x]=size[ch[0][x]]+size[ch[1][x]]+cnt[x];
    }
};
};
#endif