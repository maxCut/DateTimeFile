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