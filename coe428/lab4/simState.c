#include <stdlib.h>
#include <stdio.h>

/*State Machine:
A F E
B B C
C H D
D E G
E G B
F B A
G A H
H D F

The starting state is D */

typedef struct state_Machine{
    char name;
	int var;
	int number;//The states number in the array
	struct state_Machine * next_state_0;
	struct state_Machine * next_state_1;
} fsm;

fsm states[8];

//use an array to sort out the states
void init_states(){
     //State A
         states[0].name = 'A';
	 states[0].number = 0;
	 states[0].next_state_0 = states + 5; //State F
	 states[0].next_state_1 = states + 4; //State E
	 
	 //State B
	 states[1].name = 'B';
	 states[1].number = 1;
	 states[1].next_state_0 = states + 1; //State B
	 states[1].next_state_1 = states + 2; //State C
	 
	 //State C
	 states[2].name = 'C';
	 states[2].number = 2;
	 states[2].next_state_0 = states + 7; //State H
	 states[2].next_state_1 = states + 3; //State D
	 
	 //State D
	 states[3].name = 'D';
	 states[3].number = 3;
	 states[3].next_state_0 = states + 4; //State E
	 states[3].next_state_1 = states + 6; //State G
	 
	 //State E
	 states[4].name = 'E';
	 states[4].number = 4;
	 states[4].next_state_0 = states + 6; //State G
	 states[4].next_state_1 = states + 1; //State B
 
         //State F
	 states[5].name = 'F';
	 states[5].number = 5;
	 states[5].next_state_0 = states + 1; //State B
	 states[5].next_state_1 = states + 0; //State A
	 
	 //State G
	 states[6].name = 'G';
	 states[6].number = 6;
	 states[6].next_state_0 = states + 0; //State A
	 states[6].next_state_1 = states + 7; //State H
	 
	 //State H
	 states[7].name = 'H';
	 states[7].number = 7;
	 states[7].next_state_0 = states + 3; //State D
	 states[7].next_state_1 = states + 5; //State F	 
}

//print the states
void printstates(){
       int i=0;
          for(i =0; i <8; i++){
		    if(states[i].var!= 3){
			fprintf(stdout, "%c %c %c\n", states[i].name, states[i].next_state_0->name, states[i].next_state_1->name);
		 }
}
}

//main function
int main(int argc, char * argv[])
{
  int i, j=0;
  char comm[3]; //an array for taking in commands passed
  init_states();
  fsm current_State = states[3]; //Starting State of FSM which is D
  //Display to the users:
  fprintf(stdout, "Enter the commands without any spaces and hit q to quit the program. \n");
  fprintf(stdout, "Starting State: %c \n", current_State.name);
  
  while(j!=1){
  
      for(i=0; i<=4;i++){
	    scanf("%c",&comm[i]);
		if (comm[i] == '\n'){
		   printstates();
		   break;
		}
	  }
     //If the user enters 0
	  if(comm[0] == '0'){
	    fprintf(stdout, "%c\n",current_State.next_state_0->name);
		current_State = states[current_State.next_state_0->number];
	  }
	  
	   //If the user enters 1
	  if(comm[0] == '1'){
	    fprintf(stdout, "%c\n",current_State.next_state_1->name);
		current_State = states[current_State.next_state_1->number];
	  }
	  
	  //An optional quit command
	  if(comm[0] == 'q'){
	     j =1;
		 break;
	  }
  }
    //If user enter p to print
    if(comm[0] == 'p'){
	     printstates();
	  }
    //The change for zero
	if(comm[0] == 'c'){
	  if(comm[2] == '0'){
	       if(comm[4] == 'A'){
		   current_State.next_state_0 = states;
		   states[current_State.number].next_state_0 = states;
           }	
           else if(comm[4] == 'B'){
		   current_State.next_state_0 = states+1;
		   states[current_State.number].next_state_0 = states+1;
           }
           else if(comm[4] == 'C'){
		   current_State.next_state_0 = states+2;
		   states[current_State.number].next_state_0 = states+2;
           }
           else if(comm[4] == 'D'){
		   current_State.next_state_0 = states+3;
		   states[current_State.number].next_state_0 = states+3;
           }
           else if(comm[4] == 'E'){
		   current_State.next_state_0 = states+4;
		   states[current_State.number].next_state_0 = states+4;
           }
           else if(comm[4] == 'F'){
		   current_State.next_state_0 = states+5;
		   states[current_State.number].next_state_0 = states+5;
           }
           else if(comm[4] == 'G'){
		   current_State.next_state_0 = states+6;
		   states[current_State.number].next_state_0 = states+6;
           }	
           else if(comm[4] == 'H'){
		   current_State.next_state_0 = states+7;
		   states[current_State.number].next_state_0 = states+7;
           }		   
	  }  
	}
	//The change for one
	if(comm[0] == 'c'){
	  if(comm[2] == '1'){
	       if(comm[4] == 'A'){
		   current_State.next_state_1 = states;
		   states[current_State.number].next_state_1 = states;
           }	
           else if(comm[4] == 'B'){
		   current_State.next_state_1 = states+1;
		   states[current_State.number].next_state_1 = states+1;
           }
           else if(comm[4] == 'C'){
		   current_State.next_state_1 = states+2;
		   states[current_State.number].next_state_1 = states+2;
           }
           else if(comm[4] == 'D'){
		   current_State.next_state_1 = states+3;
		   states[current_State.number].next_state_1 = states+3;
           }
           else if(comm[4] == 'E'){
		   current_State.next_state_1 = states+4;
		   states[current_State.number].next_state_1 = states+4;
           }
           else if(comm[4] == 'F'){
		   current_State.next_state_1 = states+5;
		   states[current_State.number].next_state_1 = states+5;
           }
           else if(comm[4] == 'G'){
		   current_State.next_state_1 = states+6;
		   states[current_State.number].next_state_1 = states+6;
           }	
           else if(comm[4] == 'H'){
		   current_State.next_state_1 = states+7;
		   states[current_State.number].next_state_1 = states+7;
           }		   
	  }  
	}
	exit(0);
}

