"""Daily automation for 180 Days of C++.

    python scripts/daily.py morning   # create the next day with a real problem
    python scripts/daily.py evening   # if today's solution is still empty, add the reference solution
    python scripts/daily.py backfill  # fill every existing empty day (one-time clean-up)
    python scripts/daily.py test      # compile + run every bank solution against its sample (needs g++)

The problems and reference solutions live in bank/phase-*.txt.
"""

import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BANK_DIR = ROOT / "bank"
DAILY_DIR = ROOT / "daily"
TOTAL_DAYS = 180

MARKER = "// TODO: write your solution here"
OLD_STARTER = "// Write your solution here."
OLD_README_HINTS = ("Add today's problem statement here.", "Write the problem statement here.")

STATUS_TODO = "⏳ Not solved yet — solve it in `solution.cpp` and push."
STATUS_DONE = "✅ Solved by me."
STATUS_AUTO = "🤖 Reference solution added automatically. Come back and solve it yourself!"


# ---------------------------------------------------------------- bank

def load_bank():
    """Parse bank/phase-*.txt into {day: {title, statement, input, output, complexity, code}}."""
    bank = {}
    for path in sorted(BANK_DIR.glob("phase-*.txt")):
        text = path.read_text(encoding="utf-8").replace("\r\n", "\n")
        for block in re.split(r"^=== ", text, flags=re.M)[1:]:
            header, _, body = block.partition("\n")
            m = re.match(r"DAY (\d+) \| (.+)", header.strip())
            if not m:
                raise ValueError(f"{path.name}: bad header {header!r}")
            day, title = int(m.group(1)), m.group(2).strip()
            parts = re.split(r"^--- (statement|input|output|complexity|code)\n", body, flags=re.M)
            fields = dict(zip(parts[1::2], parts[2::2]))
            entry = {"title": title}
            for key in ("statement", "input", "output", "complexity", "code"):
                value = fields.get(key, "")
                entry[key] = value.strip("\n") if key != "code" else value.rstrip() + "\n"
            if day in bank:
                raise ValueError(f"Day {day} defined twice")
            bank[day] = entry
    return bank


# ---------------------------------------------------------------- files for one day

def day_folder(day):
    return DAILY_DIR / f"day-{day:03d}"


def readme_text(day, p, status):
    time_part, _, space_part = p["complexity"].partition("|")
    sample_in = p["input"] if p["input"] else "(no input)"
    return f"""# Day {day}: {p['title']}

## Problem Statement
{p['statement']}

### Sample Input
```
{sample_in}
```

### Sample Output
```
{p['output']}
```

## Approach
_Explain your approach here._

## Complexity
- {time_part.strip()}
- {space_part.strip()}

## Key Learnings
_Record what you learned today._

## Status
{status}
"""


def starter_code(day, p):
    return f"""// Day {day}: {p['title']}
// Problem: see README.md in this folder.
#include <bits/stdc++.h>
using namespace std;

int main() {{
    {MARKER}
    return 0;
}}
"""


def solution_code(day, p):
    return f"// Day {day}: {p['title']}\n// Reference solution (added automatically).\n\n{p['code']}"


def is_unsolved(solution_path):
    if not solution_path.exists():
        return True
    text = solution_path.read_text(encoding="utf-8", errors="replace")
    return MARKER in text or OLD_STARTER in text


def set_status(readme_path, status):
    text = readme_path.read_text(encoding="utf-8")
    if "## Status" in text:
        text = re.sub(r"## Status\n.*", "## Status\n" + status + "\n", text, flags=re.S)
    else:
        text = text.rstrip() + "\n\n## Status\n" + status + "\n"
    readme_path.write_text(text, encoding="utf-8")


def existing_days():
    days = []
    if DAILY_DIR.exists():
        for d in DAILY_DIR.iterdir():
            m = re.fullmatch(r"day-(\d{3})", d.name)
            if d.is_dir() and m:
                days.append(int(m.group(1)))
    return sorted(days)


def output(**values):
    """Pass values to later workflow steps (and print them for humans)."""
    gh_out = os.environ.get("GITHUB_OUTPUT")
    for k, v in values.items():
        print(f"{k}={v}")
        if gh_out:
            with open(gh_out, "a", encoding="utf-8") as f:
                f.write(f"{k}={v}\n")


# ---------------------------------------------------------------- modes

