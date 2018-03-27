# corewar
Core War is a 1984 programming game in which two or more battle programs (called "warriors") compete for control of a virtual computer. 

What is CoreWar? <br/>
• Corewar is a very peculiar game. It’s about bringing “players” together around a
“virtual machine”, which will load some “champions” who will fight against one another
with the support of “processes”, with the objective being for these champions
to stay “alive”.<br/>
• The processes are executed sequentially within the same virtual machine and memory
space. They can therefore, among other things, write and rewrite on top of
each others so to corrupt one another, force the others to execute instructions that
can damage them, try to rewrite on the go the coding equivalent of a Côtes du
Rhône 1982 (that is one delicious French wine!), etc... <br/>
• The game ends when all the processes are dead. The winner is the last player
reported to be “alive”. <br/>

Assembler: this is the program that compiles champions and translate
them from the assembly language into Bytecode. <br/>
