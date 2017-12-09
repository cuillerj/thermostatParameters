/*
eeprom mapping
*/
#define eepromVersion 0x01

#define eepromVersionAddr 0
#define eepromUnitIdAddr eepromVersionAddr + 1
#define eepromTemperatureListAddr eepromUnitIdAddr + 2
#define eepromLastModeAddr  eepromTemperatureListAddr + tempListSize  
#define eepromRegistersAddr eepromLastModeAddr + 1 
#define eepromScheduleAddr  eepromRegistersAddr + registerSize+10

/*
arduino registers mapping
*/
#define registerSize 10
#define reactivityRegister 0
#define sizeAnticipationRegister 1
#define maximumTemperatureRegister 2
#define absenceTemperatureReductionRegister 3
#define KpPIDRegister 4
#define KiPIDRegister 5
#define KdPIDRegister 6
#define thresholdPIDRegister 7
#define PIDCycleRegister 8		// expressed in 1/100mn
#define hysteresisDelayRegister 9  // expressed in 1/00mn

uint8_t unitGroup = 0x05; // default value
uint8_t unitId = 0x00; // default value

#define LCDAddr 0x27
#define LCDChars 16
#define LCDLines 2
#define gatewayLinkSpeed 38400

/*

*/

char daysOfTheWeek[7][4] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"};
char runningModeKeyWord[6][8] ={"Off ","Week","Day1","Day2","HorsGel","Hold"};

/*
diagByte description
*/
#define diag0 0
#define diagExtTemp 1
#define diagTimeUpToDate 2
#define diagServerConnexion 3
#define diagGatewayReady 4
#define diagTempRampup 5
#define diagDS1820 6
#define diagEeprom 7
#define diagInitMask 0b11111110

/*
#define diag0 0
#define diagEeprom 1
#define diagTempRampup 2
#define diagServerConnexion 3
#define diagTimeUpToDate 4
#define diagDS1820 5
#define diagExtTemp 6
#define diagGatewayReady 7
#define diagInitMask 0b01111010
*/
/*
communication specifications
*/
#define requestFrameBit 7   //  set to 1 request set to 0 response
#define toAcknoledgeBit 6
#define ackBit 5
#define requestResponseMask 0x10
/* 
input from micro controler point of vue
*/
#define timeUpdateResponse 0x01
#define extTempUpdateResponse 0x02

#define statusRequest 0x01
#define scheduleUpdateRequest 0x02
#define temperatureListRequest 0x03
#define registerRequest 0x04
#define registersRequest 0x05
#define unitaryScheduleRequest 0x06
#define setModeRequest 0x07
#define setInstructionRequest 0x08
#define setSecurityRequest 0x09
#define setTemporarilyHoldRequest 0x0a

#define updateTemperatureRequest 0x0b
#define updateRegisterRequest 0x0c
#define updateSchedulRequest 0x0d
#define writeEepromRequest 0x0e
#define uploadScheduleRequest 0x0f
#define uploadTemperatures 0x10
#define uploadRegisters 0x11
#define tracePIDRequest 0x12
#define setInstruction 0x13
/*
output from micro controler point of vue
*/
#define statusResponse statusRequest|requestResponseMask
#define unitaryScheduleResponse unitaryScheduleRequest|requestResponseMask
#define temperatureListResponse temperatureListRequest|requestResponseMask
#define registerResponse registerRequest|requestResponseMask
#define registersResponse registersRequest|requestResponseMask
#define sendPIDResponse tracePIDRequest|requestResponseMask
#define timeUpdateRequest 0x01
#define extTempUpdateRequest 0x02
/*
GPIOs default values
*/
#define GatewayPowerPIN 3
#define InfraRedPIN 4
#define DiagPIN 6
#define GatewayReadyPIN 7
#define RelayPIN 10



#define oneWirePIN 8
//#define configWifiPIN 11
#define configPIN 11
/*
 Infra Red decode values
*/
#define IRIncreaseTemp 0xff906f
#define IRDecreaseTemp 0xffa857
#define IRSWitchOff 0xFFA25D   // 
#define IRSelectModeWeek 0xFF30CF   // 
#define IRSelectModeDay1 0xFF18E7   //
#define IRSelectModeDay2 0xFF7A85   // #define IRSelectModeNotFreezing 0xFF10EF // #define IRRebootGateway 0xFF9867
/*running modes*/#define modeOff 0               // system off#define modeWeek 1              // 7 days x 24h scheduling #define modeDay1 2              // 24h first scheduling #define modeDay2 3              // 24h second scheduling#define modeNotFreezing 4       // keep out of freeze/*define digital value to write for power on/off*/#define GatewayPowerOn 0        
#define GatewayPowerOff 1
#define HeatingPowerOn 1
#define HeatingPowerOff 0