/*
 * alu.cpp
 *
 *  Created on: Sep 21, 2023
 *      Author: rehanashraf
 */

/*
 * Introduction:
 * Gas Pedal LLC is making a new HW accelerator consisting of
 * 3 ALUs, each can compute the following math functions:
 * - sine(value)
 * - cosine(value)
 * - log(base, value)
 * - x ^ y(base, value). “x to the power of y”.
 *
 * All registers are 32-bits.
 * All operands and results are signed, 8-bit,
 * 3.5 fixed point format.
 *
 * Register specification:
 *   Control Register:
*     address = 0x11110000
 *     bits 6 - 0: ALU instance 0
 *       bit 0 = interrupt enable
 *       bit 1 = Done bit. HW sets to 1 for complete
 *               SW sets to 0 to launch work.
 *       bit 3 - 2 = opcode:
 *                     sine = 0
 *                     cosine = 1
 *                     log = 2
 *                     exponent = 3
 *       bit 4 = Bad input error. HW halts until this is cleared.
 *       bit 5 = underflow
 *       bit 6 = overflow
 *     bits 13 - 7: ALU instance 1
 *       Format the same as ALU instance 0
 *     bits 20 - 14: ALU instance 2
 *       Format the same as ALU instance 0
 *
 *   Operand register 0:
 *     address = 0x11110004
 *       bit 7 - 0 = ‘value’ operand, ALU instance 0
 *       bit 15 - 8 = ‘base’ operand, if applicable, ALU instance 0
 *       bit 23 - 16 = ‘value’ operand, ALU instance 1
 *       bit 31 - 24 = ‘base’ operand, if applicable, ALU instance 1
 *
 *   Operand register 1:
 *     address = 0x11110008
 *       bit 7 - 0 =  ‘value’ operand, ALU instance 2
 *       bit 15 - 8 = ‘base’ operand, if applicable, ALU instance 2
 *
 *   Result register:
 *     address = 0x1111000c
 *       bit 7 - 0 = result, ALU instance 0
 *       bit 15 - 8 = result, ALU instance 1
 *       bit 23 - 16 = result, ALU instance 2
 */
// Question 1
/*
* Write separate functions to compute the below formulas using the HW accelerator. You may complete them in either order.
* 1. log(cos(y) ^ x, sin(x))
* 2. cos(y) ^ sin(x)
*
* Assume polling mode, only use ALU 0, and a single-threaded environment for now.
*/

#include <stdint.h>
#include <stdio.h>

#define CONTROL_REG_ADDR		0x11110000
#define OPERAND_REG_0_ADDR		0x11110004
#define OPERAND_REG_1_ADDR		0x11110008
#define RESULT_REG_ADDR			0x1111000c

#define CONTROL_REG		(*(volatile uint32_t *)(0x11110000))
#define OPERAND_REG_0	(*(volatile uint32_t *)(0x11110004))
#define OPERAND_REG_1	(*(volatile uint32_t *)(0x11110008))
#define RESULT_REG		(*(volatile uint32_t *)(0x1111000c))


typedef struct alu {
	uint8_t interrupt_enable :1;
	uint8_t done :1;
	uint8_t opcode :2;
	uint8_t bad_input :1;
	uint8_t underflow :1;
	uint8_t overflow :1;
} alu_t;

typedef struct control_reg {
	alu_t alu_0;
	alu_t alu_1;
	alu_t alu_2;
} volatile control_reg_t;

typedef struct input{
	uint8_t value;
	uint8_t base;
} input_t;

typedef struct operand_reg {
	input_t alu_0;
	input_t alu_1;
} volatile operand_reg_t;

typedef struct result_reg {
	uint8_t alu0_result;
	uint8_t alu1_result;
	uint8_t alu2_result;
	uint8_t reserved;
} volatile result_reg_t;

typedef enum functions {
	SINE,
	COSINE,
	LOG,
	EXPONENT,
} functions_e;


uint8_t generic_function(uint8_t value, uint8_t base,
						 functions_e func, uint8_t alu_idx) {
	uint8_t rv = 0;

	control_reg_t *cntl = (control_reg_t *)CONTROL_REG_ADDR;
	operand_reg_t *operand = NULL;

	switch (alu_idx) {
	case 0:

		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}

	cntl->alu_0.interrupt_enable = 0;
	cntl->alu_0.opcode = func;

	operand->alu_0.value = value;

	return rv;
}
