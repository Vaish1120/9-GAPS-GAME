#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    int main_board[9]={1,2,3,4,5,6,7,8,9}; // It defines the main board to store all the values from 1-9
    int missing_array[9]; // This line generates an array of size 9 to keep track of missing values
    int game_board[9]; // It defines an array to form the actual game board with random numbers and hidden values
    int temp_board[9]; // It defines an array which is a copy of the game_board and will be displayed to the user and will be updated in each iteration
    int row_results[3]; // this is an array that stores the results of calculation of each row
    int column_results[3]; // this is an array that stores the results of calculation of each column
    char operators_array[12]; // this is an array that stores random operations
    int i,j,m; // these variables will be used for loop indexes
    int rand_num,temp1; // rand_num will be used to store the result of random number generations, temp1 will be used as a temporary variable
    int level; // this variable stores the level of difficulty
    char check_game; // this is a flag variable to determine if the user solves the game correctly
    int play_again; // this is a flag variable to determine if the user wants to play again or not
    int missing_count; // this is a variable that keep track of the number of missing values in the game board.
    
    srand(time(NULL));  // It generates a seed, using current time, for the random generator
 
    do{
        check_game=1;
        level=0;
        printf("Welcome to Nine-Gaps game!...\n");
	    printf("***********\n");
	    printf("      *******      \n");
	    printf("            ***            \n");
	    printf("              *              \n");
	
        // get the level of difficulty from the user
        do{
		    puts("Choose the level of difficulty (1-Beginner, 2-Intermediate, 3-Advanced, 4-Expert):");
		    scanf("%d",&level);
		    if ((level < 1) || (level > 4))
			    puts("The entered value is not valid");
		    else{
		        switch (level){
		            case 1:
		                puts("You have chosen the Beginner level");
		                break;
		            case 2:
		                puts("You have chosen the Intermediate level");
		                break;
		            case 3:
		                puts("You have chosen the Advanced level");
		                break;
		            case 4:
		                puts("You have chosen the Expert level");
		                break;
		        }
		        break;
		    }
	    } while (1);
        //////////////////////////////////////////////////
    
        // 1- generate a random main board by shuffling the main_board      (COMPLETE THIS PART)

for(j=0;j<9;)
{

i=rand()%9;

if(main_board[j]!=main_board[i])
{
    
    temp1=main_board[j];
    main_board[j]=main_board[i];
    main_board[i]=temp1;
    j=j+1;
}
}

/*for(i=0;i<9;i++)
{
printf("%d   ",main_board[i]);

if(i==2||i==5||i==8)
{
    printf("\n");
}

}*/






        /////////////////////////////////////////////////
    

        // 2- generate random operators ( + , - , x )      (COMPLETE THIS PART)
    
for(i=0;i<=11;i++)
{
rand_num=rand()%3;

if(rand_num==0)
{
    operators_array[i]='+';
}

else if(rand_num==1)
{
    operators_array[i]='-';
}

else
{
    operators_array[i]='*';
}

//printf("%c \n",operators_array[i]);

}

        /////////////////////////////////////////////////
        
        // 3- Calculate the results in columns and rows      (COMPLETE THIS PART)


m=0;
j=0;
for(i=0;i<=2;i++)
{

 if(operators_array[j]=='+')
{
    temp1=main_board[m]+main_board[m+1];  
    //printf("%d \n",temp1);   
}
else if(operators_array[j]=='-')                  
{
    temp1 =main_board[m]-main_board[m+1];
    //printf("%d \n",temp1);
}
else
{
    temp1=main_board[m]*main_board[m+1];    
    //printf("%d \n",temp1);
}

j=j+1;

if(operators_array[j]=='+')
{
row_results[i]=temp1+main_board[m+2];
   //printf("%d \n",row_results[i]);    
}

else if(operators_array[j]=='-')
{
    row_results[i]=temp1-main_board[m+2];
    //printf("%d \n",row_results[i]);
}

else
{
    row_results[i]=temp1*main_board[m+2];
    //printf("%d \n",row_results[i]);

}

j=j+1;
m=m+3;
}


j=6;
m=0;
for(i=0;i<=2;i++)
{




if(operators_array[j]=='+')
{
    temp1=main_board[m]+main_board[m+3];
      //printf("%d \n",temp1);
}

else if(operators_array[j]=='-')
{
    temp1=main_board[m]-main_board[m+3];
      //printf("%d \n",temp1);
}

else 
{
    temp1=main_board[m]*main_board[m+3];
      //printf("%d \n",temp1);
}





if(operators_array[j+3]=='+')
{
    column_results[i]=temp1+main_board[m+6];
      //printf("%d \n",column_results[i]);

}                     

else if(operators_array[j+3]=='-')
{
    column_results[i]=temp1-main_board[m+6];
       //printf("%d \n",column_results[i]);

}

else
{
    column_results[i]=temp1*main_board[m+6];
    //printf("%d \n",column_results[i]);

}

j=j+1;
m=m+1;



}

        ////////////////////////////////////////////////////////
    
        // 4- initializing missing array to 0      (COMPLETE THIS PART)

        for(i=0;i<=8;i++)
        {
            missing_array[i]=0;
        }
        
    
        ////////////////////////////////////////////////////////
        
        
        // 5- copy the main_board into game_board      (COMPLETE THIS PART)
    
for(i=0;i<=8;i++)
{
    game_board[i]=main_board[i];
}


    
        /////////////////////////////////////////////////////////
    
    
        // Based on the selected level, 3 or 5 or 7 board values will be hidden.
    
        i=0; // initializing i to 0
    
        while (i < level*2+1){								
		    int r = rand() % 3;
		    int c = rand() % 3;
		    if (game_board[3*r+c]!='?'){ 
			    missing_array[game_board[3*r+c]-1]= game_board[3*r+c]; // the hidden values will be added to the set of missing values
		        game_board[3*r+c] = '?';
			    i++;
		    } // end of if
	    } // end of while
	    ////////////////////////////////////////////////////////
	
        // 6- Copy the game board into a temporary board      (COMPLETE THIS PART)

for(i=0;i<=8;i++)
{
temp_board[i]=game_board[i];
}



        
        ///////////////////////////////////////////////////////
    
                // the inner loop to get values from the user
        do{
        
            // Display the game board after each update
            
            printf("Game Board:\n");
	        printf("---------------------------------------------------\n");
            for (i=0;i<3;i++){
                if (i>0){                   // show the column opertors
                    for (j=0;j<3;j++){
                        printf(" %c\t\t", operators_array[3*(i+1)+ j]);
                    }
                    printf("\n");
                }
                
                for (j=0;j<3;j++){          // show the rows
                    if (game_board[(i*3)+j]!='?')
                        printf(" %d\t ", temp_board[(i*3)+j]);
                    else if (game_board[(i*3)+j]!=temp_board[(i*3)+j]){
                        printf(" %d?\t ", temp_board[(i*3)+j]);
                    }
                    else
                        printf(" ?\t ");
                
                    if (j<2)
                        printf(" %c\t", operators_array[(i*2) + j]);
                    else
                        printf("= %d", row_results[i]);       // show the rows results
                }
                printf("\n");
                if (i==2)
                    printf (" =\t\t =\t\t =\n");    
            }
            for (i=0;i<3;i++)               // show the columnar results
                printf(" %d\t\t", column_results[i]);
            printf("\n---------------------------------------------------\n");
        
        ////////////////////////////////////////////////////////
        
        // 7- Display the missing values and update the missing_count variable      (COMPLETE THIS PART)
missing_count=0;
printf("missing values-     ");
for(i=0;i<9;i++)
{
    if(missing_array[i]>=1)
    {
        printf("%d \t",missing_array[i]);
        missing_count=missing_count+1;
    }
}
  
        
        /////////////////////////////////////////////////////////
        
            // 8- break if the missing values are empty      (COMPLETE THIS PART)
            
            if(missing_count==0)
             break;


	/////////////////////////////////////////////////////
			
        // Get user's guess (location and value) and check inputs' validity

	        printf("Enter a row number (1-3), column(1-3), value(One of the missing values):\n");
	        int r, c, v; 
	        scanf("%d %d %d", &r, &c, &v);
	        if (r==0 || c==0 || v==0)
	            break;
	        
	        if (r < 1 || r > 3 || c < 1 || c > 3){
	            puts("Invalid row and/or column numbers. Try again.");
	            continue;
	        }
	        
	        if (v < 1 || v > 9) {
	            puts("Invalid cell value. Try again.");
	            continue;
	        }
	        
	        if (missing_array[v-1]<1) {
	            puts("This value is already there. Try again.");
	            continue;
	        }
            
		// 9- if the selected cell is changeable, add the value into the cell and remove it from the missing values, in other case show an error and repeat the inner loop.
		//       (COMPLETE THIS PART)

    
        if(temp_board[3*(r-1)+(c-1)]=='?')
        {
            temp_board[3*(r-1)+(c-1)]=v;

        for(i=0;i<9;i++)
        {
                if(missing_array[i]==v)
                {
                    missing_array[i]=0;
                    missing_count=missing_count-1;
                }
        }

        }

        else
        {
            {
                printf("ERROR....TRY AGAIN  \n");
                continue;
            }
        }
        
         



			//////////////////////////////////////////////////////
			
        } while (1); // end of the inner loop
		
		//////////////////////////////////////////////////////////
		
		// 10- check the results      (COMPLETE THIS PART)
j=0;
for(i=0;i<9;i++)
{
    if(main_board[i]==temp_board[i])
    {
        j=j+1;
    }
}

if(j==9)
{
    check_game=1;
}

else
{
    check_game=0;
}

		//////////////////////////////////////////////////////
        
        if (check_game)             // display Wining/Losing Message
            printf ("** Congratulations!!!*\n *You Won!!!!** \n");
        else
            printf (":( Sorry it is not correct :( \n");
        
        printf("#######################################\n");
        printf ("   Do you want to play again? (Yes:1, No:0)\n"); // ask the user to play again
        printf("#######################################\n");
        scanf ("%d", &play_again);
        
        if (!play_again){
            printf("Bye!");
            break;
        }
    } while (1); // end of the outer loop
}
