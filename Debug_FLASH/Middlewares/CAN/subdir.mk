################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/CAN/CBUctrl.c \
../Middlewares/CAN/CBUinter.c \
../Middlewares/CAN/CBUmaint.c \
../Middlewares/CAN/CBUs.c 

OBJS += \
./Middlewares/CAN/CBUctrl.o \
./Middlewares/CAN/CBUinter.o \
./Middlewares/CAN/CBUmaint.o \
./Middlewares/CAN/CBUs.o 

C_DEPS += \
./Middlewares/CAN/CBUctrl.d \
./Middlewares/CAN/CBUinter.d \
./Middlewares/CAN/CBUmaint.d \
./Middlewares/CAN/CBUs.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/CAN/%.o: ../Middlewares/CAN/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Middlewares/CAN/CBUctrl.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


