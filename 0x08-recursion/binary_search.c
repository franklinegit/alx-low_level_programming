#include <stdio.h>


int main(void)
{
    int arr[] = {1, 4, 7, 8, 11, 15, 17, 22, 24, 29, 30};
    int target = 8;
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    int target_idx = binarySearch(arr, 0, size_arr - 1, target);

    if (target_idx != -1)
    {
        print("The index of %d in the array is %d\n", target, target_idx);
        print("\n");
    }
    else
    {
        print("The target %d is not in the array.\n");
        print("\n");
    }

    return (0);
}