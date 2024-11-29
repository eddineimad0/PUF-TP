## Requirements
1. [mingw-w64](https://winlibs.com/#download-release)
    - only for windows OS.
    provides make build system tool.
    download, install and add the bin folder to PATH.

2. [arm-gnu-toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
    required to compile source code for arm chip
    download, install and add the bin folder to PATH.

4. [ST-Link tools](https://github.com/stlink-org/stlink/releases/tag/v1.8.0)
    cmdline tools to interact with ST-Link device.
    download, extract and add the bin folder to PATH.

# Installation
1. compile the firmware on success you should have a `firmware.bin` file inside **out/bin** folder .
```bash
 make
```
2. connect the microcontroller and flash the firmware with st-tools. 
```bash
st-flash --reset write out/bin/firmware.bin 0x08000000
```
3. connect to the serial port and check the output.
