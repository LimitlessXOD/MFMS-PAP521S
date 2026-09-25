# Municipal Financial Management System (MFMS)

**Course:** PAP521S – Programming in Practice
**Project:** Project A – Foundation System
**Group Number:** _[fill in]_

## Group Members
| Name | Student Number | Module Responsibility |
|---|---|---|
| _[fill in]_ | _[fill in]_ | Employee Management |
| _[fill in]_ | _[fill in]_ | Budget Management |
| _[fill in]_ | _[fill in]_ | Supplier Management |
| _[fill in]_ | _[fill in]_ | Asset Management |
| _[fill in]_ | _[fill in]_ | Reports |
| _[fill in]_ | _[fill in]_ | Functions, integration and validation |
| _[fill in]_ | _[fill in]_ | Testing, documentation and Git coordination |

## Project Description
MFMS is a menu-driven, console-based municipal financial management system written in
ANSI C (C99). It is the foundation version of a system that will be extended in Project B,
covering employee records, department budgets, suppliers, municipal assets, and reporting.

## System Features
- **Employee Management** — add, display, search, and calculate salary breakdowns
  (basic salary + housing allowance + transport allowance).
- **Budget Management** — set department budgets, record expenditure, and check
  within-budget / exceeded status.
- **Supplier Management** — add, display, and search suppliers by ID, name, or location.
- **Asset Management** — add, display, and search a municipal asset register.
- **Reports** — summary statistics for employees, budgets, suppliers, and assets.
- Input validation throughout (no negative values, no empty names, invalid menu choices handled).

## Project Structure
```
MFMS/
├── main.c
├── common.h        (shared constants + input helpers)
├── employees.c / employees.h
├── budget.c    / budget.h
├── suppliers.c / suppliers.h
├── assets.c    / assets.h
├── reports.c   / reports.h
├── Makefile
└── README.md
```

## Compilation Instructions
Requires `gcc` and `make`.

```bash
make
```

This produces an executable called `mfms`.

To clean build artifacts:
```bash
make clean
```

## How to Run
```bash
./mfms
```
Follow the on-screen menu to navigate between modules.

## Individual Responsibilities
See the group members table above. Each member's contribution should also be traceable
through individual commits in the GitHub repository's commit history.
