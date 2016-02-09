TARGET = pe_run
CXX = g++
CFLAGS = -g -Wall -Wextra -O2 -std=c++11
SRCDIR = ./
INCLUDES = -I../include/
OBJDIR = obj/
OUTDIR = ./
SOURCES = $(wildcard $(SRCDIR)*.cc)
OBJS = $(SOURCES:$(SRCDIR)%.cc=$(OBJDIR)%.o)

all: $(TARGET)

clean:
	-$(RM) $(OUTDIR)$(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CXX) -L../lib/ -o $(OUTDIR)$@ $(OBJS) -lpe++

$(OBJDIR)%.o: $(SRCDIR)%.cc
	$(CXX) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
