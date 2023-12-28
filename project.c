#include "quickmail.h"
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

#define FROM        "E-MAIL ADDRESS"
#define TO          "E-MAIL ADDRESS"
#define SMTPSERVER  "smtp.gmail.com"	// Any SMTP server, I used Google
#define SMTPPORT    587					// For Google SMTP server 
#define SMTPUSER    "SMTP USER ADDRES"
#define SMTPPASS    "SMTP PASSWORD"
#define PIRPin       7					// PIRPin		


int main ()
{
    if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		exit(1);
	}

	pinMode(PIRPin,INPUT);

    while(1){
        if (digitalRead(PIRPin)){
            quickmail_initialize();
            quickmail mailobj = quickmail_create(FROM, "Einbrecheralarm!");
            #ifdef TO
            quickmail_add_to(mailobj, TO);
            #endif
            #ifdef CC
            quickmail_add_cc(mailobj, CC);
            #endif
            #ifdef BCC
            quickmail_add_bcc(mailobj, BCC);
            #endif
            quickmail_add_header(mailobj, "Importance: High");
            quickmail_add_header(mailobj, "X-Priority: 5");
            quickmail_add_header(mailobj, "X-MSMail-Priority: High");
            quickmail_set_body(mailobj, "ALARM!\nBewegung erkannt.");
            quickmail_add_body_memory(mailobj, "text/html", "<b>ALARM!</b></br>\nBewegung erkannt.", 37, 0);	// The third parameter contains the message to be sent
            const char* errmsg;
            quickmail_set_debug_log(mailobj, stderr);
            if ((errmsg = quickmail_send(mailobj, SMTPSERVER, SMTPPORT, SMTPUSER, SMTPPASS)) != NULL)
            fprintf(stderr, "Error sending e-mail: %s\n", errmsg);
            quickmail_destroy(mailobj);
            quickmail_cleanup();
            delay(10000);
        }
    }
  
  return 0;
}
