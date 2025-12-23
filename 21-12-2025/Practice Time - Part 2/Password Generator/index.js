const characters = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9","~","`","!","@","#","$","%","^","&","*","(",")","_","-","+","=","{","[","}","]",",","|",":",";","<",">",".","?",
"/"];

const passwordLenght =15
let passOne=document.getElementById("password-one")
let passTwo=document.getElementById("password-two")

function getRandomChar(){
    const randomIndex= Math.floor(Math.random()* characters.length)
    return characters[randomIndex]
}

function generatePassword(){
    let password1 =""
    let password2 =""
    for (let i=0; i< passwordLenght;i++){
        password1 += getRandomChar()
        password2 += getRandomChar()
    }
    passOne.textContent= password1
    passTwo.textContent= password2
}
