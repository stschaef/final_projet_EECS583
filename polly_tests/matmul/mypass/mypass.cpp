#include "llvm/Analysis/LoopPass.h"
#include "llvm/Pass.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
// #include "polly/ScopInfo.h"
// #include "polly/isl/ast.h"
#include "polly/ScopPass.h"
#include "polly/ScopInfo.h"

using namespace llvm;
namespace
{
  struct GetStride : public polly::ScopPass
  {
    static char ID;

    GetStride() : polly::ScopPass(ID) {}

    bool runOnScop(Scop &S) override
    {
      for (auto BB : S.blocks())
      {
        for (auto stmt : S.getStmtListFor(BB))
        {
          for (auto access : *stmt)
          {
            // errs() << "Array : " << access->getArrayId() << "\n";
            errs() << "IsRead: " << access->isRead() << "\n";
            errs() << "Element type: " << *(access->getElementType()) << "\n";
            errs() << "Value: " << *(access->getAccessValue()) << "\n";
            errs() << "Original Base Addr: " << *(access->getOriginalBaseAddr()) << "\n";
            // TODO: can the appropriate sizes be read directly from this base addr?
          }
        }
      }

      return false;
    }
  };
} // namespace
char GetStride::ID = 0;
static RegisterPass<GetStride> X("getstride", "GetStride pass", false /* Only looks at CFG */,
                                 false /* Analysis Pass */);
