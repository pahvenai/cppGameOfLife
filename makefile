  CC = g++

  # compiler flags:
  CFLAGS  = #-g -Wall

  # the build target executable:
  TARGET = Conway

  all: $(TARGET)

  $(TARGET):	main.cpp Conway.o Grid.o dataTypes.h Grid.h Conway.h
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp Conway.o Grid.o

  Conway.o:  Conway.cpp dataTypes.h Grid.o Grid.h Conway.h
	$(CC) $(CFLAGS) -c Conway.cpp Grid.o

  Grid.o:  Grid.cpp dataTypes.h Grid.h
	$(CC) $(CFLAGS) -c Grid.cpp

  clean:
	$(RM) $(TARGET) Conway.o Grid.o
