#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_apps_rcm.h"
#include "inc/hw_gprcm.h"
#include "inc/hw_hib1p2.h"
#include "inc/hw_hib3p3.h"
#include "prcm.h"
#include "interrupt.h"
#include "cpu.h"
#include "flash.h"
#include "utils.h"
#include "pin.h"
#include "gpio.h"
#include "rom.h"
#include "rom_map.h"

#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "interrupt.h"
#include "hw_apps_rcm.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "prcm.h"
#include "gpio.h"
#include "utils.h"

// Common interface includes
#include "gpio_if.h"


PinMuxConfig(void)
{
    //
    // Enable Peripheral Clocks 
    //
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);

    //
    // Configure PIN_64 for GPIOOutput
    //
    MAP_PinTypeGPIO(PIN_64, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x2, GPIO_DIR_MODE_OUT);

    //
    // Configure PIN_01 for GPIOOutput
    //
    MAP_PinTypeGPIO(PIN_01, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x4, GPIO_DIR_MODE_OUT);

    //
    // Configure PIN_02 for GPIOOutput
    //
    MAP_PinTypeGPIO(PIN_02, PIN_MODE_0, false);
    MAP_GPIODirModeSet(GPIOA1_BASE, 0x8, GPIO_DIR_MODE_OUT);
}

void blink()
{
    while(1)
    {
        //
        // Alternately toggle hi-low each of the GPIOs
        // to switch the corresponding LED on/off.
        //
        MAP_UtilsDelay(1000000);
        GPIO_IF_LedOn(MCU_RED_LED_GPIO);
        MAP_UtilsDelay(1000000);
        GPIO_IF_LedOff(MCU_RED_LED_GPIO);
        MAP_UtilsDelay(1000000);
        GPIO_IF_LedOn(MCU_ORANGE_LED_GPIO);
        MAP_UtilsDelay(1000000);
        GPIO_IF_LedOff(MCU_ORANGE_LED_GPIO);
        MAP_UtilsDelay(1000000);
        GPIO_IF_LedOn(MCU_GREEN_LED_GPIO);
        MAP_UtilsDelay(1000000);
        GPIO_IF_LedOff(MCU_GREEN_LED_GPIO);
    }

}

int main()
{
	MAP_IntMasterEnable();
	MAP_IntEnable(FAULT_SYSTICK);
	PRCMCC3200MCUInit();

	PinMuxConfig();
	GPIO_IF_LedConfigure(LED1|LED2|LED3);
	GPIO_IF_LedOff(MCU_ALL_LED_IND);

	blink();
}
