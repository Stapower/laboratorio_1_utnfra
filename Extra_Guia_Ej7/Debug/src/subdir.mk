################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Test_C.c \
../src/arrayList.c \
../src/main.c \
../src/mylib.c 

OBJS += \
./src/Test_C.o \
./src/arrayList.o \
./src/main.o \
./src/mylib.o 

C_DEPS += \
./src/Test_C.d \
./src/arrayList.d \
./src/main.d \
./src/mylib.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


