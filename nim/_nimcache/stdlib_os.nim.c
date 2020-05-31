/* Generated by Nim Compiler v1.3.5 */
/*   (c) 2020 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32
#define NIM_EmulateOverflowChecks

/* section: NIM_merge_HEADERS */

#include "nimbase.h"
#include <string.h>
#include <time.h>
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
typedef struct tySequence__sM4lkSb7zS6F7OVMvW9cffQ tySequence__sM4lkSb7zS6F7OVMvW9cffQ;
typedef struct tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content;
typedef struct NimStrPayload NimStrPayload;
typedef struct NimStringV2 NimStringV2;
typedef struct tyObject_IndexDefect__n6tGEPHKkh7E1AP9bj30WrQ tyObject_IndexDefect__n6tGEPHKkh7E1AP9bj30WrQ;
typedef struct tyObject_Defect__LbeSGvgPzGzXnW9caIkJqMA tyObject_Defect__LbeSGvgPzGzXnW9caIkJqMA;
typedef struct Exception Exception;
typedef struct RootObj RootObj;
typedef struct TNimType TNimType;
typedef struct tySequence__uB9b75OUPRENsBAu4AnoePA tySequence__uB9b75OUPRENsBAu4AnoePA;
typedef struct tySequence__uB9b75OUPRENsBAu4AnoePA_Content tySequence__uB9b75OUPRENsBAu4AnoePA_Content;
typedef struct TNimNode TNimNode;
typedef struct tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA;

/* section: NIM_merge_TYPES */
struct tySequence__sM4lkSb7zS6F7OVMvW9cffQ {
  NI len; tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content* p;
};
struct NimStrPayload {NI cap;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct NimStringV2 {NI len;
NimStrPayload* p;
};
struct TNimType {void* destructor;
NI size;
NI align;
NCSTRING name;
void* traceImpl;
void* disposeImpl;
};
struct RootObj {TNimType* m_type;};
struct tySequence__uB9b75OUPRENsBAu4AnoePA {
  NI len; tySequence__uB9b75OUPRENsBAu4AnoePA_Content* p;
};
struct Exception {  RootObj Sup;Exception* parent;
NCSTRING name;
NimStringV2 message;
tySequence__uB9b75OUPRENsBAu4AnoePA trace;
Exception* up;
};
struct tyObject_Defect__LbeSGvgPzGzXnW9caIkJqMA {  Exception Sup;};
struct tyObject_IndexDefect__n6tGEPHKkh7E1AP9bj30WrQ {  tyObject_Defect__LbeSGvgPzGzXnW9caIkJqMA Sup;};
struct TNimNode {char dummy;
};


#ifndef tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content_PP
#define tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content_PP
struct tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content { NI cap; NimStringV2 data[SEQ_DECL_SIZE];};
#endif

      

#ifndef tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content_PP
#define tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content_PP
struct tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content { NI cap; NimStringV2 data[SEQ_DECL_SIZE];};
#endif

      

#ifndef tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content_PP
#define tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content_PP
struct tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content { NI cap; NimStringV2 data[SEQ_DECL_SIZE];};
#endif

