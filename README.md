# EECS 583 Final Project : Group 9

## Team Members
- Alireza Khadem - <arkhadem@umich.edu>,
- Ashutosh Mishra - <ashumich@umich.edu>,
- Steven Schaefer - <stschaef@umich.edu>
- Sumanth Umesh - <sumanthu@umich.edu>

## Project Description
We are taking direction from [To Pim or Not...](https://dl.acm.org/doi/pdf/10.1145/3470496.3527431?casa_token=g1c5I_7wzwsAAAAA:cM569Vz-nDbRf4g0Rom6hO3kgq5RyRgKvw7NjUPO1ymD3QR8ZTgla0uV_Lyqs1MYDD4mcbCwv2fAkCs) by Devic et al.

TODO : Add more details

## Polly Usage
We first need to use Polly to detect the parallelism in the code. The commands to do this are in combined in `Makefile` and `run_polly.sh`. 

First we need to emit LLVM IR from the C code, then this IR needs to be put into Polly canonical form. Once in the appropriate format, Polly ***should*** then be able to output some useful info about the code including dependencies, parallelism, etc. However, I have only been able to get empty output so far.