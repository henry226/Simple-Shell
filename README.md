# Shell Project

### 1. Internal commant “help” to see what the internal commands are.  
```sh
ML>> help
Meng-Tse Li's Shell
The folloowing are built in:
cd
exit
help
users
history
!!
!n
```  
### 2. External command “ls” and internal command “cd” to see and change my file directory.
```sh
ML>> ls
Makefile myshell myshell.c
ML>> cd ../
ML>> ls
Desktop Documents Downloads examples.desktop hello hello.c hi Makefile Music myshell myshell.c Pictures Public
shell shell.c Templates text text.c Video
```  
### 3. “users” command to see the user.
```sh
ML>> users
The user is: henry
ML>>
```  
### 4. “history” command to see all the commands I did in the past.
```sh
ML>> history
ls
cd ../
ls
help
clear
users
history 
clear
history
clear
history
ML>>
```
### 5. “!!” command which executes the last command I had executed. In this case, the last command I did was “history”.
```sh
ML>> history
ls
cd ../
ls
help
clear
users
history 
clear
history
clear
history
ML>> !!
ls
cd ../
ls
help
clear
users
history 
clear
history
clear
history
ML>>
```