# 002_printf
## Recode of system printf. Works with cspdiuxX% convesions, field size and precision. 
_Thanks to HecateCerridwen, cvignar and MaudClam for understanding, ideas and debugging of project._

>_The goal of this project is pretty straightforward. You will recode printf().
You will mainly learn about using a variable number of arguments._

![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/sapogov1978/002_printf?style=for-the-badge)
![Lines of code](https://img.shields.io/tokei/lines/github/sapogov1978/002_printf?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/sapogov1978/002_printf?style=for-the-badge)
![GitHub top language](https://img.shields.io/github/languages/top/sapogov1978/002_printf?style=for-the-badge)

## Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/ft_printf && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "printf.h"
```

and, when compiling your code, add the required flags:

```shell
-lftprintf -L path/to/libftprintf.a -I path/to/printf.h
```

