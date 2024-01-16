#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);
extern int isEmpty();
extern void allocate_mem(char **stack);

int main(int argc, char * argv[])
{
  int ch; // Input from stdin
  char chNext;
    char *topWord = malloc(10 * sizeof(char));  // Word at the top of the stack
    char *word = malloc(10 * sizeof(char));     // Current word to be pushed/popped

  while ((ch = getchar()) != EOF) { 
 // If there are no more inputs to be inputted, stop the while loop
      break;

    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')) 
// If input is not a letter/does not contains >, <, or /, skip current while loop
      continue;

        if (ch == '<') {  // If current input is <, then it will check if the next input does or doesnt include /
            chNext = getchar();
            if (chNext == '/') {  // If input is /, compare with top of the stack and pop
                int a = 0;
                chNext = getchar();
                do {
                    word[a] = chNext;
                    a++;
                    chNext = getchar();
                } while (chNext != '>');

                topWord = pop();
                if (strcmp(word, topWord) != 0) {  // Check if the the current word is equal to the top word.
                    fprintf(stderr, "%s\n", word);
                    fprintf(stderr, "%s\n", topWord);
                    fprintf(stderr, "Error: Incorrect XML format!\n");
                    exit(1); // The program prints an error message and exits.
                }
                fprintf(stdout, "%s\n", word);

            } else {  // If input is not /, push the word into the stack
                int a = 0;
                do {
                    word[a] = chNext;
                    a++;
                    chNext = getchar();

                } while (chNext != '>');
                push(word);
            }
            for (int i = 0; i < 10; i++)  // Resets the word array
                word[i] = '\0';
        }
    }
    if (isEmpty()) {  // Checks validity of stack.
        fprintf(stdout, "Stack is empty, it is valid.\n");
        exit(0);
    } else {
        fprintf(stderr, "Stack is not empty, it is invalid.\n");
        exit(1);
  }
  return 0;
}
//the program checks if the stack is empty. If it is, the program prints a message indicating that the input is valid XML. If it is not, the program prints a message indicating that the input is invalid XML.

