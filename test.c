#include <stdio.h>
#include "macro_global.h"
void main()
{
    for(int i = 0; i <14;i++)
    {
       printf("%s,  %d\n", err_info_f[i].info,err_info_f[i].code);
    }
}
