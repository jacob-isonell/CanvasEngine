/**************************************************************************
** CanvasEngine is a C11 cross platform multimedia library.              **
** Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)             **
**                                                                       **
** This program is free software: you can redistribute it and/or modify  **
** it under the terms of the GNU General Public License as published by  **
** the Free Software Foundation, either version 3 of the License, or     **
** (at your option) any later version.                                   **
**                                                                       **
** This program is distributed in the hope that it will be useful,       **
** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
** GNU General Public License for more details.                          **
**                                                                       **
** You should have received a copy of the GNU General Public License     **
** along with this program. If not, see <https://www.gnu.org/licenses/>. **
**************************************************************************/

#ifndef CANVAS_CORE_TIME_H
#define CANVAS_CORE_TIME_H

#include <canvas/core/error.h>
#include <time.h>
#include <math.h>

ICE_NAMESPACE_BEGIN

#define ICE_SEC2MILLI_V   1000
#define ICE_SEC2MICRO_V   1000000
#define ICE_SEC2NANO_V    1000000000
#define ICE_NANO2MICRO_V  1000
#define ICE_NANO2MILLI_V  1000000
#define ICE_NANO2SEC_V    1000000000
#define ICE_MILLI2SEC_V   1000
#define ICE_MILLI2MICRO_V 1000
#define ICE_MILLI2NANO_V  1000000
#define ICE_MICRO2SEC_V   1000000
#define ICE_MICRO2MILLI_V 1000000
#define ICE_MICRO2NANO_V  1000

#define ICE_SEC2MILLI(in)   ((in) * ICE_SEC2MILLI_V)
#define ICE_SEC2MICRO(in)   ((in) * ICE_SEC2MICRO_V)
#define ICE_SEC2NANO(in)    ((in) * ICE_SEC2NANO_V)
#define ICE_NANO2MICRO(in)  ((in) / ICE_NANO2MICRO_V)
#define ICE_NANO2MILLI(in)  ((in) / ICE_NANO2MILLI_V)
#define ICE_NANO2SEC(in)    ((in) / ICE_NANO2SEC_V)
#define ICE_MILLI2SEC(in)   ((in) / ICE_MILLI2SEC_V)
#define ICE_MILLI2MICRO(in) ((in) * ICE_MILLI2MICRO_V)
#define ICE_MILLI2NANO(in)  ((in) * ICE_MILLI2NANO_V)
#define ICE_MICRO2SEC(in)   ((in) / ICE_MICRO2SEC_V)
#define ICE_MICRO2MILLI(in) ((in) * ICE_MICRO2MILLI_V)
#define ICE_MICRO2NANO(in)  ((in) * ICE_MICRO2NANO_V)

#define CE_TIME_UTC 1

/** @brief Describes a span of time or the time span since the unix epoch time (january 1st 1970 00:00:00). */
struct ce_time_t {
	/** @brief Seconds. */
	unsigned long long int sec;
	
	/** @brief Nanoseconds. This field must be in the range of 0 to 999'999'999 (or 1 billion - 1). */
	unsigned long long int nsec;
};

/** @brief Gets the current time. */
CE_API ce_err ce_time_get(struct ce_time_t* out, int base);

ICE_INLINE
struct ce_time_t ce_time_add(struct ce_time_t a, struct ce_time_t b) {
	struct ce_time_t out;
	out.sec = a.sec + b.sec + ICE_NANO2SEC(a.nsec + b.nsec);
	out.nsec = (a.nsec + b.nsec) % ICE_SEC2NANO_V;
	return out;
}

ICE_INLINE
struct ce_time_t ce_time_sub(struct ce_time_t a, struct ce_time_t b) {
	/* This function does not return the correct result when 'nsec' is greater than
	 * or equal to 1 billion. But 'nsec' is only suppose to go from 0 up to
	 * but not including 1 billion. So if 'struct ce_time_t' is used correctly then
	 * this should be an non-issue.
	 */
	
	struct ce_time_t neg;
	neg.sec = ULLONG_MAX - b.sec;
	neg.nsec = ICE_SEC2NANO_V - b.nsec;
	return ce_time_add(a, neg);
}

ICE_INLINE
int ce_time_cmp(struct ce_time_t a, struct ce_time_t b) {
	if (a.sec < b.sec) {
		return -1;
	}
	if (a.sec > b.sec) {
		return 1;
	}
	if (a.nsec < b.nsec) {
		return -1;
	}
	if (a.nsec > b.nsec) {
		return 1;
	}
	return 0;
}

