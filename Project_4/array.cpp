//
//  array.cpp
//  array of hope
//
//  Created by Rehan Chinoy on 5/6/19.
//  Copyright © 2019 Rehan Chinoy. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int countMatches(const string a[], int n, string target);
int detectMatch(const string a[], int n, string target);
bool detectSequence(const string a[], int n, string target, int& begin, int& end);
int detectMin(const string a[], int n);
int moveToBack(string a[], int n, int pos);
int moveToFront(string a[], int n, int pos);
int detectDifference(const string a1[], int n1, const string a2[], int n2);
int deleteDups(string a[], int n);
bool contains(const string a1[], int n1, const string a2[], int n2);
int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max);
int split(string a[], int n, string splitter);

int main()
{
    string h[7] = { "romanoff", "thor", "rogers", "banner", "", "danvers", "rogers" };
    assert(countMatches(h, 7, "rogers") == 2);
    assert(countMatches(h, 7, "") == 1);
    assert(countMatches(h, 7, "rhodes") == 0);
    assert(countMatches(h, 0, "rogers") == 0);
    assert(detectMatch(h, 7, "rogers") == 2);
    assert(detectMatch(h, 2, "rogers") == -1);
    int bg;
    int en;
    assert(detectSequence(h, 7, "banner", bg, en) && bg == 3 && en == 3);
    
    string g[4] = { "romanoff", "thor", "banner", "danvers" };
    assert(detectMin(g, 4) == 2);
    assert(detectDifference(h, 4, g, 4) == 2);
    assert(contains(h, 7, g, 4));
    assert(moveToBack(g, 4, 1) == 1 && g[1] == "banner" && g[3] == "thor");
    
    string f[4] = { "danvers", "banner", "thor", "rogers" };
    assert(moveToFront(f, 4, 2) == 2 && f[0] == "thor" && f[2] == "banner");
    
    string e[5] = { "danvers", "danvers", "danvers", "thor", "thor" };
    assert(deleteDups(e, 5) == 2 && e[1] == "thor");
    
    string x[4] = { "rhodes", "rhodes", "tchalla", "thor" };
    string y[4] = { "banner", "danvers", "rhodes", "rogers" };
    string z[10];
    assert(meld(x, 4, y, 4, z, 10) == 8 && z[5] == "rogers");
    
    string xx[5] = { "banner", "rhodes", "rogers", "stark", "tchalla" };
    string yy[4] = { "danvers", "rogers", "rogers", "thor" };
    string zzz[20];
    string aa[3] = {"thor", "banner", "stark" };
    
    assert(meld(aa, 3, yy, 4, zzz, 9 ) == -1);

    assert(meld(xx, 5, yy, 4, zzz, 7) == -1);
    
    assert(split(h, 7, "rogers") == 3);
    
    cout << "All tests succeeded" << endl;
}

//returns number of matches the target string has to elements in the array
int countMatches(const string a[], int n, string target)
{
    if (n < 0) //the number of elements to scan in the array cannot be negative
        return -1;
    
    int count = 0;
    for (int k = 0; k < n; k++)
    {
        if (a[k] == target) //checks if element in array matches target string
            count++;
    }
    return count;
}

//returns position number of element in array matching target
int detectMatch(const string a[], int n, string target)
{
    if (n < 0) //the number of elements to scan in the array cannot be negative;
        return -1;
    
    for (int k = 0; k < n; k++)
    {
        if (a[k] == target) //checks if element in array equals target string
            return k;
    }
    return -1; //no such string. if n is zero we will get a return value of -1 since we will not possibly find a match if we're not scanning any elements of the array.
}

