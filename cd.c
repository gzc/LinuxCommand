#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int hasPrefix(char const *, char const *);
void cd(char *pth);

#define BUFFERSIZE 200

int main(){
    char buffer[BUFFERSIZE];
    char *prompt = "OS";
    char *a = ">";
    
    while(buffer != NULL){
        bzero(buffer, BUFFERSIZE);
        printf("%s%s",prompt,a);
        fgets(buffer, BUFFERSIZE, stdin);
        if(hasPrefix(buffer,"cd") == 0){
            char *tok = strchr(buffer,' '); //use something more powerful
            if(tok) {
                char *tempTok = tok + 1;
                tok = tempTok;
                char *locationOfNewLine = strchr(tok, '\n');
                if(locationOfNewLine) {
                    *locationOfNewLine = '\0';
                }
                cd(tok);
            }
        } else {
            system("ls"); //testing
        }
    }
    return 0;
}

int hasPrefix(char const *p, char const *q) {
    int i = 0;
    for(i = 0;q[i];i++) {
        if(p[i] != q[i])
            return -1;
    }
    return 0;
}

void cd(char *pth){
    char path[BUFFERSIZE];
    strcpy(path,pth);
    
    char cwd[BUFFERSIZE];
    if(pth[0] != '/') {
        getcwd(cwd,sizeof(cwd));
        strcat(cwd,"/");
        strcat(cwd,path);
        chdir(cwd);
    } else {
        chdir(pth);
    }
}