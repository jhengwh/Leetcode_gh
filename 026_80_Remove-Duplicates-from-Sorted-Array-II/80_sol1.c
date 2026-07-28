int removeDuplicates(int* nums, int numsSize) {
    int slow = 0;

    for (int fast = 0; fast < numsSize; fast++)
    {
        if (slow==0 || slow==1 || nums[slow-2] != nums[fast])
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}