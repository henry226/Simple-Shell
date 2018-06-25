#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pwd.h> 
#define _GNU_SOURCE

#define BUFFER_LEN 1024


int system_fork(char **args);
void help_fun();
void users();
void show_hisotry(char arg[]);
int change_dir(char * arg);

int main() {
	
	// Declaring all the variables here
	char line[BUFFER_LEN];
	char * argv[100];
	char * token;
	char history[100][100];
	int history_counter = 0;
	int n = 0;
	int m = 0;
	char * temp;
	const char ch = '!'; 
   	char *p;
	char toNum;
	
	while(1) {

		printf("ML>> ");
	
		// Get the input
		if(!fgets(line, BUFFER_LEN, stdin))
	    		break;

		// Take out all line breaks
		size_t length = strlen(line);
		if (line[length - 1] == '\n') {
		    line[length - 1] = '\0';
		}
		
		// Exit commend
		if(strcmp(line, "exit")==0) {            
			break;
	    }

		// Seperate lines into tokens
		token = strtok(line," ");
		
		int i=0;
		while(token!=NULL){
			argv[i]=token; 
   			p = strchr(token, ch);   
			if(p) {	

			}
			else {
				strcpy(history[history_counter], token);
				history_counter++; 
			}

			token = strtok(NULL," ");
			i++;
			
	    }

		
		argv[i]=NULL;
		if(argv[0] == NULL)
			continue;
		
		//Set Counter
		int counter = i;
		
		p = strchr(argv[0], ch);
		
		if(strcmp(argv[0],"!!") == 0){
			strcpy(argv[0], history[history_counter-1]);
		}
		else if(p) {
			if(strcmp(argv[0],"!") == 0) {
				printf("!: commend not found\n");
				continue;
			}
			else {
				argv[0] = strtok(argv[0], "!");
				toNum = atoi(argv[0]) - 1;
				if(toNum > history_counter) {
					strcpy(argv[0], "-100");
				}
				else
					strcpy(argv[0], history[toNum]);
			}
		}

		

		if(strcmp(argv[0],"help") == 0 || strcmp(argv[0],"cd") == 0 || strcmp(argv[0],"users") == 0 || strcmp(argv[0],"history") == 0) {
			if(strcmp(argv[0],"help") == 0)
				help_fun();

			if(strcmp(argv[0],"cd") == 0) {
				if(argv[1] != NULL)
					change_dir(argv[1]);
					
				else
					printf("Please enter your directory\n");
			}

			if(strcmp(argv[0],"users") == 0)
				users();
			
			if(strcmp(argv[0],"history") == 0) {
				for(n=0; n<history_counter; n++)
					show_hisotry(history[n]);
			}
		}
		else if(strcmp(argv[0],"-100") == 0 || strcmp(argv[0],"") == 0) {
			printf("Error, not in the history list.\n");
			continue;
		}
		else {
			system_fork(argv);
		}

	}
	
}

int system_fork(char **args){
  
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
	printf("%s: commend not found\n", args[0]);
    }
    exit(EXIT_FAILURE);
  } 
 else {
   wait(NULL);
  }

  return 1;
}


int change_dir(char * arg) {
	
	int r = chdir(arg);
	return 1;
}

void help_fun() {
	printf("Meng-Tse Li's Shell\n");
	printf("The following are built in:\n");
	printf("cd\n");
	printf("exit\n");
	printf("help\n");
	printf("users\n");
	printf("hisotry\n");
	printf("!!\n");
	printf("!n\n");
}

void users() {
	char *name; 
	struct passwd *pass; 
	pass = getpwuid(getuid()); 
	name = pass->pw_name; 
	printf("The user is: %s\n", name);
}

void show_hisotry(char arg[]) {
	if(strcmp(arg, "cd") == 0) {
		printf("%s ", arg);
	}
	else
		printf("%s\n", arg);
}
