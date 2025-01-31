#ifndef CODE_FIND_PRECEDING_WORD_H
#define CODE_FIND_PRECEDING_WORD_H

#include "string.h"

word_descriptor find_preceding_word(char* s1, char* s2) {
    char* begin_search_1 = s1;
    char* begin_search_2 = s2;

    while (get_word_without_space(begin_search_1, &_bag.words[_bag.size])) {
        begin_search_1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    while (get_word_without_space(begin_search_2, &_bag2.words[_bag2.size])) {
        begin_search_2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }

    bool stop = false;
    word_descriptor w;
    word_descriptor preceding_w = {.begin = NULL, .end = NULL};

    for (size_t i = 1; i < _bag.size; i++) {
        w = _bag.words[i];
        for (size_t j = 0; j < _bag2.size; j++)
            if (is_word_equal(w, _bag2.words[j])) {
                stop = true;
                break;
            }

        if (stop) {
            preceding_w = _bag.words[i - 1];
            break;
        }
    }

    free_bag(&_bag);
    free_bag(&_bag2);

    return preceding_w;
}

void test_empty() {
    char s1[] = "";
    char s2[] = "";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}
void test_first_empty() {
    char s1[] = "";
    char s2[] = "word";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}
void test_second_empty() {
    char s1[] = "i love";
    char s2[] = "";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}
void test_not_in_string() {
    char s1[] = "i like pizza";
    char s2[] = "hate sushi";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}
void test_first_in_string() {
    char s1[] = "Hello world";
    char s2[] = "Goodbye world";

    char dest[40] = "";
    word_descriptor word = find_preceding_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("i", dest);
}
void test_find_preceding_word() {
    test_empty();
    test_first_empty();
    test_second_empty();
    test_not_in_string();
    test_first_in_string();
}

#endif //CODE_FIND_PRECEDING_WORD_H