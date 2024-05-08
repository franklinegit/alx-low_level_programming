#include <stdio.h>
/**
 * @brief Function that performs a binary search on a sorted array
 * 
 * @param arr sorted array
 * @param lowest_idx lowest index in the array to search
 * @param highest_idx highest index in the array to search
 * @param target target whose index is to be determined
 * @return int Index of the target in the array
 */
int binarySearch(int arr[], int lowest_idx, int highest_idx, int target)
{
    if (lowest_idx >= highest_idx)
    {
        /* Base case: If only one element left to check */
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
        /* Base case: element found */
        return (mid_idx);

    else if (arr[mid_idx] > target)
        /* Recursive case: search left half */
        return (binarySearch(arr, lowest_idx, mid_idx - 1, target));

    else
        /* Recursive case: search right half */
        return (binarySearch(arr, mid_idx + 1, highest_idx, target));
}

/**
 * @brief main function 
 * 
 * @return int returns 0 on success
 */
int main(void)
{
    int arr[] = {1, 4, 7, 8, 11, 15, 17, 22, 24, 29, 30};
    int target = 17;
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    int target_idx = binarySearch(arr, 0, size_arr - 1, target);

    if (target_idx != -1)
    {
        printf("The index of %d in the array is %d\n", target, target_idx);
        printf("\n");
    }
    else
    {
        printf("The target %d is not in the array.\n", target);
        printf("\n");
    }

    return (0);
}