/*
 *  Copyright 2012-16 ARM Limited and Contributors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of ARM Limited nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY ARM LIMITED AND CONTRIBUTORS "AS IS" AND
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL ARM LIMITED AND CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * NE10 Library : common/NE10_mask_table.c
 */

#include "NE10_mask_table.h"

const ne10_uint32_t ne10_qMaskTable32[Q_MASK_TABLE_SIZE] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000,
    0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
const ne10_uint32_t ne10_dMaskTable32[D_MASK_TABLE_SIZE] = {
    0x00000000,
    0x00000000,
    0xFFFFFFFF,
    0x00000000,
    0xFFFFFFFF,
    0xFFFFFFFF,

};

const ne10_uint32_t ne10_divLookUpTable[DIV_LOOKUP_TABLE_SIZE] = {

    65535, 32768, 21845, 16384, 13107, 10923, 9362, 8192, 7282, 6554, 5958, 5461, 5041, 4681, 4369,
    4096,  3855,  3641,  3449,  3277,  3121,  2979, 2849, 2731, 2621, 2521, 2427, 2341, 2260, 2185,
    2114,  2048,  1986,  1928,  1872,  1820,  1771, 1725, 1680, 1638, 1598, 1560, 1524, 1489, 1456,
    1425,  1394,  1365,  1337,  1311,  1285,  1260, 1237, 1214, 1192, 1170, 1150, 1130, 1111, 1092,
    1074,  1057,  1040,  1024,  1008,  993,   978,  964,  950,  936,  923,  910,  898,  886,  874,
    862,   851,   840,   830,   819,   809,   799,  790,  780,  771,  762,  753,  745,  736,  728,
    720,   712,   705,   697,   690,   683,   676,  669,  662,  655,  649,  643,  636,  630,  624,
    618,   612,   607,   601,   596,   590,   585,  580,  575,  570,  565,  560,  555,  551,  546,
    542,   537,   533,   529,   524,   520,   516,  512,  508,  504,  500,  496,  493,  489,  485,
    482,   478,   475,   471,   468,   465,   462,  458,  455,  452,  449,  446,  443,  440,  437,
    434,   431,   428,   426,   423,   420,   417,  415,  412,  410,  407,  405,  402,  400,  397,
    395,   392,   390,   388,   386,   383,   381,  379,  377,  374,  372,  370,  368,  366,  364,
    362,   360,   358,   356,   354,   352,   350,  349,  347,  345,  343,  341,  340,  338,  336,
    334,   333,   331,   329,   328,   326,   324,  323,  321,  320,  318,  317,  315,  314,  312,
    311,   309,   308,   306,   305,   303,   302,  301,  299,  298,  297,  295,  294,  293,  291,
    290,   289,   287,   286,   285,   284,   282,  281,  280,  279,  278,  277,  275,  274,  273,
    272,   271,   270,   269,   267,   266,   265,  264,  263,  262,  261,  260,  259,  258,  257};

const ne10_uint64_t
    ne10_img_vresize_linear_mask_residual_table[NE10_VRESIZE_LINEAR_MASK_TABLE_SIZE] = {
        0x00000000000000FF,
        0x000000000000FFFF,
        0x0000000000FFFFFF,
        0x00000000FFFFFFFF,
        0x000000FFFFFFFFFF,
        0x0000FFFFFFFFFFFF,
        0x00FFFFFFFFFFFFFF};
