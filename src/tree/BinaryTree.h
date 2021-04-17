#include "../base/base.h"
namespace OIalgo{
/* 指针实现
template<class ValType>
class BTNode{
    public:
    ValType val;
    BTNode* fa,lch,rch;
    BTNode(BTNode *fat,ValType value=0){
        fa=fat;
        lch=nullptr;
        rch=nullptr;
    }
    BTNode(BTNode &a){
        val=a.val;
        fa=a.fa;
        lch=new BTNode(this);
        *lch=*a.lch;
        rch=new BTNode(this);
        *rch=*a.rch;
    }
    ~BTNode(){
        if(lch!=nullptr)delete lch;
        if(rch!=nullptr)delete rch;
    }
};
*/

template<const size_t len,class ValType=ll>// 二叉树 [Luogu P1305]
class BinaryTree{
	public:
    size_t rt;// 根节点编号
    size_t tot;// 节点个数
    array<size_t,len> fa;// 父亲编号
    array<array<size_t,len>,2>ch;// 左右儿子编号（0=左 1=右）
    array<ValType,len>val;// 节点值
    void init(ValType rtval=0,ValType tofill=0){// 初始化
        rt=1;tot=1;
        fa.fill(0);
        ch[0].fill(0);ch[1].fill(0);
        val.fill(tofill);
        val[1]=rtval;
    }
    size_t lch(size_t x){
        return ch[0][x];
    }
    size_t rch(size_t x){
        return ch[1][x];
    }
    void create(size_t fat,bool isrightch,ValType valu=0){// 创建新节点
        fa[++tot]=fat;
        ch[isrightch][fat]=tot;
        val[tot]=valu;
    }
    void PreVisit(vector<size_t>&sav,size_t x=rt){// 先序遍历
        if(ch[0][pl]!=0)PreVisit(sav,ch[0][x]);
        sav.push_back(x);
        if(ch[1][pl]!=0)PreVisit(sav,ch[1][x]);
    }
    void InVisit(vector<size_t>&sav,size_t x=rt){// 中序遍历
        sav.push_back(x);
        if(ch[0][pl]!=0)PreVisit(sav,ch[0][x]);
        if(ch[1][pl]!=0)PreVisit(sav,ch[1][x]);
    }
    void PostVisit(vector<size_t>&sav,size_t x=rt){// 后序遍历
        if(ch[0][pl]!=0)PreVisit(sav,ch[0][x]);
        if(ch[1][pl]!=0)PreVisit(sav,ch[1][x]);
        sav.push_back(x);
    }
// 扩展功能
    size_t depth(size_t x){// 节点深度
        size_t i=0;
        while(x!=rt){
            ++i;
            x=fa[x];
        }
        return i;
    }
    bool isLeaf(size_t x){
        tocount i=0;
        if(fa[x]!=0)i++;
        if(ch[0][x]!=0)i++;
        if(ch[1][x]!=0)i++;
        return i<=1;
    }
    size_t LeafCount(size_t x=rt){// 叶子个数
        size_t c=0;
        if(isLeaf(x))++c;
        if(ch[0][x]!=0)c+=LeafCount(ch[0][x]);
        if(ch[1][x]!=0)c+=LeafCount(ch[1][x]);
        return c;
    }
    size_t height(size_t pl=rt){// 树的高度
        size_t ans=0;
        if(ch[0][pl]!=0)ans=height(ch[0][pl]);
        if(ch[1][pl]!=0)ans=max<size_t>(ans,height(ch[1][pl]));
        return ans;
    }
};
};
