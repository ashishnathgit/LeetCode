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
    "2D DP": "Edit distance, sequence alignment, grid path costs",
    "Array": "Gap detection in IDs, schedules and sequence numbers",
    "Backtracking": "Search over choices: segmentation, solvers, config generation",
    "Binary Search": "Index lookups, git bisect, searching sorted or rotated data",
    "Binary Tree + Divide and Conquer": "Aggregating metrics bottom-up in hierarchies",
    "Binary Tree DFS": "Walking ASTs, org charts and directory trees",
    "Bit Manipulation": "Flags, checksums, subnet math, compact storage",
    "Boyer-Moore Voting": "Majority detection in streams, consensus checks",
    "BST Inorder Traversal": "Ordered iteration over sorted indexes",
    "BST Traversal": "Range queries and lookups in ordered indexes",
    "Bucketing + Sliding Window": "Near-duplicate detection in time-series data",
    "Counting Sort": "Histograms, citation metrics, sorting small-range keys",
    "Design": "Caches, iterators, buffered I/O, streaming APIs",
    "Design + Queue": "Message queues, schedulers, buffered pipelines",
    "Design + Stack": "Undo history, call stacks, min/max tracking",
    "Divide and Conquer": "Parallel merge sort, inversion metrics in rankings",
    "Dynamic Programming": "Diff tools, budgeting, scheduling, trading strategies",
    "Fast & Slow Pointers + Reversal": "In-place list checks without extra memory",
    "Geometry": "Mapping, CAD, collision detection",
    "Graph": "Routing, flood fill, object-graph copying, connected regions",
    "Greedy": "Fuel/battery planning, fair allocation",
    "Hash Map": "O(1) lookups: dedup, grouping, counting, caching",
    "Heap": "Priority queues, top-k ranking, task scheduling",
    "Interval Cost Precompute + Partition DP": "Optimal batching and segmentation of data",
    "Linked List": "LRU caches, undo history, allocators, cycle detection",
    "Math": "Spreadsheet labels, date math, primes for hashing",
    "Math / Digit Counting": "Page numbering, counters, numeric analytics",
    "Matrix": "Image processing, grid-based games and spreadsheets",
    "Monotonic Deque": "Rolling max/min in monitoring and trading",
    "Prefix/Suffix Products": "Precomputed aggregates for fast range queries",
    "Sliding Window": "Rate limiters, stream analytics, quotas",
    "Sliding Window + Hash Set": "Dedup within recent windows, replay detection",
    "Sliding Window + Monotonic Deque": "Streaming window extremes for alerting",
    "Sorting": "Ranking, custom ordering, gap analysis",
    "Stack": "Expression evaluation, undo stacks, parsers",
    "Stack (Simulated)": "Iterative traversal without recursion limits",
    "Staircase Search": "Searching sorted 2D tables and matrices",
    "String": "Parsing, fuzzy matching, version compare, text search",
    "Sweep Line + Multiset": "Skylines, calendar overlaps, resource usage over time",
    "Topological Sort": "Build systems, package managers, task schedulers",
    "Tree": "File systems, DOM trees, ASTs, database indexes",
    "Trie": "Autocomplete, spell check, IP routing",
    "Two Pointers": "Dedup, in-place rotation, merging sorted data",
}

def leetcode_url(title):
    """LeetCode problem URL from the title, e.g. "Pow(x, n)" -> .../problems/powx-n/."""
    slug = re.sub(r"[^a-z0-9 -]", "", title.lower())
    slug = re.sub(r"[\s-]+", "-", slug).strip("-")
    return f"https://leetcode.com/problems/{slug}/"


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
        "| # | Problem | LeetCode | Difficulty | Time | Space | Pattern | Real-world use |",
        "| ---: | :--- | :---: | :---: | :--- | :--- | :--- | :--- |",
    ]
    for p in problems:
        link = f"[{p['title']}]({quote(p['file'])})"
        diff = f"{DIFF_ICON.get(p['Difficulty'], '')} {p['Difficulty'] or '—'}".strip()
        lines.append(f"| {p['num']} | {link} | [Open]({leetcode_url(p['title'])}) | {diff} | {p['Time']} | {p['Space']} | {p['Pattern']} | {p['Use']} |")

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
