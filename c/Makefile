TARGET = pe
CC = gcc
CFLAGS = -fPIC -g -Wall -Wextra -O2 -std=c11
SRCDIR = src/
INCLUDES = -I./include/
OBJDIR = obj/
OUTDIR = lib/
SOURCES = $(wildcard $(SRCDIR)*.c)
OBJS = $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

all: $(TARGET)

clean:
	-$(RM) $(OBJS)

$(TARGET): $(OBJS)
	$(CC) -shared -Wl,-soname,lib$@.so.1 -o $(OUTDIR)lib$@.so.1.0.0 $(OBJS) -lm

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
