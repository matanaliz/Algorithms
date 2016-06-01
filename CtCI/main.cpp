#include <iostream>
#include <array>

#include "ctci_chapter_one.h"
#include "ctci_chapter_two.h"

void print_matrix(int* matrix, size_t rows, size_t cols)
{
	for (size_t col = 0; col < cols; ++col)
	{
		for (size_t row = 0; row < rows; ++row)
			std::cout << matrix[row + col * rows] << " ";
		std::cout << "\n";
	}
}

int main(int argc, char* argv[])
{
	std::cout << "main start \n";
	char s1[] = { "abcde\0" };
	reverseString(s1);

	char s2[] = { "hello world\0\0" };
	replaceSpace(s2, 13);

	const std::string s = { "aabbbccccd" };
	const std::string compressed = compressString(s);
	
	int matrix[6] = { 1, 0, 3, 4, 5, 6};
        print_matrix(matrix, 3, 2);
	zerofyMatrix(matrix, 3, 2);
        print_matrix(matrix, 3, 2);
        
        const std::string a { "waterbottle" };
        const std::string b { "erbottlewat" };
        std::cout << isRotation(a, b) <<std::endl;

        List lst;
        lst.print();
        lst.append(1);
        lst.append(2);
        lst.append(3);
        lst.print();
        List::Node* f = lst.find(2);
        lst.remove(f);
        lst.print();
        
        lst.append(1);
        lst.append(1);
        lst.append(3);
        lst.append(5);

        lst.print();
        lst.remove_duplicates();
        lst.print();

        lst.append(8);
        lst.append(9);
        lst.append(0);

        lst.print();

        List::Node* kth = lst.kth_last(3);
        kth->print(); 
        
        lst.partition(3);
        lst.print();

	return 0;
}
