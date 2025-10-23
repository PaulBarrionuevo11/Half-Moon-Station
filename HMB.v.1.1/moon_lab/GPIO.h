#ifndef MAIN_H_
#define MAIN_H_

#include<stdint.h>

// Adjust address and matrice
#define ADD_REG_AHB1ENR		((RCC_AHB1ENR_t*)0x40023830)
#define ADD_GPIOA_MODE		((GPIOx_MODE_t*)0x40020000)
#define ADD_GPIOA_OUT		((GPIOx_ODR_t*)0x40020014)
#define TIME_DELAY			(300000UL)
#define CLOCK_EN			(1)
#define MODE_CONF_OUTPUT	(1)
#define PIN_STATE_HIGH		(1)
#define PIN_STATE_LOW		(0)

typedef struct
{
	uint32_t gpioa_en:1;
	uint32_t gpiob_en:1;
	uint32_t gpioc_en:1;
	uint32_t gpiod_en:1;

} RCC_AHB1ENR_t;

typedef struct
{
	uint32_t pin_0:2;
	uint32_t pin_1:2;
	uint32_t pin_2:2;
	uint32_t pin_3:2;

} GPIOx_MODE_t;

typedef struct
{
	uint32_t pin_0:1;
	uint32_t pin_1:1;
	uint32_t pin_2:1;
	uint32_t pin_3:1;

} GPIOx_ODR_t;

class GPIOx_MODE_t

{
    private:
        volatile GPIOx_MODE_t* const modeReg;
        volatile GPIOx_ODR_t* const odrReg;
        uint32_t pin;
    public:


}

#endif /* MAIN_H_ */
