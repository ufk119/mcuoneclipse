/*
 * platform.c
 *
 *  Created on: 20.04.2019
 *      Author: Erich Styger
 */
#include "Platform.h"
#include "initPins.h"
#include "McuLib.h"
#include "McuRTOS.h"
#include "McuUtility.h"
#include "McuWait.h"
#include "McuArmTools.h"
#include "McuCriticalSection.h"
#include "McuRB.h"
#include "McuGenericI2C.h"
#include "McuGenericSWI2C.h"
#include "McuSSD1306.h"
#include "McuGPIO.h"
#include "McuLED.h"
#include "oled.h"
#include "McuRTT.h"
#include "McuSystemView.h"
#include "McuXFormat.h"
#include "McuButton.h"
#include "McuDebounce.h"
#include "McuI2CSpy.h"
#include "i2clib.h"
#include "virtual_com.h"

void PL_Init(void) {
  InitPins(); /* do all the pin muxing */

  /* initialize McuLib modules */
  McuLib_Init();
  McuRTOS_Init();
  McuUtility_Init();
  McuWait_Init();
  McuArmTools_Init();
  McuCriticalSection_Init();
  McuRB_Init();
  McuXFormat_Init();
#if PL_CONFIG_USE_I2C
  McuGenericI2C_Init();
#if PL_CONFIG_USE_HW_I2C
  I2CLIB_Init();
#else
  McuGenericSWI2C_Init();
#endif
  McuI2CSpy_Init();
#endif
#if PL_CONFIG_USE_OLED
  McuSSD1306_Init();
#endif
  McuRTT_Init();
#if configUSE_SEGGER_SYSTEM_VIEWER_HOOKS
  McuSystemView_Init();
#endif
  McuGPIO_Init();
  McuLED_Init();
  McuBtn_Init();
  McuDbnc_Init();

  /* initialize my own modules */
#if PL_CONFIG_USE_OLED
  OLED_Init(); /* initializes the needed McuLib components for the OLED */
#endif
#if PL_CONFIG_USE_USB_CDC
  USB_APPInit();
#endif
}

void PL_Deinit(void) {
  /*! \todo */
}
