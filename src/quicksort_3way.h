//
// Created by Yijie Ma on 10/9/16.
//

#ifndef ALGORITHM_QUICKSORT_3WAY_H
#define ALGORITHM_QUICKSORT_3WAY_H

#include <vector>

namespace {
template <typename T>
class QuickSort3Way {
public:
    static void sort(std::vector<T> &array) {
        std::random_shuffle(array.begin(), array.end());
        sort(0, array.size() - 1, array);
    }

private:
    static void sort(int lo, int hi, std::vector<T> &array) {
        if (hi <= lo) return;
        int pivot = array[lo];
        int lt = lo;
        int gt = hi;
        int i = lo + 1;
        while (i <= gt) {
            if (array[i] < pivot) std::swap(array[i++], array[lt++]);
            else if (array[i] > pivot) std::swap(array[i], array[gt--]);
            else ++i;
        }

        sort(lo, lt - 1, array);
        sort(gt + 1, hi, array);
    }
};
} // namespace

#endif //ALGORITHM_QUICKSORT_3WAY_H
