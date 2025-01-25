// SPDX-License-Identifier: GPL-3.0-only
/***********************************************************************
*                                                                      *
*                                                                      *
* Copyright 2025 svijsv                                                *
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
* along with this program.  If not, see <http:// www.gnu.org/licenses/>.*
*                                                                      *
*                                                                      *
***********************************************************************/
// uptime.c
// Emulate an uptime counter for systems lacking one
//
// NOTES:
//

#include "common.h"

#if uHAL_USE_UPTIME

const char* print_uptime(utime_t seconds) {
	// String big enough for "DDDDd:HHh:MMm:SSs" + terminal NUL
	static char ret_cstring[18];
	uint_t i = SIZEOF_ARRAY(ret_cstring);
	uint32_t tmp;

	// Prefix the decrement because we start i just past the terminal NUL above.
	// This also means ret_cstring[i] is always our string start.
	ret_cstring[--i] = 0;

	tmp = seconds % SECONDS_PER_MINUTE;
	ret_cstring[--i] = 's';
	ret_cstring[--i] = (tmp % 10) + '0';
	ret_cstring[--i] = (tmp / 10) + '0';

	tmp = (seconds % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
	if (tmp == 0) {
		goto END;
	}
	ret_cstring[--i] = 'm';
	ret_cstring[--i] = (tmp % 10) + '0';
	ret_cstring[--i] = (tmp / 10) + '0';

	tmp = (seconds % SECONDS_PER_DAY) / SECONDS_PER_HOUR;
	if (tmp == 0) {
		goto END;
	}
	ret_cstring[--i] = 'h';
	ret_cstring[--i] = (tmp % 10) + '0';
	ret_cstring[--i] = (tmp / 10) + '0';

	tmp = seconds / SECONDS_PER_DAY;
	if (tmp == 0) {
		goto END;
	}
	ret_cstring[--i] = 'd';
	do {
		ret_cstring[--i] = (tmp % 10) + '0';
		tmp /= 10;
	} while (tmp > 0 && i > 0);

END:
	return &ret_cstring[i];
}


#if uHAL_USE_UPTIME_EMULATION

// For simplicity, the uptime origin may be considered to be prior to device
// startup so we need a signed type.
static itime_t uptime_origin = 0;

err_t init_uptime(void) {
	uptime_origin = get_RTC_seconds();

	return ERR_OK;
}

err_t set_uptime(utime_t uptime_seconds) {
	uptime_origin = (itime_t )get_RTC_seconds() - (itime_t )uptime_seconds;

	return ERR_OK;
}

err_t adj_uptime(itime_t adjustment_seconds) {
	// Adjusting the uptime downwards shifts the origin forward and adjusting
	// upwards shifts the origin backwards.
	uptime_origin -= adjustment_seconds;

	return ERR_OK;
}

err_t fix_uptime(utime_t new_now, utime_t old_now) {
	uptime_origin += (itime_t )new_now - (itime_t )old_now;

	return ERR_OK;
}

utime_t get_uptime(void) {
	itime_t now = NOW();

	assert(now >= uptime_origin);

	return (now > uptime_origin) ? now - uptime_origin : 0;
}

#endif // uHAL_USE_UPTIME_EMULATION
#endif // uHAL_USE_UPTIME
