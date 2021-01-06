CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -g -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 # use '-g' to build DWARF debuggin information into binary code
LDFLAGS= --specs=nano.specs -T stm32_ls.ld -Wl,-Map=final.map #use -Wl to tell 'arm-none-eabi-gcc' that -Map=final.map is a linker command, which is supposed to be used with arm-none-eabi-ld. The --spec=nano.specs will link your project with newlib_nano library.in arm-none-eabi tool chain

all: main.o

clean:
	rm -rf *.o *elf

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@
