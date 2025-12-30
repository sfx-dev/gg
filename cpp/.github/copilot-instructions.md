# Copilot Instructions - 42 C++ Modules

## Project Overview
42 school C++ piscine: Progressive modules teaching OOP fundamentals through C++98.
- **CPP-00**: Namespaces, classes, member functions, stdio streams, static, const
- **CPP-01**: Memory allocation (`new`/`delete`), pointers to members, references, switch

## Strict Constraints (Grade = 0 if violated)
| Forbidden | Use Instead |
|-----------|-------------|
| `*printf()`, `*alloc()`, `free()` | `std::cout`, `new`/`delete` |
| `using namespace <ns_name>`, `friend` | Explicit `std::` prefix |
| C++11+, Boost, STL containers/algorithms (until Module 08) | Fixed arrays, manual loops |
| Function implementations in headers (except templates) | `.cpp` files only |

## Compilation & Build
```sh
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o <executable>
```
Makefile targets: `make`, `make clean`, `make fclean`, `make re`

## Code Conventions (from existing codebase)
- **Classes**: `UpperCamelCase` → `PhoneBook`, `Contact`, `Zombie`
- **Files**: Match class name → `ClassName.hpp`, `ClassName.cpp`
- **Private members**: Prefix with `_` → `_firstName`, `_index`, `_contacts[8]`
- **Getters/Setters**: `getFieldName() const` / `setFieldName(type value)`
- **Output**: Always end with `\n` or `std::endl`, always to `stdout`
- **Headers**: Include guards required (`#ifndef CLASSNAME_HPP`)

## Memory Patterns (CPP-01+)
```cpp
// Stack allocation (automatic cleanup, use for local scope)
Zombie stackZombie("LocalZombie");

// Heap allocation (manual cleanup, use when returning from function)
Zombie* heapZombie = new Zombie("HeapZombie");
delete heapZombie;

// Array allocation
Zombie* horde = new Zombie[N];
delete[] horde;  // Always use delete[] for arrays
```

## I/O Patterns
```cpp
#include <iostream>
#include <iomanip>   // std::setw, std::right
#include <string>    // std::string (preferred over char*)

std::getline(std::cin, str);  // Read full line with spaces
std::cin >> value;            // Read single token

// Formatted output (10-char right-aligned, truncate with ".")
std::cout << std::setw(10) << std::right << text;
if (text.length() > 10) text = text.substr(0, 9) + ".";
```

## Orthodox Canonical Form (CPP-02+)
Required for all classes from Module 02 onward:
```cpp
class Sample {
public:
    Sample();                              // Default constructor
    Sample(const Sample& src);             // Copy constructor
    Sample& operator=(const Sample& rhs);  // Copy assignment
    ~Sample();                             // Destructor
};
```

## Module-Specific Notes
- **CPP-00/ex01**: Fixed array `Contact[8]`, circular replacement at index `(_index + 1) % 8`
- **CPP-01/ex00-01**: Demonstrate stack vs heap allocation decisions
- **CPP-01/ex04**: File I/O with `std::ifstream`/`std::ofstream`, no `sed` allowed
