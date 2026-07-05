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

## 📖 Concepts Studied

During this project, we have studied and implemented the following key front-end development concepts:

### 1. 🕒 `setTimeout`
Used to run a function asynchronously after a specified delay in milliseconds.
* **Modal Delay:** Shows the modal 1.5 seconds after page load.
* **Loading Sequence:** Sequences text changes and actions.
```javascript
// Display the modal after 1.5s
setTimeout(function(){
    modal.style.display = 'inline'
}, 1500)

// Update loading text after 1.5s
setTimeout(function(){
    document.getElementById('upload-text').innerText = `Making the sale...`
}, 1500)
```

### 2. 🎨 `element.style`
Used to get or set the inline styles of an element dynamically.
```javascript
// Displaying the modal
modal.style.display = 'inline'

// Closing/hiding the modal
modal.style.display = 'none'
```

### 3. 📝 Forms
Handling user input submission. We listen to the `submit` event of the `<form>` rather than a button click to ensure all required fields are validated.
```javascript
consentForm.addEventListener('submit', function(e){
    // Form submission actions happen here
})
```

### 4. 🗃️ `FormData` & `.get()`
`FormData` lets us compile form values into key-value pairs easily. `.get(name)` retrieves the value of the input matching the `name` attribute.
```javascript
const consentFormData = new FormData(consentForm)
const fullName = consentFormData.get('fullName') // Extracts value from <input name="fullName">
```

### 5. 🛑 `event.preventDefault()`
Prevents the browser's default behavior for an event. In forms, this stops the browser from reloading the page upon submission, enabling custom asynchronous operations.
```javascript
consentForm.addEventListener('submit', function(e){
    e.preventDefault() // Prevents page reload
    // Custom logic
})
```

### 6. ↔️ CSS `row-reverse`
Uses CSS Flexbox to reverse the visual order of items. The Accept and Decline buttons are swapped when this class is applied.
```css
.modal-btns-reverse {
    flex-direction: row-reverse;
}
```

### 7. 🔄 Toggling Classes
Adding or removing a class name dynamically using `classList.toggle()`. Used here on `mouseenter` to swap the buttons' order when the user tries to click "Decline".
```javascript
declineBtn.addEventListener('mouseenter', function(){
    modalChoiceBtns.classList.toggle('modal-btns-reverse')
})
```

### 8. 🔒 `disabled` Attribute
HTML attribute to prevent user interaction with buttons.
* **HTML Setup (Initially Disabled):**
  ```html
  <button class="modal-close-btn" id="modal-close-btn" disabled>X</button>
  ```
* **JavaScript Toggle (Enabling it):**
  ```javascript
  modalCloseBtn.disabled = false // Enables the close button once the sequence completes
  ```

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