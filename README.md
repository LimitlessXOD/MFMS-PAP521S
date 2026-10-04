# Municipal Financial Management System

## Course Information

**Course:** PAP521S – Programming in Practice  
**Project:** Project A – Municipal Financial Management System  
**Programming Language:** ANSI C (C99)  
**Development Environment:** Visual Studio Code and GCC  
**Repository:** LimitlessXOD/MFMS-PAP521S  
**Project Due Date:** 02 October 2026  
**Group Number:** [5]

## Group Members

| No. | Student Name | Student Number | Responsibility | Files or Work |
|---|---|---|---|---|
| 1 | Dorothy K. Masilingi | 226091449 | Employee Management | `employees.c`, `employees.h` |
| 2 | Andrew M. J. Akwaake | 226125610 | Budget Management | `budget.c`, `budget.h` |
| 3 | Lonancia M. Matjayi | 226035670 | Supplier Management | `suppliers.c`, `suppliers.h` |
| 4 | Karoline N. Nkandi | 225141361 | Asset Management | `assets.c`, `assets.h` |
| 5 | Erastus T. Shalimba | 225057832 | Testing, documentation and Git coordination | Technical report, system testing, GitHub coordination |
| 6 | Edwin H. Antonio | 226018652 | Functions, integration and validation | `main.c` |
| 7 | Haukongo Wilbard | 225127695 | Reports | `reports.c`, `reports.h` |
| 8 | Aina Kashupi | 224031856 | Documentation | `README.md` |

## Project Description

The Municipal Financial Management System is a C programming project developed for a municipality. The system is designed to manage basic municipal information, including employees, budgets, suppliers and municipal assets.

This project demonstrates the programming concepts covered in PAP521S – Programming in Practice. These concepts include variables, arrays, strings, functions, loops, decision-making and input validation.

The system is menu-driven, which allows the user to select the section they want to use.

## System Features

The system includes the following features:

### Employee Management

- Add employee information
- Display employee records
- Search for an employee
- Calculate employee salary information
- Display employee details

### Budget Management

- Enter departmental budgets
- Enter departmental expenditure
- Calculate the remaining budget
- Check whether expenditure is within budget
- Identify departments that have exceeded their budget

### Supplier Management

- Add supplier information
- Display registered suppliers
- Search for a supplier
- Store supplier contact and location details

### Asset Management

- Add municipal assets
- Display asset information
- Search for an asset
- Store asset name, type, value, department and condition

### Reports

- Display an employee report
- Display a budget report
- Display a supplier report
- Display an asset report
- Show important totals and calculations

### Input Validation

- Check invalid menu choices
- Prevent negative salary values
- Prevent negative budget values
- Check numerical input where possible
- Handle empty or invalid input

## Program Structure

The project is divided into different C files. Each file is responsible for a specific part of the system.

```text
MFMS-PAP521S/
|
|-- main.c
|-- employees.c
|-- employees.h
|-- budget.c
|-- budget.h
|-- suppliers.c
|-- suppliers.h
|-- assets.c
|-- assets.h
|-- reports.c
|-- reports.h
|-- README.md
```

The `main.c` file contains the main menu and connects the different modules. The other C files contain the functions for employee management, budget management, supplier management, asset management and reports.

The header files contain the declarations of the functions used in each module.

## Requirements

The following software and tools are required to compile and run the system:

- Visual Studio Code
- GCC compiler
- C programming support
- A computer with an operating system that supports GCC

## How to Compile the Program

Open the terminal in the project folder and run the following command:

