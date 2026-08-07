void reverse(int* nums, int start, int end) {
    while(start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    int nk = k % numsSize;    // normalized k
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, nk - 1);
    reverse(nums, nk, numsSize - 1);
}