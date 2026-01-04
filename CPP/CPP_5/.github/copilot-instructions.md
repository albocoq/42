## Quick orientation for AI coding agents

This is a small C++ exercises repository (ex00, ex01, ex02). Each exercise lives in its own folder and is mostly self-contained. Use these notes to be productive immediately.

- Project layout

  - `ex00/`, `ex01/`, `ex02/` — each exercise contains `*.cpp`, `*.hpp`, a `main.cpp` and a `Makefile`.
  - Key source examples: `Bureaucrat.cpp/.hpp`, `Form.cpp/.hpp`, `AForm.cpp/.hpp`, and specific forms under `ex02/` (e.g. `ShrubberyCreationForm.cpp`, `RobotomyRequestForm.cpp`, `PresidentialPardonForm.cpp`).

- Build and run (concrete)

  - Each exercise uses a local `Makefile`. Typical workflow:
    - cd into exercise folder, run `make` to build the binary (target named `ex00`, `ex01`, `ex02`).
    - run the produced binary: `./ex01` (for example).
  - Standard Makefile targets present: `all`, `clean`, `fclean`, `re`.
  - Compiler and flags (from Makefiles): `CC = c++`, `CFLAGS = -Wall -Werror -Wextra -std=c++98`. Respect C++98 standard.

- How sources are organized (pattern to follow)

  - SRCS lists the `.cpp` files; add new sources by updating the `SRCS` variable in the exercise's `Makefile`.
  - Makefile uses a rule: `%.o: %.cpp %.hpp` — many `.cpp` files expect a same-named `.hpp`. When adding a `.cpp` that has no same-named header, update the pattern or add the header to avoid missing dependency assumptions.

- Coding conventions and patterns to preserve

  - C++ standard: code targets C++98. Avoid modern C++ features (no C++11+ constructs unless you update the Makefile flags and confirm tests).
  - Error handling via exceptions: examples use try/catch in `main.cpp` (see `ex01/main.cpp`), so prefer throwing and catching std::exception-derived types where appropriate.
  - One-class-per-file naming convention: `ClassName.cpp` / `ClassName.hpp`.

- Tests and CI

  - There are no automated unit tests or CI config detected in this repo. Tests are manual and exercised through `main.cpp` programs.

- Integration and external deps

  - No external libraries or networked services detected — everything is implemented locally.

- Small actionable rules for code edits

  - When adding a new exercise or source file: copy the Makefile pattern from an existing exercise, add the source file name to `SRCS`, and keep the `CFLAGS` unless you intentionally change the standard.
  - Keep binary naming consistent: `NAME = exNN` for each folder.
  - Preserve the `-Werror` flag while developing to keep warnings visible and treated as errors.

- Files to inspect for context (examples)
  - `ex01/Makefile` — shows `SRCS = main.cpp Bureaucrat.cpp Form.cpp` and the `CFLAGS` to use.
  - `ex01/main.cpp` — demonstrates exception-based tests and how Bureaucrat/Form interactions are exercised.
  - `ex02/Makefile` and form headers in `ex02/` — shows how multiple related classes (AForm + implementations) are organized.

If anything here is unclear or you want this adapted (more detail, coding style rules, or CI/test additions), tell me which area to expand and I'll iterate.
