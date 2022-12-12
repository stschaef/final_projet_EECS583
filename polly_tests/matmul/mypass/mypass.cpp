#include "llvm/Analysis/LoopPass.h"
#include "llvm/Pass.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
// #include "polly/ScopInfo.h"
// #include "polly/isl/ast.h"
#include "polly/ScopPass.h"
#include "polly/ScopInfo.h"
#include "polly/Support/GICHelper.h"

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
        for (auto & Inst : *BB) {

          auto stmt = S.getStmtFor(&Inst);

          errs() << "Instruction: " << Inst << "\n";

          if (!stmt) {
            continue;
          }

          errs() << "Statement Schedule: " << stmt->getScheduleStr() << "\n";
          errs() << "Statement Domain: " << stmt->getDomainStr() << "\n";
          // for (auto access : *stmt)
          // {
          //   errs() << "IsRead: " << access->isRead() << "\n";
          //   errs() << "Element type: " << *(access->getElementType()) << "\n";
          //   errs() << "Value: " << *(access->getAccessValue()) << "\n";
          //   errs() << "Original Base Addr: " << *(access->getOriginalBaseAddr()) << "\n";
          //   errs() << "Array ID: " << (access->getArrayId()).name() << "\n";
          //   errs() << "Is Scalar: " << access->isScalarKind() << "\n";
          //   // TODO: can the appropriate sizes be read directly from this base addr?

          //   // auto stride = access->getStride(stmt->getSchedule());
          //   // errs() << "Stride: " << polly::stringFromIslObj(stride) << "\n";

          //   errs() << '\n';

          // }
          errs() << "\n";

          // TODO: for each vectorized loop iterable, look up at which index this iterable occurs in a memory access

        
      }
        }

      // errs() << S << "\n";

      return false;
    }
  };
} // namespace
char GetStride::ID = 0;
static RegisterPass<GetStride> X("getstride", "GetStride pass", false /* Only looks at CFG */,
                                 false /* Analysis Pass */);
