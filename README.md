<h1 align="center">Anaconda</h1>

My attempt at implementing a simple language using LLVM components in C++

### Features:
- Python-like syntax
- Protoype declarations
- Functions
- Conditionals
- Loops
- Comments
- Error handling (soon)

## Usage

```bash
make
cd src/
# Start interpreter
./anaconda
```

## Demo - Fibonacci Sequence

```bash
$ ./anaconda
ready> 
 def fib(n)
  if n < 3 then
    1
  else
    fib(n-1) + fib(n-2);

Read function definition:define double @fib(double %n) {
entry:
  %cmptmp = fcmp ult double %n, 3.000000e+00
  br i1 %cmptmp, label %ifcont, label %else

else:                                             ; preds = %entry
  %subtmp = fadd double %n, -1.000000e+00
  %calltmp = call double @fib(double %subtmp)
  %subtmp1 = fadd double %n, -2.000000e+00
  %calltmp2 = call double @fib(double %subtmp1)
  %addtmp = fadd double %calltmp, %calltmp2
  br label %ifcont

ifcont:                                           ; preds = %entry, %else
  %iftmp = phi double [ %addtmp, %else ], [ 1.000000e+00, %entry ]
  ret double %iftmp
}

ready> fib(15);
ready> Evaluated to 610.000000
```
