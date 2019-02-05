  CC = g++

  # compiler flags:
  CFLAGS  = #-g -Wall

  # the build target executable:
  TARGET = Conway

  all: $(TARGET)

  $(TARGET):	main.cpp Conway.o dataTypes.h 
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp Conway.o 

  Conway.o:  Conway.cpp dataTypes.h 
	$(CC) $(CFLAGS) -c Conway.cpp

  clean:
	$(RM) $(TARGET) Conway.o
