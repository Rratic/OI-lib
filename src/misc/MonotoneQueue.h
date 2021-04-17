#include "../base/base.h"
namespace OIalgo{
template<class ValType>
class MonotoneQueue{// 单调队列 [Luogu P1886]
    public:
    list<ValType>data;
    /* 不挤
    void push(ValType x){
        bool flag=true;
        for(auto it=data.begin();it!=data.end();++it){// 向后比对
            if(*it>x){
                data.insert(it,x);
                flag=false;
                break;
            }
        }
        if(flag)data.push_back(x);
    }
    */
    bool push_min(ValType x){// 用于维护较小值
        while(!data.empty()){
            if(data.back()>=x)data.pop_back();
            else{
                data.push_back(x);
                return;
            }
        }
        data.push_back(x);
    }
    bool push_max(ValType x){// 用于维护较大值
        while(!data.empty()){
            if(data.front()<=x)data.pop_front();
            else{
                data.push_front(x);
                return;
            }
        }
        data.push_front(x);
    }
    void erase(ValType x){
        for(auto it=data.begin();it!=data.end();++it){
            if(*it==x){
                data.erase(it);
                break;
            }
        }
    }
};
};
