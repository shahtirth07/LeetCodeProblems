# LeetCode Problems

Solutions (and, for some problems, interactive visualizations) for LeetCode
problems I've solved.

## Structure

Every problem lives in its own folder under `problems/`:

```
problems/<slug>/
  meta.json        # title, source url, tags, solution files, visualization pointer
  README.md
  solution.cpp
  visualizations/   # present only for problems that have one
    index.html
```

`manifest.json` at the repo root is a generated index of every problem's
metadata, built from all the `meta.json` files — this is what external tools
(like my portfolio site) fetch to list and filter problems, and to find which
ones have a visualization to embed.

See [`docs/VISUALIZATIONS.md`](docs/VISUALIZATIONS.md) for how to add a new
problem or visualization, and how the manifest/embed convention works.
