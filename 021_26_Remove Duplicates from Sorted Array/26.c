int removeDuplicates(int* nums, int numsSize)
{
    if (sizeof(nums) == 1)
        return 1;
    int fast = 1, slow = 1;
    int prev = nums[0];
    for (; fast < numsSize; fast++) {
        if (nums[fast] == prev)
            continue;
        nums[slow] = nums[fast];
        prev = nums[slow];
        slow++;
    }
    return slow;
}