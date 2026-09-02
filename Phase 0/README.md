# Phase 0 — C++ Language Foundations

This folder marks the completion of **Phase 0** of my C++ + DSA placement prep roadmap — going from zero C++ knowledge to a solid working foundation across 10 core topics. Every concept below was learned by writing, compiling, and running real code (not just reading theory), so I could see actual outputs, actual compiler errors, and actual crashes where relevant.

This README is a plain-language summary of what each topic covers and why it matters. Full commented code examples for each topic live in this folder.

---

## 1. Basic Syntax — Variables, Data Types, I/O

The skeleton every C++ program follows (`#include`, `using namespace std`, `int main()`), the core data types (`int`, `float`, `double`, `char`, `bool`, `string`), and how to take input safely.

**Key things I learned:**
- `bool` prints as `0`/`1` by default, not the words true/false.
- `double` is generally safer to use than `float` — more precision, negligible cost difference.
- `cin >>` only reads a single word (stops at whitespace); `getline()` reads a full line — and mixing the two without `cin.ignore()` causes a classic bug where `getline()` silently reads nothing.
- Integer division truncates: `17 / 5` gives `3`, not `3.4`. You have to cast to `double` to get a real decimal answer.

---

## 2. Conditionals — if/else, switch

How to make decisions in code, and the two traps that catch most beginners:

- **Order matters in `if`/`else if` chains.** Conditions are checked top to bottom, and only the *first* true one runs — even if a later condition would also be true. Writing range checks in the wrong order silently produces wrong results.
- **`switch` falls through** if you forget a `break` — execution keeps running into the next case instead of stopping.

Also covered: nested conditions, combining conditions with `&&`/`||`, and the ternary operator (`condition ? valA : valB`) as shorthand for simple if/else.

---

## 3. Loops — for, while, do-while

- **`for`** — best when you know the range in advance.
- **`while`** — best when looping depends on a condition that changes unpredictably (e.g., stripping digits off a number until it reaches 0).
- **`do-while`** — like `while`, but always runs the body at least once before checking the condition.
- **`break`** exits a loop completely; **`continue`** skips just the current iteration and moves to the next.
- **Nested loops** — the outer loop controls the row, inner loop(s) control what happens within that row. Used this to build pattern/pyramid printing.

A recurring pattern worth remembering: `num % 10` gets the last digit of a number, `num / 10` removes it — shows up constantly in digit-manipulation problems.

---

## 4. Functions

How to break code into reusable pieces, including:

- Basic structure, `void` vs. value-returning functions
- Default arguments (`double calculatePrice(double base, double tax = 18.0)`)
- Function overloading — same function name, different parameter lists, resolved automatically by the compiler based on what arguments are passed

**The most important idea in this topic — pass by value vs. pass by reference:**
- `func(int x)` — the function receives a **copy**. Changes inside the function never affect the original variable.
- `func(int &x)` — `x` becomes **another name** for the caller's actual variable. Changes inside the function are permanent and visible outside.

This is why a `swap()` function is literally impossible to write correctly without references — without `&`, you'd only ever be swapping private copies.

---

## 5. Arrays & Strings

- Arrays are **0-indexed**, and C++ does **not** protect you from reading out of bounds — accessing `arr[5]` on a 5-element array doesn't throw an error, it silently returns garbage memory. This makes loop-bound discipline (`i < size`, never `i <= size`) genuinely important, not just a style preference.
- **2D arrays** need nested loops to traverse — outer loop for rows, inner loop for columns.
- **`std::string`** is what's actually used in practice (not old C-style char arrays): `.length()`, `[]` indexing, `.substr(start, length)`, concatenation with `+`, and the fact that strings are mutable in C++.
- Biggest trap: `substr(start, length)` takes a **length**, not an end-index — easy to get wrong if you're used to slicing syntax from another language.

---

## 6. Pointers & References

Widely known as the hardest C++ topic for beginners, so I spent extra time here.

