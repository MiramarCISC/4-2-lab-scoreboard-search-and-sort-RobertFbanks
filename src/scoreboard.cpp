#include "scoreboard.hpp"
#include <iostream>

using namespace std;

int calculateTotal(const int scores[], int size)
{

    if (scores == nullptr || size <= 0)   // Could use is valid size function declared later, can use || !isValidSize(size) instead so it doesnt need to recheck it over and over
    { // Why the extra line just for the brace?
        return 0;
    }
    else
    {
        int total = 0;
        for (int i = 0; i < size; i++)
            total += scores[i];
        return total;
    }
}

double calculateAverage(const int scores[], int size)
{

    if (scores == nullptr || size <= 0)
    {
        return 0.0;
    }
    else
    {
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            total += scores[i];
        }
        return (double)total / size;
    }
}

int findLowest(const int scores[], int size)
{

    if (scores == nullptr || size <= 0)
    {
        return 0;
    }
    else
    {
        int smallest = scores[0];
        for (int i = 1; i < size; i++)
        {
            if (scores[i] < smallest)
                smallest = scores[i];
        }
        return smallest;
    }
}

int findHighest(const int scores[], int size)
{

    if (scores == nullptr || size <= 0)
    {
        return 0;
    }
    int largest = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (largest < scores[i])

            largest = scores[i];
    }
    return largest;
}

int findScore(const int scores[], int size, int target)
{

    if (scores == nullptr || size <= 0) // nullptr is basically a pointer that doesn't point to anything
    {
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        if (scores[i] == target)
        {
            return i;
        }
    }
    return -1; // if it does not return i, it will return -1
}

void sortScores(int scores[], int size)
{
    if (scores == nullptr || size <= 0)
    {
        return;
    }
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int a = 0; a < size - 1; a++)
        {
            if (scores[a] > scores[a + 1])
            {
                temp = scores[a];
                scores[a] = scores[a + 1];
                scores[a + 1] = temp; // I used a bubble sort because that is what I learned, to me it is easier this way.
                // Its fine with a bubble sort, but the lab is better with a selection sort, there was an example on the quiz section that you can rewrite to make it work in this lab.
            }
        }
    }
}

void printScores(const int scores[], int size)
{
    if (scores == nullptr || !isValidSize(size))
    {
        cout << "No scores to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << scores[i];

        if (i < size - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
}

bool isValidSize(int size)
{

    if (size > 0)
    {
        return true; // if size is not greater than 0 then it will will return false. This is because it is a bool function
    }
    return false;
}
