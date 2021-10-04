var randomNumber1 = Math.floor(Math.random()*6)+1;            //1 - 6
var randomDiceImage = "dice" + randomNumber1 + ".png";       // dice1.png - dice6.png
var randomImageSource = "Images/" + randomDiceImage;        //Images/dice1.png - Imagaes/dice2.png
var image1 = document.querySelectorAll("img")[0];
image1.setAttribute("src",randomImageSource);

var randomNumber2 = Math.floor(Math.random()*6)+1;
var randomDiceImage = "dice" + randomNumber2 + ".png";
var randomImageSource = "Images/" + randomDiceImage;
var image2 = document.querySelectorAll("img")[1];
image2.setAttribute("src", randomImageSource);

if(randomNumber1>randomNumber2){
    document.querySelector("h1").innerHTML="Player1 wins!🤩";
}
else if(randomNumber1<randomNumber2){
    document.querySelector("h1").innerHTML="Player2 wins!😋";
}
else{
    document.querySelector("h1").innerHTML="Draw!😄";
}