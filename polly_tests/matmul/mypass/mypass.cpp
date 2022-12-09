#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"
#include "polly/PolyhedralInfo.h"

using namespace llvm;
namespace
{
  struct HW1 : public FunctionPass
  {
    static char ID;

    HW1() : FunctionPass(ID) {}

    void getAnalysisUsage(AnalysisUsage &AU) const
    {
      AU.addRequired<BlockFrequencyInfoWrapperPass>();    // Analysis pass to load
                                                          // block execution count
      AU.addRequired<BranchProbabilityInfoWrapperPass>(); // Analysis pass to load
                                                          // branch probability
    }

    virtual bool runOnFunction(Function &F) override
    {
      errs() << "Function: " << F.getName() << '\n';
      return false;
    }
  };
} // namespace
char HW1::ID = 0;
static RegisterPass<HW1> X("hw1", "HW1 pass", false /* Only looks at CFG */,
                           false /* Analysis Pass */);
