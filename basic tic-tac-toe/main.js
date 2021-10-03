const gridElement=document.querySelectorAll(".grid-item");
const display=document.querySelector(".container");
const reset=document.querySelector(".reset-button");
const playerstat=document.querySelector(".player-status");
const chooseButtonX=document.getElementById('chose-x');
const chooseButtonO=document.getElementById('chose-o');
const chooseButtonTP=document.getElementById('two-player');
const chooseButtonSP=document.getElementById('single-player');
let isTwoPlayerGame=false;
let gameOver=false;

chooseButtonTP.addEventListener('click',twoplayer);
function twoplayer(event){isTwoPlayerGame=true;display.classList.add('twoPlayer');}


let xisnext=true;
chooseButtonX.addEventListener('click',handleChooseButtonX)
function handleChooseButtonX() {document.querySelector('.option-page').classList.add('hide');xisnext=true;playerstat.innerHTML="It's X's turn !";}
chooseButtonO.addEventListener('click',handleChooseButtonO)
function handleChooseButtonO() {document.querySelector('.option-page').classList.add('hide');xisnext=false;playerstat.innerHTML="It's O's turn !";}




function resetGame(event) {
    for(let i=0;i<gridElement.length;i++){
        gridElement[i].classList.remove('x','o','change-color');
        }
        document.querySelector('.option-page').classList.remove('hide');
        gameOver=false;
}

function changePlayerStat() {
    if(xisnext===true){playerstat.innerHTML="It's X's turn !";}
    else if(xisnext===false){playerstat.innerHTML="It's O's turn !";}
}


function checkGameStatus() {
    const one=gridElement[0].classList[2];
    const two=gridElement[1].classList[2];
    const three=gridElement[2].classList[2];
    const four=gridElement[3].classList[2];
    const five=gridElement[4].classList[2];
    const six=gridElement[5].classList[2];
    const seven=gridElement[6].classList[2];
    const eight=gridElement[7].classList[2];
    const nine=gridElement[8].classList[2];
    if(one&&one===two&&one===three){
        gameOver=true;
        playerstat.innerHTML=one+" has won !";
        gridElement[0].classList.add('change-color');gridElement[1].classList.add('change-color');gridElement[2].classList.add('change-color');return;}
    if(one&&one===four&&one===seven){
        gameOver=true;
        playerstat.innerHTML=one+" has won !";
        gridElement[0].classList.add('change-color');gridElement[3].classList.add('change-color');gridElement[6].classList.add('change-color');return;}
    if(one&&one===five&&one===nine){
        gameOver=true;
        playerstat.innerHTML=one+" has won !";
        gridElement[0].classList.add('change-color');gridElement[4].classList.add('change-color');gridElement[8].classList.add('change-color');return;}
    if(two&&two===five&&two===eight){
        gameOver=true;
        playerstat.innerHTML=two+" has won !";
        gridElement[1].classList.add('change-color');gridElement[4].classList.add('change-color');gridElement[7].classList.add('change-color');return;}
    if(three&&three===six&&three===nine){
        gameOver=true;
        playerstat.innerHTML=three+" has won !"; 
        gridElement[2].classList.add('change-color');gridElement[5].classList.add('change-color');gridElement[8].classList.add('change-color');return;}
    if(three&&three===five&&three===seven){
        gameOver=true;
        playerstat.innerHTML=three+" has won !";
        gridElement[2].classList.add('change-color');gridElement[4].classList.add('change-color');gridElement[6].classList.add('change-color');return;}
    if(four&&four===five&&four===six){
        gameOver=true;
        playerstat.innerHTML=four+" has won !";
        gridElement[3].classList.add('change-color');gridElement[4].classList.add('change-color');gridElement[5].classList.add('change-color');return;}
    if(seven&&seven===eight&&seven===nine){
        gameOver=true;
        playerstat.innerHTML=seven+" has won !";
        gridElement[6].classList.add('change-color');gridElement[7].classList.add('change-color');gridElement[8].classList.add('change-color');return;}
    else if(one&&two&&three&&four&&five&&six&&seven&&eight&&nine){
        gameOver=true;
        playerstat.innerHTML="It's a Draw !";return;
    }

}


function clickCell(event){
    if(gameOver===false){
    if(event.target.classList[2]!='x'&&event.target.classList[2]!='o'){
        if(xisnext===true){
            event.target.classList.add('x');
            xisnext=false;
            checkGameStatus();
            if(gameOver===false){changePlayerStat();}
            

        }
        else if(xisnext===false) {
            event.target.classList.add('o');
            xisnext=true;
            checkGameStatus();
            if(gameOver===false){changePlayerStat();}       
        }
    }
}
}

        
    
for(let i=0;i<gridElement.length;i++){
    gridElement[i].addEventListener('click',clickCell);
    }
    reset.addEventListener('click',resetGame);
    

