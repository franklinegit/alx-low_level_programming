#include <stdio.h>

int binarySearch(int arr[], int lowest_idx, int highest_idx, int target)
{
    if (lowest_idx >= highest_idx)
    {
        if (lowest_idx == highest_idx && arr[lowest_idx] == target)
        {
            return (lowest_idx);
        }
        else
        {
            return (-1);
        }
    }

    int mid_idx = lowest_idx + (highest_idx - lowest_idx) / 2;

    if (arr[mid_idx] == target)
        return (mid_idx);

    else if (arr[mid_idx] > target)
        return (binarySearch(arr, lowest_idx, mid_idx - 1, target));

    else
        return (binarySearch(arr, mid_idx + 1, highest_idx, target));
}


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