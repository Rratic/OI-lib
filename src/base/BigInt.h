#ifndef OI_BIGINT
#define OI_BIGINT
#include "../base/base.h"
namespace OIalgo{
template<size_t len,class SavedType=unsigned short,unsigned short sq=4/* 压位 10000 */>
class BigUInt{// 高精度无符号整数
    public:
    array<SavedType,len>data;
    size_t pl;// 最高位 data[pl]
    SavedType bound;
    void init(){
        data.fill(0);
        pl=0;
        bound=1;
        for(unsigned short i=0;i<sq;i++)bound*=10;
    }
    bool in(string s){
        pl=0;
        auto i=s.rbegin();
        bool flag=true;
        while(true){
            SavedType j=1,k=0;
            for(size_t l=0;l<sq;++l){
                if(*i<'0'||*i>'9')return false;
                k+=(*i-'0')*j;
                ++i;
                if(i==s.rend()){
                    data[pl]=k;
                    flag=false;
                    break;
                }
                j*=10;
            }
            if(flag)data[pl++]=k;
        }
        return true;
    }
    string out(){
        string s;
        for(size_t i=0;i<=pl;i++){
            s=u_to_string<SavedType>(data[i])+s;
        }
        return s;
    }
    friend bool operator ==(BigUInt a,BigUInt b){
        if(a.pl!=b.pl)return false;
        for(size_t i=0;i<=a.pl;i++){
            if(a.data[i]!=b.data[i])return false;
        }
        return true;
    }
    friend bool operator <=(BigUInt a,BigUInt b){
        if(a.pl!=b.pl)return a.pl<b.pl;
        for(size_t i=0;i<=a.pl;i++){
            if(a.data[i]!=b.data[i])return a.data[i]<b.data[i];
        }
        return true;
    }
    friend bool operator <(BigUInt a,BigUInt b){
        if(a.pl!=b.pl)return a.pl<b.pl;
        for(size_t i=0;i<=a.pl;i++){
            if(a.data[i]!=b.data[i])return a.data[i]<b.data[i];
        }
        return false;
    }
    BigUInt& operator +=(BigUInt &b){
        pl=max(pl,b.pl);
        bool x=false;
        for(size_t i=0;i<=pl;i++){
            data[i]+=b.data[i];
            if(x){
                data[i]++;
                x=false;
            }
            if(data[i]>=bound){// 进位
                data[i]-=bound;
                x=true;
            }
        }
        if(x)data[++pl]=1;
        return *this;
    }
    friend BigUInt operator +(BigUInt a,BigUInt &b){
        a+=b;
        return a;
    }
    /* 数据检查
    void check(size_t start=10){
        cout<<"[";
        for(size_t i=start;i>=1;i--){
            if(i==pl)cout<<"\033[91m";
            cout<<data[i];
            if(i==pl)cout<<"\033[m";
            cout<<",";
        }
        if(pl==0)cout<<"\033[31m";
        cout<<data[0];
        if(pl==0)cout<<"\033[m";
        cout<<"]"<<pl<<"\n";
    }
    */
};
};
#endif
