PROJECT = f103_blinky_timer
BUILD_DIR = obj

SHARED_DIR = ../common-libs
CFILES = blink_timer.c delay_tim6.h

# Bluepill 64kB config
DEVICE=stm32f103c8
# TBD later
#OOCD_FILE = board/stm32f4discovery.cfg

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk

.PHONY: project

project: all $(PROJECT).lss $(PROJECT).elf
	arm-none-eabi-size $(PROJECT).elf

