# Arduino Core for STM32L0 based boards (Extension for CH2i Boards)

## What is it ?

ArduinoCore-stm32l0 is targeted at ultra low power scenarios, sensor hubs, with LoRaWAN connectivity.


## Supported boards

### Tlera Corp
 * [Grasshopper-L082CZ](https://www.tindie.com/products/TleraCorp/grasshopper-lora-development-board)
 * [Cricket-L082CZ](https://www.tindie.com/products/TleraCorp/cricket-lorawangnss-asset-tracker)
 * [Cicada-L082CZ](https://www.tindie.com/products/TleraCorp/lorasensortile)

### STMicroelectronics
 * [B-L072Z-LRWAN1](http://www.st.com/en/evaluation-tools/b-l072z-lrwan1.html)
 * [P-NUCLEO-LRWAN1](http://www.st.com/en/evaluation-tools/p-nucleo-lrwan1.html)
 * [NUCLEO-L053R8](http://www.st.com/en/evaluation-tools/nucleo-l053r8.html)
 * [NUCLEO-L073RZ](http://www.st.com/en/evaluation-tools/nucleo-l073rz.html)

### CH2i
 * CH2i various boards on Murata L082CZ chip
 
CH2i boards are based on Tlera Corp boards but we added some features such as: 

- RGB LED pins defined with ```LED_RED```, ```LED_GRN```, ```LED_BLU```
- DS18B20 GPIO definition defined ```ONEWIREPWR``` (Pin to power DS18B20, usually pin connected to VDD of the DS18B20), ```ONEWIREBUS``` (DS_DQ with 4K7 pullup)
- Battery Reading defined by ```BAT_ENABLE``` (Pin to enable battery reading), ```BAT_ANALOG``` (pin to read analog value)


When selected board you can select type by a new submenu called Board Type, and the following symbol will also be defined

- V1.0 ```BOARD_V10```
- V1.0a ```BOARD_V10a```
- ED V1.0 ```BOARD_ED_V10```

You can see these boards pinout definition in the file [variant.h](https://github.com/ch2i/ArduinoCore-stm32l0/blob/master/variants/CH2i-Murata-L082CZ/variant.h#L187-L300)

Boards can be identified at compilation by the defined symbol ```ARDUINO_STM32L0_CH2I_MURATA``` and version with also the following symbols

```cpp
#if defined (ARDUINO_STM32L0_CH2I_MURATA)
	#if defined (BOARD_V10) 
	// Code
	#elif defined (BOARD_V10a)
	// Code
	#elif defined (BOARD_ED_V10)
	// Code
	#endif
#endif
```

## Installing

### Install original repository

Follow installation for [original repository(https://github.com/GrumpyOldPizza/ArduinoCore-stm32l0)

### Add CH2i Boards 

Please to this step each time you update Tlera Corp Board from Arduino Board Manager

Donwload ZIP file from this repo folder using Clone or Download button then select Download ZIP

 1. Locate were the original repository was stored by Board Manager
  * OS X: ```~/Library/Arduino15/packages/TleraCorp/hardware/stm32l0/<VERSION>```
  * Linux: ```~/.arduino15/packages/TleraCorp/hardware/stm32l0/<VERSION>```
  * Windows: ```~/Documents/Arduino```
 2. Extract the ZIP file content (```ArduinoCore-stm32l0-master```) into the ```hardware/stm32l0/<VERSION>/``` folder overwriting all files when asked
 3. Restart the Arduino IDE



## Recovering from a faulty sketch for Boards

 Sometimes a faulty sketch can render the normal USB Serial based integration into the Arduindo IDE not working. In this case plugin the STM32L0 board and toggle the RESET button while holding down the BOOT button and program a known to be working sketch to go ack to a working USB Serial setup.

## Credits

This fork is based GrumpyOldPizza [Arduino STM32L0](https://github.com/GrumpyOldPizza/ArduinoCore-stm32l0)
This core is based on and compatible with the [Arduino SAMD Core](https://github.com/arduino/ArduinoCore-samd)

