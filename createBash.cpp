/*
  CPSC 3521 Project #1 
  July 20 2017 
   Programmers: 
	   Anas Elhadidy 
	   Aaron Matthews
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	/* The command buffer */
	string cmdBuff;
	
	/* The ID of the child process */
	pid_t pid;
	
	/* Keep running until the user has typed "exit" */
	do 
	{
		/* Prompt the user to enter the command */
		cerr << "cmd>";
		cin >> cmdBuff;
		
		/* If the user wants to exit */
		if(cmdBuff != "exit")
		{
			/* TODO: Create a child */
			pid = fork(); 
			/*** TODO: If I am child, I will do this: ****/
			if (pid == 0) 
			{
				cout << " I am the child, and I am executing your command, please see below: " << endl;
					/* Call execlp() to replace my program with that specified at the command line.
					 * PLEASE NOTE: YOU CANNOT PASS cmdBuff DIRECTLY to execlp(). It is because 
					 * cmdBuff is an object of type string (i.e., a class) and execlp() expects
					 * an array of characters.  However, you can pass cmdBuff.c_str(), which will
					 * return an array of characters representation of the string object.
					 */
				execlp (cmdBuff.c_str(), cmdBuff.c_str(),NULL); 
					// Also, please do not forget to error check your exelp() system
					
					
					
					`
                perror ( " I could not execute your command ");
			    exit (1);				
			}	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
			/*** TODO: If I am a parent, I will do the following ***? */
			else if (pid >0 ) // parent 
			{
					/* Wait for the child process to terminate */			
				wait (NULL);
				cout << " I waited for the child to finish executing,then I took over as a parent afterwards... "  << endl; 
			}
			/* TODO: Error check to make sure the child was successfully created */			
			else // if it is not a parent or child 
			{
				cout << " Fork fialed! Please contact your coders and yell at them... " << endl; 
			}	
		}
	}
	while(cmdBuff != "exit");	
	return 0;	
}
