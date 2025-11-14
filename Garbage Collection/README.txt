ARC stands for Automatic Reference Counter. Because this is CS, acronyms get mixed up.

ARC can also mean "Atomic Reference counting" which is related to rust and is just as important.

Auto addresses the problem of memory leaks, by counting how many pointers own that object, at zero the object is considered "garbage".

Atomic addresses the problem of cycles and graphs, thread safety. If two objects hold shared_ptr to each other, their strong counts never reach zero — that creates a leak.

High level: C++ gives you manual memory control, but you can build a GC on top of it. Two common approaches:
1. Reference counting (deterministic, low pause, simple) — needs extra work to handle cycles.
2. Tracing (mark-and-sweep or copying) — handles cycles, needs root discovery and pauses.


Cycles and the role of weak pointers
Reference counting alone cannot reclaim cyclic graphs (A -> B -> A) because strong counts never reach zero. Weak pointers break cycles: one side of the cycle must hold a weak reference so its presence doesn’t keep the other alive. In Rust/Cpp/other systems the pattern is:
• parent has strong to child
• child has weak to parent
When parents are dropped, children get destroyed even if they point back with weak pointers.


Design choices and tradeoffs
1 Determinism: reference counting destroys objects immediately when count hits zero(this is what we originally wanted, something automatic); tracing collects later (non-deterministic destruction time).
2 Complexity: RC is easy to implement; tracing needs root management and a traversal algorithm.
3 Cycles: RC leaks unless you add cycle detection (trial deletion / epoch-based reclamation / weak refs). Tracing naturally reclaims cycles.
4 Concurrency: GC across threads adds complexity (synchronization, stop-the-world vs concurrent). Start single-threaded for learning.
5 Object model: require GC-managed objects inherit from a base type or provide metadata so the collector can find pointers inside objects



Why leaks still happen:

1. Reference cycles: Objects A and B hold shared pointers to each other; counts never drop to zero, so neither is destroyed.


2. Hidden ownership in custom deleters or globals: A custom deleter or global container may keep resources alive even after the shared count goes to zero.


3. Mixing ownership models incorrectly: Creating raw pointers, then wrapping them in multiple control blocks (two separate shared pointers managing the same raw pointer) can double-free or leak if misused.


4. Long-lived control blocks: Weak pointers keep the control block alive until all weak refs are gone; the control block holds some memory until then.
	-Even in languages with GC, beware of this.
	-Languages with GC makes it so we don't have to take out the trash, we still have to throw it in the trash can(the allocation part, initialization, and life-cycle)
	

5. Allocator or OS-level fragmentation: Memory might not be reclaimed to the OS immediately; tools may show it as “in use” though logically freed.


6. Concurrency and races: Wrong memory-ordering or non-atomic counters (using Rc in multi-threaded context) can cause undefined behavior or leaks.


7. Logic bugs: Forgetting to reset/release cycles of ownership or accidentally storing strong pointers in containers.
