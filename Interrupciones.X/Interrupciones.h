

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

void Int_Init(void);
void __interrupt(low_priority) INT1_ISR(void);
void __interrupt(high_priority) INT0_ISR(void);

#endif	/* XC_HEADER_TEMPLATE_H */

