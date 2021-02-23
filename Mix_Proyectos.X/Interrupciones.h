

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPCIONES_H
#define	INTERRUPCIONES_H

#include <xc.h> // include processor files - each processor file is guarded.  

void Int_Init(void);
void __interrupt(low_priority) INT1_ISR(void);
void __interrupt(high_priority) TMR0_ISR(void);

#endif	/* XC_HEADER_TEMPLATE_H */

