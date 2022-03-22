#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Hello World\n");
    printf("%s\n", argv[1]);
    
    FILE *fileptr;
    char *buffer;
    long filelen;

    fileptr = fopen(argv[1], "rb");  // Open the file in binary mode
    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    buffer = (char *)malloc(filelen * sizeof(char)); // Enough memory for the file
    fread(buffer, filelen, 1, fileptr); // Read in the entire file
    fclose(fileptr); // Close the file
    
    for (int i=0; i<filelen; i++) { // sizeof(buffer) only gives like 7
        printf("%02X ", buffer[i]);
    }
    
    printf("\nfilelen: %ld\nbuffer: %s\n", filelen, buffer);
    
    return 0;
}
