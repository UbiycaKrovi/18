#ifndef CODE_LETTERS_BELONG_STRING_H
#define CODE_LETTERS_BELONG_STRING_H

#include "string.h"

#define LETTERS_SHIFT 97

bool letters_belong_string(char* string, word_descriptor word) {
    bool include[26] = {0};

    char* start = string;
    char* end = get_end_of_string(string);

    while (start != end) {
        if (isalpha(*start))
            include[*start - LETTERS_SHIFT] = true;

        start++;
    }

    while (word.begin != word.end) {
        if (!include[*word.begin - LETTERS_SHIFT])
            return false;

        word.begin++;
    }

    return true;
}

void test_empty() {
    char string[] = "";
    word_descriptor word;
    get_word("", &word);

    assert(!letters_belong_string(string, word));
}
void test_empty_word() {
    char string[] = "word";
    word_descriptor word;
    get_word("", &word);

    assert(!letters_belong_string(string, word));
}
void test_empty_string() {
    char string[] = "";
    word_descriptor word;
    get_word("word", &word);

    assert(!letters_belong_string(string, word));
}
void test_letters_not_in_string() {
    char string[] = "abc";
    word_descriptor word;
    get_word("word", &word);

    assert(!letters_belong_string(string, word));
}
void test_letters_in_string() {
    char string[] = "world";
    word_descriptor word;
    get_word("word", &word);

    assert(letters_belong_string(string, word));
}
void test_letters_belong_string() {
    test_empty();
    test_empty_word();
    test_empty_string();
    test_letters_not_in_string();
    test_letters_in_string();
}

#endif //CODE_LETTERS_BELONG_STRING_H