/*!
 * \file     CTB_dsiodef.h
 * \brief    defines the pins of the DSI/O and their modes
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef CTB_CTB_DSIODEF_H_
#define CTB_CTB_DSIODEF_H_

#include "Port.h"

#define DSI_PBIT1_PIN       PortConfigSet_DSI_DSI_PBIT1 // Hpp Maint
#define DSI_PBIT2_PIN       PortConfigSet_DSI_DSI_PBIT2 // Spare 1
#define DSI_PBIT3_PIN       PortConfigSet_DSI_DSI_PBIT3 // Spare 2
#define DSI_PBIT4_PIN       PortConfigSet_DSI_DSI_PBIT4 // EMER_STOP
#define DSI_PBIT5_PIN       PortConfigSet_DSI_DSI_PBIT5 // Hpp1
#define DSI_PBIT6_PIN       PortConfigSet_DSI_DSI_PBIT6 // Hpp2

#define DSI_CPU1_PIN        PortConfigSet_DSI_DSI_CPU1
#define DSI_CPU2_PIN        PortConfigSet_DSI_DSI_CPU2
#define DSI_CPU3_PIN        PortConfigSet_DSI_DSI_CPU3
#define DSI_CPU4_PIN        PortConfigSet_DSI_DSI_CPU4
#define DSI_CPU5_PIN        PortConfigSet_DSI_DSI_CPU5
#define DSI_CPU6_PIN        PortConfigSet_DSI_DSI_CPU6

#define DSO_CPU1_PIN        PortConfigSet_DSO_DSO_CPU1
#define DSO_CPU2_PIN        PortConfigSet_DSO_DSO_CPU2

#define DSI_PBIT1_GPIO_MODE  PORT112_GPIO
#define DSI_PBIT1_PWM_MODE   PORT112_FTM0_CH1

#define DSI_PBIT2_GPIO_MODE  PORT113_GPIO
#define DSI_PBIT2_PWM_1MODE   PORT113_FTM0_FTL2 // this mode isn't used beceause the placing of the pin is wrong in the schematics

#define DSI_PBIT3_GPIO_MODE  PORT114_GPIO
#define DSI_PBIT3_PWM_MODE   PORT114_FTM5_CH7

#define DSI_PBIT4_GPIO_MODE  PORT115_GPIO
#define DSI_PBIT4_PWM_MODE   PORT115_FTM6_CH0

#define DSI_PBIT5_GPIO_MODE  PORT116_GPIO
#define DSI_PBIT5_PWM_MODE   PORT116_FTM6_CH1

#define DSI_PBIT6_GPIO_MODE  PORT117_GPIO
#define DSI_PBIT6_PWM_MODE   PORT117_FTM6_CH2

#define DSI_CPU2_GPIO_MODE   PORT138_GPIO
#define DSI_CPU2_ICU_MODE    PORT138_FTM2_CH4

#define DSI_CPU3_GPIO_MODE   PORT139_GPIO
#define DSI_CPU3_ICU_MODE    PORT139_FTM2_CH5

#define DSO_CPU1_GPIO_MODE   PORT120_GPIO
#define DSO_CPU1_PWM_MODE    PORT120_FTM6_CH5

#define DSO_CPU2_GPIO_MODE   PORT121_GPIO
#define DSO_CPU2_PWM_MODE    PORT121_FTM6_CH6

#endif /* CTB_CTB_DSIODEF_H_ */
