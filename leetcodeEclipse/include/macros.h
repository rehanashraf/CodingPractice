//
//  macros.h
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/6/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

#ifndef macros_h
#define macros_h
#include <stdio.h>

#define DEBUGP(...) printf(__VA_ARGS__)
#define MIN(a,b)        ((a) > (b) ? (b) : (a))
#define MAX(a,b)        ((a) > (b) ? (a) : (b))

#define GETDIGIT(ch)    (ch - 48)

#define ISDIGIT(ch)     (((ch <= 57) && (ch >= 48))? true : false)
#define ISSALPHA(ch)    (((ch <= 122) && (ch >= 97))? true : false)
#define ISCAPLHA(ch)    (((ch <= 90) && (ch >= 65))? true : false)
#define ISALPHA(ch)     ((ISSALPHA(ch) || ISCAPLHA(ch))? true : false)

#define CAPITALIZE(ch)  (ISSALPHA(ch)? ch - 32: ch)
#define SMALLIZE(ch)    (ISCAPLHA(ch)? ch + 32: ch)

#endif /* macros_h */
