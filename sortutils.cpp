#include "sortutils.hpp"

#include <chrono>
#include <vector>

//This function accepts an std::array and copies its elements into a raw array.
//The author assumes that the dest array is the same size and the source array; assume
//valid arrays and matching sizes are passed in (for this class, not ever for production code).
void initializeRawArrayFromStdArray(const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[])
{
    for (int i = 0; i < HOW_MANY_ELEMENTS; i++)
    {
        dest[i] = source[i];
    }
}

//This function re - organizes the values in the data array to have an organ pipe structure.
//It is assumed that data is already sorted.Refer to the notes below on what this organization looks like.
void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data)
{

    std::array<int, HOW_MANY_ELEMENTS> tmp;
    int middle = 0;
    if (HOW_MANY_ELEMENTS % 2 == 0)
    {
        for (int i = 0; i < HOW_MANY_ELEMENTS / 2; i++)
        {
            tmp[i] = data[i];
            middle = i;
        }
        for (int i = 0; i <= middle; i++)
        {
            int add = middle + i + 1;
            int sub = middle - i;
            tmp[add] = tmp[sub];
        }
    }
    else
    {
        for (int i = 0; i < HOW_MANY_ELEMENTS / 2 + 1; i++)
        {
            tmp[i] = data[i];
            middle = i;
        }
        for (int i = 0; i <= middle; i++)
        {
            int add = middle + i;
            int sub = middle - i;
            tmp[add] = tmp[sub];
        }
    }

    data = tmp;
}

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed,
                      const SourceArray& organPipe, const SourceArray& rotated)
{

    double randomTotal = 0;
    double sortedTotal = 0;
    double reversedTotal = 0;
    double organTotal = 0;
    double rotatedTotal = 0;

    int rawRandom[HOW_MANY_ELEMENTS];
    int rawSorted[HOW_MANY_ELEMENTS];
    int rawReversed[HOW_MANY_ELEMENTS];
    int rawOrgan[HOW_MANY_ELEMENTS];
    int rawRotated[HOW_MANY_ELEMENTS];

    initializeRawArrayFromStdArray(random, rawRandom);
    initializeRawArrayFromStdArray(sorted, rawSorted);
    initializeRawArrayFromStdArray(reversed, rawReversed);
    initializeRawArrayFromStdArray(organPipe, rawOrgan);
    initializeRawArrayFromStdArray(rotated, rawRotated);

    //get the total for the random array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = rawRandom;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp, tmp + HOW_MANY_ELEMENTS);

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        randomTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = rawSorted;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp, tmp + HOW_MANY_ELEMENTS);

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        sortedTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = rawReversed;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp, tmp + HOW_MANY_ELEMENTS);

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        reversedTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = rawOrgan;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp, tmp + HOW_MANY_ELEMENTS);

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        organTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = rawRotated;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp, tmp + HOW_MANY_ELEMENTS);

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        rotatedTotal += diff.count();
    }

    std::cout << " ----- Raw Array Performance -----" << std::endl;
    std::cout << "Random Time: " << randomTotal << " ms" << std::endl;
    std::cout << "Sorted Time: " << sortedTotal << " ms" << std::endl;
    std::cout << "Reversed Time: " << reversedTotal << " ms" << std::endl;
    std::cout << "Organ Pipe Time: " << organTotal << " ms" << std::endl;
    std::cout << "Rotated Time: " << rotatedTotal << " ms" << std::endl;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed,
                      const SourceArray& organPipe, const SourceArray& rotated)
{

    double randomTotal = 0;
    double sortedTotal = 0;
    double reversedTotal = 0;
    double organTotal = 0;
    double rotatedTotal = 0;

    //get the total for the random array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = random;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        randomTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = sorted;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        sortedTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = reversed;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        reversedTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = organPipe;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        organTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = rotated;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        rotatedTotal += diff.count();
    }

    std::cout << "\n ----- std::Array performance -----" << std::endl;
    std::cout << "Random Time: " << randomTotal << " ms" << std::endl;
    std::cout << "Sorted Time: " << sortedTotal << " ms" << std::endl;
    std::cout << "Reversed Time: " << reversedTotal << " ms" << std::endl;
    std::cout << "Organ Pipe Time: " << organTotal << " ms" << std::endl;
    std::cout << "Rotated Time: " << rotatedTotal << " ms" << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed,
                       const SourceArray& organPipe, const SourceArray& rotated)
{

    double randomTotal = 0;
    double sortedTotal = 0;
    double reversedTotal = 0;
    double organTotal = 0;
    double rotatedTotal = 0;

    std::vector<int> randomVector(random.begin(), random.end());
    std::vector<int> sortedVector(sorted.begin(), sorted.end());
    std::vector<int> reverseVector(reversed.begin(), reversed.end());
    std::vector<int> organVector(organPipe.begin(), organPipe.end());
    std::vector<int> rotatedVector(rotated.begin(), rotated.end());

    //get the total for the random array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = randomVector;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        randomTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = sortedVector;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        sortedTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = reverseVector;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        reversedTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = organVector;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        organTotal += diff.count();
    }

    //get the total fo the sorted array
    for (int i = 0; i < HOW_MAMY_TIMES; i++)
    {
        auto tmp = rotatedVector;
        auto start = std::chrono::steady_clock::now();

        std::sort(tmp.begin(), tmp.end());

        auto end = std::chrono::steady_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        rotatedTotal += diff.count();
    }

    std::cout << "\n ----- std::vector Performance -----" << std::endl;
    std::cout << "Random Time: " << randomTotal << " ms" << std::endl;
    std::cout << "Sorted Time: " << sortedTotal << " ms" << std::endl;
    std::cout << "Reversed Time: " << reversedTotal << " ms" << std::endl;
    std::cout << "Organ Pipe Time: " << organTotal << " ms" << std::endl;
    std::cout << "Rotated Time: " << rotatedTotal << " ms" << std::endl;
}