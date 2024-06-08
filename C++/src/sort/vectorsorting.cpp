/*
 * vectorsorting.cpp
 *
 *  Created on: Oct 23, 2020
 *      Author: rehanashraf
 */


#include<iostream>
#include<vector>
using namespace std;

// Driver function to sort the vector elements
// by second element of pairs
bool sortbysecascending(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}


// Driver function to sort the vector elements by
// second element of pair in descending order
bool sortbysecdescing(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}


int sortascendingfirst()
{
    // Declaring vector of pairs
    vector< pair <int,int> > vect;

    // Initializing 1st and 2nd element of
    // pairs with array values
    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Entering values in vector of pairs
    for (int i=0; i<n; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );

    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;

    }

    // Using simple sort() function to sort
    sort(vect.begin(), vect.end());

     // Printing the sorted vector(after using sort())
    cout << "The vector after sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }

    return 0;
}


int sortsecondasscending()
{
    // declaring vector of pairs
    vector< pair <int, int> > vect;

    // Initialising 1st and 2nd element of pairs
    // with array values
    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Entering values in vector of pairs
    for (int i=0; i<n; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );

    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;

    }

    // Using sort() function to sort by 2nd element
    // of pair
    sort(vect.begin(), vect.end(), sortbysecascending);

    // Printing the sorted vector(after using sort())
    cout << "The vector after sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
    return 0;
}

int sortfirstdescending()
{
    // declaring vector of pairs
    vector< pair <int,int> > vect;

    // initializing 1st and 2nd element of
    // pairs with array values
    int arr[] = {5, 20, 10, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Entering values in vector of pairs
    for (int i=0; i<n; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );

    // Printing the original vector(before sort())
    cout << "The vector before applying sort is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;

    }

    // using modified sort() function to sort
    sort(vect.rbegin(), vect.rend());

    // Printing the sorted vector(after using sort())
    cout << "The vector after applying sort is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
    return 0;
}

int sortseconddesecnding()
{
    // Declaring vector of pairs
    vector< pair <int,int> > vect;

    // Initializing 1st and 2nd element of
    // pairs with array values
    int arr[] = {5, 20, 10, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Entering values in vector of pairs
    for (int i=0; i<n; i++)
        vect.push_back( make_pair(arr[i],arr1[i]) );

    // Printing the original vector(before sort())
    cout << "The vector before sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
            << vect[i].second << endl;
    }

    // using modified sort() function to sort
    sort(vect.begin(), vect.end(), sortbysecdescing);

    // Printing the sorted vector(after using sort())
    cout << "The vector after applying sort operation is:\n" ;
    for (int i=0; i<n; i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }
    return 0;
}

