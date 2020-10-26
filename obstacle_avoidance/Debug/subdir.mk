################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../IR.c \
../LCD_16x2_H_file.c \
../UART.c \
../main.c \
../motors_pwm.c 

OBJS += \
./IR.o \
./LCD_16x2_H_file.o \
./UART.o \
./main.o \
./motors_pwm.o 

C_DEPS += \
./IR.d \
./LCD_16x2_H_file.d \
./UART.d \
./main.d \
./motors_pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


