// Memory
    // - stack vs heap
    // - static vs dynamic memory allocation
// In-memory Layout of a program
    // Os Kernal Space - User code cannot readfrom nor write to these addresses, otherwise resulting in segmentation fault
    // Stack - Automatic variables(local to a function's scope) (grows towards lower memory address)

    // 1.Heap - dynamic memory allocation through malloc/new free/delete (grows towards higher memory address)
    // 2.BSS - Uninitialized static variables, filled with zeros
    // 3.Data - Static variables explicitly, initilized
    // 4.Text - Binary image of the process

// Stack memory
    // Each thread has it's own stack
    //  A "stack frame" is created when a function is called. Hence, all the local variables of that fucntion are created within the confines of this stack frame.
    // when the fucntion returns, its stack frame is "deleted" and happpens automatically
    // Big Limitation of stack: how to store variables that one can access across function calls?
        // - such a memory to store global variables is called the heap memory
        // Stacks has a size limit and if it overflows we call it stack overflow
            //  Use the command line (ulimit -a)

