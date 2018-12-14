# tpluc - Experimental Template Based Approach to Program Microcontrollers

When trying to implement libraries for interfacing components via micro controller, 
I often wanted to have some details configurable, so that the project integrating
the library can decide how to use the component. E.g. to which pins the component
is attached, etc.

## Arduino Framework

The Arduino framework provides some abstractions from the underlying microcontroller,
so the pins are numbered and addressed by using the pin numbers; they can be configured
and controlled by using these numbers and functions like ``pinMode()``, ``digitalWrite()``,
etc. When creating a configurable library on top
of the Arduino framework, the pin numbers could be passed to and stored by the library,
and the pin manipulation could be carried out using the Arduino functions.

The cons of doing so are:
* Own library requires Arduino framework
* Arduino functions are slower than direct port manipulation (see below)
* Use of program memory and RAM for the Arduino functions and configuration, e.g. pin numbers

## Microcontroller Registers

In contrast, the underlying microcontroller allows pin manipulation by manipulating
some bits of various registers, e.g. ``DDRx``, ``PORTx``, ``PINx``.
While this is *native* and so fastest possible, it's hard to easily configure,
because there are multiple registers and values that need to be considered to control a single pin.

## Templates

In this project, I'm trying to have some abstractions and ways to configure libraries like
possible with the Arduino approach, but without its drawbacks. C++ offers a very powerfull mechanism,
that moves a lot of magic from runtime to compile time: templates.

Here I want to explore how to use templates to build configurable libraries.
