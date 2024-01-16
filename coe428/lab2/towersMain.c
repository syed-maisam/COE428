#include "towers.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int n = 3; //tower number
  int from = 1; //inital location
  int dest = 2; // final location

  if (argc == 1) {
    towers(n, from, dest);
    exit(0);
  } // no arguments (deafult case)

  else if (argc == 2) { // 1 argument (# of disks)
    n = atoi(argv[1]);
    towers(n, from, dest);
    exit(0);
  }

  else if (argc == 4) { // 3 arguments (# of disks, Start, End)
    n = atoi(argv[1]);
    from = atoi(argv[2]);
    dest = atoi(argv[3]);
    towers(n, from, dest);
    exit(0);
  }

  else { // if invalid # of arguments are given
    int x = argc-1;
    fprintf(stderr, "ERROR: INVALID NUMBER OF ARGUMENTS GIVEN, PLEASE TRY "
                    "AGAIN         WITH EITHER 0, 1,OR 3 ARGUEMENTS \n YOU GAVE: %d ARGUEMENTS",x);
    exit(1);
  }

    	exit(0);
}

