# ==========================================
#   Collection of Algorithms makefile
#   Copyright (c) 2016 Zeyuan Hu
#   Modified based upon Unity Project makefile
# ==========================================

# We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OSTYPE),cygwin)
  CLEANUP = rm -f
  MKDIR = mkdir -p
  TARGET_EXTENSION=.out
elseifeq ($(OSTYPE),msys)
  CLEANUP = rm -f
  MKDIR = mkdir -p
  TARGET_EXTENSION=.exe
elseifeq ($(OS),Windows_NT)
  CLEANUP = del /F /Q
  MKDIR = mkdir
  TARGET_EXTENSION=.exe
else
  CLEANUP = rm -f
  MKDIR = mkdir -p
  TARGET_EXTENSION=.out
endif

# Directories
PATHU = unity/
PATHS = src/
PATHT = test/

# gcc & flags
C_COMPILER=gcc
CFLAGS = -Wall

# supplements to gcc commands
TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
INC_DIRS=\
  -I$(PATHU) \
  -I$(PATHT) \
  -I$(PATHT)testModule1 \
  -I$(PATHT)testUtility \
  -I$(PATHS)module1 \
  -I$(PATHS)utility \
  -I$(PATHS) \

SRC_FILES1=\
  $(wildcard $(PATHU)*.c) \
  $(wildcard $(PATHT)*.c) \
  $(wildcard $(PATHT)*/*.c) \
  $(wildcard $(PATHS)*.c) \
  $(wildcard $(PATHS)*/*.c) \



.PHONY: clean
.PHONY: test

test:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1) -v

clean:
	$(CLEANUP) *$(TARGET_EXTENSION)
