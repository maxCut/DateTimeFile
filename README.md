# DateTimeFile

Enviorment: 
Window 10
gcc version 13.2.0

Description:
This is a c program that takes an input file, parses out all unique date times that follow the valid format, and writes all uniquely found date times to an output file.

Performance:
- This program relies on qsort to sort the list of valid date times. This can result in a worst case run time of O(nlogn)

Precompile: 
- in main.c 
    - replace the input file name with the desired input text file.
    - replace the output file name with the deisred output text file

Compile: gcc main.c

Usage: ./a.exe

Next Steps
- Replacing the qsort implementation of filtering out duplicate date times with a hashset. This would improve performance, converting the step from O(nlogn) to O(n). 

- having input and output files be passed in as commandline args. This would make it easier to use, and make it so the program doesnt need to be recopiled to update the input/output files.

- using a regex parser to match the file format. This will make the code more readable.