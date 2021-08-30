#ifndef DECODE_H
#define DECODE_H

#include "types.h"

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4


typedef struct _DecodeInfo
{
    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    /* Dest File Info */
    char *dest_fname;
    char *dest_file_extn;
    char *dest_fname_with_extn;
    FILE *fptr_dest_file;
    long size_dest_file;
    char image_data[MAX_IMAGE_BUF_SIZE];
    char extn_secret_file[MAX_FILE_SUFFIX];
    char extn_size;

     
    /* Magic Pattern info */
    char *magic_pattern;

    
} DecodeInfo;

/* Decoding function prototype */

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the encoding */
Status do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status open_files_decode(DecodeInfo *decInfo);

/* Open dest file */
Status func_open_dest_files_decode(DecodeInfo *decInfo);

/* Decode Magic String */
Status decode_magic_string(char *magic_string, DecodeInfo *decInfo);

/*Decode secret file extension size*/
Status decode_secret_file_extn_size(const char *secret_fname,DecodeInfo *decInfo);

/*Decode secret file extension */
Status decode_secret_file_extn(const char *secret_fname,DecodeInfo *decInfo);
/*Decode secret file size*/
Status decode_secret_file_size(DecodeInfo *decInfo);

/*Decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

/*Decode lsbs to bytes*/
int decode_lsb_tobyte(int size, char *image_data);

#endif
