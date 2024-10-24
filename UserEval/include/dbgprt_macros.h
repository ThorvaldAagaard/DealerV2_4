/* File dbgprt_macros.h in UserEval */
#ifndef DBGPRT_MACROS_H
#define DBGPRT_MACROS_H
/* this next line should come from the environment. */
//  #define JGMDBG 1   /* for testing  */
#ifdef JGMDBG
  #define DBGPRINT(...) fprintf(stderr, __VA_ARGS__)
  #define DBGLOC(fmt,...) fprintf(stderr, "%s:%d " fmt, __FILE__,__LINE__,## __VA_ARGS__)
  #define PHEX(x) do { fprintf(stderr, "%#10x %s\n", (x) , #x ) ;} while (0)
  #define DBGBLK(...) do { fprintf(stderr, __VA_ARGS__); fflush(stderr); } while(0)
  #define JGMDPRT(l,fmt,...) do {if (jgmDebug >= (l)) { fprintf(stderr, "%s:%d " fmt, __FILE__,__LINE__,## __VA_ARGS__) ; } } while(0)
  #define DBGDO(l,...) do { if(jgmDebug >= (l) ) {(__VA_ARGS__) ; } } while (0)  // call an arbitrary subroutine ...
#else
  #define DBGDO(l,...)   // Note You still need the arglist here to gobble up what is in the code
  #define DBGPRINT(...)
  #define DBGLOC(fmt,...)
  #define PHEX(x)
  #define DBGBLK(...)
  #define JGMDPRT(l,fmt,...)
#endif
/* Note that in the PHEX, the value is in a fixed width field so the value lines up right justified. The descr is on the right.
   Testing PHEX 
     0xfff 4095  			PHEX( 4095 ) ;
       0x3 NR				NR = 3 ; PHEX(NR) ;
      0x41 str[0] 		char str[4] = "ABC"; PHEX( str[0] ) ; 
0xffffffff -1				PHEX ( -1 ) ;

 */
#endif
