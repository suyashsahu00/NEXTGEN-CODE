# Workspace Custom Rules for NEXTGEN-CODE

## README Formatting Rules

When formatting or updating ANY README files or creating READMEs for new or future folders in this repository, follow these design guidelines:

1. **Chapter Ordering:** 
   - Group content into chapters corresponding to folders (e.g., Chapter 1, Chapter 2).
   - Place earlier chapters at the top of the README and append newer chapters chronologically below them.

2. **Chapter-Specific Resources:**
   - Keep "Useful Resources" or links related to a specific topic within that chapter's section. 
   - Do **NOT** combine all resources in a single section at the bottom of the document.

3. **Visuals and Recap Layout:**
   - Put diagrams and slides in a collapsible `<details>` disclosure panel so they don't clutter the layout.
   - Use clean callouts (Note, Tip, Important) for recap questions and quiz summaries.

4. **Code Snippets:**
   - Always include a small snippet of the most important code parts for each chapter in its respective section.

5. **Pre-push Formatting:**
   - Always verify and format the README file before staging, committing, and pushing changes to GitHub.

6. **Root README Synchronization:**
   - When creating or updating chapters in date-specific or module-level README files (e.g., `05-07-2026/APIs and Async JavaScript/README.md`), always verify and synchronize the repository root [README.md](file:///c:/Users/suyas/Downloads/CODING%281%29/NEXTGEN-CODE/README.md).
   - Ensure both the **Date Directory & Quick Access Index** table row and the corresponding **Chapter summary & representative code snippet** reflect the latest topics, technologies, and projects completed.

7. **Mermaid Diagram Validation:**
   - Always verify and test Mermaid diagram syntax before committing.
   - Avoid HTML tags (such as `<code>`, `<br>`) and escaped quotes (`\"`) inside node labels, as they break Markdown Mermaid parsers. Use clean single quotes or plain text enclosed in double-quoted brackets (e.g. `node["Label: 'text'"]`).

8. **Commit Confirmation & Clean Commit Messages:**
   - Never commit changes automatically without explicit user confirmation.
   - Before running `git commit`, always ask the user for confirmation and propose a clear, descriptive conventional commit message (e.g., `docs(api): add chapter 24 request body with sanitized mermaid diagram`).
