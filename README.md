# 42 C++ Modules — Object-Oriented Programming & Systems Engineering

Welcome to the **42 C++ Modules** repository. This project repository demonstrates a comprehensive journey from C fundamentals to advanced C++ Object-Oriented Programming (OOP), memory management, template metaprogramming, and Standard Template Library (STL) design.

All modules are strictly compliant with the **C++98 standard** and compiled with strict flags (`-Wall -Wextra -Werror -std=c++98`).

---

## Executive Summary

This repository showcases hands-on experience in writing modern, robust, and leak-free C++ code under strict constraints. Key technical competencies developed across these projects include:

* **Object-Oriented Architecture & Design Patterns**: Encapsulation, Single/Multiple/Virtual Inheritance, Interface Segregation, Abstract Base Classes (ABCs), Polymorphism, and Factory Patterns.
* **Orthodox Canonical Form & RAII**: Strict memory ownership rules, preventing resource leaks by encapsulating resources inside constructors and destructors, and enforcing deep copies for dynamic allocations.
* **Low-Level Memory & Pointer Mechanics**: Distinction between stack vs. heap allocation, references vs. pointers, dynamic arrays, pointer-to-member dispatch tables, and bitwise/fixed-point arithmetic.
* **Explicit Typecasting & RTTI**: Mastering safe C++ cast operators (`static_cast`, `dynamic_cast`, `reinterpret_cast`) and dynamic type deduction without relying on standard RTTI (`typeid`).
* **Exception Safety & Robustness**: Designing robust error-handling pipelines using standard and custom `std::exception` classes.
* **Generic Programming**: Building reusable template functions and generic container classes.
* **Standard Template Library (STL)**: Effective use of STL containers, iterators, and generic algorithms.

---

## Technical Skills & Concepts Breakdown

### 🧠 1. Memory Management & RAII
* Deep vs. Shallow copying: Avoiding dangling pointers and double-free bugs by explicitly writing copy constructors and assignment operators.
* Dynamic object creation (`new`/`delete`, `new[]`/`delete[]`).
* Memory leak prevention verified with **Valgrind** across all test suites.

### 🏗️ 2. Object-Oriented Programming (OOP)
* **Encapsulation**: Enforcing strict accessor/mutator patterns and private data members.
* **Polymorphism & Dynamic Dispatch**: Utilizing `virtual` member functions and `virtual` destructors to ensure clean object destruction in polymorphic class hierarchies.
* **Inheritance & The Diamond Problem**: Multi-level inheritance and solving ambiguous base class duplication using `virtual` inheritance (`virtual public Base`).
* **Interfaces & Abstract Base Classes**: Designing pure abstract interfaces (`pure virtual functions = 0`) to decouple interfaces from concrete implementations.

### ⚙️ 3. Advanced Language Features
* **Fixed-Point Arithmetic**: Building a fixed-point number representation class from scratch, handling raw bits, integer/float conversions, and precision manipulation.
* **Operator Overloading**: Overloading arithmetic (`+`, `-`, `*`, `/`), relational (`>`, `<`, `==`, `!=`), increment/decrement (`++`, `--`), and stream I/O (`<<`, `>>`) operators.
* **Function Pointers & Dispatch Tables**: Replacing complex conditionals with tables of pointers to member functions.
* **Explicit Casting**:
  * `static_cast`: Safe standard type conversions.
  * `reinterpret_cast`: Bit-level reinterpretation and memory pointer serialization (`uintptr_t`).
  * `dynamic_cast`: Safe downcasting across polymorphic class hierarchies using reference and pointer semantics.

### 🛠️ 4. Generic Metaprogramming & STL
* Function templates for generic operations.
* Class templates parameterized over arbitrary data types with custom array index checking.
* STL container utilization (`std::vector`) and standard algorithms (`std::find`, `std::sort`, `std::min_element`, `std::max_element`).

---

## Module Index

| Module | Core Focus | Key Concepts & Exercises Implemented |
| :--- | :--- | :--- |
| **[Module 00](file:///home/fishie/Desktop/42/42_cpp/00)** | Namespaces & Basics | `std::iostream`, `std::string`, member functions, static members, execution logging (`megaphone`, `PhoneBook` CLI, `Account` ledger log). |
| **[Module 01](file:///home/fishie/Desktop/42/42_cpp/01)** | Memory & Pointers | Stack vs Heap allocation, references vs pointers, file streams (`std::ifstream`/`ofstream`), string replacing (`sed`), member function pointer dispatch tables (`Harl`). |
| **[Module 02](file:///home/fishie/Desktop/42/42_cpp/02)** | Operator Overloading | Orthodox Canonical Class Form, fixed-point arithmetic class (`Fixed`), comprehensive operator overloading (`+`, `-`, `*`, `/`, `>`, `<`, `==`, `++`, `--`). |
| **[Module 03](file:///home/fishie/Desktop/42/42_cpp/03)** | Inheritance | Single inheritance (`ClapTrap` ➡️ `ScavTrap` / `FragTrap`), constructor/destructor execution order, multiple & virtual inheritance (`DiamondTrap`). |
| **[Module 04](file:///home/fishie/Desktop/42/42_cpp/04)** | Polymorphism & Interfaces | Virtual destructors, shallow vs deep copy handling with internal heap objects (`Brain`), Pure virtual abstract classes, RPG Materia & Inventory interface design (`AMateria`, `ICharacter`, `IMateriaSource`). |
| **[Module 05](file:///home/fishie/Desktop/42/42_cpp/05)** | Exceptions & Factories | Custom exception classes inheriting from `std::exception`, exception-safe forms (`Bureaucrat`, `AForm`), dynamic object instantiator using the Factory Pattern (`Intern`). |
| **[Module 06](file:///home/fishie/Desktop/42/42_cpp/06)** | C++ Casts & RTTI | Scalar converter engine (`ScalarConverter`), pointer serialization (`Serializer` / `uintptr_t`), runtime type identification without `typeid` using `dynamic_cast` (`Base`/`A`/`B`/`C`). |
| **[Module 07](file:///home/fishie/Desktop/42/42_cpp/07)** | C++ Templates | Function templates (`swap`, `min`, `max`, `iter`), custom dynamic template array container (`Array<T>`) with bounds-checked subscripting. |
| **[Module 08](file:///home/fishie/Desktop/42/42_cpp/08)** | STL Containers & Algorithms | STL algorithms wrapper (`easyfind`), dataset range filler & span calculator (`Span` using `std::vector` and algorithm iterators). |

---

## Build & Execution Instructions

Each exercise contains its own `Makefile` configured with strict 42 compilation standards.

### Compilation Flags
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

### Running an Exercise
To compile and run any exercise, navigate into its folder and run `make`. For example, for Module 04/ex03:

```bash
cd 04/ex03
make
./materia
```

### Clean Up
```bash
make clean    # Remove object files
make fclean   # Remove object files and binary executable
make re       # Recompile from scratch
```

### Memory Leak Check
All programs are designed to exit with 0 leaks:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./<executable>
```

---

## Author
* **42 Student**: `yelu` (42 KL)
