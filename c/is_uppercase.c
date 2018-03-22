#include <stdbool.h>
#include <stdio.h> // include for testing, not needed for is_uppercase()

bool is_uppercase(const char *source) {
    char *p = source;

    while(*p) {
        if('a' <= *p && *p <= 'z')  // Check if *p is a-z
            return false;           // Found lowercase- return false.
        ++p;
    }
    return true; // Got all the way through without finding lowercase- return true.
}

void test(const char *source, bool expected_result) {
    if(is_uppercase(source) == expected_result)
        printf("Pass: Got %i on %s", expected_result, source);
    else
        printf("Fail: Got %i on %s", expected_result, source);
    printf("\n");
}

int main(void) {
    // Start with some simple tests
    test("a", false);
    test("z", false);
    test("A", true);
    test("M", true);
    test("Z", true);

    test("ABCD", true);
    test("ABCd", false);

    test("Call me Ishmael.", false);
    test("CALL ME ISHMAEL.", true);     // test punctuation
    test("CALL ME ISHMAEL",  true);     // test alpha caps
    test("cALL ME ISHMAEL",  false);    // test for off-by-one error (note lowercase first letter)
    test("CALL ME ISHMAEl",  false);    // test for off-by-one error (note lowercase last letter)

    return 0;
}

