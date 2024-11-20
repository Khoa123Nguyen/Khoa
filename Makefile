# Cài đặt các biến
CC = g++                  # Trình biên dịch (ở đây dùng gcc, nếu dùng g++ cho C++ thì thay g++)
CFLAGS += -g -Wall        # Các cờ biên dịch (thêm cờ debug -g và cảnh báo -Wall)

EXEC = Final_exercise

INC = -Iinc/
SRC = \
	main.cpp  \
	src/Ex1.cpp  \
	src/Ex2.cpp  \
	src/Ex3.cpp  \
	src/Ex4.cpp  \
	src/Ex5.cpp  \


	
#target
$(EXEC):  
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@


clean:
	-rm -f  $(EXEC)