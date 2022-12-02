CC = /n/eecs583b/home/stschaef/llvm_polly/bin/clang
INC = -I/n/eecs583b/home/stschaef/llvm_polly/include
CFLAGS = -Xclang -disable-O0-optnone 

OPT=/n/eecs583b/home/stschaef/llvm_polly/bin/opt

all: example.s example.preopt.ll

%.s: %.c
	$(CC) -S -emit-llvm $(INC) $(CFLAGS) $< -o $@

%.preopt.ll: %.s
	$(OPT) -S -polly-canonicalize $< -o $@

clean:
	rm -f *.preopt.ll *.s *.ll