#!/usr/bin/env python3
"""Rebuilds the "Progress" section of Readme.md from the tag line at the top of each solution.

Tag format (first line of each .cpp file):
// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Hash Map | Use: Where this shows up in real systems

Run: python3 scripts/update_readme.py
"""
import re
from collections import Counter
from pathlib import Path
from urllib.parse import quote

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "Readme.md"
START, END = "<!-- PROGRESS:START -->", "<!-- PROGRESS:END -->"

DIFF_ICON = {"Easy": "🟢", "Medium": "🟡", "Hard": "🔴"}

# Real-world summary for each pattern (shown in the pattern table)
PATTERN_USE = {
    "Array": "Gap detection in IDs, schedules and sequence numbers",
    "Backtracking": "Search over choices: segmentation, solvers, config generation",
    "Binary Search": "Index lookups, git bisect, searching sorted or rotated data",
    "Bit Manipulation": "Flags, checksums, subnet math, compact storage",
    "Design": "Caches, iterators, buffered I/O, streaming APIs",
    "Divide and Conquer": "Parallel merge sort, inversion metrics in rankings",
    "Dynamic Programming": "Diff tools, budgeting, scheduling, trading strategies",
    "Graph": "Routing, flood fill, object-graph copying, connected regions",
    "Greedy": "Fuel/battery planning, fair allocation",
    "Hash Map": "O(1) lookups: dedup, grouping, counting, caching",
    "Linked List": "LRU caches, undo history, allocators, cycle detection",
    "Math": "Spreadsheet labels, date math, primes for hashing",
    "Matrix": "Image processing, grid-based games and spreadsheets",
    "Sliding Window": "Rate limiters, stream analytics, quotas",
    "Sorting": "Ranking, custom ordering, gap analysis",
    "Stack": "Expression evaluation, undo stacks, parsers",
    "String": "Parsing, fuzzy matching, version compare, text search",
    "Topological Sort": "Build systems, package managers, task schedulers",
    "Tree": "File systems, DOM trees, ASTs, database indexes",
    "Trie": "Autocomplete, spell check, IP routing",
    "Two Pointers": "Dedup, in-place rotation, merging sorted data",
}

TAG = re.compile(r"^//\s*Difficulty:(.*)$", re.M)


def parse(path):
    """Returns the problem's fields, or None fields if the file has no tag line."""
    number, title = path.stem.split(". ", 1)
    info = {"num": int(number), "title": title, "file": path.name,
            "Difficulty": None, "Time": "—", "Space": "—", "Pattern": "—", "Use": "—"}
    match = TAG.search(path.read_text(encoding="utf-8")[:2000])
    if match:
        fields = ("Difficulty:" + match.group(1)).split("|")
        for field in fields:
            key, _, value = field.partition(":")
            info[key.strip()] = value.strip()
    return info


def build(problems):
    counts = Counter(p["Difficulty"] for p in problems)
    patterns = Counter(p["Pattern"] for p in problems if p["Pattern"] != "—")

    lines = [
        f"**{len(problems)} problems solved** · "
        f"🟢 {counts['Easy']} Easy · 🟡 {counts['Medium']} Medium · 🔴 {counts['Hard']} Hard",
        "",
        "### By Pattern",
        "",
        "| Pattern | Solved | Where it's used in real systems |",
        "| :--- | :---: | :--- |",
    ]
    for pattern, count in sorted(patterns.items(), key=lambda kv: (-kv[1], kv[0])):
        lines.append(f"| {pattern} | {count} | {PATTERN_USE.get(pattern, '—')} |")

    lines += [
        "",
        "### All Problems",
        "",
        "| # | Problem | Difficulty | Time | Space | Pattern | Real-world use |",
        "| ---: | :--- | :---: | :--- | :--- | :--- | :--- |",
    ]
    for p in problems:
        link = f"[{p['title']}]({quote(p['file'])})"
        diff = f"{DIFF_ICON.get(p['Difficulty'], '')} {p['Difficulty'] or '—'}".strip()
        lines.append(f"| {p['num']} | {link} | {diff} | {p['Time']} | {p['Space']} | {p['Pattern']} | {p['Use']} |")

    untagged = [p["file"] for p in problems if not p["Difficulty"]]
    return "\n".join(lines), untagged


def main():
    files = [f for f in ROOT.glob("*.cpp") if re.match(r"^\d+\. ", f.name)]
    problems = sorted((parse(f) for f in files), key=lambda p: p["num"])
    section, untagged = build(problems)

    readme = README.read_text(encoding="utf-8")
    if START not in readme:
        raise SystemExit(f"Readme.md is missing the {START} / {END} markers")
    before, rest = readme.split(START, 1)
    _, after = rest.split(END, 1)
    README.write_text(f"{before}{START}\n{section}\n{END}{after}", encoding="utf-8")

    print(f"Readme updated: {len(problems)} problems")
    for name in untagged:
        print(f"  warning: no tag line in {name}")


if __name__ == "__main__":
    main()
