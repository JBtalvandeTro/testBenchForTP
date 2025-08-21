################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/WDO_Management/WDO.c 

OBJS += \
./Middlewares/WDO_Management/WDO.o 

C_DEPS += \
./Middlewares/WDO_Management/WDO.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/WDO_Management/%.o: ../Middlewares/WDO_Management/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Middlewares/WDO_Management/WDO.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


