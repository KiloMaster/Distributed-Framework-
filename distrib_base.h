#include "macro_global.h"
#include <time.h>
#include <pthread.h>


#define Dargv_interval 8
#define Dregister(func)\
Dregister_(func,#func);

typedef struct Droutine_id
{
   uint32_t IP;
   uint16_t port;
   time_t    tm;
   uint64_t  id;
} Droutine_id_t;

typedef struct Dargs
{
   Droutine_id_t    rid;
   pthread_rwlock_t rwlock;/**防止多线程修改，暂时没有使用到**/
   char     funcName[8];
   pid_t    pid;  
   pthread_t  pth_id;  
   int      argc;
   int      size;
   int      cursor;
   int      pointer_cursor;
   int      errno;
   uint64_t pointer_map[16];
   uint8    argv[0]; 
} Dargs_t;

typedef Dargs_t* (*Droutine_t)(Dargs_t*);

/**注册分布式事务处理函数**/
extern Dregister_(Droutine_t rt,char* rt_name);

#define   D_ARGS  Droutine_args* _args_Df_

#define   get_darg_int32()\
          ((*_args_Df_).cursor+=sizeof(int32_t),*(int32_t* )((*_args_Df_).argv - 4 + (*_args_Df_).cursor)+ Dargv_interval)

#define   get_darg_int64()\
          ((*_args_Df_).cursor+=sizeof(int64_t),*(int64_t* )((*_args_Df_).argv - 8 + (*_args_Df_).cursor)+ Dargv_interval)

#define   get_darg_pointer32()\
          ((*_args_Df_).cursor+=sizeof(int32_t),(*_args_Df_).pointer_cursor++,*(int32_t* )((*_args_Df_).argv - 4 + (*_args_Df_).cursor)+ Dargv_interval)

#define   get_darg_pointer64()\
          ((*_args_Df_).cursor+=sizeof(int64_t),(*_args_Df_).pointer_cursor++,*(int64_t* )((*_args_Df_).argv - 8 + (*_args_Df_).cursor)+ Dargv_interval)

#define   Dmap(ptr,nmemb)\
          Dmap_(_args_Df_,ptr,sizeof(*ptr),nmemb) 

#define   Dfopen(fname,mod)\
          Dfopen_(_args_Df_,fname,ptr) 

#define   Dfread(bf,sz,nmemb,stream)\
          Dfread_(_args_Df_,bf,sz,nmemb,stream)

#define   Dfwrite(bf,sz,nmemb,stream)\
          Dfwrite_(_args_Df_,bf,sz,nmemb,stream)

#define   Dfclose(fptr)\
          Dfclose_(_args_Df_,fptr)









