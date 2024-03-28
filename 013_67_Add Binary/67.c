char* addBinary(const char* a, const char* b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxSize = lenA > lenB ? lenA : lenB;

    // +2 for potential carry and null terminator
    char* result = (char*)malloc((maxSize + 2) * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int carry = 0;
    int i = lenA - 1;
    int j = lenB - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += (a[i] - '0');
            i--;
        }
        if (j >= 0) {
            sum += (b[j] - '0');
            j--;
        }
        result[k] = (sum % 2) + '0';
        k++;
        carry = sum / 2;
    }
    result[k] = '\0';

    // Reverse the result string
    int left = 0, right = k - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }

    return result;
    // free(result);
}