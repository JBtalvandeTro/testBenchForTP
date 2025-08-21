################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/FSM/FSM.c \
../Modules/FSM/FSMupdat.c 

OBJS += \
./Modules/FSM/FSM.o \
./Modules/FSM/FSMupdat.o 

C_DEPS += \
./Modules/FSM/FSM.d \
./Modules/FSM/FSMupdat.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/FSM/%.o: ../Modules/FSM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/FSM/FSM.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


