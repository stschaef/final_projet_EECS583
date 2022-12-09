#include "llvm/Analysis/BlockFrequencyInfo.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/Format.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;
namespace {
struct HW1 : public FunctionPass {
  static char ID;

  HW1() : FunctionPass(ID) {}

  void getAnalysisUsage(AnalysisUsage &AU) const {
    AU.addRequired<BlockFrequencyInfoWrapperPass>();    // Analysis pass to load
                                                        // block execution count
    AU.addRequired<BranchProbabilityInfoWrapperPass>(); // Analysis pass to load
                                                        // branch probability
  }

  virtual bool runOnFunction(Function &F) override {
    /* *******Implementation of Your code ******* */
    BranchProbabilityInfo &bpi =
        getAnalysis<BranchProbabilityInfoWrapperPass>().getBPI();
    BlockFrequencyInfo &bfi =
        getAnalysis<BlockFrequencyInfoWrapperPass>().getBFI();

    int biased_branch_inst_count = 0;
    int unbiased_branch_inst_count = 0;
    int int_alu_inst_count = 0;
    int float_alu_inst_count = 0;
    int mem_inst_count = 0;
    int other_inst_count = 0;
    int total_inst_count = 0;
    for (BasicBlock &BB : F) {
      uint64_t blockCount =
          bfi.getBlockProfileCount(&BB)
              .getValue(); // example for the analysis pass usage.
      for (Instruction &I : BB) {
        total_inst_count += blockCount;
        switch (I.getOpcode()) {
        case Instruction::Br:
        case Instruction::Switch:
        case Instruction::IndirectBr: {
          bool is_biased = false;
          for (BasicBlock *Succ : successors(&I)) {
            if (bpi.getEdgeProbability(&BB, Succ) > BranchProbability(4, 5)) {
              is_biased = true;
            }
          }
          if (is_biased)
            biased_branch_inst_count += blockCount;
          else
            unbiased_branch_inst_count += blockCount;
          break;
        }

        case Instruction::Add:
        case Instruction::Sub:
        case Instruction::Mul:
        case Instruction::UDiv:
        case Instruction::SDiv:
        case Instruction::URem:
        case Instruction::Shl:
        case Instruction::LShr:
        case Instruction::AShr:
        case Instruction::And:
        case Instruction::Or:
        case Instruction::Xor:
        case Instruction::ICmp:
        case Instruction::SRem:
          int_alu_inst_count += blockCount;
          break;
        case Instruction::FAdd:
        case Instruction::FSub:
        case Instruction::FMul:
        case Instruction::FDiv:
        case Instruction::FRem:
        case Instruction::FCmp:
          float_alu_inst_count += blockCount;
          break;
        case Instruction::Alloca:
        case Instruction::Load:
        case Instruction::Store:
        case Instruction::GetElementPtr:
        case Instruction::Fence:
        case Instruction::AtomicCmpXchg:
        case Instruction::AtomicRMW:
          mem_inst_count += blockCount;
          break;
        default:
          other_inst_count += blockCount;
          break;
        }
      }
    }

    if (total_inst_count == 0) {
      errs().write_escaped(F.getName())
          << ", " << 0 << ", " << format("%.3f", float(0)) << " , "
          << format("%.3f", float(0)) << " , " << format("%.3f", float(0))
          << " , " << format("%.3f", float(0)) << " , "
          << format("%.3f", float(0)) << " , " << format("%.3f", float(0))
          << '\n';
      return false;
    }

    errs().write_escaped(F.getName())
        << ", " << total_inst_count << ", "
        << format("%.3f", float(int_alu_inst_count) / float(total_inst_count))
        << " , "
        << format("%.3f", float(float_alu_inst_count) / float(total_inst_count))
        << " , "
        << format("%.3f", float(mem_inst_count) / float(total_inst_count))
        << " , "
        << format("%.3f",
                  float(biased_branch_inst_count) / float(total_inst_count))
        << " , "
        << format("%.3f",
                  float(unbiased_branch_inst_count) / float(total_inst_count))
        << " , "
        << format("%.3f", float(other_inst_count) / float(total_inst_count))
        << '\n';
    return false;
  }
};
} // namespace
char HW1::ID = 0;
static RegisterPass<HW1> X("hw1", "HW1 pass", false /* Only looks at CFG */,
                           false /* Analysis Pass */);