ICE_INLINE unsigned long long int ce_time_to_inano(struct ce_time_t in) { return ICE_SEC2NANO(in.sec) + in.nsec;	}
ICE_INLINE unsigned long long int ce_time_to_imicro(struct ce_time_t in) { return ICE_SEC2MICRO(in.sec) + ICE_NANO2MICRO(in.nsec);	}
ICE_INLINE unsigned long long int ce_time_to_imilli(struct ce_time_t in) { return ICE_SEC2MILLI(in.sec) + ICE_NANO2MILLI(in.nsec); }
ICE_INLINE unsigned long long int ce_time_to_iseconds(struct ce_time_t in) { return in.sec + ICE_NANO2SEC(in.nsec); }
ICE_INLINE double ce_time_to_nano(struct ce_time_t in) { return ICE_SEC2NANO((double)in.sec) + (double)in.nsec;	}
ICE_INLINE double ce_time_to_micro(struct ce_time_t in) { return ICE_SEC2MICRO((double)in.sec) + ICE_NANO2MICRO((double)in.nsec);	}
ICE_INLINE double ce_time_to_milli(struct ce_time_t in) { return ICE_SEC2MILLI((double)in.sec) + ICE_NANO2MILLI((double)in.nsec); }
ICE_INLINE double ce_time_to_seconds(struct ce_time_t in) { return (double)in.sec + ICE_NANO2SEC((double)in.nsec); }
ICE_INLINE float ce_time_to_fnano(struct ce_time_t in) { return ICE_SEC2NANO((float)in.sec) + (float)in.nsec;	}
ICE_INLINE float ce_time_to_fmicro(struct ce_time_t in) { return ICE_SEC2MICRO((float)in.sec) + ICE_NANO2MICRO((float)in.nsec);	}
ICE_INLINE float ce_time_to_fmilli(struct ce_time_t in) { return ICE_SEC2MILLI((float)in.sec) + ICE_NANO2MILLI((float)in.nsec); }
ICE_INLINE float ce_time_to_fseconds(struct ce_time_t in) { return (float)in.sec + ICE_NANO2SEC((float)in.nsec); }
ICE_INLINE long double ce_time_to_lnano(struct ce_time_t in) { return ICE_SEC2NANO((long double)in.sec) + (long double)in.nsec;	}
ICE_INLINE long double ce_time_to_lmicro(struct ce_time_t in) { return ICE_SEC2MICRO((long double)in.sec) + ICE_NANO2MICRO((long double)in.nsec);	}
ICE_INLINE long double ce_time_to_lmilli(struct ce_time_t in) { return ICE_SEC2MILLI((long double)in.sec) + ICE_NANO2MILLI((long double)in.nsec); }
ICE_INLINE long double ce_time_to_lseconds(struct ce_time_t in) { return (long double)in.sec + ICE_NANO2SEC((long double)in.nsec); }

ICE_INLINE struct ce_time_t ce_time_inano(unsigned long long int in) { return CE_STRUCT_INIT(struct ce_time_t) { ICE_NANO2SEC(in), in % ICE_NANO2SEC_V };	}
ICE_INLINE struct ce_time_t ce_time_imicro(unsigned long long int in) { return CE_STRUCT_INIT(struct ce_time_t) { ICE_MICRO2SEC(in), ICE_MICRO2NANO(in % ICE_MICRO2SEC_V) }; }
ICE_INLINE struct ce_time_t ce_time_imilli(unsigned long long int in) { return CE_STRUCT_INIT(struct ce_time_t) { ICE_MILLI2SEC(in), ICE_MILLI2NANO(in % ICE_MILLI2SEC_V) }; }
ICE_INLINE struct ce_time_t ce_time_iseconds(unsigned long long int in) { return CE_STRUCT_INIT(struct ce_time_t) { in, 0 }; }
ICE_INLINE struct ce_time_t ce_time_nano(double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_NANO2SEC(in), (unsigned long long int)fmod(in, ICE_NANO2SEC_V) };	}
ICE_INLINE struct ce_time_t ce_time_micro(double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_MICRO2SEC(in), (unsigned long long int)ICE_MICRO2NANO(fmod(in, ICE_MICRO2SEC_V)) }; }
ICE_INLINE struct ce_time_t ce_time_milli(double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_MILLI2SEC(in), (unsigned long long int)ICE_MILLI2NANO(fmod(in, ICE_MILLI2SEC_V)) }; }
ICE_INLINE struct ce_time_t ce_time_seconds(double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)in, 0 }; }
ICE_INLINE struct ce_time_t ce_time_fnano(float in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_NANO2SEC(in), (unsigned long long int)fmodf(in, ICE_NANO2SEC_V) };	}
ICE_INLINE struct ce_time_t ce_time_fmicro(float in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_MICRO2SEC(in), (unsigned long long int)ICE_MICRO2NANO(fmodf(in, ICE_MICRO2SEC_V)) }; }
ICE_INLINE struct ce_time_t ce_time_fmilli(float in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_MILLI2SEC(in), (unsigned long long int)ICE_MILLI2NANO(fmodf(in, ICE_MILLI2SEC_V)) }; }
ICE_INLINE struct ce_time_t ce_time_fseconds(float in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)in, 0 }; }
ICE_INLINE struct ce_time_t ce_time_lnano(long double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_NANO2SEC(in), (unsigned long long int)fmodl(in, ICE_NANO2SEC_V) };	}
ICE_INLINE struct ce_time_t ce_time_lmicro(long double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_MICRO2SEC(in), (unsigned long long int)ICE_MICRO2NANO(fmodl(in, ICE_MICRO2SEC_V)) }; }
ICE_INLINE struct ce_time_t ce_time_lmilli(long double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)ICE_MILLI2SEC(in), (unsigned long long int)ICE_MILLI2NANO(fmodl(in, ICE_MILLI2SEC_V)) }; }
ICE_INLINE struct ce_time_t ce_time_lseconds(long double in) { return CE_STRUCT_INIT(struct ce_time_t) { (unsigned long long int)in, 0 }; }

ICE_NAMESPACE_END

#endif /* !CANVAS_CORE_TIME_H */
