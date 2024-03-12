/** Solution 1  (from Leetcode)
 * Two head pointers
 */
int removeElement(int* nums, int numsSize, int val)
{
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

/** Solution 2  (my original)
 * Two pointers
 * One from head, one from tail
 */
int removeElement(int* nums, int numsSize, int val)
{
    int i = 0, j = numsSize - 1, k = 0;
    // int temp = 0;                         // 1.
    while (i < j) {                          // 2.
        while (nums[i] != val && i < j) {    // 3.
            k++;
            i++;
        }
        while (nums[j] == val && j > 0) {    // 4.
            j--;
        }
        if (i < j) {
            nums[i] = nums[j];
            i++;
            k++;
            j--;
        }
    }
    if (i == j && nums[i] != val)    // 2.
        k++;
    return k;
}