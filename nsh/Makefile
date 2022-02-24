
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

ifeq ($(TRANSPORT),SERIAL)
CFLAGS+=-D__SERIAL__
ADDSRCS := $(shell find src/serial -name *.cpp -or -name *.c -or -name *.asm)
else
CFLAGS+=-D__ADAMNET__
ADDSRCS := $(shell find src/adamnet -name *.cpp -or -name *.c -or -name *.asm)
endif

ifeq ($(PLATFORM),UNIX)
TARGET_EXEC ?= nsh
CC=cc -g -o $(TARGET_EXEC)
CFLAGS+=-D__UNIX__
else
TARGET_EXEC ?= nsh.com
CC=zcc
CFLAGS=+cpm -subtype=adam -D__CPM__ 
LDFLAGS=+cpm -subtype=adam -o$(TARGET_EXEC) -create-app -lfujicpm
endif

SRCS += $(ADDSRCS) $(shell find $(SRC_DIRS) -depth 1 \( -name *.cpp -or -name *.c -or -name *.asm \) )
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)


INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

ifeq ($(PLATFORM),UNIX)
all: $(BUILD_DIR)/$(TARGET_EXEC)
else
all: $(BUILD_DIR)/$(TARGET_EXEC)
	cp nsh.img ../../tnfs/nsh.dsk
endif

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# asm source
$(BUILD_DIR)/%.asm.o: %.asm
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r nsh* $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p

test:
	-echo $(ADDSRCS)
	-echo $(SRCS)
