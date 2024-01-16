void mySort (int d[], unsigned int n)
{
//initialize temp variables
int j,key;
//implement the pseudo-code for insertion sort
//for loop used to access and modify the elements in the array
for (int i = 0; i < n; i++){
j = i-1;
key = d[i];

/* do-while loop used to compare the elements in the array (provided the
conditions) */

while (j >= 0 && d[j] > key){
d[j+1] = d[j];
j--;
}

//when conditions are met, the next element is replaced

d[j+1] = key;
}
}
