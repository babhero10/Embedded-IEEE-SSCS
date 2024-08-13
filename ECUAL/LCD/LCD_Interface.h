/*
 * LCD_Interface.h
 *
 *  Created on: Aug 13, 2024
 *      Author: abdal
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"

// LCD Commands
#define LCD_CLEAR_DISPLAY        0x01
#define LCD_RETURN_HOME          0x02
#define LCD_ENTRY_MODE_SET       0x06
#define LCD_DISPLAY_ON           0x0C
#define LCD_DISPLAY_OFF          0x08
#define LCD_CURSOR_ON            0x0E
#define LCD_CURSOR_OFF           0x0C
#define LCD_BLINK_ON             0x0D
#define LCD_BLINK_OFF            0x0C
#define LCD_SHIFT_LEFT           0x18
#define LCD_SHIFT_RIGHT          0x1C
#define LCD_SET_4BIT_MODE        0x28
#define LCD_SET_8BIT_MODE        0x38
#define LCD_SET_CURSOR_POSITION  0x80

typedef struct {
    GPIO_Pin_t rsPin;  // Register Select pin
    GPIO_Pin_t rwPin;  // Read/Write pin (optional, can be grounded if only writing)
    GPIO_Pin_t enPin;  // Enable pin
    GPIO_Pin_t dataPins[4]; // Data pins (D4 to D7 for 4-bit mode)
} LCD_t;

/**
 * @brief  Initializes the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @return None.
 */
void LCD_Init(LCD_t* lcd);

/**
 * @brief  Sends a command to the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  cmd: Command to send.
 * @return None.
 */
void LCD_SendCommand(LCD_t* lcd, U8 cmd);

/**
 * @brief  Sends a character to the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  data: Character to send.
 * @return None.
 */
void LCD_SendChar(LCD_t* lcd, U8 data);

/**
 * @brief  Sends a string to the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  str: Pointer to the string to send.
 * @return None.
 */
void LCD_SendString(LCD_t* lcd, const char* str);

/**
 * @brief  Sets the cursor position on the LCD.
 * @param  lcd: Pointer to the LCD structure.
 * @param  row: Row number (0 or 1).
 * @param  col: Column number (0 to 15).
 * @return None.
 */
void LCD_SetCursorPosition(LCD_t* lcd, U8 row, U8 col);

/**
 * @brief  Clears the display.
 * @param  lcd: Pointer to the LCD structure.
 * @return None.
 */
void LCD_Clear(LCD_t* lcd);

#endif /* LCD_LCD_INTERFACE_H_ */
