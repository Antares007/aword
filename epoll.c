#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_EVENTS 10
int setnonblocking(long fd) {
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags < 0)
    return flags;
  flags |= O_NONBLOCK;
  return fcntl(fd, F_SETFL, flags);
}

int main() {
  int epollfd;
  if ((epollfd = epoll_create1(0)) == -1)
    perror("epoll_create1"), exit(EXIT_FAILURE);

  struct epoll_event ev = {.events = EPOLLIN, .data.fd = STDIN_FILENO};
  if (setnonblocking(ev.data.fd) == -1)
    perror("cant set O_NONBLOCK"), exit(EXIT_FAILURE);

  if (epoll_ctl(epollfd, EPOLL_CTL_ADD, ev.data.fd, &ev) == -1)
    perror("epoll_ctl: listen_sock"), exit(EXIT_FAILURE);

  unsigned char buffer[65536];
  struct epoll_event events[MAX_EVENTS];
  for (int nfds;;)
    if ((nfds = epoll_wait(epollfd, events, MAX_EVENTS, 0)) == -1)
      perror("epoll_wait"), exit(EXIT_FAILURE);
    else
      for (long n = 0; n < nfds; ++n)
        for (long buflen;;)
          if ((buflen = read(events[n].data.fd, buffer, sizeof(buffer))) < 0)
            if (errno == EAGAIN || errno == EWOULDBLOCK)
              break;
            else
              perror("read"), exit(EXIT_FAILURE);
          else
            printf("%ld\n", buflen);
}
/*
what does it means to multitask when we have ony one robot? it means to at some
point our robot must stop execution instructions to put asaide current task and
continue other or start new one.

Exactly when must we stop?
it depends on a aword he executing. aword can diside to give controll into other
hand.
now we need to do concrete example. we need to start process and follow with our
robot(CPU). We need to prepare concrete example to show actionable word in
action. I think best example will be to show how it can be used to controll and
connect information flow. we need to show how we can describe information flow
in a way that is simple and easy to understand.

We can view whole actionable sentence as a pipe composed by acrionable words.
basicly each word can be viewed as producer, consumer or transformer.
Producer will produce information and it will cache it. so every time when
execution flow will go true producer it will take current information. consumer
will consume information in any way he wants and transformer will do bouth
operations.

Actionable sentence is very mutch like normal english.
In particular in actinable word execution will flow from bouth directions. from
left and from right.

by convention we will recall actionable words with prefix a.
Here is concrete example:
read from "input" file and write to console.
so we desided to implement this setence. question is which protocol we will use?

we know that we need to assert width of actionable word.

# Actionabe word as a binary file:
it has variable width.
thay have clear defined boundaries.
thay can be puted together in a ram to compose actionable text.
we can say that actionable word has two forms as a binary which
is whole meaning it does not need dinamic linking during loading
by executor. it has its own method to satisfy dependencies.

What is the method of dependecy injection?
How do we inject dependecyes?
How we structure actionable text?
We can use idea of book papers grouped together. we can draw analogy to
blockchain too. so paper i.e. block of actionable texts. there maybe headers
with definition. or just text separated by dots.
In any case it can be binary executable block?
it must be aword. simply by protocol aword is asentence and asentence is a
aword. so we have aword and by protocol connection between awords is indirect so
we can say aword can be asentece which is distributed like blockchain. And it
uses its own beginings to satisfy all dependencies it needs. We need to think
about special awords which represents newline and space. we are using it to
split header text from its definitions i.e. asenteces. below we will show what
we are doing when we flow in it.

so how exactly we can start exequiting this aword which is abook?
suppose we have hash which represents this abook.
we will get last page and will flow in in Fuchsia ray. now we are in the aword
"dot". note execution of asentence is starting from dot. and we will flow down
to begining of the sentence which is represented by special word abegin and this
last sentence must be a program. it is the part definitons of some "aheader". So
we have header text followed by anewline with one or more asentece.

so we can start executiong it right away?
what does in this context means branch?
to define tree in mathematics we are using substitution. we can name group of
asentences and use that aname in other place. so we have brunch.
TOTI.

In actionable word when we are composing actionable text we need to take in
consideration that it is well desctribed in human language.

When we are defining the word in human langugage we are writing word and its
definition from new line.
We do not putting dot in the end of header text.
Rather we continue definition from new line. Note we can put as many definitions
as we header text requires.

What does it mean in contect of substitution.
We meand subtitution as a mechanism we are using in mathematics. In definition
of other entity we can substitute header text we are using with its body. now
question is how we are sustituting if we heave several definitions. I have
intuition that we need to substitue one by one. substitution in this case looks
like product operator.
So we need some way to proppeler definitions of actionable word. in other words
we need to produce as many executable brances as many definitions we have.

Another question is we can have header as text composed with several awords what
does it means?

# Actionable word as a narrative:
we cant easely write actionable text in this version.
this version is lightwait and easy to show main idea. we spoted how to dependecy
injection can work. now lets extend idea and discuss roots i.e. root system.
roots is just asentece which is there from begining. It is aword which has acess to
hardware in other words it staticly linked with os.
in this version we need to know width of the pith rest we can calculate as a result
we will have variable length atext. we can also fix width 5+5+5 = 15 this we already
have and to show concept it is mere then enought.

# how dependecy injection will work?
we need to have boundaries around aword. main reason is to avoid static linking. in sthis way aword can fully defined.

# text index
text index is number which we can use to reference aword, 

how we define names?
with help of specal "tab", "carige return", "space" and "dot" words.
example:
Τab T_Green(na) T_Green(me) Tcr T_Green(definition) Ts T_Green(one) To
im switching from one version to another.

think version forces us to solve any issue with colsed boundaries and without global O.
it can have inner alocations to wite sentences which will projected on a global O in any way.
now we need to start! i.e. start sharing! what we will share first? well i want to share
somthing which i will be proud of. it must be usefull it must solve real problem in realy
nice way. at least 10 times nicer easier and faster. bug free etc.
real problem is todays communication complexity. in particular resfull API-s.
HTTP/JSON communication. it involves parsing multitasking and complexity of defining task
which involves time dimension.

here we can observe that we have even more little composition units then word.
we can compose words itself with prefix root sufix.


now i have observed when i am reading i cant focus have other ideas floating in
it. so i need to write all time to be in perfect focus state.

So my writing will be trush at first but we will refine them latter. So dont
worry be happy.

this is awesome example to describe protocol and show all its beauty.
we can start by implementing above text and then descibing it in plain words.
ok lets do it now.

what is actionable text?

we have several protocols actionable word as
an bindary file and as a group of narratives which together are defining
actionable text.


T stands for actionable text and we have actionable word and sentence lets
define them.


in actionable word execution can flow in from


Read decode execute write.
Where should we place the call to epoll_wait?
Read data in a loop until EAGAIN?

The epoll_wait function checks if there is data to read and returns an answer.
If we don't read all of the data until EAGAIN, the epoll_wait function will
never tell us that there is still data to read. We can think of the epoll_wait
call as an interrupt handler for a device, such as a keyboard. In the interrupt
handler, we need to read all of the data from the device and store it in a
separate location for the consumer. If the data is flowing too quickly for us to
consume it, we need to apply backpressure to the device to slow down the data
transmission. If there is no more space to store the data, we may need to
discard it. For a keyboard, we can signal the user with a sound as backpressure,
telling them to "stop typing so fast."

To analyze our thinking, what is backpressure? In normal human-to-human
communication, we can identify moments when the listener may say "stop talking
too fast" or acknowledge with some reaction to request more data. Today, we need
to do something measurable and have a plan. Here are some tasks to consider:

Write a program to calculate mathematical expressions. The program should
consume input from stdin, parse expressions and calculate them incrementally.
Write a program that listens to stdin and parses text, then performs actions
accordingly. The goal is to make the program as efficient as possible.

   example:
    1+2*3<CR>
    7
    *7<CR>
    49
    -1<CR>
    48
   example:
    open window by 800x600. draw line from 0, 0 to 100, 100.
 */
