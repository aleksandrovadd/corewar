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

<strong>In this project:</strong> <br/>
The Assembler: this is the program that compiles champions and translate
them from the assembly language into Bytecode. <br/>

The virtual machine (VM): It’s the “arena” in which your champions will be executed. <br/>

The champion: for this project only needs to scare the bejesus out of a neurasthenic hedgehog. <br/>

Maximum is 4 players. <br/>

Also with the help of ncurses library was made the visualization mode where all the processes that are in the VM are shown like on the "battle field". All players have their own colors so it can be seen what they are doing and on the information pannel you can see the main information about the processes, cycles, amount of lives each champion/player "said" to have in the current period. There is an opportunity to slow or fasten the cycles running. To run the visualization use --visual.

