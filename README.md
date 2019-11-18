# Arduino Core for STM32L0 based boards

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

### Manually

Donwload ZIP file from this rpo folder using Clone or Downlaod button then select Download ZIP

 1. ```cd <SKETCHBOOK>```, where ```<SKETCHBOOK>``` is your Arduino Sketch folder:
  * OS X: ```~/Documents/Arduino```
  * Linux: ```~/Arduino```
  * Windows: ```~/Documents/Arduino```
 2. Create a folder named ```hardware```, if it does not exist, and change directories to it
 3. Extract the ZIP file content (```ArduinoCore-stm32l0-master```) into the ```hardware``` folder
 4. Rename the folder ```ArduinoCore-stm32l0-master``` to whatever you like, IE ```CH2i-stm32l0```
 5. Restart the Arduino IDE


### From git

 1. Follow steps from Board Manager section above
 2. ```cd <SKETCHBOOK>```, where ```<SKETCHBOOK>``` is your Arduino Sketch folder:
  * OS X: ```~/Documents/Arduino```
  * Linux: ```~/Arduino```
  * Windows: ```~/Documents/Arduino```
 3. Create a folder named ```hardware```, if it does not exist, and change directories to it
 4. Clone this repo: ```git clone https://github.com/ch2i/ArduinoCore-stm32l0.git CH2i/stm32l0```
 5. Restart the Arduino IDE

#### OS Specific Setup

##### Linux

 1. Go to ~/.arduino15/packages/TleraCorp/hardware/stm32l0/```<VERSION>```/drivers/linux/
 2. sudo cp *.rules /etc/udev/rules.d
 3. reboot

#####  Windows

###### STM32 BOOTLOADER driver setup for Tlera Corp and CH2i boards

 1. Download [Zadig](http://zadig.akeo.ie)
 2. Plugin STM32L0 board and toggle the RESET button while holding down the BOOT button
 3. Let Windows finish searching for drivers
 4. Start ```Zadig```
 5. Select ```Options -> List All Devices```
 6. Select ```STM32 BOOTLOADER``` from the device dropdown
 7. Select ```WinUSB (v6.1.7600.16385)``` as new driver
 8. Click ```Replace Driver```

###### USB Serial driver setup for Tlera Corp and CH2i boards (Window XP / Windows 7 only)

 1. Go to ~/AppData/Local/Arduino15/packages/TleraCorp/hardware/stm32l0/```<VERSION>```/drivers/windows
 2. Right-click on ```dpinst_x86.exe``` (32 bit Windows) or ```dpinst_amd64.exe``` (64 bit Windows) and select ```Run as administrator```
 3. Click on ```Install this driver software anyway``` at the ```Windows Security``` popup as the driver is unsigned

###### ST-LINK V2.1 driver setup for STMicroelectronics boards

 1. Plugin STMicroelectronics board
 2. Download and install [ST-Link USB Drivers](http://www.st.com/en/embedded-software/stsw-link009.html)

## Recovering from a faulty sketch for Tlera Corp or CH2i Boards

 Sometimes a faulty sketch can render the normal USB Serial based integration into the Arduindo IDE not working. In this case plugin the STM32L0 board and toggle the RESET button while holding down the BOOT button and program a known to be working sketch to go ack to a working USB Serial setup.

## Credits

This fork is based GrumpyOldPizza [Arduino STM32L0](https://github.com/GrumpyOldPizza/ArduinoCore-stm32l0)
This core is based on and compatible with the [Arduino SAMD Core](https://github.com/arduino/ArduinoCore-samd)