```bash
gcc -Wall -Wextra -std=c99 main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

## How to Run the Program

On Windows, run:

```bash
mfms
```

If the program does not run directly, use:

```bash
.\mfms.exe
```

On Linux or macOS, run:

```bash
./mfms
```

## How the System Works

When the program starts, the main menu is displayed. The user can select an option by entering a number.

```text
1. Employee Management
2. Budget Management
3. Supplier Management
4. Asset Management
5. Reports
6. Exit
```

After selecting an option, the user is taken to the selected module. The user can then add, display, search or calculate information depending on the selected module.

The program continues running until the user selects the exit option.

## C Programming Concepts Used

The following C programming concepts are used in the project:

- Variables
- Different data types
- Arithmetic operators
- Relational operators
- Logical operators
- `if` and `else` statements
- `switch` statements
- `for` and `while` loops
- Arrays
- Strings
- Structures
- Functions
- Function parameters
- Return values
- Input validation
- Searching
- Calculations
- String functions such as `strcmp()` and `strcpy()`

## Individual Responsibilities

### Dorothy K. Masilingi

**Student Number:** 226091449  
**Responsibility:** Employee Management  

Dorothy worked on the employee management module. This included adding, displaying and searching for employee information.

**Files:**

- `employees.c`
- `employees.h`

### Andrew M. J. Akwaake

**Student Number:** 226125610  
**Responsibility:** Budget Management  

Andrew worked on the budget management module. This included entering budgets, entering expenditure, calculating remaining budgets and checking whether departments exceeded their budgets.

**Files:**

- `budget.c`
- `budget.h`

### Lonancia

**Student Number:** 226035670  
**Responsibility:** Supplier Management  

Lonancia worked on the supplier management module. This included adding, displaying and searching for supplier information.

**Files:**

- `suppliers.c`
- `suppliers.h`

### Karoline N. Nkandi

**Student Number:** 225141361  
**Responsibility:** Asset Management  

Karoline worked on the asset management module. This included recording, displaying and searching for municipal assets.

**Files:**

- `assets.c`
- `assets.h`

### Erastus T. Shalimba

**Student Number:** 225057832  
**Responsibility:** Testing, documentation and Git coordination  

Erastus tested the complete system across every module, including deliberately entering invalid input (negative values, blank fields, ID 0) to find gaps that needed fixing. He set up and coordinated the GitHub repository and wrote the technical report.

**Files and work:**

- Technical report
- System testing
- GitHub coordination

### Edwin H. Antonio

**Student Number:** 226018652  
**Responsibility:** Functions, integration and validation  

Edwin worked on connecting the different modules to the main program. He also worked on the main menu, input validation and the integration of the system.

**File:**

- `main.c`

### Haukongo Wilbard

**Student Number:** 225127695  
**Responsibility:** Reports  

Haukongo did the reports module, which pulls data from the employee, budget, supplier and asset modules to produce totals and summaries.

**Files:**

- `reports.c`
- `reports.h`

### Aina Kashupi

**Student Number:** 224031856  
**Responsibility:** Documentation  

Aina is responsible for the README, covering the project description, features, compile instructions and group information.

**File:**

- `README.md`

## GitHub Collaboration

GitHub was used to store the project and manage the contributions of the group members.

The repository is:

```text
LimitlessXOD/MFMS-PAP521S
```

The group used GitHub to:

- Store the source code
- Share files between group members
- Track changes
- Combine the different modules
- Test updated versions of the system
- Keep a record of individual contributions

Each group member was expected to make an identifiable contribution to the project.

## Challenges Encountered

Some of the challenges encountered during the development of the system included:

- Combining the different modules into one program
- Making sure that the header files matched the C files
- Handling invalid user input
- Searching for records correctly
- Making sure that calculations were correct
- Testing all the menu options
- Solving compilation errors
- Coordinating the work through GitHub

## Solutions Implemented

The group solved these challenges by:

- Dividing the system into separate modules
- Using header files for function declarations
- Testing each module separately
- Using functions to organise the program
- Using loops to repeat menus
- Using conditions to validate user input
- Compiling the complete program regularly
- Using GitHub to share and manage the project files
- Testing the system using different types of input

## Conclusion

The Municipal Financial Management System is a foundation system for managing basic municipal financial information.

The project helped the group practise the C programming concepts covered in PAP521S. These concepts include functions, arrays, strings, loops, decision-making, input validation and modular programming.

The project also gave the group experience in working as a team and using GitHub for version control.