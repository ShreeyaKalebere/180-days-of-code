from pathlib import Path
import argparse

ROOT = Path(__file__).resolve().parent
DAILY_DIR = ROOT / "daily"

TOPICS = {
    1: "Introduction to C++",
    2: "Variables and Data Types",
    3: "Input and Output",
    4: "Operators",
    5: "Conditional Statements",
    6: "Loops",
    7: "Pattern Printing",
    8: "Functions",
    9: "Function Parameters and Return Values",
    10: "Arrays",
    11: "Strings",
    12: "Pointers and References",
    13: "Basic Recursion",
    14: "Time and Space Complexity",
    15: "Fundamentals Revision",
}


def create_day(day):
    if not 1 <= day <= 180:
        raise ValueError("Day must be between 1 and 180.")

    folder = DAILY_DIR / f"day-{day:03d}"

    if folder.exists():
        print(f"Day {day} already exists: {folder}")
        return

    folder.mkdir(parents=True)

    topic = TOPICS.get(day, "DSA Practice")

    readme = f"""# Day {day}: {topic}

## Objective
Learn and practice: {topic}.

## Problem Statement
Write the problem statement here.

## Approach
Explain your approach here.

## Complexity
- Time: To be analyzed.
- Space: To be analyzed.

## Key Learnings
Record what you learned today.

## Completion Checklist
- [ ] Understand the problem.
- [ ] Implement the solution.
- [ ] Compile and test the solution.
- [ ] Analyze complexity.
- [ ] Commit the solution to GitHub.
"""

    solution = """#include <iostream>
using namespace std;

int main() {
    // Write your solution here.
    return 0;
}
"""

    (folder / "README.md").write_text(readme, encoding="utf-8")
    (folder / "solution.cpp").write_text(solution, encoding="utf-8")

    print(f"Created Day {day}: {topic}")
    print(f"Location: {folder}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate a daily C++ challenge folder."
    )
    parser.add_argument(
        "day",
        type=int,
        help="Day number, from 1 to 180"
    )
    args = parser.parse_args()

    create_day(args.day)

