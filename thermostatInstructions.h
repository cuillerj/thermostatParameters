
/* default values
*/
#define reactivity 65     // express in 1/10 of °celsius the heating system capacity to increase temperature in 30mn with 10° outside tempreature
#define sizeAnticipation 7  // the window size of 30mn schedule steps that is taken into account to anticipate the warming need
#define maximumTemperature 220  // 
#define minimumTemperature 100
#define outHomeTemperatureDecrease 5
#define KpPID 20
#define KiPID 30
#define KpdPID 45
#define thresholdPID 7         // 255 means no PID
#define PIDCyleDelay 40 // expressed in mn*10 ex: 45 means 4mn30s
#define hysteresisDelay 30 // expressed in mn*10 ex: 45 means 4mn30s

#define tempListSize 5
#define notFreezeIdx 4
uint8_t temperatureList[tempListSize]={
  195,182,205,175,120};  // consigne temp *10 morning day evening night nofreeze