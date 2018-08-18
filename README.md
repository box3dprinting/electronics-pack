# electronics-pack
box3d firmware for the bo3d controller, suitable for 3D printer enclosures.

# box3d mission
3D priners are emitting toxic fumes, producing terrible noise and users experience warping. We want to make 3D printing stable, safe and silent for everyone. You can use this software to flash the box3d controller. We are not dedicated software developpers like many of you. Your help in improving this software is greatly appriciated. Feel free to do any modifications to this software and share it with the 3D printing community.

# FLASH BOX3D WITH THE LATEST FIRMWARE
To upload the latest firmware to the box3d controller, follow the next steps (windows only):

1. Go to http://xloader.russemotto.com/ to download the latest version of Xloader
2. Open Xloader
3. Select the .hex file with the firmware
4. For "Device", select Duemilanove/Nano(ATmega328)
5. Disconnect the power supply from the controller
6. Connect the controller with the usb cable to you PC
7. The Baud rate should be the default 57600
8. Click on "Upload"
9. Done. The display of the box3d controller should start up now.

# MODIFY BOX3D FIRMWARE
You can modify the box3d firmware, but is at your own risk. Please read the following notes carefully:
Notes:
- Modifying the firmware is at your own risk. By modifying the firmware, all warranty on electronics is no longer valid.
- It uses the “U8glib” and “EEPROM” libraries which can be downloaded in the Arduino IDE.
- The code is written and tested in Arduino IDE version 1.8.5.
- The following pins are in use, and should not be overwritten: D2, D3, D4, D5, D9, A0, A4, A5

# Thanks
For using and contributing to this software!

Yours,
the box3d team
