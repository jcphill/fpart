/*-
 * Copyright (c) 2011 Ganael LAPLANCHE <ganael.laplanche@martymac.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _OPTIONS_H
#define _OPTIONS_H

#include "types.h"

#include <sys/types.h>

/* stat(2) */
#include <sys/types.h>
#include <sys/stat.h>

/* Program options */
struct program_options {
/* number of partitions (option -n) */
#define DFLT_OPT_NUM_PART           0
    pnum_t num_parts;
/* maximum files per partition (option -f) */
#define DFLT_OPT_MAX_ENTRIES        0
    fnum_t max_entries;
/* maximum partition size (option -s) */
#define DFLT_OPT_MAX_SIZE           0
    fsize_t max_size;
/* input file (option -i); NULL = undefined, "-" = stdout, "filename" */
    char *in_filename;
/* output file (option -o); NULL = stdout, "filename" */
    char *out_filename;
/* display directories after certain depth (option -d); -1 = disabled */
#define DFLT_OPT_DIR_DEPTH          -1
    int dir_depth;
/* add slash to directories (option -e) */
#define OPT_NOADDSLASH              0
#define OPT_ADDSLASH                1
#define DFLT_OPT_ADDSLASH           OPT_NOADDSLASH
    unsigned char add_slash;
/* verbose output (option -v) */
#define OPT_NOVERBOSE               0
#define OPT_VERBOSE                 1
#define DFLT_OPT_VERBOSE            OPT_NOVERBOSE
    unsigned char verbose;
/* follow symbolic links (option -l) */
#define OPT_FOLLOWSYMLINKS          (&stat)
#define OPT_NOFOLLOWSYMLINKS        (&lstat)
#define DFLT_OPT_FOLLOWSYMLINKS     OPT_NOFOLLOWSYMLINKS
    int (*stat_function)(const char *path, struct stat *sb);
/* cross fs boundaries (option -x) */
#define OPT_NOCROSSFSBOUNDARIES     0
#define OPT_CROSSFSBOUNDARIES       1
#define DFLT_OPT_CROSSFSBOUNDARIES  OPT_CROSSFSBOUNDARIES
    unsigned char cross_fs_boundaries;
};

void init_options(struct program_options *options);
void uninit_options(struct program_options *options);

#endif /* _OPTIONS_H */