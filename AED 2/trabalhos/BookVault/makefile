APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

GTK_FLAGS = `pkg-config --cflags --libs gtk+-3.0` -rdynamic
MULTIPLE_FLAGS = "-Wl,--allow-multiple-definition"

all: _src clean_apps _apps
 

_src: $(OBJ)/AvlBooks.o \
      $(OBJ)/error.o \
      $(OBJ)/book.o \
	  $(OBJ)/order.o \
      $(OBJ)/session.o \
      $(OBJ)/store.o \
	  $(OBJ)/AvlUser.o \
      $(OBJ)/user.o \
	  $(OBJ)/DataBaseManager.o\
	  $(OBJ)/LinkedList.o\

clean_apps:
	rm -rf $(BIN)/*

_apps: $(BIN)/BookVault

clean:
	rm -f $(OBJ)/*

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@ $(GTK_FLAGS) $(MULTIPLE_FLAGS)

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(GTK_FLAGS) $(MULTIPLE_FLAGS)

a:
	rm -rf _luis/*
	cp -rf * _luis/
