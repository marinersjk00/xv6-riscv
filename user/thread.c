#include "kernel/stat.h"
#include "kernel/types.h"
#include "user/thread.h"
#include "user/user.h"

int thread_create(void *(start_routine)(void*), void *arg){
    void* stack = malloc(4096);
    int cloneVal = clone(stack);
    if(cloneVal == -1){
        return -1;
    }else if(cloneVal == 0){
        start_routine(arg);
        exit(0);
    }else{
        return 0;
    }
    
}




void lock_init(struct lock_t* lock){
    lock->locked = 0;
}

void lock_acquire(struct lock_t* lock){
    
  //  while(__sync_lock_test_and_set(&lock->locked, 1) != 0)
   // ;

    __sync_synchronize();




}

void lock_release(struct lock_t* lock){
    
    __sync_synchronize();

    __sync_lock_release(&lock->locked);


}