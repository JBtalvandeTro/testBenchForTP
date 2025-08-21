################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SCHeduler/SCH.c 

OBJS += \
./SCHeduler/SCH.o 

C_DEPS += \
./SCHeduler/SCH.d 


# Each subdirectory must supply rules for building sources it contributes
SCHeduler/SCH.o: ../SCHeduler/SCH.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SCHeduler/SCH.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"SCHeduler/SCH.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


