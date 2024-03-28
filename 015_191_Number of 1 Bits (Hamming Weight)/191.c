/* Solution from Leetcode */
int hammingWeight(int n)
{
    int weight = 0;
    while (n) {
        weight += (1 & n);
        n = n >> 1;
    }
    return weight;
}

/* My original attempt */
// int hammingWeight(int n)
// {
//     /* 2^31 numbers need 31 binary bits, or
//      * 8 bits hexadecimal to represent; also,
//      * "0x" + 8 bits + "\0" = 11 bits */
//     char str[11] = "";
//     char* pStr = str;
//     int weight = 0, len = 0;
//
//     sprintf(str, "%x", n);
//     len = strlen(str);
//     str[len] = '\0';
//
//     while (*pStr) {
//         switch (*pStr) {
//         case '1': case '2': case '4': case '8':
//             weight += 1;
//             break;
//         case '3': case '5': case '6': case '9': case 'a': case 'c':
//             weight += 2;
//             break;
//         case '7': case 'b': case 'd': case 'e':
//             weight += 3;
//             break;
//         case 'f':
//             weight += 4;
//             break;
//         }
//         pStr += 1;
//     }
//     return weight;
// }