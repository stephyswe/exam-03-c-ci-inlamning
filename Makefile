PROG=programmet.exe
TEST=check.exe
SOURCES=main.c calculator.c shapes.c input.c shapesfunc.c game.c gamefunc.c
DEPS=shapes.h calculator.h input.h game.h gamefunc.h
CC=gcc
CFLAGS=-Wall -Werror
DEBUG?=1
GTEST = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=programmet-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif

OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@del /q "$(OUTPUTDIR)"
	@del /q $(PROG) $(TEST)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

$(TEST): input.o TestShapes.o calculator.o shapesfunc.o game.o TestCalc.o TestGame.o gamefunc.o
	g++ -o $@ $^ $(CFLAGS) -I $(GTEST) $(LIBGTEST)

test: $(TEST)
	./$(TEST)

$(OUTPUTDIR)/TestCalc.o: TestCalc.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OUTPUTDIR)/TestGame.o: TestGame.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean test