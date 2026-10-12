#!/usr/bin/env python3
"""Rebuild manifest.json from every problems/*/meta.json.

Run this after adding or editing a problem:
    python3 scripts/generate_manifest.py
"""
import json
import pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
PROBLEMS_DIR = ROOT / "problems"


def main():
    entries = []
    for meta_path in sorted(PROBLEMS_DIR.glob("*/meta.json")):
        meta = json.loads(meta_path.read_text())
        meta["path"] = f"problems/{meta_path.parent.name}"
        entries.append(meta)

    entries.sort(key=lambda m: (m.get("number") is None, m.get("number") or 0, m["slug"]))

    manifest = {"problems": entries}
    (ROOT / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(f"Wrote manifest.json with {len(entries)} problems "
          f"({sum(1 for m in entries if m.get('visualization'))} with visualizations)")


if __name__ == "__main__":
    main()
