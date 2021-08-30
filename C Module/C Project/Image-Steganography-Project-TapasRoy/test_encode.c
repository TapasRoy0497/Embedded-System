/* *****************************************************************************************************************************

NAME		:	TAPAS ROY

DESCRIPTION	: 	Programme to encode secret file data to source image file by creating new image file with option '-e' 
			and decode data from new image file to new text file

DATE		: 	18-08-2021

INPUT 		:	For option 'e'
			a) Source image file name
			b) Secret text file name
			c) Output image file name
			For option 'd'
			a) Stego image file name
			b) Output text file name

OUTPUT		:	Data in secret file copied to Output text file

***************************************************************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc, char **argv)
{
    if (check_operation_type(argv) == e_encode)
    {
        printf("Chosen Encoding\n");
        EncodeInfo encInfo;
        if (read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("Read and Validate is successful\n");
            printf("Started Encoding\n");
            if (do_encoding(&encInfo) == e_success)
            {
                printf("Completed Encoding\n");
            }
            else
            {
                printf("Encoding was a failure\n");
                return 1;
            }

        }
        else 
        {
            printf("Read and Validate was not successful");
            return 1;
        }



    }
    else if (check_operation_type(argv) == e_decode)
    {
        printf("Chosen Decoding\n");
        EncodeInfo decInfo;
        if (read_and_validate_decode_args(argv, &decInfo) == e_success)
        {
            printf("Read and validate is successful\n");
            printf("Started Decoding\n");
            if (do_decoding(&decInfo) == e_success)
            {
                printf("Completed Decoding\n");
            }
            else
            {
                printf("Decoding was a failure\n");
                return 1;
            }
        }
        else
        {
            printf("Read and Validate was not successful\n");
            return 1;
        }
    }
    else
    {
        printf("Invalid Input\nPlease pass\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
    }

}

OperationType check_operation_type(char *argv[])
{
    if (strcmp( argv[1], "-e") == 0)
    {
        return e_encode;
    }
    else if (strcmp( argv[1], "-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }

}
