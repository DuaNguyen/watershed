Watershed
--------------
This repository contains source code for Watershed embedded project using STM Board.

System diagram
--------------
![system diagram](https://raw.githubusercontent.com/DuaNguyen/watershed/master/system_diagram.png)

Project structure
--------------
```
root/
├── lib/
│   ├── INA219/
│   │   ├── INA219_consts.h
│   │   ├── INA219.hpp
│   │   └── INA219.cpp
│   │
│   ├── IO/
│   │   ├── interruptfunc.h  // button SW_SET and SW_SELECT
│   │   └── iopin.h    //IO pins definition
│   │
│   ├── LCD_display/
│   │   ├── lcd_menu.hpp  // 3 menus
│   │   └── logo.h    // contains Watershed's logo
│   │
│   └── SSD1306/
│       ├── Adafruit_GFX.h
│       ├── Adafruit_GFX.cpp
│       ├── Adafruit_GFX_Config.h
│       ├── Adafruit_SSD1306.h
│       └── Adafruit_SSD1306.cpp
│     
└── src/
    └── main.cpp  // main function goes here

```

Installation
--------------

Usage
--------------

To be updated ...