int removeDuplicates(int* nums, int numsSize) {
    int fast = 1, slow = 0;
    bool already_two = false;

    for (; fast < numsSize; fast++)
    {
        if (nums[fast] != nums[slow])
        {
            slow++;
            nums[slow] = nums[fast];
            already_two = false;
        }
        else if (!already_two)
        {
            slow++;
            nums[slow] = nums[fast];
            already_two = true;
        }
    }
    return slow + 1;
}