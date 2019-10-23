#pragma once
#include <array>
#include <iostream>

//const std::size_t HOW_MANY_ELEMENTS = 250000;
const std::size_t HOW_MANY_ELEMENTS = 250000;
const std::uint8_t HOW_MAMY_TIMES = 25;
using SourceArray = std::array<int, HOW_MANY_ELEMENTS>;

//This function accepts an std::arrayand copies its elements into a raw array.
//The author of assumptions is that the dest array is the same sizeand the source array; assume
//valid arraysand matching sizes are passed in(for this class, not ever for production code).
void initializeRawArrayFromStdArray(const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[]);

//This function re - organizes the values in the data array to have an organ pipe structure.
//It is assumed that data is already sorted.Refer to the notes below on what this organization looks like.
void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data);
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed,
                      const SourceArray& organPipe, const SourceArray& rotated);
void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed,
                      const SourceArray& organPipe, const SourceArray& rotated);
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed,
                       const SourceArray& organPipe, const SourceArray& rotated);