#include <stdio.h>
#include <string.h>
#include "common.h"
#include "encode.h"
#include "types.h"

/* Function Definitions */

/*
    Read and validate command line arguments.
    Input  : Command line arguments, Structure pointer.
    Output : Validate args and return -e_success/e_failure.
 
*/
Status read_and_validate_encode_args(char *argv[], EncodeInfo * encInfo)
{
	if (strcmp(strstr(argv[2], ".bmp"), ".bmp") == 0) // check if .bmp file is passed in CLA
	{
		encInfo -> src_image_fname = argv[2]; // store the address of the file in variable
	}
	else
	{
		return e_failure; // .bmp file is not passed
	}
	if (strcmp(strstr(argv[3], ".txt"), ".txt") == 0) // check if .txtfile is passed in CLA
	{
		encInfo -> secret_fname = argv[3]; // store the address of the file in the variable
	}
	else
	{
		return e_failure; // .txt file is not passed
	}
	if(argv[4] != NULL) // check if the fourth argument is passed
	{
		encInfo -> stego_image_fname = argv[4]; // store the address of the file in the variable
	}
	else
	{
		encInfo -> stego_image_fname = "stego.bmp"; // create a file and store the address in the variable
	}
    return e_success;
}

/* Get image size
 * Input       : Image file ptr
 * Output      : width * height * bytes per pixel (3 in our case)
 * Description : In BMP Image, width is stored in offset 18,
 		  and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs       : Src Image file, Secret file and Stego Image file
 * Output       : FILE pointer for above files
 * Return Value : e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Doing Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Doing Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    
    // Doing Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }

    // No failure return e_success
    return e_success;
}

/*
 check capacity
 Input       : EncodeInfo - image capacity and secret file size
 Output      : Status: success if true
 Description : BMP Image size should be able to handle 1:8 
 		ratio encoding excluding the header 54 bytes
 */
Status check_capacity(EncodeInfo *encInfo)
{
	encInfo-> image_capacity =  get_image_size_for_bmp(encInfo->fptr_src_image);
        //printf("file size = %u\n", encInfo->image_capacity);
	encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);
	if(encInfo -> image_capacity > (16 + 32 + 32 + 32 + ( 8 * encInfo ->size_secret_file)))
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}	
}

/*
 Get size of secret file file 
 Input        : Struct pointer to Encode Info 
 Output       : Size of secret file file
 Return Value : Size of secret file file
 */

uint get_file_size(FILE *fptr)
{
	fseek(fptr, 0, SEEK_END);
	return ftell(fptr);
}

/*
 Copy header of bmp file to stegano file
 Input        : Source Image file, Secret file and Stegano Image file 
 Output       : Header of bmp file copied to stegano file as its header
 Return Value : e_success or e_failure
 */

Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
	char str [54];
	fseek(fptr_src_image, 0, SEEK_SET);
	fread (str, sizeof(char), 54, fptr_src_image);
	fwrite(str, sizeof(char), 54, fptr_dest_image);
	return e_success;
}  

/*
 Encode Magic Pattern
 Input        : Magic Pattern as given in header file
 Output       : Magic pattern encoded 
 Return value : e_success or e_failure
 */
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    encode_data_to_image(magic_string, strlen(magic_string), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

/* Encode function, which does the real encoding */
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image, EncodeInfo *encInfo)
{
    int i;
    for(i=0 ; i < size ; i++)
    {
        fread(encInfo->image_data, sizeof(char), 8, encInfo->fptr_src_image);
        encode_byte_to_lsb(data[i], encInfo->image_data);
        fwrite(encInfo->image_data, sizeof(char), 8, encInfo->fptr_stego_image);
    }
    return e_success;
}

/* Encode a byte into LSB of image data array */
Status encode_byte_to_lsb(char data, char * image_buffer)
{
    int i;
    unsigned int mask = 1 << 7;
    for(i = 0 ; i < 8 ; i++)
    {
        image_buffer[i] = (image_buffer[i] & 0xFE) | ((data & mask) >> (7 - i));
        mask = mask >> 1;
    }
}

/* Encode Secret file extension size */
Status encode_secret_file_extn_size(int size, FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char str[32];
    fread(str, 32, 1, fptr_src_image);
    encode_size_to_lsb(str, size);
    fwrite(str, 32, 1, fptr_dest_image);
    return e_success;
}

