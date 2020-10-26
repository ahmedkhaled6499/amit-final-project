################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
obstacle_avoidance.lss \

FLASH_IMAGE += \
obstacle_avoidance.hex \

EEPROM_IMAGE += \
obstacle_avoidance.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: obstacle_avoidance.elf secondary-outputs

# Tool invocations
obstacle_avoidance.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,obstacle_avoidance.map -mmcu=atmega16 -o "obstacle_avoidance.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

obstacle_avoidance.lss: obstacle_avoidance.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S obstacle_avoidance.elf  >"obstacle_avoidance.lss"
	@echo 'Finished building: $@'
	@echo ' '

obstacle_avoidance.hex: obstacle_avoidance.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex obstacle_avoidance.elf  "obstacle_avoidance.hex"
	@echo 'Finished building: $@'
	@echo ' '

obstacle_avoidance.eep: obstacle_avoidance.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex obstacle_avoidance.elf  "obstacle_avoidance.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: obstacle_avoidance.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 obstacle_avoidance.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) obstacle_avoidance.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