//Find the earliest occurrence in a of one or more consecutive strings that are equal to target; set begin to the position of the first occurrence of target, set end to the last occurrence of target in that earliest consecutive sequence.
bool detectSequence(const string a[], int n, string target, int& begin, int& end)
{
    if (n <= 0) //the number of elements to scan in the array cannot be negative. if the number of elements to scan is zero, then begin and end are unchanged and return false.
        return false;
    if (countMatches(a, n, target) == 0) //if there is no target string in the array, return false.
        return false;
        
    begin = 0;
    end = 0;
    
    for (int k = 0; k < n; k++)
    {
        if (a[k] == target && a[begin] == target) //if begin is already at the target, set end to this element
            end = k;
        else if (a[k] == target) //if begin is not at the target yet, set begin to this element
            begin = k;
        else if (a[k] != target && a[begin] == target) // if begin is at the target and this element is not at the target, we've finished the sequence.
            break;
            
    }
    if (a[begin] == target && a[end] == target)
        return true;
    else if (a[begin] == target && a[end] != target) //if begin is at the target but end is not, set end and begin equal to each other because it's a sequence of 1.
    {
        end = begin;
        return true;
    }
    else return false; //unrecognized error
}

//Return the position of a string in the array such that that string is <= every string in the array.
 int detectMin(const string a[], int n)
 {
    if (n <= 0) //the number of elements to scan in the array cannot be negative or zero
        return -1;
 
    int track = 0;
 
     for (int k = 1; k < n; k++)
        {
            if (a[k] < a[track])
                track = k;
        }
    return track;
 }

//Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array. Return the original position of the item that was moved to the end.
 int moveToBack(string a[], int n, int pos)
 {
     if (n < 0 || pos >= n || pos < 0)//the number of elements to scan in the array cannot be negative, position cannot be greater than number of elements to scan or less than 0.
         return -1;
 
     string temp = a[pos]; //temp variable gets target value
 
     for (int k = pos; k < n-1 ; k++)
         a[k] = a[k+1]; //every element after the position element is shifted left
         
     a[n-1] = temp; //copy target value into last element of array
     return pos;
 }

//Eliminate the item at position pos by copying all elements before it one place to the right. Put the item that was thus eliminated into the first position of the array. Return the original position of the item that was moved to the beginning.
 int moveToFront(string a[], int n, int pos)
 {
     if (n < 0 || pos >= n || pos < 0)//the number of elements to scan in the array cannot be negative, position cannot be greater than number of elements to scan or less than 0.
         return -1;
     
    string target = a[pos]; //string at target position
    string hold = a[0]; //hold and temp are used to rotate values to the right without losing data.
    string temp = "";

    for (int k = 1; k <= pos ; k++)
    {
        temp = a[k]; //draw diagram to visualize. no data is lost and elements before the position value are shifted to the right.
        a[k] = hold;
        hold = temp;
    }
     a[0] = target; //first element gets string at target position
    
    return pos;
 }

//Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other.
int detectDifference(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0) //the numbers of elements to scan in the array cannot be negative.
        return -1;
    int k = 0;
    int position;
    
    if (n1 <= n2) //finding the lesser value between n1 and n2
        position = n1;
    else
        position = n2;
    
    for (k = 0; k < position; k++) //increment up to "position" to avoid undefined behavior
    {
        if (a1[k] != a2[k]) //if there is a difference, return the position at which the difference occurs.
            return k;
    }
    return position; // if there is no difference, return the lesser or equal value between n1 and n2, which was defined as the variable "position".
}

//For every sequence of consecutive identical items in a, retain only one item of that sequence. Suppose we call the number of retained items r. Then when this functions returns, elements 0 through r-1 of a must contain the retained items (in the same relative order they were in originally), and the remaining elements may have whatever values you want. Return the number of retained items.
int deleteDups(string a[], int n)
{
    if (n <= 0)//the number of elements to scan in the array cannot be negative. And it does not make sense to scan zero elements for duplicates.
        return -1;
    
    string temp = "";
    int dups = 0, count = 0;
    
    for (int x = 0; x < n; x++)
    {
        temp = a[0];
        for (int i = 1; i < n; i++) //no need to check first term for duplicate
        {
            if (i != (n-1) && a[i] == temp)
            {
                temp = a[i];
                a[i] = a[i+1];
                dups++; //increment every time the previous term is the same as the current one, or the definition of a duplicate
            }
            else if (i == (n-1) && a[i] == temp)
                dups++; //don't forget to increment if last element is a duplicate too
            else
                temp = a[i];
        }
        if (x == 0)
            count = dups; //make sure that dups is saved before the second run of the outer for loop
    }
    return (n - count); //total elements - dups is the number of retained elements
}

