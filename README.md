# Small Garbage Collector For C
A small garbage collector software for C.

# Usage
The new Garbage Collector function creates a new GC object. This object has list and dataofadress properties. dataofaddres stores the address of the memory block allocated from the heap. If no pointer points to this address, this address is deleted with the check function. The assign function is used to assign the same pointer to another pointer. In this way, the addresses of all pointers pointing to the same object are stored in the list. The check function, on the other hand, deletes it from memory with the free function if no pointer points to that object.
