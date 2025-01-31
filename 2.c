#include "string.h"

void removeAdjacentEqualLetters(char *s) {
    char *begin = s;
    char *destination = s;
    char last = *begin;
    while (*begin != '\0') {
        if (*begin != last) {
            *destination = last;
            destination++;
        }
        last = *begin++;
    }
    if (last != '\0') {
        *destination = last;
        *destination++;
    }
    *destination = '\0';
}
void test_removeAdjacentEqualLetters_nonWords() {
    char s[] = " ";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(" ", s);
}
void test_removeAdjacentEqualLetters_nonEqualLetters() {
    char s[] = "abc";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("abc", s);
}
void test_removeAdjacentEqualLetters_EqualLetters() {
    char s[] = "abbccc";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("abc", s);
}
void test_removeAdjacentEqualLetters_alternationEqualLetters() {
    char s[] = "aabbccaabbc";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("abcabc", s);
}
void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_nonWords();
    test_removeAdjacentEqualLetters_nonEqualLetters();
    test_removeAdjacentEqualLetters_EqualLetters();
    test_removeAdjacentEqualLetters_alternationEqualLetters();
}

int main() {
    test_removeAdjacentEqualLetters();
    return 0;
}