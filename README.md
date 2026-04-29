# math-lib-calculator
A reusable math engine paired with a graphical calculator interface, demonstrating separation of core logic and UI.

## Table of contents
- [Introduction](#introduction)
- [Functionality](#functionality)
- [Environment](#environment)
- [Installation](#installation)
- [Usage](#usage)
- [Authors](#authors)
- [License](#license)

## Introduction
This project is a **graphical calculator application** that provides a user-friendly interface for performing a variety of mathematical operations.

It is built with a **modular design**, separating the core mathematical library from the graphical interface, and can be operated via both **keyboard** and **GUI controls**.

Designed for **educational and general-purpose use**, the calculator includes an integrated help system to assist users in navigating its features.

## Functionality
This calculator provides a fully functional GUI-based and engine-driven mathematical expression evaluator built on top of a custom math-lib.

It supports the following operations:
- Basic arithmetic: +, -, *, /
- Grouping: parentheses ( )
- Modulo: %
- Factorial: !
- Exponentiation: ^
- Square root: √
- Decimal numbers: full floating-point support

#### Expression rules
Expressions are parsed and evaluated using a custom math engine powered by math-lib.
Standard operator precedence is respected (PEMDAS/BODMAS rules).
Nested expressions with parentheses are fully supported.
Negative numbers

#### Negative numbers:
Must be explicitly written using parentheses

``(-5)
(-3.14)
( -2 )``

This design choice ensures unambiguous parsing between subtraction and unary negation.

Example:

``(3) + (-5) * 2``

instead of:

``3 + -5 * 2``   ❌ not supported

## Environment
**Operating systems:**
- Ubuntu 24.04+ 64-bit

**Graphical Interfaces:**
- Qt 6.10+

#### Building from source (for developers)
Requirements:
|Program|Toolchain|Version|
|---|---|---|
|make|GNU|>4.4|
|cmake||>3.16|
|g++ compiler|GCC|>15.2|
|doxygen||>1.16|

Please note that specified versions are tested and older versions may not work properly.

## Installation
This project can be installed either using the provided installer/uninstaller or by building it from the source repository.

#### Option 1: Installer / Uninstaller (Recommended)

The project comes with an included installer and uninstaller for easy setup.

- Run the installer to automatically configure and install the calculator.

#### Option 2: Build from Source (Git) 
sudo apt install/uninstall ivs-calculator_1.0_amd64.deb

You can also clone and build the project manually from the repository:

```git
git clone https://github.com/erikbohac/math-lib-calculator.git
cd math-lib-calculator
```
**Build Instructions**

The project uses a Makefile-based build system located in:

```
math-lib-calculator/src
```

To build the project, run:

```bash
cd src
make
```

This will compile the project and output the final build into:

```bash
math-lib-calculator/src/build
```

**Output Structure**
After a successful build, the compiled application will be available in:

```bash
src/build/
```
The build system is based on make and cmake.
Ensure all required toolchain dependencies are installed before building.
If you are using the installer version, manual building is not required.

## Usage
#### GUI Mode
The GUI provides an interactive interface for entering and evaluating expressions.

1. Launch the application.
2. Enter your expression using the on-screen buttons or keyboard input.
3. Press = or *Enter* key to evaluate the result.
The result is displayed instantly in the output field.

Example input:

``(12 + 3) * 2``

Result:

``30``

#### Engine (Programmatic) Mode
The calculator engine can be used directly through code by passing expressions as strings to the evaluation function exposed by calculator engine.

## Authors
Team `segfault` members:
- Erik Boháč (xbohace00)
- Dominik Dusbaba (xdusbad00)
- Patrik Kadlec (xkadlep00)

## License
This project is open-source and distributed under the [GNU GPL v3](LICENSE) license.
# math-lib-calculator
A reusable math engine paired with a graphical calculator interface, demonstrating separation of core logic and UI.

## Table of contents
- [Introduction](#introduction)
- [Functionality](#functionality)
- [Environment](#environment)
- [Installation](#installation)
- [Usage](#usage)
- [Authors](#authors)
- [License](#license)

## Introduction
This project is a **graphical calculator application** that provides a user-friendly interface for performing a variety of mathematical operations.

It is built with a **modular design**, separating the core mathematical library from the graphical interface, and can be operated via both **keyboard** and **GUI controls**.

Designed for **educational and general-purpose use**, the calculator includes an integrated help system to assist users in navigating its features.

## Functionality
*TODO*

## Environment
**Operating systems:**
- Ubuntu 24.04+ 64-bit

**Graphical Interfaces:**
- Qt 6.10+

### Building from source (for developers)
Requirements:
- make
- cmake
- g++ compiler
- doxygen (for documentation)

## Installation
*TODO*

## Usage
*TODO*

## Authors
Team `segfault` members:
- Erik Boháč (xbohace00)
- Dominik Dusbaba (xdusbad00)
- Patrik Kadlec (xkadlep00)

## License
This project is open-source and distributed under the [GNU GPL v3](LICENSE) license.
