# World's Most Annoying Cookie Consent Website 🍪💀

A humorous, highly interactive front-end project designed to practice DOM manipulation, form handling, events, and asynchronous JavaScript (`setTimeout`). 

This project simulates a ridiculously persistent, data-hungry, and annoying cookie consent modal that won't let the user leave without accepting the terms.

---

## ✨ Features

- **🕒 Delayed Modal Popup:** The cookie consent modal automatically displays 1.5 seconds after the page loads.
- **🚫 Unclickable Decline Button:** If the user attempts to hover over the "Decline" button, it dynamically swaps places with the "Accept" button using CSS flex-direction reversal.
- **🔄 Fake Data Selling Simulator:** Upon submitting the form with their name and email, the user is shown a hilarious sequence of loading screens:
  1. *"Uploading your data to the dark web..."*
  2. *"Making the sale..."*
  3. A final message thanking them for selling the rights to their eternal soul, accompanied by a pirate GIF.
- **🔒 Close Button Lock:** The modal close button (`X`) is completely disabled until the fake data upload and soul sale process is finished.

---

## 🛠️ Tech Stack

- **HTML5:** Semantic markup for page and modal layout.
- **CSS3:** Custom styles, layout using Flexbox, and transition reversed classes.
- **JavaScript (Vanilla ES6):** Event listeners (`click`, `mouseenter`, `submit`), DOM selection, and asynchronous timers (`setTimeout`).
- **Vite:** Next-generation frontend tooling for fast development.

---

## 🚀 Getting Started

### Prerequisites

Make sure you have [Node.js](https://nodejs.org/) installed.

### Installation

1. Install the dependencies:
   ```bash
   npm install
   ```

2. Run the development server:
   ```bash
   npm run dev
   ```

3. Open your browser and navigate to the local URL (usually `http://localhost:5173`).

---

## 📂 Project Structure

```
├── images/
│   ├── bugatti.jpg        # Content image
│   ├── loading.svg        # Loader spinner
│   └── pirate.gif         # Humorous success GIF
├── index.html             # Structure of the site and modal
├── index.css              # Custom styling & reverse layouts
├── index.js               # Logic for reverse toggle, timers, & forms
├── package.json           # Scripts and Vite dependency
└── vite.config.js         # Vite configuration
```

---

*Made with 💜 during the Scrimba Fullstack Developer Path.*