//If all n2 elements of a2 appear in a1, in the same order (though not necessarily consecutively), then return true. Return false if a1 does not so contain a2. Return false if this function is passed any bad arguments.
bool contains(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0 || n1 < n2)        //if either n1 or n2 are negative or n1 is less than n2, it will cause undefined behavior
        return false;
    else if (n2 == 0 || (n1==0 && n2==0)) //every sequence, even a sequence of 0 elements, contains a sequence of 0 elements.
        return true;
    
    int matched = 0;
    int x = 0, y = 0;
    
    
    while (y < n2) //cannot access outside of second array. use of while loop to have more control over incrementing y
    {
        for (x = 0; x < n1; x++)
        {
            if (a1[x] == a2[y])             //if both elements are the same
            {
                matched++;
                if (matched == n2)          //if the number of matched in a row is equal to the size of the second array, return true
                    return true;
                y++;
            }                             //notice that if both elements are not the same we just continue traversing the array
        }
        if (matched != n2) //make sure program is not caught in while loop if finished with for loop
            return false;
    }
    
    return false; //unrecognized error
}

//If a1 has n1 elements in nondecreasing order, and a2 has n2 elements in nondecreasing order, place in result all the elements of a1 and a2, arranged in nondecreasing order, and return the number of elements so placed. Return −1 if the result would have more than max elements or if a1 and/or a2 are not in nondecreasing order.
int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
    if ((n1 + n2) > max || n1 < 0 || n2 < 0 || max < 0)
        return -1;
    
    for (int x = 1; x < n1; x++) //no need to start at zero-th element. check to see if a1 has non-decreasing elements
    {
        if (a1[x] < a1[x-1]) //if it does not, return -1
            return -1;
            }
    
    for (int i = 0; i < n1; i++) //copies elements of a1 into result
        result[i] = a1[i];
    
    for (int y = 1; y < n2; y++) //check to see if a2 has non-decreasing elements
    {
        if (a2[y] < a2[y-1]) //if it does not, return -1
            return -1;
    }
    
    
    int z = n1;
    while (z < (n1 + n2)) //makes sure we do not try to access an element outside of result's size
    {
        for (int count = 0; count < n2; count++)
        {
            result[z] = a2[count]; //copies elements of a2 into result after the elements of a1
            z++;
        }
        if (z < (n1 +n2))
            return -1; //unrecognized error, do not want to get caught in while loop
    }
    
    string temp = "";
    
    for (int i = 0; i < (n1 + n2); i++) //sorts elements of result into non-decreasing order
    {
        for (int track = 0; track < (n1 + n2); track++)
        {
            if (track!=0 && result[track] < result[track-1])
            {
                temp = result[track]; //draw diagram to visualize. this makes sure we are preserving data while sorting.
                result[track] = result[track-1];
                result[track-1] = temp;
            }
        }
    }

    return (n1 + n2); //return number of elements in result
}

//Rearrange the elements of the array so that all the elements whose value is < splitter come before all the other elements, and all the elements whose value is > splitter come after all the other elements. Return the position of the first element that, after the rearrangement, is not < splitter, or n if there are no such elements.
int split(string a[], int n, string splitter)
{
    if (n < 0)        //the number of elements to scan in the array cannot be negative.
        return -1;
    
    int sameIndex = 0;              //set sameIndex to track where splitter would be if it was actually an element in the array
    
    for (int x = n-1; x >= 0; x--)  //iterating from the end of the array
        if (a[x] >= splitter)
            moveToBack(a, n, x);    //push current element to the end of the array and move everything to the left
        else
            sameIndex++;
    
    for (int x = 0; x < n; x++)
        if (a[x] == splitter)
        {
            string temp = a[x];   //temp variable gets the current element
            a[x] = a[sameIndex];  //set the current element to the element where the current element should be
            a[sameIndex] = temp;  //set the element in the replaced location to the temp string
            sameIndex++;      //add one to sameIndex because now it would be one to the right
        }
    
    for (int x = 0; x < n; x++)
        if (a[x] >= splitter)  //if the current element is greater than or equal to the splitter string, return the current index
            return x;
    
    return n; //if we cannot return current index, return n
}
