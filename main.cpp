#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int globalVar = 100;
static int staticGlobalVar = 200;

// TODO: Declare 2 uninitialized global variables (BSS segment)
int uninitGlobal1;
int uninitGlobal2;

// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    cout << "main local addr (parent frame) : " << (void*)parentAddr << endl;
    cout << "param addr (child frame) : " << (void*)&parentAddr << endl;
    cout << "child local addr (child frame) : " << (void*)&childVar << endl;
    cout << "Stack grows: " << ((&childVar < parentAddr) ? "DOWN" : "UP") << endl;
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int minVar = 10;
    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    char* heapVar1 = (char*)malloc(1024);
    char* heapVar2 = (char*)malloc(1024);

    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    cout << "Address of main(): " << (void*)&main << endl;
    cout << "Address of checkStack(): " << (void*)&checkStack << endl;
    cout << endl;

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "Address of globalVar: " << (void*)&globalVar << endl;
    cout << "Value of globalVar: " << globalVar << endl;
    cout << "Address of staticGlobalVar: " << (void*)&staticGlobalVar << endl;
    cout << "Value of staticGlobalVar: " << staticGlobalVar << endl;
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    cout << "Address of uninitGlobal1: " << (void*)&uninitGlobal1 << " value: " << uninitGlobal1 << endl;
    cout << "Address of uninitGlobal2: " << (void*)&uninitGlobal2 << " value: " << uninitGlobal2 << endl;
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);
    checkStack(&minVar);

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    cout << "heapVar1 addr: " << (void*)heapVar1 << endl;
    cout << "heapVar2 addr: " << (void*)heapVar2 << endl;
    cout << "Heap grows: " << ((heapVar2 > heapVar1) ? "UP" : "DOWN") << endl;
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    cout << "TEXT (lowest) : " << (void*)&main << endl;
    cout << "DATA : " << (void*)&globalVar << endl;
    cout << "BSS : " << (void*)&uninitGlobal1 << endl;
    cout << "HEAP : " << (void*)heapVar1 << endl;
    cout << "STACK (highest) : " << (void*)&minVar << endl;

    // TODO: Free all heap allocations
    free(heapVar1);
    free(heapVar2);

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses?
 * - Which has the highest?
 * - Does stack grow down? How did you verify this?
 * - Does heap grow up? How did you verify this?
 * - What is the gap between HEAP and STACK?
 */
