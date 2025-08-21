################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generate/src/CDD_Mcl_Cfg.c \
../generate/src/CDD_Mcl_Init_PBcfg.c \
../generate/src/CDD_Rm_Cfg.c \
../generate/src/CDD_Rm_Init_PBcfg.c \
../generate/src/CDD_Rm_Ipw_Init_PBcfg.c \
../generate/src/Can_Init_PBcfg.c \
../generate/src/Can_Ipw_Init_PBcfg.c \
../generate/src/Clock_Ip_Cfg.c \
../generate/src/Clock_Ip_Init_PBcfg.c \
../generate/src/Cmp_Ip_Init_PBcfg.c \
../generate/src/Crc_Cfg.c \
../generate/src/Crc_Ip_Cfg.c \
../generate/src/Crypto_Cfg.c \
../generate/src/Dio_Cfg.c \
../generate/src/Dma_Ip_Cfg.c \
../generate/src/Dma_Ip_Init_PBcfg.c \
../generate/src/FlexCAN_Ip_Init_PBcfg.c \
../generate/src/Flexio_Mcl_Ip_Init_PBcfg.c \
../generate/src/Flexio_Pwm_Ip_Init_PBcfg.c \
../generate/src/Flexio_Spi_Ip_Init_PBcfg.c \
../generate/src/Fls_Cfg.c \
../generate/src/Fls_Init_PBcfg.c \
../generate/src/Ftfc_Fls_Ip_Init_PBcfg.c \
../generate/src/Ftm_Gpt_Ip_Init_PBcfg.c \
../generate/src/Ftm_Icu_Ip_Init_PBcfg.c \
../generate/src/Ftm_Pwm_Ip_Init_PBcfg.c \
../generate/src/Gpt_Cfg.c \
../generate/src/Gpt_Init_PBcfg.c \
../generate/src/Gpt_Ipw_Init_PBcfg.c \
../generate/src/Icu_Cfg.c \
../generate/src/Icu_DmaNotification.c \
../generate/src/Icu_Init_PBcfg.c \
../generate/src/Icu_Ipw_Init_PBcfg.c \
../generate/src/LPit_Gpt_Ip_Init_PBcfg.c \
../generate/src/Lpit_Icu_Ip_Init_PBcfg.c \
../generate/src/Lpspi_Ip_Init_PBcfg.c \
../generate/src/Lptmr_Gpt_Ip_Init_PBcfg.c \
../generate/src/Lptmr_Icu_Ip_Init_PBcfg.c \
../generate/src/Mcu_Cfg.c \
../generate/src/Mcu_Init_PBcfg.c \
../generate/src/Mpu_Ip_Init_PBcfg.c \
../generate/src/OsIf_Cfg.c \
../generate/src/Platform_Cfg.c \
../generate/src/Platform_Ipw_Cfg.c \
../generate/src/Port_Cfg.c \
../generate/src/Port_Ci_Icu_Ip_Init_PBcfg.c \
../generate/src/Port_Ci_Port_Ip_Init_PBcfg.c \
../generate/src/Port_Init_PBcfg.c \
../generate/src/Power_Ip_Cfg.c \
../generate/src/Power_Ip_Init_PBcfg.c \
../generate/src/Pwm_Init_PBcfg.c \
../generate/src/Qspi_Ip_Init_PBcfg.c \
../generate/src/Ram_Ip_Cfg.c \
../generate/src/Ram_Ip_Init_PBcfg.c \
../generate/src/SRtc_Ip_Init_PBcfg.c \
../generate/src/Spi_Init_PBcfg.c \
../generate/src/Spi_Ipw_Init_PBcfg.c \
../generate/src/Trgmux_Ip_Cfg.c \
../generate/src/Trgmux_Ip_Init_PBcfg.c \
../generate/src/Wdg_43_Instance0_Cfg.c \
../generate/src/Wdg_43_Instance0_Init_PBcfg.c \
../generate/src/Wdg_43_Instance0_Ipw_Init_PBcfg.c \
../generate/src/Wdg_CfgExt.c \
../generate/src/Wdog_Ip_Init_PBcfg.c 