      struct tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA {NCSTRING procname;
NI line;
NCSTRING filename;
};


#ifndef tySequence__uB9b75OUPRENsBAu4AnoePA_Content_PP
#define tySequence__uB9b75OUPRENsBAu4AnoePA_Content_PP
struct tySequence__uB9b75OUPRENsBAu4AnoePA_Content { NI cap; tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA data[SEQ_DECL_SIZE];};
#endif

      
/* section: NIM_merge_PROC_HEADERS */
N_LIB_PRIVATE N_NIMCALL(void*, newSeqPayload)(NI cap, NI elemSize, NI elemAlign);
N_LIB_PRIVATE N_NIMCALL(NI, paramCount__LYkRnwMk6UXTCs9c59cPvZsQ)(void);
static N_INLINE(NIM_BOOL, nimSubInt)(NI a, NI b, NI* res);
N_LIB_PRIVATE N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(void, nimFrame)(TFrame* s_0);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(void, add__dK9ajFgX5RSWQx0eHjjpjSQ)(tySequence__sM4lkSb7zS6F7OVMvW9cffQ* x, NimStringV2 value_0);
N_LIB_PRIVATE N_NIMCALL(NimStringV2, paramStr__T0ST6UXXTEqaiXY9akIayng)(NI i_0);
N_LIB_PRIVATE N_NIMCALL(NimStringV2, cstrToNimstr)(NCSTRING str);
N_LIB_PRIVATE N_NIMCALL(void, eqdestroy___dS1BF3Vxjg9aJMmmhVJKSpQ)(NimStringV2* dest);
N_LIB_PRIVATE N_NIMCALL(void*, nimNewObj)(NI size_0);
static N_INLINE(void, appendString)(NimStringV2* dest, NimStringV2 src);
static N_INLINE(void, copyMem__M04YC71iJg1N7gBF3HZTngsystem)(void* dest, void* source, NI size_0);
static N_INLINE(void, nimCopyMem)(void* dest, void* source, NI size_0);
static N_INLINE(NIM_BOOL, nimAddInt)(NI a, NI b, NI* res);
N_LIB_PRIVATE N_NOINLINE(void, raiseRangeErrorI)(NI64 i_0, NI64 a, NI64 b);
N_LIB_PRIVATE N_NIMCALL(void, eqsink___aBBXmHFBEivKqERloP6zmA)(NimStringV2* dest, NimStringV2 src);
N_LIB_PRIVATE N_NIMCALL(NimStringV2, nimIntToStr)(NI x);
N_LIB_PRIVATE N_NIMCALL(NimStringV2, rawNewString)(NI space);
N_LIB_PRIVATE N_NIMCALL(void, raiseExceptionEx)(Exception* e, NCSTRING ename, NCSTRING procname, NCSTRING filename, NI line);
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void);
static N_INLINE(void, nimZeroMem)(void* p_0, NI size_0);
static N_INLINE(void, nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory)(void* a, int v, NI size_0);
N_LIB_PRIVATE N_NOINLINE(void, raiseDivByZero)(void);
static N_INLINE(NIM_BOOL, nimDivInt)(NI a, NI b, NI* res);
static N_INLINE(NIM_BOOL, nimMulInt)(NI a, NI b, NI* res);
static N_INLINE(NF, toFloat__y1Fm9aHmxw9bS2jir137Fu5gsystem)(NI i_0);
static N_INLINE(NF, abs__BRaAqinz6OWTHkALb4oj6Qsystem)(NF x);

/* section: NIM_merge_DATA */
extern TNimType NTI__n6tGEPHKkh7E1AP9bj30WrQ_;
static const struct {
  NI cap; NIM_CHAR data[43+1];
} TM__yu6cxgKBBXbNsTkT9cyMd4g_4 = { 43 | NIM_STRLIT_FLAG, "index out of bounds, the container is empty" };
static const NimStringV2 TM__yu6cxgKBBXbNsTkT9cyMd4g_5 = {43, (NimStrPayload*)&TM__yu6cxgKBBXbNsTkT9cyMd4g_4};
static const struct {
  NI cap; NIM_CHAR data[6+1];
} TM__yu6cxgKBBXbNsTkT9cyMd4g_6 = { 6 | NIM_STRLIT_FLAG, "index " };
static const NimStringV2 TM__yu6cxgKBBXbNsTkT9cyMd4g_7 = {6, (NimStrPayload*)&TM__yu6cxgKBBXbNsTkT9cyMd4g_6};
static const struct {
  NI cap; NIM_CHAR data[13+1];
} TM__yu6cxgKBBXbNsTkT9cyMd4g_10 = { 13 | NIM_STRLIT_FLAG, " not in 0 .. " };
static const NimStringV2 TM__yu6cxgKBBXbNsTkT9cyMd4g_11 = {13, (NimStrPayload*)&TM__yu6cxgKBBXbNsTkT9cyMd4g_10};

/* section: NIM_merge_VARS */
N_LIB_PRIVATE NIM_THREADVAR tySequence__sM4lkSb7zS6F7OVMvW9cffQ environment__mlhK49b6YMgc9cgrcYkKq9a3g;
N_LIB_PRIVATE NIM_THREADVAR NIM_BOOL envComputed__LLyFo9bsdu1ZXMDvAe8DhrQ;
extern NCSTRING* environ;
extern int cmdCount;
extern NCSTRING* cmdLine;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR NIM_BOOL nimInErrorMode__759bT87luu8XGcbkw13FUjA;

