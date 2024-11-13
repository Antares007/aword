// clang-format off
#include "../main.h"
N(dive);
N(rise);
S(nearch            ) { τ = β[ρYellow][1],
                        oB(ρYellow, rise), Go(OS); }

/// search name in actionable text twisted in Blue
/// first search South, then North
S(search            ) { oB(ρYellow, Go, τ = ((τ >> Σ) << Σ)),
                        oB(ρYellow, nearch),
                        oB(ρYellow, Or),
                        oB(ρYellow, dive), Go(OS); }

S(book_of_ani       );

/// step east and interpret actionable word with book_of_ani
N(ani               ) { oB(ρYellow, book_of_ani), go_e(OS); }

S(stop              ) {}


/// match string twisted in Blue and twist "stop" into A
/// pyramids' Red side to stop left recursion check chain.
///
/// twist match string on B pyramids' Red side. It is
/// used by the print procedure, and twist in advanced input 
/// string representation on the Blue side of the B pyramid.
S(match             ) { const char *t = o[τ + 1];
                        const char *s = β[ρBlue][1];
                        long length   = β[ρBlue][2];
                        long pos      = β[ρBlue][3];
                        if (pos < length && s[pos] == t[0])
                          oA(ρRed,  stop),
                          oB(ρRed,  Go, o[τ + 1]),
                          oB(ρBlue, Go, s, length, pos + 1), ani(OS);
                        else
                          Gor(OS);
                      }

/// twist in string from actionable text to B pyramids' Red side for printing.
S(ani_put           ) { oB(ρRed, Go, o[τ + 1]), ani(OS); }

/// print all stuff twisted in B pyramids' Red side.
S(ani_print         ) { long **b = β;
                        printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
                        while (b[ρRed][-1])
                          printf("%s ", (char *)b[ρRed][1]), b = b[ρRed][-1];
                        printf(")\n");
                        ani(OS); }

extern int strcmp(const char *, const char *);
extern int getchar (void);


/// procedure for left recursion check chain which is twisted on A pyramids' Red side.
/// it is twisted in swords interpretation and has access to tau of the "sword".
/// it stores the result in callers arms (τ+2).
S(check_lr          ) { if(strcmp(o[β[ρYellow][1]+1], o[τ + 1]) == 0) o[τ + 2] = 1; else
                        Go(OS); }

S(set_τ_to_βρYellow1) { τ = β[ρYellow][1], Go(OS); }

/// switches Pyramids, restores forward flow from the right side of the sword,
/// and twists in stop in the left recursion check chain.
S(ani_twist         ) { oA(ρYellow, ani),
                        oB(ρRed,    stop),
                        oB(ρYellow, Twist), Go(OS); }

/// cursor in time. by climing up to this cursor on B Pyramid, we restore all
/// accessable state (staff located above us), which is twisted in pyramyds A and B
/// Now we are free to try new path in actionable text terrain and down grow Pyramyds accordingly.
S(cursor            ) { τ = β[ρYellow][1],
                        α = β[ρYellow][2], God(OS); }

/// Go in to the first tab and twist tau of the found name into A pyramids Blue side.
/// we need it when we will reach "dot" to know from where definitions is starting
/// for current tab (paragraph);
S(marknameandgointab) { oB(ρYellow, book_of_ani),
                        oB(ρYellow, go_s),
                        oA(ρBlue,   Go, τ), Go(OS); }
/// * run left recurrsion check chain so if this is the "tab" which recurses ignore it
/// and clime to next cursor.
/// we do not take path which curses. we will handle problem of the left curses form other
/// side of the tab (sentence/paragraph).
///
/// note: sentece has two sides begining "tab" and end "dot".(period):w
///
/// * twist in left recursion check chain and cursor on pyramid A to climb for sword
/// and continue flow from its rightside. climbing on pyramid A starts when we reach "dot"
/// in actionable text i.e. when we fully interpret defining "tab" (paragraph) of the sword.
/// * find definition for swords name and goin into first "tab"
///
S(Yellow_sword      ) { Go( o, α, β, τ, σ, ρRed, -δ, ν);
                        if(o[τ + 2]) return Gor(OS);

                        oA(ρYellow, ani_twist, τ),
                        oA(ρRed,    check_lr),
                        oA(ρYellow, set_τ_to_βρYellow1);

                        oB(ρYellow, marknameandgointab),
                        oB(ρYellow, And),
                        oB(ρBlue,   Go, o[τ + 1]),
                        oB(ρYellow, search), Go(OS); }

S(ani_sword         ) { oB(ρYellow, Yellow_sword), Go(OS); }

S(ani_tword         ) { oB(ρGreen,  Go),
                        oB(ρYellow, match), Go(OS); }

/// twist cursor, for potentionaly next "tab" into B pyramid  and setep east with book of ani.
/// on next line we may found 'tab', 'name', or 'halt'. ofcorse we will do same for tab or
/// climb up for next cursor for other cases.
S(ani_tab           ) { oB(ρYellow, book_of_ani, τ + (1 << Σ), α),
                        oB(ρYellow, cursor);
                        ani(OS); }


S(grow              ) { oB(ρGreen,  book_of_ani),
                        oB(ρYellow, to_Green), Go(OS); }

S(Yellow_dot        ) { //oB(ρYellow, grow, α[ρBlue][1] + (1 << Σ), α),
                        //oB(ρYellow, cursor);
                        oB(ρYellow, Twist), Go(OS); }

S(ani_dot           ) { //oB(ρGreen,  Go),
                        oB(ρYellow, Yellow_dot), Go(OS); }

/// climb up to the top of the B pyramid.
S(ani_name          ) { Go(OS); }
S(ani_halt          ) { Go(OS); }
S(ani_end           ) { Go(OS); }

S(book_of_ani       ) {
  is_a_book_of(
    [tab  ] = ani_tab,
    [put  ] = ani_put,
    [tword] = ani_tword,
    [nop  ] = ani,
    [print] = ani_print,
    [sword] = ani_sword,
    [dot  ] = ani_dot,
    [end  ] = ani_end,
    [name ] = ani_name,
    [halt ] = ani_halt,
  );
}
