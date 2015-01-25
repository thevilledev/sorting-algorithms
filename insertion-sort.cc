// Insertion-sort implemented in C++. Complexity O(n²).
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

const int MAX = 8;
void insertion_sort(int arr[]);
void print(int arr[]);

int main() {
    int arr[MAX] = {2, 4, 0, 30,1, 5, 9, 3};
    std::cout << "Before: " << std::endl; print(arr);
    insertion_sort(arr);
    std::cout << "After: " << std::endl; print(arr);
    return EXIT_SUCCESS;
}

void insertion_sort(int arr[]) {
    for(int i=1;i<MAX;++i) {
        int key=arr[i];
        int j=i;
        while(j>0&&arr[j-1]>key) {
            arr[j]=arr[j-1];
            --j;
        }
        arr[j]=key;
    }
}

void print(int arr[]) {
    for(int i=0;i<MAX;++i) {
        std::cout << arr[i];
        if(i+1!=MAX) { std::cout << " "; }
        else { std::cout << " " << std::endl; }
    }
}
