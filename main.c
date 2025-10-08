#include <stdio.h>
#include <stdbool.h>
const char* inputFile = "input.txt";
int main(int arc, char *argv[]) {
    printf("Hello, World!\n");
    return 0;
}

char** removeDuplicates(char** lines, int* lineCount)
{

}

void writeOutputFile(char** lines, int lineCount)
{

}

char** getInputLines()
{

}

/*
 * We are going to do a greedy algorithm.
 * Since we know each datetime is the same number of characters,
 * we can just check each character position and see if the character will
 * be valid at that position.
 * 
 * There are some dependent characters, for example if in the day section and the 
 * first character is a '3', the second character can only be a '0' or '1'.
 * 
 * to handle this we will pass in a char* in that step. Here if we are on the second day in month 
 * section currentStep might be "3" or "2"
 */
bool checkCharValidForIndex(char c, int index, char* currentStep)
{

}