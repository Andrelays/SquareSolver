CXX = g++

CXXFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

release: utilities.o solve_equations.o input_data.o output_data.o release.o
	$(CXX) main.cpp utilities.o solve_equations.o input_data.o output_data.o release.o -o release $(CXXFLAGS)

test: test.o utilities.o solve_equations.o
	$(CXX) main.cpp test.o utilities.o solve_equations.o -DTEST -DDEBUG -o test $(CXXFLAGS)

docs:
	doxygen doxy_config

%.o: %.cpp
	@echo [CXX] [CXXFLAGS] $^ -o $@
	@$(CXX) $(CXXFLAGS) -c $^
	
clean:
	rm -rf *.o SquareSolver
	
	