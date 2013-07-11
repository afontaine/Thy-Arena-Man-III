CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lm -lncurses
HEADERDIR=Header/
HEADER=$(HEADERDIR)$(wildcard, *.h)
SOURCEDIR=Source/
SOURCE=$(SOUCEDIR)$(wildcard, *.cpp)
OBJDIR=Object/
OBJS=$(addprefix $(OBJDIR)/,$(notdir $($SOURCE:.cpp=.o)))
EXECUTABLE=They-Arena-Man-III

$(EXECUTABLE): $(OBJS)
	$(CC) -Wall $(LDFLAGS) -o $@ $^
	
$(OBJDIR)/%.o: $(SOURCEDIR)/%.cpp $(HEADERDIR)/%.h | $(OBJDIR)
	$(CC) $(CFLAGS) -o *@ $<

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean

clean:
	rm -r $(OBJDIR) $(EXECUTABLE)
