#!/bin/bash
#
# Sizes to handle in addition to uint
sizes=("8" "16" "32" "64")
# Function prototypes to print.
protos=(
"BITOP_FUNC_INLINE uintNN_t set_bit_uNN(uintNN_t field, uintNN_t bits)"
"BITOP_FUNC_INLINE uintNN_t clear_bit_uNN(uintNN_t field, uintNN_t bits)"
"BITOP_FUNC_INLINE uintNN_t toggle_bit_uNN(uintNN_t field, uintNN_t bits)"
"BITOP_FUNC_INLINE uintNN_t modify_bits_uNN(uintNN_t field, uintNN_t mask, uintNN_t bits)"
"BITOP_FUNC_INLINE uintNN_t select_bits_uNN(uintNN_t field, uintNN_t mask)"
"BITOP_FUNC_INLINE uintNN_t mask_bits_uNN(uintNN_t field, uintNN_t mask)"
"BITOP_FUNC_INLINE uintNN_t gather_bits_uNN(uintNN_t field, uintNN_t mask, uint_fast8_t offset)"
"BITOP_FUNC_INLINE bool bit_is_set_uNN(uintNN_t field, uintNN_t mask)"
"BITOP_FUNC_INLINE bool bits_are_set_uNN(uintNN_t field, uintNN_t mask)"
"BITOP_FUNC_INLINE uintNN_t as_bit_uNN(uint_fast8_t n)"
"BITOP_FUNC_INLINE uintNN_t lowest_bit_uNN(uintNN_t field)"
"BITOP_FUNC_INLINE uintNN_t shift_lowest_bit_uNN(uintNN_t field)"
)

gen_head() {
	cat <<EOF
// SPDX-License-Identifier: GPL-3.0-only
/***********************************************************************
*                                                                      *
*                                                                      *
* Copyright 2024 svijsv                                                *
* This program is free software: you can redistribute it and/or modify *
* it under the terms of the GNU General Public License as published by *
* the Free Software Foundation, version 3.                             *
*                                                                      *
* This program is distributed in the hope that it will be useful, but  *
* WITHOUT ANY WARRANTY; without even the implied warranty of           *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    *
* General Public License for more details.                             *
*                                                                      *
* You should have received a copy of the GNU General Public License    *
* along with this program. If not, see <http:// www.gnu.org/licenses/>.*
*                                                                      *
*                                                                      *
***********************************************************************/
// bits.h
// Operations on bitfields
// NOTES:
//   These are typed function versions of macros available in bits.h. Normally
//   they are included from that file and inlined, but if ULIB_BITOP_ENABLE_INLINED_FUNCTIONS
//   is 0 bits.c will need to be added to the source file list to be used and the
//   functions won't be inlined.
//
//   Not all macros have inlined function versions because not all would benefit
//   from them.
//
//   Many of the macros will act on the bit field directly, but with the
//   functions the field will need to be assigned by the caller (e.g.
//   'SET_BIT(f, x)' vs. 'f = set_bit_u32(f, x)'.
//
//   The only likely advantages of these functions is type checking and avoiding
//   the occasional cast or unintended integer promotion.
//
//   This file was partially generated by ${0##*/} on $(date)
//
#if ULIB_ENABLE_BITOPS
#ifndef _ULIB_BITS_H
# include "bits.h"
#endif


EOF
}
gen_tail() {
	cat <<EOF


#endif // ULIB_ENABLE_BITOPS
EOF
}

gen_head

for p in "${protos[@]}"; do
	printf "%s {\n}\n" "${p}" | sed -e "s|intNN_t|int|g" -e "s|_uNN||g"
	for s in "${sizes[@]}"; do
		if [ ${s} -gt 32 ]; then
			echo "#if ULIB_BITOP_ENABLE_INLINED_${s}BIT_FUNCTIONS"
			printf "%s {\n}\n" "${p}" | sed -e "s|NN|${s}|g"
			echo "#endif"
		else
			printf "%s {\n}\n" "${p}" | sed -e "s|NN|${s}|g"
		fi
	done
	echo
done
#BITOP_FUNC_INLINE uintNN_t set_bit_uNN(uintNN_t field, uintNN_t bits)

gen_tail