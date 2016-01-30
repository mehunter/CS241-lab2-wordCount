/* Matt Hunter */

#define RETURN 0xa
#define TRUE 1
#define FALSE 0

#include <stdio.h>

char c;
int totalChars  = 0;
int lineChars   = 0;
int totalWords  = 1;
int lineWords   = 0;
int lineNumber  = 0;
int mostChars, mostCharsLine = 0;
int mostWords, mostWordsLine = 0;
int inWordFlag  = FALSE;
int newLineFlag = TRUE;

int main (void)
{
  /* Read in chars, print, and count until EOF*/
  while ( ( c = getchar() ) != EOF )
    {
      /* If we're at a new line, print the line number, then set flag to false */
      if (newLineFlag)
        {
          ++lineNumber;
          printf("%d:", lineNumber);
          newLineFlag = FALSE;
        }

      /* Check for 'RETURN', which is not counted as a character */
      /* If found, then print stuff at end of line, set flag, and count it */
      if (c == RETURN)
        {
          printf("(%i,%i)%c", lineChars, lineWords, c);
          newLineFlag = TRUE;
          totalChars += lineChars;

          /* Check to see if line is one with most characters */
          if (lineChars >= mostChars) /* Using >= instead of > per spec */
            {
              mostChars = lineChars;
              mostCharsLine = lineNumber;
            }
          
          lineChars = 0; /* reset lineChars because we're moving on to a new line */
        }

      /* Since c != return or EOF, just print c and increment counter */
      else
        {
          printf("%c", c);
          ++lineChars;
        }
    }

  /* EOF has appeared, so print lines with stats */
  printf("%i lines, %i words, %i characters\n", lineNumber, totalWords, totalChars);
  printf("Line %i has the most characters with %i\n", mostCharsLine, mostChars);
  printf("Line %i has the most words with %i\n", mostWordsLine, mostWords);

  return 0;
}
