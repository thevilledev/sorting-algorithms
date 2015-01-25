// Counting-sort implemented in C++. Complexity O(n+k).
// Copyright (C) 2009 Ville Törhönen <ville@torhonen.fi>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>

const int SIZE = 8;
int find_range(const int arr[]);
int* count_sort(int arr[]);
void print(const int arr[], const int range);

int main() {
    int arr[SIZE] = {11,9,7,5,3,1,1,1};
    std::cout << "Before:" << std::endl; print(arr, SIZE);
    int* result = count_sort(arr);
    std::cout << "After:" << std::endl; print(result, SIZE);
    delete[] result;
}   

int find_range(const int arr[]) {
    int min = 0; int max = 0;
    for(int i=0;i<SIZE;++i) {
        if(arr[i]<min) { min = arr[i]; }
        if(arr[i]>max) { max = arr[i]; }
    }
    return max-min+1;
}

int* count_sort(int arr[]) {
    int range = find_range(arr);
    int* count = new int[range];
    int* R = new int[SIZE];
    for(int i=0;i<range;i++) {
        count[i] = 0;
    }
    for(int j=0;j<SIZE;j++) {
        count[arr[j]] += 1;
    }
    for(int i=1;i<range;i++) {
        count[i] += count[i-1];
    }
    for(int j=SIZE-1;j>=0;j--) {
        R[count[arr[j]]-1] = arr[j];
        count[arr[j]] -= 1;
    }
    delete[] count;
    return R;
}

void print(const int arr[], const int range) {
    for(int i=0;i<range;++i) {
        std::cout << arr[i];
        if(i+1!=range) { std::cout << " "; }
    }
    std::cout << std::endl;
}
