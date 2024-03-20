
void*amain[] = {};
int main() {
}
/*
where to start?
composition? how we compose systems with this protocol? we need to write concrete examples.

this is the only way to write idea down. 
to be efficient in handling tcp connections on linx platform we can use epoll in ET mode.
we should try new abstactions for operating systems. using protocol of the actionable word 
we can start bulding operating system on top of linux os.  in other words we can defer to
implement new abstractions on top of bare metal.
we can use epoll with idea of elevated "goto" to mimick interrupts.

Now lets think about "goto".
To do so we need to define abstactions first or we can start writing statemens using
abstractions and after we have stated everithing then define them.

we need to see how we map structures, produced by protocol, on the apaper.
we need to write atext and asentences for common problems and to see how we
can express them with awords.

below is how we can express fibonaci using structured languages alike math.
f(0) = 1
f(1) = 1
f(n) = f(n-1) + f(n-2)

below fib is written in C language
unsigned int fib(unsigned int n) { return (n<2) ? 1 : fib(n-1) + fib(n-2); }

this is not a thing which we can express as a asentence.
asentence is for alive things it is not used to
express computation which will produce value/quantity.

it is to express alive thing. wtf does it means?
it means streams and flows and transforamtions.
it is the way to describe event based things.
it is the way to express things changing over time.
it is the way to express time.

ok so we can see time in this sentece how it will flow from start to end?
in AraDaNi protocol we cycle in sentence to construct and connect awords
according to syntax.
wtf does this means?
it means once sentence is connected we can start twist.
connected??? wtf does this means?

it means once transcript is joted on paper we can start twist.
while we twisting we may produce more trascript.
at some point we will start jotting tracript and
this is the perfect cycle we are trying to define.

We are using value oriented composition.
To ilustrate this consider how we itentify
What we need to do on server side while using http/json (rest) API.
First of all let's split our investigation in two parts.
Operating system does great job to hide complexity of TCP communiction
and gives us stream of chunks with order guarantee.
so we need to parse receved chunck to get to Http:body. then we
need to parse Http:body to get Json value. to be efficient this whole
process must run in coninious parsing mode. and all of this is done in
super complex manner.
the main problem is that we dont have protocol which is composable and
same time handles time flow.

can we do better?
lets imagine we have protocol which can parse page after page and can
produce page after page.

How we receive chuncks. first execution flow is interrupted,
then we read data from network card and we put it into queue
then we resume current procces.
At some point process will check and it will take data from queue.

So we need protocol which supports eleveating existing staff on next level.
So what we have?

We have:
Instruction set, RAM, written text for each interrupt, registers, call stack and GOTO.

So how to wrap all this?
We should have written transcript by which typewriter will type and wrap all of this
As growing ring.

Typewriter is same as tword.









How to express time in a sentence?
Time is already expressed by execution flow.
We need to start writing code.
We need to stop typing random ideas and start to code.

I need to stay here until we write the sample sentence.


Network interfaces.

Create socket.
Bind it to "127.0.0.1" address 3000 port.
Listen to socket.

Create socket and bind it and listen to it.

Listen for tcp connections. Foreach connection do something.

twist

* Sat Mar 16 11:46:42 AM +04 2024
CPU City

In the beginning, CPU City starts executing instructions stored in read-only memory.
These instructions instruct the CPU to execute commands from mountable media.

As users of computers, we can write instructions on mountable media and put them in the mountable device.
In fact, many of us copy instructions from others onto mountable devices to start our CPU City.

We are talking about instructions of the operating system.
We can think about the OS as a layer around CPU City.
The OS layer comes with its tooling to support programmers writing code,
which can be placed on top of the OS layer.

The OS is a single-layer monolithic beast.

We are missing abstractions that can support growth.

Let's pay attention to a living tree.
We can find the embryo of the tree within its seed.
The embryo has bark, roots, and two embryonic leaves.
While it grows, it forms a growing ring between the bark and the outermost growing ring.
That's how the layered architecture shows itself in creations of nature.
(picture of tree cut)
The tree grows and adapts to its surroundings and local climate.
Year after year and cycle after cycle, it forms growth rings, retaining information,
and extending its strengths, and memory.
It is a perfect example of the natural model of artificial intelligence (AI) by nature.

We need to find abstractions and paradigms that support this kind of beauty in software architectures.
1. Save State:          Save the current state of the program.
2. Disable Interrupts:  Prevent further interrupts.
3. Fetch ISR Address:   Retrieve the address of the Interrupt Service Routine (ISR) from the Interrupt Descriptor Table (IDT).
4. Execute ISR:         Transfer control to the ISR to handle the interrupt.
5. Process Interrupt:   Perform actions specific to the interrupt.
6. Restore State:       Restore the saved state of the program.
7. Enable Interrupts:   Allow subsequent interrupts.
8. Resume Execution:    Continue execution of the program from where it was interrupted.



* Sat Mar 16 02:35:03 PM +04 2024 */
