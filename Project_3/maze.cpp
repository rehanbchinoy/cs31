//
//  maze.cpp
//  project 3
//
//  Created by Rehan Chinoy on 5/4/19.
//  Copyright © 2019 Rehan Chinoy. All rights reserved.
//

#include "grid.h"
#include <iostream>
#include <cassert>
using namespace std;

bool isCourseWellFormed (string course);
int driveSegment(int r, int c, char dir, int maxSteps);
int driveCourse(int sr, int sc, int er, int ec, string course, int& nsteps);


int main()
{
    setSize(2,5);
    setWall(2,2);
    draw (2,5, 1,3);
    int ns = 0;
    int ret = driveCourse(2,5, 1,3, "n345", ns);
    cerr << "Returned: " << ret <<endl;
    cerr << "Nsteps is: " << ns << endl;
    
    }


bool isCourseWellFormed (string course)
{
    if (course == "" )
        return true;
    if (isdigit(course[0]))
    {
        cerr << "The first element was a number. " << endl;
        return false;
    }
    
    for (int k = 0; k < course.size();k++)
    {
        if (toupper(course[k]) != 'N' && toupper(course[k]) != 'S' && toupper(course[k]) != 'E' && toupper(course[k]) != 'W' && !(isdigit(course[k])))
        {
            cerr << "The element was not a number or symbol for cardinal direction " << endl;
            return false;
        }
        else if (isdigit(course[k]) && isdigit(course[k+1]) && isdigit(course[k+2]))
        {
            cerr << "There were 3 numbers in a row. " << endl;
            return false;
        }
    }
    return true;
}


int driveSegment(int r, int c, char dir, int maxSteps)
{
  
    if (isWall(r,c)) // making sure there is no wall at grid position
        return -1;
    if ((r < 1 || r > getRows()) || (c < 1 || c > getCols())) // making sure (r,c) is on the grid
        return -1;
    if (toupper(dir) != 'N' && toupper(dir) != 'S' && toupper(dir) != 'E' && toupper(dir) != 'W')
        return -1;
    if (maxSteps < 0)
        return -1;
   
    
    
    if (dir == 'N' || dir == 'n') //for north direction
    {
        int count = 0;
        for (int a = 1; a <= maxSteps && a < r; a++)
        {
            if ((r - a) > getRows() || isWall(r - a,c))
                return(count);
            else count++;
        }
        return (count);
    }
  
    
    else if (dir == 'S' || dir == 's') //for south direction
    {
        int count = 0;
        for (int a = 1; a <= maxSteps && (r + a) <= getRows(); a++)
        {
            if ((r+a) > getRows() || isWall(r + a,c))
                return(count);
            else count++;
            
        }
        return count;
    }
    
    
    else if (dir == 'E' || dir == 'e') //for east direction
    {
        int count = 0;
        for (int b = 1; b <= maxSteps && (c + b) <= getCols(); b++)
        {
            if ((b + c) > getCols() || isWall(r,b + c))
                return (count);
            else count++;
        }
        return count;
    }
    
    
    else if (dir == 'W' || dir == 'w') //for west direction
    {
        int count = 0;
        for (int b = 1; b <= maxSteps && b < c; b++)
        {
            if ((c- b) > getCols() || isWall(r,c-b))
                return count;
            else count++;
        }
        return count;
    }
    else return -1;
}


int driveCourse(int sr, int sc, int er, int ec, string course, int& nsteps)
{
    bool go_ahead = isCourseWellFormed(course); //makes sure course is valid
    if (go_ahead == false) //if not valid...
        return 2;
    if (isWall(sr,sc) || isWall(er, ec)) // makes sure there is no wall at grid positions
        return 2;
    if ((sr < 1 || sr > getRows()) || (sc < 1 || sc > getCols()) || (er < 1 || er > getRows()) || (ec < 1 || ec > getCols())) // makes sure coordinates are on the grid
        return 2;
    
    int r = sr, c = sc, max = 0, counter = 0;
    char ch = '0';
    nsteps = 0;
    
    for (int y = 0; y < course.size(); y++)
    {
        if (isalpha(course[y]))
        {
            char dir = course[y];
            if (course.size()> y+1 && isdigit(course[y+1]))
            {
                max = course[y+1] - ch; // use of 'ch' ensures accurate number
                if(course.size()> y+2 && isdigit(course[y+2]))
                    max = ((course[y+1] - ch)*10) + (course[y+2]-ch);
            }
            else max = 1;
            counter = driveSegment(r, c, dir, max);
            nsteps += counter;
            if (counter < max)
            {
                cerr << "totalsteps: " << nsteps << endl;
                return 3;
            }
            switch(dir) //updates coordinates for the next iteration
            {
                case ('N'):
                case ('n'):
                    r -= counter;
                    break;
                case ('S'):
                case ('s'):
                    r += counter;
                    break;
                case ('W'):
                case ('w'):
                    c -= counter;
                    break;
                case ('E'):
                case ('e'):
                    c += counter;
                    break;
                default: cerr << "error that isCourseWellFormed function did not catch" << endl;
            }
            counter = 0; //clear counter
        }
        
    }
    cerr << "Total steps: " << nsteps << endl;
    if (r == er && c == ec) //checks to see if car ends up at end coordinate
        return 0;
    else
        return 1;
}