def morning(bank):
    days = existing_days()
    day = (days[-1] + 1) if days else 1
    if day > TOTAL_DAYS:
        print("All 180 days are created. 🎉")
        output(changed="false")
        return
    p = bank[day]
    folder = day_folder(day)
    folder.mkdir(parents=True)
    (folder / "README.md").write_text(readme_text(day, p, STATUS_TODO), encoding="utf-8")
    (folder / "solution.cpp").write_text(starter_code(day, p), encoding="utf-8")
    output(changed="true", day=day, title=p["title"],
           message=f"Day {day}: {p['title']} - new problem")


def evening(bank):
    days = existing_days()
    if not days:
        output(changed="false")
        return
    day = days[-1]
    folder = day_folder(day)
    sol, readme = folder / "solution.cpp", folder / "README.md"
    p = bank[day]
    if is_unsolved(sol):
        sol.write_text(solution_code(day, p), encoding="utf-8")
        set_status(readme, STATUS_AUTO)
        output(changed="true", day=day, message=f"Day {day}: {p['title']} - add solution")
    else:
        text = readme.read_text(encoding="utf-8") if readme.exists() else ""
        if STATUS_TODO in text:
            set_status(readme, STATUS_DONE)
            output(changed="true", day=day, message=f"Day {day}: mark as solved")
        else:
            print(f"Day {day} already solved. Nice work!")
            output(changed="false", day=day)


def backfill(bank):
    filled = []
    for day in existing_days():
        folder = day_folder(day)
        readme, sol = folder / "README.md", folder / "solution.cpp"
        p = bank[day]
        old = readme.read_text(encoding="utf-8") if readme.exists() else ""
        empty_readme = not old or any(h in old for h in OLD_README_HINTS)
        unsolved = is_unsolved(sol)
        if unsolved:
            sol.write_text(solution_code(day, p), encoding="utf-8")
        if empty_readme:
            readme.write_text(readme_text(day, p, STATUS_AUTO if unsolved else STATUS_DONE), encoding="utf-8")
        elif unsolved:
            set_status(readme, STATUS_AUTO)
        if unsolved or empty_readme:
            filled.append(day)
        for exe in folder.glob("*.exe"):
            exe.unlink()
    print("Filled days:", filled)
    output(changed="true" if filled else "false",
           message=f"Fill days {filled[0]}-{filled[-1]} with problems and solutions" if filled else "")


def run_tests(bank):
    missing = [d for d in range(1, TOTAL_DAYS + 1) if d not in bank]
    if missing:
        sys.exit(f"Bank is missing days: {missing}")
    norm = lambda s: "\n".join(line.rstrip() for line in s.strip().splitlines())
    failures = []
    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        for day in range(1, TOTAL_DAYS + 1):
            p = bank[day]
            src, exe = tmp / f"d{day}.cpp", tmp / f"d{day}"
            src.write_text(p["code"], encoding="utf-8")
            c = subprocess.run(["g++", "-std=c++17", "-O2", "-Wall", "-o", str(exe), str(src)],
                               capture_output=True, text=True)
            if c.returncode != 0:
                failures.append(f"Day {day}: compile error\n{c.stderr}")
                continue
            r = subprocess.run([str(exe)], input=p["input"] + "\n", capture_output=True, text=True, timeout=10)
            if norm(r.stdout) != norm(p["output"]):
                failures.append(f"Day {day}: wrong output\n--- expected\n{p['output']}\n--- got\n{r.stdout}")
        # Your own solutions only need to compile.
        for sol in sorted(DAILY_DIR.glob("day-*/solution.cpp")):
            c = subprocess.run(["g++", "-std=c++17", "-fsyntax-only", str(sol)], capture_output=True, text=True)
            if c.returncode != 0:
                failures.append(f"{sol.relative_to(ROOT)}: compile error\n{c.stderr}")
    if failures:
        print("\n\n".join(failures))
        sys.exit(f"{len(failures)} problem(s) failed")
    print(f"All {TOTAL_DAYS} reference solutions passed, and every daily solution compiles.")


if __name__ == "__main__":
    mode = sys.argv[1] if len(sys.argv) > 1 else ""
    modes = {"morning": morning, "evening": evening, "backfill": backfill, "test": run_tests}
    if mode not in modes:
        sys.exit(__doc__)
    modes[mode](load_bank())
