#!/bin/bash

/n/eecs583b/home/stschaef/llvm_polly/bin/opt \
 -polly-process-unprofitable \
 -polly-dependences \
 -polly-detect \
 -polly-scops \
 -analyze \
 example.preopt.ll \