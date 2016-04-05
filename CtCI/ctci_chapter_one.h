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

/* 1.6 Given an image represented by NxN matrix, where each pixel in the image is 4 bytes, 
	write a method to rotate image in place.*/
void rotateMatrix(int* matrix, size_t n);

/* 1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0*/
void zerofyMatrix(int* matrix, size_t m, size_t n);

/* 1.8 Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings,
	s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g., "waterbottle" is a 
	rotation of "erbottlewat")*/
bool isRotation(const std::string& a, const std::string& b);

#endif