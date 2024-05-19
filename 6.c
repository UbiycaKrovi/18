#include "string.h"

bool isWordsOrderedLexically(char *s) {
    char *beginSearch = s;
    WordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return true;
    WordDescriptor previousWord = currentWord;
    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return false;
        beginSearch = currentWord.end;
        previousWord = currentWord;
    }
    return true;
}

void test_isWordsOrderedLexically_nonWords() {
    char s[] = "";
    assert(isWordsOrderedLexically(s) == true);
}
void test_isWordsOrderedLexically_Lexically() {
    char s[] = "abc def";
    assert(isWordsOrderedLexically(s) == true);
}
void test_isWordsOrderedLexically_notLexically() {
    char s[] = "fde acb";
    assert(isWordsOrderedLexically(s) == false);
}
void test_isWordsOrderedLexically() {
    test_isWordsOrderedLexically_nonWords();
    test_isWordsOrderedLexically_isLexically();
    test_isWordsOrderedLexically_notLexically();
}

int main() {
    test_isWordsOrderedLexically();
    
    return 0;
}