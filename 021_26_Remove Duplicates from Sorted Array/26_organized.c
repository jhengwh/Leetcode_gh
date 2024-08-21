int removeDuplicates(int* nums, int numsSize)
{
    int fast = 1, slow = 0;
    for (; fast < numsSize; fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}