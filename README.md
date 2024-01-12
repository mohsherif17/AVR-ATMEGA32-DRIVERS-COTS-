# AVR-ATMEGA32-DRIVERS-COTS-
The layered architecture structure or Componant on the shelf (COTS)  in Embedded system is a method of abstraction of different Code Layers to achieve reusability ,Modularity, configurability and portability

The drivers included in this project are devided into three layers:-
1- MCAL:
    -DIO (Digital input/output)
    -ADC (Analog to Digital Converte)
    -GIE  (Genreal inturrept)
    -EXT-inturrept (External inturrept)
    -Timer 0
    -Timer 1
    -watchdog
    -USART
    -SPI
    -TWI(I2C)

2- HAL:
    -CLCD  (character LCD)
    -DC motor
    -EEPROM
    -KPD (KEYPAD)
    -SSD (SEVEN SEGMENT DISPLAY)
    -STEPPER MOTOR
3- LIBS
    -STD_TYPES
    -BIT_MATH