/* Encode size to lsb of image data */
Status encode_size_to_lsb(char *buffer, int size)
{
    int i;
    unsigned int mask = 1 << 31;
    for(i = 0 ; i < 32 ; i++)
    {
        buffer[i] = (buffer[i] & 0xFE) | ((size & mask) >> (31 - i));
        mask = mask >> 1;
    }
}


/* 
 Encode Secret file extension
 Input        : Secret file name
 Output       : Secret file name extension
 Return value : e_success or e_failure
 */
Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo)
{
    encode_data_to_image(file_extn, strlen(file_extn), encInfo->fptr_src_image, encInfo->fptr_stego_image, encInfo);
    return e_success;
}

/* 
 Encode Secret file size into the Stegano file
 Input        : file size, Structure Pointer to Encoding Info
 Output       : Secret file size encoded into Stegano file
 Return Value : e_success or e_failure
 */
Status encode_secret_file_size(int size, EncodeInfo *encInfo)
{
    char str[32];
    fread(str, 32, 1, encInfo->fptr_src_image);
    encode_size_to_lsb(str, size);
    fwrite(str, 32, 1, encInfo->fptr_stego_image);
    return e_success;
}

/*
 Encode Secret file data
 Input        : Source Image file, Source Text file  
 Output       : Stegano Image file
 Return Value : e_success or e_failure
 */

Status encode_secret_file_data(EncodeInfo *encInfo)
{
    fseek(encInfo->fptr_secret, 0, SEEK_SET);
    char ch;
    int i;
    for(i = 0;i < encInfo -> size_secret_file ; i++ )
    {
        fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);
        fread(&ch, 1, 1, encInfo->fptr_secret);
        encode_byte_to_lsb(ch, encInfo->image_data);
        fwrite(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    }
    return e_success;
}

/* 
 Copy remaining Source Image Data bytes to Stegano Image fileafter encoding
 Input        : FILE pointer to Source Image file and Destination Stegano file 
 Output       : Stegano file complete
 Return Value : e_success or e_failure
 */
Status copy_remaining_img_data(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char ch;
    while(fread(&ch, 1, 1, fptr_src_image) > 0)
    {
        fwrite(&ch, 1, 1, fptr_dest_image);
    }
    return e_success;
}


Status do_encoding(EncodeInfo * encInfo)
{  
    if( open_files(encInfo) == e_success)
    {   
        printf("Open files is successful\n");
        if( check_capacity(encInfo) == e_success)
        {
            printf("Capacity is a success\n");
            if( copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
            {
                printf("Copied bmp header sucessfully\n");
                if (encode_magic_string(MAGIC_STRING, encInfo) == e_success)
                {
                    printf("Encoded Magic string successfuly\n");
                    strcpy(encInfo->extn_secret_file, strstr(encInfo->secret_fname, "."));
                    if (encode_secret_file_extn_size ( strlen(encInfo->extn_secret_file), encInfo-> fptr_src_image, encInfo-> fptr_stego_image) == e_success)
                    {
                        printf("Encoded secret file extn size successflly\n");
                        if(encode_secret_file_extn(encInfo->extn_secret_file, encInfo) == e_success)
                        {
                            printf("Encoded Secret file extn successfully\n");
                            if(encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success)
                            {
                                printf("Encoded secret file size successfully\n");
                                if(encode_secret_file_data(encInfo) == e_success)
                                {
                                    printf("Encoded secret file data successfully\n");
                                    if(copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
                                    {
                                       printf("Copied remaining data successfully\n");
                                    }
                                    else
                                    {
                                       printf("Failed to copy remaining data\n");
                                    }
                                }
                                else
                                {
                                    printf("Failed to encode secret file data\n");
                                }
                            }
                            else
                            {
                                printf("Encode secret file size unsuccessful\n");
                            }
                        }
                        else
                        {
                            printf("Failed to encode Secret file extn\n");
                        }
                    }
                    else
                    {
                        printf("Encoded secret file extn was not sucessful\n");
                        return 1;
                    }
                }
                else
                {
                    printf("Failed to encode Magic String\n");
                    return 1;
                }
            }
            else
            {
                printf("copy bmp header was a failure\n");
                return e_failure;
            }
        }
        else
        {
            printf("Check capacity was a failure");
            return e_failure;         
        }
    }
    else
    {
        printf("Open Files was a failure\n");
        return e_failure;
    }
    return e_success;
}
