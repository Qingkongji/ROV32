#ifndef DEBUG_H_
#define DEBUG_H_

//commet this if under non-debug situation

#ifdef DEBUG

/*
#define MS5837DEBUG    //debug macro for ms5837
#define JY901DEBUG     //debug macro for jy901
#define OUTTERDEBUG    //debug macro for outer loop
<<<<<<< HEAD
#define DATASENDDEBUG
=======
#define DATASENDDEBUG  //debug macro for serial data sending
#define IRQDEBUG       //debug macro for IRQ 
#define DECODERDEBUG   //debug macro for decoder
>>>>>>> HaskiDuan-master
*/

//#define JY901DEBUG     //debug macro for jy901
#define MS5837DEBUG    //debug macro for ms5837
#define IRQDEBUG
#define DECODERDEBUG


#endif  //#ifdef DEBUG

#endif  //#ifndef DEBUG_H_
