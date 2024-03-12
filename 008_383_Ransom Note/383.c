/** Solution 1 (from Leetcode)
 * Time complexity:  O(m + n)
 * Space complexity: O(ALPHABET_SIZE)
 * where m = len(magazine); n = len(ransomNote)
 */
bool canConstruct(char* ransomNote, char* magazine)
{
    int hash[26] = { 0 };
    int lenR = strlen(ransomNote);
    int lenM = strlen(magazine);

    if (lenR > lenM)
        return false;

    for (int i = 0; i < lenM; i++)
        hash[magazine[i] - 'a']++;

    for (int i = 0; i < lenR; i++) {
        if (hash[ransomNote[i] - 'a'] <= 0)
            return false;
        hash[ransomNote[i] - 'a']--;
    }

    return true;
}

/** My original attempt
 * Time complexity:  O(mlogm + nlogn)
 * Space complexity: O(logm + logn)
 * where m = len(magazine); n = len(ransomNote)
 */
int compare(const void* arg1, const void* arg2)
{
    return (*(char*)arg1 - *(char*)arg2);
}

bool canConstruct(char* ransomNote, char* magazine)
{
    qsort((void*)ransomNote, strlen(ransomNote), sizeof(char),
        compare);
    qsort((void*)magazine, strlen(magazine), sizeof(char),
        compare);

    int ptr = 0;
    // magazine.length <= 10^5
    for (int i = 0; i < strlen(magazine); i++) {
        if (magazine[i] == ransomNote[ptr])
            ptr++;
        if (ptr == strlen(ransomNote))
            return true;
    }
    return false;
}