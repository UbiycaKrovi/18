#ifndef CODE_REMOVE_PALINDROME_WORD_H
#define CODE_REMOVE_PALINDROME_WORD_H

#include "string.h"

void remove_palindrome_word(char* s) {
    char* read_begin = _string_buffer;
    char* read_end = copy(s, s + strlen_(s), _string_buffer);
    char* rec_ptr = s;

    word_descriptor word;
    while (get_word(read_begin, &word)) {
        if (!is_palindrome_word(&word)) {
            rec_ptr = copy(word.begin, word.end, rec_ptr);

            if (word.end !=  read_end)
                *rec_ptr++ = ' ';
        }
        read_begin = word.end + 1;
    }

    *rec_ptr = '\0';

    free_string(_string_buffer);
}

void test_empty() {
    char s[] = "";
    remove_palindrome_word(s);
    ASSERT_STRING("", s);
}
void test_non_palindrome() {
    char s[] = "none palindrome words";
    remove_palindrome_word(s);
    ASSERT_STRING("none palindrome words", s);
}
void test_only_letters() {
    char s[] = "a b c d";
    remove_palindrome_word(s);
    ASSERT_STRING("", s);
}
void test_different_string() {
    char s[] = "mom dad brother sister";
    remove_palindrome_word(s);
    ASSERT_STRING("brother sister", s);
}
void test_remove_palindrome_word() {
    test_empty();
    test_non_palindrome();
    test_only_letters();
    test_different_string();
}

#endif //CODE_REMOVE_PALINDROME_WORD_H