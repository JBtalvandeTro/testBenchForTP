################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/COM_Management/COM.c \
../Modules/COM_Management/COMrx.c \
../Modules/COM_Management/COMtx.c 

OBJS += \
./Modules/COM_Management/COM.o \
./Modules/COM_Management/COMrx.o \
./Modules/COM_Management/COMtx.o 

C_DEPS += \
./Modules/COM_Management/COM.d \
./Modules/COM_Management/COMrx.d \
./Modules/COM_Management/COMtx.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/COM_Management/%.o: ../Modules/COM_Management/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/COM_Management/COM.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


