#include <sys/resource.h>
void func() 
{
    const rlim_t kStackSize = 16L * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
        if (rl.rlim_cur < kStackSize)
            rl.rlim_cur = kStackSize, result = setrlimit(RLIMIT_STACK, &rl);
}
#define int long long    // its important you declare this line after the function as during 
                        // compiling it will change the int to long long which will give compilation errors
