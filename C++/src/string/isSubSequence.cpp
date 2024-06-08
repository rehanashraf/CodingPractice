//
//  isSubSequence.cpp
//  leetcode
//
//  Created by Rehan Ashraf on 2/21/23.
//

#include <stdio.h>
#include <string>

using namespace std;

bool isSubsequence(string s, string t) {
    size_t tSize = t.size();
    size_t sSize = s.size();
    size_t s_index = 0;
    bool rv = false;

    for (size_t i = 0; i < tSize; i++) {
        if (s[s_index] == t[i]) {
            s_index++;
        }
        if(s_index == sSize) {
            break;
        }
    }
    if(s_index == sSize) {
        rv = true;
    }
    return rv;
}
