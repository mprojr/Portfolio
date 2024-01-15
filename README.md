Text Processing and Search Application
--------------------------------------

Description:
This C++ application provides a set of functionalities for processing text documents. 
It reads documents, extracts and sorts unique words, performs various search operations (such as AND, OR, NOT searches), and indexes words using a hash table. 
The program supports indexing each line of a document into a vector and filters each word from the given text, removing duplicates and sorting them.

Features:
Document Indexing: Reads a document and indexes each line.
Unique Word Extraction: Filters and sorts unique words from the text.
Search Operations: Supports AND, OR, NOT, and combined search operations.
Hash Table Implementation: Utilizes a hash table for efficient word indexing and searching.
Installation
To run this program, you need a C++ compiler installed on your system. You can compile the program using any standard C++ compiler like GCC or Clang.

Usage:
To use this application, compile the source code and run the resulting executable with the following command-line arguments -

./ProjectName <Text_Input_File> <Instruction_Input_File> <Hash_Matrix_Output_File> <Instruction_Result_File>

Text_Input_File: The path to the text file you want to process.
Instruction_Input_File: The path to the file containing search instructions.
Hash_Matrix_Output_File: The path where the hash matrix will be written.
Instruction_Result_File: The path where the results of the instruction processing will be written.

Example:
Here's an example of how to run the application:

./TextSearchApp input.txt instructions.txt hash_matrix.txt results.txt

Make sure input.txt and instructions.txt are valid files in the directory from which you run the program.
Hash_matrix.txt and results.txt will be output files created to demonstrate the results of the first two arguments.

Contributing:
Contributions to this project are welcome. Please feel free to fork the repository, make changes, and submit pull requests.

License:
MIT License

Copyright (c) [2023] [Martin Rodriguez]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
