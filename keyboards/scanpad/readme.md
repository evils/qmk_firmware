# scanpad

An stm32f103 (blue pill like) based 5x5 macro pad.  
It uses the TI TCA8418 key matrix scanner IC to handle the key matrix.  
It also has 2 RGB LEDs on the support plate (top left and top right) driven by an AP3156.

* Keyboard Maintainer: [Evils](https://github.com/Evils)

Make example for this keyboard (after setting up your build environment):

    make scanpad:default

Flashing example for this keyboard:

    make scanpad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
