#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char* inputFile = "input.txt";
const char* outputFile = "output.txt";
const char* inputFormatLong = "YYYY-MM-DDTHH:MM:SS+HH:MM";
const char* inputFormatShort = "YYYY-MM-DDTHH:MM:SSZ";

long getFileSize()
{
    FILE* file = fopen(inputFile, "r");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    return size;
}

/*
* at its core this will use a hashmap or a set to store each unique datetime then skip 
* duplicates.
*/
char** removeDuplicates(char** lines, int* lineCount)
{

}

void writeOutputFile(char** lines, int lineCount)
{

}


/*
 * We are going to do a greedy algorithm.
 * Since we know each datetime is the same number of characters with the exception of TZD,
 * we can just check each character position and see if the character will
 * be valid at that position.
 * 
 * There are some dependent characters, for example if in the day section and the 
 * first character is a '3', the second character can only be a '0' or '1'.
 * 
 * to handle this we will pass in a lastchar in that step. Here if we are on the second day in month 
 * section lastChar might be "3" or "2"
 * 
 * @Param index - the index of the datetime format we are checking validity for
 * @Param c - the character we are checking
 * @Param lastChar - the previous character in the datetime string
 */
bool checkCharValidForIndex(char c, int index, char lastChar)
{
    if(index<4) // Year section
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
    if(index==4) // First dash
    {
        if(c=='-')
            return true;
        return false;
    }
    if(index==5) // First month character
    {
        if(c>='0' && c<='3')
            return true;
        return false;
    }
    if(index==6) // Second month character
    {
        if(lastChar=='1') // First month character was 1, so second can only be 0-2
        {
            if(c>='0' && c<='2')
                return true;
            return false;
        }
        else // First month character was 0 so second can be 0-9
        {
            if(c>='0' && c<='9')
                return true;
            return false;
        }
        return false; // Should never reach here
    }
    if(index==7) // Second dash
    {
        if(c=='-')
            return true;
        return false;
    }
    if(index==8) // First day character
    {
        if(c>='0' && c<='3')
            return true;
        return false;
    }
    if(index==9) // Second day character
    {
        if(lastChar=='3') // First day character was 3, so second can only be 0-1
        {
            if(c>='0' && c<='1')
                return true;
            return false;
        }
        else // First day character was 0,1,2 so second can be 0-9
        {
            if(c>='0' && c<='9')
                return true;
            return false;
        }
        return false; // Should never reach here
    }
    if(index==10) // T
    {
        if(c=='T')
            return true;
        return false;
    }
    if(index==11) // First hour character
    {
        if(c>='0' && c<='2')
            return true;
        return false;
    }
    if(index==12) // Second hour character
    {
        if(lastChar=='2') // First hour character was 2, so second can only be 0-3
        {
            if(c>='0' && c<='3')
                return true;
            return false;
        }
        else // First hour character was 0 or 1 so second can be 0-9
        {
            if(c>='0' && c<='9')
                return true;
            return false;
        }
        return false; // Should never reach here
    }
    if(index==13) // Colon
    {
        if(c==':')
            return true;
        return false;
    }
    if(index==14) // First minute character
    {
        if(c>='0' && c<='5')
            return true;
        return false;
    }
    if(index==15) // Second minute character
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
    if(index==16) // Colon
    {
        if(c==':')
            return true;
        return false;
    }
    if(index==17) // First second character
    {
        if(c>='0' && c<='5')
            return true;
        return false;
    }
    if(index==18) // Second second character
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
    if(index==19) // Z
    {
        if(c=='Z' || c=='+' || c=='-')
            return true;
        return false;
    }
    if(index==20) // First TZD hour character
    {
        if (lastChar=='Z') // If Z, there should be no TZD
            return false;
        if(c>='0' && c<='2')
            return true;
        return false;
    }
    if(index==21) // Second TZD hour character
    {
        if(lastChar=='2') // First TZD hour character was 2, so second can only be 0-3
        {
            if(c>='0' && c<='3')
                return true;
            return false;
        }
        else // First TZD hour character was 0 or 1 so second can be 0-9
        {
            if(c>='0' && c<='9')
                return true;
            return false;
        }
        return false; // Should never reach here
    }
    if(index==22) // Colon
    {
        if(c==':')
            return true;
        return false;
    }
    if(index==23) // First TZD minute character
    {
        if(c>='0' && c<='5')
            return true;
        return false;
    }
    if(index==24) // Second TZD minute character
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
}



/*
 * Read the file and return a list of strings, each string is a valid date.
 * note: its unsorted and may contain duplicates, but each string is valid.
*/
int getListOfDatesFromFile(char** output, int biggestDateSize, int smallestDateSize)
{
    FILE* file = fopen(inputFile, "r");
    char character;
    char lastChar = '\0';
    int index = 0;
    int currentDateIndex = 0;
    char* currentDate = malloc(biggestDateSize);
    while ((character = fgetc(file)) != EOF)
    {
        if(checkCharValidForIndex(character, index, lastChar))
        {
            currentDate[index] = character;
            // Valid character for this position
            lastChar = character;
            index++;
            if(index==biggestDateSize || (index ==  smallestDateSize && lastChar == 'Z')) // Reached end of longest possible date
            {   
                currentDate[index] = '\0'; // Null terminate the string
                output[currentDateIndex] = malloc(biggestDateSize);
                sprintf(output[currentDateIndex], "%s", currentDate); // Store date in output array
                index=0;
                currentDateIndex++;
                lastChar='\0';
                // Store date in output array
            }
        }
        else
        {
            // Invalid character for this position
            index=0;
            lastChar='\0';
            if(checkCharValidForIndex(character, index, lastChar)) // Check if this character can be the start of a new date
            {
                lastChar = character;
                index++;
            }
        }
        // Process character
    }
    free(currentDate);
    fclose(file);
    return currentDateIndex; // Return number of dates found
}
int compareStrings(const void *a, const void *b) {
    const char **str1 = (const char **)a;
    const char **str2 = (const char **)b;
    return strcmp(*str1, *str2);
}
 
int main(int arc, char *argv[]) {
    long fileSize = getFileSize();
    int biggestDateSize = strlen(inputFormatLong);
    int smallestDateSize = strlen(inputFormatShort);
    int maxDates = fileSize / smallestDateSize; // Worst case every date is the smallest size
    char** unfilteredDates = malloc(maxDates * sizeof(char*));
    int numDates = getListOfDatesFromFile(unfilteredDates, biggestDateSize, smallestDateSize);
    qsort(unfilteredDates, numDates, sizeof(char*), compareStrings);
    FILE* file = fopen(outputFile, "w");
    for (int i=0; i<numDates; i++)
    {
        if(i>0 && strcmp(unfilteredDates[i], unfilteredDates[i-1])==0)
        {
            // Duplicate, skip
            continue;
        }
        fprintf(file, "%s\n", unfilteredDates[i]);
    }
    fclose(file);
    for (int i=0; i<numDates; i++)
    {
        free(unfilteredDates[i]);
    }
    free(unfilteredDates);
    return 0;
}