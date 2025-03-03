# Set compiler
CC = gcc

# Set name for the executable
SERVER_NAME = server
SERVER_PATH = server.c

CLIENT_NAME = client
CLIENT_PATH = client.c


# Directories
BUILD = build
SRC = src

# Flags for compiling
DEBUG_CFLAGS = -Wall -g
RELEASE_CFLAGS =
LDFLAGS = -lcjson

# Get all the source files in the SRC directory and its subdirectories
SRCFILES = $(shell find $(SRC) -name '*.c')

# Generate object file names from source file names
OBJFILES = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCFILES))

.PHONY: debug release clean

# Target to build the executable with debug flags
debug: CFLAGS = $(DEBUG_CFLAGS)
debug: $(OBJFILES)
	@echo "Building Client and Server in debug mode"
	@$(CC) $(CFLAGS) $(SERVER_PATH) $^ -o $(SERVER_NAME) $(LDFLAGS)
	@$(CC) $(CFLAGS) $(CLIENT_PATH) $^ -o $(CLIENT_NAME) $(LDFLAGS)
	@echo "Done!"


# Target to build the executable with release flags
build_release: CFLAGS = $(RELEASE_CFLAGS)
build_release: $(OBJFILES)
	@echo "Building Client and Server in release mode"
	@$(CC) $(CFLAGS) $(SERVER_PATH) $^ -o $(SERVER_NAME) $(LDFLAGS)
	@$(CC) $(CFLAGS) $(CLIENT_PATH) $^ -o $(CLIENT_NAME) $(LDFLAGS)
	@echo "Done!"

# To clean out debug code
release:
	@$(MAKE) clean --no-print-directory
	@$(MAKE) build_release --no-print-directory


# Rule to compile each source file into an object file
$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

# Target to clean up generated file
clean:
	@rm -rf $(OBJFILES) $(CLIENT_NAME) $(SERVER_NAME)
