#include <stdio.h>

char c;
int totalChars  = 0;
int lineChars   = 0;
int totalWords  = 0;
int lineWords   = 0;
int lineNumber  = 0;
int mostChars, mostCharsLine = 0;
int mostWords, mostWordsLine = 0;
int inWordFlag  = 0;
int newLineFlag = 1;

int main (void)
{
  while (1) /* Read in chars, print, and count until EOF breaks loop*/
    {
      c = getchar();

      if (c == EOF) /* Test for end of file stop loop */
        {
          break;
        }

      if (newLineFlag)
        {
          ++lineNumber;
          printf("%d:", lineNumber);
          newLineFlag = 0;
        }
        
      if (c == 0xa) /* check for return, which is not counted as a character */
        {
          printf("(%i,%i)%c", lineChars, lineWords, c);
          newLineFlag = 1;
          totalChars += lineChars;

          /* Check to see if line is one with most characters */
          if (lineChars >= mostChars) /* Using >= instead of > to match Brooke */
            {
              mostChars = lineChars;
              mostCharsLine = lineNumber;
            }
          
          lineChars = 0; /* reset lineChars*/
        }

      else
        {
          printf("%c", c);
          ++lineChars;
        }
    }

  /* Loop has been broken, so time to print lines with stats */
  printf("%i lines, %i words, %i characters\n",
         lineNumber, totalWords, totalChars);
  printf("Line %i has the most characters with %i\n", mostCharsLine, mostChars);
  printf("Line %i has the most words with %i\n", mostWordsLine, mostWords);

  return 0;
}
