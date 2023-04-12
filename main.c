#include "garbage_collector.h"
int main(void){
    GarbageCollector *gc = new_GarbageCollector();
  
    int *numbers = allocate_memory(&numbers, 5, gc);
  
    for (int i = 0; i < 5; ++i) {
        numbers[i] = i+10;
    }
  
    int *copyNumbers = assign(&copyNumbers, numbers, gc);
  
    numbers = NULL;
  
    check(gc);
  
    copyNumbers = NULL;
  
    check(gc);
    return 0;
}
