#ifndef OI_SPLAY
#define OI_SPLAY
#include "../base/base.h"
namespace OIalgo{
/*
推荐阅读 [洛谷日报 #62](https://www.luogu.com.cn/blog/tiger0132/slay-notes)
Splay是一种经典的BST（二叉搜索树），维护任意A：A的左子树任意节点的值<A的值<A的右子树任意节点的值
[Luogu P3369]
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
    void init(){
        rt=0;tot=0;
        fa.fill(0);
        ch[0].fill(0);ch[1].fill(0);
        val.fill(0);
        cnt.fill(0);
        size.fill(0);
    }
    size_t chk(size_t x){// 查询左还是右
        return ch[1][fa[x]]==x;
    }
    void push_up(size_t x){
        size[x]=size[ch[0][x]]+size[ch[1][x]]+cnt[x];
    }
/*
为了使splay保持平衡而进行旋转操作，旋转的本质是将某个节点上移一个位置
旋转需要保证：
* 整棵splay的中序遍历不变（不能破坏二叉查找树的性质）
* 受影响的节点维护的信息依然正确有效。
* root必须指向旋转后的根节点。

旋转分为两种：左旋和右旋

右旋
1. 将y的左儿子指向x的右儿子，且x的右儿子（如果x有右儿子的话）的父亲指向y
2. 将x的右儿子标为y，且y的父亲指向x
3. 如果原来的y还有父亲z，那么把z的某个儿子（原来y所在的儿子位置）指向x，且x的父亲指向z
*/
    void rotate(size_t x){
        size_t y=fa[x],z=fa[y],k=chk(x),w=ch[k^1/* 取反 */][x];
        ch[k][y]=w;
        fa[w]=y;
        ch[chk(y)][z]=x;
        fa[x]=z;
        ch[k^1][x]=y;
        fa[y]=z;
        push_up(y);
        push_up(x);
    }
    void splay(size_t x,size_t goal=0){// 伸展
        while(fa[x]!=goal){
            size_t y=fa[x];
            size_t z=fa[y];
            if(z!=goal){
                if(chk(x)==chk(y))rotate(y);
                else rotate(x);
            }
            rotate(x);
        }
        if(!goal)rt=x;
    }
    void find(ValType x){// 将最大的小于等于x的数所在的节点splay到根
        if(!rt)return;
        size_t cur=rt;
        while(ch[x>val[cur]][cur]&&x!=val[cur]){
            cur=ch[x>val[cur]][cur];
        }
        splay(cur);
    }
/*
从根节点开始，一路搜索下去。如果节点存在则直接自增cnt的值。否则新建节点并与父节点连边。
因为新建节点时可能会拉出一条链，所以新建节点后需要将该节点splay到根节点。
沿途的rotate操作可以使平衡树恢复平衡。
*/
    void insert(size_t x){
        size_t cur=rt,p=0;
        while(cur&&val[cur]!=x){
            p=cur;
            cur=ch[x>val[cur]][cur];
        }
        if(cur){
            cnt[cur]++;
        }
        else{
            cur=++tot;
            if(p)ch[x>val[p]][p]=cur;
            ch[0][cur]=ch[1][cur]=0;
            val[cur]=x;
            fa[cur]=p;
            cnt[cur]=size[cur]=1;
        }
        splay(cur);
    }
    ValType kth(size_t k){// 从根节点开始，一路搜索下去。每次判断要走向哪个子树。注意考虑重复权值。
        size_t cur=rt;
        while(true){
            if(ch[0][cur]&&k<=size[ch[0][cur]]){
                cur=ch[0][cur];
            }
            else if(k>size[ch[0][cur]]+cnt[cur]){
                k-=size[ch[0][cur]]+cnt[cur];
                cur=ch[1][cur];
            }
            else{
                splay(cur);
                return cur;
            }
        }
    }
    size_t rank(ValType x){
        find(x);
        return size[ch[0][rt]];
    }
    size_t pre(ValType x) {// 前继：将该节点find到根后返回左子树最右边的节点即可
        find(x);
        if (val[rt]<x)return rt;
        size_t cur=ch[0][rt];
        while(ch[1][cur])cur=ch[1][cur];
        splay(cur);
        return cur;
    }
    size_t succ(ValType x){// 后继
        find(x);
        if (val[rt]>x)return rt;
        size_t cur=ch[1][rt];
        while (ch[0][cur])cur=ch[0][cur];
        splay(cur);
        return cur;
    }
    void remove(size_t x){
        size_t last=pre(x),next=succ(x);
        splay(last);
        splay(last,next);
        size_t del=ch[0][next];
        if(cnt[del]>1){// 特判
            cnt[del]--;
            splay(del);
        }
        else ch[0][next]=0;
        push_up(next);
        push_up(x);
    }
};
};
#endif
