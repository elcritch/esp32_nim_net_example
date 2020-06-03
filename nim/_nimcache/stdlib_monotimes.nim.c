/* Generated by Nim Compiler v1.3.5 */
/*   (c) 2020 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32
#define NIM_EmulateOverflowChecks

/* section: NIM_merge_HEADERS */

#include "nimbase.h"
#include <string.h>
#include <time.h>
#include <sys/types.h>
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef far
#undef powerpc
#undef unix

/* section: NIM_merge_FRAME_DEFINES */
  #  define nimfr_(proc, file) \
      TFrame FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = 0; nimFrame(&FR_);

  #  define nimfrs_(proc, file, slots, length) \
      struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename; NI len; VarSlot s[slots];} FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = length; nimFrame((TFrame*)&FR_);

  #  define nimln_(n, file) \
      FR_.line = n; FR_.filename = file;
  
/* section: NIM_merge_FORWARD_TYPES */
typedef struct tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w;
typedef struct tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw;

/* section: NIM_merge_TYPES */
struct tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w {NI64 ticks;
};
struct tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw {NI64 seconds;
NI nanosecond;
};

/* section: NIM_merge_PROC_HEADERS */
static N_INLINE(void, nimZeroMem)(void* p, NI size);
static N_INLINE(void, nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory)(void* a, int v, NI size);
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void);
static N_INLINE(NIM_BOOL, nimMulInt64)(NI64 a, NI64 b, NI64* res);
static N_INLINE(NF, toBiggestFloat__hTpm9cXKgh17pxyZUsNnUyQsystem)(NI64 i);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(NF, abs__BRaAqinz6OWTHkALb4oj6Qsystem)(NF x);
N_LIB_PRIVATE N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NIM_BOOL, nimAddInt64)(NI64 a, NI64 b, NI64* res);
N_LIB_PRIVATE N_NIMCALL(tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw, initDuration__wcR3zetvspAUsyuvWZ07Xg)(NI64 nanoseconds, NI64 microseconds, NI64 milliseconds, NI64 seconds, NI64 minutes, NI64 hours, NI64 days, NI64 weeks);
static N_INLINE(NIM_BOOL, nimSubInt64)(NI64 a, NI64 b, NI64* res);

/* section: NIM_merge_VARS */
extern NIM_THREADVAR NIM_BOOL nimInErrorMode__759bT87luu8XGcbkw13FUjA;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;

/* section: NIM_merge_PROCS */

#line 22 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
static N_INLINE(void, nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory)(void* a, int v, NI size) {	void* T1_;
#line 24 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"

#line 24 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
	T1_ = (void*)0;	T1_ = memset(a, v, ((size_t) (size)));}

#line 424 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void) {	NIM_BOOL* result;	result = (NIM_BOOL*)0;
#line 425 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	result = (&nimInErrorMode__759bT87luu8XGcbkw13FUjA);	return result;}

#line 33 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
static N_INLINE(void, nimZeroMem)(void* p, NI size) {NIM_BOOL* nimErr_;{nimErr_ = nimErrorFlag();
#line 34 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"

#line 34 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
	nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory(p, ((int) 0), size);
	if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;	}BeforeRet_: ;
}

#line 549 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(void, nimFrame)(TFrame* s) {
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!(framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA3_;

#line 551 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s).calldepth = ((NI16) 0);	}
	goto LA1_;
	LA3_: ;
	{
#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"

#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s).calldepth = (NI16)((*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1));	}
	LA1_: ;

#line 556 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	(*s).prev = framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
#line 557 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = s;
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!((*s).calldepth == ((NI16) 2000))) goto LA8_;

#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"

#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw();
	}
	LA8_: ;
}

#line 85 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(void, popFrame)(void) {
#line 86 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).prev;}

#line 1405 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
static N_INLINE(NF, toBiggestFloat__hTpm9cXKgh17pxyZUsNnUyQsystem)(NI64 i) {	NF result;	nimfr_("toBiggestFloat", "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim");	result = (NF)0;
#line 1406 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
	nimln_(1406, "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim");	result = ((NF) (i));	popFrame();	return result;}

#line 1490 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
static N_INLINE(NF, abs__BRaAqinz6OWTHkALb4oj6Qsystem)(NF x) {	NF result;	result = (NF)0;
#line 1491 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"

#line 1491 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
	{
#line 1491 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
		if (!(x < 0.0)) goto LA3_;

#line 1491 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
		result = -(x);	}
	goto LA1_;
	LA3_: ;
	{		result = x;	}
	LA1_: ;
	return result;}

#line 111 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimMulInt64)(NI64 a, NI64 b, NI64* res) {	NIM_BOOL result;	NI64 r;	NF floatProd;	NF T1_;	NF T2_;	NF resAsFloat;	result = (NIM_BOOL)0;
#line 90 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 90 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	r = ((NI64) ((NU64)((NU64)(((NU64) (a))) * (NU64)(((NU64) (b))))));
#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	T1_ = (NF)0;	T1_ = toBiggestFloat__hTpm9cXKgh17pxyZUsNnUyQsystem(a);
#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	T2_ = (NF)0;	T2_ = toBiggestFloat__hTpm9cXKgh17pxyZUsNnUyQsystem(b);	floatProd = ((NF)(T1_) * (NF)(T2_));
#line 92 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 92 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	resAsFloat = toBiggestFloat__hTpm9cXKgh17pxyZUsNnUyQsystem(r);
#line 95 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	{
#line 95 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		if (!(resAsFloat == floatProd)) goto LA5_;

