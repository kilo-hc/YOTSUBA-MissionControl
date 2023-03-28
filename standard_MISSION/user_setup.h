#include <18LF4620.h>
//#include <16F877A.h>

#FUSES HS
#FUSES NOWDT
#FUSES PUT
#FUSES NOPUT
#FUSES NOCPD
#FUSES NOPROTECT
#FUSES NOBROWNOUT
#FUSES NOLVP
#FUSES NODEBUG
#FUSES NOWRT

#use delay(clock = 4M)
#use rs232(stream = terminal, baud = 9600, xmit = PIN_b7, rcv = PIN_b6, bits = 8)

#define disp(...) fprintf(terminal, __VA_ARGS__)
