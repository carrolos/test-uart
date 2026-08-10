# About
This repo contains a few simple tests for the miniUART on the
raspberry pi zero (and zero w). The actual driver for the device is in
library, which is explained below.

# Getting Started
If you actually want to run the programs on the pi, you'll need:
- a pi zero
- a way to power the pi
- an sd card
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
and then choose a test <x> and run
```
cp <x> kernel.img
```

Then copy `firmware/*` and `kernel.img` into your sd card.

Plug your sd card into the pi, then power on the pi, and you should see it
blink every second!
