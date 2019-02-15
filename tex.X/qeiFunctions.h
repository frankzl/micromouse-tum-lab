
#ifndef	QEI_FUNCTIONS_H
#define	QEI_FUNCTIONS_H

void setupQEI();

void __attribute__((interrupt, auto_psv)) _QEIInterrupt(void);

#endif 