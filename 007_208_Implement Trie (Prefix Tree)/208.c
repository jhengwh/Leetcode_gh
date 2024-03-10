#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct _Trie {
    struct Trie* children[ALPHABET_SIZE];
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
} Trie;

Trie* trieCreate()
{
    Trie* pNode = NULL;
    pNode = (Trie*)malloc(sizeof(Trie));
    if (pNode) {
        int i;
        pNode->isEndOfWord = false;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void trieInsert(Trie* obj, char* word)
{
    int length = strlen(word);
    int index;
    Trie* pCrawl = obj;

    for (int level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(word[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = trieCreate();
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char* word)
{
    int length = strlen(word);
    int index;
    Trie* pCrawl = obj;

    for (int level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(word[level]);
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord);
}

bool trieStartsWith(Trie* obj, char* prefix)
{
    int length = strlen(prefix);
    int index;
    Trie* pCrawl = obj;

    for (int level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(prefix[level]);
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return true;
}

// Free all the nodes recursively
void trieFree(Trie* obj)
{
    if (obj == NULL)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        trieFree(obj->children[i]);

    free(obj);
    return;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/