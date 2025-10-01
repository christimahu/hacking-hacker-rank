# ==============================================================================
# HackerRank TDD Interview Framework
# ==============================================================================
#
# Run 'make' or 'make help' to see usage instructions
#
# ==============================================================================

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

.PHONY: test submit run clean all help

# Default target: show help
help:
	@echo "=========================================="
	@echo "HackerRank TDD Interview Framework"
	@echo "=========================================="
	@echo ""
	@echo "PURPOSE:"
	@echo "  Develop C++ solutions locally with TDD, then generate"
	@echo "  a single file to copy-paste into HackerRank."
	@echo ""
	@echo "FILE STRUCTURE:"
	@echo "  problem.h           - Function declarations"
	@echo "  problem.cpp         - Implementation (wrap in BEGIN_SOLUTION/END_SOLUTION)"
	@echo "  test.cpp            - Test suite (demonstrate SDET skills)"
	@echo "  submit_template.cpp - Template with includes and main()"
	@echo "  submit.cpp          - Auto-generated file to copy to HackerRank"
	@echo ""
	@echo "WORKFLOW:"
	@echo "  1. Read HackerRank problem"
	@echo "  2. Write tests in test.cpp"
	@echo "  3. Declare functions in problem.h"
	@echo "  4. Implement solution in problem.cpp between markers:"
	@echo "     // BEGIN_SOLUTION"
	@echo "     your code here"
	@echo "     // END_SOLUTION"
	@echo "  5. Run: make all"
	@echo "     - Cleans build artifacts"
	@echo "     - Compiles and runs tests"
	@echo "     - If tests pass, generates submit.cpp"
	@echo "  6. Run: make run"
	@echo "     - Executes submit.cpp to verify final output"
	@echo "  7. Copy all of submit.cpp to HackerRank"
	@echo ""
	@echo "AVAILABLE COMMANDS:"
	@echo "  make          - Show this help message"
	@echo "  make all      - Clean, test, generate submit.cpp (if tests pass)"
	@echo "  make test     - Only run tests"
	@echo "  make submit   - Only generate submit.cpp"
	@echo "  make run      - Execute submit.out to see final output"
	@echo "  make clean    - Remove all generated files"
	@echo "  make help     - Show this help message"
	@echo ""
	@echo "TYPICAL USAGE:"
	@echo "  make all ; make run   - Full workflow: test, generate, and verify"
	@echo ""

# Clean, test, and generate submit.cpp if tests pass
all: clean test submit

# Remove all generated files
clean:
	@rm -f *.out *.o .solution.tmp .includes.tmp submit.cpp
	@echo "Cleaned build artifacts"
	@echo ""

# Compile and run test suite
test: test.out
	@./test.out
	@echo ""

# Build test executable from test.cpp + problem.cpp
test.out: test.cpp problem.cpp problem.h
	@echo "Building test suite..."
	@$(CXX) $(CXXFLAGS) -o test.out test.cpp problem.cpp
	@echo ""

# Generate submit.cpp and verify it compiles, then display it
submit: submit.cpp submit.out
	@echo "=========================================="
	@echo "submit.cpp ready for HackerRank"
	@echo "Copy everything between the lines below:"
	@echo "=========================================="
	@cat submit.cpp
	@echo "=========================================="

# Extract includes and solution from problem.cpp and inject into submit_template.cpp
submit.cpp: problem.cpp submit_template.cpp
	@echo "Generating submit.cpp..."
	@grep '^#include' problem.cpp | grep -v '"problem.h"' > .includes.tmp
	@sed -n '/BEGIN_SOLUTION/,/END_SOLUTION/p' problem.cpp | sed '1d;$$d' > .solution.tmp
	@awk '/__INCLUDES_PLACEHOLDER__/{system("cat .includes.tmp");next}/__SOLUTION_PLACEHOLDER__/{system("cat .solution.tmp");next}1' submit_template.cpp > submit.cpp
	@rm -f .includes.tmp .solution.tmp

# Compile submit.cpp to verify it has no errors
submit.out: submit.cpp
	@echo "Compiling submit.cpp..."
	@$(CXX) $(CXXFLAGS) -o submit.out submit.cpp

# Run the final submit.out to verify output matches expectations
run: submit.out
	@echo "Running submit.out:"
	@echo "---"
	@./submit.out
