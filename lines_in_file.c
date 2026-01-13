/******************************************************************************
 * BSD Zero Clause License
 *
 * Copyright (c) 2026 Nick Teeter
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MY_BUFFER_SIZE 1024
#define FILENAME "lines_in_file.c"


/******************************************************************************
 * Function: lines_in_file() -> int
 *****************************************************************************/
int lines_in_file(const char *filename, int *result)
{
    FILE *file_ptr = fopen(filename, "r");
    if(!file_ptr)
    {
        perror("Error");
        return EXIT_FAILURE;
    }

    char buffer[MY_BUFFER_SIZE] = {0};
    *result = 0;

    while(fgets(buffer, sizeof(buffer), file_ptr) != NULL)
    {
        if(strchr(buffer, '\n') == NULL)
        {
            int c;
            while((c = fgetc(file_ptr)) != '\n' && c != EOF)
                ;
        }
        ++(*result);
    }

    fclose(file_ptr);

    return EXIT_SUCCESS;
}


// Example usage
int main(void)
{
    int lines = 0;
    int ret_val = lines_in_file(FILENAME, &lines);
    if(ret_val == EXIT_FAILURE)
    {
        fprintf(stderr, "Error: getting lines in file\n");
        return EXIT_FAILURE;
    }

    printf("File \"%s\" contains %d lines.\n", FILENAME, lines);

	return EXIT_SUCCESS;
}
