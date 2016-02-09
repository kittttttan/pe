TARGET = pe_run
CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11 -O2
SRCDIR = ./
INCLUDES = -I../include/
OBJDIR = obj/
OUTDIR = ./
SOURCES = $(wildcard $(SRCDIR)*.c)
OBJS = $(SOURCES:$(SRCDIR)%.c=$(OBJDIR)%.o)

all: $(TARGET)

clean:
	-$(RM) $(OUTDIR)$(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CC) -L../lib/ -o $(OUTDIR)$@ $(OBJS) -lpe

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
