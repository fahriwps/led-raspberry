/*
 * Copyright (C) 2018 bzt (bztsrc@github)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "mbox.h"
#include "delays.h"

void set_led(int state) //cek status LED
{
    if (state==1){ //LED ON
        mbox[0] = 8*4;                  // panjang pesan
        mbox[1] = MBOX_REQUEST;         // pesan request
    
        mbox[2] = 0x00038041;   		// serial number
        mbox[3] = 8;                    // ukuran buffer
        mbox[4] = 0;
        mbox[5] = 130;                    // bersihkan output buffer
        mbox[6] = 1;                      //LED ON
        mbox[7] = MBOX_TAG_LAST;
        mbox_call(8);
    }
    else if (state==0){ //LED OFF
        mbox[0] = 8*4;                  // panjang pesan
        mbox[1] = MBOX_REQUEST;         // pesan request
    
        mbox[2] = 0x00038041;   		// serial number
        mbox[3] = 8;                    // ukuran buffer
        mbox[4] = 0;
        mbox[5] = 130;                    // bersihkan output buffer
        mbox[6] = 0;                    //LED OFF
        mbox[7] = MBOX_TAG_LAST;
        mbox_call(8);
    }
}

void delay(int miliseconds) 
{ 
    // convert milisec ke microsec 
    int micro_seconds = 1000 * miliseconds; 
  
    wait_msec(micro_seconds); 
} 

void main()
{
    // LED berkedip sesuai NIU
    //Nama : FAHRI
    //NIU  : 
    //NIM  : 

    int digit1 = 3;
    int digit2 = 9;
    int digit3 = 4;
    int digit4 = 9;
    int digit5 = 2;
    int digit6 = 9;
    int n = 0;
    
    
    while (1)
    {
        for (n = 1; n <= digit1; n++) 
        { 
            set_led(0); //karena saya memakai Raspi 3 B+ LED pada power harus OFF terlebih dahulu 
            delay(200);
            set_led(1);
            delay(200); 
        } 

        delay(2000);

        for (n = 1; n <= digit2; n++) 
        { 
            set_led(0);
            delay(200);
            set_led(1);
            delay(200); 
        } 

        delay(2000);

        for (n = 1; n <= digit3; n++) 
        { 
            set_led(0);
            delay(200);
            set_led(1);
            delay(200); 
        } 

        delay(2000);

        for (n = 1; n <= digit4; n++) 
        { 
            set_led(0);
            delay(200);
            set_led(1);
            delay(200); 
        } 

        delay(2000);

        for (n = 1; n <= digit5; n++) 
        { 
            set_led(0);
            delay(200);
            set_led(1);
            delay(200); 
        } 

        delay(2000);

        for (n = 1; n <= digit6; n++) 
        { 
            set_led(0);
            delay(200);
            set_led(1);
            delay(200); 
        } 

        delay(2000);
    }
    
    
}
