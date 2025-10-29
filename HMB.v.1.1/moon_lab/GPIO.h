#ifndef GPIO_H_
#define GPIO_H_

#include<stdint.h>

// ESP32 WROOM GPIO Address Matrix Register

#define GPIO_BASE_ADDR      0x3FF44000
#define GPIO_OUT_REG_ADDR   (GPIO_BASE_ADDR + 0x04)
#define GPIO_OUT_W1TS_ADDR  (GPIO_BASE_ADDR + 0x08)
#define GPIO_OUT_W1TC_ADDR  (GPIO_BASE_ADDR + 0x0C)
#define GPIO_IN_REG_ADDR    (GPIO_BASE_ADDR + 0x3C)

#define PIN_STATE_HIGH			(1)
#define PIN_STATE_LOW			(0)
#define TIME_DELAY				(100000UL)

typedef struct
{
	uint32_t pin_0:1;
	uint32_t pin_1:1;
	uint32_t pin_2:1;
	uint32_t pin_3:1;
	uint32_t pin_4:1;
	uint32_t pin_5:1;
	uint32_t pin_6:1;
	uint32_t pin_7:1;
	uint32_t pin_8:1;
	uint32_t pin_9:1;
	uint32_t pin_10:1;	
	uint32_t pin_11:1;
	uint32_t pin_12:1;
	uint32_t pin_13:1;
	uint32_t pin_14:1;
	uint32_t pin_15:1;	
	uint32_t pin_16:1;
	uint32_t pin_17:1;
	uint32_t pin_18:1;
	uint32_t pin_19:1;
	uint32_t pin_20:1;
	uint32_t pin_21:1;
	uint32_t pin_22:1;
	uint32_t pin_23:1;
	uint32_t pin_24:1;
	uint32_t pin_25:1;	
	uint32_t pin_26:1;
	uint32_t pin_27:1;
	uint32_t pin_28:1;
	uint32_t pin_29:1;
	uint32_t pin_30:1;
	uint32_t pin_31:1;

} GPIO_IO_REG;

class GPIO

{
	public:	
		GPIO(uint8_t pinNumber);
		uint8_t read_pin();
		void write_pin(uint8_t state);

    private:
		uint32_t pin;
		
};

#endif // GPIO_H_
