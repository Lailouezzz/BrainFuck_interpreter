# BrainFuck_interpreter
Small brainfuck interpreter written in C++


## How to compile and use
- Use compiler that support C++17
- Compile with this following arguments : 
      
      -std=c++17 .\\src\\BFCompiler.cpp .\\src\\BFException.cpp .\\src\\BFInterpreter.cpp .\\src\\BFVerificator.cpp main.cpp -o BFInterpreter
- Excute BF script :

      BFInterpreter [your BF script]
