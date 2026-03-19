const btn = document.getElementById("hamburger");
const navRight = document.querySelector(".nav-right");

btn.addEventListener("click", () => {
    navRight.classList.toggle("active");
}); 
