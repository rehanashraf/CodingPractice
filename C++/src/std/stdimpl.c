//
//  itoa.c
//  leetcode
//
//  Created by Rehan Ashraf on 5/29/23.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define SIZE_OF(type) ((char*)(&type +1) - (char*)(&type)) 
// A utility function to reverse a string
void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

char *convert(unsigned int num, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50] = {0};
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);

    return(ptr);
}

// Implementation of citoa()
char* citoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitly, otherwise empty string is
     * printed for 0 */
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled
    // only with base 10. Otherwise numbers are
    // considered unsigned.
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}

// Driver program to test implementation of itoa()
int runItoA()
{
    char str[100];
    printf("Number: %d\nBase: %d\tConverted String: %s\n",
           1567, 10, citoa(1567, str, 10));
    printf("Base: %d\t\tConverted String: %s\n", 2,
           citoa(1567, str, 2));
    printf("Base: %d\t\tConverted String: %s\n", 8,
           citoa(1567, str, 8));
    printf("Base: %d\tConverted String: %s\n", 16,
           citoa(1567, str, 16));
    return 0;
}

int catoi(char *str) {
    // Initialize result
    int res = 0;
 
    // Initialize sign as positive
    int sign = 1;
 
    // Initialize index of first digit
    int i = 0;
 
    // If number is negative,
    // then update sign
    if (str[0] == '-') {
        sign = -1;
 
        // Also update index of first digit
        i++;
    }
 
    // Iterate through all digits
    // and update the result
    for (; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    // Return result with sign
    return sign * res; 
}

void Myprintf(char* format,...)
{
    char *traverse;
    unsigned int i;
    char *s;

    //Module 1: Initializing Myprintf's arguments
    va_list arg;
    va_start(arg, format);

    for(traverse = format; *traverse != '\0'; traverse++)
    {
        while( *traverse != '%' )
        {
            putchar(*traverse);
            traverse++;
        }

        traverse++;

        //Module 2: Fetching and executing arguments
        switch(*traverse)
        {
            case 'c' : i = va_arg(arg,int);        //Fetch char argument
                        putchar(i);
                        break;

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0)
                        {
                            i = -i;
                            putchar('-');
                        }
                        puts(convert(i,10));
                        break;

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break;

            case 's': s = va_arg(arg,char *);         //Fetch string
                        puts(s);
                        break;

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break;
        }
    }

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg);
}

void myMemCpy(void *dest, void *src, size_t n) 
{ 
    // Typecast src and dest addresses to (char *) 
    char *csrc = (char *)src; 
    char *cdest = (char *)dest; 
    
    // Copy contents of src[] to dest[] 
    for (int i=0; i<n; i++) 
        cdest[i] = csrc[i]; 
} 

void myMemMove(void *dest, void *src, size_t n) 
{ 
    // Typecast src and dest addresses to (char *) 
    char *csrc = (char *)src; 
    char *cdest = (char *)dest; 
    
    // Create a temporary array to hold data of src 
    char *temp = malloc(n * sizeof(char)); 
    
    // Copy data from csrc[] to temp[] 
    for (int i=0; i<n; i++) 
        temp[i] = csrc[i]; 
    
    // Copy data from temp[] to cdest[] 
    for (int i=0; i<n; i++) 
        cdest[i] = temp[i]; 
    
    free(temp); 
}

char* my_strcpy(char* destination, const char* source)
{
    if (destination == NULL) {
        return NULL;
    }
    char *ptr = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

char* my_strcat(char* destination, const char* source)
{
    char* ptr = destination + strlen(destination);
    while (*source != '\0') {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}

uint32_t my_strlen(char *source){
    uint32_t rv = 0;
    while(*source != '\0') {
        source++;
        rv++;
    }
    return rv;
}