document.getElementById("new-deck").addEventListener("click", function() {
    fetch("https://apis.scrimba.com/deckofcards/api/deck/new/shuffle/")
        .then(res => res.json())
        .then(data => console.log(data))
})

// Functions are a first-class object in JavaScript

let myNum = 42
let myNum2 = myNum

function myFunction(a, b) {
    console.log(a + b)
}

let myFunction2 = myFunction
myFunction2(1, 2)