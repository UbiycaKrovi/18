#include "string.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *writePtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        writePtr = source;
    } 
    else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        writePtr = source;
    }
    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            if (areWordsEqual(word1, (WordDescriptor) {readPtr, readPtr +
                                                                w1Size}) <= 0) {
                copy(word2.begin, word2.end, writePtr);
                readPtr += w1Size;
                writePtr += w2Size;
            } 
            else
                *writePtr++ = *readPtr++;
        } 
        else
            *writePtr++ = *readPtr++;
    }
    *writePtr = '\0';
}

void test_replace_nonWords() {
    char s[] ="";
    replace(s, "Afternoon", "Evening");
    ASSERT_STRING("", s);
}
void test_replace_nonWord1() {
    char s[] ="Good Morning";
    replace(s, "Afternoon", "Evening");
    ASSERT_STRING("Good Morning", s);
}
void test_replace_withWord1() {
    char s[] ="Good Afternoon";
    replace(s, "Afternoon", "Evening");
    ASSERT_STRING("Good Evening", s);
}
void test_replace() {
    test_replace_nonWords();
    test_replace_nonWord1();
    test_replace_withWord();
}
int main() {
    test_replace();
    
    return 0;
}