/* 
 * File:   MotorFunctions.h
 * Author: Natalia
 *
 * Created on 07 December 2018, 14:23
 */

#ifndef MOTORFUNCTIONS_H
#define	MOTORFUNCTIONS_H

void motorSetup();

void setMotorDir( int );

void changeMotorDir();


//for h-bridge direction output
#define DIR_A LATBbits.LATB2
#define DIR_B LATBbits.LATB3

void motorDrive(int drive_level);


#endif	/* MOTORFUNCTIONS_H */

