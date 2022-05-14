
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <ctype.h>

void func1(char *src)
{
    if(src != NULL){
        char dst[(strlen(src) + 1) * sizeof(char)]; // flawfinder: ignore
        strncpy(dst, src, strlen(src) + sizeof(char)); // flawfinder: ignore
        dst[strlen(dst)] = 0; // flawfinder: ignore
    }   
}

void func2(int fd)
{
    char *buf;
    size_t len;
    if(read(fd, &len, sizeof(len)) == -1)  // flawfinder: ignore
        return;
    if (len > 1024)
        return;
    buf = malloc(len+1); 
    if(read(fd, buf, len) == -1)    // flawfinder: ignore
        return; 
    buf[len] = '\0';
}

void func3()
{	
    char buffer[1024]; // flawfinder: ignore
    printf("Please enter your user id :");
    if(fgets(buffer, 1024, stdin) == NULL){
        return;
    }

    if (!isalpha(buffer[0]))
    {   
        char errormsg[1044]; // flawfinder: ignore
        strncpy(errormsg, buffer,1024); // flawfinder: ignore
        strcat(errormsg, " is not  a valid ID"); // flawfinder: ignore
        fprintf(stderr, "'%s'", errormsg);
 	}
}

void func4(char *foo)
{
    if(foo != NULL){
        char *buffer = (char *)malloc((strlen(foo)+1) * sizeof(char)); // flawfinder: ignore 
        strncpy(buffer, foo, sizeof(buffer) - 1); // flawfinder: ignore
        buffer[sizeof(buffer)-1] = '\0';
    }   
}



main()
{
    int y=10;
    int a[10];
    FILE *aFile; 

    func4("fooooooooooooooooooooooooooooooooooooooooooooooooooo");
    func3();
    
    aFile = tmpfile();  // flawfinder: ignore
    if(aFile == NULL){
        printf("cannot create this temporary file");
        return 0;
    }

    fprintf(aFile, "%s", "hello world");  
    fclose(aFile);  

    while (y>=0) {   
        if(y < sizeof(a) / sizeof(int))
            a[y]=y;
        y=y-1;
    }
    return 0;

}