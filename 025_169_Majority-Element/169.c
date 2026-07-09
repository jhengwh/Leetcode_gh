int majorityElement(int* nums, int numsSize) {
    int major = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (count <= 0)
        {
            major = nums[i];
            count = 1;
        }
        else if (nums[i] == major)
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count > (numsSize / 2))
        {
            break;
        }
    }

    return major;
}