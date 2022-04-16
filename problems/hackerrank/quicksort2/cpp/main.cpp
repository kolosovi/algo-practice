// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
#include <bits/stdc++.h>
using namespace std;

void quickSortIter(std::vector<int> &arr, std::vector<int> &tmp, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int pivot = begin, l = begin, r = end;
    for (int i = pivot+1; i <= end; i++) {
        if (arr[i] < arr[pivot]) {
            tmp[l++] = arr[i];
        }
        if (arr[i] > arr[pivot]) {
            tmp[r--] = arr[i];
        }
    }
    tmp[l] = arr[pivot];
    for (int last = end; r < last;) {
        std::swap(tmp[++r], tmp[last--]);
    }
    for (int i = begin; i <= end; i++) {
        arr[i] = tmp[i];
    }
    quickSortIter(arr, tmp, begin, l-1);
    quickSortIter(arr, tmp, l+1, end);
    std::cout << arr[begin];
    for (int i = begin+1; i <= end; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << "\n";
}

void quickSort(vector <int> &arr) {
    std::vector<int> tmp(arr.size());
    quickSortIter(arr, tmp, 0, arr.size()-1);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
