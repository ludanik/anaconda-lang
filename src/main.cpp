#include "driver.h"
#include "library.h"

int main() {
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  InitializeNativeTargetAsmParser();

  BinopPrecedence['<'] = 10;
  BinopPrecedence['+'] = 20;
  BinopPrecedence['-'] = 20;
  BinopPrecedence['*'] = 40; 

  fprintf(stderr, "ready> ");
  getNextToken();

  TheJIT = ExitOnErr(AnacondaJIT::Create());

  InitializeModuleAndManagers();

  MainLoop();

  return 0;
}
