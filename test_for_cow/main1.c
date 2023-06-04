#include <stdio.h>
#include <sys/types.h>
#include <dlfcn.h>
#include "hello.h"
#include <sys/mman.h>

int main()
{

    
    FILE *maps_fd;
    char maps_path[64] = "/proc/self/maps";
    if ((maps_fd = fopen(maps_path, "r")) == NULL) {
        perror("open maps file");
        return -1;
    }

    /* 读取 maps */
    char line[256];
    char attr[256];
    char module_path[256];
    unsigned long start_addr, end_addr, offset, inode,printhello_addr;
    
    while (fgets(line, 256, maps_fd)) {
        /* 格式化对应列的数据，并判断是否是需要查找的模块 */
        //puts(line);
        sscanf(line, "%lx-%lx %4c %lx %*x:%*x %lu %s", &start_addr, &end_addr,  attr, &offset, &inode, module_path);
        
        puts(line);
        /* 如果当前模块路径匹配，说明找到了需要的动态链接库 */
        if (strstr(module_path, "libhello.so") && strstr(attr, "x")) {
            printf("[*] Found module: %s\n", module_path);
            break;
        }
                
    }
    
    printf("%16lx\n", *(long *)(start_addr+0x105));
    printhello_addr = start_addr+0x105;
    
    mprotect(start_addr, getpagesize(), PROT_READ | PROT_WRITE | PROT_EXEC);
	void (*function)(void) = (void (*)(void))printhello_addr;
	function();
	
	//memset(printhello_addr,0xc3, 4);
	//加载动态库 
	
	
	for(;;)
	{
		printf("orign print:");
		printhello();
		sleep(2);
	}

	return 0;   

}
