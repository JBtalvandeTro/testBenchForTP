################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modules/PWB/PWB.c \
../Modules/PWB/PWBCbit.c \
../Modules/PWB/PWBPbit.c \
../Modules/PWB/PWBio.c 

OBJS += \
./Modules/PWB/PWB.o \
./Modules/PWB/PWBCbit.o \
./Modules/PWB/PWBPbit.o \
./Modules/PWB/PWBio.o 

C_DEPS += \
./Modules/PWB/PWB.d \
./Modules/PWB/PWBCbit.d \
./Modules/PWB/PWBPbit.d \
./Modules/PWB/PWBio.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/PWB/%.o: ../Modules/PWB/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Modules/PWB/PWB.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


