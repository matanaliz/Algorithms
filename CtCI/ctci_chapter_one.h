#ifndef CTCL_CHAPTER_ONE_H
#define CTCL_CHAPTER_ONE_H

#include <string>
#include <set>

#include <iterator>

/* 1.1 Implement an algorithm to determine if string has all unique characters. */
bool allUnique(const std::string& str);

/* 1.2 Implement function which reverse null-terminated string. */
void reverseString(char* str);

/* 1.3 Given two strings, write a method to decide if one is permutation of the other. */
bool isPermutation(const std::string& a, const std::string& b);

/* 1.4 Write a method to replace all spaces in a string with '%20'. */
void replaceSpace(char* str, size_t len);

/* 1.5 Implement a method to perform basic string compression using counts of repeated chars. 
	e.g. aabccccdd == a2bc4d2. Should return original if compressed is same or more length. */
std::string compressString(const std::string& str);

#endif