/* section: NIM_merge_PROCS */

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
static N_INLINE(void, nimFrame)(TFrame* s_0) {
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!(framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA3_;

#line 551 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s_0).calldepth = ((NI16) 0);	}
	goto LA1_;
	LA3_: ;
	{
#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"

#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s_0).calldepth = (NI16)((*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1));	}
	LA1_: ;

#line 556 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	(*s_0).prev = framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
#line 557 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = s_0;
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!((*s_0).calldepth == ((NI16) 2000))) goto LA8_;

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

#line 2779 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
N_LIB_PRIVATE N_NIMCALL(NI, paramCount__LYkRnwMk6UXTCs9c59cPvZsQ)(void) {	NI result;	NI32 TM__yu6cxgKBBXbNsTkT9cyMd4g_2;	nimfr_("paramCount", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");{	result = (NI)0;
#line 2781 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(2781, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");
#line 2781 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	if (nimSubInt(cmdCount, ((NI32) 1), &TM__yu6cxgKBBXbNsTkT9cyMd4g_2)) { raiseOverflow(); goto BeforeRet_;};	result = ((NI) ((NI32)(TM__yu6cxgKBBXbNsTkT9cyMd4g_2)));	}BeforeRet_: ;
	popFrame();	return result;}

#line 11 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
static N_INLINE(void, nimCopyMem)(void* dest, void* source, NI size_0) {	void* T1_;
#line 13 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"

#line 13 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
	T1_ = (void*)0;	T1_ = memcpy(dest, source, ((size_t) (size_0)));}

#line 2138 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
static N_INLINE(void, copyMem__M04YC71iJg1N7gBF3HZTngsystem)(void* dest, void* source, NI size_0) {
#line 2139 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"

#line 2139 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
	nimCopyMem(dest, source, size_0);
}

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

#line 80 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
static N_INLINE(void, appendString)(NimStringV2* dest, NimStringV2 src) {{
#line 81 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
	{		NI TM__yu6cxgKBBXbNsTkT9cyMd4g_8;		NI TM__yu6cxgKBBXbNsTkT9cyMd4g_9;
#line 81 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
		if (!(((NI) 0) < src.len)) goto LA3_;

#line 83 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"

#line 83 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
		if (nimAddInt(src.len, ((NI) 1), &TM__yu6cxgKBBXbNsTkT9cyMd4g_8)) { raiseOverflow(); goto BeforeRet_;};		if (((NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_8)) < ((NI) 0) || ((NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_8)) > ((NI) 2147483647)){ raiseRangeErrorI((NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_8), ((NI) 0), ((NI) 2147483647)); goto BeforeRet_;}
#line 83 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
		copyMem__M04YC71iJg1N7gBF3HZTngsystem(((void*) ((&(*(*dest).p).data[(*dest).len]))), ((void*) ((&(*src.p).data[((NI) 0)]))), ((NI) ((NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_8))));

#line 84 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
		if (nimAddInt((*dest).len, src.len, &TM__yu6cxgKBBXbNsTkT9cyMd4g_9)) { raiseOverflow(); goto BeforeRet_;};		(*dest).len = (NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_9);	}
	LA3_: ;
	}BeforeRet_: ;
}

#line 424 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void) {	NIM_BOOL* result;	result = (NIM_BOOL*)0;
#line 425 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	result = (&nimInErrorMode__759bT87luu8XGcbkw13FUjA);	return result;}

#line 2774 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
N_LIB_PRIVATE N_NIMCALL(NimStringV2, paramStr__T0ST6UXXTEqaiXY9akIayng)(NI i_0) {	NimStringV2 result;	NimStringV2 colontmpD_;	NimStringV2 colontmpD__2;	tyObject_IndexDefect__n6tGEPHKkh7E1AP9bj30WrQ* T8_;NIM_BOOL* nimErr_;	nimfr_("paramStr", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");{nimErr_ = nimErrorFlag();	result.len = 0; result.p = NIM_NIL;	colontmpD_.len = 0; colontmpD_.p = NIM_NIL;	colontmpD__2.len = 0; colontmpD__2.p = NIM_NIL;
#line 2776 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(2776, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");	{		NIM_BOOL T4_;
#line 2776 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		T4_ = (NIM_BOOL)0;
#line 2776 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		T4_ = (i_0 < ((NI) (cmdCount)));		if (!(T4_)) goto LA5_;

#line 2776 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		T4_ = (((NI) 0) <= i_0);		LA5_: ;
		if (!T4_) goto LA6_;

#line 2776 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"

#line 2776 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"

#line 2776 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		result = cstrToNimstr(cmdLine[i_0]);
#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		nimln_(49, "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim");
#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		eqdestroy___dS1BF3Vxjg9aJMmmhVJKSpQ((&colontmpD__2));

#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"

#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		eqdestroy___dS1BF3Vxjg9aJMmmhVJKSpQ((&colontmpD_));
		goto BeforeRet_;
	}
	LA6_: ;
	T8_ = (tyObject_IndexDefect__n6tGEPHKkh7E1AP9bj30WrQ*)0;	T8_ = (tyObject_IndexDefect__n6tGEPHKkh7E1AP9bj30WrQ*) nimNewObj(sizeof(tyObject_IndexDefect__n6tGEPHKkh7E1AP9bj30WrQ));	(*T8_).Sup.Sup.Sup.m_type = (&NTI__n6tGEPHKkh7E1AP9bj30WrQ_);	(*T8_).Sup.Sup.name = "IndexDefect";
#line 2777 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(2777, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");	{		NI32 TM__yu6cxgKBBXbNsTkT9cyMd4g_3;
#line 7 "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors.nim"
		nimln_(7, "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors."
"nim");
#line 2777 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		nimln_(2777, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");		if (nimSubInt(cmdCount, ((NI32) 1), &TM__yu6cxgKBBXbNsTkT9cyMd4g_3)) { raiseOverflow(); goto LA1_;};		if (!((NI32)(TM__yu6cxgKBBXbNsTkT9cyMd4g_3) < ((NI32) 0))) goto LA11_;
		(*T8_).Sup.Sup.message = TM__yu6cxgKBBXbNsTkT9cyMd4g_5;	}
	goto LA9_;
	LA11_: ;
	{		NimStringV2 T14_;		NimStringV2 T15_;		NI32 TM__yu6cxgKBBXbNsTkT9cyMd4g_12;		NimStringV2 T16_;
#line 8 "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors.nim"
		nimln_(8, "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors."
"nim");		T14_.len = 0; T14_.p = NIM_NIL;
#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		nimln_(49, "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim");
#line 8 "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors.nim"
		nimln_(8, "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors."
"nim");		T15_.len = 0; T15_.p = NIM_NIL;		T15_ = nimIntToStr(i_0);
#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		nimln_(49, "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim");		eqsink___aBBXmHFBEivKqERloP6zmA((&colontmpD_), T15_);

#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"

#line 8 "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors.nim"
		nimln_(8, "/home/elcritch/.asdf/installs/nim/devel/lib/system/indexerrors."
"nim");
#line 2777 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		nimln_(2777, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");		if (nimSubInt(cmdCount, ((NI32) 1), &TM__yu6cxgKBBXbNsTkT9cyMd4g_12)) { raiseOverflow(); goto LA1_;};		T16_.len = 0; T16_.p = NIM_NIL;		T16_ = nimIntToStr(((NI) ((NI32)(TM__yu6cxgKBBXbNsTkT9cyMd4g_12))));
#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		nimln_(49, "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim");		eqsink___aBBXmHFBEivKqERloP6zmA((&colontmpD__2), T16_);
		T14_ = rawNewString(colontmpD_.len + colontmpD__2.len + 19);appendString((&T14_), TM__yu6cxgKBBXbNsTkT9cyMd4g_7);appendString((&T14_), colontmpD_);appendString((&T14_), TM__yu6cxgKBBXbNsTkT9cyMd4g_11);appendString((&T14_), colontmpD__2);		(*T8_).Sup.Sup.message = T14_;	}
	LA9_: ;
	(*T8_).Sup.Sup.parent = NIM_NIL;
#line 2777 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(2777, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");	raiseExceptionEx((Exception*)T8_, "IndexDefect", "paramStr", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim", 2777);	goto LA1_;	{		LA1_:;	}
	{
#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		nimln_(49, "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim");
#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		eqdestroy___dS1BF3Vxjg9aJMmmhVJKSpQ((&colontmpD__2));

#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"

#line 49 "/home/elcritch/.asdf/installs/nim/devel/lib/system/fatal.nim"
		eqdestroy___dS1BF3Vxjg9aJMmmhVJKSpQ((&colontmpD_));
	}
	if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;	}BeforeRet_: ;
	popFrame();	return result;}

#line 2784 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
N_LIB_PRIVATE N_NIMCALL(tySequence__sM4lkSb7zS6F7OVMvW9cffQ, commandLineParams__K1tl5In8R9bx536wDa4ggRw)(void) {	tySequence__sM4lkSb7zS6F7OVMvW9cffQ result;NIM_BOOL* nimErr_;	nimfr_("commandLineParams", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");{nimErr_ = nimErrorFlag();	result.len = 0; result.p = NIM_NIL;
#line 2809 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(2809, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");	result.len = 0; result.p = (tySequence__sM4lkSb7zS6F7OVMvW9cffQ_Content*) newSeqPayload(0, sizeof(NimStringV2), NIM_ALIGNOF(NimStringV2));	{		NI i_1;		NI colontmp_;		NI res;		i_1 = (NI)0;		colontmp_ = (NI)0;
#line 2810 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		nimln_(2810, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");
#line 2810 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
		colontmp_ = paramCount__LYkRnwMk6UXTCs9c59cPvZsQ();		if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;
#line 77 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators_1.nim"
		nimln_(77, "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators_1."
"nim");		res = ((NI) 1);		{
#line 78 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators_1.nim"
			nimln_(78, "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators_1."
"nim");			while (1) {				NimStringV2 T4_;				NI TM__yu6cxgKBBXbNsTkT9cyMd4g_13;
#line 78 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators_1.nim"
				if (!(res <= colontmp_)) goto LA3;

#line 2810 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
				nimln_(2810, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");				i_1 = res;
#line 2811 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
				nimln_(2811, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");
#line 2811 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"

#line 2811 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
				T4_.len = 0; T4_.p = NIM_NIL;				T4_ = paramStr__T0ST6UXXTEqaiXY9akIayng(i_1);				if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;
#line 2811 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
				add__dK9ajFgX5RSWQx0eHjjpjSQ((&result), T4_);

#line 80 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators_1.nim"
				nimln_(80, "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators_1."
"nim");				if (nimAddInt(res, ((NI) 1), &TM__yu6cxgKBBXbNsTkT9cyMd4g_13)) { raiseOverflow(); goto BeforeRet_;};				res = (NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_13);			} LA3: ;
		}
	}
	}BeforeRet_: ;
	popFrame();	return result;}

#line 22 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
static N_INLINE(void, nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory)(void* a, int v, NI size_0) {	void* T1_;
#line 24 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"

#line 24 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
	T1_ = (void*)0;	T1_ = memset(a, v, ((size_t) (size_0)));}

#line 33 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
static N_INLINE(void, nimZeroMem)(void* p_0, NI size_0) {NIM_BOOL* nimErr_;{nimErr_ = nimErrorFlag();
#line 34 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"

#line 34 "/home/elcritch/.asdf/installs/nim/devel/lib/system/memory.nim"
	nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory(p_0, ((int) 0), size_0);
	if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;	}BeforeRet_: ;
}

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
static N_INLINE(NF, toFloat__y1Fm9aHmxw9bS2jir137Fu5gsystem)(NI i_0) {	NF result;	nimfr_("toFloat", "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim");	result = (NF)0;
#line 1392 "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim"
	nimln_(1392, "/home/elcritch/.asdf/installs/nim/devel/lib/system.nim");	result = ((NF) (i_0));	popFrame();	return result;}

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

#line 3011 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
N_LIB_PRIVATE N_NIMCALL(void, nossleep)(NI milsecs) {	struct timespec a;	struct timespec b;	NI TM__yu6cxgKBBXbNsTkT9cyMd4g_14;	NI TM__yu6cxgKBBXbNsTkT9cyMd4g_15;	NI TM__yu6cxgKBBXbNsTkT9cyMd4g_16;	NI TM__yu6cxgKBBXbNsTkT9cyMd4g_17;	int T1_;	nimfr_("sleep", "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");{	nimZeroMem((void*)(&a), sizeof(struct timespec));	nimZeroMem((void*)(&b), sizeof(struct timespec));
#line 3017 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(3017, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");
#line 3017 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	if (((NI) 1000) == 0){ raiseDivByZero(); goto BeforeRet_;}	if (nimDivInt(milsecs, ((NI) 1000), &TM__yu6cxgKBBXbNsTkT9cyMd4g_14)) { raiseOverflow(); goto BeforeRet_;};	a.tv_sec = (NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_14);
#line 3018 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(3018, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");
#line 3018 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"

#line 3018 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"

#line 3018 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	if (((NI) 1000) == 0){ raiseDivByZero(); goto BeforeRet_;}	if (nimModInt(milsecs, ((NI) 1000), &TM__yu6cxgKBBXbNsTkT9cyMd4g_15)) { raiseOverflow(); goto BeforeRet_;};	if (nimMulInt((NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_15), ((NI) 1000), &TM__yu6cxgKBBXbNsTkT9cyMd4g_16)) { raiseOverflow(); goto BeforeRet_;};	if (nimMulInt((NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_16), ((NI) 1000), &TM__yu6cxgKBBXbNsTkT9cyMd4g_17)) { raiseOverflow(); goto BeforeRet_;};	a.tv_nsec = (NI)(TM__yu6cxgKBBXbNsTkT9cyMd4g_17);
#line 3019 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	nimln_(3019, "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim");
#line 3019 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"

#line 3019 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/os.nim"
	T1_ = (int)0;	T1_ = nanosleep((&a), (&b));	(void)(T1_);
	}BeforeRet_: ;
	popFrame();}
