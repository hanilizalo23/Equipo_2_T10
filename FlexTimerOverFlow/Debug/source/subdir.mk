################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/FlexTimer.c \
../source/NVIC.c \
../source/main.c 

OBJS += \
./source/FlexTimer.o \
./source/NVIC.o \
./source/main.o 

C_DEPS += \
./source/FlexTimer.d \
./source/NVIC.d \
./source/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MK64FN1M0VDC12 -DCPU_MK64FN1M0VDC12_cm4 -D__REDLIB__ -I"C:\Users\nelid\Documents\FTM_Bare\FTM_Bare\FlexTimerOverFlow\source" -I"C:\Users\nelid\Documents\FTM_Bare\FTM_Bare\FlexTimerOverFlow" -I"C:\Users\nelid\Documents\FTM_Bare\FTM_Bare\FlexTimerOverFlow\startup" -I"C:\Users\nelid\Documents\FTM_Bare\FTM_Bare\FlexTimerOverFlow\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


