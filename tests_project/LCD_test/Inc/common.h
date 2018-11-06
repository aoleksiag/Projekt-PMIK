/*
 * Autor: �ukasz �aguna
 * E-mail: kontakt@embeddeddev.pl
 * www.EmbeddedDev.pl
 *
 * Obs�uga LCD opartych na sterowniku HD44780
 * tryb 4-bitowy, bez odczytu busy flag
 *
 * MCU: STM32F103
 *
 */


#ifndef COMMON_H_
#define COMMON_H_

void delay_ms(uint16_t czas);
void delay_us(uint8_t czas);

#endif /* COMMON_H_ */
