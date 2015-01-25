// Bubble-sort implemented in C++. Complexity O(n²).
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
#include <cstdlib>
#include <algorithm>

void bubble_sort(int arr[], const int size);
void print(const int arr[], const int size);

int main() {
    int arr[] = {5,1,4,2,8};
    const int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Before:" << std::endl; print(arr,size);
    bubble_sort(arr,size);
    std::cout << "After:" << std::endl; print(arr,size);
    return EXIT_SUCCESS;
}

void bubble_sort(int arr[], const int size) {
    bool swapped;
    do {
        swapped=false;
        for(int i=0;i<size-2;++i) {
            if(arr[i]>arr[i+1]) {
                std::swap(arr[i],arr[i+1]);
                swapped=true;
            }
        }
    } while(swapped);
}

void print(const int arr[], const int size) {
    for(int i=0;i<size;++i) {
        std::cout << arr[i];
        if(i+1!=size) { std::cout << " "; }
    }
    std::cout << std::endl;
}
