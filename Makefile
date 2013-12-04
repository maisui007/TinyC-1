####################################################################
#	
# Marcos Rivas R 1181599
#
# File name:    Makefile
#
# Description:  Flex Makefile
#
#   
####################################################################
#
# Define the compiler optimization flags
#
COPT    = -O2
COPT2   = -Wall -O2
CDBG    = -g -DDEBUG
CC      = gcc
LEX     = flex
YACC    = bison
ECHO    = echo
#
# Define the target names
#
TARGET_LEX = tinyC.l
TARGET_BISON = tinyC.y
TARGET_GRAM = tinyC_grammar.y
TARGET_NAME= tinyC
TARGET_TABLE= SymbolTable.h
#
# Rule definitions for target builds
#

all:
	$(YACC) -v $(TARGET_BISON)
	$(LEX) $(TARGET_LEX)
	$(CC) $(COPT2) -o $(TARGET_NAME) -DYACC $(TARGET_NAME).tab.c -ll

debug:
	$(YACC) -v $(TARGET_BISON)
	$(LEX) $(TARGET_LEX)
	$(CC) -DDEBUG $(COPT) -o $(TARGET_NAME) -DYACC $(TARGET_NAME).tab.c -ll

clean:
	rm -f *~ core lex.yy.c $(TARGET_NAME).tab.* $(TARGET_NAME).output

clobber: clean
	rm -f $(TARGET_NAME)
