CFLAGS=-c -Wall
LDFLAGS=-lm -lncurses
HEADERDIR=Header/
HEADER=$(wildcard $(HEADERDIR)*.h)
SOURCEDIR=Source/
SOURCE=$(wildcard $(SOURCEDIR)*.cpp)
OBJDIR=Object/
OBJS=$(addprefix $(OBJDIR)/, $(notdir $(SOURCE:.cpp=.o)))
EXECUTABLE=Thy-Arena-Man-III

$(EXECUTABLE): $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)
	
$(OBJDIR)/%.o: $(SOURCEDIR)/%.cpp $(HEADERDIR)/%.h | $(OBJDIR)
	$(CXX) $(CFLAGS) $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean

clean:
	rm -r $(OBJDIR) $(EXECUTABLE)

list:
	echo $(OBJS)
