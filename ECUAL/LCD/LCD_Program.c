/*
 * LCD_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: abdal
 */

#include "LCD_Interface.h"

/**
 * @brief Send enable pulse to the enable pin.
 * @param lcd: Pointer to LCD_t to send enable pulse.
 * @return None
 * */
static void LCD_EnablePulse(LCD_t* lcd) {
    GPIO_WritePin(&lcd->enPin, 1);
    _delay_us(1);
    GPIO_WritePin(&lcd->enPin, 0);
    _delay_us(100);
}

/**
 * @brief Send 4 bits to the data pins.
 * @param lcd: Pointer to LCD_t to send bits.
 * @param data: Bits to send.
 * @return None.
 * */
static void LCD_Send4Bits(LCD_t* lcd, U8 data) {
    for (int i = 0; i < 4; i++) {
        GPIO_WritePin(&lcd->dataPins[i], (data >> i) & 0x01);
    }
    LCD_EnablePulse(lcd);
}

/**
 * @brief  Initializes the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @return None.
 */
void LCD_Init(LCD_t* lcd) {
    // Set pin modes
    GPIO_Config_t config;
    config.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    config.speed = GPIO_SPEED_2MHZ;

    config.pin = lcd->rsPin;
    GPIO_init(&config);

    config.pin = lcd->enPin;
    GPIO_init(&config);

    for (int i = 0; i < 4; i++) {
        config.pin = lcd->dataPins[i];
        GPIO_init(&config);
    }

    // Initialization sequence
    _delay_ms(20);  // Wait for LCD to power up
    LCD_Send4Bits(lcd, 0x03);  // Function set (8-bit mode)
    _delay_ms(5);
    LCD_Send4Bits(lcd, 0x03);
    _delay_us(100);
    LCD_Send4Bits(lcd, 0x03);
    _delay_us(100);
    LCD_Send4Bits(lcd, 0x02);  // Set to 4-bit mode

    // Function set, display on, clear display, entry mode
    LCD_SendCommand(lcd, LCD_SET_4BIT_MODE);
    LCD_SendCommand(lcd, LCD_DISPLAY_ON);
    LCD_Clear(lcd);
    LCD_SendCommand(lcd, LCD_ENTRY_MODE_SET);
}

/**
 * @brief  Sends a command to the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  cmd: Command to send.
 * @return None.
 */
void LCD_SendCommand(LCD_t* lcd, U8 cmd) {
    GPIO_WritePin(&lcd->rsPin, 0);
    LCD_Send4Bits(lcd, cmd >> 4);
    LCD_Send4Bits(lcd, cmd & 0x0F);
}

/**
 * @brief  Sends a character to the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  data: Character to send.
 * @return None.
 */
void LCD_SendChar(LCD_t* lcd, U8 data) {
    GPIO_WritePin(&lcd->rsPin, 1);
    LCD_Send4Bits(lcd, data >> 4);
    LCD_Send4Bits(lcd, data & 0x0F);
}

/**
 * @brief  Sends a string to the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  str: Pointer to the string to send.
 * @return None.
 */
void LCD_SendString(LCD_t* lcd, const char* str) {
    while (*str) {
        LCD_SendChar(lcd, *str++);
    }
}

/**
 * @brief  Sets the cursor position on the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  row: Row number (0 or 1).
 * @param  col: Column number (0 to 15).
 * @return None.
 */
void LCD_SetCursorPosition(LCD_t* lcd, U8 row, U8 col) {
    U8 address = (row == 0) ? (0x00 + col) : (0x40 + col);
    LCD_SendCommand(lcd, LCD_SET_CURSOR_POSITION | address);
}

/**
 * @brief  Clears the display.
 * @param  lcd: Pointer to the LCD structure.
 * @return None.
 */
void LCD_Clear(LCD_t* lcd) {
    LCD_SendCommand(lcd, LCD_CLEAR_DISPLAY);
    _delay_ms(2);
}
