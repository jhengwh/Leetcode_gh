// Reverse sorting

/* Re-organized */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {    // "j >= 0" is enough (instead of "i >= 0 || j >= 0")
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            k--;
            i--;
        } else {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
}

/* Original */
// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
// {
//     int i = m - 1, j = n - 1, k = m + n - 1;
//     while (i >= 0 || j >= 0) {
//         if (i >= 0 && j >= 0) {
//             if (nums1[i] > nums2[j]) {
//                 nums1[k] = nums1[i];
//                 k -= 1;
//                 i -= 1;
//             } else {
//                 nums1[k] = nums2[j];
//                 k -= 1;
//                 j -= 1;
//             }
//         } else if (i < 0 && j >= 0) {
//             nums1[k] = nums2[j];
//             k -= 1;
//             j -= 1;
//         } else {
//             nums1[k] = nums1[i];
//             k -= 1;
//             i -= 1;
//         }
//     }
// }