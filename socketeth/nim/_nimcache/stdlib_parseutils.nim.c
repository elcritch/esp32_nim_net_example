/* Generated by Nim Compiler v1.3.5 */
/*   (c) 2020 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32
#define NIM_EmulateOverflowChecks

/* section: NIM_merge_HEADERS */

#include "nimbase.h"
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
typedef struct NimStrPayload NimStrPayload;
typedef struct NimStringV2 NimStringV2;

/* section: NIM_merge_TYPES */
struct NimStrPayload {NI cap;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct NimStringV2 {NI len;
NimStrPayload* p;
};

/* section: NIM_merge_PROC_HEADERS */
static N_INLINE(NIM_BOOL, nimAddInt)(NI a, NI b, NI* res);
N_LIB_PRIVATE N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NIM_CHAR, toLower__eK9b2e49aPf4wAIdUwhbmZsQparseutils)(NIM_CHAR c);
static N_INLINE(NIM_BOOL, nimSubInt)(NI a, NI b, NI* res);
N_LIB_PRIVATE N_NOINLINE(void, raiseRangeErrorI)(NI64 i, NI64 a, NI64 b);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NOINLINE(void, raiseIndexError2)(NI i, NI n);
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void);
N_LIB_PRIVATE N_NOINLINE(void, raiseDivByZero)(void);
static N_INLINE(NIM_BOOL, nimDivInt)(NI a, NI b, NI* res);
static N_INLINE(NIM_BOOL, nimMulInt)(NI a, NI b, NI* res);
static N_INLINE(NF, toFloat__y1Fm9aHmxw9bS2jir137Fu5gsystem)(NI i);
static N_INLINE(NF, abs__BRaAqinz6OWTHkALb4oj6Qsystem)(NF x);

/* section: NIM_merge_VARS */
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR NIM_BOOL nimInErrorMode__759bT87luu8XGcbkw13FUjA;

/* section: NIM_merge_PROCS */

