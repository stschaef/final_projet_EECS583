#include "llvm/Analysis/LoopPass.h"
#include "llvm/Pass.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
// #include "polly/ScopInfo.h"
// #include "polly/isl/ast.h"
#include "polly/ScopPass.h"

using namespace llvm;
namespace
{
  struct GetStride : public polly::ScopPass
  {
    static char ID;

    GetStride() : polly::ScopPass(ID) {}

    bool runOnScop(Scop &S) override
    {
      // auto schedule = S.getSchedule();
      // auto m = schedule.extract_map(schedule.get_space());

      errs() << S << "\n";

      return false;
    }
  };
} // namespace
char GetStride::ID = 0;
static RegisterPass<GetStride> X("getstride", "GetStride pass", false /* Only looks at CFG */,
                                 false /* Analysis Pass */);
