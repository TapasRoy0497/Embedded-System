#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"
#include "types.h"
#include "common.h"
/* Function definitions */

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if (strcmp(strstr(argv[2], ".bmp"), ".bmp") == 0) // check if .bmp file is passed in CLA
    {
        decInfo -> stego_image_fname = argv[2]; // store the address of the file in variable
    }
    else
    {
        return e_failure; // .bmp file is not passed
    }
    if(argv[3] != NULL) // check if the third argument is passed
    {
        decInfo -> dest_fname = argv[3]; // store the address of the file in the variable
    }
    else
    {
        decInfo -> dest_fname = "decode.txt"; // create a file and store the address in the variable
    }
    return e_success;
}

/*
 * Get File pointers for i/p and o/p files
 * Inputs       : Src Image file, Secret file and Stego Image file
 * Output       : FILE pointer for above files
 * Return Value : e_success or e_failure, on file errors
 */

Status open_files_decode(DecodeInfo *decInfo)
{
    // Src Image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");
    // Doing Error handling
    if (decInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

        return e_failure;
    }

    // Secret file
    decInfo->fptr_dest_file = fopen( decInfo->dest_fname, "w");
    // Doing Error handling
    if (decInfo->fptr_dest_file == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->dest_fname);

        return e_failure;
    }

    // No failure return e_success
    return e_success;
}

Status decode_magic_string(char *magic_string,DecodeInfo *decInfo)
{
    //jumping to 54 th byte of encoded image
    fseek(decInfo -> fptr_stego_image,54,SEEK_SET);
    char buff[8];
    char new = 0;

    for(int i = 0; i < strlen(magic_string); i++)
    {
        memset(buff,0,8);

        //copy the 8 bytes from stego image to buffer
        fread(buff,1,8,decInfo -> fptr_stego_image);
        int s = 0;

        //decode those bytes to get magic strings
        s = decode_lsb_to_byte(8, buff);
        printf("magic string: %c\n", s);

    }
    return e_success;
}

/*Decode secret file extension size*/
Status decode_secret_file_extn_size(const char *secret_fname,DecodeInfo *decInfo)
{
    //
    char *f = (char*)secret_fname;
    int count=0;
    while(*f != '.')
    {
        f++;
    }

    //count the extn size
    while(*f++)
    {
        count++;
    }
    int new=0;

    //allocate the memory dynamically
    char *buff = malloc(count*8);

    //read the byte from stego image into buffer
    fread(buff,1,count*8,decInfo -> fptr_stego_image);


    //decode those extracted byte to get extn size
    int s=decode_lsb_to_byte(count*8, buff);

    return e_success;
}

/*Decode secret file extension */
Status decode_secret_file_extn(const char *secret_fname,DecodeInfo *decInfo)
{
    char *f = (char*)secret_fname;
    int count=0;

    //logic to get the size of extn
    while(*f != '.')
    {
        f++;
    }
    while(*f++)
    {
        count++;
    }

    //repeat until count reach
    for(int i = 0; i < count ; i++)
    {
        char *buff = calloc(8,sizeof(char));
        fread(buff,1,8,decInfo -> fptr_stego_image);

        char s=decode_lsb_to_byte(8, buff);

    }
    return e_success;
}
/*decode the secrete file size */

Status decode_secret_file_size(DecodeInfo *decInfo)
{
    char buff[64];

    //fetch the 64 bytes from stego image into buffer
    fread(buff,1,64,decInfo -> fptr_stego_image);

    long s = decode_lsb_to_byte(64,buff);
    decInfo->size_dest_file = s;

    return e_success;
}


/* decode the secrete file data */

Status decode_secret_file_data(DecodeInfo *decInfo)
{
    //repeat untill reaches the file size
    for(int i = 0; i < 24 ;i++)
    {
        //allocat a memory  for every character
        char *buff = calloc(8,sizeof(char));


        //fetching a 8 bytes from encoded image
        fread(buff,1,8,decInfo -> fptr_stego_image);

        char s = decode_lsb_to_byte(8,buff);
        fprintf(decInfo -> fptr_dest_file,"%c", s);
    }

    fprintf(decInfo -> fptr_dest_file, "\n");
    return e_success;
}

/*
   logic to extract lsb bits from the buffer. Buffer containf extracted bytes from stego image
 */
int decode_lsb_to_byte(int size, char *image_data)
{
    int new = 0;
    for(int i = 0; i < size;i++)
    {
        if (i != (size - 1))
            new = (new | (*(image_data + i) & 1)) << 1;
        else
            new = (new | (*(image_data + i) & 1));
    }
    return new;
}

Status do_decoding(DecodeInfo *decInfo)
{
    if( open_files_decode(decInfo) == e_success)
    {
        printf("open files succesful\n");

        if(decode_magic_string(MAGIC_STRING, decInfo) == e_success)
        {
            printf("magic string success\n");

            if(decode_secret_file_extn_size(decInfo->dest_fname,decInfo)==e_success)
            {
                printf("secret file extn size success\n");

                if(decode_secret_file_extn(decInfo->dest_fname,decInfo)==e_success)
                {
                    printf("secret file extn success\n");
                    
                    if (decode_secret_file_size(decInfo) == e_success)
                    {
                        printf("Secret file size successful\n");

                        if(decode_secret_file_data(decInfo) == e_success)
                        {   
                            printf("secret data success\n");
                        }   
                        else
                        {
                            printf("secret data fail\n");
                            return 1;
                        }
                    }
                    else
                    {
                        printf("Secret file size unsuccessful\n");
                        return 1;
                    }
                }
                else
                {
                    printf("secret file extn fail\n");
                    return 1;
                }
            }
            else
            {
                printf("secret file extn size fail\n");
                return 1;
            }
        }
        else
        {
            printf("magic string fail\n");
            return 1;
        }
    }
    else
    {
        printf("open files unsuccesful\n");
        return 1;
    }
    return e_success;
}
