#include "string.h"

int isGraph(char s) {
    return !isspace(s);
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isGraph);
    *destination = '\0';
}
void test_removeNonLetters_nonWords() {
    char s[] = " ";
    removeNonLetters(s);
    ASSERT_STRING ("", s);
}
void test_removeNonLetters_oneWord() {
    char s[] = "abc";
    removeNonLetters(s);
    ASSERT_STRING ("abc", s);
}
void test_removeNonLetters_manyWords() {
    char s[] = "abc abc";
    removeNonLetters(s);
    ASSERT_STRING ("abcabc", s);
}
void test_removeNonLetters() {
    test_removeNonLetters_nonWords();
    test_removeNonLetters_oneWord();
    test_removeNonLetters_manyWords();
}

int main() {
    test_removeNonLetters();
    return 0;
}