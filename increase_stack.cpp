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

//In competitive programming sometimes it's the case that you declare some arrays or makes recursive functions 
//that go for like 2e5 iterations and then your system get a run time error as SIGSEGV or in this specific case
//stack overflow. The reason for this is that by default stack size is limited to some 1MB but if you want to run the big test case
//then in that case you would have to increase the stack size. The function above increases the stack size to the memory you specify.
