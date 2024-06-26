//
//  isIsomorphic.cpp
//  leetcode
//
//  Created by Rehan Ashraf on 2/21/23.
//

#include <stdio.h>
#include <string>

using namespace std;
#define MAX_CHARS 256

bool isIsomorphic(string s, string t) {
    int visited_chars[MAX_CHARS] = { 0 };
    int mapping[MAX_CHARS] = { 0 };
    int sSize = s.size();
    bool rv = true;

    for (int i = 0; i < MAX_CHARS; i++) {
        mapping[i] = -1;
    }

    for (int i = 0; i < sSize; i++) {
        if (mapping[(uint8_t) s[i]] == -1) {
            if (visited_chars[(uint8_t) t[i]] == true) {
                rv = false;
                return rv;
            }

            visited_chars[(uint8_t) t[i]] = true;
            mapping[(uint8_t) s[i]] = t[i];
        } else if (mapping[(uint8_t) s[i]] != t[i]) {
            rv = false;
            return rv;
        }
    }
    return rv;
}
