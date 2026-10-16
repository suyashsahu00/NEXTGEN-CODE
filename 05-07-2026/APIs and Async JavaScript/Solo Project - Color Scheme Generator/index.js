const btn = document.getElementById("get-scheme");

function getColors() {
    const color = document.getElementById("seed-color").value.slice(1);
    const mode = document.getElementById("scheme-mode").value;

    console.log(color, mode);
    
    
    fetch(`https://www.thecolorapi.com/scheme?hex=${color}&mode=${mode}&count=5`)
    .then(res => res.json())
    .then(data => {
        let html = ""
        data.colors.forEach(color =>{
            html += `
                <div class="color-column" data-hex="${color.hex.value}">
                    <div class="color-swatch"
                        style="background-color: ${color.hex.value}"></div>
                    <div class="color-hex">${color.hex.value}</div>
                </div>
            `
        })
        document.getElementById("color-container").innerHTML = html
    })
}


btn.addEventListener("click", getColors);
getColors();

document.getElementById("color-container").addEventListener("click", e => {
    const hex = e.target.closest(".color-column")?.dataset.hex;
    if(hex) {
        navigator.clipboard.writeText(hex);
        const msg = document.getElementById("copy-msg");
        msg.textContent = "Copied";
        
        setTimeout(() => {
            msg.textContent = "";
        }, 1500);
    }

});


