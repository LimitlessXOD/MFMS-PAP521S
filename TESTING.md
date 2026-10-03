# Manual Testing Checklist

## Compile Command

```bash
gcc -std=c99 -Wall -Wextra main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

## Menu Input Validation

- [ ] Enter letters at main menu (example: `abc`) and confirm program asks again.
- [ ] Enter out-of-range main menu value (example: `9`) and confirm program asks again.
- [ ] Repeat same checks inside Employee, Budget, Supplier, and Asset submenus.

## Employee Module

- [ ] Add one employee with valid values.
- [ ] Try adding employee with negative salary component and confirm rejection.
- [ ] Display employees and confirm captured record appears.
- [ ] Search existing employee ID and confirm full details shown.
- [ ] Search missing employee ID and confirm not-found message.

## Budget Module

- [ ] Add one budget with valid allocated/spent values.
- [ ] Try adding budget with negative allocated or spent value and confirm rejection.
- [ ] Display budgets and confirm status is shown.
- [ ] Update spending with valid extra amount.
- [ ] Try update with negative extra spending and confirm rejection.

## Supplier Module

- [ ] Add one supplier with valid email.
- [ ] Try invalid email without `@` and confirm re-prompt.
- [ ] Display suppliers and confirm supplier is listed.
- [ ] Search supplier by name and confirm details.
- [ ] Run compare/search submenu options for town search and string length display.

## Asset Module

- [ ] Add one asset with valid values.
- [ ] Try negative purchase value and confirm rejection.
- [ ] Display assets and confirm captured record appears.
- [ ] Search existing and missing asset IDs.

## Reports Module

- [ ] Generate reports after adding test data in all modules.
- [ ] Confirm employee report shows total employees, average gross salary, highest and lowest gross salary.
- [ ] Confirm budget report shows total allocated, total spent, remaining balance, and over-budget departments.
- [ ] Confirm supplier report lists all suppliers.
- [ ] Confirm asset report lists all assets.

## Empty-Data Report Checks

- [ ] Start with no records and generate reports.
- [ ] Confirm each report prints a clear empty-data message instead of crashing.
