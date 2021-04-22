#ifndef OI_SLOWSORT
#define OI_SLOWSORT
#include "../base/base.h"
namespace OIalgo{
// 这些排序并不是此库的主要部分，不予过多功能
// 对a[1]~a[n]从小到大排序
template<class ValType>
void SelectionSort(ValType *a,size_t n){// 选择排序
    for(size_t i=1;i<=n;++i){
        size_t temp=i;
        for(size_t j=i+1;j<=n;j++){
            if(a[j]<a[temp])temp=j;
        }
        swap(a[i],a[temp]);// 找出最小的进行交换
    }
}

template<class ValType>
void BubbleSort(ValType *a,size_t n){// 冒泡排序
    while(true){
        bool flag=true;
        for(size_t i=1;i<n;++i){
            if(a[i]>a[i+1]){
                flag=false;
                swap(a[i],a[i+1]);
            }
        }
        if(flag)return;// 排完直接结束
    }
}

template<class ValType>
void InsertionSort(ValType *a,size_t n){// 插入排序
    for(size_t i=1;i<n;++i){
        ValType temp=a[i+1];
        size_t j=i;
        while(j>0&&a[j]>temp){// 寻找插入位置
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=temp;
    }
}
};
#endif
