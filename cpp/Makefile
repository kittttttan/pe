TARGET = pe++
CXX = g++
CFLAGS = -fPIC -g -Wall -Wextra -O2 -std=c++11
SRCDIR = src/
INCLUDES = -I./include/
OBJDIR = obj/
OUTDIR = lib/
SOURCES = $(wildcard $(SRCDIR)*.cc)
OBJS = $(SOURCES:$(SRCDIR)%.cc=$(OBJDIR)%.o)

all: $(TARGET)

clean:
	-$(RM) $(OBJS)

$(TARGET): $(OBJS)
	$(CXX) -shared -Wl,-soname,lib$@.so.1 -o $(OUTDIR)lib$@.so.1.0.0 $(OBJS) -lm

$(OBJDIR)%.o: $(SRCDIR)%.cc
	$(CXX) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
