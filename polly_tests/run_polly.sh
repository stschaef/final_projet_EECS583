#!/bin/bash

/n/eecs583b/home/stschaef/llvm_polly/bin/opt \
 -basic-aa \
 -polly-ast \
 -analyze \
 example.preopt.ll \
 -polly-process-unprofitable \
 -polly-use-llvm-names \