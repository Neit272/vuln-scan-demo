#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memcpy_01_bad() {
    char * data;
    char dataBuffer[10];
    data = dataBuffer;
    
    // FLAW: Get data from environment variable without length check
    char * environment_var = getenv("ADD");
    
    if (environment_var != NULL) {
        // This pattern (getenv -> strcpy) triggers the model
        strcpy(data, environment_var);
    }
}
