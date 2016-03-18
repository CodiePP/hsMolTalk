# hsMolTalk
Haskell binding to the [MolTalk](https://github.com/CodiePP/libmoltalk) library for structural bioinformatics analyses


## compilation

> make

> stack build


## running

> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`

start the executable on a structure file (in PDB format) and indicating a chain code:
> stack exec hsMolTalk 0abc.pdb A


