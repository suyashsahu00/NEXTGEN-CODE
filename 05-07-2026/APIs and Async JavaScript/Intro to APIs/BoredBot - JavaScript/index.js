/**
Challenge: 

When the button is clicked, call out to the Bored API
(URL: https://apis.scrimba.com/bored/api/activity)
and replace the h4 with the activity from the API

*/

const activityButtton = document.getElementById("boredBtn");

activityButtton.addEventListener("click", function(){
  console.log("Button Clicked")
  fetch("https://apis.scrimba.com/bored/api/activity")
  .then(response => response.json())
  .then(data=>{
    console.log(data)
    document.getElementById("activityBtn").textContent = data.activity;
  })
});