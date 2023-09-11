#include "mysort.hpp"
#include "iostream"

namespace std {
    void bubble_sort(vector<int>&);

    int main() {
        std::vector<int> v = {4, 6, 2, 3, 7, 1};
        bubble_sort(v);
        for (auto n : v) {
          std::cout << n << " ";
        }
        return 0;
    }
}
