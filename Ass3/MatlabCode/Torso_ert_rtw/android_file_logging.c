/* 
 *
 * Copyright 2017-2018 The MathWorks, Inc.
 *
 * File: android_file_logging.c
 *
 *
 */

#include "rtwtypes.h"
#include "ert_targets_logging.h"
#include <android/log.h>

#define MODULE_NAME  "MW-SL-MAT"

#if !defined(MAT_FILE) || (defined(MAT_FILE) && MAT_FILE == 1)

FILE *MW_fopen(const char *filename, const char *mode)
{
    __android_log_print(ANDROID_LOG_DEBUG, MODULE_NAME, "File Name = %s", filename);
    char androidFileName[256];
    sprintf(androidFileName,"/sdcard/%s",filename);
    FILE *fp = fopen(androidFileName,mode);
    if (fp == NULL) {
        __android_log_print(ANDROID_LOG_ERROR, MODULE_NAME, "File can not be opened: %s", androidFileName);
    } else {
        __android_log_print(ANDROID_LOG_DEBUG, MODULE_NAME, "File opened = %s", androidFileName);
    }
    return fp;
}


size_t MW_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  //  __android_log_print(ANDROID_LOG_DEBUG, MODULE_NAME, "MW_fwrite called");
  return fwrite(ptr, size, nmemb, stream);
}

size_t MW_fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
   return fread(ptr, size, nmemb, stream);
}

void MW_rewind(FILE *stream)
{
    rewind(stream);
}

int MW_fclose(FILE *stream)
{
    //  __android_log_print(ANDROID_LOG_DEBUG, MODULE_NAME, "MW_fclose");
    return (int)fclose(stream);
}

int MW_remove(const char *filename) 
{
	remove(filename);
}

#endif