#line 96 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		(*res) = r;	}
	goto LA3_;
	LA5_: ;
	{
#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		{			NF T10_;			NF T11_;
#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
			T10_ = (NF)0;			T10_ = abs__BRaAqinz6OWTHkALb4oj6Qsystem(((NF)(resAsFloat) - (NF)(floatProd)));
#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
			T11_ = (NF)0;			T11_ = abs__BRaAqinz6OWTHkALb4oj6Qsystem(floatProd);			if (!(((NF)(3.2000000000000000e+01) * (NF)(T10_)) <= T11_)) goto LA12_;

#line 106 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
			(*res) = r;		}
		goto LA8_;
		LA12_: ;
		{
#line 108 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
			result = NIM_TRUE;		}
		LA8_: ;
	}
	LA3_: ;
	return result;}

#line 53 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimAddInt64)(NI64 a, NI64 b, NI64* res) {	NIM_BOOL result;	NI64 r;	result = (NIM_BOOL)0;
#line 46 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 46 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	r = ((NI64) ((NU64)((NU64)(((NU64) (a))) + (NU64)(((NU64) (b))))));
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	{		NIM_BOOL T3_;
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (NIM_BOOL)0;
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (IL64(0) <= (NI64)(r ^ a));		if (T3_) goto LA4_;

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (IL64(0) <= (NI64)(r ^ b));		LA4_: ;
		if (!T3_) goto LA5_;

#line 48 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		(*res) = r;	}
	goto LA1_;
	LA5_: ;
	{
#line 50 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		result = NIM_TRUE;	}
	LA1_: ;
	return result;}

#line 86 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
N_LIB_PRIVATE N_NIMCALL(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w, getMonoTime__QkEugs2Q2iFK9b83sl2B6wA)(void) {	tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w result;	struct timespec ts;	int T1_;	NI64 TM__IP4V1hRabVpf8OnX9bWuPxw_2;	NI64 TM__IP4V1hRabVpf8OnX9bWuPxw_3;	nimfr_("getMonoTime", "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim");{	nimZeroMem((void*)(&result), sizeof(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w));	nimZeroMem((void*)(&ts), sizeof(struct timespec));
#line 104 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	nimln_(104, "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim");
#line 104 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"

#line 104 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	T1_ = (int)0;	T1_ = clock_gettime(((clockid_t) (CLOCK_MONOTONIC)), (&ts));	(void)(T1_);

#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	nimln_(105, "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim");	nimZeroMem((void*)(&result), sizeof(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w));
#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"

#line 105 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	if (nimMulInt64(((NI64) (ts.tv_sec)), IL64(1000000000), &TM__IP4V1hRabVpf8OnX9bWuPxw_2)) { raiseOverflow(); goto BeforeRet_;};	if (nimAddInt64((NI64)(TM__IP4V1hRabVpf8OnX9bWuPxw_2), ((NI64) (ts.tv_nsec)), &TM__IP4V1hRabVpf8OnX9bWuPxw_3)) { raiseOverflow(); goto BeforeRet_;};	result.ticks = (NI64)(TM__IP4V1hRabVpf8OnX9bWuPxw_3);	}BeforeRet_: ;
	popFrame();	return result;}

#line 65 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimSubInt64)(NI64 a, NI64 b, NI64* res) {	NIM_BOOL result;	NI64 r;	result = (NIM_BOOL)0;
#line 58 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 58 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	r = ((NI64) ((NU64)((NU64)(((NU64) (a))) - (NU64)(((NU64) (b))))));
#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	{		NIM_BOOL T3_;
#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (NIM_BOOL)0;
#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (IL64(0) <= (NI64)(r ^ a));		if (T3_) goto LA4_;

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (IL64(0) <= (NI64)(r ^ (NI64)((NU64) ~(b))));		LA4_: ;
		if (!T3_) goto LA5_;

#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		(*res) = r;	}
	goto LA1_;
	LA5_: ;
	{
#line 62 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		result = NIM_TRUE;	}
	LA1_: ;
	return result;}

#line 124 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
N_LIB_PRIVATE N_NIMCALL(tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw, minus___p9cBm7joedh4BwcboQ3HMVQ)(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w a, tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w b) {	tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw result;	NI64 TM__IP4V1hRabVpf8OnX9bWuPxw_4;NIM_BOOL* nimErr_;	nimfr_("-", "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim");{nimErr_ = nimErrorFlag();	nimZeroMem((void*)(&result), sizeof(tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw));
#line 125 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	nimln_(125, "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim");
#line 126 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	nimln_(126, "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim");
#line 126 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	if (nimSubInt64(a.ticks, b.ticks, &TM__IP4V1hRabVpf8OnX9bWuPxw_4)) { raiseOverflow(); goto BeforeRet_;};
#line 126 "/home/elcritch/.asdf/installs/nim/devel/lib/std/monotimes.nim"
	result = initDuration__wcR3zetvspAUsyuvWZ07Xg((NI64)(TM__IP4V1hRabVpf8OnX9bWuPxw_4), IL64(0), IL64(0), IL64(0), IL64(0), IL64(0), IL64(0), IL64(0));	if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;	}BeforeRet_: ;
	popFrame();	return result;}