OBJS += \
./generate/src/CDD_Mcl_Cfg.o \
./generate/src/CDD_Mcl_Init_PBcfg.o \
./generate/src/CDD_Rm_Cfg.o \
./generate/src/CDD_Rm_Init_PBcfg.o \
./generate/src/CDD_Rm_Ipw_Init_PBcfg.o \
./generate/src/Can_Init_PBcfg.o \
./generate/src/Can_Ipw_Init_PBcfg.o \
./generate/src/Clock_Ip_Cfg.o \
./generate/src/Clock_Ip_Init_PBcfg.o \
./generate/src/Cmp_Ip_Init_PBcfg.o \
./generate/src/Crc_Cfg.o \
./generate/src/Crc_Ip_Cfg.o \
./generate/src/Crypto_Cfg.o \
./generate/src/Dio_Cfg.o \
./generate/src/Dma_Ip_Cfg.o \
./generate/src/Dma_Ip_Init_PBcfg.o \
./generate/src/FlexCAN_Ip_Init_PBcfg.o \
./generate/src/Flexio_Mcl_Ip_Init_PBcfg.o \
./generate/src/Flexio_Pwm_Ip_Init_PBcfg.o \
./generate/src/Flexio_Spi_Ip_Init_PBcfg.o \
./generate/src/Fls_Cfg.o \
./generate/src/Fls_Init_PBcfg.o \
./generate/src/Ftfc_Fls_Ip_Init_PBcfg.o \
./generate/src/Ftm_Gpt_Ip_Init_PBcfg.o \
./generate/src/Ftm_Icu_Ip_Init_PBcfg.o \
./generate/src/Ftm_Pwm_Ip_Init_PBcfg.o \
./generate/src/Gpt_Cfg.o \
./generate/src/Gpt_Init_PBcfg.o \
./generate/src/Gpt_Ipw_Init_PBcfg.o \
./generate/src/Icu_Cfg.o \
./generate/src/Icu_DmaNotification.o \
./generate/src/Icu_Init_PBcfg.o \
./generate/src/Icu_Ipw_Init_PBcfg.o \
./generate/src/LPit_Gpt_Ip_Init_PBcfg.o \
./generate/src/Lpit_Icu_Ip_Init_PBcfg.o \
./generate/src/Lpspi_Ip_Init_PBcfg.o \
./generate/src/Lptmr_Gpt_Ip_Init_PBcfg.o \
./generate/src/Lptmr_Icu_Ip_Init_PBcfg.o \
./generate/src/Mcu_Cfg.o \
./generate/src/Mcu_Init_PBcfg.o \
./generate/src/Mpu_Ip_Init_PBcfg.o \
./generate/src/OsIf_Cfg.o \
./generate/src/Platform_Cfg.o \
./generate/src/Platform_Ipw_Cfg.o \
./generate/src/Port_Cfg.o \
./generate/src/Port_Ci_Icu_Ip_Init_PBcfg.o \
./generate/src/Port_Ci_Port_Ip_Init_PBcfg.o \
./generate/src/Port_Init_PBcfg.o \
./generate/src/Power_Ip_Cfg.o \
./generate/src/Power_Ip_Init_PBcfg.o \
./generate/src/Pwm_Init_PBcfg.o \
./generate/src/Qspi_Ip_Init_PBcfg.o \
./generate/src/Ram_Ip_Cfg.o \
./generate/src/Ram_Ip_Init_PBcfg.o \
./generate/src/SRtc_Ip_Init_PBcfg.o \
./generate/src/Spi_Init_PBcfg.o \
./generate/src/Spi_Ipw_Init_PBcfg.o \
./generate/src/Trgmux_Ip_Cfg.o \
./generate/src/Trgmux_Ip_Init_PBcfg.o \
./generate/src/Wdg_43_Instance0_Cfg.o \
./generate/src/Wdg_43_Instance0_Init_PBcfg.o \
./generate/src/Wdg_43_Instance0_Ipw_Init_PBcfg.o \
./generate/src/Wdg_CfgExt.o \
./generate/src/Wdog_Ip_Init_PBcfg.o 

