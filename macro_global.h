#ifndef _MACRO_GLOBAL_H
#define _MACRO_GLOBAL_H
/**=============服务类型================== **/

/**请求某机器服务**/
#define S_REQUEST_SERVICE          1

/**返回应答结果**/
#define S_REPLAY_RESULT            2

/**请求固定资源，如文件，目录等，生命周期与文件系统相同的资源**/
#define S_REQUEST_RESOURCE_SOLID   3

/**请求生命周期同操作系统启动周期相同的资源；即关机之后会消失的资源；但程序运行结束不会消失的资源**/
#define S_REQUEST_RESOURCE_LIVE    4

/**请求动态资源，生命周期随程序运行周期**/
#define S_REQUEST_RESOURCE_DYNAMIC 5

/**订阅消息**/
#define S_SUBSCRIBE_MSG            6


/**=============资源的权限=================**/


/**必须要应答**/
#define A_MUST_REPLY               (0x1<<1)

/**可以委托其他服务器执行运算,但结果仍然是被请求的服务器返回**/
#define A_CAN_BE_DELEGATED         (0x1<<2)

/**可以写回**/
#define A_CAN_REWRITE              (0x1<<3)

/**只读**/
#define A_ONLY_READABLE            (0x1<<0)

/**可以其他服务器返回结果**/
#define A_CAN_REPLY_BE_DELEGATE    (0x1<<4)


/**=============错误代码===================**/
#define ERR_INFO_F(info)  {#info,info}

struct err_info_f
{
   char info[32];
   int  code; 
};
#define E_SUCCESS               0
#define E_CAN_NOT_FIND_RESOURCE     1
#define E_MACHINE_NOT_EXIT      2
#define E_CAN_NOT_BE_SUBSCRIBE  3
#define E_CAN_NOT_BE_SUBSCRIBE_CURRENT 4
#define E_MACHINE_BUSY          5
#define E_FUNCTION_NOT_EXIT     6
#define E_POINTER_NULL          7
#define E_REQUEST_REDIRECT      8
#define E_REDIRECT_FAILURE      9
#define E_ALLOW_REDIRECT        10
#define E_DONT_ALLOW_REDIRECT   11
#define E_REFUSE_SUBSCRIBE      12
#define E_AUTHORITY_FAILURE     13
#define E_MACHINE_NOT_AVAILABLE 14  

static struct err_info_f err_info_f[] = {
ERR_INFO_F( E_SUCCESS),
ERR_INFO_F( E_CAN_NOT_FIND_RESOURCE),
ERR_INFO_F( E_MACHINE_NOT_EXIT),
ERR_INFO_F( E_CAN_NOT_BE_SUBSCRIBE),
ERR_INFO_F( E_CAN_NOT_BE_SUBSCRIBE_CURRENT),
ERR_INFO_F( E_MACHINE_BUSY),          
ERR_INFO_F( E_FUNCTION_NOT_EXIT),     
ERR_INFO_F( E_POINTER_NULL),          
ERR_INFO_F( E_REQUEST_REDIRECT),      
ERR_INFO_F( E_REDIRECT_FAILURE),      
ERR_INFO_F( E_ALLOW_REDIRECT),
ERR_INFO_F( E_DONT_ALLOW_REDIRECT),
ERR_INFO_F( E_REFUSE_SUBSCRIBE),
ERR_INFO_F( E_AUTHORITY_FAILURE),   
ERR_INFO_F( E_MACHINE_NOT_AVAILABLE)
};

const* get_readable_errstr(int i)
{
     return err_info_f[i].info;
}





#endif















