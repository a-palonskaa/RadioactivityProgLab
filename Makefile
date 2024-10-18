CC = gcc
CFLAGS =
LDFLAGS =

INCLUDE_DIR = include
SOURCE_DIR  = src
BUILD_DIR   = build

SOURCES = experiment.c linear_equation.c lab.c add_noise.c deviations.c precision_analysis.c nonlinear_equation.c
SOURCES := $(addprefix $(SOURCE_DIR)/, $(SOURCES))

OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:%.c=%.o))
DEPS 	= $(OBJECTS:.o=.d)

CFLAGS += -I$(INCLUDE_DIR)

EXECUTABLE = $(BUILD_DIR)/exp

.PHONY: all

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(LDFLAGS) $^ -o $@

$(OBJECTS): $(BUILD_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DEPS): $(BUILD_DIR)/%.d: %.c
	@mkdir -p $(@D)
	@$(CC) -E $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@

.PHONY: clean
clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(DEPS)

NODEPS = clean

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
-include $(DEPS)
endif