#line 52 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimAddInt)(NI a, NI b, NI* res) {	NIM_BOOL result;	NI r;	result = (NIM_BOOL)0;
#line 46 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 46 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	r = ((NI) ((NU)((NU32)(((NU) (a))) + (NU32)(((NU) (b))))));
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	{		NIM_BOOL T3_;
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (NIM_BOOL)0;
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (((NI) 0) <= (NI)(r ^ a));		if (T3_) goto LA4_;

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (((NI) 0) <= (NI)(r ^ b));		LA4_: ;
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

#line 64 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimSubInt)(NI a, NI b, NI* res) {	NIM_BOOL result;	NI r;	result = (NIM_BOOL)0;
#line 58 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 58 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	r = ((NI) ((NU)((NU32)(((NU) (a))) - (NU32)(((NU) (b))))));
#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	{		NIM_BOOL T3_;
#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (NIM_BOOL)0;
#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (((NI) 0) <= (NI)(r ^ a));		if (T3_) goto LA4_;

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (((NI) 0) <= (NI)(r ^ (NI)((NU32) ~(b))));		LA4_: ;
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

#line 59 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
static N_INLINE(NIM_CHAR, toLower__eK9b2e49aPf4wAIdUwhbmZsQparseutils)(NIM_CHAR c) {	NIM_CHAR result;	nimfr_("toLower", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");{	result = (NIM_CHAR)0;
#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
	nimln_(60, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");
#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
	{		NI TM__vI9aZNKIcImom6dDyKXW1ZA_3;		NI TM__vI9aZNKIcImom6dDyKXW1ZA_4;
#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA3_;

#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 60 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		if (nimSubInt(((NU8)(c)), ((NI) 65), &TM__vI9aZNKIcImom6dDyKXW1ZA_3)) { raiseOverflow(); goto BeforeRet_;};		if (nimAddInt((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_3), ((NI) 97), &TM__vI9aZNKIcImom6dDyKXW1ZA_4)) { raiseOverflow(); goto BeforeRet_;};		if (((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_4)) < ((NI) 0) || ((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_4)) > ((NI) 255)){ raiseRangeErrorI((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_4), ((NI) 0), ((NI) 255)); goto BeforeRet_;}		result = ((NIM_CHAR) (((NI) ((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_4)))));	}
	goto LA1_;
	LA3_: ;
	{		result = c;	}
	LA1_: ;
	}BeforeRet_: ;
	popFrame();	return result;}

#line 424 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void) {	NIM_BOOL* result;	result = (NIM_BOOL*)0;
#line 425 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	result = (&nimInErrorMode__759bT87luu8XGcbkw13FUjA);	return result;}

#line 268 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
N_LIB_PRIVATE N_NIMCALL(NI, skipIgnoreCase__Z630VYBL4pZDWlOyn05K5w)(NimStringV2 s, NimStringV2 token, NI start) {	NI result;NIM_BOOL* nimErr_;	nimfr_("skipIgnoreCase", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");{nimErr_ = nimErrorFlag();	result = (NI)0;	{
#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		nimln_(273, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");		while (1) {			NIM_BOOL T3_;			NIM_BOOL T4_;			NI TM__vI9aZNKIcImom6dDyKXW1ZA_2;			NI TM__vI9aZNKIcImom6dDyKXW1ZA_5;			NIM_CHAR T7_;			NIM_CHAR T8_;			NI TM__vI9aZNKIcImom6dDyKXW1ZA_6;
#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			T3_ = (NIM_BOOL)0;
#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			T4_ = (NIM_BOOL)0;
#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			if (nimAddInt(start, result, &TM__vI9aZNKIcImom6dDyKXW1ZA_2)) { raiseOverflow(); goto BeforeRet_;};
#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			T4_ = ((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_2) < s.len);			if (!(T4_)) goto LA5_;

#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 273 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			T4_ = (result < token.len);			LA5_: ;
			T3_ = T4_;			if (!(T3_)) goto LA6_;

#line 274 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			nimln_(274, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");
#line 274 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 274 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			if (nimAddInt(result, start, &TM__vI9aZNKIcImom6dDyKXW1ZA_5)) { raiseOverflow(); goto BeforeRet_;};			if ((NU)((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_5)) >= (NU)s.len){ raiseIndexError2((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_5),s.len-1); goto BeforeRet_;}
#line 274 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			T7_ = (NIM_CHAR)0;			T7_ = toLower__eK9b2e49aPf4wAIdUwhbmZsQparseutils(s.p->data[(NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_5)]);			if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;
#line 274 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			if ((NU)(result) >= (NU)token.len){ raiseIndexError2(result,token.len-1); goto BeforeRet_;}
#line 274 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			T8_ = (NIM_CHAR)0;			T8_ = toLower__eK9b2e49aPf4wAIdUwhbmZsQparseutils(token.p->data[result]);			if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;			T3_ = ((NU8)(T7_) == (NU8)(T8_));			LA6_: ;
			if (!T3_) goto LA2;

#line 274 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			if (nimAddInt(result, ((NI) 1), &TM__vI9aZNKIcImom6dDyKXW1ZA_6)) { raiseOverflow(); goto BeforeRet_;};			result = (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_6);		} LA2: ;
	}

#line 275 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
	nimln_(275, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");	{
#line 275 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 275 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 275 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		if (!!((result == token.len))) goto LA11_;

#line 275 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		result = ((NI) 0);	}
	LA11_: ;
	}BeforeRet_: ;
	popFrame();	return result;}

#line 122 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimDivInt)(NI a, NI b, NI* res) {	NIM_BOOL result;	result = (NIM_BOOL)0;
#line 117 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	{		NIM_BOOL T3_;
#line 117 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (NIM_BOOL)0;
#line 117 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (a == ((NI) (-2147483647 -1)));		if (!(T3_)) goto LA4_;

#line 117 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (b == ((NI) -1));		LA4_: ;
		if (!T3_) goto LA5_;

#line 118 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		result = NIM_TRUE;	}
	goto LA1_;
	LA5_: ;
	{
#line 120 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 120 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		(*res) = (NI)(a / b);	}
	LA1_: ;
	return result;}

#line 1391 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
static N_INLINE(NF, toFloat__y1Fm9aHmxw9bS2jir137Fu5gsystem)(NI i) {	NF result;	nimfr_("toFloat", "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim");	result = (NF)0;
#line 1392 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
	nimln_(1392, "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim");	result = ((NF) (i));	popFrame();	return result;}

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

#line 110 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimMulInt)(NI a, NI b, NI* res) {	NIM_BOOL result;	NI r;	NF floatProd;	NF T1_;	NF T2_;	NF resAsFloat;	result = (NIM_BOOL)0;
#line 90 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 90 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	r = ((NI) ((NU)((NU32)(((NU) (a))) * (NU32)(((NU) (b))))));
#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	T1_ = (NF)0;	T1_ = toFloat__y1Fm9aHmxw9bS2jir137Fu5gsystem(a);
#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 91 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	T2_ = (NF)0;	T2_ = toFloat__y1Fm9aHmxw9bS2jir137Fu5gsystem(b);	floatProd = ((NF)(T1_) * (NF)(T2_));
#line 92 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 92 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	resAsFloat = toFloat__y1Fm9aHmxw9bS2jir137Fu5gsystem(r);
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

#line 466 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
N_LIB_PRIVATE N_NIMCALL(NI, parseSaturatedNatural__hGWFPKYRsDcYFCjZLM9acZw)(NimStringV2 s, NI* b, NI start) {	NI result;	NI i;	nimfr_("parseSaturatedNatural", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");{	result = (NI)0;
#line 476 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
	nimln_(476, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");	i = start;
#line 477 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
	nimln_(477, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");	{		NIM_BOOL T3_;		NI TM__vI9aZNKIcImom6dDyKXW1ZA_7;
#line 477 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		T3_ = (NIM_BOOL)0;
#line 477 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 477 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		T3_ = (i < s.len);		if (!(T3_)) goto LA4_;

#line 477 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		if ((NU)(i) >= (NU)s.len){ raiseIndexError2(i,s.len-1); goto BeforeRet_;}		T3_ = ((NU8)(s.p->data[i]) == (NU8)(43));		LA4_: ;
		if (!T3_) goto LA5_;

#line 477 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		if (nimAddInt(i, ((NI) 1), &TM__vI9aZNKIcImom6dDyKXW1ZA_7)) { raiseOverflow(); goto BeforeRet_;};		i = (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_7);	}
	LA5_: ;

#line 478 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
	nimln_(478, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");	{		NIM_BOOL T9_;		NI TM__vI9aZNKIcImom6dDyKXW1ZA_15;
#line 478 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		T9_ = (NIM_BOOL)0;
#line 478 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 478 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		T9_ = (i < s.len);		if (!(T9_)) goto LA10_;

#line 478 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		if ((NU)(i) >= (NU)s.len){ raiseIndexError2(i,s.len-1); goto BeforeRet_;}		T9_ = (((NU8)(s.p->data[i])) >= ((NU8)(48)) && ((NU8)(s.p->data[i])) <= ((NU8)(57)));		LA10_: ;
		if (!T9_) goto LA11_;

#line 479 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		nimln_(479, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");		(*b) = ((NI) 0);		{
#line 480 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
			nimln_(480, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");			while (1) {				NIM_BOOL T15_;				NI c;				NI TM__vI9aZNKIcImom6dDyKXW1ZA_8;				NI TM__vI9aZNKIcImom6dDyKXW1ZA_13;
#line 480 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
				T15_ = (NIM_BOOL)0;
#line 480 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 480 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
				T15_ = (i < s.len);				if (!(T15_)) goto LA16_;

#line 480 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
				if ((NU)(i) >= (NU)s.len){ raiseIndexError2(i,s.len-1); goto BeforeRet_;}				T15_ = (((NU8)(s.p->data[i])) >= ((NU8)(48)) && ((NU8)(s.p->data[i])) <= ((NU8)(57)));				LA16_: ;
				if (!T15_) goto LA14;

#line 481 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
				nimln_(481, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");
#line 481 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 481 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
				if ((NU)(i) >= (NU)s.len){ raiseIndexError2(i,s.len-1); goto BeforeRet_;}				if (nimSubInt(((NU8)(s.p->data[i])), ((NI) 48), &TM__vI9aZNKIcImom6dDyKXW1ZA_8)) { raiseOverflow(); goto BeforeRet_;};				c = (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_8);
#line 482 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
				nimln_(482, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");				{					NI TM__vI9aZNKIcImom6dDyKXW1ZA_9;					NI TM__vI9aZNKIcImom6dDyKXW1ZA_10;					NI TM__vI9aZNKIcImom6dDyKXW1ZA_11;					NI TM__vI9aZNKIcImom6dDyKXW1ZA_12;
#line 482 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 482 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 482 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
					if (nimSubInt(((NI) 2147483647), c, &TM__vI9aZNKIcImom6dDyKXW1ZA_9)) { raiseOverflow(); goto BeforeRet_;};					if (((NI) 10) == 0){ raiseDivByZero(); goto BeforeRet_;}					if (nimDivInt((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_9), ((NI) 10), &TM__vI9aZNKIcImom6dDyKXW1ZA_10)) { raiseOverflow(); goto BeforeRet_;};					if (!((*b) <= (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_10))) goto LA19_;

#line 483 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
					nimln_(483, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");
#line 483 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 483 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
					if (nimMulInt((*b), ((NI) 10), &TM__vI9aZNKIcImom6dDyKXW1ZA_11)) { raiseOverflow(); goto BeforeRet_;};					if (nimAddInt((NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_11), c, &TM__vI9aZNKIcImom6dDyKXW1ZA_12)) { raiseOverflow(); goto BeforeRet_;};					(*b) = (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_12);				}
				goto LA17_;
				LA19_: ;
				{
#line 485 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
					nimln_(485, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");					(*b) = ((NI) 2147483647);				}
				LA17_: ;

#line 486 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
				nimln_(486, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");				if (nimAddInt(i, ((NI) 1), &TM__vI9aZNKIcImom6dDyKXW1ZA_13)) { raiseOverflow(); goto BeforeRet_;};				i = (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_13);				{
#line 487 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
					nimln_(487, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");					while (1) {						NIM_BOOL T24_;						NI TM__vI9aZNKIcImom6dDyKXW1ZA_14;
#line 487 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
						T24_ = (NIM_BOOL)0;
#line 487 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"

#line 487 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
						T24_ = (i < s.len);						if (!(T24_)) goto LA25_;

#line 487 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
						if ((NU)(i) >= (NU)s.len){ raiseIndexError2(i,s.len-1); goto BeforeRet_;}						T24_ = ((NU8)(s.p->data[i]) == (NU8)(95));						LA25_: ;
						if (!T24_) goto LA23;

#line 487 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
						if (nimAddInt(i, ((NI) 1), &TM__vI9aZNKIcImom6dDyKXW1ZA_14)) { raiseOverflow(); goto BeforeRet_;};						i = (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_14);					} LA23: ;
				}
			} LA14: ;
		}

#line 488 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		nimln_(488, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim");
#line 488 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/parseutils.nim"
		if (nimSubInt(i, start, &TM__vI9aZNKIcImom6dDyKXW1ZA_15)) { raiseOverflow(); goto BeforeRet_;};		result = (NI)(TM__vI9aZNKIcImom6dDyKXW1ZA_15);	}
	LA11_: ;
	}BeforeRet_: ;
	popFrame();	return result;}
