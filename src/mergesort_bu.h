//
// Created by Yijie Ma on 10/8/16.
//

#ifndef ALGORITHM_MERGESORT_BU_H
#define ALGORITHM_MERGESORT_BU_H

#include <algorithm>
#include <functional>
#include <vector>

namespace {
template <typename T>
class MergeSortBU {
public:
    static void sort(std::vector<T> &array) {
        int N = array.size();
        std::vector<T> aux(N);
        for (int sz = 1; sz < N; sz = sz + sz)
        for (int lo = 0; lo < N - sz; lo = lo + sz + sz) {
            if (array[lo + sz - 1] > array[lo + sz]) {
                merge(lo, lo + sz - 1, std::min(N - 1, lo + sz + sz - 1), aux, array);
            }
        }
    }

private:
    static void merge(int lo, int mid, int hi, std::vector<T> &aux, std::vector<T> &array) {
        for (int k = lo; k <= hi; ++k) {
            aux[k] = array[k];
        }

        int i = lo;
        int j = mid + 1;
        for (int k = lo; k <= hi; ++k) {
            if (i > mid) array[k] = aux[j++];
            else if (j > hi) array[k] = aux[i++];
            else if (aux[i] > aux[j]) array[k] = aux[j++];
            else array[k] = aux[i++];
        }
    }
};

} // namespace
#endif //ALGORITHM_MERGESORT_BU_H
