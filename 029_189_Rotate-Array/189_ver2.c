void reverse(int* nums, int numsSize) {
    int start = 0;
    int end = numsSize - 1;

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
    reverse(nums, numsSize);
    reverse(nums, nk);
    reverse(nums + nk, numsSize - nk);
}