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

#define ICE_TIME_T unsigned long long
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

ICE_NAMESPACE_BEGIN

CE_INLINE
ce_time_t ce_time_add(ce_time_t a, ce_time_t b) {
  ce_time_t out;
  out.sec = a.sec + b.sec + ICE_NANO2SEC(a.nsec + b.nsec);
  out.nsec = (a.nsec + b.nsec) % ICE_SEC2NANO_V;
  return out;
}

CE_INLINE
ce_time_t ce_time_sub(ce_time_t a, ce_time_t b) {
  /* This function does not return the correct result when 'nsec' is greater than
   * or equal to 1 billion. But 'nsec' is only suppose to go from 0 up to
   * but not including 1 billion. So if 'ce_time_t' is used correctly then
   * this should be an non-issue.
   */
  
  ce_time_t neg;
  neg.sec = ULLONG_MAX - b.sec;
  neg.nsec = ICE_SEC2NANO_V - b.nsec;
  return ce_time_add(a, neg);
}

CE_INLINE
int ce_time_cmp(ce_time_t a, ce_time_t b) {
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

CE_INLINE
unsigned long long ce_time_to_inano(ce_time_t in) {
  return ICE_SEC2NANO(in.sec) + in.nsec;
}

CE_INLINE
unsigned long long ce_time_to_imicro(ce_time_t in) {
  return ICE_SEC2MICRO(in.sec) + ICE_NANO2MICRO(in.nsec);
}

CE_INLINE
unsigned long long ce_time_to_imilli(ce_time_t in) {
  return ICE_SEC2MILLI(in.sec) + ICE_NANO2MILLI(in.nsec);
}

CE_INLINE
unsigned long long ce_time_to_iseconds(ce_time_t in) {
  return in.sec + ICE_NANO2SEC(in.nsec);
}

CE_INLINE
double ce_time_to_nano(ce_time_t in) {
  return ICE_SEC2NANO((double)in.sec) + (double)in.nsec;
}

CE_INLINE
double ce_time_to_micro(ce_time_t in) {
  return ICE_SEC2MICRO((double)in.sec) + ICE_NANO2MICRO((double)in.nsec);
}

CE_INLINE
double ce_time_to_milli(ce_time_t in) {
  return ICE_SEC2MILLI((double)in.sec) + ICE_NANO2MILLI((double)in.nsec);
}

CE_INLINE
double ce_time_to_seconds(ce_time_t in) {
  return (double)in.sec + ICE_NANO2SEC((double)in.nsec);
}

CE_INLINE
float ce_time_to_fnano(ce_time_t in) {
  return ICE_SEC2NANO((float)in.sec) + (float)in.nsec;
}

CE_INLINE
float ce_time_to_fmicro(ce_time_t in) {
  return ICE_SEC2MICRO((float)in.sec) + ICE_NANO2MICRO((float)in.nsec);
}

CE_INLINE
float ce_time_to_fmilli(ce_time_t in) {
  return ICE_SEC2MILLI((float)in.sec) + ICE_NANO2MILLI((float)in.nsec);
}

CE_INLINE
float ce_time_to_fseconds(ce_time_t in) {
  return (float)in.sec + ICE_NANO2SEC((float)in.nsec);
}

CE_INLINE
long double ce_time_to_lnano(ce_time_t in) {
  return ICE_SEC2NANO((long double)in.sec) + (long double)in.nsec;
}

CE_INLINE
long double ce_time_to_lmicro(ce_time_t in) {
  return ICE_SEC2MICRO((long double)in.sec) + ICE_NANO2MICRO((long double)in.nsec);
}

CE_INLINE
long double ce_time_to_lmilli(ce_time_t in) {
  return ICE_SEC2MILLI((long double)in.sec) + ICE_NANO2MILLI((long double)in.nsec);
}

CE_INLINE
long double ce_time_to_lseconds(ce_time_t in) {
  return (long double)in.sec + ICE_NANO2SEC((long double)in.nsec);
}

CE_INLINE
ce_time_t ce_time_inano(unsigned long long in) {
  ce_time_t out;
  out.sec = ICE_NANO2SEC(in),
  out.nsec = in % ICE_NANO2SEC_V;
  return out;
}

CE_INLINE
ce_time_t ce_time_imicro(unsigned long long in) {
  ce_time_t out;
  out.sec = ICE_MICRO2SEC(in),
  out.nsec = ICE_MICRO2NANO(in % ICE_MICRO2SEC_V);
  return out;
}

CE_INLINE
ce_time_t ce_time_imilli(unsigned long long in) {
  ce_time_t out;
  out.sec = ICE_MILLI2SEC(in),
  out.nsec = ICE_MILLI2NANO(in % ICE_MILLI2SEC_V);
  return out;
}

CE_INLINE
ce_time_t ce_time_iseconds(unsigned long long in) {
  ce_time_t out;
  out.sec = in,
  out.nsec = 0;
  return out;
}

CE_INLINE
ce_time_t ce_time_nano(double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_NANO2SEC(in),
  out.nsec = (ICE_TIME_T)fmod(in, ICE_NANO2SEC_V);
  return out;
}

CE_INLINE
ce_time_t ce_time_micro(double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_MICRO2SEC(in);
  out.nsec = (ICE_TIME_T)ICE_MICRO2NANO(fmod(in, ICE_MICRO2SEC_V));
  return out;
}

CE_INLINE
ce_time_t ce_time_milli(double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_MILLI2SEC(in);
  out.nsec = (ICE_TIME_T)ICE_MILLI2NANO(fmod(in, ICE_MILLI2SEC_V));
  return out;
}

CE_INLINE
ce_time_t ce_time_seconds(double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)in;
  out.nsec = 0;
  return out;
}

CE_INLINE
ce_time_t ce_time_fnano(float in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_NANO2SEC(in);
  out.nsec = (ICE_TIME_T)fmodf(in, ICE_NANO2SEC_V);
  return out;
}

CE_INLINE
ce_time_t ce_time_fmicro(float in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_MICRO2SEC(in);
  out.nsec = (ICE_TIME_T)ICE_MICRO2NANO(fmodf(in, ICE_MICRO2SEC_V));
  return out;
}

CE_INLINE
ce_time_t ce_time_fmilli(float in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_MILLI2SEC(in);
  out.nsec = (ICE_TIME_T)ICE_MILLI2NANO(fmodf(in, ICE_MILLI2SEC_V));
  return out;
}

CE_INLINE
ce_time_t ce_time_fseconds(float in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)in;
  out.nsec = 0;
  return out;
}

CE_INLINE
ce_time_t ce_time_lnano(long double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_NANO2SEC(in);
  out.nsec = (ICE_TIME_T)fmodl(in, ICE_NANO2SEC_V);
  return out;
}

CE_INLINE
ce_time_t ce_time_lmicro(long double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_MICRO2SEC(in);
  out.nsec = (ICE_TIME_T)ICE_MICRO2NANO(fmodl(in, ICE_MICRO2SEC_V));
  return out;
}

CE_INLINE
ce_time_t ce_time_lmilli(long double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)ICE_MILLI2SEC(in);
  out.nsec = (ICE_TIME_T)ICE_MILLI2NANO(fmodl(in, ICE_MILLI2SEC_V));
  return out;
}

CE_INLINE
ce_time_t ce_time_lseconds(long double in) {
  ce_time_t out;
  out.sec = (ICE_TIME_T)in;
  out.nsec = 0;
  return out;
}

ICE_NAMESPACE_END
