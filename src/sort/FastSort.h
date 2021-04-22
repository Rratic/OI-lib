#ifndef OI_FASTSORT
#define OI_FASTSORT
#include "../base/base.h"
namespace OIalgo{
// 对a[1]~a[n]从小到大排序

// 基于值域的排序
template<class ValType>
void BucketSort(ValType *a,size_t n){// 桶排序
}

template<class ValType>
void CountingSort(ValType *a,size_t n){// 计数排序

}

template<class ValType>
void RadixSort(ValType *a,size_t n){// 基数排序
}

// O(nlogn) 排序
template<class ValType>
void QuickSort(ValType *a,size_t n){// 快速排序
}

template<class ValType>
void MergeSort(ValType *a,size_t n){// 归并排序
}

template<class ValType>
void HeapSort(ValType *a,size_t n){// 堆排序
}

template<class ValType>
void ShellSort(ValType *a,size_t n){// 希尔排序
}

template<class ValType>
void TournamentSort(ValType *a,size_t n){// 锦标赛排序
}

// 优化
template<class ValType>
void ThreeWayRadixSort(ValType *a,size_t n){// 三路快速排序
}

template<class ValType>
void IntroSort(ValType *a,size_t n){// 内省排序
}
};
#endif
