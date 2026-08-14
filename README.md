# About
This repo contains a few simple tests for the miniUART on the
raspberry pi zero (and zero w). The actual driver for the device is in
library, which is explained below.

# Getting Started
If you actually want to run the programs on the pi, you'll need:
- a pi zero
- a way to power the pi
- an sd card
- a USB to TTL serial adapter
- compiler toolchain: arm-none-eabi (available on Linux, Windows, and macOS)

# Install
This repo makes use of a git submodule which contains the necessary bare-metal
code (linker script, gpio driver, etc.,) for the program(s) in this repo to
work. Since the library is inspired by Stanford's CS140E, it's private to
prevent the distribution of solutions to current/future students.

**Recruiters/employers**: if you'd like access to the library, please email me
at browses.epitaph.0e@icloud.com and I'll be happy to provide access.

Clone the repo and fetch the submodule
```
git clone --recurse-submodules git@github.com:carrolos/simple-blinky.git
```

If you stopped reading after 'Clone' and need to fetch the submodule:
```
git submodule update --init
```

# Running the program
To build the programs, run
```
make all
```
## No bootloader
If you don't have the bootloader, choose a test <x> and run
```
cp <x> kernel.img
```

Then copy `firmware/*` and `kernel.img` into your sd card. Plug your SD card
into the pi, then power on the pi, and connect the pi to your dev machine.

Since you don't have the bootloader, you'll have to use another utility that
communicates with devices and shows what's going on on your terminal, like
`screen`, `minicom`, `picocom`, etc. `screen` is standard, so I'll show how to
use that.

Find your tty device on your machine. On macOS, they'll have the prefix
`cu.usbserial-<xxx>` in the `/dev` directory, so run
```
ls /dev
```
to find the pi.

Then run
```
screen /dev/cu.usbserial-<xxx> 115200
```
on macOS, where you replace `<xxx>` with the suffix you found on the previous
step.

Your terminal should now show output from the pi!