C_DEPS += \
./generate/src/CDD_Mcl_Cfg.d \
./generate/src/CDD_Mcl_Init_PBcfg.d \
./generate/src/CDD_Rm_Cfg.d \
./generate/src/CDD_Rm_Init_PBcfg.d \
./generate/src/CDD_Rm_Ipw_Init_PBcfg.d \
./generate/src/Can_Init_PBcfg.d \
./generate/src/Can_Ipw_Init_PBcfg.d \
./generate/src/Clock_Ip_Cfg.d \
./generate/src/Clock_Ip_Init_PBcfg.d \
./generate/src/Cmp_Ip_Init_PBcfg.d \
./generate/src/Crc_Cfg.d \
./generate/src/Crc_Ip_Cfg.d \
./generate/src/Crypto_Cfg.d \
./generate/src/Dio_Cfg.d \
./generate/src/Dma_Ip_Cfg.d \
./generate/src/Dma_Ip_Init_PBcfg.d \
./generate/src/FlexCAN_Ip_Init_PBcfg.d \
./generate/src/Flexio_Mcl_Ip_Init_PBcfg.d \
./generate/src/Flexio_Pwm_Ip_Init_PBcfg.d \
./generate/src/Flexio_Spi_Ip_Init_PBcfg.d \
./generate/src/Fls_Cfg.d \
./generate/src/Fls_Init_PBcfg.d \
./generate/src/Ftfc_Fls_Ip_Init_PBcfg.d \
./generate/src/Ftm_Gpt_Ip_Init_PBcfg.d \
./generate/src/Ftm_Icu_Ip_Init_PBcfg.d \
./generate/src/Ftm_Pwm_Ip_Init_PBcfg.d \
./generate/src/Gpt_Cfg.d \
./generate/src/Gpt_Init_PBcfg.d \
./generate/src/Gpt_Ipw_Init_PBcfg.d \
./generate/src/Icu_Cfg.d \
./generate/src/Icu_DmaNotification.d \
./generate/src/Icu_Init_PBcfg.d \
./generate/src/Icu_Ipw_Init_PBcfg.d \
./generate/src/LPit_Gpt_Ip_Init_PBcfg.d \
./generate/src/Lpit_Icu_Ip_Init_PBcfg.d \
./generate/src/Lpspi_Ip_Init_PBcfg.d \
./generate/src/Lptmr_Gpt_Ip_Init_PBcfg.d \
./generate/src/Lptmr_Icu_Ip_Init_PBcfg.d \
./generate/src/Mcu_Cfg.d \
./generate/src/Mcu_Init_PBcfg.d \
./generate/src/Mpu_Ip_Init_PBcfg.d \
./generate/src/OsIf_Cfg.d \
./generate/src/Platform_Cfg.d \
./generate/src/Platform_Ipw_Cfg.d \
./generate/src/Port_Cfg.d \
./generate/src/Port_Ci_Icu_Ip_Init_PBcfg.d \
./generate/src/Port_Ci_Port_Ip_Init_PBcfg.d \
./generate/src/Port_Init_PBcfg.d \
./generate/src/Power_Ip_Cfg.d \
./generate/src/Power_Ip_Init_PBcfg.d \
./generate/src/Pwm_Init_PBcfg.d \
./generate/src/Qspi_Ip_Init_PBcfg.d \
./generate/src/Ram_Ip_Cfg.d \
./generate/src/Ram_Ip_Init_PBcfg.d \
./generate/src/SRtc_Ip_Init_PBcfg.d \
./generate/src/Spi_Init_PBcfg.d \
./generate/src/Spi_Ipw_Init_PBcfg.d \
./generate/src/Trgmux_Ip_Cfg.d \
./generate/src/Trgmux_Ip_Init_PBcfg.d \
./generate/src/Wdg_43_Instance0_Cfg.d \
./generate/src/Wdg_43_Instance0_Init_PBcfg.d \
./generate/src/Wdg_43_Instance0_Ipw_Init_PBcfg.d \
./generate/src/Wdg_CfgExt.d \
./generate/src/Wdog_Ip_Init_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
generate/src/%.o: ../generate/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@generate/src/CDD_Mcl_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


