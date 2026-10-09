#include <stdio.h>
int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid; 
        }
        if (array[mid] > target) {
            right = mid - 1;
        } 
        
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    
    int numbers[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int target = 23;
    
    int result = binarySearch(numbers, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

