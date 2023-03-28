#include "user_setup.h"

//#use RS232(stream = MAIN_STREAM, baud = 9600, bits = 8, UART1)
#use RS232(stream = MAIN_STREAM, baud = 9600, bits = 8, xmit = PIN_C2, rcv = PIN_C1)

#define INTERRUPT_MAIN_PIN  PIN_B5

#define DATA_SIZE_MAX 1

int8 get_data[DATA_SIZE_MAX] = {};

void send_MAIN();
void data_print(char* data_name, int8* data, int8 data_size);

#INT_EXT
void from_MAIN() {
   disp("Interrupt << MAIN\r\n");
   for (int8 i = 0; i < DATA_SIZE_MAX; ) {
      if (kbhit(MAIN_STREAM)) {
         get_data[i] = fgetc(MAIN_STREAM);
         disp(get_data[i]);
         i++;
      }
   }
   data_print((char*)"get_data from MAIN:", get_data, DATA_SIZE_MAX);
}


int main(void) {
   delay_ms(2000);
   disp("fliename: %s\r\n", __FILENAME__);
   disp("compiled: %s %s\r\n", __DATE__, __TIME__);
    
   //disp("\r\nMISSION CONTROL START\r\n");
   
   enable_interrupts(INT_EXT);
   enable_interrupts(global);
  
   delay_ms(1);
   while (TRUE) {
      //send_MAIN();
       
      delay_ms(2000);
   }
    
   disp("program end\r\n");
    
   return 0;
}

void send_MAIN() {
   static int8 data = 0;
   output_high(INTERRUPT_MAIN_PIN);
   delay_us(8);
   for (int8 i = 0; i < DATA_SIZE_MAX; i++) {
      fputc(data, MAIN_STREAM);
      data++;
   }
   output_low(INTERRUPT_MAIN_PIN);
    
   disp("%u bytes sent to MAIN\r\n", i);
}

void data_print(char* data_name, int8* data, int8 data_size) {
   disp("%s", data_name);
   for (int i = 0; i < data_size; i++) {
      if (!(i % 16)) {
         disp("\r\n");
      }
      disp(" %3u", data[i]);
   }
   disp("\r\n");
}


