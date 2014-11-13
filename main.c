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

int main()
{
	//MAP_IntMasterEnable();
	//MAP_IntEnable(FAULT_SYSTICK);
	PRCMCC3200MCUInit();
}
