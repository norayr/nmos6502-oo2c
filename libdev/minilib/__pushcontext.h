{
  void **src_ptr = (void**)(_SOURCE_PTR);
typedef int __jmp_buf[6];
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int))) ];
  } __sigset_t;
typedef struct __jmp_buf_tag	 
  {
    __jmp_buf __jmpbuf;		 
    int __mask_was_saved;	 
    __sigset_t __saved_mask;	 
  } jmp_buf[1];
extern int __sigsetjmp  (jmp_buf __env, int __savemask)    ;
extern void longjmp  (jmp_buf __env, int __val)    
     __attribute__ ((__noreturn__));
extern void _longjmp  (jmp_buf __env, int __val)    
     __attribute__ ((__noreturn__));
typedef jmp_buf sigjmp_buf;
extern void siglongjmp  (sigjmp_buf __env, int __val)    
     __attribute__ ((__noreturn__));
  _SAVE_RVARS
  _push_exception_context (&_local_context);
  if (__sigsetjmp (( *(jmp_buf*)(&_local_context.jmpbuf) ), 0)  > 0) {
    extern void* _exception_source;
    _RESTORE_RVARS
    *src_ptr = (void*)_exception_source;
  } else {
    *src_ptr = NULL;
  }
}
