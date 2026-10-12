# Adding a visualization

Each problem lives in `problems/<slug>/`. To add a visualization for one:

1. Copy the template:
   ```
   mkdir -p problems/<slug>/visualizations
   cp templates/visualization-template.html problems/<slug>/visualizations/index.html
   ```
2. Build the visualization inside that one HTML file (inline CSS/JS, or
   additional files in the same `visualizations/` folder if you need assets).
   It must work standalone when opened directly in a browser or dropped into
   an `<iframe>` — don't depend on anything outside that folder except CDN
   scripts (e.g. `cdnjs.cloudflare.com`, `cdn.jsdelivr.net`).
3. Update that problem's `problems/<slug>/meta.json`:
   ```json
   "visualization": { "entry": "visualizations/index.html" }
   ```
4. Regenerate the manifest:
   ```
   python3 scripts/generate_manifest.py
   ```
5. Commit everything, including the regenerated `manifest.json`.

## Folder layout

```
problems/<slug>/
  meta.json            # title, LeetCode/GFG/NeetCode url, tags, solution files, visualization pointer
  README.md
  solution.cpp          # one or more language solutions
  visualizations/
    index.html          # present only once a visualization exists
```

`templates/meta.template.json` and `templates/visualization-template.html` are
the starting points for a brand-new problem or a new visualization.

## How the portfolio site (or anyone else) uses this repo

- `manifest.json` at the repo root lists every problem with its metadata and,
  for problems that have one, a `visualization.entry` path. Fetch it from
  raw GitHub content or GitHub Pages and render a list/filter UI from it —
  don't hand-maintain a duplicate list on the site.
- Each `visualizations/index.html` is a fully self-contained page, so it can
  be embedded directly:
  ```html
  <iframe
    src="https://shahtirth07.github.io/LeetCodeProblems/problems/<slug>/visualizations/index.html"
    loading="lazy"
    style="width:100%; aspect-ratio:16/9; border:0;">
  </iframe>
  ```
  This requires GitHub Pages to be enabled for this repo (Settings → Pages →
  Deploy from branch `main`, folder `/ (root)`). Raw GitHub content
  (`raw.githubusercontent.com`) serves HTML as `text/plain`/an attachment, so
  it won't render inside an iframe — Pages (or any static host) is required
  for the embed to actually execute as HTML.
- Anyone forking this repo gets the same convention: every problem is
  self-describing via its `meta.json`, so tooling built against `manifest.json`
  keeps working without changes.
