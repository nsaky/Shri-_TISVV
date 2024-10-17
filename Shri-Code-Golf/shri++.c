#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 30000

void print_help()
{
    printf("Shri++ Interpreter Usage:\n");
    printf("./shri++_interpreter <filename>\n");
    printf("Options:\n");
    printf("  -h, --help   Display this help message and exit.\n");
    printf("\n");
    printf("Commands (Shri++ language):\n");
    printf("  @  Move pointer to the right\n");
    printf("  #  Move pointer to the left \n");
    printf("  ^  Increment the value at the pointer\n");
    printf("  _  Decrement the value at the pointer\n");
    printf("  :  Output the integer value at the pointer\n");
    printf("  ;  Input a value and store it at the pointer)\n");
    printf("  {  Start loop\n");
    printf("  }  End loop\n");
}

char *read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (!buffer)
    {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0';
    fclose(file);

    return buffer;
}

int has_spp_extension(const char *filename)
{
    const char *ext = strrchr(filename, '.');
    return ext && strcmp(ext, ".spp") == 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Error: No input file specified.\n");
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        print_help();
        return 0;
    }

    // Check if the file has a .spp extension
    if (!has_spp_extension(argv[1]))
    {
        printf("Error: The file must have a .spp extension.\n");
        return 1;
    }

    char *program = read_file(argv[1]);
    if (!program)
    {
        return 1;
    }

    char memory[MEMORY_SIZE] = {0};
    char *ptr = memory;
    char *pc = program;

    while (*pc)
    {
        switch (*pc)
        {
        case '@':  // Move pointer to the right
            ptr++;
            break;
        case '#':  // Move pointer to the left
            ptr--;
            break;
        case '^':  // Increment value at the pointer
            (*ptr)++;
            break;
        case '_':  // Decrement value at the pointer
            (*ptr)--;
            break;
        case ':':  // Output the integer value stored at the pointer
            printf("%d", *ptr);  // Print the numeric value
            break;
        case ';':  // Input a value and store at the pointer
            scanf("%d", (int *)ptr);
            break;
        case '{':  // Start loop
            if (!*ptr)
            {
                int loop = 1;
                while (loop > 0)
                {
                    pc++;
                    if (*pc == '{')
                        loop++;
                    if (*pc == '}')
                        loop--;
                }
            }
            break;
        case '}':  // End loop
            if (*ptr)
            {
                int loop = 1;
                while (loop > 0)
                {
                    pc--;
                    if (*pc == '{')
                        loop--;
                    if (*pc == '}')
                        loop++;
                }
            }
            break;
        default:
            // Ignore non-relevant characters
            break;
        }
        pc++;
    }

    free(program);
    return 0;
}
