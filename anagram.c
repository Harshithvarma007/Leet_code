#include <stdio.h>
#include <stdbool.h>

#define MAX_CHARS 256
bool isAnagram(char* s, char* t) {
    // Create an array to store the frequency of characters
    int count[MAX_CHARS] = {0};

    // Traverse the first string and increment the count for each character
    for (int i = 0; s[i] != '\0'; i++)
        count[s[i]]++;

    // Traverse the second string and decrement the count for each character
    for (int i = 0; t[i] != '\0'; i++)
        count[t[i]]--;

    // If the two strings are anagrams, all counts should be zero
    for (int i = 0; i < MAX_CHARS; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}