- **`&variable`** means "give me this variable's address."
- **`*`** has two different meanings depending on context: in a declaration (`int* p`) it means "this is a pointer"; everywhere else (`*p`) it means "dereference — go to that address and get the value there."
- A dereference **always** gives back a value, never an address — even when two different pointer variables hold the same address (like `p` and `q` both pointing at the same `x`), dereferencing either one reaches the exact same underlying data.
- **Pointers vs. references:** a reference is a permanent alias for a variable (can't be reassigned, can't be null); a pointer stores an address and can be reassigned or set to `nullptr`.
- Dereferencing a `nullptr` causes a real crash (**segmentation fault**) — I triggered this on purpose to see it happen, not just take it on faith.
- Arrays and pointers are deeply connected: an array name decays into a pointer to its first element, and `arr[i]` is literally shorthand for `*(arr + i)`.

---

## 7. Memory Management — Stack vs. Heap

- **Stack** memory (regular local variables) is automatic — it's created and destroyed for you as functions are entered/exited.
- **Heap** memory (`new`/`delete`) is manual — it survives beyond the function that created it, but *you* are responsible for freeing it.
- Returning a pointer to a stack (local) variable creates a **dangling pointer** — the compiler actually warns about this, and I confirmed it crashes at runtime.
- **`new`** allocates on the heap; **`delete`** frees it. Arrays need `delete[]`, not `delete`.
- **Memory leaks**, explained precisely: it's not that the pointer "still holds the value" — it's the opposite. The pointer (on the stack) gets destroyed or reassigned, but the data it pointed to (on the heap) doesn't disappear on its own — it just becomes permanently unreachable, since nothing remembers its address anymore. I tested this directly by reassigning a pointer without freeing what it originally pointed to, and confirmed exactly one allocation leaked.
- In real DSA work, `vector` (Topic 10) replaces almost all manual `new`/`delete` array usage — but understanding this manual version first is what makes `vector` actually make sense.

---

## 8. OOP — Classes, Objects, Constructors, Encapsulation

- A **class** is a blueprint; a **object** is an actual instance created from it, with its own independent copy of the data.
- **Constructors** run automatically when an object is created — same name as the class, no return type. Multiple constructors (default vs. parameterized) are resolved the same way as function overloading, based on the arguments passed.
- **Destructors** (`~ClassName()`) run automatically when an object is destroyed — for a stack object, that's the moment it goes out of scope. Useful for cleanup.
- **Encapsulation**: making member variables `private` and only exposing controlled `public` functions (like `deposit()`/`withdraw()` on a bank account) to interact with them. I confirmed directly that trying to access a `private` member from outside the class fails to compile — the compiler enforces this, it's not just a convention.

---

## 9. Inheritance, Polymorphism, Abstraction

- **Inheritance** (`class Student : public Person`) lets a derived class reuse everything public in a base class and add its own extra members — no duplication.
- **Constructor chaining**: when a derived class object is created, the base class's constructor always runs first, then the derived class's own constructor body.
- **Polymorphism**: without the `virtual` keyword, calling a function through a base-class pointer uses the base class's version — even if the pointer is actually pointing at a derived object. I demonstrated this directly (it silently prints the wrong output, no error or warning). Adding `virtual` to the base class function fixes it — now the correct derived-class version runs, decided at runtime based on the object's real type. This is the core mechanism behind polymorphism.
- **Abstraction**: a pure virtual function (`virtual void func() = 0;`, no body) makes a class *abstract* — you literally cannot create an object of it directly (confirmed via a real compiler error), and every derived class is forced to provide its own implementation.

---

## 10. STL Basics — vector, pair, string methods, set, map, sort

- **`vector`** is the array I'll actually use going forward — it resizes automatically (unlike fixed-size arrays) and manages its own memory (no `new`/`delete`, no leak risk). Covered `push_back`, `pop_back`, `size()`, range-based `for` loops, and 2D vectors for grid/matrix problems.
- **`pair`** bundles two values together (`.first` / `.second`) — very common for coordinates, (value, index) pairs, or (key, count) pairs.
- More **string** methods: `.find()` (returns `string::npos` if not found — never compare to `-1`), converting between chars and their ASCII values, `to_string()` / `stoi()` for number-string conversion.
- Quick introduction to **`set`** (unique, auto-sorted values) and **`map`** (key-value pairs, auto-sorted by key), plus **`sort()`** for sorting a vector in ascending or descending order.

---

## What's next

**Phase 1 — DSA Foundations**: time & space complexity (Big-O), arrays (traversal, searching, two-pointer, sliding window), searching algorithms, sorting algorithms, recursion, and hashing.

---

*All code in this phase was written and verified by actually compiling and running it — every output shown in my notes is real, not assumed.*
