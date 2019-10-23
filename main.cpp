// Array Performance.cpp : Defines the entry point for the application.
//
#include "sortutils.hpp"

#include <algorithm>
#include <iostream>
#include <random>

int main()
{
    int min = -10000000;
    int max = 10000000;
    //generate the numbers
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<> dist(min, max);

    //fill our initial array
    SourceArray source;
    for (int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        std::uint32_t number = dist(engine);
        source[i] = number;
    }

    SourceArray random = source;
    SourceArray sorted = source;
    std::sort(sorted.begin(), sorted.end());
    SourceArray reversed = sorted;
    std::reverse(reversed.begin(), reversed.end());
    SourceArray organ = sorted;
    organPipeStdArray(organ);
    SourceArray rotated = sorted;
    std::rotate(rotated.begin(), rotated.begin() + 1, rotated.end());

    evaluateRawArray(random, sorted, reversed, organ, rotated);
    evaluateStdArray(random, sorted, reversed, organ, rotated);
    evaluateStdVector(random, sorted, reversed, organ, rotated);

    return 0;
}
